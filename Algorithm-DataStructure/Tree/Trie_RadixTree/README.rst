Trie
=====================
Trie又名字典树、前缀树、digital tree，是一种有序搜索树，可以存储动态的set、关联数组(键值对)。不像二叉搜索树，Trie树的结点里并不存储完整的key，key是在查找的路径上体现的。例如，对于key "abc"，就从root出发，首先向a的方向前进，然后b，最后c，此时当前结点就是我们要找的结点。

.. image: images/Trie-example.png

性质
---------------

- 每个结点的后裔，都共有一个前缀(所以叫前缀树)
- Trie就是树状的DFA

应用
---------------

- 替代Hash Table
- 存储predictive text(比如手机上的九宫格输入)和autocomplete字典。Trie也用来实现用于拼写检查、hyphenation algorithm。

实现
---------------
最基本的实现方法是，是在每一个node里存放一个大小为Alphabet Size(对于英语为26，对于所有ASCII字符为256)的数组，存放子node的指针::

	struct TrieNode
	{
        void *data;
        struct TrieNode *children[ALPHABET_SIZE];
        ...
	};

如果当前字符为b，那么下一个node的index就是(int)'b' - (int)'a'，即children[1]。

可以看出，这种方式非常耗费内存，对于Alphabeta为所有ASCII字符的Trie，在64位系统上，每个结点都要存储256 * 8 = 2048bytes的指针。而且Trie树越靠近叶子结点，children就越少，这意味着NULL指针越来越多。

要减少内存占用，可以用一种方法来缩小Alphabet的大小。比如，一个长度为n的字符串，可以看作是长度为2n的、多个4bit的单元的组合，其Alphabet大小变为2^4 = 16。但是，这样本来查找m次(m为key的长度)就能找到的数据，需要查找2m次。

另一种方法是，将node设计为三元序列(symbol、child、next)，并将子结点用单链表串起来。child指针指向第一个子节点，next指向下一个同级结点。children也可以用二叉搜索树来存储。

Compressed tries
++++++++++++++++++++++
压缩过的trie，是在普通trie上增加一条规则：每个内部结点都必须有2个或以上的子节点。这样一个trie又被称为Radix tree或Patricia tries。

外部存储中的Trie
++++++++++++++++++++++
有一种将B-tree与Trie结合起来的数据结构，叫做B-Trie。


Radix Tree
======================
Radix Tree(或者Radix Trie、compact prefix tree)，是在Trie的基础上，要求将只有一个child的结点与该child合并。这样做的结果是，每个内部结点都至少有基数r个子结点，r = 2^x，x >= 1。每个边可以标记上字符序列或者单个字符，节约了空间。
