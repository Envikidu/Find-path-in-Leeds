#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "get_map.h"
#include "main.h" 

extern int tot;
extern int apq_len;
extern int sz;
extern double minLat;
extern double minLon;
extern double maxLat;
extern double maxLon;

void add(int x,int y,double z) 
{
	ver[++tot] = y;
	edge[tot] = z;
	next[tot] = head[x];
	head[x] = tot;
	//printf("%f\n",edge[tot]);
}

void get_map()
{
	int LEN=2000;
	FILE *fp;
	fp=fopen("Final_Map.map","r");
	if(!fp)
	{
		printf("Fail to load.\n");
		exit(0);
		//return 0;
	}
	
	long long link_id;
	int way;
	double veg;
	double arch;
	double land;
	
	char read[LEN];
	fgets(read,LEN,fp);
	int i=1;
	for(i;i<=2344;i++)  //所有连边数 
	{
		fgets(read,LEN,fp);
		sscanf(read,"<link id=%lld node=%lld node=%lld way=%d length=%lf veg=%lf arch=%lf land=%lf POI=;/link>\n", &link_id, &node1_temp[i], &node2_temp[i], &way, &length_temp[i], &veg, &arch, &land);
		//add(node1_temp[i],node2_temp[i],length_temp[i]);
		//printf("%lld %lld %f\n",node1_temp[i],node2_temp[i],length_temp[i]);
	}
	
	
	for(i=1;i<=3991;i++)  //所有节点数 
	{
		fgets(read,LEN,fp);
		sscanf(read,"<node id=%lld lat=%lf lon=%lf /node>", &node_collection[i].node_id, &node_collection[i].lat, &node_collection[i].lon);
	}
	
	
	
	FILE *kp;
	kp=fopen("map_data.txt","w");
	for(i=1;i<=2344;i++)   //遍历所有邻接表临时节点组 
	{
		int j;
		for(j=1;j<=3991;j++)  //寻找第一组节点 
		{
			
			if(node1_temp[i]==node_collection[j].node_id)  //找到第一组之后开始找第二组 
			{
				int k;
				for(k=1;k<=3991;k++)
				{
					if(node2_temp[i]==node_collection[k].node_id)  //找到了第二组 
					{
						add(j,k,length_temp[i]);  //把对应编号加入 
						add(k,j,length_temp[i]); 
						//printf("%d %d %f\n",j,k,length_temp[i]);
						fprintf(kp, "%f %f\n", node_collection[j].lon, node_collection[j].lat);
						fprintf(kp, "%f %f\n\n", node_collection[k].lon, node_collection[k].lat);
						
					}
				}
			}
		}
	}
	
	fclose(kp);
	fclose(fp);
	
	
	
	
	//char read[100010];
	/*for(i=1;i<=2344;i++)
	{
		for(j=1;j<=3991;j++)
		{
			if(node1_temp[i]==node_collection[j].node_id)  
			{
				for(k=1;k<=3991;k++)
				{
					if(node2_temp[i]==node_collection[k].node_id)
					{
						
					}
					
				}
			}
		}
	} */
	
	return;
}
