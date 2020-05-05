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
	//清空队列
	void clear() {
		lst.clear();
	}
	//队列是否为空
	bool isEmpty()const {
		return lst.empty();
	}
	//返回队首元素
	T& front() {
		return lst.front();
	}
	//出队
	T dequeue() {
		T el = lst.front();
		lst.pop_front();
		return el;
	}
	//入队
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