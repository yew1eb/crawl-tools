var fs = require('fs')
    , cheerio = require('cheerio')
    , superagent = require('superagent')
    , globalCookie = undefined;


function saveCode(problemId, code) {
    var filename = '_code/hdu' + problemId + '/' + problemId + '.cpp';
    fs.exists(filename, function (exists) {
        if (!exists) {
            try {
                fs.open(filename, 'w+', function (err, fd) {
                    fs.writeFile(filename, code);
                });
            } catch (err) {
                throw err;
            }
            console.log('ProblemId: ' + problemId + ", _code saved, path: " + filename);
        } else {
            console.log(filename + " exists!");
        }
    });
}

// 从 csdn 题解详情页获取代码
function getCode(solutionUrl, problemId) {
    superagent.get(solutionUrl, function (err, sres) {
        var $ = cheerio.load(sres.text);
        var code = $("pre").eq(2).text();
        if (!code) {
            return;
        }
        saveCode(problemId, code);
    });
}


function download(pageId) {
    superagent
        .get('http://www.acmerblog.com/category/problemset/hdu/page/' + pageId)
        .set("User-Agent", "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.111 Safari/537.36")
        .set("Content-Type", "text/html; charset=UTF-8")
        .end(function (err, sres) {
            if (err) {
                console.log("superagent failed pageId : " + pageId + ",try again!");
                download(pageId);
            } else {
                try {
                    var $ = cheerio.load(sres.text);
                    var list = $('.h1 a');
                    for (var i = 0; i < list.length; ++i) {
                        var node = list.eq(i);
                        var solutionUrl = node.attr('href');
                        var problemId = solutionUrl.substr(29, 4);
                        //console.log(solutionUrl + " " +problemId);
                        getCode(solutionUrl, problemId);
                    }
                    console.log("current page : " + pageId);
                } catch (err) {
                    console.log(err);
                }
            }
        });
}


function start() {
    for (i = 1000; i < 4500; ++i) {
        var f = '_code/hdu' + i;
        try {
            fs.exists(f, function (exists) {
                if (!exists) fs.mkdir(f);
            });
        } catch (err) {
            console.log(err);
        }
    }
    for (var i = 1; i <= 366; ++i) {
        var pageId = i, delay = i * 10;
        (function (delay, pageId) {
            setTimeout(function () {
                download(pageId);
            }, delay);
        }(delay, pageId));
    }
}

start();