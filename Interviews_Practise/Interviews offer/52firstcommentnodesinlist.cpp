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
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if ((pHead1 == NULL) || (pHead2 == NULL))
            return NULL;
        int length1 = getlistlength(pHead1);
        int length2 = getlistlength(pHead2);
        ListNode *pnode1 = pHead1;
        ListNode *pnode2 = pHead2;
        if (length2 > length1)
        {
            while (length1 != length2)
            {
                pnode2 = pnode2->next;
                length2--;
            }
        }
        else
        {
            while (length1 != length2)
            {
                pnode1 = pnode1->next;
                length1--;
            }
        }

        while (pnode1 != NULL)
        {
            if (pnode1 == pnode2)
                return pnode1;
            pnode1 = pnode1->next;
            pnode2 = pnode2->next;
        }
        return NULL;
    }
    int getlistlength(ListNode *pHead)
    {
        ListNode *pnode = pHead;
        int res = 0;
        while (pnode != NULL)
        {
            res++;
            pnode = pnode->next;
        }
        return res;
    }
};
class Test_Solution
{
  public:
    Solution Sol;
    MyList mylist;
    void Test(char *testName, ListNode *pHead1, ListNode *pHead2, ListNode *pExpected)
    {
        if (testName != nullptr)
            printf("%s begins: ", testName);

        ListNode *pResult = Sol.FindFirstCommonNode(pHead1, pHead2);
        if (pResult == pExpected)
            printf("Passed.\n");
        else
            printf("Failed.\n");
    }

    // µÚÒ»¸ö¹«¹²½áµãÔÚÁ´±íÖÐ¼ä
    // 1 - 2 - 3 \
//            6 - 7
    //     4 - 5 /
    void Test1()
    {
        ListNode *pNode1 = mylist.CreateListNode(1);
        ListNode *pNode2 = mylist.CreateListNode(2);
        ListNode *pNode3 = mylist.CreateListNode(3);
        ListNode *pNode4 = mylist.CreateListNode(4);
        ListNode *pNode5 = mylist.CreateListNode(5);
        ListNode *pNode6 = mylist.CreateListNode(6);
        ListNode *pNode7 = mylist.CreateListNode(7);

        mylist.ConnectListNodes(pNode1, pNode2);
        mylist.ConnectListNodes(pNode2, pNode3);
        mylist.ConnectListNodes(pNode3, pNode6);
        mylist.ConnectListNodes(pNode4, pNode5);
        mylist.ConnectListNodes(pNode5, pNode6);
        mylist.ConnectListNodes(pNode6, pNode7);

        Test("Test1", pNode1, pNode4, pNode6);

        DestroyNode(pNode1);
        DestroyNode(pNode2);
        DestroyNode(pNode3);
        DestroyNode(pNode4);
        DestroyNode(pNode5);
        DestroyNode(pNode6);
        DestroyNode(pNode7);
    }

    // Ã»ÓÐ¹«¹²½áµã
    // 1 - 2 - 3 - 4
    //
    // 5 - 6 - 7
    void Test2()
    {
        ListNode *pNode1 = mylist.CreateListNode(1);
        ListNode *pNode2 = mylist.CreateListNode(2);
        ListNode *pNode3 = mylist.CreateListNode(3);
        ListNode *pNode4 = mylist.CreateListNode(4);
        ListNode *pNode5 = mylist.CreateListNode(5);
        ListNode *pNode6 = mylist.CreateListNode(6);
        ListNode *pNode7 = mylist.CreateListNode(7);

        mylist.ConnectListNodes(pNode1, pNode2);
        mylist.ConnectListNodes(pNode2, pNode3);
        mylist.ConnectListNodes(pNode3, pNode4);
        mylist.ConnectListNodes(pNode5, pNode6);
        mylist.ConnectListNodes(pNode6, pNode7);

        Test("Test2", pNode1, pNode5, nullptr);

        mylist.DestroyList(pNode1);
        mylist.DestroyList(pNode5);
    }

    // ¹«¹²½áµãÊÇ×îºóÒ»¸ö½áµã
    // 1 - 2 - 3 - 4 \
//                7
    //         5 - 6 /
    void Test3()
    {
        ListNode *pNode1 = mylist.CreateListNode(1);
        ListNode *pNode2 = mylist.CreateListNode(2);
        ListNode *pNode3 = mylist.CreateListNode(3);
        ListNode *pNode4 = mylist.CreateListNode(4);
        ListNode *pNode5 = mylist.CreateListNode(5);
        ListNode *pNode6 = mylist.CreateListNode(6);
        ListNode *pNode7 = mylist.CreateListNode(7);

        mylist.ConnectListNodes(pNode1, pNode2);
        mylist.ConnectListNodes(pNode2, pNode3);
        mylist.ConnectListNodes(pNode3, pNode4);
        mylist.ConnectListNodes(pNode4, pNode7);
        mylist.ConnectListNodes(pNode5, pNode6);
        mylist.ConnectListNodes(pNode6, pNode7);

        Test("Test3", pNode1, pNode5, pNode7);

        DestroyNode(pNode1);
        DestroyNode(pNode2);
        DestroyNode(pNode3);
        DestroyNode(pNode4);
        DestroyNode(pNode5);
        DestroyNode(pNode6);
        DestroyNode(pNode7);
    }

    // ¹«¹²½áµãÊÇµÚÒ»¸ö½áµã
    // 1 - 2 - 3 - 4 - 5
    // Á½¸öÁ´±íÍêÈ«ÖØºÏ
    void Test4()
    {
        ListNode *pNode1 = mylist.CreateListNode(1);
        ListNode *pNode2 = mylist.CreateListNode(2);
        ListNode *pNode3 = mylist.CreateListNode(3);
        ListNode *pNode4 = mylist.CreateListNode(4);
        ListNode *pNode5 = mylist.CreateListNode(5);

        mylist.ConnectListNodes(pNode1, pNode2);
        mylist.ConnectListNodes(pNode2, pNode3);
        mylist.ConnectListNodes(pNode3, pNode4);
        mylist.ConnectListNodes(pNode4, pNode5);

        Test("Test4", pNode1, pNode1, pNode1);

        mylist.DestroyList(pNode1);
    }

    // ÊäÈëµÄÁ½¸öÁ´±íÓÐÒ»¸ö¿ÕÁ´±í
    void Test5()
    {
        ListNode *pNode1 = mylist.CreateListNode(1);
        ListNode *pNode2 = mylist.CreateListNode(2);
        ListNode *pNode3 = mylist.CreateListNode(3);
        ListNode *pNode4 = mylist.CreateListNode(4);
        ListNode *pNode5 = mylist.CreateListNode(5);

        mylist.ConnectListNodes(pNode1, pNode2);
        mylist.ConnectListNodes(pNode2, pNode3);
        mylist.ConnectListNodes(pNode3, pNode4);
        mylist.ConnectListNodes(pNode4, pNode5);

        Test("Test5", nullptr, pNode1, nullptr);

        mylist.DestroyList(pNode1);
    }

    // ÊäÈëµÄÁ½¸öÁ´±íÓÐÒ»¸ö¿ÕÁ´±í
    void Test6()
    {
        Test("Test6", nullptr, nullptr, nullptr);
    }

    void DestroyNode(ListNode *pNode)
    {
        delete pNode;
        pNode = nullptr;
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
    return 0;
}
