#pragma once
#include "Llista.h"

template <class T1>
class Stack : public Llista<T1> {
public:
	Stack() { }
	//Stack(Node<T1>* s):Llista(s){}
	~Stack() { Llista<T1>::~Llista(); }
	//Stack& operator=(const Stack& s);

	void push(const T1& valor);
	void pop();
	T1& top();
private:

};

/*
template <class T1>
Stack& Stack<T1>::operator=(const Stack& s) {
m_first = s.m_first;
return *this;
}
*/
template <class T1>
void Stack<T1>::push(const T1& valor) {
	Llista<T1>::addNext(valor, 0);
}

template <class T1>
void Stack<T1>::pop() {
	Llista<T1>::eliminateNext(0);
}

template <class T1>
T1& Stack<T1>::top() {
	return Llista<T1>::getFirst();
}
