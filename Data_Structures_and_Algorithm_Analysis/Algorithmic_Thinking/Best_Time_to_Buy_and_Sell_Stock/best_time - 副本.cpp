/***************************************************************************************************
问题一：（买卖股票的最佳时机）给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
注意你不能在买入股票前卖出股票。
说明：
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
参考链接：

问题二：（买卖股票的最佳时机 2）给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意你不能在买入股票前卖出股票。
说明：
输入:[7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
参考链接：

问题三：（买卖股票的最佳时机 3/4）给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易（当k=2时，为买卖股票的最佳时机3）。
注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
说明：
输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
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
    //问题一
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        if (prices.size() <= 1)
            return res;
        int buy_time = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < buy_time)
            {
                buy_time = prices[i];
            }
            else if ((prices[i] - buy_time) > res) //修改为 条件运算符来表达可以提高运行时间
            {
                res = prices[i] - buy_time;
            }
        }
        return res;
    }
    //问题二
    int maxProfit2(vector<int> &prices)
    {
        int res = 0;
        if (prices.size() <= 1)
            return res;
        int buy_time = prices[0];
        int sell_time = prices[0];
        int max_error = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < buy_time)
            {
                buy_time = prices[i];
            }
            else if ((prices[i] - buy_time) > max_error)
            {
                max_error = prices[i] - buy_time;
            }

            if ((prices[i] < prices[i - 1]) || (i == prices.size() - 1))
            {
                res = max_error + res;
                buy_time = prices[i];
                max_error = 0;
            }
        }
        return res;
    }

    int maxProfit2_Greed(vector<int> &prices)
    {
        // write your code here
        int i, d;
        int max = 0;
        for (i = 1; i < prices.size(); ++i)
        { //只要有钱赚就买卖
            d = prices[i] - prices[i - 1];
            if (d > 0)
            {
                max += d;
            }
        }
        return max;
    }
    //问题三
    struct Sub
    { //买卖区间
        int begin;
        int end;
        bool fill;

        Sub(int begin = 0, int end = 0, bool fill = true)
        {
            this->begin = begin;
            this->end = end;
            this->fill = fill;
        }
    };
    //正方向搜索
    int maxProfit_p(vector<int> &prices, int indiex_min, int indiex_max, Sub &sub)
    {
        int res = 0;
        sub.fill = true;
        if (prices.size() <= 1)
            return res;
        int buy_time;
        int index_buy_tmp;
        int max_error = 0;
        buy_time = prices[indiex_min];
        index_buy_tmp = indiex_min;
        sub.begin = indiex_min;
        sub.end = indiex_min;
        for (int i = indiex_min + 1; i <= indiex_max; i++)
        {
            if ((prices[i] < buy_time))
            {
                buy_time = prices[i];
                index_buy_tmp = i;
            }
            else if ((prices[i] - buy_time) > res)
            {
                res = prices[i] - buy_time;
                sub.begin = index_buy_tmp;
                sub.end = i;
            }
        }
        return res;
    }
    //反方向搜索
    int maxProfit_r(vector<int> &prices, int indiex_min, int indiex_max, Sub &sub)
    {
        int res = 0;
        sub.fill = false;
        if (prices.size() <= 1)
            return res;
        int buy_time;
        int max_error = 0;
        int index_buy_tmp;
        buy_time = prices[indiex_max];
        sub.begin = indiex_max;
        sub.end = indiex_max;

        for (int i = indiex_max - 1; i >= indiex_min; i--)
        {
            if ((prices[i] < buy_time))
            {
                buy_time = prices[i];
                index_buy_tmp = i;
            }
            else if ((prices[i] - buy_time) > res)
            {
                res = prices[i] - buy_time;
                sub.begin = i;
                sub.end = index_buy_tmp;
            }
        }
        return res;
    }

    int maxProfit3(int k, vector<int> &prices)
    {
        int max = 0;
        vector<Sub> subArr;
        subArr.push_back(Sub(0, prices.size() - 1, false));
        while (k--)
        {
            //寻找一次最有利的切分
            int maxCount = 0;
            int maxIndex = -1;
            Sub maxSub;
            Sub tmpSub;
            for (int i = 0; i < subArr.size(); ++i)
            {
                int tmp;
                if (subArr[i].fill)
                { //在实心区间上挖下一个最小值
                    tmp = maxProfit_r(prices, subArr[i].begin, subArr[i].end, tmpSub);
                }
                else
                { //在空心区间上找最大利润区间
                    tmp = maxProfit_p(prices, subArr[i].begin, subArr[i].end, tmpSub);
                }
                if (tmp > maxCount)
                { //记录下当前最佳划分方式和其带来的利润
                    maxCount = tmp;
                    maxIndex = i;
                    maxSub = tmpSub;
                }
            }

            //计算切分之后的区间状态
            if (maxIndex >= 0)
            {
                Sub sub = subArr[maxIndex];
                if (sub.fill) //反向求解之后，划分的求解。
                {
                    subArr.push_back(Sub(sub.begin, maxSub.begin, true));
                    subArr.push_back(Sub(maxSub.end, sub.end, true));
                    maxSub.begin += 1;
                    maxSub.end -= 1;
                    subArr[maxIndex] = maxSub; //默认为ture
                }
                else
                {
                    subArr.push_back(Sub(sub.begin, maxSub.begin - 1, false));
                    subArr.push_back(Sub(maxSub.end + 1, sub.end, false));
                    subArr[maxIndex] = maxSub;
                }
                //计算此次切分之后的最大利润
                max += maxCount;
            }
            else
            { //若无法再切分则退出循环
                break;
            }
        }
        return max;
    }
    //使用动态规划算法~
    //如果k的值远大于prices的天数，比如k是好几百万，而prices的天数就为若干天的话，使用DP解法就非常的没有效率
    //这时候可以选择问题二的贪心解法
    int maxProfit3_dp(int k, vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int n = prices.size(), g[n][3] = {0}, l[n][3] = {0};
        for (int i = 1; i < prices.size(); ++i)
        {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; ++j)
            {
                l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
                g[i][j] = max(l[i][j], g[i - 1][j]);
            }
        }
        return g[n - 1][k];
    }
    //空间优化
    int maxProfit3_dp2(int k, vector<int> &prices)
    {
        if (prices.empty()) return 0;
        int g[3] = {0};
        int l[3] = {0};
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(l[j], g[j]);
            }
        }
        return g[k];
    }
};

int main(void)
{
    vector<int> prices;
    // prices = {7, 1, 5, 3, 6, 4};
    // prices = {7, 6, 4, 3, 1};
    // prices = {1, 2, 3, 4, 5};
    // prices = {7,6,4,3,1};
    // prices = {3,3,5,0,0,3,1,4};
    // prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0}; //13
    prices = {2, 4, 1};
    // prices = {3, 2, 6, 5, 0, 3};

    Solution Sol;
    int max_price = Sol.maxProfit(prices);
    cout << "问题一" << max_price << endl;
    max_price = Sol.maxProfit2(prices);
    cout << "问题二" << max_price << endl;
    max_price = Sol.maxProfit2_Greed(prices);
    cout << "问题二（贪心解法）" << max_price << endl;
    max_price = Sol.maxProfit3(2, prices);
    cout << "问题三" << max_price << endl;
    max_price = Sol.maxProfit3_dp(2, prices);
    cout << "问题三(动态规划)" << max_price << endl;
    max_price = Sol.maxProfit3_dp2(2, prices);
    cout << "问题三(优化后动态规划)" << max_price << endl;
    return 0;
}