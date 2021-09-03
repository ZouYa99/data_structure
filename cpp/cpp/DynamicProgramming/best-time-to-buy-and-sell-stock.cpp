//
//  best-time-to-buy-and-sell-stock.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/4.
//

#include <stdio.h>
#include <vector>
using namespace::std;
/*
 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。
 设计一个算法来计算你所能获取的最大利润。
 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int min = prices[0];
        int profit = 0;
        for(int i=1;i<size;i++){
            int cur=prices[i];
            if(cur<min){
                min=cur;
            }else{
                cur=cur-min;
                profit=cur>profit?cur:profit;
            }
        }
        return profit;
    }
};
