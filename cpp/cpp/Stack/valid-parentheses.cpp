//
//  valid-parentheses.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/31.
//

#include <stdio.h>
#include <string>
#include <stack>
#include <unordered_map>
using namespace::std;
/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 有效字符串需满足：
 左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。
 */
class Solution {
public:
    bool isValid(string s) {
        int length = s.length();
        if(length%2==1){
            return false;
        }
        stack<char> stack;
        unordered_map<char,char> dictionary = {{')','('},{'}','{'},{']','['}};
        for(char c : s){
            if(dictionary.count(c)){
                if(stack.empty()||stack.top()!=dictionary[c]){
                    return false;
                }
                stack.pop();
            }else{
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
