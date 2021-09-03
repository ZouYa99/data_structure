//
//  intersection-of-two-linked-lists.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/4.
//

#include "ListNode.hpp"
/*
 给你两个单链表的头节点 headA 和 headB ，
 请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr){
            return nullptr;
        }
        ListNode *curA=headA,*curB=headB;
        while(curA!=curB){
            curA = (curA==nullptr)?headB:curA->next;
            curB = (curB==nullptr)?headA:curB->next;
        }
        return curA;
    }
};
