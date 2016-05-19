var fs = require('fs'),
    cheerio = require('cheerio')
    , superagent = require('superagent')
    , globalCookie = undefined;


// 模拟代码提交
function post(code, problemId) {
    var lang = 0;
    if (code.indexOf('import') >= 0) {
        lang = 5;
    }

    superagent
    // 代码 post 的 url
        .post('http://acm.hdu.edu.cn/submit.php?action=submit')
        .set('Content-Type', 'application/x-www-form-urlencoded')
        .set("Cookie", globalCookie)
        .send({"language": lang})
        .send({"problemid": problemId})
        .send({"usercode": code})
        .end(function (err, sres) {
            console.log(problemId + " *");
        });
}

function doit(pid) {
    var filename = '_code/hdu' + pid + '/' + pid + '.cpp';
    fs.exists(filename, function (exists) {
        if (!exists) {
            console.log(filename + ' file no exist!');
        } else {
            var code = fs.readFileSync(filename, 'utf-8');
            post(code, pid);
        }
    });
}

function login() {
    superagent
    // get 请求任意 acm.hdu.edu.cn 域名下的一个 url
    // 获取 key 为 PHPSESSID 这个 Cookie
        .get('http://acm.hdu.edu.cn/status.php')
        .end(function (err, sres) {
            if (err) {
                console.log(err.text());
                login();
                return;
            }
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
                .send({"username": "xxx"})
                .send({"userpass": "xxx"})
                // 这个请求头是必须的
                .set("Content-Type", "application/x-www-form-urlencoded")
                // 请求携带 Cookie
                .set("Cookie", globalCookie)
                .end(function (err, sres) {
                    // 登录完成后，启动程序
                    start();
                });
        });
}

var solved = new Set();
function downSolved() {
    superagent
        .get('http://acm.hdu.edu.cn/userstatus.php?user=xxx')
        .end(function (err, sres) {
            var $ = cheerio.load(sres.text);
            var need = $('body table p').eq(2).text();
            //var need2 = $('body table p').eq(3).text();
            var rs = need.match(/\d{4}/g);
            //rs = rs.concat(need2.match(/\d{4}/g));
            fs.writeFile('solved.txt', rs.join(','), 'utf-8');
        });
}

function initSet() {

    var file = fs.readFileSync('solved.txt', 'utf-8');
    var array = file.split(',');
    var list = "";
    for (i = 0; i < array.length; ++i) {
        solved.add(array[i]);
        list += array[i] + ',';
        if ((i + 1) % 25 == 0) {
            list += '\n';
        }
    }
    console.log(list);
    console.log("sovled total: " + solved.size);
}
// 程序启动
function start() {
    downSolved();
    initSet();
    fromId = 4049;
    endId = 4830;
    var count = 0;
    for (var i = fromId; i <= endId; ++i) {
        if (solved.has(String(i))) {
            continue;
        }
        var Id = i, delay = (++count) * 100;
        (function (delay, Id) {
            setTimeout(function () {
                doit(Id);
            }, delay);
        }(delay, Id));
    }
}

login();
