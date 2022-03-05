Action()
{

	lr_start_transaction("1_begin");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("index.php", 
		"URL=http://automationpractice.com/index.php?controller=authentication&back=my-account", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/themes/default-bootstrap/font/fontawesome-webfont.woff?v=3.2.1", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/footer-bg.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/jquery/uniform/sprite.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/autoload/uniform.default.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/order-step-done-last.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/order-step-a.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/order-step-current.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		LAST);

	lr_end_transaction("1_begin",LR_AUTO);

	lr_start_transaction("2_login");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://automationpractice.com");

	web_submit_data("index.php_2", 
		"Action=http://automationpractice.com/index.php?controller=authentication", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=authentication&back=my-account", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=email", "Value=derejenets@ramler.ru", ENDITEM, 
		"Name=passwd", "Value=123Test", ENDITEM, 
		"Name=back", "Value=my-account", ENDITEM, 
		"Name=SubmitLogin", "Value=", ENDITEM, 
		LAST);

	lr_end_transaction("2_login",LR_AUTO);

	lr_start_transaction("3_wishlist");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(10);

	web_url("My wishlists", 
		"URL=http://automationpractice.com/index.php?fc=module&module=blockwishlist&controller=mywishlist", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=my-account", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_wishlist",LR_AUTO);

	lr_start_transaction("4_add_wishlist");

	web_add_header("Origin", 
		"http://automationpractice.com");

	web_submit_data("index.php_3", 
		"Action=http://automationpractice.com/index.php?fc=module&module=blockwishlist&controller=mywishlist", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?fc=module&module=blockwishlist&controller=mywishlist", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=token", "Value=279ce434016d7cf72c9f127af85c4679", ENDITEM, 
		"Name=name", "Value=test555", ENDITEM, 
		"Name=submitWishlist", "Value=", ENDITEM, 
		LAST);

	lr_end_transaction("4_add_wishlist",LR_AUTO);

	lr_start_transaction("5_logout");

	web_url("Sign out", 
		"URL=http://automationpractice.com/index.php?mylogout=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?fc=module&module=blockwishlist&controller=mywishlist", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("5_logout",LR_AUTO);

	return 0;
}