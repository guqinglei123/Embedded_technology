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
    char FirstNotRepeatingChar(string str)
    {
        if (str.empty())
            return '\0';
        int hashtable[256];
        for (int i = 0; i < 256; i++)
            hashtable[i] = 0;
        int str_index = 0;
        while (str_index < str.size())
        {
            hashtable[str[str_index]]++;
            str_index++;
        }
        str_index = 0;
        while (str_index < str.size())
        {
            if (hashtable[str[str_index]] == 1)
                return str[str_index];
            str_index++;
        }
        return '\0';
    }
};
class Test_Solution
{
  public:
    Solution Sol;
    void Test(const char *pString, char expected)
    {
        if (Sol.FirstNotRepeatingChar(pString) == expected)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
};
int main(int argc, char *argv[])
{
    Test_Solution test;
    // ³£¹æÊäÈë²âÊÔ£¬´æÔÚÖ»³öÏÖÒ»´ÎµÄ×Ö·û
    test.Test("google", 'l');

    // ³£¹æÊäÈë²âÊÔ£¬²»´æÔÚÖ»³öÏÖÒ»´ÎµÄ×Ö·û
    test.Test("aabccdbd", '\0');

    // ³£¹æÊäÈë²âÊÔ£¬ËùÓÐ×Ö·û¶¼Ö»³öÏÖÒ»´Î
    test.Test("abcdefg", 'a');

    // Â³°ôÐÔ²âÊÔ£¬ÊäÈënullptr
    // test.Test(nullptr, '\0');

    return 0;
}