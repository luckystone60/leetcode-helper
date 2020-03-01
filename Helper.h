/*
* Copyright (c) Jiaoleilei Technologies Co., Ltd. 2012-2018. All right reserved.
* Description: Helper.h 文件功能描述
* Author：焦磊磊
* Create：2020-03-01
*/
#ifndef LEETCODE_HEAD
#define LEETCODE_HEAD

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <regex>
#include <sstream>

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
const int32_t TREE_NODE_BOUNDNARY = INT_MIN + 1;    // replace null
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
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

ListNode *CreateListImpl(const std::vector<int> &vec)
{
	size_t count = vec.size();
    ListNode *head, *curr;

	if (count == 0) {
		return nullptr;
	}

    head = new ListNode(vec[0]);
    curr = head;
    for (size_t i = 1; i < count; i++) {
        ListNode *temp = new ListNode(vec[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

ListNode *CreateList(const std::string &inputStr)
{
	auto vec = CreateVector<int>(inputStr);
    return CreateListImpl(vec);
}

void DestroyList(ListNode *head)
{
    ListNode *curr = head;
    ListNode *temp = NULL;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        delete temp;
    }
}

TreeNode *CreateTreeImpl(const std::vector<int> &vec)
{
	size_t count = vec.size();
    TreeNode **treeArr = new TreeNode*[count];
    for (size_t i = 0; i < count; i++)
    {
        if (TREE_NODE_BOUNDNARY == vec[i]) {
			treeArr[i] = nullptr;
		} else {
            treeArr[i] = new TreeNode(vec[i]);
		}
	}

    size_t curr = 1;
    for (size_t i = 0; i<count; i++)
    {
        if( !treeArr[i] ) {
            continue;
		}
 
        if (curr < count) {
            treeArr[i]->left = treeArr[curr++];
		}
        if (curr < count) {
            treeArr[i]->right = treeArr[curr++];
		}
    }
    
    TreeNode *root = treeArr[0];
    delete[] treeArr;
    return root;
}

TreeNode *CreateTree(const std::string &input)
{
	auto root = CreateTreeImpl(CreateVector<int>(input));
    return root;
}

void DestroyTree(TreeNode *root)
{
    if (nullptr == root) {
        return;
	}

    DestroyTree(root->left);
    DestroyTree(root->right);
    delete root;
}

/*******************************
2. print funcitons
*******************************/
template<typename T>
void PrintValue(const T &value, const std::string message = "")
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

std::vector<int> TransListToVector(ListNode *head)
{
    std::vector<int> ret;
    ListNode *node = head;
    while (node) {
        ret.push_back(node->val);
        node = node->next;
    }

    return ret;
}

void PrintList(ListNode *head)
{
    auto vec = TransListToVector(head);
    PrintVector(vec, "PrintList");
}

void PrintTreeImpl(TreeNode* n, bool left, std::string const& indent)
{
    if (n->right)
    {
        PrintTreeImpl(n->right, false, indent + (left ? "|     " : "      "));
    }
    std::cout << indent;
    std::cout << (left ? '\\' : '/');
    std::cout << "-----";
    std::cout << n->val << std::endl;
    if (n->left)
    {
        PrintTreeImpl(n->left, true, indent + (left ? "      " : "|     "));
    }
}
 
void PrintTree(TreeNode* root)
{
    if (root->right) {
        PrintTreeImpl(root->right, false, " ");
    }
    
    std::cout << root->val << std::endl;
    if (root->left) {
        PrintTreeImpl(root->left, true, " ");
    }
}

#endif //LEETCODE_HEAD