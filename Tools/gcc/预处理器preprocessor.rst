Concatenation拼接
====================================
宏中的##符号可以将左右两边的符号拼接成一个符号，例如::

    #define VAR(num)     var_##num
    ...
    VAR(386) = 999;                     # 展开为var_386 = 999;

也可以拼接出多字符的运算符，例如::

    #define OPERATOR(op)    op##=
    ...
    num OPERATOR(+) 3;                  # 展开为num += 3;

但是需要注意的是，拼接出的结果必须是一个符号(token)，否则预处理器将报错，例如下面的会报错::

    #define RESULT(op)    result##op
    ...
    RESULT(=) 386;                      # 理论上会展开为result= 386，但由于result=并不是一个符号(token)，因此会出错

顺便一提，在上述例子中，拼接是多余的，只要这样就可以了::

    #define RESULT(op)    result op
