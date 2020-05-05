#include<list>
#include<iostream>
#include<string>
using namespace std;
template<class T>
class Queue
{
public:
	Queue(){
	}
	//��ն���
	void clear() {
		lst.clear();
	}
	//�����Ƿ�Ϊ��
	bool isEmpty()const {
		return lst.empty();
	}
	//���ض���Ԫ��
	T& front() {
		return lst.front();
	}
	//����
	T dequeue() {
		T el = lst.front();
		lst.pop_front();
		return el;
	}
	//���
	void enqueue(const T& el) {
		lst.push_back(el);
	}
private:
	list<T>lst;
};

int main() {
	Queue<string> queue;
	cout << "queue isEmpty?-->" << queue.isEmpty() << endl;
	queue.enqueue("I");
	queue.enqueue("love");
	queue.enqueue("JiaJia");
	queue.enqueue("I");
	queue.enqueue("love");
	queue.enqueue("JiaJia");
	cout << queue.dequeue() << queue.dequeue() << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	string a, b, c;
	a = "I";
	b = "Love";
	c = "JiaJia";
	cout << a << b << c;
	getchar();
 	return 0;
}