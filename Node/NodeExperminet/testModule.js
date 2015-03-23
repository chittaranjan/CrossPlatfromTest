var test= require('./moduleIo');
test(process.argv[2], process.argv[3], function(err, data) {
	if (err)
		throw err;
	for (var count = 0; count < data.length; count++)
		console.log(data[count]);
});