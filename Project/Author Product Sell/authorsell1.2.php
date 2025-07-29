<?php
/**
 * Plugin Name: Author Product Seller
 * Description: Allow author users to sell WooCommerce products with extra fields and frontend dashboard.
 * Version: 1.1
 * Author: Ragib Hasan Abid Sami
 */

// Register custom fields
add_action('add_meta_boxes', function () {
    add_meta_box('custom_product_fields', 'Extra Product Info', 'custom_product_fields_callback', 'product', 'normal', 'high');
});

function custom_product_fields_callback($post) {
    $seller_name = get_post_meta(get_the_ID(), '_seller_name', true);
    $condition = get_post_meta(get_the_ID(), '_product_condition', true);
    $contact = get_post_meta($post->ID, '_contact_number', true);
    $semester = get_post_meta($post->ID, '_semester_number', true);
    $facebook = get_post_meta($post->ID, '_facebook_id', true);
    $varsity = get_post_meta($post->ID, '_varsity_name', true);
    $varsities = get_option('varsity_options', []);

    echo '<label>Seller Nickname: </label><input type="text" name="seller_name" value="' . esc_attr($seller_name) . '" /><br><br>';
    echo '<label>Product Condition: </label><select name="product_condition">';
    echo '<option value="">Select Condition</option>';
    echo '<option value="Used"' . selected($condition, 'Used', false) . '>Used</option>';
    echo '<option value="New"' . selected($condition, 'New', false) . '>New</option>';
    echo '</select><br><br>';
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
    if (isset($_POST['seller_name'])) update_post_meta($post_id, '_seller_name', sanitize_text_field($_POST['seller_name']));
    if (isset($_POST['product_condition'])) update_post_meta($post_id, '_product_condition', sanitize_text_field($_POST['product_condition']));
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
    $seller_name = get_post_meta($post->ID, '_seller_name', true);
    $condition = get_post_meta(get_the_ID(), '_product_condition', true);

    // Product details
    echo '<br><div style="margin-bottom:8px; color:#E60E0E;"><strong>' . esc_html($condition ? $condition : 'N/A') . '</strong></div>';

    echo "<div style='margin-top:20px;'><h2 style='color:#bd5219;'>Seller Info:</h2>";
    echo "<p><strong>👤 Nickname:</strong> " . esc_html($seller_name) . "</p>";
    echo "<p><strong>📞 Contact:</strong> $contact</p>";
    echo "<p><strong>🗓️ Semester:</strong> $semester</p>";
    echo "<p><strong>🏫 Varsity:</strong> $varsity</p>";
    echo "<p><strong>🔗 Facebook:</strong> <a href='$facebook' target='_blank'>$facebook</a></p>";
    // Add Call Now and Message Now buttons
    echo "<div style='margin-top:14px;'>";
    if ($contact) {
        echo "<a href='tel:" . esc_attr($contact) . "' style='display:inline-block;padding:8px 18px;margin-right:10px;background:#28a745;color:#fff;border-radius:5px;text-decoration:none;font-weight:500;'>Call Now</a>";
    }
    if ($facebook) {
        echo "<a href='" . esc_url($facebook) . "' target='_blank' style='display:inline-block;padding:8px 18px;background:#1C68FA;color:#fff;border-radius:5px;text-decoration:none;font-weight:500;'>Message Now</a>";
    }
    echo "</div>";
    echo "<p>To buy the product, Call or Message the seller...</p>";;
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
    if (!is_user_logged_in() || !current_user_can('edit_posts')) return '<div class="notice">Please login as an author or admin to access this panel.</div>';

    ob_start();
    $user_id = get_current_user_id();
    $is_admin = current_user_can('manage_options');

    // Handle delete
    if (isset($_GET['delete_product'])) {
        $del_id = intval($_GET['delete_product']);
        $post = get_post($del_id);
        if ($post && ($post->post_author == $user_id || $is_admin)) {
            wp_trash_post($del_id);
            echo "<div class='alert success'>Product deleted.</div>";
        } else {
            echo "<div class='alert error'>You are not allowed to delete this product.</div>";
        }
    }

    // Handle save
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
        }

        $pid = $_POST['product_id'] ?: $product_id;
        update_post_meta($pid, '_price', floatval($_POST['product_price']));
        update_post_meta($pid, '_seller_name', sanitize_text_field($_POST['seller_name']));
        update_post_meta($pid, '_contact_number', sanitize_text_field($_POST['contact_number']));
        update_post_meta($pid, '_semester_number', sanitize_text_field($_POST['semester_number']));
        update_post_meta($pid, '_facebook_id', esc_url_raw($_POST['facebook_id']));
        update_post_meta($pid, '_varsity_name', sanitize_text_field($_POST['varsity_name']));
        update_post_meta($pid, '_product_condition', sanitize_text_field($_POST['product_condition']));

        if (!empty($_FILES['product_image']['name'])) {
            require_once(ABSPATH . 'wp-admin/includes/image.php');
            require_once(ABSPATH . 'wp-admin/includes/file.php');
            require_once(ABSPATH . 'wp-admin/includes/media.php');
            $attachment_id = media_handle_upload('product_image', $pid);
            if (is_numeric($attachment_id)) {
                set_post_thumbnail($pid, $attachment_id);
            }
        }

        echo "<div class='alert success'>Product Posted Successfully!</div>";
    }

    // Style
    echo <<<STYLE
    <style>
    .product-form, .product-list { max-width: 800px; margin: 20px auto; padding: 20px; background: #fff; border-radius: 10px; box-shadow: 0 4px 8px rgba(0,0,0,0.1); }
    .product-form input, .product-form select, .product-form textarea { width: 100%; padding: 10px; margin-bottom: 15px; border: 1px solid #ddd; border-radius: 5px; }
    .product-form button, .product-list a.button { padding: 4px 10px; font-size: 0.85em; background: #0073aa; color: white; border: none; border-radius: 5px; cursor: pointer; text-decoration: none; display: inline-block; margin: 6px 6px 0 0; }
    .product-form button:hover, .product-list a.button:hover { background: #005f8d; }
    .alert { margin: 10px auto; padding: 10px; max-width: 800px; border-radius: 5px; }
    .alert.success { background: #d4edda; color: #155724; }
    .alert.error { background: #f8d7da; color: #721c24; }
    .product-list ul { list-style: none; padding: 0; }
    .product-list li { padding: 10px 0; border-bottom: 1px solid #ddd; }
    .product-list .product-title { font-size: 1.5em; font-weight: bold; margin-bottom: 6px; display: block; }
    .product-list .button-group { margin-top: 4px; }
    </style>
    STYLE;

    echo '<div class="product-list">';
    echo "<h2>🛍️ Your Products</h2>";
    echo '<a href="?add_new_product=1" class="button">➕ Add New Product</a><br><br>';

    // Add/edit form
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

        echo '<div class="product-form">';
        echo '<h3>' . ($edit_id ? '✏️ Edit Product' : '➕ Add New Product') . '</h3>';
        echo '<form method="post" enctype="multipart/form-data">';
        echo '<input type="hidden" name="product_id" value="' . esc_attr($edit_id) . '">';
        echo '<label for="product_name"><strong>Product Name:</strong></label>';
        echo '<input type="text" id="product_name" name="product_name" value="' . esc_attr($name) . '" placeholder="C++ Book" required>';
        echo '</select>';
        echo '<label for="product_condition"><strong>Product Condition:</strong></label>';
        echo '<select id="product_condition" name="product_condition" required>';
        echo '<option value="">Select Condition</option>';
        echo '<option value="Used"' . (get_post_meta($edit_id, '_product_condition', true) == 'Used' ? ' selected' : '') . '>Used</option>';
        echo '<option value="New"' . (get_post_meta($edit_id, '_product_condition', true) == 'New' ? ' selected' : '') . '>New</option>';
        echo '</select>';
        echo '<label for="product_price"><strong>Product Price: (BDT)</strong></label>';
        echo '<input type="number" step="0.01" min="0" id="product_price" name="product_price" value="' . esc_attr(get_post_meta($edit_id, '_price', true)) . '" placeholder="999" required>';
        echo '<label for="product_details"><strong>Product Details:</strong></label>';
        echo '<textarea id="product_details" name="product_details" placeholder="Details" required>' . esc_textarea($desc) . '</textarea>';
        echo '<label for="product_category"><strong>Product Category:</strong></label>';
        echo '<select id="product_category" name="product_category" required>';
        echo '<option value="">Select Category</option>';
        foreach ($categories as $cat) {
            echo '<option value="' . $cat->term_id . '">' . $cat->name . '</option>';
        }
        echo '</select>';
        echo '<label for="product_image"><strong>Product Image:</strong></label>';
        echo '<input type="file" id="product_image" name="product_image">';

        echo '<h3>👤 Enter Seller Info</h3>';
        echo '<label for="seller_name"><strong>Your Nickname:</strong></label>';
        echo '<input type="text" id="seller_name" name="seller_name" value="' . esc_attr(get_post_meta($edit_id, '_seller_name', true)) . '" placeholder="Neymar" required>';       
        echo '<label for="contact_number"><strong>Contact Number:</strong></label>';
        echo '<input type="text" id="contact_number" name="contact_number" value="' . esc_attr($contact) . '" placeholder="01xxxxxxxx">';
        echo '<label for="semester_number"><strong>Semester Number:</strong></label>';
        echo '<input type="text" id="semester_number" name="semester_number" value="' . esc_attr($semester) . '" placeholder="1st">';
        echo '<label for="facebook_id"><strong>Facebook Profile Link:</strong></label>';
        echo '<input type="url" id="facebook_id" name="facebook_id" value="' . esc_attr($facebook) . '" placeholder="https://www.facebook.com/...........">';
        echo '<label for="varsity_name"><strong>Select University:</strong></label>';
        echo '<select id="varsity_name" name="varsity_name" required>';
        echo '<option value="">Select University</option>';
        foreach ($varsities as $v) {
            $sel = $v == $varsity ? 'selected' : '';
            echo "<option value='" . esc_attr($v) . "' $sel>" . esc_html($v) . "</option>";
        }
        echo '</select>';
        echo '<button type="submit" name="save_product">Submit Post</button>';
        echo '</form></div><hr>';
    }

    // Product List
    $args = ['post_type' => 'product', 'posts_per_page' => -1];
    if (!$is_admin) $args['author'] = $user_id;
    $products = new WP_Query($args);
    echo '<ul>';
    while ($products->have_posts()) {
        $products->the_post();
        $edit_link = add_query_arg('edit_product', get_the_ID());
        $delete_link = add_query_arg('delete_product', get_the_ID());
        $price = get_post_meta(get_the_ID(), '_price', true);
        $seller_name = get_post_meta(get_the_ID(), '_seller_name', true);
        $condition = get_post_meta(get_the_ID(), '_product_condition', true);
        $img = get_the_post_thumbnail(get_the_ID(), 'thumbnail', ['style' => 'max-width:200px; border-radius:8px; margin-bottom:8px;']);
        echo '<li>';
        // Product image
        if ($img) echo '<a href="' . get_permalink() . '">' . $img . '</a>';
        // Product name
        echo '<span class="product-title">' . get_the_title() . '</span>';
        // Product price
        echo '<div style="font-size:1.1em; color:#E60E0E; margin-bottom:8px;">Price: ' . ($price ? wc_price($price) : 'N/A') . '</div>';

        // Buttons
        echo '<div class="button-group">';
        echo '<a href="' . get_permalink() . '" class="button">View</a>';
        echo '<a href="' . $edit_link . '" class="button">Edit</a>';
        echo '<a href="' . $delete_link . '" class="button" onclick="return confirm(\'Delete this product?\')">Delete</a>';
        echo '</div>';
        echo '<br><br>';
        echo '</li>';
    }
    wp_reset_postdata();
    echo '</ul></div>';

    return ob_get_clean();
});
