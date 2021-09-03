//
//  longest-palindromic-substring.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/31.
//

#include <stdio.h>
#include <string>
using namespace::std;
/*
 给你一个字符串 s，找到 s 中最长的回文子串。
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        if(length<2){
            return s;
        }
        bool dp[length][length];
        int i,j,l;
        int len=1,start=0;
        for(i=0;i<length;i++){
            dp[i][i] = true;
        }
        for(l=2;l<=length;l++){
            for(i=0;i<length;i++){
                j = i+l-1;
                if(j>=length){
                    break;
                }
                if(s[i]!=s[j]){
                    dp[i][j] = false;
                }else{
                    if(j-i<3){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]&&l>len){
                    len = l;
                    start=i;
                }
            }
        }
        return s.substr(start,len);
    }
};

/*
 中心扩展法：
 class Solution {
 public:
     pair<int, int> expandAroundCenter(const string& s, int left, int right) {
         while (left >= 0 && right < s.size() && s[left] == s[right]) {
             --left;
             ++right;
         }
         return {left + 1, right - 1};
     }

     string longestPalindrome(string s) {
         int start = 0, end = 0;
         for (int i = 0; i < s.size(); ++i) {
             auto [left1, right1] = expandAroundCenter(s, i, i);
             auto [left2, right2] = expandAroundCenter(s, i, i + 1);
             if (right1 - left1 > end - start) {
                 start = left1;
                 end = right1;
             }
             if (right2 - left2 > end - start) {
                 start = left2;
                 end = right2;
             }
         }
         return s.substr(start, end - start + 1);
     }
 };
 */
