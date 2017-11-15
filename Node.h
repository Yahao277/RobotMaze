#pragma once

template <class T1>

class Node {
public:
	Node() :m_valor(T1()), m_next(0) {}
	Node(const T1& valor) :m_valor(valor), m_next(0) {}
	~Node() { m_next = 0; }
	void setValor(T1 x) { m_valor = x; }
	void setNext(Node<T1>* y) { m_next = y; }
	T1& getValor() { return m_valor; }
	Node<T1>* getNext() { return m_next; }

private:
	T1 m_valor;
	Node<T1>* m_next;
};