### 第二章 线性表

- 其中`SqList.h`  ,`SqList.cpp`,  `SqListTest.cpp`,这三个文件是线性表基本操作
- `SqListQuestion.cpp`,`SqListQuestion.h`, `SqListQuestionTest.cpp`是课后习题

#### 1. build

```sh
# SqList
g++ SqList.h SqList.cpp SqListTest.cpp  -o SqListTest
# 算法习题
g++ SqListQuestion.cpp SqListQuestion.h SqListQuestionTest.cpp SqList.cpp SqList.h -o SqListQuestionTest
```
#### 2. run
```shell
# SqList
./SqListTest
# 算法习题
./SqListQuestionTest
```

