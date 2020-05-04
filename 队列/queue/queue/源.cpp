#include<iostream>
using namespace std;

//clear() -- ��ն���
//isEmpty() -- �ж϶����Ƿ�Ϊ��
//enqueue(el) -- �ڶ���β������Ԫ��el
//dequeue() -- ȡ�����еĵ�һ��Ԫ��
//firstEI() -- ���ض��еĵ�һ��Ԫ�أ�����ɾ��
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