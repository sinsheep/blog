---
title: springboot 
date: 2021-05-11 21:49
tags: [springboot]
categories: [java,springboot] 
---

## springboot


springboot项目代码必须放到Application类所在的同级目录或下级目录

### spring 默认配置


properties 和 yml/yaml 只能存在一个，两个都存在以properties为准
#### properties写法

```properties
#设置内置端口号
server.port=8080

设置上下文根
server.servlet.context-path=/springboot
```


#### yml, yaml写法

```yml
server:
  port: 8081
  servlet:
    context-path/spring
```

#### 多环境下的springboot配置

命名为application-xxx.properties; 使用spring.profiles.active=xxx

#### 自定义参数配置


##### 获取单个参数@Value("")
配置中定义参数例如school.name=zisu

在java中使用java注解@Value获取文件

```java
    @Value("${school.name}")
    public String schoolName;

```

##### 获取一组参数

在application.properties中写

```properties
school.name=zisu
school.address=liuhelu299
```
在java文件中设置注解@Component交给spring容器管理
再加入@ConfigurationProperties(prefix = "school")
1. prefix是配置文件中参数前缀

```java
@Component
@ConfigurationProperties(prefix = "school")
public class School {

    private String name;
    private String address;

    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAddress(String address) {
        this.address = address;
    }
}
```
#### spring集成jsp

引入springboot内嵌Tomcatjsp解析依赖，不添加解析不了jsp
```xml
        <dependency>
            <groupId>org.apache.tomcat.embed</groupId>
            <artifactId>tomcat-embed-jasper</artifactId>
        </dependency>
```

springboot默认推荐使用前端引擎是thymeleaf  
现在我们要是用springboot集成jsp，手动指定jsp最后编译的路径  
而且springboot集成编译jsp的路径是springboot规定好的位置  
META-INF/resources

```xml
        <resources>
            <resource>
                <directory>src/main/webapp</directory>
                <targetPath>META-INF/resources</targetPath>
                <includes>
                    <include>*.*</include>
                </includes>
            </resource>
        </resources>

```

### springboot集成mybatis


#### 需要jar包

```java
            <plugin>
                <groupId>org.mybatis.generator</groupId>
                <artifactId>mybatis-generator-maven-plugin</artifactId>
                <version>1.3.6</version>
                <configuration>
                    <configurationFile>GeneratorMapper.xml</configurationFile>
                    <verbose>true</verbose>
                    <overwrite>true</overwrite>
                </configuration>
            </plugin>

```


#### GeneratorMapper.xml文件
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE generatorConfiguration
        PUBLIC "-//mybatis.org//DTD MyBatis Generator Configuration 1.0//EN"
        "http://mybatis.org/dtd/mybatis-generator-config_1_0.dtd">

<generatorConfiguration>

    <!-- 指定连接数据库的JDBC驱动包所在位置，指定到你本机的完整路径，需确保本地路径下存在该jar -->
    <classPathEntry location="/home/ysx/.m2/repository/mysql/mysql-connector-java/8.0.23/mysql-connector-java-8.0.23.jar"/>

    <!-- 配置table表信息内容体，targetRuntime指定采用MyBatis3的版本 -->
    <context id="tables" targetRuntime="MyBatis3">
        <!--序列化-->
        <plugin type="org.mybatis.generator.plugins.SerializablePlugin"/>

        <!--以下需要插件  -->

        <!--
            插入成功后返回ID
           <plugin type="cn.doity.common.generator.plugin.InsertAndReturnKeyPlugin"/>

           分页查询功能
           <plugin type="cn.doity.common.generator.plugin.SelectByPagePlugin"/>

           生成带有for update后缀的select语句插件
           <plugin type="cn.doity.common.generator.plugin.SelectForUpdatePlugin"/> -->


        <!-- 抑制生成注释，由于生成的注释都是英文的，可以不让它生成 -->
        <commentGenerator>
            <property name="suppressAllComments" value="true" />
        </commentGenerator>


        <!-- 配置数据库连接信息 -->
        <jdbcConnection driverClass="com.mysql.jdbc.Driver"
                        connectionURL="jdbc:mysql://localhost:3306/test"
                        userId="root"
                        password="tbswlcgjdwgrcy">
        </jdbcConnection>

        <!-- 生成model类，targetPackage指定model类的包名， targetProject指定生成的model放在eclipse的哪个工程下面-->
        <javaModelGenerator targetPackage="com.example.springbootfirst.model" targetProject="src/main/java">
            <property name="enableSubPackages" value="false" />
            <property name="trimStrings" value="false" />
        </javaModelGenerator>

        <!-- 生成MyBatis的Mapper.xml文件，targetPackage指定mapper.xml文件的包名， targetProject指定生成的mapper.xml放在eclipse的哪个工程下面 -->
        <sqlMapGenerator targetPackage="com.example.springbootfirst.mapper" targetProject="src/main/java">
            <property name="enableSubPackages" value="false" />
        </sqlMapGenerator>

        <!-- 生成MyBatis的Mapper接口类文件,targetPackage指定Mapper接口类的包名， targetProject指定生成的Mapper接口放在eclipse的哪个工程下面 -->
        <javaClientGenerator type="XMLMAPPER" targetPackage="com.example.springbootfirst.mapper" targetProject="src/main/java">
            <property name="enableSubPackages" value="false" />
        </javaClientGenerator>

        <!-- 数据库表名及对应的Java模型类名 -->
        <table tableName="student"
               domainObjectName="Student"
               enableCountByExample="false"
               enableUpdateByExample="false"
               enableDeleteByExample="false"
               enableSelectByExample="false"
               selectByExampleQueryId="false"/>
    </context>
</generatorConfiguration>

```

#### @Mapper

需要在每一个在mapper接口上加上, 作用扫描dao接口

#### @MapperScan(package="xxx")

在spring启动的类中加入, 扫描所有的包

#### 存放到Mapper映射文件存放位置的写法

1. mapper接口类和mapper xml 配置文件分开放, 需要在springboot核心配置中指定mapper映射文件存放的位置

2. mapper接口类和mapper xml 配置放在一起， 需要在pom.xml 设置编译xml文件类型文件

#### @Transactional

加入事务给springboot

#### @RestController 

相当如在控制层上加入@Controller + 方法上加入@ResponseBody
意味着所有的方法返回的都是json

#### mapping 注解

| 注解          | 效果    |
| ------------- | ------- |
| @GetMapping    | 效果等于@RequestMapping 不过只接受get请求 通常使用查询            |
| @PostMapping   | 效果果等于@RequestMapping 不过只接受post请求 通常使用于新增       |
| @DeleteMapping | 效果差不多等于@RequestMapping 不过只接受delete请求 通常使用于删除 |
| @PutMapping    | 效果差不多等于@RequestMapping 不过只接受put请求 通常使用于修改    |



### restful写法

#### 介绍

RESTFUL是一种网络应用程序的设计风格和开发方式，基于HTTP，可以使用XML格式定义或JSON格式定义。RESTFUL适用于移动互联网厂商作为业务接口的场景，实现第三方OTT调用移动网络资源的功能，动作类型为新增、变更、删除所调用资源。

#### 使用

写法:@RequestMapping(value = "/student/detail/{id}/{age}") 在参数前面加入注解@PathVariable

通常restful风格中方法的请求方式会按照增删改查的请求方式来区分

```java
    @GetMapping(value = "/student/detail/{id}/{age}")
    public Object student1(@PathVariable("id") Integer id,
                           @PathVariable("age") Integer age){
        Map<String,Object> resMap = new HashMap<>();
        resMap.put("id",id);
        resMap.put("age",age);
        return resMap;
    }
    @DeleteMapping(value = "/student/detail/{id}/{status}")
    public Object student2(@PathVariable("id") Integer id,
                           @PathVariable("status") Integer status){
        Map<String,Object> resMap = new HashMap<>();
        resMap.put("id",id);
        resMap.put("age",status);
        return resMap;
    }

```

### springboot集成redis

加入依赖
```xml
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-redis</artifactId>
        </dependency>

```

基础用法

```java
    @Autowired
    private RedisTemplate<Object,Object> redisTemplate;
    redisTemplate.opsForValue().get(key);
    redisTemplate.opsForValue().put(key,value);
```

### spring集成Dubbo

1. 接口工程：存放尸体bean和业务接口
2. 服务提供者： 业务接口的是吸纳类并将服务暴露切注册到注册中心，调用数据持久层
    - 添加依赖（dubbo，注册中心，接口工程）
    - 配置服务提供者核心配置文件
3. 服务消费者： 处理浏览器客户端发送的请求，从注册中心调用服务提供者所提供的服务
    - 添加依赖（dubbo，注册中心，接口工程）
    - 配置服务消费者核心配置文件

### springboot  java项目

springboot程序启动后返回值是ConfigurableApplicationContext 他也是一个spring容器
相当于spring容器中启动容器ClasspathXmlApplicationContext
ConfigurableApplicationContext applicationContext = SpringApplication.run(Application.class,args);
可以通过application.getbean 获取实现类


spring Application 启动类 实现CommandLineRunner类实现run方法

### springboot集成Interceptor 拦截器


创建一个HandlerInterceptor的实现类重写preHandler, postHandler, afterCompletion方法, 并且创建一个WebMvcConfiger实现类 重写addInterceptors方法
```java
package com.example.springbootfirst.config;

import com.example.springbootfirst.inteceptor.UserInterceptor;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

@Configuration      //声明为配置文件类
public class InterceptorConfig implements WebMvcConfigurer {

    @Override
    public void addInterceptors(InterceptorRegistry registry) {
        String[] addPathPatterns = {
                "/user/**"
        };
        String[] excludePathPatterns = {
                "/user/out",
                "/user/login",
                "/user/error"
        };
        registry.addInterceptor(new UserInterceptor()).addPathPatterns(addPathPatterns).excludePathPatterns(excludePathPatterns);
    }
}
```

### springboot集成Servlet

#### 方法一
1. 创建个HttpServlet实现类  
2. 在类上加入注释@WebServlet(urlPatterns="/xxx")    
3. urlPatterns 是网站uri地址  
4. 然后在springboot项目启动类中加入注解, @ServletComponentScan(basePackages = "your package name")

#### 方法二

1. 创建个HttpServlet实现类  
2. 创建个Config类,在类上加入注解@Configuration
3. 创建个返回值为 ServletRegistrationBean 方法
4. 在方法前加入@Bean注释， @Bean是一个方法级别的注释，主要用在配置类中 ，相当于一个bean标签
```java
@Configuration
public class ServletConfig {
    @Bean
    public ServletRegistrationBean myServletRegistrationBean(){
        ServletRegistrationBean servletRegistrationBean = new ServletRegistrationBean(new Myservlet(),"/myservlet2");
        return servletRegistrationBean;
    }
}
```



### springboot集成Filter

#### 方法一

1. 创建Filter实现类
2. 在类上加入标签@Filter(urlPatterns="/xxx")
3. 重写doFilter方法
4. 在springboot项目启动类中加入注解 @ServletComponentScan(basePackages ="your package name")

#### 方法二

1. 创建个Filter实现类
2. 创建个Config类, 在类上加入注解@Configuration
3. 创建个返回值为FilterRegisrationBean 方法
4. 在方法前加入@Bean注解

### springboot设置字符编码

在springboot核心配置文件中设置
```properties
server.servlet.encoding.charset=utf-8
server.servlet.encoding.enabled=true
server.servlet.encoding.force=true
```


###spring打包文件

#### 打包war包

需要spring启动类继承SpringBootServletInitializer, 重写 configure方法
通过builer对象的sources重新构建新资源
```java
protected SpringApplicationBuilder configure(SpringApplicationBuilder builder){
    returnb builder.sources(Application.class);
}
```
springboot打war包本地springboot Application.properties设置的上下文根和端口号就失效了以本地tomcat为准

#### 打包jar包

springboot打包jar包端口号，上下文根以springboot核心配置文件为准

### thymeleaf

首先加入依赖

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-thymeleaf</artifactId>
</dependency>
```
需要在html加入解析器
```html
<html lang="en" xmlns:th="http://www.thymeleaf.org">
```

使用thymeleaf需要在html表达式中使用

```html
<div th:text="${user.id}"></div>
<div th:text="${user.userName}"></div>


<!--使用*{} 必须使用th:object 属性来绑定这个对象用*代替绑定的那个对象 -->
<div th:object="${user}">
    user ID: <span th:text="*{id}"></span>
    user username: <span th:text="*{id}"></span>
</div>

```

**@{}超链接使用** 

需要传递参数多个参数使用括号参数间用逗号隔开
或者使用字符串拼接
```html
<a th:href="@{/test(name=${user.id},age=${user.userName})}">click</a>
<a th:href="@{'/test?name='+${user.id}}">click</a>

```

restful写法
<a th:href="@{/test/${id}}">click</a>


#### th:each

遍历list和array
```html
<div th:each="user,userStat:${userList}">
    <span th:text="${userStat.count}"></span>
    <span th:text="${user.id}"/>
    <span th:text="${user.userName}"/>
</div>
```
1. user 当前循环对象的变量名称  
2. userStat 当前循环对象状态的变量(可选默认就是对象变量名称+Stat)
3. ${userList} 当前循环的集合

遍历map  
```html
<div th:each="user,userStat:${map}">
    <span th:text="${userStat.count}"></span>
    <span th:text="${user.key}"/>
    <span th:text="${user.value}"/>
    <span th:text="${user.value.userName}"/>
    <span th:text="${user.value.id}"/>
</div>
```
遍历复杂集合  
```html
<h2>循环遍历复杂集合list->map->list->user</h2>
<div th:each="myListMap:${myList}" >
    <div th:each="myListMapObj:${myListMap}">
        <div th:each="myListMapObjList:${myListMapObj.value}">
            <span th:text="${myListMapObjList.id}"/>
            <span th:text="${myListMapObjList.userName}"/>
        </div>
    </div>
</div>

```

#### 判断语句

```html
<!DOCTYPE html>
<html lang="en" xmlns:th="http://www.thymeleaf.org">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>

<div th:if="${sex eq 1}">
    男
</div>
<div th:if="${sex eq 0}">
    女
</div>

<h2>与if相似就是取反</h2>
<div th:unless="${sex eq 0}">
    男
</div>

<h2>th:switch/case 用法</h2>

<div th:switch="${product}">
    <span th:case="0">产品0</span>
    <span th:case="1">产品0</span>
    <span th:case="*">无此产品</span>
</div>
</body>
</html>
```

#### th:inline

```html
<!DOCTYPE html>
<html lang="en" xmlns:th="http://www.thymeleaf.org">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<h1>内敛文本： th:inline="text"</h1>

<div th:inline="text">
    data: [[${data}]]
</div>

<h1>内敛脚本 th:inline="javascript"</h1>
<script type="text/javascript" th:inline="javascript">
    function showData(){
        alert([[$(data)]]);
    }
</script>
</body>
</html>
```
