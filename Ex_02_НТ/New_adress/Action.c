Action()
{
    seconds = functiontime(x);
    lr_save_int(seconds, "SEC");

	lr_start_transaction("1_begin");

	web_reg_find("Search=All",
		"Text=Already registered",
		LAST);

	web_url("index.php", 
		"URL=http://automationpractice.com/index.php?controller=authentication&back=my-account", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("1_begin",LR_AUTO);

	lr_start_transaction("2_login");

/*Correlation comment: Automatic rules - Do not change!  
Original value='702845b18252838dcfe693b22f279bf0' 
Name ='token' 
Type ='Rule' 
AppName ='vk' 
RuleName ='AutoGeneratedRuleName_1'*/
	web_reg_save_param_regexp(
		"ParamName=token",
		"RegExp=static_token = '(.*?)'\;",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/index.php*",
		LAST);

	web_reg_find("Search=All",
		"Text=Sign out",
		LAST);

	web_submit_data("index.php_2",
		"Action=http://automationpractice.com/index.php?controller=authentication",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?controller=authentication&back=my-account",
		"Snapshot=t30.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=email", "Value={login}", ENDITEM,
		"Name=passwd", "Value={password}", ENDITEM,
		"Name=back", "Value=my-account", ENDITEM,
		"Name=SubmitLogin", "Value=", ENDITEM,
		LAST);

	lr_end_transaction("2_login",LR_AUTO);

	lr_start_transaction("3_adress");

	web_reg_find("Search=All",
		"Text=Your addresses are listed below",
		LAST);

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


	lr_start_transaction("4_new_adress");

	web_reg_find("Search=All",
		"Text=To add a new address, please fill out the form below",
		LAST);

	web_url("Add a new address",
		"URL=http://automationpractice.com/index.php?controller=address",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?controller=addresses",
		"Snapshot=t32.inf",
		"Mode=HTML",
		LAST);


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
		"Name=lastname", "Value={name}", ENDITEM,
		"Name=company", "Value=", ENDITEM,
		"Name=address1", "Value=12413", ENDITEM,
		"Name=address2", "Value=", ENDITEM,
		"Name=city", "Value={city}", ENDITEM,
		"Name=id_state", "Value=16", ENDITEM,
		"Name=postcode", "Value={postcode}", ENDITEM,
		"Name=id_country", "Value=21", ENDITEM,
		"Name=phone", "Value=+79245684951", ENDITEM,
		"Name=phone_mobile", "Value=", ENDITEM,
		"Name=dni", "Value=", ENDITEM,
		"Name=other", "Value=", ENDITEM,
		"Name=alias", "Value={SEC}", ENDITEM,
		"Name=id_address", "Value=0", ENDITEM,
		"Name=select_address", "Value=0", ENDITEM,
		"Name=token", "Value={token}", ENDITEM,
		"Name=submitAddress", "Value=", ENDITEM,
		LAST);

	lr_end_transaction("4_new_adress",LR_AUTO);

	lr_start_transaction("5_logout");

	web_reg_find("Search=Body",
		"Text=Already registered",
		LAST);

	web_url("Sign out",
		"URL=http://automationpractice.com/index.php?mylogout=",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?controller=addresses",
		"Snapshot=t34.inf",
		"Mode=HTML",
		LAST);
    lr_end_transaction("5_logout",LR_AUTO);
	return 0;
}
