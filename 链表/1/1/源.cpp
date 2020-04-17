#include<iostream>
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

	void clear() {
		if (IsEmpty())
			return;
		else {
			ListNode* temp = head;
			while (head != nullptr) {
				 temp = head->Nodeptr;
				 delete head;
				 head = temp;
			}
			head = nullptr;
		}
		ListLength = 0;
	}

	bool IsEmpty() {
		if (head == nullptr)
			return true;
		else
			return false;
	};

	bool Insert(T t, int p) {
		if ((p > ListLength) || (p < 1)) {
			return false;
		}
		else {
			int Num = 1;
			ListNode* temp = head;
			if (1 == p) {
				ListNode* insert = new ListNode(t);
				insert->Nodeptr = head->Nodeptr;
				head = insert;
			}
			else {
				while (Num < p) {
					Num++;
					if (Num == p) {
						ListNode* insert = new ListNode(t);
						insert->Nodeptr = temp->Nodeptr;
						temp->Nodeptr = insert;
					}
					temp = temp->Nodeptr;
				}
			}	
			ListLength += 1;
			return true;
		}	
	}

	bool Delete(int p) {
		if ((p > ListLength) || (p < 1)) {
			return false;
		}
		else {
			int Num = 1;
			ListNode* temp = head;
			if (1 == p) {
				head = head->Nodeptr;
				delete temp;
			}
			else {
				while (Num != p) {
					Num++;
					if (Num == p) {			
						ListNode* deltemp = temp->Nodeptr;
						temp->Nodeptr = temp->Nodeptr->Nodeptr;
						delete deltemp;
					}
					temp = temp->Nodeptr;
				}
			}
			ListLength -= 1;
			return true;
		}
	}

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
		if (!IsEmpty()) {
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
		}
		else {
			head = new ListNode(t);
		}
		ListLength += 1;
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
	//ListNode* end = nullptr;
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
	list.clear();
	cout << endl;
	list.printList();
	cout << endl;
	list.AddToTail('x');
	list.AddToTail('i');
	list.AddToTail('a');
	list.AddToTail('o');
	list.AddToTail('j');
	list.AddToTail('i');
	list.AddToTail('e');
	list.AddToTail('j');
	list.AddToTail('i');
	list.AddToTail('e');
	list.AddToTail('!');
	list.Insert('2', 2);
	list.printList();
	cout << endl;
	list.Delete(3);
	list.printList();
	list.clear();
	cout << endl;
	list.printList();
	getchar();
	return 0;
}
