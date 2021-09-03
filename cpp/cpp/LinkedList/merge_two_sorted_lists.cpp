//
//  merge_two_sorted_lists.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/31.
//

#include "ListNode.hpp"
/*
 将两个升序链表合并为一个新的 升序 链表并返回。
 新链表是通过拼接给定的两个链表的所有节点组成的。
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        ListNode *cur1=l1,*cur2=l2;
        ListNode *head = new ListNode(-200);
        ListNode *cur = head;
        while(cur1!=nullptr&&cur2!=nullptr){
            if(cur1->val<cur2->val){
                cur->next=cur1;
                cur1=cur1->next;
            }else{
                cur->next=cur2;
                cur2=cur2->next;
            }
            cur=cur->next;
        }
        cur->next = cur1==nullptr ? cur2 : cur1;
        return head->next;
    }
};
