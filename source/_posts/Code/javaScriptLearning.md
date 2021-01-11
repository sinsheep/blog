---
title: javaScriptLearning
date: 2020-07-23 09:44:58
tags: [javaScript]
categories: [Code]
---


## 对象

### hasOwnProperty()

检测传递参数是否有该属性
```javaScript

function oss(options){
    if(!options.hasOwnProperty('host')){
       throw new Error('must set host') 
    }
}
oss({name:"test"});
// will throw Error lack of host
```

