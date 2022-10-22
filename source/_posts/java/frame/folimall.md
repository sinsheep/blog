---
title: folimall 
date: 2021-07-06 15:37
tags: [springboot]
categories: [springboot] 
---


### Gateway

1. 开启服务发现
2. 配置文件

```yml
spring:
  cloud:
    gateway:
      routes:
        - id: test_route
          uri: https://www.baidu.com
          predicates:
            - Query=url,baidu

        - id: qq_route
          uri: https://www.qq.com
          predicates:
            - Query=url,qq

```
### 前端

使用框架  jjQuery,vue,webpack


### 上传图片

使用阿里云的oss对象存储


服务器签名后直接传递
 ```mermaid
 graph LR;
     A(用户)--1.用户向应用服务器请求上传policy--->jc(应用服务器);
     jc--2.应用服务器上传返回上传policy-->A(用户);
     A--3.用户直接上传数据到oss----->oss(oss);
 ```


1. 引入spring-boot-starter-aliyun-oss
2. 配置key，endpoint等相关信息
3. 使用OSSClient 进行相关操作

依赖
```xml
        <dependency>
            <groupId>com.alibaba.cloud</groupId>
            <artifactId>spring-cloud-starter-alicloud-oss</artifactId>
            <version>2.1.0.RELEASE</version>
        </dependency>
```
application.yml配置
```yml
spring:
  cloud:
    alicloud:
      access-key: youraccess-key
      secret-key: yoursecret-key 
      oss:
        endpoint: oss-cn-hangzhou.aliyuncs.com
```

样例代码
```java
	@Autowired
	OSSClient ossClient;
	@Test
	public void testUpload() throws FileNotFoundException {
		InputStream inputStream = new FileInputStream("/home/ysx/Documents/Picture1.png");
		ossClient.putObject("folimall","dialog.jpg",inputStream);

		ossClient.shutdown();
	}
```



## gateway

网关配置
```
    - id: qq_route
    uri: https://www.qq.com
    predicates:#断言
    - Query=url,qq#查询url=qq

    - id: product_route
    uri: lb://folimall-product #lb 负载均衡后面跟着微服务的名
    predicates:
    - Path=/api/product/** #需要判断的路径
    filters:
    - RewritePath=/api/(?<segment>.*),/$\{segment} #重写地址
```



### 校验注解

JSR303
1. 给bean添加校验注解javax.validation.constraint
2. 添加@Valid注解 效果: 校验错误以后会有默认的响应
3. 紧跟bean后一个BindingResult ,  可以获取得到校验的结果


#### 分组校验


1. @NotBlank(message = "品牌名不能为空!!!!!", groups = {AddGroup.class,UpdateGroup.class}) 给校验注解备注什么情况下需要进行校验
2. @Validated(value = {AddGroup.class}) 在需要校验参数前加入
3. 默认没有指定分组的注解会校验，指定了分组的不会校验


#### 自定义校验

1. 编写一个自定义的校验注解
2. 编写一个自定义的校验器
3. 关联自定义的校验器
```java
package com.ysx.common.valid;

import javax.validation.Constraint;
import javax.validation.Payload;
import java.lang.annotation.*;

@Documented
@Constraint(
        validatedBy = {ListValueConstraintValidator.class}//校验器, 可以指定多个来匹配不同类型的
)
@Target({ElementType.METHOD, ElementType.FIELD, ElementType.ANNOTATION_TYPE, ElementType.CONSTRUCTOR, ElementType.PARAMETER, ElementType.TYPE_USE})
@Retention(RetentionPolicy.RUNTIME)
public @interface ListValue {

    String message() default "{com.ysx.common.valid.ListValue.message}";

    Class<?>[] groups() default {};

    Class<? extends Payload>[] payload() default {};

    int[] values() default {};
}

```


### 统一异常处理

1. @ControllerAdvice
2. @ExceptionHandler
代码
```java
package com.ysx.folimall.product.exception;

import com.ysx.common.utils.R;
import lombok.extern.slf4j.Slf4j;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

import java.util.HashMap;
import java.util.Map;

@Slf4j
@RestControllerAdvice(basePackages = {"com.ysx.folimall.product.controller"})
public class FolimallExceptionControllerAdvice {


    @ExceptionHandler(value = MethodArgumentNotValidException.class)
    public R handleValidException(MethodArgumentNotValidException e){
        log.error("数据校验出现问题{},异常类型｛｝",e.getMessage(),e.getClass());
        BindingResult result = e.getBindingResult();
        Map<String,String> errorMap = new HashMap<>();
        result.getFieldErrors().forEach((fieldError -> {
            errorMap.put(fieldError.getField(),fieldError.getDefaultMessage());
        }));
        return R.error(400,"数据校验出现问题").put("data",errorMap);
    }

    @ExceptionHandler(value = Throwable.class)
    public R handleException(Throwable throwable){

        return R.error(400,);
    }

}
```



### 父子组件(前端)

1. 子组件给父组件传递数据，事件机制
2. 子组件给父组件发一个事件，携带上事件
3. this.$emit("事件名字",携带数据...);

子组件
```
			console.log("attrgourp感知被category被点击", data, node, component);
			<category-vue @tree-node-click="treenodeclick"></category-vue>
```

父组件
```
<template>
	<el-tree :data="menus" :props="defaultProps" node-key="catId" ref="menuTree" @node-click="nodeclick">

	</el-tree>
</template>

<script>
export default {
	methods: {
		nodeclick(data, node, component) {
			console.log("子组件被点击", data, node, component);
			this.$emit("tree-node-click", data, node, component);
		},
	},
};
</script>
<style>
</style>
```




### openFeign


使用要注册进入注册中心， 并且在启动类加上  
@EnableFeignClients(basePackages = "com.ysx.folimall.member.feign") 注解


```java
package com.ysx.folimall.product.feign;

import com.ysx.common.to.SpuBoundTo;
import com.ysx.common.utils.R;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;

@FeignClient("folimall-coupon")
public interface CouponFeignService {


    /**
     * couponFeignService.saveSpuBounds(sputBoundTO)
     * 1. @RequestBody 将这个对象转为json
     * 2. 找到folimall-coupon对象 给/coupon/spubounds/save 发请求
     * 将上一步转的json放在请求体的位置，发送请求
     * 3. 对方服务受到请求，请求体里有json数据
     * function(@RequestBody SpuBoundsEntity spuBounds) 将请求体的json转为SpuBoundsEntity
     * 只要json的数据模型数据模型是兼容的，双方服务无需使用同一个to，属性名一一对应就ok
     * @param spuBoundTo
     * @return
     */
    @PostMapping("/coupon/spubounds/save")
    R saveSpuBounds(@RequestBody SpuBoundTo spuBoundTo);
}

```


