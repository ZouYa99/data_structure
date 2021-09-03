//
//  ListNode.hpp
//  cpp
//
//  Created by ZouYa on 2021/8/30.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif /* ListNode_hpp */
