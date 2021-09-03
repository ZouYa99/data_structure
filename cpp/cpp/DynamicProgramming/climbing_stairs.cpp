//
//  climbing_stairs.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/30.
//

#include <stdio.h>
/*
 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 注意：给定 n 是一个正整数。
 */

class Solution {
public:
    int climbStairs(int n) {
        //动态规划：f(x)=f(x-1)+f(x-2)
        //f(0)=1,f(1)=1;
        int x0=0,x1=0,x2=1;
        for(int i=0;i<n;i++){
            x0=x1;
            x1=x2;
            x2=x0+x1;
        }
        return x2;
    }
};
