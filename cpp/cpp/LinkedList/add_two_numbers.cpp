//
//  add_two_numbers.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/30.
//

#include "ListNode.hpp"
/*
 给你两个 非空 的链表，表示两个非负的整数。
 它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 请你将两个数相加，并以相同形式返回一个表示和的链表。
 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1=l1,*cur2=l2;
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        int cur=0,pre=0;
        while(cur1||cur2){
            int num1 = cur1==nullptr?0:cur1->val;
            int num2 = cur2==nullptr?0:cur2->val;
            cur = num1 + num2 + pre;
            ListNode *node = new ListNode(cur%10);
            p->next = node;
            p=p->next;
            pre=cur/10;
            if(cur1){
                cur1=cur1->next;
            }
            if(cur2){
                cur2=cur2->next;
            }
        }
        if(pre!=0){
            p->next = new ListNode(pre);
            p=p->next;
        }
        p->next=nullptr;
        return head->next;
    }
};
