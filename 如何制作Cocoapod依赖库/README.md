# 如何制作Cocoapod依赖库

##### 新建 Git 仓库 、Clone 到本地、添加文件

##### 创建相应的 .podspec 文件、修改对应信息

##### 打上标签并将所有修改推送到远程仓库

##### 验证 .podspec 文件的有效性
 

##### 将 .podspec 文件提交到官方的 CocoaPods Specs 中
pod trunk push RWBanner.podspec



###### 小结
1. 成功之后，执行 
pod search RWBanner
如果并没有查询到该依赖库，可以执行
pod setup
CocoaPods 会将这些 podspe c索引文件更新到本地的~/.cocoapods/目录，pod setup成功后会生成~/Library/Caches/CocoaPods/search_index.json文件。如果还是失败，可以删除生成的 .json 文件，然后在执行查询命令。

2. 新增该依赖库修改完善的开发者账号
pod trunk add-owner RWBanner xx@163.com

3. 一旦一个版本的pod被发布了，你将不能够再修改它。如果你必须要做一定的修改，请发布一个新的版本。