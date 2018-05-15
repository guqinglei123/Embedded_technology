#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int rowsNum = array.size();//行的数量
        int colsNum = array[0].size();//列的数量
        int rows=rowsNum-1;
        int cols=0;
         if(rowsNum !=0 &&  colsNum!=0)
         {
            while(rows >=0 && cols < rowsNum)
            {
               if(array[rows][cols] == target)
                    return true;
                else if(array[rows][cols] > target)
                    rows--;
                else if(array[rows][cols] < target)
                    cols++;
            }
         }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> matrix;
    matrix = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }};
    Solution Sol;
    int res=Sol.Find(9,matrix);
    return 0;
}
