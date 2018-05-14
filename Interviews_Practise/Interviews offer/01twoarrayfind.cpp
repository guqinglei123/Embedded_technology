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
        int i,j;
        int rowsNum = array.size();//行的数量
        int colsNum = array[0].size();//列的数量
        i=colsNum-1;
        j=0;
        while(i >= 0)
        {
             if(array[0][i] < target)
                break;
             i++;
        }
        while(j < rowsNum)
        {
            if(array[j][i] == target)
                return true;
            else if(array[j][i] > target)
                return false;
            j++;
        }
        return false;
                
        
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    int matrix[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
    return 0;
}
