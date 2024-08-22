# miniSTL库

---
CSDN配套博客链接 : [zengy5](http://t.csdnimg.cn/cGOYP)

项目文件目录

```cpp

miniSTL
├─ include
│  ├─ HashTable.h
│  └─ RedBlackTree.h
└─ src
   ├─ myDeque.cpp
   ├─ myHashTable.cpp
   ├─ myList.cpp
   ├─ myMap.cpp
   ├─ myMultiSet.cpp
   ├─ myRedBlackTree.cpp
   ├─ mySet.cpp
   ├─ myUnMap.cpp
   ├─ myUnSet.cpp
   └─ myVector.cpp
```

项目实现了包括

+ vector
+ deque
+ map
+ set
+ stack

等容器,以及它们的变形,如unordered_set等,并且在博客中有详细实现过程与原理

目前进度(10/14),配套博客更新进度为(9/14)

以及测试工程还未完成

使用方法:

```bash
git clone https://github.com/zengy5/miniSTL.git
cd miniSTL
mkdir build && cd build
cmake ..
make
```
