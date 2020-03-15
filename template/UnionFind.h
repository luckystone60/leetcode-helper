/*
* Copyright (c) luckystone60 Technologies Co., Ltd. 2012-2018. All right reserved.
* Description: UnionFind.h
* Author：luckystone60
* Create：2020-03-13
*/

// /*
//     查找操作，递归找父结点，直到父结点指向自己，表示为根，然后进行路径压缩，对路径上所有节点进行父结点的重新指定
//     两个while
// */
// int find(vector<int>& parent, int i)
// {
//     int tmp = i;
//     while (tmp != parent[tmp]) {
//         tmp = parent[tmp];
//     }

//     while(tmp != parent[i]) {
//         int tt = parent[i];
//         parent[i] = tmp;
//         i = tt;
//     }
//     return tmp;
// }


// /*
//     合并操作，首先通过查找操作，判断两个节点是否父结点相同，如相同不做任何操作，如不同则指定一节点的父结点为另一节点，后续有查找操作会将父结点统一
//     执行查找操作
// */
// void un(vector<int>& parent, int a, int b)
// {
//     if (find(parent, a) != find(parent, b)) {
//         parent[b] = a;
//     }
// }

// int main()
// {
//     int n;
//     while(cin >> n) {
//         vector<int> table{0, 1, 2, 3, 4, 5, 6,7,8,9};
//         vector<int> parent = table;     // 1. 初始化，所有节点的父结点均为自身

//         for (int i = 0; i < n; i++)
//         {
//             int a, b;
//             cin >> a >> b;

//             un(parent, a, b);           // 2. 合并操作
//         }

//         for_each(table.begin(), table.end(), [&](int x){
//             cout << find(parent, x) << endl;    // 3. 最后遍历一次查找操作，返回相同父结点的认为是同一类
//         });

//     }
// }