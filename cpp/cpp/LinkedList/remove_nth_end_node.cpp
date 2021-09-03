//
//  remove_nth_end_node.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/31.
//

#include "ListNode.hpp"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *preHead = new ListNode(-1,head);
        ListNode *prev=preHead,*cur=head;
        int i=0;
        while(i<n&&cur){
            cur=cur->next;
            i++;
        }
        while(cur){
            cur=cur->next;
            prev=prev->next;
        }
        prev->next=prev->next->next;
        ListNode *ans=preHead->next;
        delete preHead;
        return ans;
    }
};
