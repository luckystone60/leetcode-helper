/*
* Copyright (c) luckystone60 Technologies Co., Ltd. 2012-2018. All right reserved.
* Description: main.cpp
* Author：luckystone60
* Create：2020-03-01
*/

#include "Helper.h"
#include "Solution.h"

using namespace std;
using namespace LEETCODE::HELPER;

#ifdef TEST
int TestHelper()
{
    int intTest = 0;
    float floatTest = 0.0f;
    double doubleTest = 0.0f;
    string stringTest = "test";
    string stringNullTest = "";
    char * strTest = "test";
    vector<int> vecIntTest = {0, 2};
    vector<int> vecIntNullTest = {};

    vector<vector<int>> matIntTest = {{0,3}, {2, 4}};
    vector<vector<int>> matIntNullTest = {{}};

    // // [2.123,0.234,34]
    string inputDoubleVec = "[2.123,0.234,34]";
    string inputIntVec = "[2, 9, 0]";
    auto doubleVec = CreateVector<double>(inputDoubleVec);
    PrintVector(doubleVec);
    cout << "++++++++++++++++++++++++++++++++++++++" << endl;

    // ["sdf", "sdfr", "seosd"]
    string inputStrVec = R"(["sdf", "sdfr", "seosd"])";
    auto strVec = CreateVector<string>(inputStrVec);
    PrintVector(strVec);
    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
    
    // [[2.123,0.234,34], [2.123,0.234,34], [2.123,0.234,34]]
    string inputFloatMat = R"([[-2.123,0.234,34], [2.123,0.234,34], [-2.123,0.234,34]])";
    auto floatMat = CreateMatrix<float>(inputFloatMat);
    PrintMatrix(floatMat);
    cout << "++++++++++++++++++++++++++++++++++++++" << endl;

    ListNode *head = CreateList(inputIntVec);
    PrintList(head);
    DestroyList(head);
    cout << "++++++++++++++++++++++++++++++++++++++" << endl;

    string inputTree = "[1, -2, 3, 4, null, 5, 6]";
    string inputTree2 = "[1, -2, 3, 4, null, 5, 6, 7, 8, 9, 10, 11, 12]";
    TreeNode *root = CreateTree(inputTree2);
    PrintTree(root);
    DestroyTree(root);
    cout << "++++++++++++++++++++++++++++++++++++++" << endl;

    return 0;
}
#endif


int main()
{

    // Solution235 so;
    // auto input = CreateTree("[6,2,8,0,4,7,9,null,null,3,5]");
    // PrintTree(input);

    // auto p = GetSpecifiedValueNode(input, 2);
    // auto q = GetSpecifiedValueNode(input, 8);

    // auto ret = so.lowestCommonAncestor(input, p, q);
    // PrintValue(ret->val, "result ");

    Solution418 so;
    vector<string> input = {"a", "b", "e"};
    PrintValue(so.wordsTyping(input, 10000, 7));

    system("pause");
    return 0;
}
