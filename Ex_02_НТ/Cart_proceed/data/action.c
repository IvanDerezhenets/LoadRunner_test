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
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/themes/default-bootstrap/font/fontawesome-webfont.woff?v=3.2.1", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/footer-bg.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/jquery/uniform/sprite.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/autoload/uniform.default.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/bg_bt.gif", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/functional-bt-shadow.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/product_list.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/price-container-bg.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/product_list.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/order-step-a.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/order-step-current.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/order-step-done.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/order-step-done-last.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/bankwire.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/cheque.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
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
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=email", "Value=derejenets@ramler.ru", ENDITEM, 
		"Name=passwd", "Value=123Test", ENDITEM, 
		"Name=back", "Value=my-account", ENDITEM, 
		"Name=SubmitLogin", "Value=", ENDITEM, 
		LAST);

	lr_end_transaction("2_login",LR_AUTO);

	lr_start_transaction("3_choose_clothes");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("Dresses", 
		"URL=http://automationpractice.com/index.php?id_category=8&controller=category", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=my-account", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/img/c/8-category_default.jpg", "Referer=http://automationpractice.com/index.php?id_category=8&controller=category", ENDITEM, 
		"Url=/js/jquery/ui/themes/base/images/ui-bg_flat_75_ffffff_40x100.png", "Referer=http://automationpractice.com/js/jquery/ui/themes/base/jquery.ui.theme.css", ENDITEM, 
		"Url=/js/jquery/ui/themes/base/images/ui-bg_highlight-soft_75_cccccc_1x100.png", "Referer=http://automationpractice.com/js/jquery/ui/themes/base/jquery.ui.theme.css", ENDITEM, 
		"Url=/js/jquery/ui/themes/base/images/ui-bg_glass_75_e6e6e6_1x400.png", "Referer=http://automationpractice.com/js/jquery/ui/themes/base/jquery.ui.theme.css", ENDITEM, 
		LAST);

	web_add_header("Origin", 
		"http://automationpractice.com");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(6);

	web_submit_data("index.php_3", 
		"Action=http://automationpractice.com/index.php?rand=1645606426876", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?id_category=8&controller=category", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=controller", "Value=cart", ENDITEM, 
		"Name=add", "Value=1", ENDITEM, 
		"Name=ajax", "Value=true", ENDITEM, 
		"Name=qty", "Value=1", ENDITEM, 
		"Name=id_product", "Value=4", ENDITEM, 
		"Name=token", "Value=702845b18252838dcfe693b22f279bf0", ENDITEM, 
		EXTRARES, 
		"Url=/img/p/1/0/10-cart_default.jpg", "Referer=http://automationpractice.com/index.php?id_category=8&controller=category", ENDITEM, 
		LAST);

	lr_end_transaction("3_choose_clothes",LR_AUTO);

	lr_start_transaction("4_checkout");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(18);

	web_url("index.php_4", 
		"URL=http://automationpractice.com/index.php?controller=order", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?id_category=8&controller=category", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	lr_think_time(10);

	web_url("Proceed to checkout", 
		"URL=http://automationpractice.com/index.php?controller=order&step=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=order", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"http://automationpractice.com");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(4);

	web_submit_data("index.php_5", 
		"Action=http://automationpractice.com/index.php?controller=order", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=order&step=1", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=id_address_delivery", "Value=643434", ENDITEM, 
		"Name=same", "Value=1", ENDITEM, 
		"Name=message", "Value=", ENDITEM, 
		"Name=step", "Value=2", ENDITEM, 
		"Name=back", "Value=", ENDITEM, 
		"Name=processAddress", "Value=", ENDITEM, 
		LAST);

	lr_think_time(4);

	web_submit_data("index.php_6", 
		"Action=http://automationpractice.com/index.php?controller=order&multi-shipping=", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=order", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=delivery_option[643434]", "Value=2,", ENDITEM, 
		"Name=cgv", "Value=1", ENDITEM, 
		"Name=step", "Value=3", ENDITEM, 
		"Name=back", "Value=", ENDITEM, 
		"Name=processCarrier", "Value=", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	lr_think_time(6);

	web_url("Pay by bank wire (order processing will be longer)", 
		"URL=http://automationpractice.com/index.php?fc=module&module=bankwire&controller=payment", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=order&multi-shipping=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"http://automationpractice.com");

	web_submit_data("index.php_7", 
		"Action=http://automationpractice.com/index.php?fc=module&module=bankwire&controller=validation", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?fc=module&module=bankwire&controller=payment", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=currency_payement", "Value=1", ENDITEM, 
		LAST);

	lr_end_transaction("4_checkout",LR_AUTO);

	lr_start_transaction("5_logout");

	web_url("Sign out", 
		"URL=http://automationpractice.com/index.php?mylogout=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=order-confirmation&id_cart=4262502&id_module=3&id_order=404442&key=78e55637ce01c42cd4565112055ff05d", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}