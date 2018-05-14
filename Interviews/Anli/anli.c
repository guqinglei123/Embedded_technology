/*
题目一
编译器版本: gcc 4.8.4
请使用标准输入输出(stdin，stdout) ；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h , unistd.h , curl/curl.h , process.h
时间限制: 1S (C/C++以外的语言为: 3 S)   内存限制: 128M (C/C++以外的语言为: 640 M)
输入:
输入描述，例如：
第一行输入是八阵图的行数。
第二行输入是八阵图的列数。
后续行输入每个区域兵力。每一行的数据中间使用空格分开，当前一行输入完成后回车输入下一行数据。
输出:
输出描述，例如：
输出八个单阵中兵力最大值和最小值。
输入范例:
20
20
34  0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  0   0   0   30
0   23  10  5   5   0   0   0   5   5   5   5   5   0   0   0   30  0   40  0
0   9   0   0   5   0   0   0   4   4   4   4   4   0   0   0   0   30  0   0
0   8   7   7   0   5   0   0   3   3   3   3   0   0   0   0   7   0   9   0
0   9   0   0   5   0   5   0   0   12  12  0   0   0   0   10  0   0   0   9
0   0   0   0   5   0   0   5   0   12  12  0   0   5   0   0   0   0   0   0
0   0   0   0   0   0   0   0   0   12  12  0   0   5   0   0   0   0   0   0
0   0   0   0   0   0   0   0   0   0   0   0   0   5   0   0   0   0   0   0
0   0   0   0   0   0   0   0   0   0   0   0   0   5   0   0   0   0   0   0
40  30  3   6   6   0   0   0   0   0   0   0   0   5   5   0   0   0   10  0
0   0   20  0   0   6   6   0   0   0   0   0   0   0   5   6   5   10  10  0
40  30  3   7   6   0   0   0   0   0   0   0   0   0   0   6   0   0   10  0
0   0   0   0   0   0   0   17  0   0   0   0   17  0   0   6   5   7   7   0
0   0   0   0   0   0   0   0   7   0   0   7   0   0   0   0   0   0   0   0
0   20  0   0   7   0   0   0   0   4   4   0   0   0   0   0   10  0   0   0
0   20  0   0   7   0   0   0   0   4   4   0   0   0   0   0   10  0   0   0
0   20  0   0   7   0   0   0   0   4   4   0   0   0   0   0   10  0   0   0
0   30  0   7   0   0   0   0   0   5   5   0   0   0   0   0   0   10  0   50
0   40  7   0   0   0   0   0   0   5   5   0   0   0   0   0   0   0   50  0
43  30  25  10  50  0   0   0   6   6   6   6   0   0   0   0   0   50  0   0
输出范例:
323
116*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int* getMilitaryStrength(int A_size_row, int A_size_cols, int* A,int* result_size) {


}

int main() {
    int res_size;
    int* res;

    int _A_rows = 0;
    int _A_cols = 0;
    scanf("%d", &_A_rows);
    scanf("%d", &_A_cols);
    
    int** _A = (int**)malloc(_A_rows*sizeof(int*));
    int _A_init_i=0;
    for(_A_init_i=0 ; _A_init_i<_A_rows ; ++_A_init_i)
    {
        _A[_A_init_i] = (int*)malloc(_A_cols*(sizeof(int)));
    }
    
    int _A_i, _A_j;
    for(_A_i = 0; _A_i < _A_rows; _A_i++) {
        for(_A_j = 0; _A_j < _A_cols; _A_j++) {
            int _A_item;
            scanf("%d", &_A_item);
            
            _A[_A_i][_A_j] = _A_item;
        }
    }   
 
    res = getMilitaryStrength(_A_rows, _A_cols, _A, &res_size);
    for(res_i=0; res_i < res_size; res_i++) {
    
        printf("%d\n", res[res_i]);
        
    }
    
    return 0;

}

/*
题目二
三年二班的同学们要去郊游了，他们决定所有人都从一个地方出发，但是每个人都要有不同的路线，最终完成一次郊游。所以他们想知道，在它们去的公园里，究竟有多少种不同的路线供选择。
公园可以被描述为一个具有N个结点，M条有向边的图，你要做的任务就是，选择其中某个点，使得其能够产生尽量多的从这个点出发的路线。

提示：此处可以利用node代表结点的总数，结点编号从0到node-1。edge用来描述边。你的程序应该返回路径最多的结点对应的路径数。
注意：所有的边都是有向边！数据输入将保证不包含环路，不包括重复的边。

输入数据示例：
node = 4

edge = {{0, 1}, {1, 2}, {2, 3}, {0, 2}}，包含4条有向边

输出结果：5

示例解释：
显然，0号节点应该是起点。
对应的5条路线为：
0 1
0 1 2
0 1 2 3
0 2
0 2 3
编译器版本: gcc 4.8.4
请使用标准输入输出(stdin，stdout) ；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h , unistd.h , curl/curl.h , process.h
时间限制: 3S (C/C++以外的语言为: 5 S)   内存限制: 128M (C/C++以外的语言为: 640 M)
输入:
输入描述
输入数据包含M+2行
第一行 整型 node的个数N，范围1-10000
第二行 描述边是M行2列矩阵大小，M  2
第三行-第M+2行表示edge的数据，其中每行代表一条有向边，实际上可以描述成一个N*2的二维数组，行描述边，列表示结点
输出:
输出描述
最大路径的数:一个整型数字
输入范例:
输入范例 例如下面表示总共4个结点和4条边：
4      (总共4个结点，编号0,1,2,3)
4 2
0 1 （从结点0到结点1的一条有向边）
1 2 （从结点1到结点2的一条有向边）
2 3 （从结点2到结点3的一条有向边）
0 2 （从结点0到结点2的一条有向边）
输出范例:
输出范例 例如：
100

*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int maxpathnumber(int node, int edge_size_row, int edge_size_cols, int* edge) {


}

int main() {
    int res;

    int _node;
    scanf("%d", &_node);

    int _edge_rows = 0;
    int _edge_cols = 0;
    scanf("%d", &_edge_rows);
    scanf("%d", &_edge_cols);
    
    int** _edge = (int**)malloc(_edge_rows*sizeof(int*));
    int _edge_init_i=0;
    for(_edge_init_i=0 ; _edge_init_i<_edge_rows ; ++_edge_init_i)
    {
        _edge[_edge_init_i] = (int*)malloc(_edge_cols*(sizeof(int)));
    }
    
    int _edge_i, _edge_j;
    for(_edge_i = 0; _edge_i < _edge_rows; _edge_i++) {
        for(_edge_j = 0; _edge_j < _edge_cols; _edge_j++) {
            int _edge_item;
            scanf("%d", &_edge_item);
            
            _edge[_edge_i][_edge_j] = _edge_item;
        }
    }
    
    res = maxpathnumber(_node, _edge_rows, _edge_cols, _edge);
    printf("%d\n", res);
    
    return 0;

}