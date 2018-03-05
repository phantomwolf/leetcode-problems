boost中的boyer_moore解析
===================================
使用方法
-----------------
boost中有个类模板boyer_moore，使用方法::

	#include <boost/algorithm/searching/boyer_moore.hpp>
	#include <string>

	int main(int argc, char *argv[])
	{
		string::iterator iter;
		string pattern("EXAMPLE");
		string text("HERE IS A SIMPLE EXAMPLE");
		boyer_moore<string::const_iterator> bm(pattern.begin(), pattern.end());
		iter = bm(text.begin(), text.end());
		return 0;
	}

观察可知，boyer_moore类模板需要iterator的类型，构造函数需要pattern的两个iterator。它的()操作符经过了重载，调用生成的对象即可开始搜索，返回一个iterator。


Bad Character坏字符规则
---------------------------------
boost采用的是没有使用扩展规则的bad character规则，即只记录每个字符最后一次出现的位置。如果此位置在当前位置的右边，则对我们没有帮助。

该类中建立bad character规则表的函数为 build_skip_table，此表被称为 skip_table(变量为skip_)。


Good Suffix好后缀原则
---------------------------------
当pattern的一个后缀t已经匹配成功，但t左边的字符不匹配时，我们需要在t的左边寻找一个相同的子字符串t'，且t'左边的字符与t不同，并且通过移动，将t'移动到t原来的位置。如果无法找到这样一个t'，那么就跳过pattern的既是适当前缀又是后缀的子字符串的长度（类似KMP）。

对于前者，boost将pattern反转，并用compute_bm_prefix函数计算其既是适当前缀又是后缀的子字符串的长度表，正如KMP算法中的一样。设pattern为P，反转后的pattern为P'，该表为prefix_reversed。有如下关系::

    P:                  AAABAA
    prefix:             012012
    P':                 AABAAA
    prefix_reversed:    010122
   
设j为pattern的index，我们来看j=5时不匹配的情况

    P:                  A|AABAA
    P'                  AABAA|A    
    prefix_reversed     01012|2
    
可以发现，我们找到了后缀t: AA在前面的t': AA。
