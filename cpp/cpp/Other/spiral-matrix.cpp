//
//  spiral-matrix.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include <stdio.h>
#include <vector>
using namespace::std;
/*
 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(),column = matrix[0].size();
        vector<int> order;
        int left=0,right=column-1,top=0,bottom=row-1;
        while(left<=right&&top<=bottom){
            int i,j;
            for(i=left;i<=right;i++){
                order.push_back(matrix[top][i]);
            }
            for(j=top+1;j<=bottom;j++){
                order.push_back(matrix[j][right]);
            }
            if(left<right&&top<bottom){
                for(i=right-1;i>=left;i--){
                    order.push_back(matrix[bottom][i]);
                }
                for(j=bottom-1;j>top;j--){
                    order.push_back(matrix[j][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};
