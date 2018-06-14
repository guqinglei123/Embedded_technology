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
    bool g_InvalidInput = false;
    int FindGreatestSumOfSubArray(vector<int> nums)
    {
        g_InvalidInput = true;
        if(nums.empty())
            return  0;
        g_InvalidInput = false;
        if (nums.size() <= 1)
            return nums[0];

        int l = nums[0];
        int g = nums[0];
        for (int i = 1; i < nums.size(); i++) //修改为 条件运算符来表达可以提高运行时间
        {
            l = max(l + nums[i], nums[i]);
            g = max(g, l);
        }
        return g;
    }
};

class Test_Solution
{
  public:
    Solution Sol;
    void Test(char *testName, int *pData, int nLength, int expected, bool expectedFlag)
    {
        if (testName != nullptr)
            printf("%s begins: \n", testName);
        vector<int> pData_vec;
        for (int i = 0; i < nLength; i++)
            pData_vec.push_back(pData[i]);

        int result = Sol.FindGreatestSumOfSubArray(pData_vec);
        if (result == expected && expectedFlag == Sol.g_InvalidInput)
            printf("Passed.\n");
        else
            printf("Failed.\n");
    }

    // 1, -2, 3, 10, -4, 7, 2, -5
    void Test1()
    {
        int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
        Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
    }

    // ËùÓÐÊý×Ö¶¼ÊÇ¸ºÊý
    // -2, -8, -1, -5, -9
    void Test2()
    {
        int data[] = {-2, -8, -1, -5, -9};
        Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
    }

    // ËùÓÐÊý×Ö¶¼ÊÇÕýÊý
    // 2, 8, 1, 5, 9
    void Test3()
    {
        int data[] = {2, 8, 1, 5, 9};
        Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
    }

    // ÎÞÐ§ÊäÈë
    void Test4()
    {
        Test("Test4", nullptr, 0, 0, true);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Test_Solution test;
    test.Test1();
    test.Test2();
    test.Test3();
    test.Test4();
    return 0;
}
