#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;
class Solution
{
  public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        int stack1_size=stack1.size();
        for (int i = 0; i < stack1_size; i++)
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res=stack2.top();//注意一下，删除的是那个顶点
        stack2.pop();
        int stack2_size=stack2.size();
        for (int i = 0; i < stack2_size; i++)//两个栈的数据应该交换回去,也可以不交换。只需要判断一下stack2是不是空
        {
            stack1.push(stack2.top());      //，如果为空则将stack1的数据如上面交换。不为空着继续弹出stack2数据。
            stack2.pop();
        }
        return res;
    }
    bool empty()
    {
        if(stack1.empty())
            return true;
        else
            return false;
    }

  private:
    stack<int> stack1;
    stack<int> stack2;
};
int main(int argc, char const *argv[])
{
    /* code */
    Solution solu;
    solu.push(1);
    solu.push(2);
    solu.push(3);
    solu.push(4);
    int node;

    while (solu.empty() != true)
    {

        cout << solu.pop();
    }
    cout<<endl;
    return 0;
}
