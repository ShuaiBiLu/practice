#include<iostream>
using namespace std;

//clear() -- 清空队列
//isEmpty() -- 判断队列是否为空
//enqueue(el) -- 在队列尾部加入元素el
//dequeue() -- 取出队列的第一个元素
//firstEI() -- 返回队列的第一个元素，但不删除
template<typename T, int size = 100>

class ArrayQueue {
public:
		ArrayQueue(){
			first = last = -1;
		}
		void enqueue(T el) {
			if (!isFull()) {
				if (last == size - 1 || last == -1) {
					storage[0] = el;
					last = 0;
					if (first == -1) {
						first = 0;
					}
				}
				else storage[++last] = el;
			}
			else cout << "Full queue.\n" << endl;
		}
		T dequeue() {
			T tmp;
			tmp = storage[first];
			if (first == last) {
				last = first = -1;
			}
			else if (first == size - 1) {
				first = 0;
			}
			else first++;
			return tmp;
		}
		bool isFull() {
			return first == 0 && last == size - 1 || first == last + 1;
		}
		bool isEmpty() {
			return first == -1;
		}

private:
	int first, last;
	T storage[size];
};

int main() {
	ArrayQueue<int> queue;
	cout << "isEmpty-->" << queue.isEmpty() << endl;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << "isEmpty-->" << queue.isEmpty() << endl;
	getchar();
	return 0;
}