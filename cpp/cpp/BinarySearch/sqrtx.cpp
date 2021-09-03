//
//  sqrtx.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/30.
//

#include <stdio.h>
#include <math.h>
/*
 计算并返回 x 的平方根，其中 x 是非负整数。
 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 */

class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
    //  MARK: - 二分查找法
    //     int i=0,j=x,ans;
    //     while(i<=j){
    //         int m = i+((j-i)>>1);
    //         if((long long)m*m<=x){
    //             ans = m;
    //             i = m+1;
    //         }else{
    //             j = m-1;
    //         }
    //     }
    //     return ans;
    //  MARK: - 牛顿迭代法
    //  画出方程对应的曲线，寻找零点，先取一个点，
    //  过该点做曲线的切线，再取其零点，依次往下，知道两个点之间相差很小，则为对应点
    //  第一个点取为x
    /*
     abs()主要用于对求整数的绝对值，在“stdlib.h”(或 <cstdlib>)头文件里面。
     而fabs()主要是求精度要求更高的double ，float 型的绝对值，
     在<cmath>头文件里。
     两者在只#include<cmath>时都可以使用。*/
        double C = x,x0=x,x1=x;
        while(true){
            //通过切线方程得到的零点公式
            x1 = (x0 + C/x0)*0.5;
            if(fabs(x0-x1)<1e-7){
                break;
            }
            x0 = x1;
        }
        return (int)x0;
    }
};

