SQL语法
====================================
ORDER BY
-----------------------------
将SELECT的结果按照指定的字段排序。

ORDER BY可接受多个参数，排序的时候先按第一个参数的字段排序，若两条记录的该字段值相等，则比较下一个参数的字段。在字段后加DESC表示从大到小排序。

JOIN
-----------------------------
笛卡尔积
~~~~~~~~~~~~~~~~~~~~~~~~
笛卡尔积也叫Cartesian Join，将所有可能的组合都显示出来，有两中写法::

    SELECT * FROM table1, table2;
    SELECT * FROM table1 CROSS JOIN table2;

SELF JOIN
~~~~~~~~~~~~~~~~~~~~~~~~
顾名思义，按照一定条件，将表与它自己连接::

    SELECT * FROM salary a, salary b WHERE a.salary < b.salary;

其它JOIN
~~~~~~~~~~~~~~~~~~~~~~~~
见join.pdf


Aggregate Function
-----------------------------
合计函数。Postgresql也支持函数。Aggregate Functions从多行记录中计算出一个单一的结果。常用的函数有：count、sum、avg、max、min。使用示例::

    SELECT max(temp_lo) FROM weather;

但是函数不能被用在WHERE语句中，因为WHERE语句决定了哪些记录会被用做函数的输入，所以WHERE语句必须在函数之前被求值。例如，以下SQL语句是错误的::

    SELECT city FROM weather WHERE temp_lo = max(temp_lo);  -- 错误！

可以用子查询实现上述需求。::

    SELECT city FROM weather WHERE temp_lo = (SELECT max(temp_lo) FROM weather);

GROUP BY语句
~~~~~~~~~~~~~~~~~~~~~~~~
GROUP BY语句经常与合计函数一起用，例如::

    SELECT city, max(temp_lo) FROM weather GROUP BY city;

结果::

    city          | max
    ---------------+-----
    San Francisco |  46
    Hayward       |  37
    (2 rows)

第一条数据表示，当city值为San Francisco时，temp_lo的最大值为46。

HAVING语句
~~~~~~~~~~~~~~~~~~~~~~~~
因为WHERE里不能使用合计函数，所以引入了HAVING语句。求值的顺序是：WHERE语句 -> 合计函数 -> HAVING语句。例如::

    SELECT avg(temp_lo), max(temp_lo), city FROM weather GROUP BY city HAVING avg(temp_lo) > 40;


UPDATE语句
-----------------------------
UPDATE语句可用与更新表中记录，例如下面的语句将最高、最低温度都减少2::

    UPDATE weather SET temp_hi = temp_hi - 2, temp_lo = temp_lo - 2
            WHERE date > '1994-11-28';


DELETE语句
-----------------------------
删除记录::

    DELETE FROM weather WHERE city = 'Hayward';

要小心的是，如果没有WHERE语句的限制，会从表中删除所有记录，例如::

    DELETE FROM weather;


DROP语句
-----------------------------
DROP可用于删除表或数据库::

    DROP TABLE students;
    DROP DATABASE student_data;


TRUNCATE语句
-----------------------------
TRUNCATE可清空表。不同于DELETE，TRUNCATE语句会略过完整性检查，也因此性能更好::

    TRUNCATE TABLE Student_details;


View视图
-----------------------------
视图类似表，可以对其进行查询。View相当于存储了一条查询语句::

    CREATE VIEW myview AS
        SELECT city, temp_lo, temp_hi, prcp, date, location
            FROM weather, cities
            WHERE city = name;
    SELECT * FROM myview;


Alias
-----------------------------
可以用AS来给column或table起别名。子查询可视为一个表，也可以用AS来添加别名::

    SELECT empno AS no, salary FROM salary;  # 在结果中，empno一列会被显示为no
    SELECT avg(tmp.salary) FROM (SELECT empno, salary FROM salary ORDER BY empno) AS tmp;


UNION
-----------------------------
用于将两个SELECT语句的结果合并，即两个集合的并集。两个SELECT语句的列的类型以及顺序必须相同。重复结果会被去掉::

    SELECT column_name(s) FROM table1 UNION SELECT column_name(s) FROM table2;


PostgreSQL
====================================
双引号
-----------------------------
PostgreSQL中，关键字(例如SELECT)、标识符(例如table_name)都是不区分大小写的。然而有一个例外，带双引号的标识符区分大小写，且双引号中的任何内容都将被视为标识符，而不是关键字::

    UPDATE "my_table" SET "a" = 5;

这意味着可以用关键字当表名、数据库名::

    CREATE TABLE "select" (xxx);

而单引号是SQL中的字符串，不要混淆。
