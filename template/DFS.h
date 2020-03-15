/*
* Copyright (c) luckystone60 Technologies Co., Ltd. 2012-2018. All right reserved.
* Description: DFS.h
* Author：luckystone60
* Create：2020-03-10
*/

/*
input--输入数据指针
cur or gap--标记当前位置或距离目标的距离
path--当前路径，也是中间结果
result--存放最终结果
void dfs(type *input, type *path, int cur or gap, type *result)
{
    if (数据非法) return 0;     // 终止条件
    if (cur == input.size( or gap == 0)) {  // 收敛条件
        将 path 放入 result
    }

    if (可以剪枝) return;   // 也可能会放在for循环里剪枝

    for(...) { // 执行所有可能的扩展动作
        执行动作，修改path
        dfs(input, step + 1 or gap--, result);
        恢复 path
    }
}
*/