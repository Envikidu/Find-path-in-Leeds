#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "main.h"


int tot=0;
int apq_len=0;
int sz=0;
double minLat=53.801600;
double minLon=-1.564000;
double maxLat=53.811000;
double maxLon=-1.543100;
int pre[100010];
int path_len=0;
int path[100010];

void pop()
{
	int i;
	for(i=1;i<=sz-1;i++)
	{
		out[i].dist=out[i+1].dist;
		out[i].node_id=out[i+1].node_id;
	}
	sz--;
	/*int ret = heap[0]; //大顶堆的最大值
	int x = heap[--sz]; // 取最后一个元素，并且删除 （因为要保证是完全二叉树，所以取最后一个） 
	int i = 0; //把x放到开头 
	while(i*2+1 < sz){
		int l = i*2 + 1; //左孩子 
		int r = i*2 + 2; //右孩子 
		if(r < sz && heap[l] < heap[r]) l = r; //两个孩子中较大的 设为l,heap[l] 
		if(x > heap[l]) break; //如果x 比这两个孩子都大，因为下面已经保证是大顶堆了，所以x放到这 
		heap[i] = heap[l];//否则 较大的这个孩子节点提上去，将较大的孩子节点（此时为x）作为下一个节点，继续往下找 
		i = l;
	} 
	heap[i] = x;*/
	return;
}






void adjust_down(APQ a[],int father,int n)
{
//将元素father向下调整
    int son;
    APQ store;
    store.dist=a[father].dist;
    store.node_id=a[father].node_id;
    
    //沿着key较大的子结点向下筛选
    for (son=2*father;son<=n;son*=2)  //每次循环之后若未超出边界，则找向下找当前节点的左孩子 
	{ 
    	 
        if(son<n&&a[son].dist<a[son+1].dist)
		{
            son++;   //左孩子不是最后一个节点且右孩子比左孩子更大，则把研究对象调整到右孩子上 
        }
        
        
        if(a[father].dist>=a[son].dist)   //若该父节点比最大的孩子节点还要大，则无需再调整 
        {
        	continue;
		}
		
        else 
		{
            a[father].dist=a[son].dist;   //将a[son]调整到父结点上
            a[father].node_id=a[son].node_id;
            a[son].dist=store.dist;
            a[son].node_id=store.node_id;
            father=son;	   //修改father值，以便继续向下筛选
        }
    }
    
    //a[father]=store;			//被筛选的值放入最终的位置
    return;
}



void build_max_heap(APQ a[],int n)
{
    int i;
    for (i=n/2;i>0;i--) 
	{
        adjust_down(a,i,n);  //从倒数第二层调整（最低的父节点层） 
    }
    return;
}




void heap_sort(APQ a[], int n)
{
	if(n==1)
	{
		return;
	}
	
	int j;
	for(j=n;j>0;j--)
	{
    	build_max_heap(a,j); //先建立堆
    
    	/*for(int i=1;i<=n;i++)
    	{
    		printf("\n");
    		printf("%lf ",a[i]);
		}*/
		
		out[j].dist=a[1].dist; //每次取堆顶的当前最大元素放在尾部
		out[j].node_id=a[1].node_id;
		 
		a[1].dist=a[j].dist;
		a[1].node_id=a[j].node_id;
		
	}
	return;
    
}



void push(APQ x)
{
	sz++;
	int i=sz; //i表示x（最后一个）的编号 同时个数加一 
	out[sz].dist=x.dist;   
	out[sz].node_id=x.node_id; //在out的堆尾增加一个push的新元素
	//printf("%d\n",out[sz].node_id);
	int j;
	for(j=1;j<=sz;j++)
	{
		list[j].dist=out[j].dist;  
		list[j].node_id=out[j].node_id;  //把list维护成和out一样 
	}
	

	heap_sort(list,sz);
	
	/*printf("%d\n",out[sz].node_id);
	printf("%f\n",out[sz].dist);
	printf("%d\n",list[sz].node_id);
	printf("%f\n",list[sz].dist);*/
	/*while(i>0)
	{
		int p=i/2;
		if(out[p]>=x)   //如果某个heap[i]的父节点比它大 就把x放到这里 
		{
			out[i]=x;
			break;
		}
		out[i]=out[p];//否则 父节点下来 然后再将这个父节点（此时为x）当成下一个子节点，再往上找 
		i=p;
	}*/
	return;
	
}



/*int main()
{
	scanf("%d",&sz);
	int i;
	for(i=1;i<=sz;i++)
	{
		scanf("%lf",&list[i]);
	}
	
	heap_sort(list,sz);
	
	
	for(i=1;i<=sz;i++)
    {
    	printf("%lf ",out[i]);
	}
	
	push(5);
	
	printf("\n");
	
	for(i=1;i<=sz;i++)
    {
    	printf("%lf ",out[i]);
	}
	
	pop();
	
	printf("\n");
	for(i=1;i<=sz;i++)
    {
    	printf("%lf ",out[i]);
	}
	
	return 0;
}*/


//编号从1开始1的小根堆 
void dijkstra() 
{
	int y=0;
	for(y;y<=100010;y++)
	{
		d[y]=2147483647;
	}
	memset(v,0,sizeof(v)); 
	d[start_point]=0;  //距离起点距离初始化为0 
	/*for(y=0;y<10;y++)
	{
		printf("%f\n",d[y]);
	}*/
	
	APQ first;  //起始点初始化 
	first.dist=0;
	first.node_id=start_point;
	
	push(first);  //把起始点加入堆 
	
	//printf("%d\n\n",out[1].node_id);
	/*int w;
	for(w=1;w<=10;w++)
	{
		printf("%d\n",list[w].node_id);
		printf("%d\n",out[w].node_id);
	}*/
	
	while (sz!=0) 
	{
		
		int x = out[1].node_id; //堆顶的元素 最近节点的编号 
		pop();
		
		//printf("%d\n\n",x);
		
		
		
		/*int w;
		for(w=1;w<=10;w++)
		{
			printf("%d\n",list[w].node_id);
			
		}
		printf("\n");
		
		for(w=1;w<=10;w++)
		{
			printf("%d\n",out[w].node_id);
		}*/
		
		
		
		
		
		
		if (v[x])  //若这个点已经被遍历过了 
		{
			continue;
		}
		
		v[x] = 1;
		
		int i;
		for (i = head[x]; i; i = next[i]) //当前节点所能指向的边 
		{
			int y = ver[i];
			double z = edge[i];
			if (d[y] > d[x] + z)
			{
				d[y] = d[x] + z;
				//printf("%f\n",d[y]);
				APQ temp;
				temp.dist=d[y];
				temp.node_id=y;
				push(temp);
				pre[y]=x;
				//q.push(make_pair(-d[y], y));
			}
		}
	}
	
	return;
}


int main()
{
	int o;
	for(o=0;o<100010;o++)
	{
		head[o]=0;
		v[o]=0;
	}
	for(o=0;o<100010;o++)
	{
		ver[o]=0;
		edge[o]=0;
		next[o]=0;
	}
	for(o=0;o<100010;o++)
	{
		pre[o]=-1;
	}
	
	get_map();
	//printf("%f %f ",node_collection[3941].lon,node_collection[3941].lat);
	/*int jj;
	for(jj=1;jj<=100;jj++)
	{
		printf("%f\n",edge[jj]);
	}*/
	//printf("%lld %lld\n",node_collection[2].node_id,node_collection[3].node_id);
	//printf("%f %f %f %f\n",length_temp[1],length_temp[2],length_temp[3],length_temp[4]);
	/*int p=0;
	for(p;p<50;p++)
	{
		//printf("%lld %f %f\n", node_collection[p].node_id, node_collection[p].lat, node_collection[p].lon);
		
	}*/
	
	printf("Please enter the ID you want to start:");
	scanf("%d",&start_point);
	printf("Please enter the ID of your destination:");
	scanf("%ld",&destination_point);
	dijkstra(); 
	
	if(d[destination_point]>2147483640)
	{
		printf("There is no path from place %d to place %d.",start_point,destination_point);
		/*int h;
		for(h=0;h<100;h++)
		{
			printf("%f\n",d[h]);
		}*/
		/*int p;
		for(p=1;p<=3991;p++)
		{
			//printf("%lld %f %f\n",node_collection[p].node_id,node_collection[p].lat,node_collection[p].lon);
			//printf("%f\n",d[p]);
			printf("%f\n",d[p]);
		}*/
	}
	
	else  //1-2119
	{
		printf("The shortest distance from place %d to place %d is %f.\n",start_point, destination_point, d[destination_point]);
		printf("The path is: ");
		int t=destination_point,now=t;
		while(now!=-1)
		{
			path[path_len]=now;
			path_len++;
			now=pre[now];
		}
		
		for(o=path_len-1;o>=0;o--)
		{
			printf("%d ",path[o]);
		}
		printf("\n");
		
		FILE *wp;
		wp=fopen("path.dat","w");
		for(o=path_len-1;o>=0;o--)
		{
			fprintf(wp,"%f %f\n", node_collection[path[o]].lon, node_collection[path[o]].lat);
		}
		fclose(wp);
		
		printf("The path data has been writen in 'path.dat' successfully, use gnuplot to visualize it on map.\n");
		//int p;
		/*for(p=1;p<=1000;p++)
		{
			//printf("%lld %f %f\n",node_collection[p].node_id,node_collection[p].lat,node_collection[p].lon);
			//printf("%f\n",d[p]);
			printf("%f\n",d[p]);
		}*/
	}
	
	return 0;
	
	
	 
}
