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
	void replaceSpace(char *str,int length) {
        if(length <=0)
            return;
        vector<char> str_vect;
        int i=0;
        while(str[i]!='\0')
        {
            if(str[i]==' ')
            {
                str_vect.push_back('%');
                str_vect.push_back('2');
                str_vect.push_back('0');
            }
            else
            {
                str_vect.push_back(str[i]);
            }
            i++;                
        }
        int kk= str_vect.size();
        if(length < str_vect.size()-1)
            return;
        str[str_vect.size()]='\0';
        for(int j = str_vect.size()-1;j>=0;j--)
        {
            str[j]=str_vect[j];
        }

	}
};
int main(int argc, char const *argv[])
{
    /* code */
    // char aa[30]="We Are Happy";
    char aa[30]=" helloworld";
    Solution Sol;
    Sol.replaceSpace(aa,30);
    return 0;
}