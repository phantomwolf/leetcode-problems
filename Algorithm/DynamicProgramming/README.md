# Leetcode DP Problems

* 70. Climbing Stairs [Easy]
* 198. House Robber [Medium]
* 139. Word Break [Medium]
* 188. Best Time to Buy and Sell Stock IV [Hard]
* [2510. Check if There is a Path With Equal Number of 0's And 1's](https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s/description/)
* 416. Partition Equal Subset Sum [Medium]

# 动态规划
动态规划是一种算法范式(algorithmic paradigm)，它将复杂的问题分解为较小的子问题，并且存储这些子问题解，以避免重复求解。


## 性质
以下两个性质确保问题可以用动态规划解决：

### 最优子结构
一个问题拥有最优子结构(Optimal substructure)，说明问题可以通过采用其子问题的最优解来解决。

### 重叠子问题
像分治法一样，动态规划需要合并子问题的解。动态规划多用于需要重复计算子问题的解的情况，它将子问题的解存入一个数组，之后需要时直接读取，提高了性能。所以当子问题不需要重复求解时(例如归并排序)，动态规划是没有意义的，因为不需要存储子问题的解(这时可以用分治法divide and conquer)。

## 问题
### Longest Increasing Subsequence(LIS)
Longest Increasing Subsequence：在一个序列（比如一个数组）中，找出最长的子序列的长度，使其所有元素递增。子序列不要求连续。

状态转移方程：设d[i]为在i处结尾的最长递增子序列的长度。那么有:

    设0 < j < i，若存在arr[j] < arr[i]，那么d[i] = 1 + max(d[j])
    若不存在这样的j，那么d[i] = 1

可见，我们必须把所有的j尝试一遍，才能知道d[i]的值。要求出d[3]，我们需要求出d[2]、d[1]、d[0]；要求出d[2]，我们需要求出d[1]、d[0]。如果我们用普通的递归法求解，d[1]、d[0]会被重复求值。因此我们用循环的方式，先求较小问题，并用数组d存储它们的结果，避免重复求解。

### Longest Common Subsequence(LCS)
描述：Longest Common Subsequence：给定2个序列，找出它们最长的公共子序列，求其长度。子序列不要求连续。LCS可用于表示两个字符串的相似度

### Edit Distance
给定2个字符串str1和str2，str1上可以执行插入一个字符、删除一个字符、替换一个字符这3个操作。问至少需要多少次操作，可以把str1转换为str2。

定义子问题：设str1长度为m，str2长度为n。子问题就是求str1与str2的前缀的edit distance。

#### 递归解
设edit_distance(str1, m, str2, n)为str1与str2的edit distance。

如果str1和str2的最后一个字符相同，那么我们就没必要对这个字符进行任何操作，因此可以将问题转化为一个较小的问题edit_distance(str1, m - 1, str2, n - 1)。

如果str1和str2的最后一个字符不相同，那我们有3种操作可以选，我们需要求操作数最少的一个::

    edit_distance(str1, m, str2, n) == 1 + min(edit_distance(str1, m, str2, n - 1), // 插入
                                               edit_distance(str1, m - 1, str2, n), // 删除
                                               edit_distance(str1, m - 1, str2, n - 1)) // 替换

### Min Cost Path
给定一个代价矩阵，矩阵中每个元素都表示经过该位置的代价。给定其中一个位置(m, n)，求从(0, 0)到达(m, n)所需的最小代价，以及路线。只能向右、向下或对角线前进::

    1 → 2   3
          ↘
    4   8   2
            ↓
    1   5   3

#### 最优子结构
要到达(m, n)，必须要经过3个位置中的1个：(m-1, n-1), (m-1, n), (m, n-1)。所以到达(m, n)的最小代价，等于到达这3个位置中代价的最小值，加上(m, n)的代价。由此，问题转化为子问题的最优解。

#### 重叠子问题
设min_cost(m, n)为到达(m, n)的最小代价，cost为代价矩阵，那么递归解为::

    min_cost(m, n) = cost[m][n] + min(min_cost(m - 1, n - 1),
                                      min_cost(m - 1, n),
                                      min_cost(m, n - 1));

                                    mC(2, 2)
                          /            |           \
                         /             |            \
                 mC(1, 1)           mC(1, 2)             mC(2, 1)
              /     |     \       /     |     \           /     |     \
             /      |      \     /      |      \         /      |       \
       mC(0,0) mC(0,1) mC(1,0) mC(0,1) mC(0,2) mC(1,1) mC(1,0) mC(1,1) mC(2,0)

可见，有些结点的代价被重复计算。如果问题的规模扩大，重复的结点会更多。因此，我们可以使用动态规划。

### Coin Change
有数量不限的面值为S = {S1, S2, .., Sm}的硬币，要凑齐N元，有多少种方案。

#### 分析
与求凑齐N元所需的最少硬币数不同，本题求共有多少种方案(且不能重复)。

本题并不能简单的用count(i)表示凑齐i元所需的方案数：假设有充足的面值为1、2的两种硬币，需要凑齐3元，有以下几种方案::

    先凑齐2元，再拿一个1元硬币
    先凑齐1元，再拿一个2元硬币

要凑齐2元，也有两种方案::

    两个1元硬币
    一个2元硬币

表面上看，凑齐3元共有3种方案：{1, 1, 1}, {1, 2}, {2, 1}。然而有2种方案是重复的。

为了避免重复，我们定义count(m, n)为只使用coins[0..m]种硬币，凑齐n元有多少种方案(相当于排除了一些硬币coins[m+1..$])。要凑齐n元，有两类方案：一种是完全不包含coins[m]的；一种是至少包含一个coins[m]的。因此::

    count(m, n) = count(m - 1, n) + count(m, n - coins[m])

设d[i][j]为，在可以使用coins[0..j]的情况下，凑齐i元，共有多少种方案。于是有::

    int d[amount + 1][coins.size()];
    for (int i = 0; i < len; ++i) {
        // 要凑齐0元，不管用哪些硬币，都只有1种方案
        d[0][i] = 1;
    }

    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < len; ++j) {
            int x = (j > 0) ? d[i][j - 1] : 0;
            int y = (i >= coins[j]) ? d[i - coins[j]][j] : 0;
            d[i][j] = x + y;
        }
    }

但是此算法的空间可以进一步优化。已知count(0, n) = 0，将cout(m, n)的式子继续展开，有::

    count(m,n) = count(m-1,n) + count(m,n-coins[m])
               = count(m-2,n) + count(m-1,n-coins[m-1]) + count(m,n-coins[m])
               = count(m-3,n) + count(m-2,n-coins[m-2]) + count(m-1,n-coins[m-1]) + count(m,n-coins[m])
               ...
               = count(0,n) + count(1,n-coins[1]) + count(2, n-coins[2]) + ... + count(m,n-coins[m])
               = count(1,n-coins[1]) + count(2, n-coins[2]) + ... + count(m,n-coins[m])

即不断缩小可选硬币的范围，每次都规定至少使用一个可用范围内最大面值的硬币。通过更改循环的次序，我们可以用一维数组来解决问题::

    int d[amount + 1] = {0};
    d[0] = 1;
    for (int i = 0; i < len; ++i) {
        for (int j = coins[i]; j <= amount; ++j)
            d[j] += d[j - coins[i]];

i为coins的下标，表示至少要使用一个coins[i]硬币；j为要凑齐的钱数。如果j < coins[i]，显然可行方案数为0（默认值），因此j是从本次必须要使用的硬币面值coins[i]开始增长的。


### 矩阵相乘
有一系列矩阵相乘，求相乘的顺序，使得乘法运算的次数最少。返回最少的乘法次数。

矩阵乘法的次序不影响最终结果，例如(AB)C = A(BC)。设3个矩阵，分别为：A 10x30，B 30x5, C 5x60。两种计算次序的乘法次数分别为::

    (AB)C = (10x30x5) + (10x5x60) = 4500
    A(BC) = (30x5x60) + (10x30x60) = 27000

可见第一种方法更加高效。

#### 分析
如何将用子问题的最优解计算较大问题的最优解呢？假设我们有3个矩阵相乘ABC，如何扩展到4个矩阵相乘呢？::

    ABCD = (ABC)D = (AB)(CD) = A(BCD)

可见共有3种方案，我们需要求其中乘法次数最小的一个，这意味着我们需要求出全部3种方案的值，然后求min。观察这3种方案可以发现，我们需要知道矩阵链中任意一段的乘法次数。所以我们要设置一个二维数组d[i][j]，表示从i到j的所有矩阵相乘，最少需要多少次乘法运算。


### 0-1背包问题
背包问题(Knapsack Problem)：有一个可容纳重量为W的背包，给定一些重量、价格已知的物品。求如何选取，才能让背包里的物品价值最高。物品不能重复选择。

#### 分析
此问题难处在于，不允许重复选择元素，每个物品只有一个。所以我们每选择一个物品，还要更改可选用物品的范围。

设val[]包含物品价值，wt[]包含物品重量，n为这俩数组的长度。knapsack(W, wt[], val[], n)表示：wt[]与val[]的长度为n(超过此长度的物品不考虑)，使用这些物品，如何使容量为W的背包里的物品价值最大。我们可以考虑2种情况，一种是把item[n-1]放入背包，并将item[n-1]排除在外，此时背包里物品的最大价值为::

    knapsack(W - wt[n-1], wt[], val[], n - 1);

另一种情况是，不把item[n-1]放入背包，并将其排除在外(保证之后也不会选用item[n-1]，避免和上一种情况重复)，此时背包物品价值为::

    knapsack(W, wt[], val[], n - 1);

我们要求背包价值最大的情况，因此::

    knapsack(W, wt[], val[], n) = max(knapsack(W - wt[n-1], wt[], val[], n - 1),
                                      knapsack(W, wt[], val[], n - 1));

采用自底向上的计算方法，令d[i][j]表示knapsack(j, wt[], val[], i)。


### 11 Egg Dropping Puzzle
丢鸡蛋问题。我们有n个鸡蛋，和一个k层的楼梯。已知：

- 所有鸡蛋都是一样的
- 如果从某层台阶丢下鸡蛋后摔碎，那么从更高的台阶丢下鸡蛋一定会摔碎；如果从某层台阶丢下鸡蛋后没有摔碎，那么从更低的台阶丢下鸡蛋一定不会摔碎。
- 坏掉的鸡蛋必须丢掉，没摔碎的可以继续用
- 不排除第一个台阶就会摔碎鸡蛋，也不排除最后一个台阶也不会摔碎鸡蛋

设目标台阶为，可以安全丢鸡蛋而不会摔碎的最高台阶。求应该从哪些台阶丢下鸡蛋，使得我们用最少的次数来探测出目标台阶，最少的探测次数是多少。

#### 分析
当设egg_drop(n, k)为：共有k个台阶。最坏情况下，用n个鸡蛋来探测目标台阶，需要丢几次鸡蛋。

当从第x个台阶丢下鸡蛋时，有两种情况：鸡蛋碎了，鸡蛋没碎。如果鸡蛋碎了，我们只需要用剩下的鸡蛋，检查更低的台阶即可，问题转化为1 + egg_drop(n-1, x-1)；如果鸡蛋没碎，我们只需要检查比x高的台阶，问题转化为1 + egg_drop(n, k-x)。由于不知道哪一种情况会发生，所以我们取这两种情况的最大值::

    max(egg_drop(n-1, x-1), egg_drop(n, k-x))

穷尽所有x，并取其中的最小值，就是在最坏情况下，探测出目标台阶所需的丢鸡蛋次数::

    egg_drop(n, k) = 1 + min(  max(egg_drop(n-1, x-1), egg_drop(n, k-x))  ), x属于[1, k]

### LongestBitonicSubsequence
求数组中的一个最长子序列，使其元素先递增，再递减。递增的子序列，可被视为递减部分为空；全程递减的子序列，可被视为递增部分为空。二者均符合要求。

#### 分析
此题可时为LIS(Longest Increasing Subsequence)问题的变种。不同于LIS序列，Bitonic序列先增后减。因此我们设置两个数组lis和lds，lis保存以array[i]结尾的Longest Increasing Subsequence的长度，lds保存以array[i]开头的Longest Decreasing Subsequence的长度。max(lis[i] + lds[i] - 1)就是我们要求的结果。


### 17 Palindrome Partitioning
将一个字符串分为几段，如果每段都是一个回文(Palindrome)，那么这种划分方案叫做Palindrome Partitioning。给定一个字符串，求如何划分最少的次数，使每段都是一个回文。

#### 分析
已知：一个长度为1的字符串永远是回文；一个长度为2的字符串，如果两个字符相等，那么它是回文。一个回文，可以通过在左右两边各添加一个相同的字符，来扩展成一个较大的回文。

#### 变种
返回所有的划分方案。可以用递归法，也可以用动态规划。

若用动态规划，需要自己设置一个vector<vector<vector<string>>> result变量，来记录中间结果，设result[i]包含对于子字符串str[0..i]，所有的分区方案。每个分区方案都是一个vector<string>，每个string都是一段回文。


### 18 Partition Problem
分区问题(Partition Problem)是决定一个集合是否可以被分为两个子集，使得两者的和相等。

#### 分析
计算整个数组的和sum，如果是奇数，那么不可能有2个子集的和相等(因为元素均为整数，不可能加起来等于一个小数)。

如果整个数组的和sum为偶数，找出一个子集，使其元素和为sum/2即可。

设detect(int arr[], int n, int target)返回布尔值，表示长度为n的数组arr[]中是否存在一个子集，使其值为target。那么有::

    detect(arr[], n, sum/2) = detect(arr, n - 1, sum/2) ||
                              detect(arr, n - 1, sum/2 - arr[n - 1])

前者是arr[n - 1]不在序列里的情况；后者是arr[n - 1]在序列中的情况。二者只要有1个为true，那就说明存在一个子序列，使得其和为sum/2。由于数组所有元素的和为sum，所以另一半元素的和也为sum/2，于是我们就可以确定，可以把arr[]分为2个子集，使两者和相等。

与之前的题类似，使用二维数组d[i][j]，i表示target，j表示arr[]的长度。

### 19 Word Wrap Problem
自动换行问题。在类似Word这种编辑器中，为了让一个单词不被分散到两行中，都有自动换行功能。如果一行中剩余的空间放不下一个单词，就会在该行补齐空格，并把该单词写入下一行。Word Wrap Problem，是探讨如何让除最后一行外，每行中补齐空格的数量更加平均。

设每一行补齐空格的代价是末尾补齐空格数量的平方(之所以用平方，是为了避免某一行末尾出现过多空格)

#### 贪心算法
贪心算法，即在任何一行中都尽可能写入更多的单词。然而在以下情况下，并不能获得最优解::

    aaa bb
    cc
    ddddd

这种情况下，尽管第一行可以放得下bb，但将bb写入第二行更好::

    aaa
    bb cc
    ddddd

因此贪心算法并不适用。

#### 动态规划
设置一个二维数组lc[][]，lc[i][j]表示将单词i到j放入同一行，会有多大的代价，代价等于末尾补齐空格的数量的平方。如果单词i到j并不能放入同一行，那么lc[i][j] = ∞ 。当构建好lc表后，设c[j]为word[0..j]的代价之和::

    c[j] = min(c[i - 1] + lc[i][j]), 1 <= i <= j


### 20 Maximum Length Chain of Pairs
给定一系列序偶，第一个数字永远小于第二个。若b < c，那么(a, b), (c, d)可以组成一个链。求最长的链的长度，以及相应的序偶。

本题是Longest Increasing Subsequence的变种，区别是原本的整数变成了序偶，LIS问题中可以直接比较2个元素的大小，本题中需要比较前一个序偶的第二个数与后一个序偶的前一个数。


### 22 Box Stacking Problem
给定n种立方体，每种立方体的数量都不限，你要尽可能高地将这些立方体堆起来，求最高可以堆多高，并给出所用立方体的序号。只有当上面的立方体的长宽都小于下面的立方体时，才可以将其放在上面；立方体可以任意旋转，即可以让任何一面朝下。

#### 思路
此题是LIS的变种，可以用如下方法转换为LIS问题：

1. 产生每个立方体的每一种旋转方案，存入一个数组squares。例如对于立方体1x2x3，可以产生1x2，2x3，1x3三种方案。为了便于比较，我们永远将较小的数放前面。
2. 将squares里的元素按照面积排序。因为如果一个立方体可以放在另一个上面，那么其底部面积一定是小于另一个的。
3. 接下来，问题就跟LIS问题一样了。我们需要找出一个按照面积递减的序列，且长宽必须小于上一个元素的长宽。

### 24 Optimal Binary Search Tree
给定一个有序的数组keys[0..n-1]，保存二叉搜索树结点的key；给定一个数组freq[0..n-1]，保存相应结点的搜索次数(数字越大，表明该key搜索越频繁)。一个key的搜索代价，等于结点的深度乘以其freq，root结点的深度为1。

### 25 Subset Sum Problem
给定一个非负整数集合，和一个数值sum，判断集合中是否存在一个子集，使得其和为sum。

### 31 Optimal Strategy for a Game
有这样一个游戏：给定n个硬币，面值分别为v_1, v_2, ..., v_n，n为偶数。两个人轮流拿出第一个或最后一个硬币，直到没有硬币为止。最后硬币面值加起来后，大的一方获胜。

设两个玩家同样聪明，先手玩家应该如何取硬币，才能保证手里硬币的数量最大？最大值是多少？

#### 思路
首先要知道，每次都选两者中较大的一个，是不行的。例如对于：8, 15, 3, 7这4枚硬币，若先手拿较大的8,那么15就会被后手拿走，前者就会输掉比赛。

设F(i, j)表示先手玩家从第i到第j个硬币中，可以拿到的硬币面值总和的最大值。那么哪些情况呢？我们来分析一下：

首先，先手玩家可能从i...j硬币里选择v_i或者v_j。我们要取这两种方案的最大值。

选择了v_i后，后手玩家有可能选择v_i+1或者v_j，然后先手玩家才能再次选择。这时，我们要取两种情况中，对先手玩家最不利的情况，因为另一个玩家也很聪明。同样的，若先手玩家选择了v_j，那么同样有2种情况，我们同样需要取最不利的那一个。

综合以上情况，我们得到了递归解:

    F(i, j) = max(  v_i + min( F(i+2, j), F(i+1, j-1) ),
                    v_j + min( F(i+1, j-1), F(i, j-2) ))
    F(i, j) = v_i if j == i;
    F(i, j) = max(v_i, v_j) if j == i + 1;

### 37 Boolean Parenthesization Problem
有以下符号::

    T       true
    F       false

以及以下运算符号::

    &       boolean AND
    |       boolean
    ^       boolean

给定一个以上符号组成的运算序列，求有多少种加括号的方法，使得运算结果为true。

#### 思路
设T[i][j]为，让i与j之间的符号运算结果为true的括号方案总数；F[i][j]为，让i与j之间的符号运算结果为false的括号方案总数。那么，所有括号方案总数total[i][j]为T[i][j] + F[i][j]。

基础情况：当i == j时，问题范围内只有1个符号T或者F。若symbols[i]为T，那么T[i][i]就为1，F[i][i]为0，因为没有任何方法能让一个单独的T运算结果为F。当symbols[i]为F时也类似。

### Leetcode 221: Maximal Square
设dp[i][j]为以matrix[i][j]为右下角的正方形的边长。

观察矩阵可知

1. 若matrix[i][j]为0，那么dp[i][j]必为0
2. 若matrix[i][j]为1，但其左上方的点都为0，那么dp[i][j]为1
3. 若matrix[i][j]为1，且左上方也有一些1，那么就可能结合起来成为一个更大的正方形

我们考虑第3种情况，画图可知，若dp[i-1][j-1], dp[i-1][j], dp[i][j-1]均为x，那么dp[i][j]应为x+1；若dp[i-1][j-1], dp[i-1][j], dp[i][j-1]不相等，去三者的最小值，这对0值也适用。

结论：当matrix[i][j]为1时

    dp[i][j] = 1, i = 0 or j = 0
    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1

在求dp的同时跟踪其最大值，可以得到最大正方形的边长，从而求出其面积。

### Leetcode 516. Longest Palindromic Subsequence
将字符串s反转为r，s和r的Longest Common Subsequence就是s的Longest Palindromic Subsequence。

优化：

1. 我们没必要真的将s反转，只需要通过计算，造成反转的效果即可：r.charAt(j - 1)等价于s.charAt(s.length() - j)
2. 可以使用空间优化技巧，将dp数组优化成一维数组。

### Leetcode 1986. Minimum Number of Work Sessions to Finish the Tasks
DP + bitmap. bitmap用于表示tasks的一个子集。

设dp[mask] = {numberOfSessions, timeOfCurrentSession}为，完成mask所表示的任务所需的session数，和当前session的总共时间。

### Leetcode 1723. Find Minimum Time to Finish All Jobs
首先，用bitmap来表示jobs[]的所有子集，并求出每个子集的sum。

问题中有两个状态：mask表示子集，i表示worker数量。

### Bitmask + DP: Count ways to assign unique cap to every person
https://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/

There are 100 different types of caps each having a unique id from 1 to 100. Also, there are ‘n’ persons each having a collection of a variable number of caps. One day all of these persons decide to go in a party wearing a cap but to look unique they decided that none of them will wear the same type of cap. So, count the total number of arrangements or ways such that none of them is wearing the same type of cap.

Constraints: 1 <= n <= 10

Example:

The first line contains the value of n, next n lines contain collections of all the n persons.

    Input:
    3
    5 100 1     // Collection of the first person.
    2           // Collection of the second person.
    5 100       // Collection of the third person.

    Output:
    4
    Explanation: All valid possible ways are (5, 2, 100), (100, 2, 5), (1, 2, 5) and (1, 2, 100)

Since, number of ways could be large, so output modulo 1000000007

#### 分析
本题共有两个状态：一是当前戴帽子的人的集合，另一个是可用的帽子种类。设dp[i][mask]为：

    只用1...i的帽子，对mask所表示的子集里的所有人分配帽子，共有多少种方案

与其他DP问题一样，每次我们只考虑第i号帽子：要么让某个人戴上第i号帽子（如果他的收藏里有），要么什么也不做。

    什么也不做：dp[i][mask] += dp[i - 1][mask]
    给某人戴上：清空mask中某一bit得到新newMask，dp[i][mask] += dp[i - 1][newMask].

dp[i][mask]就是这两种情况的总和。

初始条件：当mask为0，而i大于0时，说明要给0个人分配帽子，此时答案为1。

### Bitmask + DP: Travelling Salesman Problem
https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/

共N个城市，售货员从第0城市出发，访问每个城市一次，最后回到城市0。求满足条件的最短路径的长度。

设dp[mask][i]为从0出发，访问mask所表示的城市的子集里的每个城市一次，最终停在i城市的最短路径的长度。当mask里只有2个bit为1时，表示子集里只有2个城市，dp[mask][i]即为两者之间的距离dist[0][i]；当mask有3个或以上的bit为1时，从mask中去掉一个0和i以外的bit "j"。根据dp的定义，`dp[mask][i] = min(dp[newMask][j] + dist[j][i])`，即可以先访问其他城市并停留在j，再从j前往i。尝试所有可能的j，取结果中的最小值，就是到达i的最优方案。
