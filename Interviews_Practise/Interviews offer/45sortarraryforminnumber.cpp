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
    string PrintMinNumber(vector<int> numbers)
    {
        string res_str;
        if (numbers.empty())
            return res_str;
        if (numbers.size() == 1)
            return to_string(numbers[0]);
        sort(numbers.begin(), numbers.end()); //注意要先排序
        string str_num = to_string(numbers[0]);
        for (int i = 1; i < numbers.size(); i++)
        {
            string str1 = str_num + to_string(numbers[i]);
            string str2 = to_string(numbers[i]) + str_num;
            if (str1 > str2)//注意不能直接比较两个整数，存在大数问题
                 str_num = str2;
            else
                 str_num = str1;
            // if (stoi(str1) > stoi(str2))//注意不能直接比较两个整数，存在大数问题
            //     str_num = str2;
            // else
            //     str_num = str1;
        }
        res_str = str_num;
        return res_str;
    }
};

class Test_Solution
{
  public:
    Solution Sol;
    void Test(const char *testName, int *numbers, int length, const char *expectedResult)
    {
        if (testName != nullptr)
            printf("%s begins:\n", testName);

        if (expectedResult != nullptr)
            printf("Expected result is: \t%s\n", expectedResult);
        vector<int> numbers_vect;
        for (int i = 0; i < length; i++)
            numbers_vect.push_back(numbers[i]);
        printf("Actual result is: \t");
        string res_str;
        res_str = Sol.PrintMinNumber(numbers_vect);
        cout << res_str << endl;
    }

    void Test1()
    {
        int numbers[] = {3, 5, 1, 4, 2};
        Test("Test1", numbers, sizeof(numbers) / sizeof(int), "12345");
    }

    void Test2()
    {
        int numbers[] = {3, 32, 321};
        Test("Test2", numbers, sizeof(numbers) / sizeof(int), "321323");
    }

    void Test3()
    {
        int numbers[] = {3, 323, 32123};
        Test("Test3", numbers, sizeof(numbers) / sizeof(int), "321233233");
    }

    void Test4()
    {
        int numbers[] = {1, 11, 111};
        Test("Test4", numbers, sizeof(numbers) / sizeof(int), "111111");
    }

    // Êý×éÖÐÖ»ÓÐÒ»¸öÊý×Ö
    void Test5()
    {
        int numbers[] = {321};
        Test("Test5", numbers, sizeof(numbers) / sizeof(int), "321");
    }

    void Test6()
    {
        Test("Test6", nullptr, 0, "Don't print anything.");
    }
};
int main(int argc, char *argv[])
{
    Test_Solution test;
    test.Test1();
    test.Test2();
    test.Test3();
    test.Test4();
    test.Test5();
    test.Test6();

    return 0;
}