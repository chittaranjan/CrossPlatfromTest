var http = require("http");
http.createServer(function(request, response){
	response.writeHead(200, {"Content-Type": "text/html"});

	var urlobject = require("url").parse(request.url, true);
	
})