Action()
{

	lr_start_transaction("1_begin");

	web_reg_save_param_regexp(
		"ParamName=day",
		"RegExp=добавлено: (.*?)&nbsp",
		LAST);
 	
	web_reg_save_param_regexp(
		"ParamName=month",
		"RegExp=добавлено: \d{1,2}&nbsp;(.*?)&nbsp;",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=yy",
		"RegExp=добавлено: \d{1,2}&nbsp;...&nbsp;(.*?)",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=comment_count",
		"RegExp=\êîììåíòîâ:\\s(\\d{1})<",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=first_comment",
		"RegExp=\<div class\=\"post\"\>\\r\\n\\s\+\<p\>(.*?)\<\/p\>",
		"Ordinal=1",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=first_author",
		"RegExp=\<b class\=\"author\"\>(.*?)\<\/b\>",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=all_author",
		"RegExp=\<b class\=\"author\"\>(.*?)\<\/b\>",
		"Ordinal=ALL",
		LAST);	


	web_reg_save_param_regexp(
		"ParamName=procomment",
		"RegExp=\<a href\=\"(.*?)\"\\sclass\=\"comment\"\>Ïðîêîììåíòèðîâàòü\<\/a\>",
		LAST);		

	web_reg_save_param_regexp(
        "ParamName=all_tags",
        "RegExp=\<a href\=\"\/blogs\/iyun\/tags\/\.\+\>(.*?)\<\/a\>",
        "Ordinal=ALL",
        LAST);

			
	web_url("2267",
		"URL=https://www.sql.ru/blogs/iyun/2267", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_output_message(lr_eval_string("{day}-{month}-{year}"));
	
    lr_output_message(lr_eval_string("{comment_count}"));
	
    lr_output_message(lr_eval_string("{first_comment}"));
	
    lr_output_message(lr_eval_string("{first_author}"));
  
    lr_output_message(lr_eval_string("{procomment}"));
	
	lr_end_transaction("1_begin",LR_AUTO);

	return 0;
}
