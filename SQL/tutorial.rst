SQL基础
====================================
ORDER BY
-----------------------------
将SELECT的结果按照指定的字段排序。

ORDER BY可接受多个参数，排序的时候先按第一个参数的字段排序，若两条记录的该字段值相等，则比较下一个参数的字段。在字段后加DESC表示从大到小排序。

JOIN
-----------------------------
笛卡尔积
~~~~~~~~~~~~~~~~~~~~~~~~
简单地将两个表的记录拼起来::

    SELECT * FROM table1, table2;

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


View视图
-----------------------------
视图类似表，可以对其进行查询。View相当于存储了一条查询语句::

    CREATE VIEW myview AS
        SELECT city, temp_lo, temp_hi, prcp, date, location
            FROM weather, cities
            WHERE city = name;
    SELECT * FROM myview;


Foreign Keys
-----------------------------
外键是这样一个字段，它唯一地对应另一个表中的一个记录::

    CREATE TABLE cities (
            city     varchar(80) primary key,
            location point
    );
    
    CREATE TABLE weather (
            city      varchar(80) references cities(city),
            temp_lo   int,
            temp_hi   int,
            prcp      real,
            date      date
    );

如果插入一个不存在的城市的名字::

    INSERT INTO weather VALUES ('Berkeley', 45, 53, 0.0, '1994-11-28');

就会报错::

    ERROR:  insert or update on table "weather" violates foreign key constraint "weather_city_fkey"
    DETAIL:  Key (city)=(Berkeley) is not present in table "cities".

因此，外键保证了数据的正确性，不过会带来一些性能损失。互联网公司似乎都不喜欢用。


Transaction事务
-----------------------------
事务将多个操作绑定到一起，要么执行成功，要么什么也不做。一旦事务成功完成，数据库保证这些数据即使系统崩溃也不会丢失。且多个并行执行的事务，不会看到其它事务未完成的修改。::

    BEGIN;
    UPDATE accounts SET balance = balance - 100.00
        WHERE name = 'Alice';
    -- etc etc
    COMMIT;

SAVEPOINT
~~~~~~~~~~~~~~~~~~~~~~~~
可以在事务的途中设置SAVEPOINT，之后可以回退到这些SAVEPOINT，例如::

    BEGIN;
    UPDATE accounts SET balance = balance - 100.00
        WHERE name = 'Alice';
    SAVEPOINT my_savepoint;
    UPDATE accounts SET balance = balance + 100.00
        WHERE name = 'Bob';
    -- oops ... forget that and use Wally's account
    ROLLBACK TO my_savepoint;
    UPDATE accounts SET balance = balance + 100.00
        WHERE name = 'Wally';
    COMMIT;


Window Functions
-----------------------------
窗口函数是对一组值进行操作，不需要使用GROUP BY 子句对数据进行分组，还能够在同一行中同时返回基础行的列和聚合列。举例来说，我们要得到一个年级所有班级所有学生的平均分，按照传统的写法，我们肯定是通过AVG聚合函数来实现求平均分。这样带来的”坏处“是我们不能轻松地返回基础行的列（班级，学生等列），而只能得到聚合列。因为聚合函数的要点就是对一组值进行聚合，以GROUP BY 查询作为操作的上下文，由于GROUP BY 操作对数据进行分组后，查询为每个组只返回一行数据，因此，要限制所有表达式为每个组只返回一个值。而通过窗口函数，基础列和聚合列的查询都轻而易举。

语法：SELECT func(args) OVER () FROM xxx。OVER必须紧跟着窗口函数的名字和参数

我们来看例子。设表中有以下字段

- depname: Text, department name
- empno: Int, employee number
- salary: Int

需求：输出每个记录的depname, empno, salary以及该部门的平均工资。PARTITION BY depname表示将depname相同的记录作为单独的一组来处理，因此avg(salary)求出的是depname相同的记录的平均值::

    SELECT depname, empno, salary, avg(salary) OVER (PARTITION BY depname) FROM empsalary;

    depname   | empno | salary |          avg
    ----------+-------+--------+-----------------------
    develop   |    11 |   5200 | 5020.0000000000000000
    develop   |     7 |   4200 | 5020.0000000000000000
    develop   |     9 |   4500 | 5020.0000000000000000
    develop   |     8 |   6000 | 5020.0000000000000000
    develop   |    10 |   5200 | 5020.0000000000000000
    personnel |     5 |   3500 | 3700.0000000000000000
    personnel |     2 |   3900 | 3700.0000000000000000
    sales     |     3 |   4800 | 4866.6666666666666667
    sales     |     1 |   5000 | 4866.6666666666666667
    sales     |     4 |   4800 | 4866.6666666666666667
    (10 rows)

需求：将每个部门的员工按照工资从高到低排序，并标上序号。PARTITION语句将记录按depname分为了几组，因此rank()是针对每个小组内标序号。如果没有PARTITION，rank()就是将所有记录视为一大组，进行标序号::

    SELECT depname, empno, salary,
        rank() OVER (PARTITION BY depname ORDER BY salary DESC)
    FROM empsalary;

      depname  | empno | salary | rank 
    -----------+-------+--------+------
     develop   |     8 |   6000 |    1
     develop   |    10 |   5200 |    2
     develop   |    11 |   5200 |    2
     develop   |     9 |   4500 |    4
     develop   |     7 |   4200 |    5
     personnel |     2 |   3900 |    1
     personnel |     5 |   3500 |    2
     sales     |     1 |   5000 |    1
     sales     |     4 |   4800 |    2
     sales     |     3 |   4800 |    2
    (10 rows)


窗口函数仅可用于查询命令中的SELECT列表和ORDER BY语句中，其它地方是禁止的(比如GROUP BY, HAVING, WHERE)，因为窗口函数逻辑上是在上述语句之后执行的。且窗口函数在合计函数之后执行。因此，合计函数的结果可用作窗口函数的参数，但是反过来不行。如果需要在窗口函数执行后进行过滤、分组操作，可以使用子查询::

    SELECT depname, empno, salary, enroll_date, pos
    FROM
        (SELECT depname, empno, salary, enroll_date,
                rank() OVER (PARTITION BY depname ORDER BY salary DESC, empno) AS pos
         FROM empsalary
        ) AS ss
    WHERE pos < 3;

AS语句可将某个复杂的字段、子查询起个别名，以便后续使用。

SQL语句可以包含多个窗口函数。WINDOW语句可以给窗口函数命名::

    SELECT sum(salary) OVER w, avg(salary) OVER w
        FROM empsalary
        WINDOW w AS (PARTITION BY depname ORDER BY salary DESC);


Inheritance
-----------------------------
一个表可以继承另一个表，衍生出来的表会继承原表的所有字段，并且可以在此基础上增加新的字段::

    CREATE TABLE cities (
      name       text,
      population real,
      altitude   int     -- (in ft)
    );
    
    CREATE TABLE capitals (
      state      char(2)
    ) INHERITS (cities);

对原表进行查询，衍生表的结果也会显示出来::

    SELECT name, altitude
        FROM cities
        WHERE altitude > 500;

    name       | altitude
    -----------+----------
    Las Vegas  |     2174
    Mariposa   |     1953
    Madison    |      845
    (3 rows)

用ONLY可以只查询原表的内容::

    SELECT name, altitude
        FROM ONLY cities
        WHERE altitude > 500;

    name       | altitude
    -----------+----------
    Las Vegas  |     2174
    Mariposa   |     1953
    (2 rows)
