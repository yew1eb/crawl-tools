var fs = require('fs');

var file = fs.readFileSync('solved.txt', 'utf-8');
var array = file.split(',');
for (i = 0; i < array.length; ++i) {
    try {
        var filename = '_code/hdu'+array[i]+'/';
        fs.del(filename);
    }catch(err) {
        console.log(err);
    }
}