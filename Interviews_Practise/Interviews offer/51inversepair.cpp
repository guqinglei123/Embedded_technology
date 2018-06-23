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
#include "mylist.h"
using namespace std;
class Solution
{
  public:
    long long InversePairs(vector<int> data)
    {
        if (data.empty())
            return 0;
        long long res = help(data, 0, data.size() - 1);
        return res;
    }
    long long help(vector<int> &data, int begins, int end)
    {
        long long res = 0, res1 = 0, res2 = 0, res3 = 0;
        if (begins < end)
        {
            int mid = (end + begins) / 2;
            res1 = help(data, begins, mid);
            res2 = help(data, mid + 1, end);
            res3 = InversePairsCore(data, begins, mid, end);
        }
        res = res1 + res2 + res3;
        return res;
    }
    long long InversePairsCore(vector<int> &data, int begins, int mid, int end)
    {
        long long res = 0;
        int m = begins, n = mid + 1;
        int i = mid, j = end;
        vector<int> temp_sort(end - begins + 1, 0);
        int k = end - begins;
        while (i >= m && j >= n)
        {
            if (data[i] <= data[j])
                temp_sort[k--] = data[j--];
            else
            {
                temp_sort[k--] = data[i--];
                res = res + j - mid;
            }
        }
        while (i >= m)
        {
            temp_sort[k--] = data[i--];
        }

        while (j >= n)
        {
            temp_sort[k--] = data[j--];
        }

        for (i = 0; i <= (end - begins); i++)
            data[begins + i] = temp_sort[i];
        return res;
        //     int res = 0;
        //     if (end - begins == 1)
        //     {
        //         if (data[begins] > data[end])
        //         {
        //             int temp = data[begins];
        //             data[begins] = data[end];
        //             data[end] = temp;
        //             res = 1;
        //             return res;
        //         }
        //     }
        //     else
        //     {
        //         int i = begins, j = mid + 1;
        //         int m = mid, n = end;
        //         vector<int> temp_sort(end - begins + 1, 0);
        //         int k = 0;
        //         while (i <= m && j <= n)
        //         {
        //             if (data[i] <= data[j])
        //                 temp_sort[k++] = data[i++];
        //             else
        //             {
        //                 temp_sort[k++] = data[j++];
        //                 res = res + end - j + 1;
        //             }
        //         }
        //         while (i <= m)
        //         {
        //             temp_sort[k++] = data[i++];
        //             res = res + (end - mid + 1);
        //         }

        //         while (j <= n)
        //         {
        //             temp_sort[k++] = data[j++];
        //         }

        //         for (i = 0; i < k; i++)
        //             data[begins + i] = temp_sort[i];
        //     }
        //     return res;
    }
};
class Test_Solution
{
  public:
    Solution Sol;
    void Test(char *testName, int *data, int length, int expected)
    {
        if (testName != nullptr)
            printf("%s begins: ", testName);
        vector<int> data_vect;
        for (int i = 0; i < length; i++)
            data_vect.push_back(data[i]);
        if (Sol.InversePairs(data_vect) == expected)
            printf("Passed.\n");
        else
            printf("Failed.\n");
    }

    void Test1()
    {
        int data[] = {1, 2, 3, 4, 7, 6, 5};
        int expected = 3;

        Test("Test1", data, sizeof(data) / sizeof(int), expected);
    }

    // µÝ¼õÅÅÐòÊý×é
    void Test2()
    {
        int data[] = {6, 5, 4, 3, 2, 1};
        int expected = 15;

        Test("Test2", data, sizeof(data) / sizeof(int), expected);
    }

    // µÝÔöÅÅÐòÊý×é
    void Test3()
    {
        int data[] = {1, 2, 3, 4, 5, 6};
        int expected = 0;

        Test("Test3", data, sizeof(data) / sizeof(int), expected);
    }

    // Êý×éÖÐÖ»ÓÐÒ»¸öÊý×Ö
    void Test4()
    {
        int data[] = {1};
        int expected = 0;

        Test("Test4", data, sizeof(data) / sizeof(int), expected);
    }

    // Êý×éÖÐÖ»ÓÐÁ½¸öÊý×Ö£¬µÝÔöÅÅÐò
    void Test5()
    {
        int data[] = {1, 2};
        int expected = 0;

        Test("Test5", data, sizeof(data) / sizeof(int), expected);
    }

    // Êý×éÖÐÖ»ÓÐÁ½¸öÊý×Ö£¬µÝ¼õÅÅÐò
    void Test6()
    {
        int data[] = {2, 1};
        int expected = 1;

        Test("Test6", data, sizeof(data) / sizeof(int), expected);
    }

    // Êý×éÖÐÓÐÏàµÈµÄÊý×Ö
    void Test7()
    {
        int data[] = {1, 2, 1, 2, 1};
        int expected = 3;

        Test("Test7", data, sizeof(data) / sizeof(int), expected);
    }

    void Test8()
    {
        int expected = 0;

        Test("Test8", nullptr, 0, expected);
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
    test.Test5();
    test.Test6();
    test.Test7();
    test.Test8();
    return 0;
}