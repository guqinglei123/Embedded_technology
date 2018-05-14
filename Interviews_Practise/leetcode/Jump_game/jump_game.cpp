/***************************************************************************************************
 * ����һ��(55��Ծ��Ϸһ)����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
�ж����Ƿ��ܹ��������һ��λ�á�
˵����
    ����: [2,3,1,1,4]
    ���: true
    ����: ��λ�� 0 �� 1 �� 1 ��, Ȼ���� 3 ���������һ��λ�á�
    ����: [3,2,1,0,4]
    ���: false
    ����: �������������ܻᵽ������Ϊ 3 ��λ�á�����λ�õ������Ծ������ 0 �� ��������Զ�����ܵ������һ��λ�á�
�ο����ӣ�http://www.cnblogs.com/grandyang/p/4371526.html

�������(45��Ծ��Ϸ��)����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�
˵����
    ����: [2,3,1,1,4]
    ���: 2
    ����: �������һ��λ�õ���С��Ծ���� 2��
        ���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã��� 1 ����Ȼ���� 3 ��������������һ��λ�á�
    ���������ǿ��Ե�����������һ��λ�á�
�ο�����:http://www.cnblogs.com/grandyang/p/4373533.html

 * ********************************************************************************************/
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        if(nums.size() <1 )
            return false;
        int index_k = 0;
        int pre_jump = 0;
        int temp_jump =0;
        int max_i=1;
        int jump=0;
        while(max_i != 0 )
        {
             pre_jump=0;
             max_i = 0; 
             temp_jump=0;  
            for(int i=index_k+1; i <= index_k+nums[index_k]; i++)
            {
                temp_jump = nums[index_k] + nums[i];
                if (temp_jump > pre_jump)
                {
                    max_i = i;

                }
                pre_jump = temp_jump;
            }
            jump=nums[max_i]+ max_i + 1;
            if(jump >= nums.size())
                return true;
            index_k = max_i;
        }

        return false;        
    }
    bool canJump_greed(vector<int>& nums) 
    {
        if(nums.size() <1 )
            return false;
        int len = nums.size();    
        //̰���㷨������,ע���ж�����
        int reach=0;//��¼��Զ�ܵ����λ��
        for(int i=0;i<len;i++)
        {
            if(reach>=len-1)
                return true;
            if(i>reach)
                return false;
            reach=max(reach,i+nums[i]);//���ж��ٸ���reach��ֵ
        }
        if(reach>=len-1)
            return true;
    }
    int canJump2(vector<int>& nums) 
    {
        if(nums.size() <= 1 )
            return 0;
        int res=0;
        int index_k = 0;
        int pre_jump = 0;
        int temp_jump =0;
        int max_i=1;
        int jump=0;
        int max_jump=0;
        while(max_i != 0 )  //forѭ���������棬whileѭ����������
        {
             pre_jump=0;
             max_i = 0; 
             temp_jump=0;
             max_jump = 0;  
            for(int i=index_k+1; i <= index_k+nums[index_k]; i++)
            {
                temp_jump = i + nums[i];
                if (temp_jump > max_jump)
                {
                    max_i = i;
                    max_jump = temp_jump;

                }
                // pre_jump = temp_jump;
            }
            jump=nums[max_i]+ max_i + 1;
            res++;
            if(jump >= nums.size())
            {
                if(nums[0] >= nums.size()-1)
                    return res;
                else
                    return res+1;
            }
            index_k = max_i;
        }      
    }

};
int main()
{
    vector<int> nums;
    nums = {2,3,1,1,4};
    // nums = {3,2,1,0,4};
    // nums ={1,1,1,0};
    // nums = {2,3,1};
    // nums ={7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    // nums = {1,2};
    // nums = {2,1};
    // nums = {6,9,1,5,6,0,0,5,9};
    Solution Sol; 
    int res = Sol.canJump(nums);
    cout << "����һ�Ľ⣺" << res <<endl;
    res = Sol.canJump_greed(nums);
    cout << "����һ��̰�Ľⷨ:" << res <<endl;
    res = Sol.canJump2(nums);
    cout << "�������̰�Ľⷨ:" << res <<endl;
    return 0;
}