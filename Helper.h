/*
* Copyright (c) luckystone60 Technologies Co., Ltd. 2012-2018. All right reserved.
* Description: Helper.h
* Author：luckystone60
* Create：2020-03-01
*/

#ifndef LEETCODE_H
#define LEETCODE_H

#include <iostream>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>

#include <regex>
#include <sstream>

namespace LEETCODE
{
namespace HELPER
{
/*******************************
0. data structure
*******************************/
// list Node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// tree Node
const int32_t TREE_NODE_BOUNDNARY = INT_MIN + 1; // replace null
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

/*******************************
1. create structure
*******************************/
template<typename T>
std::vector<T> CreateVector(const std::string inputStr)
{
    std::vector<T> ret;
    const std::string pattern = R"(([+|-]?\w*\.?\w+),?)";
    std::smatch match;

    std::string log = inputStr;
    while(regex_search(log, match, (std::regex)pattern)) {
        // std::cout << match.str(1) << '\n';
        std::stringstream ss;

        std::string treeNull = match.str(1) == "null" ? std::to_string(TREE_NODE_BOUNDNARY) : match.str(1);
        ss << treeNull;
        T temp;
        ss >> temp;
        ret.push_back(temp);
        log = match.suffix();
    }

    if (ret.empty()) {
        std::cout << "CreateVector failed." << std::endl;
    }

    return ret;
}

template<typename T>
std::vector<std::vector<T>> CreateMatrix(const std::string inputStr)
{
    std::vector<std::vector<T>> ret;
    const std::string pattern = R"((\[[^\[\]]*\]))";
    std::smatch match;

    std::string log = inputStr;
    while(regex_search(log, match, (std::regex)pattern)) {
        std::string vec = match.str(1);
        ret.push_back(CreateVector<T>(vec));
        log = match.suffix();
    }

    if (ret.empty()) {
        std::cout << "CreateVector failed." << std::endl;
    }
    return ret;
}

ListNode *CreateListImpl(const std::vector<int> &vec);

ListNode *CreateList(const std::string &inputStr);

void DestroyList(ListNode *head);

TreeNode *CreateTreeImpl(const std::vector<int> &vec);

TreeNode *CreateTree(const std::string &input);

void DestroyTree(TreeNode *root);

/*******************************
2. print funcitons
*******************************/
template<typename T>
void PrintValue(const T &value, const std::string message = "PrintValue")
{
    std::cout << message << " " << value << std::endl;
}

template<typename T>
void PrintVector(const std::vector<T> &vec, const std::string message = "PrintVector", bool showMessage = true, bool endWithEnter = true)
{
    if (showMessage) {
        std::cout << message << ": " << std::endl;
    }

    std::cout << "[";
    int32_t count = 0;
    for (auto &&i : vec) {
        if (count == 0) {
            std::cout << i;
        } else {
            std::cout << "," << i;
        }

        count++;
    }
    
    std::cout << "]";
    if (endWithEnter) {
        std::cout << std::endl;
    }

    return;
}

template<typename T>
void PrintMatrix(const std::vector<std::vector<T>> &matrix, const std::string message = "PrintMatrix")
{
    std::cout << message << ": " << std::endl;
    std::cout << "[";
    int32_t count = 0;
    for (auto &&i : matrix) {
        if (count == 0) {
            PrintVector(i, "", false, false);
        } else {
            std::cout << ",";
            PrintVector(i, "", false, false);
        }

        count++;
    }
    
    std::cout << "]" << std::endl;
}

std::vector<int> TransListToVector(ListNode *head);

void PrintList(ListNode *head);

void PrintTreeImpl(TreeNode *n, bool left, std::string const &indent);

void PrintTree(TreeNode *root);
} // namespace HELPER
} // namespace LEETCODE

#endif //LEETCODE_H