#include "main.h"
//#include "get_map.h"
#include "unity.h"
#include<stdio.h>



void test_build_max_heap()
{
	APQ t1[5];
	t1[1].dist=1.4;
	t1[1].node_id=1;
	
	t1[2].dist=5.3;
	t1[2].node_id=2;
	
	t1[3].dist=4.1;
	t1[3].node_id=3;
	
	t1[4].dist=9.9;
	t1[4].node_id=4;
	
	t1[5].dist=10.2;
	t1[5].node_id=5;
	
	
	build_max_heap(t1,5);
	if(t1[1].dist==10.2&&t1[2].dist==9.9&&t1[3].dist==4.1&&t1[4].dist==1.4&&t1[5].dist==5.3)  //父节点总比儿子节点更大 
	{
		int a=1;
		TEST_ASSERT_EQUAL_INT(a,1);
	}
	
	else
	{
		int a=0;
		TEST_ASSERT_EQUAL_INT(a,1);
	}
}



void test_heap_sort()
{
	APQ t1[5];
	t1[1].dist=1.4;
	t1[1].node_id=1;
	
	t1[2].dist=5.3;
	t1[2].node_id=2;
	
	t1[3].dist=4.1;
	t1[3].node_id=3;
	
	t1[4].dist=9.9;
	t1[4].node_id=4;
	
	t1[5].dist=10.2;
	t1[5].node_id=5;
	
	heap_sort(t1,5);
	if(out[1].dist==1.4&&out[2].dist==4.1&&out[3].dist==5.3&&out[4].dist==9.9&&out[5].dist==10.2)  //堆排序测试 
	{
		APQ t2[2];
		t2[1].dist=1.7;
		t2[1].node_id=1;
		heap_sort(t2,1);
		if(out[1].dist==1.7)  //边界情况 
		{
			int b=1; 
			TEST_ASSERT_EQUAL_INT(b,1);
		}
		
		else
		{
			int b=0;
			TEST_ASSERT_EQUAL_INT(b,1);
		}
		
	}
	
	else
	{
		int b=0;
		TEST_ASSERT_EQUAL_INT(b,1);
	}
}



void test_dijkstra()
{
	
	int pre[100010];
	int path_len=0;
	int path[100010];
	int destination_point=7;
	
	
	dijkstra();
	int o;
	for(o=0;o<100010;o++)
	{
		pre[o]=-1;
	}
	
	if(d[1]==0&&d[2]==7&&d[3]==10&&d[4]==5&&d[5]==10&&d[6]==14&&d[7]==12) //到各节点的距离 
	{
		/*int t=destination_point,now=t;
		while(now!=-1)
		{
			path[path_len]=now;
			path_len++;
			now=pre[now];
		}
		
		for(o=path_len-1;o>=0;o--)
		{
			printf("%d ",path[o]);
		}*/
		
		int c=1;
		TEST_ASSERT_EQUAL_INT(c,1);
		
	}
	
	else
	{
		int c=0;
		TEST_ASSERT_EQUAL_INT(c,1);
	}
}

void setUp()
{

}

void tearDown()
{

}


int main(int argc, char *argv[])
{
	UNITY_BEGIN();
	
	RUN_TEST(test_build_max_heap);
	RUN_TEST(test_heap_sort);
	
	start_point=1;
	destination_point=7;
	
	int i;
	for(i=0;i<=10001;i++)
	{
		ver[i]=0;
		edge[i]=0;
		next[i]=0;
		head[i]=0;
	}
	
	add(1,4,5);
	add(1,3,10);
	add(4,5,15);
	add(2,5,3);
	add(3,5,6);
	add(3,6,4);
	add(5,7,2);
	add(6,7,7);
	add(1,2,7);
	
	RUN_TEST(test_dijkstra);
	return UNITY_END();
}
