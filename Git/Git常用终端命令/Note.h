=============== 1
// 创建新的仓库
git init

// 检出仓库
git clone 本地路径/远程仓库地址

// 添加改动到缓冲区
git add <filename>
git add *

// 实际提交到文件存储区
git commit -m "提交说明"

// 将实际改动推送到远程仓库
git push origin master/其他分支

// 如果你还没有克隆现有仓库，并欲将你的仓库连接到某个远程服务器，你可以使用如下命令添加：如此你就能够将你的改动推送到所添加的服务器上去了。
git remote add origin <server>

=============== 分支操作
// 列出所有本地分支
git branch

// 列出所有远程分支
git branch -r

// 检出 feature_x 分支
git checkout -b feature_x

// 切换回主分支
git checkout master

// 再把新建的分支删掉（只是删除本地分支）
git branch -d feature_x

// 删除远程分支
git push origin --delete [branch-name]
git branch -dr [remote/branch]

// 将分支 feature_x 推送到远端仓库
git push origin feature_x

=============== 更新与合并
// 更新你的本地仓库至最新改动
git pull

// 合并
git merge <branch>

// 在合并改动之前，也可以使用如下命令查看
git diff <source_branch> <target_branch>

=============== 标签
// 添加标签
git tag 1.0

// 推送到远程
git push tags

// 列出所有标签
git tag

// 删除标签
git tag -d 1.0
