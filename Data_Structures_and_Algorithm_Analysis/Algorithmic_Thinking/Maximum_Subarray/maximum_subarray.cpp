/***************************************************************************************************
 * 问题一：(53最大子序和)给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
说明：
    输入: [-2,1,-3,4,-1,2,1,-5,4],
    输出: 6
    解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
相关链接：https://blog.csdn.net/linhuanmars/article/details/21314059
 * ********************************************************************************************/

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums[0];
            
        int l=nums[0];
        int g=nums[0];
        for (int i = 1; i < nums.size(); i++)//修改为 条件运算符来表达可以提高运行时间
        {
            l = max(l+nums[i],nums[i]);
            g = max(g,l);
        }
        return g;
    }
};
 
int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums;
    nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution Sol;
    int res = Sol.maxSubArray(nums);
    cout << "" << res <<endl;

    return 0;
}
