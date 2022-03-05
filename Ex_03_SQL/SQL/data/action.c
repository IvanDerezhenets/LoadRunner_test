Action()
{

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	lr_start_transaction("1_begin");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\" Not A;Brand\";v=\"99\", \"Chromium\";v=\"98\", \"Google Chrome\";v=\"98\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("2267", 
		"URL=https://www.sql.ru/blogs/iyun/2267", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/css/layout.css?v=1", "Referer=https://www.sql.ru/css/screen.css?v=1", ENDITEM, 
		"Url=/css/sides.css", "Referer=https://www.sql.ru/css/screen.css?v=1", ENDITEM, 
		"Url=/css/vote.css", "Referer=https://www.sql.ru/css/screen.css?v=1", ENDITEM, 
		"Url=/css/homepage.css", "Referer=https://www.sql.ru/css/screen.css?v=1", ENDITEM, 
		"Url=/css/articles.css", "Referer=https://www.sql.ru/css/screen.css?v=1", ENDITEM, 
		"Url=/css/job.css", "Referer=https://www.sql.ru/css/screen.css?v=1", ENDITEM, 
		"Url=/css/images/icons/li-dot.gif", "Referer=https://www.sql.ru/css/sides.css", ENDITEM, 
		"Url=/css/images/v-delim-line.gif", "Referer=https://www.sql.ru/css/articles.css", ENDITEM, 
		"Url=/css/images/icons/comment.gif", "Referer=https://www.sql.ru/css/articles.css", ENDITEM, 
		"Url=/css/images/icons/comment-small.gif", "Referer=https://www.sql.ru/css/articles.css", ENDITEM, 
		"Url=/css/images/icons/print.gif", "Referer=https://www.sql.ru/css/articles.css", ENDITEM, 
		"Url=/favicon.ico", ENDITEM, 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("Origin", 
		"https://www.sql.ru");

	web_add_auto_header("Sec-Fetch-Site", 
		"cross-site");

	web_url("client.ru.min.json", 
		"URL=https://s7.addthis.com/l10n/client.ru.min.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.sql.ru/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"iframe");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("sh.f48a1a04fe8dbf021b4cda1d.html", 
		"URL=https://s7.addthis.com/static/sh.f48a1a04fe8dbf021b4cda1d.html", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.sql.ru/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://v1.addthisedge.com/live/boost/xa-4cb75b821386eec8/_ate.track.config_resp", "Referer=https://www.sql.ru/", ENDITEM, 
		"Url=https://m.addthis.com/live/red_lojson/300lo.json?si=621e5e5937407a78&bkl=0&bl=1&pdt=1888&sid=621e5e5937407a78&pub=xa-4cb75b821386eec8&rev=v8.28.8-wp&ln=ru&pc=men&cb=0&ab=-&dp=www.sql.ru&fp=blogs%2Fiyun%2F2267&fr=&of=0&pd=0&irt=0&vcl=0&md=0&ct=1&tct=0&abt=0&cdn=0&pi=1&rb=0&gen=100&chr=windows-1251&colc=1646157401732&jsl=1&uvs=621e5e59fae36422000&skipb=1&callback=addthis.cbs.jsonp__76580960170740680", "Referer=https://www.sql.ru/", ENDITEM, 
		LAST);

	lr_end_transaction("1_begin",LR_AUTO);

	return 0;
}