/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ¡¶½£Ö¸Offer¡ª¡ªÃûÆóÃæÊÔ¹Ù¾«½²µäÐÍ±à³ÌÌâ¡·´úÂë
// ×÷Õß£ººÎº£ÌÎ
//==================================================================

// ÃæÊÔÌâ50£¨¶þ£©£º×Ö·ûÁ÷ÖÐµÚÒ»¸öÖ»³öÏÖÒ»´ÎµÄ×Ö·û
// ÌâÄ¿£ºÇëÊµÏÖÒ»¸öº¯ÊýÓÃÀ´ÕÒ³ö×Ö·ûÁ÷ÖÐµÚÒ»¸öÖ»³öÏÖÒ»´ÎµÄ×Ö·û¡£ÀýÈç£¬µ±´Ó
// ×Ö·ûÁ÷ÖÐÖ»¶Á³öÇ°Á½¸ö×Ö·û"go"Ê±£¬µÚÒ»¸öÖ»³öÏÖÒ»´ÎµÄ×Ö·ûÊÇ'g'¡£µ±´Ó¸Ã×Ö
// ·ûÁ÷ÖÐ¶Á³öÇ°Áù¸ö×Ö·û"google"Ê±£¬µÚÒ»¸öÖ»³öÏÖÒ»´ÎµÄ×Ö·ûÊÇ'l'¡£

#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

class CharStatistics
{
public:
    CharStatistics() : index(0)
    {
        for(int i = 0; i < 256; ++i)
            occurrence[i] = -1;
    }

    void Insert(char ch)
    {
        if(occurrence[ch] == -1)
            occurrence[ch] = index;
        else if(occurrence[ch] >= 0)
            occurrence[ch] = -2;

        index++;
    }

    char FirstAppearingOnce()
    {
        char ch = '\0';
        int minIndex = numeric_limits<int>::max();
        for(int i = 0; i < 256; ++i)
        {
            if(occurrence[i] >= 0 && occurrence[i] < minIndex)
            {
                ch = (char) i;
                minIndex = occurrence[i];
            }
        }

        return ch;
    }

private:
    // occurrence[i]: A character with ASCII value i;
    // occurrence[i] = -1: The character has not found;
    // occurrence[i] = -2: The character has been found for mutlple times
    // occurrence[i] >= 0: The character has been found only once
    int occurrence[256];
    int index;
};

// ====================²âÊÔ´úÂë====================
void Test(const char* testName, CharStatistics chars, char expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(chars.FirstAppearingOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    CharStatistics chars;

    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

    return 0;
}

