#ifndef MAIN__H
#define MAIN__H
#include<stdio.h>

//const int N=100010;
int head[100010];
int ver[100010];
double edge[100010];
int next[100010];  
//int edge[100010]; //�ڽӱ�
//int tot=0;





long long node1_temp[5000];
long long node2_temp[5000];
double length_temp[5000];  //��ʱ�洢������Ϣ 





int start_point;
int destination_point;  //������յ� 





int v[100010];  //��¼ÿ�����Ƿ񱻱�����
double d[100010];  //�뵱ǰ�㼯�ľ��� 


typedef struct _Node{
	long long node_id;
	double lat;
	double lon;
}Node;    //�ڵ�洢 
Node node_collection[9999];



typedef struct _APQ{
	double dist;
	int node_id;
}APQ;  //�˹����ȶ������� 
APQ apq[9999];
//int apq_len=0;  //���鳤�� 
//int sz=0; //���ȶ����ﵱǰ�ܽڵ��� 
APQ list[100010];  //���ȶ���Ԥ�������飨�ڵ��ţ� 
APQ out[100010];   //��������ȶ������飨�ڵ��ţ� 






//get map
//double minLat=53.801600;
//double minLon=-1.564000;
//double maxLat=53.811000;
//double maxLon=-1.543100;





#endif 
