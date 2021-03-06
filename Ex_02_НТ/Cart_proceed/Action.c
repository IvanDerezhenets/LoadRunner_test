Action()
{

	lr_start_transaction("1_begin");

	web_reg_find("Search=All",
		"Text=Sign in",
		LAST);

	web_url("index.php", 
		"URL=http://automationpractice.com/index.php?controller=authentication&back=my-account", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("1_begin",LR_AUTO);

	lr_start_transaction("2_login");

	web_reg_find("Search=All",
		"Text=Sign out",
		LAST);

/*Correlation comment - Do not change!  Original value='702845b18252838dcfe693b22f279bf0' Name ='token' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=token",
		"RegExp=static_token = '(.*?)'\;",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/index.php*",
		LAST);

	web_submit_data("index.php_2",
		"Action=http://automationpractice.com/index.php?controller=authentication",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?controller=authentication&back=my-account",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=email", "Value={login}", ENDITEM,
		"Name=passwd", "Value={password}", ENDITEM,
		"Name=back", "Value=my-account", ENDITEM,
		"Name=SubmitLogin", "Value=", ENDITEM,
		LAST);

	lr_end_transaction("2_login",LR_AUTO);
    lr_start_transaction("3_choose_clothes");
	    
	web_reg_find("Search=All",
		"Text=Dresses",
		LAST);

	web_reg_find("Search=Body",
		"Text=Product successfully added to your shopping cart",
		LAST);

 web_url("Dresses",
		"URL=http://automationpractice.com/index.php?id_category=8&controller=category", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=my-account", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);


/*Correlation comment - Do not change!  Original value='643434' Name ='id_address_delivery' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=id_address_delivery",
		"RegExp=idAddressDelivery\"\:(.*?)\,",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

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
		"Name=token", "Value={token}", ENDITEM,
		LAST);

	lr_end_transaction("3_choose_clothes",LR_AUTO);

	lr_start_transaction("4_checkout");

	web_reg_find("Search=Body",
		"Text=remove this product from my cart",
		LAST);

	web_url("index.php_4", 
		"URL=http://automationpractice.com/index.php?controller=order", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?id_category=8&controller=category", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

    web_reg_find("Search=All",
		"Text=Choose a delivery address:",
		LAST);
	
    web_url("Proceed to checkout",
		"URL=http://automationpractice.com/index.php?controller=order&step=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://automationpractice.com/index.php?controller=order", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_find("Search=All",
		"Text=Choose a shipping option for this address",
		LAST);
		
	web_submit_data("index.php_5",
		"Action=http://automationpractice.com/index.php?controller=order",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?controller=order&step=1",
		"Snapshot=t7.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=id_address_delivery", "Value={id_address_delivery}", ENDITEM,
		"Name=same", "Value=1", ENDITEM,
		"Name=message", "Value=", ENDITEM,
		"Name=step", "Value=2", ENDITEM,
		"Name=back", "Value=", ENDITEM,
		"Name=processAddress", "Value=", ENDITEM,
		LAST);

	lr_think_time(4);

    web_reg_find("Search=All",
		"Text=Pay by bank wire",
		LAST);
		
	web_submit_data("index.php_6",
		"Action=http://automationpractice.com/index.php?controller=order&multi-shipping=",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?controller=order",
		"Snapshot=t8.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=delivery_option[{id_address_delivery}]", "Value=2,", ENDITEM,
		"Name=cgv", "Value=1", ENDITEM,
		"Name=step", "Value=3", ENDITEM,
		"Name=back", "Value=", ENDITEM,
		"Name=processCarrier", "Value=", ENDITEM,
		LAST);

	web_reg_find("Search=All",
		"Text=You have chosen to pay by bank wire. Here is a short summary of your order",
		LAST);
		
	web_url("Pay by bank wire (order processing will be longer)",
		"URL=http://automationpractice.com/index.php?fc=module&module=bankwire&controller=payment",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?controller=order&multi-shipping=",
		"Snapshot=t9.inf",
		"Mode=HTML",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='4262502' 
Name ='id_cart' 
Type ='Rule' 
AppName ='test1' 
RuleName ='5'*/
	web_reg_save_param_regexp(
		"ParamName=id_cart",
		"RegExp=id_cart=(.*?)&",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/index.php*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='404442' 
Name ='id_order' 
Type ='Rule' 
AppName ='test1' 
RuleName ='6'*/
	web_reg_save_param_regexp(
		"ParamName=id_order",
		"RegExp=id_order=(.*?)&",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/index.php*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='78e55637ce01c42cd4565112055ff05d' 
Name ='key' 
Type ='Rule' 
AppName ='test1' 
RuleName ='7'*/
	web_reg_save_param_regexp(
		"ParamName=key",
		"RegExp=key=(.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/index.php*",
		LAST);

	web_reg_find("Search=All",
		"Text=Your order on My Store is complete.",
		LAST);
		
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

	web_reg_find("Search=All",
		"Text=Sign in",
		LAST);
	
	web_url("Sign out",
		"URL=http://automationpractice.com/index.php?mylogout=",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://automationpractice.com/index.php?controller=order-confirmation&id_cart={id_cart}&id_module=3&id_order={id_order}&key={key}",
		"Snapshot=t11.inf",
		"Mode=HTML",
		LAST);
    lr_end_transaction("5_logout",LR_AUTO);
	return 0;
}
