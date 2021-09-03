//
//  reverse-nodes-in-k-group.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include "ListNode.hpp"
#include <utility>
using namespace::std;
/*
 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 k 是一个正整数，它的值小于或等于链表的长度。
 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 */

class Solution {
private:
    pair<ListNode*,ListNode*> reverseLink(ListNode* head,ListNode* tail){
        ListNode *pre=tail->next,*cur=head;
        while(pre!=tail){
            ListNode* next = cur->next;
            cur->next = pre;
            pre=cur;
            cur=next;
        }
        return {tail,head};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        ListNode* preHead = new ListNode(-1);
        preHead->next = head;
        ListNode* pre = preHead;
        ListNode* tail = pre;
        while(head){
            for(int i=0;i<k;i++){
                tail = tail->next;
                if(!tail){
                    return preHead->next;
                }
            }
            pair<ListNode*,ListNode*>result = reverseLink(head,tail);
            head=result.first;
            tail=result.second;
            pre->next=head;
            pre=tail;
            head=pre->next;
        }
        return preHead->next;
    }
};
