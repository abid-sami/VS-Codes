v<?php
/**
 * Plugin Name: Author Product Seller
 * Description: Allow author users to sell WooCommerce products with extra fields and frontend dashboard.
 * Version: 1.0
 * Author: ChatGPT for Sami
 */

// Register custom fields
add_action('add_meta_boxes', function () {
    add_meta_box('custom_product_fields', 'Extra Product Info', 'custom_product_fields_callback', 'product', 'normal', 'high');
});

function custom_product_fields_callback($post) {
    $contact = get_post_meta($post->ID, '_contact_number', true);
    $semester = get_post_meta($post->ID, '_semester_number', true);
    $facebook = get_post_meta($post->ID, '_facebook_id', true);
    $varsity = get_post_meta($post->ID, '_varsity_name', true);
    $varsities = get_option('varsity_options', []);

    echo '<label>Contact Number: </label><input type="text" name="contact_number" value="' . esc_attr($contact) . '" /><br><br>';
    echo '<label>Semester Number: </label><input type="text" name="semester_number" value="' . esc_attr($semester) . '" /><br><br>';
    echo '<label>Facebook ID Link: </label><input type="url" name="facebook_id" value="' . esc_attr($facebook) . '" /><br><br>';

    echo '<label>Varsity Name: </label><select name="varsity_name">';
    foreach ($varsities as $v) {
        $selected = $varsity == $v ? 'selected' : '';
        echo "<option value='" . esc_attr($v) . "' $selected>" . esc_html($v) . "</option>";
    }
    echo '</select>';
}

// Save custom fields
add_action('save_post', function ($post_id) {
    if (isset($_POST['contact_number'])) update_post_meta($post_id, '_contact_number', sanitize_text_field($_POST['contact_number']));
    if (isset($_POST['semester_number'])) update_post_meta($post_id, '_semester_number', sanitize_text_field($_POST['semester_number']));
    if (isset($_POST['facebook_id'])) update_post_meta($post_id, '_facebook_id', esc_url_raw($_POST['facebook_id']));
    if (isset($_POST['varsity_name'])) update_post_meta($post_id, '_varsity_name', sanitize_text_field($_POST['varsity_name']));
});

// Show on single product
add_action('woocommerce_single_product_summary', function () {
    global $post;
    $contact = get_post_meta($post->ID, '_contact_number', true);
    $semester = get_post_meta($post->ID, '_semester_number', true);
    $facebook = get_post_meta($post->ID, '_facebook_id', true);
    $varsity = get_post_meta($post->ID, '_varsity_name', true);

    echo "<div style='margin-top:20px;'><h3>Seller Info:</h3>";
    echo "<p><strong>Contact:</strong> $contact</p>";
    echo "<p><strong>Semester:</strong> $semester</p>";
    echo "<p><strong>Varsity:</strong> $varsity</p>";
    echo "<p><strong>Facebook:</strong> <a href='$facebook' target='_blank'>$facebook</a></p>";
    echo "</div>";
}, 30);

// Varsity admin settings
add_action('admin_menu', function () {
    add_menu_page('Varsity Options', 'Varsity Options', 'manage_options', 'varsity-options', 'varsity_options_page');
});

function varsity_options_page() {
    if (isset($_POST['varsities'])) {
        update_option('varsity_options', array_map('sanitize_text_field', explode(',', $_POST['varsities'])));
        echo '<div class="updated"><p>Updated</p></div>';
    }
    $varsities = implode(',', get_option('varsity_options', []));
    echo '<h2>Varsity Names</h2>';
    echo '<form method="post"><textarea name="varsities" rows="5" style="width:100%;">' . esc_textarea($varsities) . '</textarea><p>Comma separated.</p><input type="submit" class="button-primary" value="Save"></form>';
}

// Frontend Shortcode: Product Dashboard
add_shortcode('author_product_dashboard', function () {
    if (!is_user_logged_in() || !current_user_can('edit_posts')) return 'Login as an author to access this.';

    ob_start();
    $user_id = get_current_user_id();

    echo "<h2>Your Products</h2>";
    echo '<a href="?add_new_product=1" class="button">Add New Product</a><br><br>';

    if (isset($_GET['delete_product'])) {
        wp_trash_post(intval($_GET['delete_product']));
        echo "<p>Product deleted.</p>";
    }

    if (isset($_POST['save_product'])) {
        $post_data = [
            'post_title' => sanitize_text_field($_POST['product_name']),
            'post_content' => sanitize_textarea_field($_POST['product_details']),
            'post_status' => 'publish',
            'post_type' => 'product',
            'post_author' => $user_id,
        ];

        if ($_POST['product_id']) {
            $post_data['ID'] = intval($_POST['product_id']);
            wp_update_post($post_data);
        } else {
            $product_id = wp_insert_post($post_data);
            wp_set_object_terms($product_id, intval($_POST['product_category']), 'product_cat');
            update_post_meta($product_id, '_regular_price', 0);
            update_post_meta($product_id, '_price', 0);
        }

        $pid = $_POST['product_id'] ?: $product_id;

        update_post_meta($pid, '_contact_number', sanitize_text_field($_POST['contact_number']));
        update_post_meta($pid, '_semester_number', sanitize_text_field($_POST['semester_number']));
        update_post_meta($pid, '_facebook_id', esc_url_raw($_POST['facebook_id']));
        update_post_meta($pid, '_varsity_name', sanitize_text_field($_POST['varsity_name']));

        if (!empty($_FILES['product_image']['name'])) {
            require_once(ABSPATH . 'wp-admin/includes/image.php');
            require_once(ABSPATH . 'wp-admin/includes/file.php');
            require_once(ABSPATH . 'wp-admin/includes/media.php');
            $attachment_id = media_handle_upload('product_image', $pid);
            if (is_numeric($attachment_id)) {
                set_post_thumbnail($pid, $attachment_id);
            }
        }

        echo "<p>Product saved.</p>";
    }

    if (isset($_GET['add_new_product']) || isset($_GET['edit_product'])) {
        $edit_id = $_GET['edit_product'] ?? 0;
        $product = $edit_id ? get_post($edit_id) : null;

        $name = $product ? $product->post_title : '';
        $desc = $product ? $product->post_content : '';
        $contact = get_post_meta($edit_id, '_contact_number', true);
        $semester = get_post_meta($edit_id, '_semester_number', true);
        $facebook = get_post_meta($edit_id, '_facebook_id', true);
        $varsity = get_post_meta($edit_id, '_varsity_name', true);
        $varsities = get_option('varsity_options', []);
        $categories = get_terms('product_cat', ['hide_empty' => false]);

        echo '<form method="post" enctype="multipart/form-data">';
        echo '<input type="hidden" name="product_id" value="' . esc_attr($edit_id) . '">';
        echo '<p><input type="text" name="product_name" value="' . esc_attr($name) . '" placeholder="Product Name" required></p>';
        echo '<p><textarea name="product_details" placeholder="Details">' . esc_textarea($desc) . '</textarea></p>';
        echo '<p><select name="product_category">';
        foreach ($categories as $cat) echo '<option value="' . $cat->term_id . '">' . $cat->name . '</option>';
        echo '</select></p>';
        echo '<p><input type="file" name="product_image"></p>';
        echo '<p><input type="text" name="contact_number" value="' . esc_attr($contact) . '" placeholder="Contact Number" required></p>';
        echo '<p><input type="text" name="semester_number" value="' . esc_attr($semester) . '" placeholder="Semester Number" required></p>';
        echo '<p><input type="url" name="facebook_id" value="' . esc_attr($facebook) . '" placeholder="Facebook Profile Link"></p>';
        echo '<p><select name="varsity_name">';
        foreach ($varsities as $v) {
            $sel = $v == $varsity ? 'selected' : '';
            echo "<option $sel>" . esc_html($v) . "</option>";
        }
        echo '</select></p>';
        echo '<p><input type="submit" name="save_product" value="Save Product" class="button-primary"></p>';
        echo '</form>';
    }

    $args = [
        'post_type' => 'product',
        'author' => $user_id,
        'posts_per_page' => -1
    ];
    $products = new WP_Query($args);

    echo '<ul>';
    while ($products->have_posts()) {
        $products->the_post();
        $edit_link = add_query_arg('edit_product', get_the_ID());
        $delete_link = add_query_arg('delete_product', get_the_ID());
        echo '<li><a href="' . get_permalink() . '">' . get_the_title() . '</a> | <a href="' . $edit_link . '">Edit</a> | <a href="' . $delete_link . '">Delete</a></li>';
    }
    wp_reset_postdata();
    echo '</ul>';

    return ob_get_clean();
});
