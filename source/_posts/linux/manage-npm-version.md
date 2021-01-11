---
title: manage-npm-version 
date: 2020-09-20 08:18
tags: [npm]
categories: [linux] 
---

遇到了一些坑如hexo在npm 14.00时候会一直报错,所以我们安装一个node版本管理模块n

```sh
sudo npm install n
```

安装稳定版本
```bash
sudo n stable
```

安装最新版本
```
sudo n latest
```

安装版本号
```
sudo n 版本号
```

例如
```
sudo n 12.0
```

查看当前已有版本号
```
n
```

切换版本号
```
n 版本号
```

删除版本号
```
sudo n rm 版本号
```
