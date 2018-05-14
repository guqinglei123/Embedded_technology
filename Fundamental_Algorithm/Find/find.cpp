/*****************************************************************************************************
�ο����ӣ�http://www.cnblogs.com/maybe2030/p/4715035.html
https://blog.csdn.net/chenyukuai6625/article/details/76889375
https://blog.csdn.net/chenyukuai6625/article/details/77165144
 * *******************************************************************************************/
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <time.h>
#include "math.h"
using namespace std;
class Find
{
  public:
    //˳�����,�ʺ��ڴ洢�ṹΪ˳��洢�����Ӵ洢�����Ա�����������ҡ�
    int sequenceFind(int target, vector<int> &vect, int index_begin, int index_end)
    {
        for (int i = index_end - 1; i >= index_begin; i--)
        {
            if (vect[i] == target)
                return i;
        }
        return -1;
    }
    //���ֲ���,Ԫ�ر���������ģ�������������Ҫ�Ƚ������������
    int binaryFind(int target, vector<int> &vect, int index_begin, int index_end)
    {
        int index_mid = 0;
        while (index_begin < index_end)
        {
            index_mid = (index_begin + index_end) / 2;
            (target < vect[index_mid]) ? index_end = index_mid : index_begin = index_mid + 1;
        }
        --index_begin;
        return (target == vect[index_begin]) ? index_begin : -1;
    }
    int binaryFind_recursion(int target, vector<int> &vect, int index_begin, int index_end)
    {
        int index_mid = index_begin + (index_end - index_begin) / 2;
        if (index_begin <= index_end)
        {
            if (vect[index_mid] == target)
                return index_mid;
            if (vect[index_mid] > target)
                return binaryFind_recursion(target, vect, index_begin, index_mid - 1);
            if (vect[index_mid] < target)
                return binaryFind_recursion(target, vect, index_mid + 1, index_end);
        }
        else
        {
            return -1;
        }
    }
    //��ֵ����
    int insertionFind(int target, vector<int> &vect, int index_begin, int index_end)
    {
        int index_mid = index_begin + ((target - vect[index_begin]) / (vect[index_end] - vect[index_begin])) * (index_end - index_begin);
        if (index_begin <= index_end)
        {
            if (vect[index_mid] == target)
                return index_mid;
            if (vect[index_mid] > target)
                return insertionFind(target, vect, index_begin, index_mid - 1);
            if (vect[index_mid] < target)
                return insertionFind(target, vect, index_mid + 1, index_end);
        }
        else
        {
            return -1;
        }
    }
    //쳲���������
    int fibonacci(int n)
    {
        // vector<int> F(n+1);
        // for(int i=0; i <= n;++i)
        // {
        //     if(i < 2)
        //         F[i] = i;
        //     else
        //         F[i] = F[i-1] + F[i-2];
        // }
        // return F[n];
        int f = 1, g = 0;
        while (0 < n--)
        {
            g += f;
            f = g - f;
        }
        return g;
    }
    int fibonacciFind(int target, vector<int> &vect, int index_begin, int index_end)
    {
        vector<int> fib;
        for (int i = 0; fibonacci(i) < index_end - index_begin; i++)
            fib.push_back(fibonacci(i));
        int index_mid;
        int fib_index = fib.size() - 1;
        while (index_begin < index_end)
        {
            index_mid = index_begin + fib[fib_index] - 1;
            if (target < vect[index_mid])
                index_end = index_mid;
            else if (target > vect[index_mid])
                index_begin = index_mid + 1;
            else
                return index_mid;
            fib_index--;
        }
        return -1;
    }
    int blockFind(int target, vector<int> &vect, int index_begin, int index_end)
    {
    }
    int hashFind(int target, vector<int> &vect, int index_begin, int index_end)
    {
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //���������
    Find Sol;
    int N = 35;
    vector<int> vect;
    int target = 1, target_sort = 1;
    int res;
    //���������
    int pos, value;
    vector<int>::iterator it;
    srand((unsigned int)time(NULL)); //�����������
    for (int i = 0; i < N; i++)      //��[0, 3n)��ѡ��n�����������������
    {
        pos = rand() % (i + 1);
        it = vect.begin() + pos;
        value = rand() % (3 * N);
        vect.insert(it, value);
    }
    cout << "��ʼ���ݣ�"; //Ϊʲô��һ�����������
    for (int i = 0; i < vect.size(); i++)
    {

        cout << vect[i] << ' ';
    }
    cout << endl;
    //��������
    vector<int> vect_sort(vect);
    sort(vect_sort.begin(), vect_sort.end());
    cout << "�������ݣ�";
    for (int i = 0; i < vect_sort.size(); i++)
    {
        cout << vect_sort[i] << ' ';
    }
    cout << endl;

    target = 10;
    target = vect[1];
    // target_sort = vect_sort[1];
    target_sort = target;

    //������в���
    res = Sol.sequenceFind(target, vect, 0, vect.size()); //���䶼������ҿ�,���صĲ���Ԫ�ص��±꣬ʧ��Ϊ-1
    cout << "Ԫ��λ��(˳������)��" << res << endl;

    //������в��ң�������ظ����ݣ��������߿��ܸ��Ĳ�һ����
    res = Sol.binaryFind(target_sort, vect_sort, 0, vect.size()); //�������䶼������ҿ�,���صĲ���Ԫ�ص��±꣬ʧ��Ϊ���ҵ�ʧ��λ��
    cout << "Ԫ��λ��(���ֲ���)��" << res << endl;
    res = Sol.binaryFind_recursion(target_sort, vect_sort, 0, vect.size());
    cout << "Ԫ��λ��(���ֲ���(������))��" << res << endl;

    res = Sol.insertionFind(target_sort, vect_sort, 0, vect.size()); //�������䶼������ҿ�,���صĲ���Ԫ�ص��±꣬ʧ��Ϊ���ҵ�ʧ��λ��
    cout << "Ԫ��λ��(��ֵ����)��" << res << endl;

    res = Sol.fibonacciFind(target_sort, vect_sort, 0, vect.size()); //�������䶼������ҿ�,���صĲ���Ԫ�ص��±꣬ʧ��Ϊ���ҵ�ʧ��λ��
    cout << "Ԫ��λ��(쳲���������)��" << res << endl;
    return 0;
}
