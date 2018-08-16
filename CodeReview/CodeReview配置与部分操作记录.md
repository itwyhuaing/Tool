# CodeReview

## 环境配置

### 1、配置PHP环境
[参考-在Mac系统下配置PHP运行环境](http://www.jianshu.com/p/f4fd87fea61c)

### 2、安装 Git
安装一个图形界面工具(GUI)即可,例如 SourceTree 等。
如果想了解 git 可参考 [git教程](http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000) 。

### 3、安装Arcnist
1> 首先在某一路径下新建一个文件(这里举例，新建一个命名 Arcnist 的文件)
2> 终端命令打开至刚刚新建的文件，即执行以下命令：
```
$ cd Arcnist
```
然后回车。
3> 依次执行以下终端命令：
```
$ git clone git://github.com/facebook/libphutil.git
$ git clone git://github.com/facebook/arcanist.git
```
两次 clone 成功结束之后。
首先终端查看Path,命令如下：
```
$ echo $PATH
```
然后将刚刚克隆到的arcanist文件夹下的bin文件路径添加查询到的路径，终端命令如下：
```
export PATH=xxx
```
注：xxx 代表arcanist文件夹下的bin文件路径。回车之后，再次查询即可确认是否添加成功。
正确添加之后，终端输入一下命令:
```
$ arc
回车之后出现一下提示及说明配置OK 。
Usage Exception: No command provided. Try arc help.
```
### 4、配置Editor
Windows 系统需要此配置。
[参考](https://secure.phabricator.com/book/phabricator/article/arcanist_windows/)
Mac 系统可忽略此步奏。

### 5、设置URI
输入以下终端命令：
```
arc set-config default http:xxx.xxx.xxx.xxx:xxxx
回车之后出现以下提示，说明设置OK。null指的是原来的值。
Set key "default" = "http:xxx.xxx.xxx.xxx:xxxx" in user config (was null).
```
注：xxx.xxx.xxx.xxx:xxxx为搭建的公司内部局域网。

### 6、注册新账号
登录`xxx.xxx.xxx.xxx:xxxx`,注册一个新账号，会收到一封激活邮箱的邮件，点击链接激活。
然后还需要等待管理员激活账号即可使用。

### 7、 上传自己的ssh公钥
设置Git的user name和email，终端命令如下：
```
$ git config --global user.name "用户名"
$ git config --global user.email "邮箱账号"
```
之后生成公钥等文件，终端命令：
```
$ssh-keygen -t rsa
```
找到 ‘.ssh/id_rsa.pub’ 内容。
接着打开`xxx.xxx.xxx.xxx:xxxx`，如下操作。
个人中心-->设置-->ssh公钥-->SSH Key Actions-->上传公钥-->名称（自己命名），Public Key（复制 id_rsa.pub 的内容）-->上传公钥。
然后就可以clone项目了。


### 8、配置Project信息
登录Phabricator找到需要clone的项目，git clone下来后，在项目代码的根目录下，创建 **.arcconfig **文件，内容如下：
```
{
   "phabricator.uri" : "xxx.xxx.xxx.xxx:xxxx"
}
```
**此文件提交到Git，以后clone下来就不需要新建了。**

### 9、安装Arcnist证书
证书可以让你通过验证,安装证书后才能使用`arc`命令提交审核，证书只需要安装一次，后面项目就不需要安装了。
```
$ cd yourproject/
yourproject/ $ arc install-certificate
```
根据提示打开浏览器输入这个网页：http://xxx.xxx.xxx.xxx:xxxx/conduit/login/
复制API Token到命令行，回车，提示如下信息表示安装成功。
> SUCCESS！ API Token installed.

在进行完基本的配置和安装后，可以开始 Code Review 了。


## 配置代码仓库

### 创建Code Review规则Rule
如果不创建Rule，在提交没有审核的情况下也能使用`git push`发布代码到仓库。
1、管理员登录Phabricator,在**More Applications**找到**HeraId**；
2、在创建时，**New Rule for** 选：_Commit Hook: Commit Content._；**Rule Type**选：_Global_
3、**Conditions**中是组合条件，可以根据自己需要指定一些条件；**Action** 指定当前情况符合你指定的条件组合时执行的动作。示例如图：

![](http://b3672b6b.wiz03.com/share/resources/f3889611-e866-47ef-92cb-9629438fe8e3/index_files/9ffdc2a8-6484-4a99-982e-ec27291b6ad3.png)

示例中定义了以下规则：
在向所有分支提交代码时，所提交的代码必须是通过 Code Review 流程审查通过的，否则会被拒绝；
除非 Commit Message 中包含字符**@bypass-review**。指定 Commit Message 中包含字符 **@bypass-review** 这种例外情况，主要考虑到在紧急修复一些问题，没时间等待审查时使用。
当提交被拒绝时，如图：
![](http://b3672b6b.wiz03.com/share/resources/f3889611-e866-47ef-92cb-9629438fe8e3/index_files/ebed6677-09c7-4ff7-bfc5-ef5373f6e130.png)

### 新建Git仓库
只有管理员才有权限新建仓库，管理员登陆：http://172.16.10.158:9005
**Diffusion**下点击**+ Create Repository**选择Git仓库，填写基本信息后创建。
然后active仓库，查看URI，会显示在服务器上仓库的位置，没显示代表配置错误。

这里有个坑，新建Git仓库后，虽然界面显示有master分支，实际上仓库中没有master分支，在后面使用arc diff提交审核时会有问题，所以第一次clone下来需要提交一次master分支，顺便把**.arcconfig**文件提交了，切记一定要在commit message 中写上**@bypass-review**关键字，否则会很麻烦。
在项目目录下创建 **.arcconfig **文件，参考上面[**配置Project信息**]，发布到master分支：
```
git add .
git commit -m "添加.arcconfig文件  @bypass-review"
git push origin master
```

## Code Review流程

Phabricator提供两种Code Review的方式：**pre-push**，**post-push**
**pre-push** 是指审查发生在变更发布前；**post-push** 是指审查发生在变更已经被发布或者正在发布。
这里我们认为 **pre-push** 的方式更适合，所以接下来说一下 **pre-push** 的工作流：

> **Write, Review, Merge, Publish**



### 主分支操作流程
1、编写代码
2、提交本地`git commit -m "commit message"`
3、`arc diff` 提交审查请求，根据提示，按y,会弹出记事本编写
```
Summary: 概要简介            概要（必填）
Test Plan: no               测试计划（必填）
Reviewer: jackli;admin      审核人：多人用分号隔开（必填）
Subscribers:                订阅者（可选）
```
4、审核人登录pha审核
5、审核通过后，`arc land`提交变更发布
6、如果不通过，修改后`arc diff`再次提交审核

### 新建分支
本地新建分支提交审核时，由于远程仓库没有此分支，arc diff会失败，所以新建分支时，用@bypass-review将本地新分支push到远程仓库

```
git checkout -b newb                   //创建并切换到新分支newb
git touch new.txt
git add .
git commit -m "新建分支newb @bypass-review"
git push origin newb                   //将新分支push到远程分支
git branch -u origin/newb              //把本地的分支与远程分支相关联
```
然后和主分支操作流程类似。
建议请使用 `git branch -u origin/远程分支名称` 把本地的分支与远程分支相关联，否则，在执行完 `arc land` 后，本地分支会被删除。如果你不想这样做，又需要保留现在分支的话，请使用 `arc land --keep-branch`。


**系统会发送邮件给审核人，审核人登录pha页面进行审核，在Action选项进行操作。**
做为 **_审查人_**，可进行的操作有：
_Comment_：说点什么。可以针对某行代码进行评论，直接点击行号即可
_Accept Revision_：接受变更，这哥们代码写得不错，不需要改
_Request Changes_：不行，还要改
_Resign as Reviewer_：重新指定审查代码的人
_Commandeer Revision_：字面意思是将这个Revision据为己有的意思，实际上这个时候Reviewer的身份已经变为Owner的身份了，不能再进行Review了，但是Comment还是可以的
_Add Reviewer_：添加审查人
_Add Subscribers_：添加订阅者，CC

做为 **_作者_**，可进行的操作有：
_Comment_：说点什么。可以针对某行代码进行评论，直接点击行号即可
_Abandon Revision_：废除版本。废除后，这个版本就不需要再审核了
_Plan Changes_：计划变更，我自己发现了一些问题或者需求有变，正在改
_Add Reviewer_：添加其它审查人（除当前审查人外）
_Add Subscribers_：添加订阅者，CC

## Arcanist常用命令
_arc diff_：发送变更详情和审查请求
_arc land_：推送变更（Git and Mercurial），当通过审查后使用这个命令
_arc list_：显示变更处理的情况
_arc cover_：查找最有可能审查变更的人
_arc patch_：给版本打补丁
_arc export_：从Differential下载补丁
_arc amend_：更新Git commit
_arc commit_：提交变更（SVN）
_arc branch_：查看Git branches更加详细的信息

在配置了 lint 和 unit test intergration后，可以用这些命令：
_arc lint_：静态代码检查
_arc unit_：单元测试

与其它工具交互：
_arc upload_：上传文件
_arc download_：下载文件
_arc paste_：创建和查看剪贴

还有一些高级功能：
_arc call-conduit_：执行 Conduit 方法
_arc liberate_：创建或更新 libphutil 库
_arc shell-complete_：激活 tab 补全


## 参考链接
[使用Phabricator做为Code Review工具](http://www.jianshu.com/p/b1a75a14638c)
注：关于PATH变量的全局化，可参考 [Linux设置环境变量小结:设置永久变量&临时变量 全局变量&局部变量](http://www.cnblogs.com/haore147/p/3633116.html) 
