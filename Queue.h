#pragma once
#include "Node.h"
#include "Llista.h"

template <class T1>
class Queue :public Llista<T1> {
public:
	Queue() { m_last = 0; }
	//Queue(const Queue<T1> &q) :Llista(q.m_first) { m_last = q.m_last; }
	~Queue();
	//Queue& operator=(const Queue& q);

	bool empty();
	T1& getFirst();
	void add(const T1& valor);
	void remove();
	T1& getLast();


private:
	Node<T1>* m_last;

};

template <class T1>
Queue<T1>::~Queue() {
	while (this->m_first != 0)
		Llista<T1>::eliminateNext(0);

}

/*
template <class T1>
Queue& Queue<T1>::operator=(const Queue& q) {
m_first = q.m_first;
m_last = q.m_last;
return *this;
}
*/

template <class T1>
T1& Queue<T1>::getLast() {
	return m_last->getValor();
}

template <class T1>
T1& Queue<T1>::getFirst() {
	return Llista<T1>::getFirst();
}

template <class T1>
void Queue<T1>::add(const T1& valor) {
	if (empty()) {
		Llista<T1>::addNext(valor, m_last);
		m_last = this->m_first;
	}
	else {
		Llista<T1>::addNext(valor, m_last);
		m_last = m_last->getNext();
	}
}

template <class T1>
void Queue<T1>::remove() {
	Llista<T1>::eliminateNext(0);
}

template <class T1>
bool Queue<T1>::empty() {
	return Llista<T1>::empty();
}