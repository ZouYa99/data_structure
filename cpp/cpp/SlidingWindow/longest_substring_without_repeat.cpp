//
//  longest_substring_without_repeat.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/31.
//

#include <stdio.h>
#include <string>
#include <unordered_set>
using namespace::std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        if(length==0){
            return 0;
        }
        unordered_set<char> set;
        int right = -1,sum=0;
        for(int i=0;i<length;i++){
            if(i!=0){
                set.erase(s[i-1]);
            }
            while(right+1<length && !set.count(s[right+1])){
                right++;
                set.insert(s[right]);
            }
            sum = max(sum,right-i+1);
        }
        return sum;
    }
};
