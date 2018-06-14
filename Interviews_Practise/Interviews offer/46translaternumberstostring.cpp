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
    int GetTranslationCount(int number)
    {
        if (number < 0)
            return 0;
        string str_num = to_string(number);
        return help(str_num, 0, str_num.size() - 1);
    }
    int help(string &str_num, int begin, int end)
    {
        int res;
        if (begin == end)//递归基
            return 1;
        string str_temp(str_num, begin, 2);  
        if (end - begin == 1)
        {
                           //复制两位数据出来
            if ((stoi(str_temp) > 25) || (stoi(str_temp) < 10)) //注意小于10的也不能算两次
                res = 1;
            else
                res = 2;
            return res;
        }
        return ((stoi(str_temp) <= 25) && (stoi(str_temp) >= 10)) ? (help(str_num, begin + 1, end) + help(str_num, begin + 2, end)) : help(str_num, begin + 1, end);
    }
};

class Test_Solution
{
  public:
    Solution Sol;
    void Test(const string &testName, int number, int expected)
    {
        if (Sol.GetTranslationCount(number) == expected)
            cout << testName << " passed." << endl;
        else
            cout << testName << " FAILED." << endl;
    }

    void Test1()
    {
        int number = 0;
        int expected = 1;
        Test("Test1", number, expected);
    }

    void Test2()
    {
        int number = 10;
        int expected = 2;
        Test("Test2", number, expected);
    }

    void Test3()
    {
        int number = 125;
        int expected = 3;
        Test("Test3", number, expected);
    }

    void Test4()
    {
        int number = 126;
        int expected = 2;
        Test("Test4", number, expected);
    }

    void Test5()
    {
        int number = 426;
        int expected = 1;
        Test("Test5", number, expected);
    }

    void Test6()
    {
        int number = 100;
        int expected = 2;
        Test("Test6", number, expected);
    }

    void Test7()
    {
        int number = 101;
        int expected = 2;
        Test("Test7", number, expected);
    }

    void Test8()
    {
        int number = 12258;
        int expected = 5;
        Test("Test8", number, expected);
    }

    void Test9()
    {
        int number = -100;
        int expected = 0;
        Test("Test9", number, expected);
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
    test.Test7();
    test.Test8();
    test.Test9();
    return 0;
}
