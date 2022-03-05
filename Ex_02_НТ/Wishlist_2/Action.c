Action()
{
    seconds = functiontime(x);
    lr_save_int(seconds, "SEC");

	lr_start_transaction("1_begin");

/*Correlation comment: Automatic rules - Do not change!  
Original value='authentication' 
Name ='controller' 
Type ='Rule' 
AppName ='vk' 
RuleName ='3'*/
	web_reg_save_param_regexp(
		"ParamName=controller",
		"RegExp=controller=(.*?)\"\\ method",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/index.php*",
		LAST);

	web_reg_find("Search=All",
		"Text=Already registered",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='my-account' 
Name ='back' 
Type ='Rule' 
AppName ='test1' 
RuleName ='12'*/
	web_reg_save_param_regexp(
		"ParamName=back",
		"RegExp=controller=(.*?)\"\\ title",
		"Ordinal=36",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/index.php*",
		LAST);

	web_url("index.php", 
		"URL=http://automationpractice.com/index.php?controller=authentication&back=my-account", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("1_begin",LR_AUTO);

	lr_start_transaction("2_login");

/*Correlation comment - Do not change!  Original value='279ce434016d7cf72c9f127af85c4679' Name ='token' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=token",
		"RegExp==\\ '(.*?)';\\\nvar\\ usingSecureMode\\ ",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/index.php*",
		LAST);

	web_reg_find("Search=All",
		"Text=My account",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='mywishlist' 
Name ='controller_1' 
Type ='Rule' 
AppName ='test1' 
RuleName ='12'*/
	web_reg_save_param_regexp(
		"ParamName=controller_1",
		"RegExp=controller=(.*?)\"\\ title",
		"Ordinal=23",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/index.php*",
		LAST);

	web_submit_data("index.php_2",
		"Action=http://automationpractice.com/index.php?controller={controller}",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?controller={controller}&back={back}",
		"Snapshot=t25.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=email", "Value={login}", ENDITEM,
		"Name=passwd", "Value={password}", ENDITEM,
		"Name=back", "Value={back}", ENDITEM,
		"Name=SubmitLogin", "Value=", ENDITEM,
		LAST);

	lr_end_transaction("2_login",LR_AUTO);

	lr_start_transaction("3_wishlist");

	web_url("My wishlists",
		"URL=http://automationpractice.com/index.php?fc=module&module=blockwishlist&controller={controller_1}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?controller={back}",
		"Snapshot=t26.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("3_wishlist",LR_AUTO);

	lr_start_transaction("4_add_wishlist");

	web_reg_find("Search=All",
		"Text=My wishlists",
		LAST);

	web_submit_data("index.php_3",
		"Action=http://automationpractice.com/index.php?fc=module&module=blockwishlist&controller={controller_1}",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?fc=module&module=blockwishlist&controller={controller_1}",
		"Snapshot=t27.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=token", "Value={token}", ENDITEM,
		"Name=name", "Value={SEC}", ENDITEM,
		"Name=submitWishlist", "Value=", ENDITEM,
		LAST);

	lr_end_transaction("4_add_wishlist",LR_AUTO);

	lr_start_transaction("5_logout");

	web_reg_find("Search=All",
		"Text=Sign in",
		LAST);

	web_url("Sign out",
		"URL=http://automationpractice.com/index.php?mylogout=",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?fc=module&module=blockwishlist&controller={controller_1}",
		"Snapshot=t28.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("5_logout",LR_AUTO);

	return 0;
}