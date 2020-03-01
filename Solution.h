/*
* Copyright (c) luckystone60 Technologies Co., Ltd. 2012-2018. All right reserved.
* Description: Solution.h
* Author：luckystone60
* Create：2020-03-01
*/

#ifndef SOLUTION_H
#define SOLUTION_H

#include "Helper.h"
using namespace LEETCODE::HELPER;
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // iteration
        stack<ListNode*> next;
        ListNode* temp=head;
        while(temp)
        {
            next.push(temp);
            temp=temp->next;
        }
        ListNode* result=new ListNode(0);
        temp=result;
        while(!next.empty())
        {
            temp->next=next.top();
            next.pop();
            temp=temp->next;
        }
        temp->next=NULL;
        return result->next;
    }
};

#endif //SOLUTION_H