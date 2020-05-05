//*****************************genStack****************************
//         generic class for vector implementation of stack

#include<vector>
#include<iostream>
template<class T, int capacity = 30>
class Stack {
public:
	Stack() {
		pool.reserve(capacity);
	}
	void clear() {
		pool.clear;
	}
	bool isEmpty()const {
		return pool.empty();
	}
	T& topEL() {
		return pool.back();
	}
	T pop() {
		T el = pool.back();
		pool.pop_back();
		return el;
	}
	void push(const T& el) {
		pool.push_back(el);
	}

private:
	vector<T> pool;
};

//*****************************genListStack.h******************************
//			generic stack defined as doubly linked list

#include<list>

template<class T>
class LLStack {
public:
	LLStack() {
	}
	void clear() {
		lst.clear();
	}
	bool isEmpty()const {
		return lst.empty();
	}
	T& topEl() {
		return lst.back();
	}
	T pop() {
		T el = lst.back();
		lst.pop_back();
		return el;
	}
	void push(const T& el) {
		lst.push_back(el);
	}

private:
	list<T> lst;
};