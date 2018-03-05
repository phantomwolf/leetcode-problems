# 红黑树
红黑树是一种特殊的二叉查找树，其性质如下：

1. 每个结点是红的，或是黑的
2. 根结点是黑的
3. 每个叶结点(NIL)是黑的
4. 如果一个结点是红的，则它的两个儿子都是黑的。
5. 对于每个结点，从该结点到其子孙结点的所有路径上包含相同数目的黑结点

黑高度：从某个结点x出发（不包括该结点）到底一个叶结点的任意一条路径上，黑色结点的个数称为该结点x的黑高度（bh(x)）。

## 插入
红黑树的插入过程与普通二叉查找树相似，只是需要将结点涂为红色。将结点涂为红色的过程，可能会破坏红黑树的性质：

1. 若新结点是根结点，则违反了性质2。这种情况下，只需要将根结点涂成黑色，这样所有路径上都增加了一个黑结点，不违反性质5。
2. 若新结点的父结点是红色的，则违反了性质4。

## 删除
如果要删除的结点z只有一个子结点或者没有子结点，那么删除该结点本身；如果z有2个子结点，则寻找其后继结点y（一般都是其右子树中最小的一个），后继结点y必定没有或只有个子结点，用y将z替换掉，然后删除原来的y。但是在红黑树中，结点拥有颜色。如果删除的y结点是红色结点，则红黑树的性质不会被破坏；如果删除的y结点是黑色结点，则需要考虑以下情况：

## linux内核中的红黑树
### rbtree root
树的头结点

	struct rb_root {
		struct rb_node *rb_node;
	};

### rbtree node
使用时将以下结构体嵌入自己的struct里，就可以使用linux kernel自带的宏。

	struct rb_node {
    		unsigned long  __rb_parent_color;
    		struct rb_node *rb_right;
    		struct rb_node *rb_left;
	} __attribute__((aligned(sizeof(long))));

红黑树结点中的__rb_parent_color，既保存了父结点的指针，又保存了结点的颜色。原理在于，rb_node是按long的大小来对齐的，在32位系统里也就是4字节(在64位系统中是8字节，但是并不影响)。那么任意struct rb_node的地址必定是4的倍数，用二进制表示的话，最低2位必然为0。因为必然为0，所以低2位可用来保存结点的颜色。在取地址时，将低2位置为0；在取颜色时，只取低2位即可。
### 红黑树的宏
#### rb_parent: 从__rb_parent_color中获得父结点的地址
	#define rb_parent(r)   ((struct rb_node *)((r)->__rb_parent_color & ~3))

之前已经提到，要从__rb_parent_color中取出父结点地址，只需将最低2位置0即可。3在二进制中是0000 0011，~3(取反)是除最后2位以外，其余全部为0。将~3与__rb_parent_color取合运算即可获得父结点的地址。

### rb_entry: 从struct rb_node结构体，获取包含它的结构体的地址
	#define rb_entry(ptr, type, member) container_of(ptr, type, member)
	#define container_of(ptr, type, member) ({
		const typeof( ((type *)0)->member ) *__mptr = (ptr);
		(type *)( (char *)__mptr - offsetof(type,member) );})
	#define offsetof(TYPE, MEMBER)  ((size_t)&((TYPE *)0)->MEMBER)

注：以上代码需要用到gcc的扩展，gcc -std=gnu99

我们有以下结构体，已知node的地址，求data的地址。

	struct data {
		int i;
		struct rb_node node;
	};

原理：计算出node在data里的偏移量，然后把node的地址减去偏移量即得到data的地址。

偏移量：将0转换成struct data*类型，然后看它的node成员的地址(当然这个data结构体并不存在)，就是偏移量。

container_of宏：需要3个参数，分别是ptr(node的地址)，type(本例中struct data)，member(本例中为node成员)
