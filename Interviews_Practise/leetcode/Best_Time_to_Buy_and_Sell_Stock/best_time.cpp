/***************************************************************************************************
����һ����121������Ʊ�����ʱ��������һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������
ע���㲻���������Ʊǰ������Ʊ��
˵����
    ����: [7,1,5,3,6,4]
    ���: 5
    ����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
        ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�
    ����: [7,6,4,3,1]
    ���: 0
    ����: �����������, û�н������, �����������Ϊ 0��
�ο����ӣ�https://blog.csdn.net/zaqwsx20/article/details/51082686
    https://blog.csdn.net/linhuanmars/article/details/23162793

���������������Ʊ�����ʱ�� 2������һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����
ע���㲻���������Ʊǰ������Ʊ��
˵����
    ����:[7,1,5,3,6,4]
    ���: 7
    ����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 3 �죨��Ʊ�۸� = 5����ʱ������, ��ʽ������ܻ������ = 5-1 = 4 ��
        ����ڵ� 4 �죨��Ʊ�۸� = 3����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ������, ��ʽ������ܻ������ = 6-3 = 3 ��
    ����: [1,2,3,4,5]
    ���: 4
    ����: �ڵ� 1 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �� ����Ʊ�۸� = 5����ʱ������, ��ʽ������ܻ������ = 5-1 = 4 ��
        ע���㲻���ڵ� 1 ��͵� 2 ����������Ʊ��֮���ٽ�����������
        ��Ϊ��������ͬʱ�����˶�ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ��
    ����: [7,6,4,3,1]
    ���: 0
    ����: �����������, û�н������, �����������Ϊ 0��
�ο����ӣ�https://blog.csdn.net/zaqwsx20/article/details/51082686

����������123/188������Ʊ�����ʱ�� 3/4������һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
����һ�����飬���ĵ� i ��Ԫ����һ֧�����Ĺ�Ʊ�ڵ� i ��ļ۸�
���һ���㷨�����������ܻ�ȡ�������������������� k �ʽ��ף���k=2ʱ��Ϊ������Ʊ�����ʱ��3����
ע��: �㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ��
˵����
    ����: [2,4,1], k = 2
    ���: 2
    ����: �ڵ� 1 �� (��Ʊ�۸� = 2) ��ʱ�����룬�ڵ� 2 �� (��Ʊ�۸� = 4) ��ʱ����������ʽ������ܻ������ = 4-2 = 2 ��
    ����: [3,2,6,5,0,3], k = 2
    ���: 7
    ����: �ڵ� 2 �� (��Ʊ�۸� = 2) ��ʱ�����룬�ڵ� 3 �� (��Ʊ�۸� = 6) ��ʱ������, ��ʽ������ܻ������ = 6-2 = 4 ��
        ����ڵ� 5 �� (��Ʊ�۸� = 0) ��ʱ�����룬�ڵ� 6 �� (��Ʊ�۸� = 3) ��ʱ������, ��ʽ������ܻ������ = 3-0 = 3 ��
�ο����ӣ�https://blog.csdn.net/zaqwsx20/article/details/51082686
    http://www.cnblogs.com/grandyang/p/4281975.html
    http://www.cnblogs.com/grandyang/p/4295761.html
    http://blog.csdn.net/linhuanmars/article/details/23236995

�����ģ�(309���������Ʊʱ�����䶳��)���һ���㷨����������������������Լ�������£�����Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ��:
        �㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
        ������Ʊ�����޷��ڵڶ��������Ʊ (���䶳��Ϊ 1 ��)��
˵����
    prices = [1, 2, 3, 0, 2]
    maxProfit = 3
    transactions = [buy, sell, cooldown, buy, sell]
�ο����ӣ�http://www.cnblogs.com/grandyang/p/4997417.html

������:(714������Ʊ�����ʱ����������)����һ���������� prices�����е� i ��Ԫ�ش����˵� i ��Ĺ�Ʊ�۸� ���Ǹ����� fee �����˽��׹�Ʊ���������á�
��������޴ε���ɽ��ף�������ÿ�ν��׶���Ҫ�������ѡ�������Ѿ�������һ����Ʊ����������֮ǰ��Ͳ����ټ��������Ʊ�ˡ�
���ػ����������ֵ��
˵��:
    ����: prices = [1, 3, 2, 8, 4, 9], fee = 2
���: 8
����: �ܹ��ﵽ���������:  
    �ڴ˴����� prices[0] = 1
    �ڴ˴����� prices[3] = 8
    �ڴ˴����� prices[4] = 4
    �ڴ˴����� prices[5] = 9
    ������: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
    0 < prices.length <= 50000.
    0 < prices[i] < 50000.
    0 <= fee < 50000.
�ο����ӣ�

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
    //����һ
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
            else if ((prices[i] - buy_time) > res) //�޸�Ϊ ������������������������ʱ��
            {
                res = prices[i] - buy_time;
            }
        }
        return res;
    }
    int maxProfit_dp(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        int local = 0;
        int global = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            local = max(local + prices[i + 1] - prices[i], 0);//�ֲ�����
            global = max(local, global);//ȫ������
        }
        return global;
    }
    //�����
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
        { //ֻҪ��Ǯ׬������
            d = prices[i] - prices[i - 1];
            if (d > 0)
            {
                max += d;
            }
        }
        return max;
    }
    //������
    struct Sub
    { //��������
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
    //����������
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
    //����������
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
            //Ѱ��һ�����������з�
            int maxCount = 0;
            int maxIndex = -1;
            Sub maxSub;
            Sub tmpSub;
            for (int i = 0; i < subArr.size(); ++i)
            {
                int tmp;
                if (subArr[i].fill)
                { //��ʵ������������һ����Сֵ
                    tmp = maxProfit_r(prices, subArr[i].begin, subArr[i].end, tmpSub);
                }
                else
                { //�ڿ����������������������
                    tmp = maxProfit_p(prices, subArr[i].begin, subArr[i].end, tmpSub);
                }
                if (tmp > maxCount)
                { //��¼�µ�ǰ��ѻ��ַ�ʽ�������������
                    maxCount = tmp;
                    maxIndex = i;
                    maxSub = tmpSub;
                }
            }

            //�����з�֮�������״̬
            if (maxIndex >= 0)
            {
                Sub sub = subArr[maxIndex];
                if (sub.fill) //�������֮�󣬻��ֵ���⡣
                {
                    subArr.push_back(Sub(sub.begin, maxSub.begin, true));
                    subArr.push_back(Sub(maxSub.end, sub.end, true));
                    maxSub.begin += 1;
                    maxSub.end -= 1;
                    subArr[maxIndex] = maxSub; //Ĭ��Ϊture
                }
                else
                {
                    subArr.push_back(Sub(sub.begin, maxSub.begin - 1, false));
                    subArr.push_back(Sub(maxSub.end + 1, sub.end, false));
                    subArr[maxIndex] = maxSub;
                }
                //����˴��з�֮����������
                max += maxCount;
            }
            else
            { //���޷����з����˳�ѭ��
                break;
            }
        }
        return max;
    }
    //ʹ�ö�̬�滮�㷨~
    //���k��ֵԶ����prices������������k�Ǻü����򣬶�prices��������Ϊ������Ļ���ʹ��DP�ⷨ�ͷǳ���û��Ч��
    //��ʱ�����ѡ���������̰�Ľⷨ
    int maxProfit3_2dp(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int n = prices.size();
        int g[n][3]= {0}, l[n][3]= {0} ;//����д����linux��֪��Ϊʲô�������⣿

        for (int i = 1; i < prices.size(); ++i)
        {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j)
            {
                l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
                g[i][j] = max(l[i][j], g[i - 1][j]);
            }
        }
        return g[n - 1][2];
    }
        //�ռ��Ż�
    int maxProfit3_2dp2(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int g[3] = {0};
        int l[3] = {0};
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            int diff = prices[i + 1] - prices[i];
            for (int j = 2; j >= 1; --j)
            {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(l[j], g[j]);
            }
        }
        return g[2];
    }

    int maxProfit3_dp2k(int k, vector<int> &prices) 
    {
        if (prices.empty()) return 0;
        if (k >= prices.size()) return solveMaxProfit(prices);
        int g[k + 1]= {0};//����д����linux��֪��Ϊʲô�������⣿
        int l[k + 1]= {0};
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }

    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }



    int maxProfit4(vector<int> &prices)
    {

    }
    int maxProfit5(vector<int> &prices, int fee)
    {
        
    }
};

int main(void)
{
    vector<int> prices;
    // prices = {7, 1, 5, 3, 6, 4};
    // prices = {7, 6, 4, 3, 1};
    prices = {1, 2, 3, 4, 5};
    // prices = {7,6,4,3,1};
    // prices = {3, 3, 5, 0, 0, 3, 1, 4};
    // prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0}; //13
    // prices = {2, 4, 1};
    // prices = {3, 2, 6, 5, 0, 3};

    Solution Sol;
    int max_price = Sol.maxProfit(prices);
    cout << "����һ�Ľ⣺" << max_price << endl;
    max_price = Sol.maxProfit_dp(prices);
    cout << "����һ�Ķ�̬�滮�ⷨ��" << max_price << endl;
    max_price = Sol.maxProfit2(prices);
    cout << "������Ľ⣺" << max_price << endl;
    max_price = Sol.maxProfit2_Greed(prices);
    cout << "�������̰�Ľⷨ��" << max_price << endl;
    max_price = Sol.maxProfit3(2, prices);
    cout << "�������Ľ⣺" << max_price << endl;
    max_price = Sol.maxProfit3_2dp(prices);
    cout << "������(k=2)�Ķ�̬�滮�ⷨ��" << max_price << endl;//��������
    max_price = Sol.maxProfit3_2dp2(prices);
    cout << "������(k=2)���Ż���̬�滮�ⷨ��" << max_price << endl;
    max_price = Sol.maxProfit3_dp2k(2,prices);
    cout << "���������Ż���̬�滮�ⷨ��" << max_price << endl;//��������
    return 0;
}