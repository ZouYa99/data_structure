//
//  merge-k-sorted-lists.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include "ListNode.hpp"
#include <vector>
using namespace::std;
/*
 给你一个链表数组，每个链表都已经按升序排列。
 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 */
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode *cur1=l1,*cur2=l2;
        ListNode *head = new ListNode();
        ListNode *p=head;
        while(cur1&&cur2){
            if(cur1->val<cur2->val){
                p->next = cur1;
                cur1 = cur1->next;
            }else{
                p->next = cur2;
                cur2 = cur2->next;
            }
            p=p->next;
        }
        if(cur1){
            p->next = cur1;
        }else{
            p->next = cur2;
        }
        return head->next;
    }
    ListNode* merge(vector<ListNode*>& lists,int low,int high){
        if(low==high) return lists[low];
        if(low>high) return nullptr;
        int mid = low + ((high-low)>>1);
        return mergeTwoLists(merge(lists,low,mid),merge(lists,mid+1,high));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size==0){
            return nullptr;
        }
        return merge(lists,0,size-1);
    }
};
