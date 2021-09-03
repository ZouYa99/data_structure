//
//  middle_of_linked_list.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/31.
//

#include "ListNode.hpp"
/*
 给定一个头结点为 head 的非空单链表，返回链表的中间结点。
 如果有两个中间结点，则返回第二个中间结点。
 */

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow=head,*fast=head;
    if(head->next==NULL){
        return head;
    }
    while(fast->next!=NULL){
        if(fast->next->next==NULL){
            return slow->next;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
