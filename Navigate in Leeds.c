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
	/*int ret = heap[0]; //�󶥶ѵ����ֵ
	int x = heap[--sz]; // ȡ���һ��Ԫ�أ�����ɾ�� ����ΪҪ��֤����ȫ������������ȡ���һ���� 
	int i = 0; //��x�ŵ���ͷ 
	while(i*2+1 < sz){
		int l = i*2 + 1; //���� 
		int r = i*2 + 2; //�Һ��� 
		if(r < sz && heap[l] < heap[r]) l = r; //���������нϴ�� ��Ϊl,heap[l] 
		if(x > heap[l]) break; //���x �����������Ӷ�����Ϊ�����Ѿ���֤�Ǵ󶥶��ˣ�����x�ŵ��� 
		heap[i] = heap[l];//���� �ϴ��������ӽڵ�����ȥ�����ϴ�ĺ��ӽڵ㣨��ʱΪx����Ϊ��һ���ڵ㣬���������� 
		i = l;
	} 
	heap[i] = x;*/
	return;
}






void adjust_down(APQ a[],int father,int n)
{
//��Ԫ��father���µ���
    int son;
    APQ store;
    store.dist=a[father].dist;
    store.node_id=a[father].node_id;
    
    //����key�ϴ���ӽ������ɸѡ
    for (son=2*father;son<=n;son*=2)  //ÿ��ѭ��֮����δ�����߽磬���������ҵ�ǰ�ڵ������ 
	{ 
    	 
        if(son<n&&a[son].dist<a[son+1].dist)
		{
            son++;   //���Ӳ������һ���ڵ����Һ��ӱ����Ӹ�������о�����������Һ����� 
        }
        
        
        if(a[father].dist>=a[son].dist)   //���ø��ڵ�����ĺ��ӽڵ㻹Ҫ���������ٵ��� 
        {
        	continue;
		}
		
        else 
		{
            a[father].dist=a[son].dist;   //��a[son]�������������
            a[father].node_id=a[son].node_id;
            a[son].dist=store.dist;
            a[son].node_id=store.node_id;
            father=son;	   //�޸�fatherֵ���Ա��������ɸѡ
        }
    }
    
    //a[father]=store;			//��ɸѡ��ֵ�������յ�λ��
    return;
}



void build_max_heap(APQ a[],int n)
{
    int i;
    for (i=n/2;i>0;i--) 
	{
        adjust_down(a,i,n);  //�ӵ����ڶ����������͵ĸ��ڵ�㣩 
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
    	build_max_heap(a,j); //�Ƚ�����
    
    	/*for(int i=1;i<=n;i++)
    	{
    		printf("\n");
    		printf("%lf ",a[i]);
		}*/
		
		out[j].dist=a[1].dist; //ÿ��ȡ�Ѷ��ĵ�ǰ���Ԫ�ط���β��
		out[j].node_id=a[1].node_id;
		 
		a[1].dist=a[j].dist;
		a[1].node_id=a[j].node_id;
		
	}
	return;
    
}



void push(APQ x)
{
	sz++;
	int i=sz; //i��ʾx�����һ�����ı�� ͬʱ������һ 
	out[sz].dist=x.dist;   
	out[sz].node_id=x.node_id; //��out�Ķ�β����һ��push����Ԫ��
	//printf("%d\n",out[sz].node_id);
	int j;
	for(j=1;j<=sz;j++)
	{
		list[j].dist=out[j].dist;  
		list[j].node_id=out[j].node_id;  //��listά���ɺ�outһ�� 
	}
	

	heap_sort(list,sz);
	
	/*printf("%d\n",out[sz].node_id);
	printf("%f\n",out[sz].dist);
	printf("%d\n",list[sz].node_id);
	printf("%f\n",list[sz].dist);*/
	/*while(i>0)
	{
		int p=i/2;
		if(out[p]>=x)   //���ĳ��heap[i]�ĸ��ڵ������ �Ͱ�x�ŵ����� 
		{
			out[i]=x;
			break;
		}
		out[i]=out[p];//���� ���ڵ����� Ȼ���ٽ�������ڵ㣨��ʱΪx��������һ���ӽڵ㣬�������� 
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


//��Ŵ�1��ʼ1��С���� 
void dijkstra() 
{
	int y=0;
	for(y;y<=100010;y++)
	{
		d[y]=2147483647;
	}
	memset(v,0,sizeof(v)); 
	d[start_point]=0;  //�����������ʼ��Ϊ0 
	/*for(y=0;y<10;y++)
	{
		printf("%f\n",d[y]);
	}*/
	
	APQ first;  //��ʼ���ʼ�� 
	first.dist=0;
	first.node_id=start_point;
	
	push(first);  //����ʼ������ 
	
	//printf("%d\n\n",out[1].node_id);
	/*int w;
	for(w=1;w<=10;w++)
	{
		printf("%d\n",list[w].node_id);
		printf("%d\n",out[w].node_id);
	}*/
	
	while (sz!=0) 
	{
		
		int x = out[1].node_id; //�Ѷ���Ԫ�� ����ڵ�ı�� 
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
		
		
		
		
		
		
		if (v[x])  //��������Ѿ����������� 
		{
			continue;
		}
		
		v[x] = 1;
		
		int i;
		for (i = head[x]; i; i = next[i]) //��ǰ�ڵ�����ָ��ı� 
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
