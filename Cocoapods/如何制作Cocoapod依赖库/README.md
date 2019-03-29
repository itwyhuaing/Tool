# 如何制作Cocoapod依赖库及版本升级

### 制作预升级步骤

##### 新建 Git 仓库 、Clone 到本地、添加文件
> 首先你需要在 Github 上注册一个账号

![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/如何制作Cocoapod依赖库/image/1.png)


> 远程库文件第一次拉到本地只有 LICENSE 与 README.md 俩个文件 ；这里添加待制作的依赖库与一个示例 Demo

![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/如何制作Cocoapod依赖库/image/2.png)

##### 创建相应的 .podspec 文件、修改对应信息

> 进行该操作前，你需要在 CocoaPods 注册开发者信息及查看开发者信息终端命令如下(--verbose 便于查看命令执行的错误信息):

```
pod trunk register renyiyouxiangzhanghu@163.com 'namexx'  --verbose

pod trunk me
```

> 终端进入相应文件路径下，创建 .podspec 描述文件 ，创建之后会默认填写一些信息；其中关键的主要信息的修改可参考示例的配置文件；升级过程中注意修改版本及其他相应信息

```
pod spec create RWBanner
```

![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/如何制作Cocoapod依赖库/image/3.png)


>  .podspec 文件配置项说明

```


```


##### 打上标签并将所有修改推送到远程仓库

> 所有代码和描述文件修改之后打上标签并推送至远程仓库，添加、查看、推送、删除标签的终端命令如下:
> 这里打标签终端命令操作几次验证描述文件时始终找不到对应版本，网上也有很多类似问题，始终绕不过去；所以关于代码提交推送及标签最好使用版本管理工具：

```
// 新增标签
git tag "v0.1.2"          

// 查看所有标签
git tag                 

// 删除标签
git tag -d 0.1.2        

// 标签推送到远程
git push --tags         

// 添加远程库关联
git add .
git commit -m "Initial"
git remote add origin https://github.com/*******/RWBanner.git #添加远端仓库
git push origin master #提交到远端仓库
```

##### 验证 .podspec 文件的有效性

```
pod spec lint RWBanner.podspec
```

> 无论初次验证还是版本升级验证比较易错的地方是版本信息问题

![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/如何制作Cocoapod依赖库/image/4_1.png)


> 处理警告

![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/如何制作Cocoapod依赖库/image/4_2.png)


> 通过之后的终端命令结果

![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/如何制作Cocoapod依赖库/image/4_3.png)


##### 将 .podspec 文件提交到官方的 CocoaPods Specs 中

> 我们前面已验证过的 文件只有提交到 之后才可以被搜多到 ，所需终端命令如下:

```
pod trunk push RWBanner.podspec
```

> 成功

![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/如何制作Cocoapod依赖库/image/5.png)


##### 最后的搜索

> 通过之前个操作之后，终端搜索命令及结果如下:

```
pod search RWBanner
```

![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/如何制作Cocoapod依赖库/image/6.png)

### 常见问题
1. 成功之后，执行

```
pod search RWBanner
```

如果并没有查询到该依赖库，可以执行


```
pod setup
```

CocoaPods 会将这些 podspec 索引文件更新到本地的 ~/.cocoapods/ 目录，pod setup 成功后会生成 ~/Library/Caches/CocoaPods/search_index.json 文件。
如果还是失败，可以删除生成的 .json 文件，然后在执行查询命令。

```
rm ~/Library/Caches/CocoaPods/search_index.json
```

![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/如何制作Cocoapod依赖库/image/error_search.png)

2. 新增该依赖库修改完善的开发者账号
```
pod trunk add-owner RWBanner xx@163.com
```

3. 一旦一个版本的pod被发布了，你将不能够再修改它。如果你必须要做一定的修改，请发布一个新的版本。

4. 验证说明文件报错 - 解决方式：建议使用版本控制管理工具 Git/SVN (这里使用Git)

![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/如何制作Cocoapod依赖库/image/error_tag.png)

5. 制作的当前依赖库需要依赖其他已存在依赖库 - 验证 .podspec 文件时会报以下错

>> 报错关键词提取

```
error: include of non-modular header inside framework module

-Werror,-Wnon-modular-include-in-framework-module

```

![image](https://github.com/itwyhuaing/Tool/blob/master/Cocoapods/如何制作Cocoapod依赖库/image/error_lint_1.png)

关于这个这个错误在网上看了些材料，类似的问题遇到的蛮多，但解决方式似乎都不太一样；贴出两个表靠谱的解决方式地址链接，便于查看。

* [私有库依赖私有库](https://www.jianshu.com/p/4d73369b8cf9)
* [--use-libraries](https://blog.csdn.net/weixin_33695082/article/details/86982044)

> 制作 JXFMDBMOperator 依赖库遇到该问题时，采用的解决方式时添加 --use-libraries 。

##### 参考


* [手把手教你发布自己的cocoapods开源库](https://www.jianshu.com/p/3a365f273439)

* [Cocoapods私有库管理实现](http://www.cocoachina.com/ios/20170706/19695.html)
