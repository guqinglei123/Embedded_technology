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
    int getMaxValue_solution(vector<vector<int>> &maxtrix_values)
    {
        if (maxtrix_values.empty())
            return 0;
        int rows = maxtrix_values.size();
        int cols = maxtrix_values[0].size();
        int *values = new int[cols];
        int i = 0, j = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                int val1 = 0, val2 = 0;
                if (i > 0)
                    val1 = values[j];
                if (j > 0)
                    val2 = values[j - 1];
                values[j] = max(val1, val2) + maxtrix_values[i][j];
            }
        int res = values[cols - 1];
        delete[] values;
        return res;
    }
    int getMaxValue_solution2(vector<vector<int>> &maxtrix_values)
    {
    }
};
class Test_Solution
{
  public:
    Solution Sol;
    void test(const char *testName, const int *values, int rows, int cols, int expected)
    {
        vector<vector<int>> maxtrix_values;
        for (int i = 0; i < rows; i++)
        {
            vector<int> vector_temp;
            for (int j = 0; j < cols; j++)
                vector_temp.push_back(*(values + i * cols + j));
            maxtrix_values.push_back(vector_temp);
        }

        if (Sol.getMaxValue_solution(maxtrix_values) == expected)
            std::cout << testName << ": solution1 passed." << std::endl;
        else
            std::cout << testName << ": solution1 FAILED." << std::endl;

        if (Sol.getMaxValue_solution2(maxtrix_values) == expected)
            std::cout << testName << ": solution2 passed." << std::endl;
        else
            std::cout << testName << ": solution2 FAILED." << std::endl;
    }

    void Test1()
    {
        // ÃˆÃ½Ã�Ã�ÃˆÃ½Ã�Ã�
        int values[][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
        int expected = 29;
        test("test1", (const int *)values, 3, 3, expected);
    }

    void Test2()
    {
        //Ã‹Ã„Ã�Ã�Ã‹Ã„Ã�Ã�
        int values[][4] = {
            {1, 10, 3, 8},
            {12, 2, 9, 6},
            {5, 7, 4, 11},
            {3, 7, 16, 5}};
        int expected = 53;
        test("test2", (const int *)values, 4, 4, expected);
    }

    void Test3()
    {
        // Ã’Â»Ã�Ã�Ã‹Ã„Ã�Ã�
        int values[][4] = {
            {1, 10, 3, 8}};
        int expected = 22;
        test("test3", (const int *)values, 1, 4, expected);
    }

    void Test4()
    {
        int values[4][1] = {
            {1},
            {12},
            {5},
            {3}};
        int expected = 21;
        test("test4", (const int *)values, 4, 1, expected);
    }

    void Test5()
    {
        // Ã’Â»Ã�Ã�Ã’Â»Ã�Ã�
        int values[][1] = {
            {3}};
        int expected = 3;
        test("test5", (const int *)values, 1, 1, expected);
    }

    void Test6()
    {
        // Â¿Ã•Ã–Â¸Ã•Ã«
        int expected = 0;
        test("test6", nullptr, 0, 0, expected);
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