---
title: dubbo Learning 
date: 2021-05-18
tags: [dubbo]
categories: [java,dubbo] 
---

## Dubbo

Dubbo是一个高性能的RPC框架，解决了分布式中的调用问题
    优点： 解决了分布式系统中互相调用的问题
    缺点： 假设有100台服务器，50台用户业务服务器，50台订单业务服务器，但是在上线后发现, 用户服务器使用效率很小，但是订单服务器压力很大，最佳配比应该是1:4 这时候就要求我们还有一个统一管理的调度中心

[![gh46c8.jpg](https://z3.ax1x.com/2021/05/18/gh46c8.jpg)](https://imgtu.com/i/gh46c8)

