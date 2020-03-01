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

class Solution235 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(p->val<root->val&&q->val<root->val)
            return lowestCommonAncestor(root->left, p, q);
        if(p->val>root->val&&q->val>root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

class Solution418 {
public:
    bool isValid(vector<int> &pos, int &wordInd)
    {
        if (cols - pos[1] == sentence[wordInd].size()) {
            cout << sentence[wordInd] << endl;
            pos[0]++;
            pos[1] = 0;
            wordInd++;
            return true;
        } else if (cols - pos[1] > sentence[wordInd].size()) {
            pos[1] += sentence[wordInd].size() + 1;
            if (pos[1] == cols) {
                pos[0]++;
                pos[1] = 0;
                cout << sentence[wordInd] << "-" << endl;
            } else {
                cout << sentence[wordInd] << "-";
            }
            wordInd++;
            return true;
        } else {
            cout << endl;
            pos[0]++;
            pos[1] = 0;
            return false;
        }
    }

    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        this->sentence = sentence;
        vector<int> pos(2, 0);
        int wordInd = 0;
        int ret = 0;
        int loopCount = 0;
        while (pos[0] < rows) {
            if (isValid(pos, wordInd)) {
                if (wordInd == sentence.size()) {
                    ret++;
                    wordInd = 0;
                    if (pos[1] == 0 && pos[0] < rows && loopCount == 0) {
                        loopCount = ret;
                        int tmp = (rows - pos[0]) / loopCount;
                        pos[0] += tmp * loopCount;
                        ret += tmp * loopCount;
                    }
                }
            }
        }

        return ret;
    }

    int rows;
    int cols;
    vector<string> sentence;
};


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
