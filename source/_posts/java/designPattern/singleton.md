---
title: 单例模式 
date: 2021-06-25 23:32
tags: [design  pattern]
categories: [java, design pattern] 
---
## 单例模式


### 介绍

单例模式（Singleton Pattern）是 Java 中最简单的设计模式之一。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。  

这种模式涉及到一个单一的类，该类负责创建自己的对象，同时确保只有单个对象被创建。这个类提供了一种访问其唯一的对象的方式，可以直接访问，不需要实例化该类的对象。

提示:
    1. 单例只能有一个实例
    2. 单例必须创建自己的唯一实例
    3. 单例必须给所有的其他对象提供这一实例


### 实现

#### 懒汉模式(线程不安全的)

这种是最基本的一种实现，是一种lazy loading,但是最大的问题是不支持多线程，没有加锁，所以严格意义上不是单例  

```java
public class Singleton ｛
    private static Singleton instance;
    private Singleton(){}

    public static Singleton getInstance(){
        if(instance==null){
            instance = new Singleton();
        }
        return instance;
    }
｝
```


#### 懒汉模式(线程安全的,)


这种是具备线程安全的懒加载， 能在多线程工作，但是效率低，因为大部分情况下不需要同步
```java
public class Singleton ｛
    private static Singleton instance;
    private Singleton(){}

    public static synchronized Singleton getInstance(){
        if(instance==null){
            instance = new Singleton();
        }
        return instance;
    }
｝
```

#### 饿汉式

这种是classloader的机制，避免了多线程同步问题. 但是类加载的时候就初始化了，浪费内存.

```java

public class Singleton ｛
    private static Singleton instance = new Singleton();
    private Singleton(){}

    public static Singleton getInstance(){
        return instance;
    }
｝
```


#### 双检锁(DCL, double-checked locking)

这种也是一种懒加载方式,这种采用了双锁的方式，安全且在多线程情况下能保持多性能.

```java
public class Singleton ｛
    private static Singleton instance;
    private Singleton(){}

    public static Singleton getInstance(){
        if(instance==null){
            synchronized(Singleton.class){
                if(instance==null){
                    instance = new Singleton();
                }       
            }
        }
        return instance;
    }
｝

```
#### 登记式/静态内部类

懒加载方式, 这种方式能达到双检查锁的一样功效，单实现简单，对静态域使用延迟初始化. 比双检锁号。
双检锁可在实例域需要延迟使用时候显示

```java
public class Singleton {  
    private static class SingletonHolder {  
        private static final Singleton INSTANCE = new Singleton();  
    }  
    private Singleton (){}  
    public static final Singleton getInstance() {  
        return SingletonHolder.INSTANCE;  
    }  
}
```

