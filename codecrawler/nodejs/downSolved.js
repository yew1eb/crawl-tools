var fs = require('fs'),
    cheerio = require('cheerio'),
    superagent = require('superagent');

function downSolved() {
    superagent
        .get('http://acm.hdu.edu.cn/userstatus.php?user=jsucoder')
        .end(function (err, sres) {
            var $ = cheerio.load(sres.text);
            var need1 = $('body table p').eq(2).text();
            var need2 = $('body table p').eq(3).text();
            var rs = need1.match(/\d{4}/g);
            rs = rs.concat(need2.match(/\d{4}/g));
            fs.writeFile("solved.txt", rs.join(','), "utf-8");
        });
}

downSolved();
console.log("Down solved finished!");