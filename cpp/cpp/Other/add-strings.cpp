//
//  add-strings.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include <stdio.h>
/*
 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 */
/*
 Java:
 class Solution {
     public String addStrings(String num1, String num2) {
         int length1 = num1.length();
         int length2 = num2.length();
         if(length1==0||num1.equals("0")){
             return num2;
         }
         if(length2==0||num2.equals("0")){
             return num1;
         }
         int i=length1-1,j=length2-1;
         int cur = 0,pre = 0,now=0;
         StringBuffer strBuffer = new StringBuffer();
         while(i>=0&&j>=0){
             now = (num1.charAt(i)-'0')+(num2.charAt(j)-'0')+pre;
             cur = now % 10;
             pre = now / 10;
             strBuffer.append(cur);
             i--;
             j--;
         }
         while(i>=0){
             now = (num1.charAt(i)-'0')+pre;
             cur = now % 10;
             pre = now / 10;
             strBuffer.append(cur);
             i--;
         }
         while(j>=0){
             now = (num2.charAt(j)-'0')+pre;
             cur = now % 10;
             pre = now / 10;
             strBuffer.append(cur);
             j--;
         }
         while(pre!=0){
             cur = pre % 10;
             pre = pre / 10;
             strBuffer.append(cur);
         }
         return strBuffer.reverse().toString();
     }
 }
 */
