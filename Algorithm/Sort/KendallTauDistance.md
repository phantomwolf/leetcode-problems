# Kendall tau distance
Kendall tau距离表示两个序列中倒置的数量，例如cba和cab的Kendall tau距离为1，倒置为(a, b)。

要计算两个字符串ACBED和CDABE的Kendall tau距离，可以为第一个字符串的每个字符编号：

    01234
    ACBED

根据每个字符分配到的编号，将第二个字符串改写成按编号形式：

    14023
    CDABE

接下来，只需要计算数字序列14023中有多少个倒置，就能知道两个字符串的Kendall tau距离了。

## 计算倒置
如何计算一个序列中的倒置数量？我们可以使用merge sort。

当归并两个有序子数组时，若arr[leftIndex] > arr[rightIndex]，这表示arr[leftIndex..leftEnd]的元素都比右半部分要大，所以当前arr[rightIndex]产生了numberOfElementsInTheLeftSide - leftIndex + 1个倒置。
