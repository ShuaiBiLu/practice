#include<iostream>
#include<string>
#include<memory>
#include<ctime>
using namespace std;

template<typename T>
class List
{
	class ListNode
	{
	public:
		//初始化链表头,并初始化值
		ListNode(T t) {
			Nodeptr = nullptr;
			Num = t;
		};

	public:
		ListNode* Nodeptr = nullptr;
		T Num;
	};
public:
	void InitList() {
		head = nullptr;
		ListLength = 0;
	};

	bool IsEmpty() {
		if (head == nullptr)
			return true;
		else
			return false;
	};

	void AddToHead(T t) {
		if (IsEmpty()) {
			ListNode* temp = new ListNode(t);
			head = temp;
			temp = nullptr;
		}
		else {
			ListNode* temp = new ListNode(t);
			temp->Nodeptr = head;
			head = temp;
			temp = nullptr;
		}	
		ListLength += 1;
	};

	void AddToTail(T t) {
		ListNode* temp = head;
		ListNode* end = head;
		while (temp != nullptr) {
			temp = temp->Nodeptr;	
			if (temp != nullptr) {
				end = temp;
			}
			else {
				temp = new ListNode(t);
				end->Nodeptr = temp;
				temp = nullptr;
			}
		}
	};

	void printList() {
		ListNode* temp = head;
		cout << "Listhead" << "-->";
		while (temp != nullptr)
		{
			cout << temp->Num;
			temp = temp->Nodeptr;
			if (temp != nullptr)
				cout << "-->";
			else
				;
		}
	};

private:
	ListNode* head = nullptr;
	int ListLength = 0;
};

int main()
{

	List<char>list;
	list.InitList();
	if (true == list.IsEmpty())
		cout << "isEmpty" << endl;
	else
		cout << "isNotEmpty" << endl;
	list.AddToHead('k');
	list.AddToHead('c');
	list.AddToHead('u');
	list.AddToHead('f');
	list.AddToTail('u');
	list.AddToTail('!');
	list.printList();
	getchar();
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