//
//  reverse_linked_list.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/31.
//

#include "ListNode.hpp"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode *pre=nullptr,*cur=head;
        while(cur!=nullptr){
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
};
