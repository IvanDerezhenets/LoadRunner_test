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
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/themes/default-bootstrap/font/fontawesome-webfont.woff?v=3.2.1", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/footer-bg.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/jquery/uniform/sprite.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/autoload/uniform.default.css", ENDITEM, 
		"Url=/themes/default-bootstrap/img/icon/form-ok.png", "Referer=http://automationpractice.com/themes/default-bootstrap/css/global.css", ENDITEM, 
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
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=email", "Value=derejenets@ramler.ru", ENDITEM, 
		"Name=passwd", "Value=123Test", ENDITEM, 
		"Name=back", "Value=my-account", ENDITEM, 
		"Name=SubmitLogin", "Value=", ENDITEM, 
		LAST);

	lr_end_transaction("2_login",LR_AUTO);

	lr_start_transaction("3_adress");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(13);

	web_url("My addresses", 
		"URL=http://automationpractice.com/index.php?controller=addresses", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=my-account", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_adress",LR_AUTO);

	lr_think_time(12);

	lr_start_transaction("4_nwe_adress");

	web_url("Add a new address", 
		"URL=http://automationpractice.com/index.php?controller=address", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=addresses", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"http://automationpractice.com");

	web_submit_data("index.php_3", 
		"Action=http://automationpractice.com/index.php?controller=address", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=address", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstname", "Value=Ivan", ENDITEM, 
		"Name=lastname", "Value=Ivan", ENDITEM, 
		"Name=company", "Value=", ENDITEM, 
		"Name=address1", "Value=12413", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value=Moscow", ENDITEM, 
		"Name=id_state", "Value=16", ENDITEM, 
		"Name=postcode", "Value=10846", ENDITEM, 
		"Name=id_country", "Value=21", ENDITEM, 
		"Name=phone", "Value=+79245684951", ENDITEM, 
		"Name=phone_mobile", "Value=", ENDITEM, 
		"Name=dni", "Value=", ENDITEM, 
		"Name=other", "Value=", ENDITEM, 
		"Name=alias", "Value=new_adress", ENDITEM, 
		"Name=id_address", "Value=0", ENDITEM, 
		"Name=select_address", "Value=0", ENDITEM, 
		"Name=token", "Value=702845b18252838dcfe693b22f279bf0", ENDITEM, 
		"Name=submitAddress", "Value=", ENDITEM, 
		LAST);

	lr_end_transaction("4_nwe_adress",LR_AUTO);

	lr_start_transaction("5_logout");

	web_url("Sign out", 
		"URL=http://automationpractice.com/index.php?mylogout=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=addresses", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}