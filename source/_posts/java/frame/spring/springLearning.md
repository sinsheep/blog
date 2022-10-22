---
title: spring learning 
date: 2021-05-02 22:48
tags: [spring]
categories: [java,spring] 
---

# spring learning

## spring core

Ioc(Inversion of control): 控制反转，是一个理论，概念，思想。
描述的：把对象的创建，赋值，管理工作都交给代码之外的容器的实现，也是对象的创建是由其他的外部资源完成

1. 控制：创建对象，对象的属性赋值，对象之间的关系管理
2. 反转：把原来的开发人员挂白努力，创建对象的权限转移给代码之外的容器实现。由容器代替开发人员的管理对象。创建对象，给属性赋值
3. 正转：由开发人员在代码中，使用new构造方法创建对象，开发人员主动管理对象

容器：是一个服务器软件，一个框架(spring)

为什么要是用ioc：目的就是减少代码的改动，也能实现不同的功能，实现解耦合

## java中创建对象有那些方式
    1. 构造方法
    2. 反射
    3. 序列化
    4. 克隆
    5. ioc：容器创建对象
    6. 动态代理

## ioc 的体现
    servlet 
            1. 创建类继承HttpSevlet
            2. 在web.xml 注册servlet，使用
            </serlet-name>myservlet</servlet-name>
            <servlet-class>com.sample.controleer.Myservlet</servlet>
            3. 没有创建servlet对象
            4. servlet 是tomcat服务器创建的。tomcat也称为容器 Tomcat作为容器：里面存放的由servlet对象，Listener，Filter对象

### ioc的技术实现

DI是ioc的技术实现
DI(dependency injection) : 依赖注入，只需要在程序中提供要使用的对象的名称就好了，对象如何在容器中创建，查找都由容器内部实现
spring使用di实现ioc的功能 spring底层创建对象 使用的是反射

### di注入

1.di的实现由两种
    1.在spring的配置文件中，使用标签和属性完成，叫做给予xml的di是实现
    2.使用spring中的注解，完成属性赋值，叫做基于注解的id实现

di的语法分类
    1.set注入(设置注入) spring 调用类真的set方法, 在set方法可以实现属性的赋值
    2.spring 调用类的构造方法，创建对象，在构造方法中完成赋值


## spring注解

@Service @Service @Controller 功能基本一致，但是还有额外功能

### 扫描器

使用扫描器时候要写对包名,要不然找不到包
```java
<context:component-scan base-package=""/> //找到包和子包中所有的注解，找到注解中的所有类，按照注解功能创建对象或给属性赋值
```
不同的指定包的方式
1.多次组件扫描
```java
<context:component-scan base-package="com.sample.yourpackage1"/>
<context:component-scan base-package="com.sample.yourpackage2"/>
```
2.使用分隔符号
```java
<context:component-scan base-package="com.sample.yourpackage1;com.sample.yourpackage2"/>
```
3.指定父包
```java
<context:component-scan base-package="com.sample"/>//不建议使用太潜层目录如使用com
```

默认调用无参数构造方法，如果不适用名称@Component 默认名称为首字母小写的类名

###  @Component 
创建对象的等同与<bean> 属性
value 等同于bean的id值 value值是唯一的
位置在类的上方
```java
@Component(value="student")
```

### @Repository

使用在持久层上面的：放在dao的实现类伤 表示船舰dao对象，dao对是能访问数据库的, 用法和@Component类似

### @Service

用在业务层的：放在service的实现类伤，创建service对象，service对象是做业务处理，可以又事务等功能,用法和@Component类似

### @Controller
用在控制器伤：创建控制器对象，控制器对象，能够接受用户提交的参数，显示请求的处理结果。用法和@Component类似


### @Value
属性：value是String 类型的 表示简单类型的属性值  
位置：放在属性或者set方法上
```java
@Value("123")
private String name;
```
### @AutoWired
对应用类型的注入 默认使用bean中byType规则使用  
属性：required， 是一个boolean类型的， 默认为true，  
    required=true表示应用类型赋值失败程序报错，并终止执行  
    required=false表示应用类型赋值失败程序正常执行，应用类型为null  
位置：放在属性或者set方法上  
使用ByName方式
1.在属性伤加入@Qualifier(value="bean的id")表示使用指定的bean id 完成赋值

### Resource

来自jdk中的注解，spring框架提供了对这个注解的支持，可以使用他给引用类型赋值  
    使用的也是自动注入原理，可以使用byName 和byType 默认byName,如果byName失败在使用ByType  
    只使用ByName方法是家一个属性name @Resource(name="myid")  
位置：放在属性或者set方法上  

## aop
1. 动态代理
    实现方法：jdk动态代理，使用jdk中的Porxy，Method，InvocationHander创建代理对象
    jdk动态代理要求目标必须是实现接口
    Cglib动态代理：第三方的工具库，创建代理对象，原理是继承，通过继承目标类，创建子类，子类就是代理对象。要求目标类不能是final的，方法也不能是final的

2. 动态代理的作用
    1. 在目标类代码不改变的情况下，增加功能  2. 减少代码的重负  3. 专注鱼业务逻辑代码  
    4. 解耦和，让你的代码功能和日志，事务非业务功能分离  
3. Aop：面向切面编程，基于动态代理的，可以使用jdk，cglib两种代理方式。Aop就是动态代理的规范化，把动态代理的实现步骤，方法都定义好了，让开发人员意欧能够一种统一的方式，使用动态代理

4. AOP(Aspect Orient Programming) 面向切面编程
    Aspect: 切面，给你的目标类增加的功,像日志，事务都是切面。
    切面特点：一般都是非业务方法，独立使用

5. 一个切面的三个关键的要素
    1. 切面的功能代码，切面干什么。
    2. 切面的执行位置，使用pointcut表示切面执行的位置
    3. 切面的执行时间， 使用advice表示时间，在目标方法之前，还是在目标方法之后

### 什么时候考虑用aop

1. 当你要给系统中的一个类修改功能，到那时原有的类功能不完善
2. 当你要给项目中多个类增加一个相同的功能时候使用aop
3. 给业务方法增加事务，日志输出

### aop的实现

aop是一个规范，是动态的一个规范化，一个标准
aop的技术是西安框架：
1. spring：spring在内部是实现了aop规范，能做aop的工作。  
    spring 主要是在事务处理时使用aop  
    项目中很少使用spring的aop实现，因为太笨重了  
2. aspectJ: 一个开源专门做aop的框架，spring框架中继承了aspectj框架，通过spring就能使用aspectj的功能，aspectJ框架实现aop的两种两种方式
    1. 使用xml的配置文件
    2. 使用注解，我们吸纳公募中要坐aop功能，一般都是使用注解，aspectJ有五个注解



## 学习aspectj框架的使用

### aspectJ 介绍

切面的执行时间，这个执行的时间在规范中叫做advice（通知，增强）在aspectj框架中使用注解表示的。也可以使用xml配置文件中的标签

1. @Before
2. @AfterReturning
3. @Around
4. AfterThrowing
5. After

AspectJ 定义了撞门的表达式用鱼指定切入点。表达式的原型是:

```xml
execution(modifier-pattern? ret-type-pattern
          declaring-type-pattern?name-pattern(parm-pattern)
          throws-pattern?)
```

解释：
modifiers-pattern 访问权限类型  
ret-type-pattern 返回值类型  
declaring-type-pattern 包名类名  
throws-pattern 抛出异常类型
? 表示可选部分

| 符号          | 意义                                                                   |
| ------------- | -------------                                                          |
| *             | 零到多个符号                                                           |
| ..            | 用在方法参数中，表示任意多个参数么，用在包名中表示当前包及其子包路径 |
| +             | 用在类名后，表示当前类及其子类, 用在接口后表示当前接口和他的实现类     |

execution(访问修饰符 返回值 包名.类名.方法名(方法参数) 异常)

### aspectJ使用

1. 创建目标类：接口和它的实现类，要做的是给类中的方法增加功能
2. 创建切面类：普通类
    1. 在类的上面加入 @Aspect
    2. 在类中定义方法，方法就是切面要执行的功能代码，在方法的上面加入aspectj的通知注解，例如@Before         有需要指定的切入点表达式execution()
3. 创建spring的配置文件：声明对象，把对象交给容器统一管理  
    声明对象你可以使用注解或者xml配置文件bean
    1. 声明对象
    2. 声明切面类对象
    3. 声明aspectj框架中的自动代理生成器表亲啊。  
        自动代理生成器: 用来完成代理对象的自动创建功能
配置文件写法

如果期望目标类有接口，使用cglib代理就设置proxy-target-class=true
```java
<aop:aspctj-autoproxy proxy-target-class="true"/> //aspectj-autoproxy 会把spring容器所有目标对象，一次性生成代理对象
```


#### **@Before**   
前置通知注解
    属性：value， 是切入点表达式，表示切面的功能执行的位置
    位置： 在方法上   
    无参数的

#### **@JoinPoint**  
业务方法，要加入切面功能的业务方法  
作用是：可以在通知方法汇总获取费纳广发执行时候的信息，方法的实际参数  
如果切面功能中需要得到方法的信息 就加入JoinPoint  
JoinPoint 要加就放在第一个参数,  也可不加
```java
   @Before(value="execution(void *..service.impl.SomeServiceImpl.*(..))")
   public void myBefore(JoinPoint jp){
      System.out.println(jp.getSignature());//获取方法的定义
      System.out.println(jp.getSignature().getName());//获取方法的名字
      Object args[] = jp.getArgs();//获取方法的参数列表
      for (Object arg : args) {
         System.out.println(arg);
      }
      System.out.println("before advice time:"+new Date());
   }

```

#### **@AfterReturning**   
后置通知方法的定义，方法是是实现切片功能的。  
切面方法的定义要求：  
1. 公共的方法
2. 方法没有返回值
3. 方法名称自定义
4. 方法有参数的推荐是object，参数名自定义

属性：
1. value 切入点表达式
2. returning 自定义的变量,表示目标方法的返回值  
自定义变量名必须和通知方法的行参名一样

特点
1. 在目标方法后执行
2. 能够获得目标方法的返回值，可以更具这个返回值做不同的处理功能
3. 如果是引用类型的话在内改变值, 会改变方法返回值

```java
   @AfterReturning(value = "execution(* *..SomeServiceImpl.doOther(..))",returning = "res")
   public void myAfterReturning(Object res){
      //Object res = doOther(..); myAfterReturning(res);
      System.out.println(res);
      if("lisi20".equals(res)){
         //do Something
      }else{
         //do Something
      }
   }

```
#### **@Around** 
环绕通知的定义格式
1. public
2. 必须有一个返回值，推荐使用object
3. 名称自定义
4. 方法有固定参数 ProceedingJoinPoint

结构：
    属性：value 切入表达式
    位置：在方法的定义上面
特点:
    1. 功能最强的通知
    2. 在目标方法的前和后都能增强功能
    3. 控制目标方法是否被调用执行
    4. 修改原来的目标方法的执行结果，影响最后的调用结果。

环绕通知等同于jdk动态代理的InvocationHandler接口
参数：
    proceedingJoinpoint 等同于Method
    作用执行目标方法
返回值：
    就是目标方法的执行结果，可以被修改

```java
   @Around(value="execution(* *..SomeServiceImpl.doOther(..))")
   public Object myAround(ProceedingJoinPoint pjp) throws Throwable {
      //ProceedingJoinPoint extend joinPoint
      Object result = null;
      Object args[] = pjp.getArgs();

      String name = "";
      if(args!=null && args.length > 1){
         Object arg = args[0];
         name = (String) arg;
      }
      System.out.println("around advise start time: " + new Date());
      if("zhangsan".equals(name)){
         result = pjp.proceed();//method.invoke(); Object result = youFunc();
      }
      System.out.println("around advise end  ");
      result = "123";//可以修改返回值
      return result;
   }

```

#### **@AfterThrowing** 

异常通知格式
    1. public
    2. 没有返回值
    3. 方法名称自定义
    4. 方法有一个Exception ，如果还有就是joinPoint

属性：
    1. value 切入点表达式
    2. throwing 自定义变量，表示目标方法抛出的异常对象
        变量名必须和方法的参数名一样

特点: 
    1. 在目标费纳广发爆出异常的时执行的
    2. 可以做异常监控程序，监控目标方法执行时是不是有异常。
        如果有异常，发送短信或者邮件通知

执行类似：
```java
try{
    doSecond(..);
}catch(Exception e){
    myAfterThrowing(e);
}
```


**样例代码** 
```java
   @AfterThrowing(value = "execution(* *..SomeServiceImpl.doSecond(..))",throwing = "ex")
   public void myAfterThrowing(Exception ex){
      System.out.println("异常通知：方法发生异常执行"+ex.getMessage());
   }

```


#### **@After** 

最终通知的格式
    1. public
    2. 没有返回值
    3. 方法名称自定义
    4. 方法有一个Exception ，如果还有就是joinPoint

属性: 
    1. value 切入点表达式
特点
    1. 总是会执行 就算抛出异常还是执行
    2. 在目标方法之后
    3. 一般做资源清楚的

类似于：
    ```java
    try{
        doSomething(..);
    }catch(Exception e){
        
    }finally{
        myAfter();
    }
    ```



**样例代码** 
```java
   @After(value = "execution(void *..SomeServiceImpl.doSecond(..))")
   public void myAfter(){
      System.out.println("执行最后的方法");
   }

```


#### **@PoinCut** 

定义和管理切入点表达式的，如果项目中有多个切入点表达式相同，可以复用，可以使用@PointCut

属性：
    value： 切入点表达式

特点：
当使用@PointCut定义在一个方法上面，此时这个方法的名称就是切入点表达式的别名。
其他通知中，value属性就是可以使用这个方法名称，代替切入点表达式

```java
   @Pointcut(value = "execution(* *..SomeServiceImpl.doSecond(..))")
    private void mypt(){
      //no code
   }

    @After(value = "mypt()")
```

### 事务

#### 什么是事务
    
讲mysql的时候提出了事务，事务是指一组sql语句的集合，集合中有多条sql语句，可能有insert，update，selelct，delete。 我们希望浙西多个sql语句都能成功，或者都失败，这些sql语句的执行是一致的，作为一个整体执行

#### 在什么时候想到使用事务

在我们操作涉及得到多个表，或者是多个sql语句的insert，update，delete. 需要保证这些语句都是成功才能完成我们的功能或者都失败，保证操作是符合要求的。  

在java代码中写程序，控制事务，此时事务应该放在哪里呢？
service类的业务方法是那个，因为业务方法会调用多个dao方法，执行多个sql语句

#### 使用什么工具访问数据库

jdbc 访问数据库，处理事务 Connection conn; conn.commit(); con.rollback();  
mybatis 访问数据库，处理事务 SqlSession.commit(); SqlSession.rollback();  
hibernate 访问数据库，处理事务 Session.commit(); Sesison.rollback();

#### 上面中事务的处理方法有什么不足

1. 不同的数据库访问技术，处理事务的对象，方法不同。需要了解不同的数据库访问技术使用事务的原理
2. 掌握多种数据库中事务的处理罗技。什么时候提交事务，什么时候回滚事务
3. 处理事务的多种方法

#### 怎么解决不足呢

spring 提供一种处理事务的统一模型， 能使用统一步骤，方式完成多种不同数据库访问技术的事务处理

使用 spirng事务处理机制 可以完成mybatis/hibernate访问数据库的事务处理

#### 处理事务，需要怎么做，做什么

Spring 处理事务的模型，使用步骤都是固定的，把事务使用的信息提供给spring就可以了

1. 事务的内部提交，回滚事务，使用的事务管理七对象，代替你完成commit, rollback。事务管理器是一个接口和他的众多实现类：
    接口： PlatformTransactionManager, 定义了事务的重要的commmit，rollback
    实现类：spring把每一种数据库反问技术对应的事务处理类都创建好了  
        mybatis 访问数据库--spring创建好的是DataSourceTransactionManager
        hibernate 访问数据库 -- spring 创建好的是HibernateTransactionManager
2. 怎么使用
    你需要告诉spring 你用的那种数据库访问技术，声明数据库访问技术对于事务管理器的实现类，在spirng的配置文件中使用<bean> 声明就好了例如使用mybatis访问数据库在xml配置中
    ```xml
    <bean id="xxx" class="..DataSourceTransactionManager">
    ```

##### 说明方法需要的事务

事务的额隔离级别 四个值
    default： 采用db默认的事务处理级别，mysql默认伟REPEATABLE_READ oracle默认READ——COMMITTED
    1. READ_UNCOMMITTED: 读取未提交，未解决任何并发问题。
    2. READ_COMMITEED： 读取以提交, 存在不可重复读和幻读。
    3. REPEATABLE_READ： 可重复读，解决脏读，不可创富读存在幻读。
    4. SERIALIZABLE：串行化。不存在并发问题。

事务的超时时间: 如果一个事务运行超过一段时间就回滚

事务的传播行为： 控制业务方法是不是有事务，是什么样的事务的，7个传播行为，表示你的业务方法调用时候，事务在方法之间是如何使用的。

前三个要知道

    1. PROPAGATION_REQUIRED
    2. PROPAGATION_REQUIRES_NEW
    3. PROPAGATION_SUPPORTS
    4. PROPAGATION_MANDATORY
    5. PROPAGATION_NESTED
    6. PROPAGATION_NEVER
    7. PROPAGATION_NOT_SUPPORTED 

##### 提交事务，回滚事务的时机
    
    1. 当你的业务方法执行成功没有抛出异常，结束时会提交事务
    2. 当你的业务方法运行时候异常 spring就会回滚
    3. 当你的业务方法爆出非运行时异常 主要是受查异常时，提交事务
    抽查异常就是你写的代码中必须处理的和异常。例如：IOException， SQLException

##### spring 框架中提供的事务处理方案
1. 适合中小项目实用的，注解方案。
    spring 框架自己用aop给业务方法增加事务的功能，使用@Transactional注解增加事务。  
    @Transactional注解是spring框架自己的注解，放在public方法上，实现事务的管理机制 
    可以给注解的属性赋值，表示具体的隔离级别，传播行为，异常信息等等。  

使用@transactional的步骤
    1. 事务管理器
    ```xml
    <bean id="xxx" class="DataSourceTransactionManager">
    ```
    2. 开启事务注解驱动，告诉spring框架，我们使用注解的方式管理事务

    spring 开启aop机制， 创建@Transactional 所在的类代理对象，给方法加入事务的功能
        在你的业务方法执行之前，先开启事务，在业务方法之后提交或回滚事务，使用aop的环绕通知

2. 在大型项目中, 有很多的类，方法，需要大量的配置事务，使用aspectj框架功能，在spring配置文件中声明类，方法需要的事务，这种业务方法和事务配置完全分离
    实现步骤：都是在xml配置文件中完成的
    1. 要使用aspectJ库那个家 mavan中加入依赖
        ```xml
        <dependency> 
            <groupId>org.springframework</groupId>
            <artifactId>spring-aspects</artifactId>
            <version>5.2.5.RELEASE</version>
        </dependency>
        ```

    2. 声明事务管理器对象
        <bean id="xx" class="DataSourceTransactionManager">

    3. 声明方法需要的事务类型（配置方法的事务属性（隔离级别，传播行为，超时）
    4. 配置aop： 指定那些类要创建代理
