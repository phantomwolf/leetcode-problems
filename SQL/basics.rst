SQL基础
====================================
JOIN
-----------------------------
笛卡尔积
~~~~~~~~~~~~~~~~~~~~~~~~
简单地将两个表的记录拼起来::

    SELECT * FROM table1, table2;

INNER JOIN
~~~~~~~~~~~~~~~~~~~~~~~~
交集，两个表里都有的记录才会被选中::

    SELECT * FROM table1, table2 WHERE table1.id = table2.id;

或者::

    SELECT * FROM table1 INNER JOIN table2 ON (table1.id = table2.id);

OUTER JOIN
~~~~~~~~~~~~~~~~~~~~~~~~
并集，没有匹配元素的记录也会被返回。
