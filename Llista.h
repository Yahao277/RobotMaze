#pragma once
#pragma once
#include "Node.h"

template <class T1>
class Llista {
public:
	Llista() { m_first = 0; }
	//Llista(Node<T1>* f) { m_first->setValor(f->getValor); m_first->setNext(f->getNext()); }
	//Llista(const Llista<T1> &l) :{m_first = l.m_first; }
	~Llista();
	//Llista& operator=(const Llista& l);

	bool empty() const;
	T1& getFirst() const;
	void addNext(const T1& valor, Node<T1> *posicio);
	void eliminateNext(Node<T1>* posicio);


protected:
	Node<T1>* m_first;
};
/*
template <class T1>
Llista& Llista<T1>::operator=(const Llista& l) {
m_first = l.m_first;
return *this;
}
*/

template <class T1>
Llista<T1>::~Llista() {
	while (m_first != 0)
		eliminateNext(0);

}

template <class T1>
bool Llista<T1>::empty() const
{
	return (m_first == 0);
}

template <class T1>
T1& Llista<T1>::getFirst() const
{
	return m_first->getValor();
}

template <class T1>
void Llista<T1>::addNext(const T1& valor, Node<T1> *posicio)
{
	Node<T1>* aux = new Node<T1>();
	if (aux != 0)
	{
		aux->setValor(valor);
		if (posicio == 0)
		{
			aux->setNext(m_first);
			m_first = aux;
		}
		else
		{
			aux->setNext(posicio->getNext());
			posicio->setNext(aux);
		}
	}
	//return aux;
}

template <class T1>
void Llista<T1>::eliminateNext(Node<T1>* posicio)
{
	Node<T1>* aux;
	Node<T1>* seguent = 0;
	if (posicio == 0)
	{
		aux = m_first;
		m_first = aux->getNext();
		delete aux;
		seguent = m_first;
	}
	else
	{
		aux = posicio->getNext();
		if (aux != 0)
		{
			posicio->setNext(aux->getNext());
			seguent = aux->getNext();
			delete aux;
		}
	}
	//return seguent;
}

