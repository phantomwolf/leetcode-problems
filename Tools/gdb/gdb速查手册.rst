gdb速查手册
===========================
程序的启动与停止
-----------------------
gcc -g myprogram.c
    使用-g选项编译程序，使你可以在gdb中获取程序的变量、函数名（而不只是内存地址）

gdb a.out
    使用gdb打开编译好的程序，但并不运行程序。

run ARG1 ARG2 < INFILE > OUTFILE
    （简：r）。运行目标程序，支持参数、输入输出重定向。\*和[...]这类的参数会由sh来展开。

help COMMAND
    （简：h）。显示该命令的帮助信息

quit
    （简：q）。退出gdb

逐步运行程序
-----------------------
list
    （简：l）列出当前位置的代码

list FILE:LINENUM
    列出文件FILE的第LINENUM行的代码

list FILE:FUNCTION
    列出文件FILE里的FUNCTION函数

next [N]
    （简：n）运行下一行代码，然后暂停。如果下一行是函数，那就运行整个函数，并不进入函数内部。如果指定了N，就运行N次next。

step [N]
    （简：s）运行下一个指令，然后暂停。如果下一行是函数，那就进入函数内部。如果指定了N，就运行N次step。

finish
    运行到当前函数结束，然后暂停。

断点、监视点
-----------------------
break [LOCATION] [thread THREADNUM] [if CONDITION]
    （简：b）在LOCATION处设置断点，LOCATION可以是行号、函数。THREADNUM可以通过info threads来找到。CONDITION是一个返回bool的表达式。

watch EXPRESSION
    设置一个监视点，当EXPRESSION的值发生变化时，暂停程序的运行。

continue
    继续运行，直到下一个断点/监视点。

delete breakpoints N
    删除N号断点

变量、函数
-----------------------
print EXPR
    输出表达式EXPR当前的值

set VAR = EXPR
    将表达式EXPR的值赋给变量VAR。VAR可以是以$开头的，仅用于方便调试用的变量；也可以是程序中的变量。

call FUNCTION(ARG1, ARG2)
    调用函数FUNCTION。返回结果会被加到value history中，例如：$3 = xxx

display EXPR
    每次程序停止的时候，打印表达式EXPR的值。如果没有参数，打印当前所有自动显示的表达式。

undisplay NUM
    停止打印表达式。NUM是表达式的序号。

回溯、帧切换
-----------------------
栈(Stack)是当前的函数调用的列表，它显示你在程序中所处的位置。帧(Frame)保存一次函数调用的细节，比如参数。

bt
    回溯，也就是将当前的函数栈打印出来，显示你当前所处的位置。

up [N], down [N]
    在栈中上下切换帧。可用于切换到上一层函数里，检查本地变量。

return
    从当前函数中返回

崩溃、核心转储
-----------------------
核心转储(Core dump)是程序崩溃时的内存快照，一般存放在叫做core的文件里。gdb可以读取core dump文件，给出崩溃处的行号，传递过去的参数，以及其它信息。

gdb myprogram core
    以core作为core dump文件来调试myprogram

bt
    打印崩溃时的call stack，可以用up、down来切换，并检查变量们。

处理信号
-----------------------
信号(Signal)在特定事件后发出。gdb可以在遇到信号时暂停，或者忽略信号。

handle SIGNAL [ACTION]
    指定如何处理信号。有效的ACTION有：stop(暂停，重新进入gdb), nostop, print(打印信息), noprint, pass(将信号传递给程序), nopass(不把信号传递给程序), ignore(等于nopass), noignore(等于pass)。

自定义函数
-----------------------
gdb的define命令可以定义函数，配合上以$开头的辅助变量，就能像普通程序一样写函数。gdb支持的指令有: if, else, while, loop_break, loop_continue, end::

	define adder
		if $argc == 2
			print $arg0 + $arg1
		end
		if $argc == 3
			print $arg0 + $arg1 + $arg2
		end
	end

以及::

	define adder
		set $i = 0
		set $sum = 0
		while $i < $argc
			eval "set $sum = $sum + $arg%d", $i
			set $i = $i + 1
		end
		print $sum
	end

要执行函数，只需：adder 1 2 3。


source COMMANDFILE
	读取一个COMMANDFILE。COMMANDFILE是由gdb命令写成的文本文件，可用于引入自定义函数。#开头的行为注释。

document COMMANDNAME
	为函数添加文档

show user, show user COMMANDNAME
	显示COMMANDNAME的定义

show max-user-call-depth, set max-user-call-depth
	max-user-call-depth值表示，多少层递归后，gdb开始怀疑存在死循环。

经验
===========================
监测点比断点好用
-----------------------
watchpoint经常比breakpoint好用，这样我们就可以在需要的时候才停下来，而不是每次循环都停一下。

把printf封装为log函数
-----------------------
建议把printf封装为log函数，并支持LOG_LEVEL功能。并在代码里定义当前的LOG_LEVEL::

	#define LOG_NONE 0
	#define LOG_ERROR 1
	#define LOG_WARN 2
	#define LOG_INFO 3
	#define LOG_LEVEL LOG_WARN
	// shows msg if allowed by LOG_LEVEL
	int log(char *msg, int level){
		if (LOG_LEVEL >= level){
			printf("LOG %d: %s\n", level, msg);
			// could also log to file
		}
		return 0;
	}
