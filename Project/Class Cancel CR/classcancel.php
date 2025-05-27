<?php
/**
 * Plugin Name: Class Cancel Booking
 * Description: Users can post cancelled classes with time & room, others can book them. Includes full user dashboard.
 * Version: 1.0
 * Author: Sami
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
    $booked = get_post_meta($post->ID, '_ccb_booked', true);
    $booked_by = get_post_meta($post->ID, '_ccb_booked_by', true);
    ?>
    <label>Room No: <input type="text" name="ccb_room" value="<?php echo esc_attr($room); ?>"></label><br><br>
    <label>Time: <input type="text" name="ccb_time" value="<?php echo esc_attr($time); ?>"></label><br><br>
    
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
}
add_action('save_post', 'ccb_save_meta');

// Shortcode to show all cancelled classes with booking button
function ccb_classes_shortcode() {
    ob_start();

    if (isset($_GET['ccb_booked']) && $_GET['ccb_booked'] === 'success') {
        echo '<div style="padding:10px; background:#d4edda; color:#155724; margin-bottom:20px; border:1px solid #c3e6cb;">Class booked successfully!</div>';
    }
    if (isset($_GET['ccb_posted']) && $_GET['ccb_posted'] === 'success') {
        echo '<div style="padding:10px; background:#d1ecf1; color:#0c5460; margin-bottom:20px; border:1px solid #bee5eb;">Class posted successfully!</div>';
    }
    if (isset($_GET['ccb_deleted']) && $_GET['ccb_deleted'] === 'success') {
        echo '<div style="padding:10px; background:#f8d7da; color:#721c24; margin-bottom:20px; border:1px solid #f5c6cb;">Class deleted successfully!</div>';
    }

    $paged = get_query_var('paged') ? get_query_var('paged') : 1;

    $args = [
        'post_type' => 'cancelled_class',
        'posts_per_page' => 20,
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
        echo '⌚ Time : <strong>' . esc_html($time) . '</strong><br>';
        echo '📅 Date : <strong>' . esc_html($date) . '</strong><br>';
        echo '<small>Posted by <em>' . esc_html($author) . '</em> on ' . esc_html($posted_time) . '</small><br>';

        if ($booked !== 'yes' && is_user_logged_in()) {
            echo "<form method='post' style='display:inline-block; margin-top:10px;'>
                    <input type='hidden' name='ccb_book_class' value='$id'>
                    <button type='submit' style='padding:5px 10px;'>Book</button>
                  </form>";
        } elseif ($booked === 'yes') {
            echo "<div style='margin-top:10px;'>Booked by: <strong>" . esc_html($booked_by) . "</strong></div>";
        }

        echo '</li>';
    }
    echo '</ul>';

    // Pagination
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
        wp_redirect($_SERVER['REQUEST_URI']);
        exit;
    }
}
add_action('init', 'ccb_handle_cancel_booking');

// My bookings
function ccb_my_bookings_shortcode() {
    if (!is_user_logged_in()) return 'Please log in to view your bookings.';
    $user = wp_get_current_user();
    $args = [
        'post_type' => 'cancelled_class',
        'posts_per_page' => -1,
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
            echo '<li> 🏠 Room: ' . esc_html($room) . ' <br>⌚ Time: ' . esc_html($time);
            echo "<br><form method='post' style='display:inline; margin-left:10px;'>
                    <input type='hidden' name='ccb_cancel_booking' value='$id'>
                    <button type='submit'>Cancel Booking</button>
                  </form></li><br>";
        }
        echo '</ul>';
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
    ob_start(); ?>
    <h3>Post a Cancelled Class</h3>
    <form method="post">
        <label>🏠 Room:<br><input type="text" name="ccb_post_room" required></label><br><br>
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
        $time = sanitize_text_field($_POST['ccb_post_time']);
        $room = sanitize_text_field($_POST['ccb_post_room']);
        $date = sanitize_text_field($_POST['ccb_post_date']);
        $title = "Cancelled Class - Room: $room, Time: $time";

        $post_id = wp_insert_post([
            'post_type' => 'cancelled_class',
            'post_title' => $title,
            'post_status' => 'publish',
        ]);

        if ($post_id) {
            update_post_meta($post_id, '_ccb_time', $time);
            update_post_meta($post_id, '_ccb_room', $room);
            update_post_meta($post_id, '_ccb_date', $date); // ✅ Corrected position
            update_post_meta($post_id, '_ccb_booked', 'no');
            update_post_meta($post_id, '_ccb_booked_by', '');
        }

        $redirect_url = add_query_arg('ccb_posted', 'success', $_SERVER['REQUEST_URI']);
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
        wp_redirect($_SERVER['REQUEST_URI']);
        exit;
    }
}
add_action('init', 'ccb_handle_post_deletion');

// User's posted classes
function ccb_user_posted_classes() {
    $user_id = get_current_user_id();
    $query = new WP_Query([
        'post_type' => 'cancelled_class',
        'author' => $user_id,
        'posts_per_page' => -1
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
            $booked = get_post_meta($id, '_ccb_booked', true);
            $booked_by = get_post_meta($id, '_ccb_booked_by', true);
            echo '<li>  ⌚ Room: ' . esc_html($room) . '<br>🏠 Time: ' . esc_html($time);
            echo ' <br>➡️ Status: ' . ($booked === 'yes' ? "Booked by $booked_by" : "Available");
            echo "<br><form method='post' style='display:inline; margin-left:5px;'>
                    <input type='hidden' name='ccb_delete_post' value='$id'>
                    <button type='submit'>Delete</button>
                  </form></li><br>";
        }
        echo '</ul>';
    } else {
        echo 'You have not posted any classes yet.';
    }
    wp_reset_postdata();
    return ob_get_clean();
}

// Dashboard with tabs
function ccb_user_dashboard_shortcode() {
    if (!is_user_logged_in()) return 'Please log in to access your dashboard.';
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
