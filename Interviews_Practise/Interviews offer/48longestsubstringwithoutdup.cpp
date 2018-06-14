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
    int longestSubstringWithoutDuplication(const std::string &input)
    {
        if(input.empty())
            return 0;
        int begin = 0;
        int max_local= 0,max_global = 1;
        for (int i = 1; i < input.size(); i++)
        {
            int same_index = data_find(input, begin, i, input[i]);
            if (same_index == -1)
            {
                max_global++;
            }
            else
            {
                max_local = max(max_local, (i - begin));
                begin = same_index + 1;
                max_global = max_global - same_index;
            }
        }
        return max(max_local,max_global);
    }
    int data_find(const std::string &input, int begin, int end, int goal)
    {
        for (int j = begin; j < end; j++)
        {
            if (input[j] == goal)
            {
                return j;
            }
        }
        return -1;
    }
    int longestSubstringWithoutDuplication_2(const std::string &input)
    {
    }
};
class Test_Solution
{
  public:
    Solution Sol;
    void testSolution1(const std::string &input, int expected)
    {
        int output = Sol.longestSubstringWithoutDuplication(input);
        if (output == expected)
            std::cout << "Solution 1 passed, with input: " << input << std::endl;
        else
            std::cout << "Solution 1 FAILED, with input: " << input << std::endl;
    }

    void testSolution2(const std::string &input, int expected)
    {
        int output = Sol.longestSubstringWithoutDuplication_2(input);
        if (output == expected)
            std::cout << "Solution 2 passed, with input: " << input << std::endl;
        else
            std::cout << "Solution 2 FAILED, with input: " << input << std::endl;
    }

    void test(const std::string &input, int expected)
    {
        testSolution1(input, expected);
        testSolution2(input, expected);
    }

    void test1()
    {
        const std::string input = "abcacfrar";
        int expected = 4;
        test(input, expected);
    }

    void test2()
    {
        const std::string input = "acfrarabc";
        int expected = 4;
        test(input, expected);
    }

    void test3()
    {
        const std::string input = "arabcacfr";
        int expected = 4;
        test(input, expected);
    }

    void test4()
    {
        const std::string input = "aaaa";
        int expected = 1;
        test(input, expected);
    }

    void test5()
    {
        const std::string input = "abcdefg";
        int expected = 7;
        test(input, expected);
    }

    void test6()
    {
        const std::string input = "aaabbbccc";
        int expected = 2;
        test(input, expected);
    }

    void test7()
    {
        const std::string input = "abcdcba";
        int expected = 4;
        test(input, expected);
    }

    void test8()
    {
        const std::string input = "abcdaef";
        int expected = 6;
        test(input, expected);
    }

    void test9()
    {
        const std::string input = "a";
        int expected = 1;
        test(input, expected);
    }

    void test10()
    {
        const std::string input = "";
        int expected = 0;
        test(input, expected);
    }
};
int main(int argc, char *argv[])
{
    Test_Solution test;
    test.test1();
    test.test2();
    test.test3();
    test.test4();
    test.test5();
    test.test6();
    test.test7();
    test.test8();
    test.test9();
    test.test10();
    return 0;
}