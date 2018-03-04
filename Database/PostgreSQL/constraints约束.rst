constraints约束
=====================================
NOT NULL
-----------------------------
限制某一个字段不能为NULL::

    CREATE TABLE student (
    id INT NOT NULL,
    name TEXT
    );

UNIQUE
-----------------------------
限制字段不能出现重复值::

    CREATE TABLE Student
    (
    ID int(6) NOT NULL UNIQUE,
    NAME varchar(10),
    ADDRESS varchar(20)
    );

PRIMARY KEY
-----------------------------
可以唯一地标识一行的字段。如果一个字段是主键，那么它不能为NULL，也不能重复::

    CREATE TABLE Student
    (
    ID int(6) NOT NULL UNIQUE,
    NAME varchar(10),
    ADDRESS varchar(20),
    PRIMARY KEY(ID)
    );

FOREIGN KEY
-----------------------------
外键是这样一个字段，它唯一地对应另一个表中的一行::

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

CHECK
-----------------------------
限制字段应该满足的条件，例如::

    CREATE TABLE Student
    (
    ID int(6) NOT NULL,
    NAME varchar(10) NOT NULL,
    AGE int NOT NULL CHECK (AGE >= 18)
    );
    ALTER TABLE salary ADD CHECK(salary <= 6000);

有了这个约束，salary大于6000的记录将无法插入到salary表中。

DEFAULT
-----------------------------
为字段提供默认值::

    CREATE TABLE Student
    (
    ID int(6) NOT NULL,
    NAME varchar(10) NOT NULL,
    AGE int DEFAULT 18
    );


给现有的表添加约束
=====================================
语法::

    ALTER TABLE table_name ADD CONSTRAINT constraint_name PRIMARY KEY(depname);

也可以让数据库自动指定约束的名字::

    ALTER TABLE salary ADD FOREIGN KEY(depname) REFERENCES deps(depname);
