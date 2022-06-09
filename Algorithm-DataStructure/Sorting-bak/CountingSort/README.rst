计数排序(Counting Sort)
=======================================
给定数组A，已知A中都是非负整数，当中最大值为max。

设置一个int count[max + 1]数组。先扫描一遍数组A，记录每个数出现的次数。然后令count[i] = count[i] + count[i-1]。这样，数组A中范围[count[i-1], count[i])都应该写入i。
