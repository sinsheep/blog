---
title: springMvc 
date: 2021-05-06
tags: [springMvc]
categories: [java,springMvc] 
---

# springMvc

## 简介

sprinMvc 是基于spring的一个框架，实际上就是spring的一个模块，专门做web开发的，理解就是一个servlet升级

web 开发底层是servlet ， 框架是在servlet基础上加入一些功能，让你做web开发方便

springMvc就是一个spring spring是容器，ioc能够管理对象使用<bean> @Component,@Respository @Service @Controller springMvc 能够创建对象，加入到容器中(spirngMvc容器)

我们使用@Contorller 创建控制器对象，把对象放入到springmvc容器中，把创建对象做伟控制器使用哦哦能够，这广告控制器对象能够接受用户的请求, 类似一个servlet

[![g3082j.jpg](https://z3.ax1x.com/2021/05/07/g3082j.jpg)](https://imgtu.com/i/g3082j)
## quick start

1. 新建mavan工程
2. 加入spring-webmvc依赖，等于把spring，jsp，servlet依赖加入

3. 重点： 在web.xml中注册springmvc中的核心对象DispatcherServlet
    1. DisPatcherServlet 叫做中央调度器，是一个servlet 它的父类是继承httpservlet
    2. DisPatcherServlet 也叫做前端控制器（front controller）
    3. DisPatcherServlet 负责接受用户的提交的请求，跳用其他的控制器对象，并把结果显示给用户

4. 创建index.jsp

5. 创建控制类
    1. 在类上加入@Controller 创建对象，放入springmvc中
    2. 在类的方法上加入@RequestMapping 注解

6. 创建一个作为结果的jsp
7. 创建springmvc的配置文件（spring的配置文件一样）
    1. 声明组件扫描器，指定@Controller注解所在的包
    2. 声明视图解析器，帮助解析视图

注册springmvc核心对象DispatcherServlet 

```xml
    <servlet>
        <servlet-name>springmvc</servlet-name>
        <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>
    </servlet>
```

为什么要创建DispatcherServlet对象呢？ 因为创建此对象的过程中，会同时创建springmvc的容器对象，读取springmvc的配置文件，把这个配置文件中的对象创建号，当用户发起请求时候就可以直接使用对象了

servlet初始化的时候会执行init()方法，DispatcherServlet 中的init(){  
WebApplicationContext ctx = new ClassPathXmlApplicationContext("springmvc.xml")  

getservletContext().setAtribute(key, ctx)  

}  

在启动tomcat时候，创建 DDisPatcherServlet 会会读取你的/WEB-INF/<servlet-name>-servlet.xml 位置的springmvc配置

@RequestMapping: 请求映射，作用是吧一个请求地址和一个方法绑定在一起，一个请求指定一个方法处理
    属性：
        1. value 是一个请求的uri地址 value值必须是唯一的，使用时候推荐地址以"/" 是一个数组可以放很多uri
        2. method 表示请求的方式。他的值是RequestMethod类的枚举值，例如表示get的请求方式  
        RequestMethod.GET, post方式 RequestMethod.POST
    位置：
        3. produces: 指定一个contentType
        1. 方法上面(常用)
        2. 类上面(可为公共的名称)
    说明：
        使用RequestMapping 修饰的方法叫做处理器方法或者控制器方法
        使用RequestMapping 修饰的方法可以处理请求，类似一个servlet中的doget，dopost
返回值ModelAndView 表示本次请求的处理结果
    model： 数据i，请求处理完成后，要显示给用户的数据
    view： 视图，比如jsp等等
```java
@Controller
public class MyController {

    @RequestMapping(value="/some.do")
    public ModelAndView doSome(){

        ModelAndView mv = new ModelAndView();
        //类似request.setAttribute("name","欢迎使用springmvc开发")
        mv.addObject("name","欢迎使用springweb开发");
        mv.addObject("age","执行的是dosome");

        //框架对视图进行forward操作，request。getRequestDispather("/show.jsp").forward(..)
        mv.setViewName("/show.jsp");
        return mv;
    }
}

```

springmvc.xml配置  
```xml
    <context:component-scan base-package="com.sample.controller"/>
```

web.xml 配置  
```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">


    <servlet>
        <servlet-name>springmvc</servlet-name>
        <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>

        <init-param>
            <param-name>contextConfigLocation</param-name>
            <param-value>classpath:springmvc.xml</param-value>
        </init-param>
        <load-on-startup>1</load-on-startup>
    </servlet>
    <servlet-mapping>
        <servlet-name>springmvc</servlet-name>
        <url-pattern>*.do</url-pattern>
    </servlet-mapping>
</web-app>
```

### spring 请求的处理流程

1. 发起 some.do请求
2. tomcat(web.xml url-pattern 知道*.do的方法是要调用 DisPatcherServlet)
3. DisPatcherServlet 把some.do转发给myController中的 doSome方法
4. 框架执行dosome方法后得到ModelAndView然后进行处理，转发到show.jsp

some.do->DisPatcherServlet->MyController->doSome()


####  请求的处理过程

执行servlet的service()
    protectd void service(HttpServletRequest request, HttpServletResponse response)

    doDispatch(requset, response){
        调用MyController中的doSome() 方法
    }

### 视图解析器

```xml
    <bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">
        <property name="prefix" value="/WEB-INF/view/"/>
        <property name="suffix" value=".jsp"/>
    </bean>

java 中
//        mv.setViewName("/WEB-INF/view/show.jsp");
//        mv.setViewName("show");
```

### 接受参数

####  逐个接受请求参数

要求： 处理器方法的形参名要和请求体中的参数名一致,同名的请求参数赋值给同名的行参

框架接受请求参数
1. 使用request对象接受请求对象，
    String strName = request.getParameter("name");
    String strAge = request.getParameter("age");
2. springmvc 框架通过DispatcherServlet 调用MyController中的receiveProperty()方法时候
    按照名称对应，把接受的参数赋值给行参。
    receiveProperty(strName,Integer.valueOf(strAge))
    框架会根据提供的类型进行转换，把string转换为int long float 等类型
```java
    @RequestMapping(value = "/receiveproperty.do")
    public ModelAndView receiveProperty(String name,Integer age){

        ModelAndView mv = new ModelAndView();

        mv.addObject("name",name);
        mv.addObject("age",age);
        mv.setViewName("show");
        return mv;
    }
```

filter进行编码统一
```xml
    <filter>
        <filter-name>characterEncodingFilter</filter-name>
        <filter-class>org.springframework.web.filter.CharacterEncodingFilter</filter-class>
        <init-param>
            <param-name>encoding</param-name> 编码名称
            <param-value>utf-8</param-value>
        </init-param>
        <init-param>
            <param-name>forceRequestEncoding</param-name>
            <param-value>true</param-value>
        </init-param>
        <init-param>
            <param-name>forceResponseEncoding</param-name>
            <param-value>true</param-value>
        </init-param>
    </filter>
```
#### 参数名和行参名不同时候

@RequestParam 解决请求体参数与行参不同时候
    属性：
        1. value 请求体中的参数名称
        2. required 是一个boolean 默认true 
        true 表示请求中必须包含本参数
    位置: 在处理器方法的行参定义的前面

```java
    public ModelAndView receiveParam(@RequestParam(value = "name") String yname,@RequestParam(value = "age") Integer yage)
```
#### 使用对象接受参数

创建一个保存请求参数值的一个普通的类   
属性名要和请求中的参数名一样    

 处理器对象方法行参是java对象，这个对象的属性名和请求的参数名是一样的  
 框架会对象的无参数构造方法创建行参的java对象，给属性赋值，请求中的参数是name 框架会给name调用SetName()

```java
    @RequestMapping(value = "/receiveproperty.do")
    public ModelAndView receiveProperty(String name,Integer age){

        ModelAndView mv = new ModelAndView();

        mv.addObject("name",name);
        mv.addObject("age",age);
        mv.setViewName("show");
        return mv;
    }
```

### 返回值

1. ModelAndView(需要数据和视图)
2. String(需要视图，可以是逻辑名称，也可以是完整路径)
3. void 

#### string 

返回一个视图名称， 可以手工添加参数到Reuqest 作用域中 如果要使用完整的视图路径， 项目中不能配置视图解析器
```java
    @RequestMapping(value = "/returnstr.do")
    public String returnStr(HttpServletRequest request,String name, Integer age){
        //框架对视图进行转发操作
        request.setAttribute("name","name");
        request.setAttribute("age","age");
        return "show";
    }

```

#### void

不能表示数据, 也不能表示视图 处理ajax 的时候可以使用void 通过HttpsevletResponse输出数据。
ajax请求服务器返回的就是数据和视图无关

```java
    @RequestMapping(value = "ajax.do")
    public void ajaxTester(HttpServletResponse response,String name, Integer age) throws IOException {
       //处理ajax
        Student student = new Student();
        student.setAge(age);
        student.setName(name);
        String json = "{}";
        if(student!=null){
            ObjectMapper om = new ObjectMapper();
            json = om.writeValueAsString(student);
        }
        PrintWriter pw = response.getWriter();
        pw.println(json);
        pw.flush();
        pw.close();
    }

```

#### Object 

处理器返回object对象，这个对象可以是Integer，string， 自定义的对象等等。但有返回对象不是作为逻辑视图出现的，而是作为直接在页面显示的数据出现的，可以使用对象表示数据，相应ajax请求
返回的对象，需要使用@ResponseBody 注解

##### 实现步骤
1. 加入处理json的工具库的依赖，springmvc默认使用的jackson
2. 在springmvc配置文件中加入<mvc:annotaion-driven> 注解驱动(json = om.writeValueAsString(student);)
3. 在处理器方法的上面加入@RespnseBody注解  
    PrintWriter pw = response.getWriter();
    pw.println(json);

springmvc处理器返回object， 可以转为json输出到浏览器，响应ajax的内部原理
1. <mvc:annotation-driven> 注解驱动  
    注解驱动实现的功能是 完成java对象到json，xml，text，二进制等数据格式的转换
    <mvc:annotation-driven> 加入springmvc配置文件后，会自动创建HttpMessageConverter接口的7个实现类对象 包括 MappingJackson2HttpMessageConverter(使用jackson工具中实现java对象装换为json)

| HttpMessageConverter接口实现类 | 作用                                               |
| -------------                  | -------                                            |
| ByteArrayHttpMessageConverter  | 负责读取二进制格式的数据和写出二进制文件格式的数据 |
| StringHttpMessageConvert       | 负责读取字符串格式的数据和写出二进制格式的数据|
|ResouceHttpMessageConverter     | 负责读取资源文件和写出资源文件｜
|SourceHttpMessageConverter     |负责读取资源文件和写出资源文件数据｜
|AllEncompassingFormHttpMessageConvert|负责处理表单(form) 数据｜
|Jaxb2RootElementHttpMessageConverter | 使用JAXB负责读取和写入xml标签格式的数据｜
|MappingJackson2HttpMessageConverter  | 负责读入和写入json格式的数据。利用Jackson的ObjectMapper读取json的数据，操作Object类型的数据，可读取application/json 响应体为application/json|
    

HttpMessageConverter接口：消息转换器
功能：定义了java转为json，xml等数据格式的方法，这个接口有很多的实现类  
    这些实现类完成java对象到json，java对象到xml，java对象到二进制数据的转换

```java
        boolean canWrite(Class<?> var1, @Nullable MediaType var2);
            void write(T var1, @Nullable MediaType var2, HttpOutputMessage var3) throws IOException, HttpMessageNotWritableException;

```

1. canWrite 作用检查处理器方法能不能装换为var2的数据格式, 能就返回true
    MediaType 表示数据格式，例如json， xml等

2. wirte: 把处理器方法的返回值对象，使用jackson的ObjectorMapper转为字符串。
    json = om.writeValueAsString(student)

##### @ResponseBody
作用：把处理器方法返回对象转换为json后，通过HttpsevletResponse输出给浏览器。   
位置: 在方法的定义上面。 和其他注解没有顺序关系  
返回对象框架的处理流程：  
1. 框架会把返回Student类型，调用框架中ArrayList<HttpMessageConverter>中的每个类的canWrite()方法，  
来检查那个HttpMessageConverter接口的实现类能够处理数据  

2. 框架会调用实现类的write(), MappingJackson2HttpMessageConverter的write()方法A  
把student对象转为json，调用Jackson的ObjectMapper实现json  

3. 框架会调用@ResponseBody把2的结果输出到浏览器，ajax请求处理完成

##### 返回自定义类型对象

```java
    @ResponseBody
    @RequestMapping(value = "/returnStudent.do")
    public Student doStudentJsonObject(String name, Integer age) {

        Student student = new Student();
        student.setName("李四");
        student.setAge(20);
        return student;
     }
```

##### 返回list集合

```java
    @ResponseBody
    @RequestMapping(value = "/returnStudents.do")
    public List<Student> doStudentList(String name, Integer age) {

        List<Student> stu = new ArrayList<>();
        Student student = new Student();
        student.setName("李四");
        student.setAge(20);
        stu.add(student);
        student = new Student();
        student.setName("张三");
        student.setAge(17);
        stu.add(student);
        return stu;
    }
```

##### 返回String对象

处理器方法返回的是String , String 表示数据，不是视图  
区分返回的是数据还是视图，看有没有@ResponseBody注解  
如果有@ResponseBody注解， 返回String就是数据，反之就是视图
默认格式为 text/plain;charset=ISO-8859-1

```java
    @ResponseBody
    @RequestMapping(value = "/returnString.do",produces = "text/plain;charset=utf-8")
    public String doStringData(String name, Integer age){
        return "this is string data!";
    }

```


### DefaultServlet

tomcat本身能处理静态资源访问例如html，图片，js文件都是静态文件  

tomcat 有个DefaultServlet 会默认启动处理静态资源文件, 并且处理其他为映射到其他servlet的请求  

例如如下配置中 我们可以访问localhost:8080/myWeb/a 或者 localhost:8080/myWeb/b 时候会有servlet去处理 调用localhost:8080/myWeb/c 是没有servlet映射到就由DefaultServlet 处理
```xml
    <servlet>
        <servlet-name>aservlet</servlet-name>
        <servlet-class>...Aservlet</servlet-class>
    </servlet>
    <servlet-mapping>
        <servlet-name>aservlet</servlet-name>
        <url-pattern>/a</url-pattern>
    </servlet-mapping>
    <servlet>
        <servlet-name>bservlet</servlet-name>
        <servlet-class>...Bservlet</servlet-class>
    </servlet>
    <servlet-mapping>
        <servlet-name>bservlet</servlet-name>
        <url-pattern>/b</url-pattern>
    </servlet-mapping>

```

当你的中央处理器mapping 使用了 <url-pattern>/</url-pattern> 他就替换tomcat中的DefualtServlet 导致静态资源给DispatcherServlet处理 默认下中央调度器不能处理静态资源


#### 第一种处理静态资源的方式

在springmvc的配置文件加入 <mvc:default-servlet-handler>  
原理是：加入这个标签后，框架会创建控制器对象DefaultServletHttpRequestHandler() 类似我们创建的Controller类  
DefaultServletHttpRequestHandler()这个对象可以把接受请求转发给DefaultServlet处理

**default-servlet-handler** 和@RequestMapping由冲突要加入<mvc:annotation-driver/>解决问题

#### 第二种处理动态资源的方式

使用<mvc:resources/>

在spring3.0后Spring定义了专门处理静态资源访问请求的处理器ResouceHttpRequestHandler 并且添加了<mvc:resources/> 专门用于静态资源无法访问情况

属性：
    1. mapping: 访问姿态资源的uri
    2. location：静态资源的访问位置
```xml
    <mvc:resources mapping="image/**" location="/image/"/>
```

#### base 标签

让浏览器中的地址都已base中的地址为基地址进行访问
```html
<base href="http://localhost:8080/myWeb/i"
```

另一外一种jsp el表达式写法

```java
<% String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + request.getContextPath() + "/" %>

<base href="<%=basePath%>"/>

```

### 请求转发

[![gJY9xI.jpg](https://z3.ax1x.com/2021/05/09/gJY9xI.jpg)](https://imgtu.com/i/gJY9xI)


##### forward

显示转发，不同视图解析器一同使用

```java
mv.setViewName("forward:/xxx/xxx/xxx.jsp");
```

##### redirect

框架对重定向操作：
    1. 框架会把Model中的简单类型的数据，转为String 来使用，作为hello.jsp的get请求参数使用。
    目的是在doRedirect.do和hello.jsp中传值, 因为doRedirect.do 和重定向的hello.jsp 不是一个相同的request作用域所以el表达式取不到值
显示转发，不同视图解析器一同使用
    2. 在目标hello.jsp页面可以使用参数集合对象 ${param} 获取请求参数值 例如 ${param.xxx}
    3. 访问不了WEB-INF 文件夹下的目录
```java
@RequestMapping(value ="/doRedirect.do")
public ModelAndView doWithRedierect(String name, Integer age){
    ModelAndView mv = new ModelAndView();
    mv.addObject("myname", name);
    mv.addObject("myage", age);
    mv.setViewName("redirect:/hello.jsp");
    return mv;
    //https://localhost:8080/ssm/hello.jsp/myname=lisi&myage=12
}
```

### 异常处理

sprinbmvc框架采用的是统一，全局的异常处理。
把Controller中的所有异常都集中到一个地方，采用的是aop的思想。把业务逻辑和异常代码分开，解耦和。


#### 异常发生处理逻辑
1. 需要把异常记录下来，记录到数据库，日志文件  
    记录日志发生的时间，那个方法发生的，异常错误内容。
2. 发送通知，把异常的信息通过邮件，短信，微信发送给相关人员
3. 给用户友好的提示
#### 异常处理步骤  
1. 加入依赖文件
2. 创建一个普通类作为全局异常处理类
    1. 在类的上面加入@ControllerAdvice
    2. 在类中定义方法，方法的上面加入@ExceptionHandler
3. 创建处理异常的视图页面
4. 创建springmvc的配置文件
    1. 组件扫描器，扫描@Controller注解
    2. 组件扫描器，扫描@ControllerAdvice所在的包名
    3. 声明注解驱动
使用下面两个注解

#### @ExceptionHandler

属性:value 放类的class

处理异常的方法和控制器的定义一样，可以有多个参数，可以有ModelAndView, String , void, 对象类型的返回值  
方法形参: Exception, 表示Controller中抛出的异常对象。通过行参可以获取发生的异常信息

```java
    @ExceptionHandler(value = NameException.class)
    public ModelAndView doNameException(Exception ex){
        ModelAndView mv = new ModelAndView();

        mv.addObject("msg","姓名必须是zs，其他用户不能访问");
        mv.addObject("ex",ex);
        mv.setViewName("nameError");
        return mv;
    }

```

##### 其余异常处理

处理我们没有设置的异常时候我们在处理异常方法注解哪里不加任何值
```java
    @ExceptionHandler
    public ModelAndView defaultException(Exception ex){
        ModelAndView mv = new ModelAndView();
        mv.addObject("msg","未知错误");
        mv.addObject("ex",ex);
        mv.setViewName("age");
        return mv;
    }

```

#### @ControllerAdvice

控制器增强(也就是说给控制器类增加功能--异常处理功能)
    位置：类上面
    特点：必须让框架知道这个注解所在的包名，需要在springmvc配置文件声明组件扫描器  
    指定@ControllerAdvice所在包名

### 拦截器

1. 拦截器是springmvc中的一种， 需要实现HandlerInterceptor接口
2. 拦截器和过滤器类似，功能方向侧重点不同。过滤器是用来过滤请求参数，设置编码字符集等工作，拦截器是拦截用户的请求，做请求做判断处理的
3. 拦截器是全局的，可以对多个Controller 做拦截。  
    一个项目中可以有0个或者多个拦截器，他们在一起拦截用户的请求。  
    拦截器常用在：用户登录处理，权限检查，记录日志

拦截器：看做是多个Controller中公用的功能，集中到拦截器统一处理，使用的是aop思想  

[![gYbHB9.jpg](https://z3.ax1x.com/2021/05/09/gYbHB9.jpg)](https://imgtu.com/i/gYbHB9)

#### 拦截器的使用步骤

1. 定义类实现HandlerInterceptor接口
2. 在springmvc配置文件中，声明拦截器，让框架知道拦截器存在

#### 拦截器的执行时间
1. 在请求处理之前，也就是controller类中的方法执行之前先辈拦截
2. 在控制器方法执行之后也会执行拦截器
3. 在请求处理完成后也会执行拦截器

#### 实现HandlerInterceptor接口

##### preHandle

预处理方法

参数:
    Object handler: 被拦截的控制器对象

返回值boolean
    1. true 
    2. false 请求没有到控制器方法, 程序被拦截
特点：
    1. 方法在控制器之前执行, 用户的请求先到达此方法
    2. 在这个方法中可以获取请求信息，验证请求时候符合要求
        可以验证用户是否登录，验证用户是否有权限访问某个连接地址(url).
        如果验证失败，可以拦截请求，请求不处理  
        如果验证成功， 可以放行请求，控制器执行方法。  

```java
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        System.out.println("MyInterceptor’s preHandle()");
        String name = request.getParameter("name");
        if("zs".equals(name)){
            return true;
        }
        request.getRequestDispatcher("tips").forward(request,response);
        return false;
    }

```
##### postHandle

后处理方法

参数：
    1. Object handler 被拦截的控制器对象
    2. ModelAndView: 处理器方法的返回值

特点：
    1. 在处理器方法之后执行的
    2. 能够获取到处理器方法的返回值ModelAndView, 可以修改ModelAndView中的数据和视图  
        可以影响最后的执行结果
    3. 主要是对原来的结果二次修改

```java
    public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler, ModelAndView modelAndView) throws Exception {
        if(modelAndView!=null){
            modelAndView.addObject("mydate",new Date());
            modelAndView.setViewName("other");
        }
        System.out.println("MyInterceptor’s postHandle()");
    }

```

##### afterCompletion

参数：
    1. Object handler: 被拦截器的处理器对象
    2. Exception ex： 程序发生的异常
特点
    1. 在请求处理完成后执行的。框架中规定是当你的视图处理完成后，对视图执行了forward。就认为处理完成
    2. 一般做资源回收工作，程序请求过程中船舰了一些对象，在这里可以删除，把占用的内存回收

```java
    public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler, Exception ex) throws Exception {
        long etime = System.currentTimeMillis();
        System.out.println("MyInterceptor’s AfterHandle()");
        System.out.println("time: "+( etime-btime) );
    }

```
##### 多个拦截器

声明拦截器: 拦截器可以有0个或多个  
在框架中保存多个拦截器对象是ArrayList  
按照声明先后的顺序放入到ArrayList

```xml
<mvc:interceptors>
    <mvc:interceptor>
        <mvc:mapping path="/**"/>
        <bean class="com.sample.handler.MyInterceptor1"
    </mvc:interceptor>
    <mvc:interceptor>
        <mvc:mapping path="/**"/>
        <bean class="com.sample.handler.MyInterceptor2"
    </mvc:interceptor>
</mvc:interceptors>
```

**执行过程**

[![gNLQLF.jpg](https://z3.ax1x.com/2021/05/10/gNLQLF.jpg)](https://imgtu.com/i/gNLQLF)

tips: 任何拦截器的preHandler() 返回false 控制器方法不会执行

##### 拦截器和过滤器的区别

1. 过滤器是servlet中的对象， 拦截器是框架中的对象
2. 过滤器实现Filter接口的对象， 拦截器是实现HandlerInterceptor
3. 过滤器是设置request，response的参数, 属性的， 侧重对数据的过滤的。
    拦截器是用来验证请求的，能截断请求
4. 过滤器是是在拦截器之前执行的
5. 过滤器是tomcat服务器的对象， 拦截器是springmvc的对象。
6. 过滤器是一个执行时间点， 拦截器是三个执行时间点
7. 拦截器可以处理jsp， js， html等等  
    拦截器是侧重拦截对controller对象, 如果你的请求不能被DisPatcherServlet接受， 这个请求不会执行拦截器内容
8. 拦截器拦截普通类的方法执行，过滤器过滤servlet请求响应

### springmvc 执行流程

[![gNXXa4.jpg](https://z3.ax1x.com/2021/05/10/gNXXa4.jpg)](https://imgtu.com/i/gNXXa4)

springmvc内部请求的处理流程：也就是springmvc接受请求，到完成处理的流程
1. 用户发起请求some.do
2. DisPatcherServlet接受some.do, 把请求转交给处理器映射器
    处理器映射器：springmvc框架中的一种对戏那个，框架把是西安HandlerMapping接口的类都叫做映射器  
    处理器映射器作用： 根据请求， 从springmvc容器对象中获取处理器对象（myControlller controller = ctx.getBean("some.do") 框架把找到的处理器对象放到一个个叫做处理器执行链(HandlerExecutionChain)的类保存  
    HanlderExecutionChain: 类中保存
        1. 处理器对象 MyController
        2. 项目中的所有的拦截器List<HandlerInterceptor>
3. DispatcherServlet 把 2 中的 HanlderExecutionChain 中的处理器对象交给了处理器适配器对象
    处理器适配器：springmvc中的对象，需要是西安HandlerAdapter接口
    处理器适配器作用： 执行处理器方法(调用MyController.doSome 得到返回值ModelAndView)
4. DisPatcherServlet 把 3 中获取的ModelAndView教改会诶了视图解析器对象
    视图解析器： springmvc中的对象，需要实现ViewResoler接口(可以有多个)
    View是一个接口 表示视图的， 在框架中jsp，html不是string表示，而是使用view和他的实现类表示视图  
    InternalResourceView： 视图类， 表示jsp文件，视图解析器会创建 InternalResourceView类对象，
    这个对象的里面有个属性url=你的地址
5. DisPatcherServlet 把4步骤中创建的View 对象获取到， 调用View类自己的方法，把Model数据放入到request作用域。 执行对象视图的forward。 请求结束。 
