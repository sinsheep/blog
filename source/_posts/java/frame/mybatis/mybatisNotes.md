---
title: mybatis Nots 
date: 2021-04-28 17:43
tags: [mybatis]
categories: [java,mybatis] 
---

## mybatis 的学习笔记



## mybatis配置

### environment

```xml
<environment id="myDev">
    <transactionManager type="JDBC"/>
    <dataSource type="POOLED">
        <property name="driver" value="com.mysql.jdbc.Driver"/>
        <property name="url" value="jdbc:mysql://localhost:3306/test"/>
        <property name="username" value="root"/>
        <property name="password" value="youpassword"/>
    </dataSource>
</environment>

```

#### transactionManager

transactionManager: mybatis 提交事务,回滚事务的方式
    type: 事务的处理的类型
    1) jdbc ： 表示把mybatis的底层是调用jdbc的connection的对象的，commit， rollback
    2）MANAGED： 表示把mybatis的事务处理委托给其他的容器(一个服务器软件，一个框架(spring))

dateSource: 表示数据源，java体系中，规定实现了javax.sql.DateSource接口的都是数据源，数据源表示connection对象的

type: 制定数据源的类型
    1）POOLED 使用连接池，mybatis会创PooledDataSource类
    2）UNPOOLED：不适用连接池，每次执行sql语句，先创建连接，执行sql，在关闭连接mybatis会创建一个UnPooledDataSource，管理Connection对象的使用
    3）JNDI： java命名和目录服务
