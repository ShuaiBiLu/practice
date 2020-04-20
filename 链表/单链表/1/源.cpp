#include<iostream>
using namespace std;

template<typename T>
class ListNode
{
public:
	ListNode(T t) {
		Nodeptr = nullptr;
		Num = t;
	};

public:
	ListNode* Nodeptr = nullptr;
	T Num;
};

template<typename T>
class List
{

public:
	void InitList() {
		head = nullptr;
		ListLength = 0;
	};

	void clear() {
		if (IsEmpty())
			return;
		else {
			ListNode<T>* temp = head;
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
			ListNode<T>* temp = head;
			if (1 == p) {
				ListNode<T>* insert = new ListNode<T>(t);
				insert->Nodeptr = head->Nodeptr;
				head = insert;
			}
			else {
				while (Num < p) {
					Num++;
					if (Num == p) {
						ListNode<T>* insert = new ListNode<T>(t);
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
			ListNode<T>* temp = head;
			if (1 == p) {
				head = head->Nodeptr;
				delete temp;
			}
			else {
				while (Num != p) {
					Num++;
					if (Num == p) {			
						ListNode<T>* deltemp = temp->Nodeptr;
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
			ListNode<T>* temp = new ListNode<T>(t);
			head = temp;
			temp = nullptr;
		}
		else {
			ListNode<T>* temp = new ListNode<T>(t);
			temp->Nodeptr = head;
			head = temp;
			temp = nullptr;
		}	
		ListLength += 1;
	};

	void AddToTail(T t) {
		ListNode<T>* temp = head;
		ListNode<T>* end = head;
		if (!IsEmpty()) {
			while (temp != nullptr) {
				temp = temp->Nodeptr;
				if (temp != nullptr) {
					end = temp;
				}
				else {
					temp = new ListNode<T>(t);
					end->Nodeptr = temp;
					temp = nullptr;
				}
			}
		}
		else {
			head = new ListNode<T>(t);
		}
		ListLength += 1;
	};

	void printList() {
		ListNode<T>* temp = head;
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
	ListNode<T>* head = nullptr;
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
