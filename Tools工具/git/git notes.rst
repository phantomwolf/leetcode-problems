git squash
==================
git squash可以将多个commit合并为一个commit。使用方法：

将最近3个commit合并::

	git rebase -i HEAD~3			

将文件::

	pick f392171 Added new feature X
	pick ba9dd9a Added new elements to page design
	pick df71a27 Updated CSS for new elements
	
改为::

	pick f392171 Added new feature X
	squash ba9dd9a Added new elements to page design
	squash df71a27 Updated CSS for new elements

其中，最上面的commit是最早的commit。pick -> 保留该commit；squash -> 将其与上一个commit合并。

最后编辑commit信息，就可以完成操作。


git proxy
==================
git config --global http.proxy 'socks5://127.0.0.1:8080'
git config --global https.proxy 'socks5://127.0.0.1:8080'

git log
==================
git log -p可显示每个commit的git diff信息。

git log --stat显示每个commit的文件变化统计信息。

git log --graph能显示branching的历史。

git log -2表示只显示最近的2条内容。

git diff
==================
git diff可以显示文件的具体变化。

默认情况下，git diff显示当前工作区里的文件，与暂存区staging area之间的变化。如果指定了commit，就比较当前工作区的文件与那个commit之间的差异::

	git diff [options] [<commit>] [--] [<path>...]

git diff也可以比较两个特定commit之间的差异::

	git diff [options] <commit> <commit> [--] [<path>...]

git diff也可以比较提交到暂存区(staging area)的内容和某个commit(如果不写，就是HEAD)之间的变化::

	git diff [--options] --cached [<commit>] [--] [<path>...]

移动文件
==================
git mv可以移动文件到另一个位置，git status中将显示为：renamed:   A -> B

git status
==================
git status -s能显示短的状态。例如::

	$ git status -s
	 M README
	MM Rakefile
	A  lib/git.rb
	M  lib/simplegit.rb
	?? LICENSE.txt

可以看到，最左边的状态有两列：左边表示暂存区(staging area)的状态；右边表示工作目录的状态。M表示Modified；A表示Added，??表示新文件。

以Rakefile为例，它是原本已经存在的文件。对其修改后，其状态为::

	 M Rakefile

即其工作目录里发生了变化。这时git add Rakefile，会变为::

	M  Rakefile

这表示暂存区(staging area)里发生了变化。我们再次对其进行修改，变为::

	MM Rakefile

这说明在把改动保存到staging area后，工作目录里再次发生了变化。再次git add后::

	M  Rakefile

工作目录的改动又被加到了staging area。这时我们commit，Rakefile就从git status -s中消失了，因为它已经被保存到了.git中的数据库里。


git commit
=======================
ammend
---------------
替换当前分支顶端的commit。例如::

	$ git commit -m 'initial commit'
	$ git add forgotten_file
	$ git commit --amend

这样就能只一次commit就把forgotten_file也提交出去。git commit --amend粗略相当于::

	$ git reset --soft HEAD^
	$ ... do something else to come up with the right tree ...
	$ git commit -c ORIG_HEAD

需要注意，对于已经push的commit，这样做会修改历史。

git rev-parse
======================
打印出各种信息，比如：

- 打印branch对应的commit：git rev-parse <branch>

git-hash-object
======================
Compute object ID and optionally creates a blob from a file
