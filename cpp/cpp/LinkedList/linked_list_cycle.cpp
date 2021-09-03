//
//  linked_list_cycle.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/31.
//

#include "ListNode.hpp"
/*
 给定一个链表，判断链表中是否有环。
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr){
            return false;
        }
        //使用快慢指针，如果存在环，那么两个指针在环中最终会相遇
        ListNode *slow=head,*fast=head->next;
        // while(slow!=fast){
        //     if(fast==nullptr||fast->next==nullptr){
        //         return false;
        //     }
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // return true;
        while(fast!=nullptr){
            if(slow==fast){
                return true;
            }
            if(fast->next==nullptr){
                return false;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
};
