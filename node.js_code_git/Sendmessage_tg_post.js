var https = require('https');  
var qs = require('querystring');    
var post_data = {  
	    chat_id: "437532928",  
	    text: "hahahhahahhaha"};//这是需要提交的数据    
var content = qs.stringify(post_data);   

var options = {  
	    hostname: 'api.telegram.org',  
	    port: 443,  
	    path: '/bot673939605:AAE7WUiGvBbtLztAUCqUJDyowSSM5qQG62s/sendMessage',  
	    method: 'POST',  
	    headers: {  
		            'Content-Type': 'application/x-www-form-urlencoded; charset=UTF-8'  
		        } //必要 
};  
  
var req = https.request(options, function (res) {});    
req.on('error', function (e) {
	    console.log('problem with request: ' + e.message);  
});  
req.write(content);  
req.end();
