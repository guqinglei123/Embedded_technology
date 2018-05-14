/*****************************************************************************************************
�ο����ӣ�https://www.cnblogs.com/onepixel/articles/7674659.html
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
class Sort
{
  public:
    void sort_swap(vector<int> &vect, int m, int n)
    {
        int temp = vect[m];
        vect[m] = vect[n];
        vect[n] = temp;
    }
    //ð�ݣ��Ƚ���������������λ��
    void bubbleSort(vector<int> &vect, int index_begin, int index_end)
    {
        int temp;

        for (int i = index_begin; i < index_end; i++)
        {
            for (int j = index_begin; j < (index_end - i - 1); j++)
            {
                if (vect[j] > vect[j + 1])
                {
                    sort_swap(vect, j + 1, j);
                    // temp = vect[j + 1];
                    // vect[j + 1] = vect[j];
                    // vect[j] = temp;
                }
            }
        }
    }
    //ѡ��ѡ��δ�����������С��Ԫ�ء����������кõ����ݵ����
    void selectSort(vector<int> &vect, int index_begin, int index_end)
    {
        int temp;
        int min_index;
        for (int i = index_begin; i < index_end; i++)
        {
            min_index = i;
            for (int j = i + 1; j < index_end; j++)
            {
                if (vect[j] < vect[min_index])
                {
                    min_index = j;
                }
            }
            temp = vect[i];
            vect[i] = vect[min_index];
            vect[min_index] = temp;
        }
    }
    //����,��δ���������������õ����ݱȽϣ����β�������õ�������
    void insertSort(vector<int> &vect, int index_begin, int index_end)
    {
        int temp;

        for (int i = index_begin + 1; i < index_end; i++)
        {
            temp = vect[i];
            int j;
            for (j = i - 1; (j >= index_begin) && (vect[j] > temp); j--)
            {
                vect[j + 1] = vect[j];
            }
            vect[j + 1] = temp;
        }
    }
    //shell
    void Sedgewick(int length, vector<int> &vect_Sedgewick) //Sedgewick����
    {
        int i = 0, j = 0;
        int temp;
        for (int n = 0; n < length; n++)
        {
            if (n % 2 == 0)
            {
                temp = (int)(9 * (pow(4, i) - pow(2, i)) + 1);
                vect_Sedgewick.push_back(temp);
                i++;
            }
            else
            {
                temp = (int)(pow(2, j + 2) * (pow(2, j + 2) - 3) + 1);
                vect_Sedgewick.push_back(temp);
                j++;
            }
            if (vect_Sedgewick[n] > length)
            {
                break;
            }
        }
    }
    void shellSort(vector<int> &vect, int index_begin, int index_end)
    {
        vector<int> vect_Sedgewick;
        Sedgewick((index_end - index_begin), vect_Sedgewick);
        for (int j = (vect_Sedgewick.size() - 2); j >= 0; j--)
        {
            int index = vect_Sedgewick[j];
            for (int i = 0; i < index; i++)
            {
                for (int k = i + index; k < vect.size(); k += index)
                {
                    int pre = k - index;
                    int temp = vect[k];
                    while (pre >= 0 && vect[pre] > temp)
                    {
                        vect[pre + index] = vect[pre];
                        pre -= index;
                    }
                    vect[pre + index] = temp;
                }
            }
            // cout << "���ԣ�";
            // for (int g = 0; g < vect.size(); g++)
            // {
            //     cout << vect[g] << ' ';
            // }
            // cout << endl;
        }
    }
    //�鲢
    //��κϲ��Ǻ��ġ�
    void merger(vector<int> &vect, int index_begin, int index_mid, int index_end, int temp_sort[])
    {
        int i = index_begin, j = index_mid + 1;
        int m = index_mid, n = index_end;
        int k = 0;
        while (i <= m && j <= n)
        {
            if (vect[i] <= vect[j])
                temp_sort[k++] = vect[i++];
            else
                temp_sort[k++] = vect[j++];
        }

        while (i <= m)
            temp_sort[k++] = vect[i++];

        while (j <= n)
            temp_sort[k++] = vect[j++];

        for (i = 0; i < k; i++)
            vect[index_begin + i] = temp_sort[i];
    }
    void mergersort(vector<int> &vect, int index_begin, int index_end, int temp_sort[])
    {
        if (index_begin < index_end)
        {
            int index_mid = (index_end + index_begin) / 2;
            mergersort(vect, index_begin, index_mid, temp_sort);
            mergersort(vect, index_mid + 1, index_end, temp_sort);
            merger(vect, index_begin, index_mid, index_end, temp_sort);
        }
    }
    void mergerSort(vector<int> &vect, int index_begin, int index_end)
    {
        int *p = new int[index_end - index_begin]; //������������������һЩ
        mergersort(vect, index_begin, index_end, p);
    }

    //��������
    int partition(vector<int> &vect, int index_begin, int index_end) //�����м���Ǻ��ġ�
    {
        int pivot = index_begin;
        int index = index_begin + 1;
        for (int i = index; i < index_end; i++)
        {
            if (vect[i] < vect[pivot])
            {
                sort_swap(vect, i, index);
                index++;
            }
        }
        sort_swap(vect, pivot, index - 1);
        return index - 1;
    }
    void quickSort(vector<int> &vect, int index_begin, int index_end)
    {
        if (index_end - index_begin < 2)
            return;
        int index_mid = partition(vect, index_begin, index_end);
        quickSort(vect, index_begin, index_mid);
        quickSort(vect, index_mid + 1, index_end);
    }
    //������
    int len;
    void buildMaxHeap(vector<int> &vect, int index_begin, int index_end)
    {
        len = vect.size();
        for (int i = floor(len / 2); i >= 0; i--)
            heapify(vect, i);
    }
    void heapify(vector<int> &arr, int index_begin) //��ν����󶥶ѵ�
    {
        int left = 2 * index_begin + 1; //largest,right,left������һ�����Ƕѣ��ж��������ֵ��Ϊ�Ѷ�
        int right = 2 * index_begin + 2;
        int largest = index_begin;

        if (left < len && arr[left] > arr[largest]) //ע��������Ҫ�ж��Ƿ񳬹�len
        {
            largest = left;
        }

        if (right < len && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != index_begin)
        {
            sort_swap(arr, index_begin, largest);
            heapify(arr, largest);
        }
    }
    void heapSort(vector<int> &vect, int index_begin, int index_end)
    {
        buildMaxHeap(vect, index_begin, index_end);
        for (int i = index_end - 1; i > index_begin; i--)
        {
            sort_swap(vect, index_begin, i);
            len--;
            heapify(vect, index_begin); //�����Ѷ�֮�󣬿�ʼ����
        }
    }
    //��������
    void countSort(vector<int> &vect, int index_begin, int index_end)
    {
        int max_value = *max_element(vect.begin() + index_begin, vect.begin() + index_end); //��Ҫʡ�� ��*�� �����ֵ
        vector<int> bucket_vect(max_value + 1, 0);
        // int kk=bucket_vect.size();
        for (int i = index_begin; i < index_end; i++)
        {
            // if (!bucket_vect[vect[i]])
            // {
            //     bucket_vect[vect[i]] = 0;
            // }
            bucket_vect[vect[i]]++;
        }
        int index = 0;
        for (int i = 0; i <= max_value; i++)
        {
            while (bucket_vect[i] > 0)
            {
                vect[index++] = i;
                bucket_vect[i]--;
            }
        }
    }
    //Ͱ����
    void bucketSort(vector<int> &vect, int index_begin, int index_end)
    {
        int max_value = *max_element(vect.begin() + index_begin, vect.begin() + index_end);
        int min_value = *min_element(vect.begin() + index_begin, vect.begin() + index_end);
        int buckeSize = 10;                                             //ÿһ��Ͱ��ĳ���
        int bucketcount = floor(max_value - min_value) / buckeSize + 1; //Ͱ�ĸ���
        vector<vector<int>> bucket_vect(bucketcount);
        for (int i = index_begin; i < index_end; i++)
        {
            int index_temp = floor((vect[i] - min_value) / buckeSize);
            bucket_vect[floor((vect[i] - min_value) / buckeSize)].push_back(vect[i]);
        }
        int k = 0;
        for (int i = 0; i < bucket_vect.size(); i++)
        {
            insertSort(bucket_vect[i], 0, bucket_vect[i].size());
            for (int j = 0; j < bucket_vect[i].size(); j++)
            {
                vect[k++] = bucket_vect[i][j];
            }
        }
    }
    //��������
    void radixSort(vector<int> &vect, int index_begin, int index_end)
    {
        int max_value = *max_element(vect.begin() + index_begin, vect.begin() + index_end);
        int count = 0;

        while (max_value != 0)
        {
            max_value /= 10;
            count++;
        }
        int mod = 10, dev = 1;
        for (int i = 0; i < count; i++, dev *= 10, mod *= 10)
        {
            vector<vector<int>> radix_vect(10); //0~9������,����
            for (int j = index_begin; j < index_end; j++)
            {
                int radix = (vect[j] % mod) / dev;
                radix_vect[radix].push_back(vect[j]);
            }

            int index = index_begin;
            for (int k = 0; k < radix_vect.size(); k++)
            {
                for (int g = 0; g < radix_vect[k].size(); g++)
                {
                    vect[index++] = radix_vect[k][g];
                }
            }
            // cout << "���ԣ�";
            // for (int g = 0; g < vect.size(); g++)
            // {
            //     cout << vect[g] << ' ';
            // }
            // cout << endl;
        }
        // int kk = vect.size();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //���������
    Sort Sol;
    int N = 500;
    vector<int> vect;
    int pos, value;
    srand((unsigned int)time(NULL)); //�����������
    vector<int>::iterator it;
    for (int i = 0; i < N; i++) //��[0, 3n)��ѡ��n�����������������
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

    vector<int> vect_sort(vect);

    //ð������
    vect_sort = vect;
    Sol.bubbleSort(vect_sort, 0, vect.size());//�������䶼������ҿ�
    cout << "ð������";
    // cout << endl;
    for (int i = 0; i < vect_sort.size(); i++)
    {
        cout << vect_sort[i] << ' ';
    }
    cout << endl;

    //��������
    // vector<int> vect_sort(vect);
    vect_sort = vect;
    Sol.insertSort(vect_sort, 0, vect.size());
    cout << "��������";
    // cout << endl;
    for (int i = 0; i < vect_sort.size(); i++)
    {
        cout << vect_sort[i] << ' ';
    }
    cout << endl;

    //ѡ������
    // vector<int> vect_sort(vect);
    vect_sort = vect;
    Sol.selectSort(vect_sort, 0, vect.size());
    cout << "ѡ������";
    // cout << endl;
    for (int i = 0; i < vect_sort.size(); i++)
    {
        cout << vect_sort[i] << ' ';
    }
    cout << endl;

    //shell
    vect_sort = vect;
    Sol.shellSort(vect_sort, 0, vect.size());
    cout << "ϣ������";
    // cout << endl;
    for (int i = 0; i < vect_sort.size(); i++)
    {
        cout << vect_sort[i] << ' ';
    }
    cout << endl;

    //�鲢
    vect_sort = vect;
    Sol.mergerSort(vect_sort, 0, vect.size() - 1);//�������䶼������ұ�
    cout << "�鲢����";
    // cout << endl;
    for (int i = 0; i < vect_sort.size(); i++)
    {
        cout << vect_sort[i] << ' ';
    }
    cout << endl;

    //����
    vect_sort = vect;
    Sol.quickSort(vect_sort, 0, vect.size());
    cout << "��������";
    // cout << endl;
    for (int i = 0; i < vect_sort.size(); i++)
    {
        cout << vect_sort[i] << ' ';
    }
    cout << endl;

    //������
    vect_sort = vect;
    Sol.heapSort(vect_sort, 0, vect.size());
    cout << "������  ��";
    // cout << endl;
    for (int i = 0; i < vect_sort.size(); i++)
    {
        cout << vect_sort[i] << ' ';
    }
    cout << endl;

    //��������
    vect_sort = vect;
    Sol.countSort(vect_sort, 0, vect.size());
    cout << "��������";
    // cout << endl;
    for (int i = 0; i < vect_sort.size(); i++)
    {
        cout << vect_sort[i] << ' ';
    }
    cout << endl;

    //Ͱ����
    vect_sort = vect;
    Sol.bucketSort(vect_sort, 0, vect.size());
    cout << "Ͱ����  ��";
    // cout << endl;
    for (int i = 0; i < vect_sort.size(); i++)
    {
        cout << vect_sort[i] << ' ';
    }
    cout << endl;

    //��������
    vect_sort = vect;
    Sol.radixSort(vect_sort, 0, vect.size());
    cout << "��������";
    // cout << endl;
    for (int i = 0; i < vect_sort.size(); i++)
    {
        cout << vect_sort[i] << ' ';
    }
    cout << endl;

    return 0;
}
