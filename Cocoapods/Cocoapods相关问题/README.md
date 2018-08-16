# cocoapods 相关问题

## 卸载

##### 参考
* [如何从电脑中卸载cocoapods](http://blog.csdn.net/qq_18670721/article/details/50432892)

##### 图释
 ![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/Cocoapods相关问题/images/uninstall_cocoapods.png)

## 安装

##### 参考
* [CocoaPods安装和使用教程](http://code4app.com/article/cocoapods-install-usage)
* [报错处理](http://stackoverflow.com/questions/30812777/cannot-install-cocoa-pods-after-uninstalling-results-in-error/30851030#30851030)

##### 图释
* ![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/Cocoapods相关问题/images/install_cocoapods.png)

## 升级

##### 部分图释
* ![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/Cocoapods相关问题/images/update_cocopoads.png)

## 使用报错处理
* [CocoaPods: pod search 搜索类库失败的解决办法](http://blog.cocoachina.com/article/29127)
* [error: RPC failed; curl xx SSLRead() return error -xx](http://blog.csdn.net/wm9028/article/details/51840759)
* [升级电脑系统之后，cocoapods不能正常使用解决办法](http://blog.csdn.net/wddyzzw/article/details/78435569)

* 错误报错代码摘录 :Xcode 升级之后新建项目无法使用 CocoaPods ,报如下错误代码；解决方法为升级 Cocopoads.
```
### Report

* What did you do?

* What did you expect to happen?

* What happened instead?


### Stack

   CocoaPods : 0.33.1
        Ruby : ruby 2.1.1p76 (2014-02-24 revision 45161) [x86_64-darwin12.0]
    RubyGems : 2.2.2
        Host : Mac OS X 10.8.5 (12F45)
       Xcode : 5.1.1 (5B1008)
Ruby lib dir : /Users/maguang/.rvm/rubies/ruby-2.1.1/lib
Repositories : master - https://github.com/CocoaPods/Specs.git @ 547e828b7036ce1220a439e1c53c720410af74b0

### Error

[!] Oh no, an error occurred.

Search for existing github issues similar to yours:


```
## 常用终端命令 <持续更新 ... >
* ruby -v                                                       查看本地ruby版本
* gem sources -l                                                查看当前ruby的源
* gem sources --remove http://rubygems.org                      移除源
* gem sources  -a https://ruby.taobao.org/                      添加源
* sudo gem update --system                                      gem太老时，用于升级gem 
* sudo gem install cocoapods                                    安装 CocoaPods
* pod repo update                                               [快速更新 - 本地资源库](https://www.jianshu.com/p/1d058d224cad)
* pod --version                                                 查看当前 CocoaPods 版本
* sudo gem install -n /usr/local/bin cocoapods --pre            CocoaPods 版本升级
* sudo gem cleanup                                              CocoaPods 版本升级之后,清除已安装过得所有pods旧版本，保留当前最新版本
