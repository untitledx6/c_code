let https = require('https'); 
let http = require('http'); 
let a = '';

function sendmessage(){
	let options_price = {
		hostname: 'data.gold.hexun.com',
		port: 80,
		path: '/outData/AuPaper.ashx',   
		method: 'GET'
	};
	let options_telegram = {                                                           
		hostname: 'api.telegram.org',                                   
	        port: 443,                                                      
	        path: '/bot673939605:AAE7WUiGvBbtLztAUCqUJDyowSSM5qQG62s/sendMessage?chat_id=437532928&text=' + a,
                method: 'GET'                                             
	};//请求配置

	http.get(options_price, function(res) {
        	res.setEncoding('utf8');  // 必要
        	res.on('data', function (chunk) {  
			let temp = chunk.substring(2, chunk.length - 2);
			temp = JSON.parse(temp);
                	a = temp.Price;
                });
	});//爬取数据

	let req = https.request(options_telegram, function (res) {});  
	req.on('error', function (e) {  
		console.log('problem with request: ' + e.message);  
	});  
	req.end();//telegram转发

	setTimeout(sendmessage,86400000);//延时循环
}

sendmessage();
