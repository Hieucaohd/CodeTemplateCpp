#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Nope.cpp"

using namespace std;

/* Cai dat hang doi boi danh sach lien ket vong tron.*/
template <class typeOfDataQueue>
class CQueue
{
private:
	CNopeQueue<typeOfDataQueue> *m_tail;
public:
	CQueue();
	/* Constructor: khoi tao mot hang doi rong.
	 * */
	
	CQueue(const CQueue &Q);
	/* Constructor copy.
	 * */

	~CQueue();
	/* Destructor.
	 * */
	
	CQueue operator = (const CQueue &Q);
	/* Dinh nghia toan tu gan.
	 * */
	
	bool isQueueEmpty();
	/* Postcondition: tra ve true neu hang doi rong
	 * va tra ve false neu hang doi khong rong.
	 * */
	
	void enQueue(const typeOfDataQueue & data_parameter);
	/* Them phan tu vao duoi hang doi.
	 * Postcondition: phan tu duoc them vao cuoi hang doi.
	 * */

	typeOfDataQueue deQueue();
	/* Lay ra phan tu o dau hang doi, dong thoi 
	 * tra ve gia tri cua phan tu do
	 * Precondition: hang doi khong rong.
	 * Postcondition: xoa phan tu o dau hang doi,
	 * tra ve gia tri cua phan tu do.
	 * */
	
	typeOfDataQueue getHead();
	/* Tra ve phan tu o dau hang doi.
	 * Precondition: hang doi khong rong.
	 * Postcondition: tra ve gia tri cua phan tu o dau hang doi
	 * ma khong lam thay doi hang doi.
	 * */
};

template <class typeOfDataQueue>
CQueue<typeOfDataQueue>::CQueue()
{
	m_tail = NULL;
}

template <class typeOfDataQueue>
CQueue<typeOfDataQueue>::CQueue(const CQueue &Q)
{
	
}

template <class typeOfDataQueue>
CQueue<typeOfDataQueue>::~CQueue()
{
	/*comment*/
	if (isQueueEmpty())
	/* Neu hang doi rong.*/
	{
	    /* Thi khong lam gi ca.*/
	}
	else
	/* Neu hang doi khong rong.*/
	{
		while (m_tail->m_next != m_tail)
		/* Lap cho den khi hang doi con lai 1 phan tu.*/
		{
			/* Tao bien chay bien chay 
			 * chay tu phan tu head.*/
			CNopeQueue<typeOfDataQueue> *run = m_tail->m_next; 
			m_tail->m_next = m_tail->m_next->m_next;
			delete run;
		} // End while.

		delete m_tail;
	}
}

template <class typeOfDataQueue>
CQueue<typeOfDataQueue> CQueue<typeOfDataQueue>::operator = (const CQueue<typeOfDataQueue> &Q)
{
	
}

template <class typeOfDataQueue>
bool CQueue<typeOfDataQueue>::isQueueEmpty()
{
	return (m_tail == NULL);
}

template <class typeOfDataQueue>
void CQueue<typeOfDataQueue>::enQueue(const typeOfDataQueue & data_parameter)
{
	/* Tao mot phan tu moi.*/
	CNopeQueue<typeOfDataQueue> *new_nope = new CNopeQueue<typeOfDataQueue>(data_parameter);
	
	/* Them phan tu moi vao duoi hang doi.*/
	if (isQueueEmpty())
	/* Neu hang doi rong.*/
	{
	    m_tail = new_nope;
		m_tail->m_next = m_tail; // de tao danh sach lien ket vong tron.
	}
	else
	/* Neu hang doi khong rong.*/
	{
		new_nope->m_next = m_tail->m_next;
		m_tail->m_next = new_nope;
		m_tail = new_nope;
	}
}

template <class typeOfDataQueue>
typeOfDataQueue CQueue<typeOfDataQueue>::deQueue()
{
	if (!isQueueEmpty())
	/* Neu hang doi khong rong.*/
	{
		/* Lay du lieu tu phan tu head.*/
		typeOfDataQueue data_of_head = m_tail->m_next->m_data;

		/* Xoa phan tu head va thu hoi bo nho.*/
		if (m_tail->m_next == m_tail)
		/* Neu hang doi chi co mot phan tu.*/
		{
			delete m_tail; // thu hoi bo nho.
			m_tail = NULL; // cho hang doi thanh rong.
		}
		else
		/* Neu hang doi co tu 2 phan tu tro len.*/
		{
			CNopeQueue<typeOfDataQueue> *old_head = m_tail->m_next;
			/* Cho phan tu head tro den phan tu tiep theo.*/
			m_tail->m_next = m_tail->m_next->m_next; 
			delete old_head; // thu hoi bo nho.
		}

		return data_of_head;    
	}
	else
	/* Neu hang doi rong.*/
	{
		typeOfDataQueue null_return;
		return null_return;
	}
}

template <class typeOfDataQueue>
typeOfDataQueue CQueue<typeOfDataQueue>::getHead()
{
	if (!isQueueEmpty())
	/* Neu hang doi khong rong.*/
	{
		return m_tail->m_next->m_data;
	}
	else
	/* Neu hang doi rong.*/
	{
		typeOfDataQueue null_return;
		return null_return;
	}
}