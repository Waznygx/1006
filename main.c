#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for ( i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("haha\n");
//	}
//	return 0;
//}
////输出：13个haha

//#define NUM 12
//int main()
//{
//	int arr[NUM] = { 0 };
//	int* ptr = NULL;
//	ptr = (int*)malloc(NUM * sizeof(int));
//	if (ptr != NULL)
//	{
//		int i = 0;
//		for ( i = 0; i < NUM; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}

//int main()
//{
//	int* p = calloc(10, sizeof(int));
//	if (p != NULL)
//	{
//		;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		perror("main");
//		return 1;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = 5;
//	}
//	int* ptr = (int*)realloc(p, 40);
//	if (ptr != NULL)
//	{
//		p = ptr;
//		free(p);
//		p = NULL;
//	}
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	*p = 20;
//	free(p);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for ( i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;
//	}
//	free(p);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(10* sizeof(int));
//	p++;
//	free(p);//此时p不再指向动态内存的起始地址
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);//重复释放
//	return 0;
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	if (p != NULL)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test(); 
//	while (1);
//	return 0;
//}

//#include<string.h>
//void getmemory(char** p)
//{
//	*p = (char*)malloc(100);
//	if (*p == NULL)
//	{
//		perror("getmemory");
//	}
//}
//void test(void)
//{
//	char* str = NULL;
//	getmemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}

//char* getmemory()
//{
//	char(*p)[] = "hello world";
//	return p;
//}
//void test()
//{
//	char* str = NULL;
//	str = getmemory();
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}

//#include<string.h>
//char* getmemory(char**p,int num)
//{
//	*p = (char*)malloc(num);
//}
//void test()
//{
//	char* str = NULL;
//	getmemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}

//#include<string.h>
//void test()
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}

//typedef struct stu
//{
//	double d; 
//	int a[0];//柔性数组成员
//}s;
//int main()
//{
//	s* p = (s*)malloc(sizeof(s) + 100 * sizeof(int)); 
//	int i = 0;
//	p->d = 100.0;
//	for ( i = 0; i < 100; i++)
//	{
//		p->a[i] = i;
//	}
	//free(p);
	//p = NULL;
	//return 0;
//}

typedef struct stu
{
	double d;
	int* pa;
}s;
int main()
{
	//为结构体申请空间
	s* p = (s*)malloc(sizeof(s));
	p->d = 100.0;
	//为结构体 s 中的整数指针 pa 分配内存
	p->pa = (int*)malloc(p->d * sizeof(int));
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		p->pa[i] = i;
	}
	//后申请的先释放
	free(p->pa);
	p->pa = NULL;
	free(p);
	p = NULL;
	return 0;
}