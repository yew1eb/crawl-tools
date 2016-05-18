var fs = require('fs')
    , cheerio = require('cheerio')
    , superagent = require('superagent')
    , globalCookie = undefined;

var username = 'hanzichi';

function login() {
    superagent
    // get 请求任意 acm.hdu.edu.cn 域名下的一个 url
    // 获取 key 为 PHPSESSID 这个 Cookie
        .get('http://acm.hdu.edu.cn')
        .set("User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.102 Safari/537.36")
        .set("Host","acm.hdu.edu.cn")
        .end(function (err, sres) {
            if (err) {
                console.log("superagent login failed, try again!\n" + err);
                login();
            } else {
                // 提取 Cookie
                var str = sres.header['set-cookie'][0];
                // 过滤响应头 Cookie 中的 path 字段
                var pos = str.indexOf(';');

                // 全局变量存储 Cookie，post 代码提交时候用
                globalCookie = str.substr(0, pos);

                // 模拟登录
                superagent
                // 登录 url
                    .post('http://acm.hdu.edu.cn/userloginex.php?action=login')
                    // post 用户名 & 密码
                    .send({"username": username})
                    .send({"userpass": username})
                    // 这个请求头是必须的
                    .set("Content-Type", "application/x-www-form-urlencoded")
                    // 请求携带 Cookie
                    .set("Cookie", globalCookie)
                    .end(function (err, sres) {
                        // 登录完成后，启动程序
                        start();
                    });
            }
        });
}

function download(problemId, runId) {
    superagent
        .get('http://acm.hdu.edu.cn/viewcode.php?rid=' + runId)
        .set("Content-Type", "text/html")
        .set("Cookie", globalCookie)
        .end(function (err, sres) {
            if (err) {
                console.log("superage failed runId : " + Id + " try again!" + err);
                download(runId);
            } else {
                var $ = cheerio.load(sres.text);
                var status = $('body table font').eq(4).text();
                var code = $('#usercode').text();
                if (status != 'Accepted') {
                    console.log("Open failed, RunId: " + runId);
                    return;
                }

                var path = 'code/hdu' + problemId;
                fs.exists(path, function (exists) {
                    if (!exists) {
                        fs.mkdir(path);
                    }
                });
                var filename = path + '/' + runId + '.cpp';
                try {
                    fs.openSync(filename, 'w+', function (err, fd) {
                        if (err) {

                        } else {
                            fs.writeFileSync(filename, code);
                        }
                    });
                    fs.close();
                } catch (err) {
                    console.log(err);
                }
                console.log('RunId: ' + runId + ', ProblemId: ' + problemId + ', Status: ' + status + ", code saved, path: " + filename);
            }
        });
}

function status(Id) {
    var html = fs.readFileSync('status.txt', 'utf-8');
    var $ = cheerio.load(html);
    var text = $('#fixed_table td').text();
    console.log(text);
    return;
    superagent
        .get('http://acm.hdu.edu.cn/status.php?pid=' + Id + '&user=' + username)
        .set("Content-Type", "text/html")
        .set("Cookie", globalCookie)
        .end(function (err, sres) {
            if (err) {
                console.log("superage failed pId : " + Id + " try again!" + err);
                status(Id);
            } else {
                var $ = cheerio.load(sres);

            }
        });
}

var solved = new Set();

function downSolved() {
    superagent
        .get('http://acm.hdu.edu.cn/userstatus.php?user=' + username)
        .end(function (err, sres) {
            var $ = cheerio.load(sres.text);
            var need1 = $('body table p').eq(2).text();
            var rs = need1.match(/\d{4}/g);
            for (var i = 0; i < rs.length; ++i) {
                solved.add(rs[i]);
            }
        });
}

function start() {
    downSolved();
    fromId = 1000;
    endId = 5689;
    for (var i = fromId; i <= fromId; ++i) {
        if (solved.has(String(i))) {
            continue;
        }
        var Id = i, delay = (i - fromId) * 100;
        (function (delay, Id) {
            setTimeout(function () {
                status(Id);
            }, delay);
        }(delay, Id));
    }
}

login();