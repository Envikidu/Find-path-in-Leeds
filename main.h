#ifndef MAIN__H
#define MAIN__H
#include<stdio.h>

//const int N=100010;
int head[100010];
int ver[100010];
double edge[100010];
int next[100010];  
//int edge[100010]; //邻接表
//int tot=0;





long long node1_temp[5000];
long long node2_temp[5000];
double length_temp[5000];  //临时存储连接信息 





int start_point;
int destination_point;  //起点与终点 





int v[100010];  //记录每个点是否被遍历过
double d[100010];  //与当前点集的距离 


typedef struct _Node{
	long long node_id;
	double lat;
	double lon;
}Node;    //节点存储 
Node node_collection[9999];



typedef struct _APQ{
	double dist;
	int node_id;
}APQ;  //人工优先队列数组 
APQ apq[9999];
//int apq_len=0;  //数组长度 
//int sz=0; //优先队列里当前总节点数 
APQ list[100010];  //优先队列预处理数组（节点编号） 
APQ out[100010];   //有序的优先队列数组（节点编号） 






//get map
//double minLat=53.801600;
//double minLon=-1.564000;
//double maxLat=53.811000;
//double maxLon=-1.543100;





#endif 
