var httptest = require('http');
httptest.get(process.argv[2], function(res) {
res.setEncoding("utf8");
res.on('error', console.error);
res.on('data', console.log);

});
