#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Nope.cpp"

using namespace std;

/* Ngan xep nay su dung danh sach lien ket don.
 * Ta se them cac phan tu vao dau danh sach lien ket.*/
template <class typeOfDataStack>
class CStack
{
private:
public:
	CNopeStack<typeOfDataStack> *m_top;
	
	CStack();
	/* Constructor kien tao mot ngan xep rong.
	 * */

	CStack(const CStack &stack_parameter);
	/* Constructor copy.
	 * */

	~CStack();
	/* Destructor.
	 * */

	CStack operator = (const CStack &stack_parameter);
	/* Dinh nghia toan tu gan.
	 * */

	bool isStackEmpty();
	/* Postcondition: tra ve true neu ngan xep rong,
	 * tra ve false neu ngan xep khong rong.
	 * */

	void push(const typeOfDataStack &data_parameter);
	/* Them mot phan tu vao dinh cua ngan xep.
	 * Postcondition: phan tu data_parameter tra thanh 
	 * dinh cua ngan xep.
	 * */

	typeOfDataStack pop();
	/* Xoa phan tu o dinh cua ngan xep, dong thoi tra ve 
	 * phan tu dinh.
	 * Precondition: ham isStackEmpty() tra ve false.
	 * Postcondition: phan tu o dinh vi loai khoi ngan xep
	 * va tra ve phan tu do.
	 * */

	typeOfDataStack getTop();
	/* Tra ve gia tri cua phan tu o dinh cua ngan xep.
	 * Precondition: ham isStackEmpty() tra ve false.
	 * Postcondition: tra ve phan tu o dinh cua ngan xep.
	 * */
};

template<class typeOfDataStack>
CStack<typeOfDataStack>::CStack()
{
	m_top = NULL;
}

template<class typeOfDataStack>
CStack<typeOfDataStack>::CStack(const CStack<typeOfDataStack> &S)
{
	
}

template<class typeOfDataStack>
CStack<typeOfDataStack>::~CStack()
{
	if (isStackEmpty())
	/* Neu ngan xep rong.*/
	{
	    /* Thi khong lam gi ca.*/
	}
	else
	/* Neu ngan xep khong rong.*/
	{
		/* Thu hoi tung thanh phan.*/
		while (m_top->m_next != NULL)
		/* Duyet qua tat ca thanh phan trong ngan xep
		 * cho den khi ngan xep con lai 1 phan tu.
		 * */
		{
			CNopeStack<typeOfDataStack> *old_top = m_top;
			m_top = m_top->m_next;
			delete old_top;
		} // End while.

		delete m_top;
	}
}

template<class typeOfDataStack>
CStack<typeOfDataStack> CStack<typeOfDataStack>::operator = (const CStack<typeOfDataStack> &S)
{
	
}

template<class typeOfDataStack>
bool CStack<typeOfDataStack>::isStackEmpty()
{
	return m_top == NULL;
}

template<class typeOfDataStack>
void CStack<typeOfDataStack>::push(const typeOfDataStack &data_parameter)
{
	/* Tao mot thanh phan moi de chua du lieu
	 * truyen vao.
	 * */
	CNopeStack<typeOfDataStack> *new_nope = new CNopeStack<typeOfDataStack>(data_parameter);
		
	if (isStackEmpty())
	/* Neu ngan xep ban dau rong.*/
	{
		m_top = new_nope;
	}
	else
	/* Neu ngan xep ban dau khong rong.*/
	{
		/* Thi ta chen phan tu moi vao dau ngan xep.*/
		new_nope->m_next = m_top;
		m_top = new_nope;
	}
}

template<class typeOfDataStack>
typeOfDataStack CStack<typeOfDataStack>::pop()
{
	if (!isStackEmpty())
	/* Neu ngan xep khong rong.*/
	{
		typeOfDataStack data_from_top = m_top->m_data;
	    CNopeStack<typeOfDataStack> *old_top = m_top;
		m_top = m_top->m_next;

		delete old_top; // Giai phong bo nho.
		return data_from_top;
	}
}

template<class typeOfDataStack>
typeOfDataStack CStack<typeOfDataStack>::getTop()
{
	if (!isStackEmpty())
	/* Neu ngan xep khong rong.*/
	{
	    return m_top->m_data;
	}
}
