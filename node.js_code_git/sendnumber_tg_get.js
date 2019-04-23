var http = require('https');  
var qs = require('querystring');  
  
//var data = {  
//	    chat_id: "556017148",  
//	    text: "fdasfdsafdafdaf"};//这是需要提交的数据  
  
  
//var content = qs.stringify(data);  
var a = 0;
/*var options = {  
	    hostname: 'api.telegram.org',  
	    port: 443,  
	    path: '/bot673939605:AAE7WUiGvBbtLztAUCqUJDyowSSM5qQG62s/sendMessage?chat_id=437532928&text=' + a + '&parse_mode=HTML',  
	    method: 'GET'  
};*/ 
function sendmessage(){
var options = {                                                           
	            hostname: 'api.telegram.org',                                   
	            port: 443,                                                      
	            path: '/bot673939605:AAE7WUiGvBbtLztAUCqUJDyowSSM5qQG62s/sendMessage?chat_id=437532928&text=' + a + '&parse_mode=HTML',                     
	            method: 'GET'                                             
	      };
var req = http.request(options, function (res) {  
	    console.log('STATUS: ' + res.statusCode);  
	    console.log('HEADERS: ' + JSON.stringify(res.headers));  
	    res.setEncoding('utf8');  
	    res.on('data', function (chunk) {  
		            console.log('BODY: ' + chunk);  
		        });  
});  
  
req.on('error', function (e) {  
	    console.log('problem with request: ' + e.message);  
});  
a++;  
req.end();
	setTimeout(sendmessage,5000);
}
a++;
sendmessage();
