# leetcode-helper
包含对LeetCode中常用的数据结构：vector，List，Tree的构造，打印和输入。方便本地测试，而不用依赖于网页的LeetCode。
主要由Helper.h，Helper.cpp构成，main.cpp目前为测试
## 使用方法
将Helper.cpp和对应头文件加入编译过程中即可。注意使用前导入命名空间LEETCODE::HELPER
```c++
using namespace LEETCODE::HELPER;
```
## 构造各类数据
输入为string，格式与LeetCode官网一致
