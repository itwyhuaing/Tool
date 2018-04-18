# appium 配置及使用

##### 安装 homebrew
```
$ brew update
$ brew -v
```

##### 安装 node

```
$ brew install node
$ node -v
```
* 升级
```
$ sudo npm cache clean -f  # 清除node.js的cache
$ sudo npm install -g n    # 安装 n 工具，这个工具是专门用来管理node.js版本的
$ sudo n stable            # 安装最新版本的node.js
```
##### 安装 npm
```
$ brew install npm
$ npm -v
```

* 升级
npm -g 是管理本地全局包的命令
```
$ npm -g outdated          # 可以查看哪些包有更新
$ npm -g install <name>
```
##### 安装 appium --- server端
```
$ npm install -g appium       # 安装
$ appium-doctor               # appium 环境检测
```

##### 其他安装
```
$ brew install libimobiledevice --HEAD      # install from HEAD to get important updates
$ brew install ideviceinstaller             # 只是对iOS9有用
$ npm install -g ios-deploy                 # iOS10 以后的版本安装ios-deploy
$ sudo gem install xcpretty                 # 真机需要安装 xcpretty
```























































### 参考
* [环境搭建参考](https://github.com/erduoniba/appium_ios_sample_code)
* [npm升级所有可更新包](http://www.tuicool.com/articles/UbyY7rY)
* [安装 appoum 失败解决参考](http://blog.csdn.net/tt75281920/article/details/43907065)
