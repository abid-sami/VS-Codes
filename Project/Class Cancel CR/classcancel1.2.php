<?php
/**
 * Plugin Name: Class Cancel Booking
 * Description: Users can post cancelled classes with time, room, and date, others can book them. Includes full user dashboard with Admin Control panel
 * Version: 1.2
 * Author: Ragib Hasan Abid Sami
 * Added Dropdown for room selection
 */

// Register custom post type
function ccb_register_post_type() {
    register_post_type('cancelled_class', [
        'labels' => [
            'name' => 'Cancelled Classes',
            'singular_name' => 'Cancelled Class',
        ],
        'public' => true,
        'has_archive' => true,
        'supports' => ['title'],
        'show_in_rest' => true
    ]);
}
add_action('init', 'ccb_register_post_type');

// Add meta boxes
function ccb_add_meta_boxes() {
    add_meta_box('ccb_meta', 'Class Info', 'ccb_meta_callback', 'cancelled_class', 'normal');
}
add_action('add_meta_boxes', 'ccb_add_meta_boxes');

function ccb_meta_callback($post) {
    $time = get_post_meta($post->ID, '_ccb_time', true);
    $room = get_post_meta($post->ID, '_ccb_room', true);
    $date = get_post_meta($post->ID, '_ccb_date', true);
    $booked = get_post_meta($post->ID, '_ccb_booked', true);
    $booked_by = get_post_meta($post->ID, '_ccb_booked_by', true);
    ?>
    <label>Room No: <input type="text" name="ccb_room" value="<?php echo esc_attr($room); ?>"></label><br><br>
    <label>Time: <input type="text" name="ccb_time" value="<?php echo esc_attr($time); ?>"></label><br><br>
    <label>Date: <input type="date" name="ccb_date" value="<?php echo esc_attr($date); ?>"></label><br><br>
    <label>Booked: <?php echo $booked ? esc_html($booked) : 'no'; ?></label><br>
    <label>Booked By: <?php echo esc_html($booked_by); ?></label>
    <?php
}

function ccb_save_meta($post_id) {
    if (array_key_exists('ccb_time', $_POST)) {
        update_post_meta($post_id, '_ccb_time', sanitize_text_field($_POST['ccb_time']));
    }
    if (array_key_exists('ccb_room', $_POST)) {
        update_post_meta($post_id, '_ccb_room', sanitize_text_field($_POST['ccb_room']));
    }
    if (array_key_exists('ccb_date', $_POST)) {
        update_post_meta($post_id, '_ccb_date', sanitize_text_field($_POST['ccb_date']));
    }
}
add_action('save_post', 'ccb_save_meta');

// Admin settings page for managing rooms
function ccb_admin_menu() {
    add_menu_page(
        'Class Cancel Booking Settings',
        'CCB Settings',
        'manage_options',
        'ccb-settings',
        'ccb_settings_page',
        'dashicons-admin-settings',
        80
    );
}
add_action('admin_menu', 'ccb_admin_menu');

function ccb_settings_init() {
    register_setting('ccb_settings_group', 'ccb_room_numbers', [
        'sanitize_callback' => 'ccb_sanitize_room_numbers',
        'default' => ['Room 101', 'Room 102', 'Room 103']
    ]);

    add_settings_section(
        'ccb_rooms_section',
        'Manage Room Numbers',
        'ccb_rooms_section_callback',
        'ccb-settings'
    );

    add_settings_field(
        'ccb_room_numbers',
        'Available Rooms',
        'ccb_room_numbers_field_callback',
        'ccb-settings',
        'ccb_rooms_section'
    );
}
add_action('admin_init', 'ccb_settings_init');

function ccb_sanitize_room_numbers($input) {
    if (empty($input)) {
        return [];
    }
    $rooms = array_map('sanitize_text_field', array_filter(explode("\n", trim($input))));
    $rooms = array_unique(array_filter($rooms, 'strlen'));
    return $rooms;
}

function ccb_rooms_section_callback() {
    echo '<p>Enter the room numbers available for booking. Each room should be on a new line.</p>';
}

function ccb_room_numbers_field_callback() {
    $rooms = get_option('ccb_room_numbers', ['Room 101', 'Room 102', 'Room 103']);
    ?>
    <textarea name="ccb_room_numbers" rows="5" cols="50"><?php echo esc_textarea(implode("\n", $rooms)); ?></textarea>
    <p class="description">Enter one room number per line. Empty lines or duplicates will be ignored.</p>
    <?php
}

function ccb_settings_page() {
    ?>
    <div class="wrap">
        <h1>Class Cancel Booking Settings</h1>
        <?php if (isset($_GET['settings-updated'])) : ?>
            <div class="notice notice-success is-dismissible">
                <p><strong>Settings saved.</strong></p>
            </div>
        <?php endif; ?>
        <form method="post" action="options.php">
            <?php
            settings_fields('ccb_settings_group');
            do_settings_sections('ccb-settings');
            submit_button();
            ?>
        </form>
    </div>
    <?php
}

// Shortcode to show all cancelled classes with booking button
function ccb_classes_shortcode() {
    ob_start();

    if (isset($_GET['ccb_posted']) && $_GET['ccb_posted'] === 'success') {
        echo '<div class="ccb-message" style="padding:10px; background:#d1ecf1; color:#0c5460; margin-bottom:20px; border:1px solid #bee5eb;">Operation Successful!</div>';
    } elseif (isset($_GET['ccb_booked']) && $_GET['ccb_booked'] === 'success') {
        echo '<div class="ccb-message" style="padding:10px; background:#d4edda; color:#155724; margin-bottom:20px; border:1px solid #c3e6cb;">Operation Successful!</div>';
    } elseif (isset($_GET['ccb_cancel_booking']) && $_GET['ccb_cancel_booking'] === 'success') {
        echo '<div class="ccb-message" style="padding:10px; background:#fff3cd; color:#856404; margin-bottom:20px; border:1px solid #ffeeba;">Cancel Successful!</div>';
    }

    echo "<style>
        .ccb-message {
            transition: opacity 1s ease-out;
        }
        .ccb-message.fade-out {
            opacity: 0;
        }
    </style>
    <script>
        setTimeout(function() {
            document.querySelectorAll('.ccb-message').forEach(function(el) {
                el.classList.add('fade-out');
                setTimeout(function() {
                    el.style.display = 'none';
                }, 1000);
            });
        }, 5000);
    </script>";

    echo '<h2 style="text-align:center; margin: 30px 0 20px;">Rooms Lists</h2>';

    $paged = get_query_var('paged') ? get_query_var('paged') : 1;

    $args = [
        'post_type' => 'cancelled_class',
        'posts_per_page' => 10,
        'paged' => $paged,
    ];
    $query = new WP_Query($args);

    echo '<ul style="list-style:none; padding:0;">';
    while ($query->have_posts()) {
        $query->the_post();
        $id = get_the_ID();
        $time = get_post_meta($id, '_ccb_time', true);
        $room = get_post_meta($id, '_ccb_room', true);
        $date = get_post_meta($id, '_ccb_date', true);
        $booked = get_post_meta($id, '_ccb_booked', true);
        $booked_by = get_post_meta($id, '_ccb_booked_by', true);
        $author = get_the_author();
        $posted_time = get_the_date('F j, Y \a\t g:i a');

        echo '<li style="margin-bottom: 20px; padding: 15px; background: #f9f9f9; border-radius: 8px; border: 1px solid #ddd;">';
        echo '🏠 Room: <strong>' . esc_html($room) . '</strong><br>';
        echo '⌚ Time: <strong>' . esc_html($time) . '</strong><br>';
        echo '📅 Date: <strong>' . esc_html($date) . '</strong><br>';
        echo '<small>Posted by <b>' . esc_html($author) . '</b> on ' . esc_html($posted_time) . '</small><br>';

        if ($booked !== 'yes' && is_user_logged_in()) {
            echo "<form method='post' style='display:inline-block; margin-top:10px;'>
        <input type='hidden' name='ccb_book_class' value='$id'>
        <button type='submit' style='padding:5px 10px; background-color: green; color: white;'>Book</button>
      </form>";
        } elseif ($booked === 'yes') {
            echo "<div style='margin-top:10px;'>Booked by: <strong>" . esc_html($booked_by) . "</strong></div>";
        }

        echo '</li>';
    }
    echo '</ul>';

    $big = 999999999;
    echo paginate_links([
        'base' => str_replace($big, '%#%', esc_url(get_pagenum_link($big))),
        'format' => '?paged=%#%',
        'current' => max(1, $paged),
        'total' => $query->max_num_pages,
        'prev_text' => '« Prev',
        'next_text' => 'Next »',
        'type' => 'list',
    ]);

    wp_reset_postdata();
    return ob_get_clean();
}
add_shortcode('ccb_classes', 'ccb_classes_shortcode');

// Handle booking
function ccb_handle_booking() {
    if (isset($_POST['ccb_book_class']) && is_user_logged_in()) {
        $post_id = intval($_POST['ccb_book_class']);
        $booked = get_post_meta($post_id, '_ccb_booked', true);
        if ($booked !== 'yes') {
            $user = wp_get_current_user();
            update_post_meta($post_id, '_ccb_booked', 'yes');
            update_post_meta($post_id, '_ccb_booked_by', $user->display_name);
        }
        $redirect_url = add_query_arg('ccb_booked', 'success', $_SERVER['REQUEST_URI']);
        wp_redirect($redirect_url);
        exit;
    }
}
add_action('init', 'ccb_handle_booking');

// Cancel booking
function ccb_handle_cancel_booking() {
    if (isset($_POST['ccb_cancel_booking']) && is_user_logged_in()) {
        $post_id = intval($_POST['ccb_cancel_booking']);
        $user = wp_get_current_user();
        $booked_by = get_post_meta($post_id, '_ccb_booked_by', true);
        if ($booked_by === $user->display_name) {
            update_post_meta($post_id, '_ccb_booked', 'no');
            update_post_meta($post_id, '_ccb_booked_by', '');
        }
        wp_redirect(add_query_arg('ccb_cancel_booking', 'success', $_SERVER['REQUEST_URI']));
        exit;
    }
}
add_action('init', 'ccb_handle_cancel_booking');

// My bookings
function ccb_my_bookings_shortcode() {
    if (!is_user_logged_in()) return 'Please log in to view your bookings.';
    $user = wp_get_current_user();

    $paged = get_query_var('paged') ? get_query_var('paged') : (get_query_var('page') ? get_query_var('page') : 1);

    $args = [
        'post_type' => 'cancelled_class',
        'posts_per_page' => 5,
        'paged' => $paged,
        'meta_query' => [
            ['key' => '_ccb_booked_by', 'value' => $user->display_name, 'compare' => '=']
        ]
    ];



    $query = new WP_Query($args);
    ob_start();
    echo '<h3>Your Booked Classes</h3>';

    if ($query->have_posts()) {
        echo '<ul>';
        while ($query->have_posts()) {
            $query->the_post();
            $id = get_the_ID();
            $time = get_post_meta($id, '_ccb_time', true);
            $room = get_post_meta($id, '_ccb_room', true);
            $date = get_post_meta($id, '_ccb_date', true);

            echo '<li> 🏠 Room: <strong>' . esc_html($room) . '</strong><br>⌚ Time: ' . esc_html($time);
            if (!empty($date)) {
                echo '<br>📅 Date: ' . esc_html($date);
            }
            echo "<br><form method='post' style='display:inline; margin-left:10px;'>
        <input type='hidden' name='ccb_cancel_booking' value='$id'>
        <button type='submit' style='background-color: red; color: white; padding:5px 10px;'>Cancel Booking</button>
      </form></li><br>";
        }
        echo '</ul>';

        $big = 999999999;
        echo paginate_links([
            'base' => str_replace($big, '%#%', esc_url(get_pagenum_link($big))),
            'format' => '?paged=%#%',
            'current' => max(1, $paged),
            'total' => $query->max_num_pages
        ]);
    } else {
        echo 'You have not booked any classes yet.';
    }

    wp_reset_postdata();
    return ob_get_clean();
}
add_shortcode('ccb_my_bookings', 'ccb_my_bookings_shortcode');

// Post a cancellation (frontend form)
function ccb_post_cancellation_form() {
    if (!is_user_logged_in()) return 'Please log in to submit a cancelled class.';
    $rooms = get_option('ccb_room_numbers', ['Room 101', 'Room 102', 'Room 103']);
    ob_start(); ?>
    <h3>Post a Cancelled Class</h3>
    <form method="post" action="">
        <label>🏠 Room:<br>
            <select name="ccb_post_room" required>
                <option value="">Select a room</option>
                <?php foreach ($rooms as $room) : ?>
                    <option value="<?php echo esc_attr($room); ?>"><?php echo esc_html($room); ?></option>
                <?php endforeach; ?>
            </select>
        </label><br><br>
        <label>⌚ Time:<br><input type="text" name="ccb_post_time" required></label><br><br>
        <label>📅 Date:<br><input type="date" name="ccb_post_date" required></label><br><br>
        <button type="submit" name="ccb_submit_class">Submit</button>
    </form>
    <?php return ob_get_clean();
}
add_shortcode('ccb_post_cancellation', 'ccb_post_cancellation_form');

// Handle post form submission
function ccb_handle_frontend_submission() {
    if (isset($_POST['ccb_submit_class']) && is_user_logged_in()) {
        // Validate inputs
        $room = isset($_POST['ccb_post_room']) ? sanitize_text_field($_POST['ccb_post_room']) : '';
        $time = isset($_POST['ccb_post_time']) ? sanitize_text_field($_POST['ccb_post_time']) : '';
        $date = isset($_POST['ccb_post_date']) ? sanitize_text_field($_POST['ccb_post_date']) : '';

        // Check if all required fields are filled
        if (empty($room) || empty($time) || empty($date)) {
            wp_redirect(add_query_arg('ccb_posted', 'error', $_SERVER['REQUEST_URI']));
            exit;
        }

        $title = "Cancelled Class - Room: $room, Time: $time";

        $post_id = wp_insert_post([
            'post_type' => 'cancelled_class',
            'post_title' => $title,
            'post_status' => 'publish',
            'post_author' => get_current_user_id(),
        ]);

        if ($post_id && !is_wp_error($post_id)) {
            update_post_meta($post_id, '_ccb_time', $time);
            update_post_meta($post_id, '_ccb_room', $room);
            update_post_meta($post_id, '_ccb_date', $date);
            update_post_meta($post_id, '_ccb_booked', 'no');
            update_post_meta($post_id, '_ccb_booked_by', '');
            $redirect_url = add_query_arg('ccb_posted', 'success', wp_get_referer() ?: home_url());
        } else {
            $redirect_url = add_query_arg('ccb_posted', 'error', wp_get_referer() ?: home_url());
        }

        wp_redirect($redirect_url);
        exit;
    }
}
add_action('init', 'ccb_handle_frontend_submission');

// Delete post (by author)
function ccb_handle_post_deletion() {
    if (isset($_POST['ccb_delete_post']) && is_user_logged_in()) {
        $post_id = intval($_POST['ccb_delete_post']);
        if (get_post_field('post_author', $post_id) == get_current_user_id()) {
            wp_delete_post($post_id, true);
        }
        wp_redirect(add_query_arg('ccb_delete', 'success', $_SERVER['REQUEST_URI']));
        exit;
    }
}
add_action('init', 'ccb_handle_post_deletion');

// User's posted classes
function ccb_user_posted_classes() {
    $user_id = get_current_user_id();

    $paged = get_query_var('paged') ? get_query_var('paged') : (get_query_var('page') ? get_query_var('page') : 1);

    $query = new WP_Query([
        'post_type' => 'cancelled_class',
        'author' => $user_id,
        'posts_per_page' => 5,
        'paged' => $paged
    ]);

    ob_start();
    echo '<h3>Your Posted Classes</h3>';

    if ($query->have_posts()) {
        echo '<ul>';
        while ($query->have_posts()) {
            $query->the_post();
            $id = get_the_ID();
            $time = get_post_meta($id, '_ccb_time', true);
            $room = get_post_meta($id, '_ccb_room', true);
            $date = get_post_meta($id, '_ccb_date', true);
            $booked = get_post_meta($id, '_ccb_booked', true);
            $booked_by = get_post_meta($id, '_ccb_booked_by', true);

            echo '<li> 🏠 Room: <strong>' . esc_html($room) . '</strong><br> ⌚ Time: ' . esc_html($time);
            if (!empty($date)) {
                echo '<br>📅 Date: ' . esc_html($date);
            }
            echo ' <br>➡️ Status: ' . ($booked === 'yes' ? "Booked by $booked_by" : "Available");
            echo "<br><form method='post' style='display:inline; margin-left:5px;'>
        <input type='hidden' name='ccb_delete_post' value='$id'>
        <button type='submit' style='background-color: red; color: white; padding:5px 10px;'>Delete</button>
      </form></li><br>";
        }
        echo '</ul>';

        $big = 999999999;
        echo paginate_links([
            'base' => str_replace($big, '%#%', esc_url(get_pagenum_link($big))),
            'format' => '?paged=%#%',
            'current' => max(1, $paged),
            'total' => $query->max_num_pages
        ]);
    } else {
        echo 'You have not posted any classes yet.';
    }

    wp_reset_postdata();
    return ob_get_clean();
}
add_shortcode('ccb_user_posted_classes', 'ccb_user_posted_classes');

// Dashboard with tabs
function ccb_user_dashboard_shortcode() {
    if (!is_user_logged_in()) return 'Please <a href="' . wp_login_url() . '">Log in</a> to access your dashboard.';
    ob_start(); ?>
    <style>
        .ccb-tabs { display: flex; gap: 15px; margin-bottom: 20px; }
        .ccb-tab { cursor: pointer; padding: 8px 15px; background: #eee; border-radius: 5px; }
        .ccb-tab.active { background: #0073aa; color: white; }
        .ccb-tab-content { display: none; }
        .ccb-tab-content.active { display: block; }
    </style>
    <div class="ccb-dashboard">
        <div class="ccb-tabs">
            <div class="ccb-tab active" data-tab="submit">Submit New</div>
            <div class="ccb-tab" data-tab="booked">Booked Classes</div>
            <div class="ccb-tab" data-tab="posted">Posted Classes</div>
        </div>
        <div class="ccb-tab-content" id="tab-booked"><?php echo ccb_my_bookings_shortcode(); ?></div>
        <div class="ccb-tab-content" id="tab-posted"><?php echo ccb_user_posted_classes(); ?></div>
        <div class="ccb-tab-content active" id="tab-submit"><?php echo ccb_post_cancellation_form(); ?></div>
    </div>
    <script>
        document.querySelectorAll('.ccb-tab').forEach(tab => {
            tab.addEventListener('click', () => {
                document.querySelectorAll('.ccb-tab').forEach(t => t.classList.remove('active'));
                document.querySelectorAll('.ccb-tab-content').forEach(c => c.classList.remove('active'));
                tab.classList.add('active');
                document.getElementById('tab-' + tab.dataset.tab).classList.add('active');
            });
        });
    </script>
    <?php return ob_get_clean();
}
add_shortcode('ccb_user_dashboard', 'ccb_user_dashboard_shortcode');
?>