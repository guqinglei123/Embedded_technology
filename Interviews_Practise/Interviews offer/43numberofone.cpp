#include <vector>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstring>
using namespace std;
class Solution
{
  public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n == 0)
            return 0;
        int res = 1;
        int num_bit = 1;//该数字的位数
        int num_nbit = n;//最高数为多少
        while (num_nbit >= 10)//统计位数
        {
            num_bit++;
            num_nbit = num_nbit / 10;
        }
        if (num_bit == 1)
            return res;
        if (num_nbit > 1)
        {
            int res1 = num_nbit * (num_bit - 1) * pow(10, (num_bit - 2));//除去最高位，任固定一位为1，其他位数各取出0~10。
            int res2 = pow(10, (num_bit - 1));//最高位为1的时候有多少个情况
            int res3 = n - num_nbit * pow(10, (num_bit - 1));//除去最高位，剩下的数的大小
            res = res1 + res2 + NumberOf1Between1AndN_Solution(res3);
        }
        else
        {
            int res1 = (num_bit - 1) * pow(10, (num_bit - 2));//除去最高位，任固定一位为1，其他位数各取出0~10。
            int res2 = n - num_nbit * pow(10, (num_bit - 1)) + 1;//最高位为1的时候有多少个情况
            int res3 = n - num_nbit * pow(10, (num_bit - 1));//除去最高位，剩下的数的大小
            res = res1 + res2 + NumberOf1Between1AndN_Solution(res3);
        }
        return res;
    }
    int NumberOf1Between1AndN_Solution2(int n) //从1～n，不断直接累加1的次数
    {
    }
};
class Test_Solution
{
  public:
    Solution Sol;
    void Test(const char *testName, int n, int expected)
    {
        if (testName != nullptr)
            printf("%s begins: \n", testName);

        if (Sol.NumberOf1Between1AndN_Solution(n) == expected)
            printf("Solution1 passed.\n");
        else
            printf("Solution1 failed.\n");

        if (Sol.NumberOf1Between1AndN_Solution2(n) == expected)
            printf("Solution2 passed.\n");
        else
            printf("Solution2 failed.\n");

        printf("\n");
    }

    void Test()
    {
        Test("Test1", 1, 1);
        Test("Test2", 5, 1);
        Test("Test3", 10, 2);
        Test("Test4", 55, 16);
        Test("Test5", 99, 20);
        Test("Test6", 10000, 4001);
        Test("Test7", 21345, 18821);
        Test("Test8", 0, 0);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Test_Solution test;
    test.Test();
    return 0;
}
