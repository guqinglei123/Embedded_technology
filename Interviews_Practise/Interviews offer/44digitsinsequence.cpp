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
    int digitAtIndex(int Index)
    {
        if (Index < 10)
            return Index;
        int res = 0;
        int num_bit = 1; //该数字的位数
        int max_Index = 10;
        int num_Index = 10;
        while (Index >= max_Index) //得到在该位上数字为几位数
        {
            num_Index = max_Index;
            num_bit++;
            max_Index = max_Index + num_bit * (pow(10, num_bit) - pow(10, (num_bit - 1)));
        }
        
        int num_begin = pow(10, (num_bit - 1)) + (Index - num_Index) / num_bit; //得到该数字，等于该10^n-1 + 第几个数
        int diff_Index = num_bit - (Index - num_Index) % num_bit; //得到该位是该数字的第几位
        for (int i = 0; i < (diff_Index - 1); i++)
            num_begin = num_begin / 10;
        res = num_begin % 10;
        return res;
    }
};
class Test_Solution
{
  public:
    Solution Sol;
    void Test(const char *testName, int inputIndex, int expectedOutput)
    {
        if (Sol.digitAtIndex(inputIndex) == expectedOutput)
            cout << testName << " passed." << endl;
        else
            cout << testName << " FAILED." << endl;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Test_Solution test;
    test.Test("Test1", 0, 0);
    test.Test("Test2", 1, 1);
    test.Test("Test3", 9, 9);
    test.Test("Test4", 10, 1);
    test.Test("Test5", 189, 9);  // Êý×Ö99µÄ×îºóÒ»Î»£¬9
    test.Test("Test6", 190, 1);  // Êý×Ö100µÄµÚÒ»Î»£¬1
    test.Test("Test7", 1000, 3); // Êý×Ö370µÄµÚÒ»Î»£¬3
    test.Test("Test8", 1001, 7); // Êý×Ö370µÄµÚ¶þÎ»£¬7
    test.Test("Test9", 1002, 0); // Êý×Ö370µÄµÚÈýÎ»£¬0
    return 0;
}
