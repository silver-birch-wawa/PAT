<h3><a href='http://codeup.hustoj.com/problem.php?id=6110'>题目链接<a></h3>

---
#### 注意要点:
> 1. C与C++混用的写法

```
#include<iostream>
#include<cstdio>
using namespace std;
```

> 2. 使用sort函数需要的函数库

```
#include<algorithm>
```

> 3. sort函数使用

##### sort函数的错误写法:（要传指针而不是值）
<del> sort(stu[0],stu[10],cmp); </del>
##### 正确写法:
sort(stu+0,stu+10,cmp);
