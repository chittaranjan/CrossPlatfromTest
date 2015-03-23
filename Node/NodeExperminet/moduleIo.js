
function getExtension(filename) {
    var i = filename.lastIndexOf('.');
    return (i < 0) ? '' : filename.substr(i+1);
}

function testAsyncIO(filename, extn, callback)
{
        require("fs").readdir(filename, function(err, files){ 
                if (err)
                 return callback(err);
        var filteredlist =[];

        //console.log(extn);
        
        for ( var count = 0; count < files.length; count++) {

                var extension = getExtension(files[count]);
               // console.log(extension);

                if (extension == extn  )
                filteredlist[count] = files[count];
        }
        return callback(null, filteredlist);
        })
}
module.exports = testAsyncIO;