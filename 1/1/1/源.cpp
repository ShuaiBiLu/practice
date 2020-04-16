#include<iostream>
#include<string>
#include<memory>
#include<ctime>
using namespace std;

template<typename T>
struct ListNode {
	ListNode* ptr;
	T Num;
};

template<typename T>
void InitList(ListNode<T>* ptr) {
	if (nullptr != ptr)
	{
		delete ptr;
	}

	ptr = new ListNode<T>;
};


int main()
{
	ListNode<int>* List;
	InitList(List);
	return 0;
}

int main2()
{
	int i = 0;
	int arr[3] = { 0 };
	for (;i <= 3; i++)
	{
		arr[i] = 0;
		printf("hello world!\n");
	}
	getchar();
	return 0;
}
int main3()
{
	main2();
	return 0;
}
int main1()
{
	clock_t start, finish;
	double duration;
	int* arr = new int[64 * 1024 * 1024];
	start = clock();
	for (int i = 0; i < 64 * 1024 * 1024; i+=4)
	{
		arr[i] *= 3;
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f seconds\n", duration);
	//---------------------------------------------------
	start = clock();
	for (int i = 0; i < 64 * 1024 * 1024; i+=16)
	{
		arr[i] *= 3;
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f seconds\n", duration);
	while (1);
	return 0;
}