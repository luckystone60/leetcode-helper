/*
* Copyright (c) luckystone60 Technologies Co., Ltd. 2012-2018. All right reserved.
* Description: Helper.cpp
* Author：luckystone60
* Create：2020-03-01
*/

#include "Helper.h"

using namespace LEETCODE::HELPER;

ListNode *LEETCODE::HELPER::CreateListImpl(const std::vector<int> &vec)
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

ListNode *LEETCODE::HELPER::CreateList(const std::string &inputStr)
{
	auto vec = CreateVector<int>(inputStr);
    return CreateListImpl(vec);
}

void LEETCODE::HELPER::DestroyList(ListNode *head)
{
    ListNode *curr = head;
    ListNode *temp = NULL;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        delete temp;
    }
}

TreeNode *LEETCODE::HELPER::CreateTreeImpl(const std::vector<int> &vec)
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

TreeNode *LEETCODE::HELPER::CreateTree(const std::string &input)
{
	auto root = CreateTreeImpl(CreateVector<int>(input));
    return root;
}

void LEETCODE::HELPER::DestroyTree(TreeNode *root)
{
    if (nullptr == root) {
        return;
	}

    DestroyTree(root->left);
    DestroyTree(root->right);
    delete root;
}

std::vector<int> LEETCODE::HELPER::TransListToVector(ListNode *head)
{
    std::vector<int> ret;
    ListNode *node = head;
    while (node) {
        ret.push_back(node->val);
        node = node->next;
    }

    return ret;
}

void LEETCODE::HELPER::PrintList(ListNode *head)
{
    auto vec = TransListToVector(head);
    PrintVector(vec, "PrintList");
}

void LEETCODE::HELPER::PrintTreeImpl(TreeNode* n, bool left, std::string const& indent)
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
 
void LEETCODE::HELPER::PrintTree(TreeNode* root)
{
    if (root->right) {
        PrintTreeImpl(root->right, false, " ");
    }
    
    std::cout << root->val << std::endl;
    if (root->left) {
        PrintTreeImpl(root->left, true, " ");
    }
}