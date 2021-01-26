#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "LinkedList.cpp"
#include "Nope.cpp"

using namespace std;

/* NOTE: phai them cac phan tu du lieu trong danh sach 
 * truoc khi khoi tai iterator cho danh sach do.*/
template <class typeOfDataList>
class CListIterator
{
private:
	CNopeList<typeOfDataList> *m_current;
	CLinkedList<typeOfDataList> *m_List_ptr;
public:
	CListIterator(CLinkedList<typeOfDataList> &L);
	/* Constructor kien tao.*/

	~CListIterator();
	/* Destructor.*/
	
	void start();
	/* Postcondition: vi tri hien thoi la vi tri
	 * dau tien trong danh sach.
	 * */

	void advance();
	/* Postcondition: vi tri hien thoi la vi tri 
	 * tiep theo trong danh sach, neu vi tri hien thoi 
	 * dang o cuoi danh sach thi vi tri tiep theo se la
	 * vi tri dau tien trong danh sach.
	 * */

	bool valid();
	/* Postcondition: tra ve true neu vi tri hien thoi 
	 * trong danh sach va tra ve false neu khong.
	 * */
	
	typeOfDataList current();
	/* Precondition: ham valid() tra ve true.
	 * Postcondition: tra ve phan tu hien thoi 
	 * trong danh sach.
	 * */
	
	void add(const CNopeList<typeOfDataList> &data_parameter);
	/* Them phan tu vao vi tri hien thoi.
	 * Precondition: ham valid() tra ve true.
	 * Postcondition: nope_parameter duoc them vao vi tri
	 * hien thoi, phan tu hien thoi van la phan tu hien thoi.
	 * */
	
	void remove();
	/* Precondition: ham valid() tra ve true.
	 * Postcondition: phan tu hien thoi vi loai ra khoi danh sach,
	 * phan tu di sau no tro thanh phan tu hien thoi.
	 * */
};

template <class typeOfDataList>
CListIterator<typeOfDataList>::CListIterator(CLinkedList<typeOfDataList> &L)
{
	m_List_ptr = &L;
	m_current = m_List_ptr->m_head;
}

template <class typeOfDataList>
CListIterator<typeOfDataList>::~CListIterator()
{
	
}

template <class typeOfDataList>
void CListIterator<typeOfDataList>::start()
{
	m_current = m_List_ptr->m_head->m_next;
}

template <class typeOfDataList>
void CListIterator<typeOfDataList>::advance()
{
	/* Dua vi tri hien thoi la vi tri tiep theo 
	 * trong danh sach.
	 * */
	m_current = m_current->m_next;
}

template <class typeOfDataList>
bool CListIterator<typeOfDataList>::valid()
{
	return m_current != m_List_ptr->m_head;
}

template <class typeOfDataList>
typeOfDataList CListIterator<typeOfDataList>::current()
{
	if (valid())
	/* Neu vi tri hien thoi co trong danh sach.*/
	{
	    return m_current->m_data;
	}
	else
	/* Neu vi tri hien thoi khong trong danh sach.*/
	{
		typeOfDataList null_return;
		return null_return;
	}
}

template <class typeOfDataList>
void CListIterator<typeOfDataList>::add(const CNopeList<typeOfDataList> &data_parameter)
{
	if (valid())
	/* Neu phan tu hien thoi nam trong danh sach.*/
	{
		/* Tao phan tu moi.*/
	    CNopeList<typeOfDataList> *new_nope = new CNopeList<typeOfDataList>(data_parameter);

		/* Them vao.*/
		m_current->m_precede->m_next = new_nope;
		new_nope->m_precede = m_current->m_precede;

		m_current->m_precede = new_nope;
		new_nope->m_next = m_current;

		m_List_ptr->m_length += 1;
	}
	else
	/* Neu vi tri hien thoi khong nam trong danh sach.*/
	{
		cout << "Vi tri hien thoi khong nam trong danh sach." << endl;
	}
}

template <class typeOfDataList>
void CListIterator<typeOfDataList>::remove()
{
	if (valid())
	/* Neu vi tri hien thoi nam trong danh sach.*/
	{
		CNopeList<typeOfDataList> *pre_ptr = m_current->m_precede;
		CNopeList<typeOfDataList> *next_ptr = m_current->m_next;

		pre_ptr->m_next = next_ptr;
		next_ptr->m_precede = pre_ptr;
		
		CNopeList<typeOfDataList> *delete_ptr = m_current;
		m_current = m_current->m_next;
		delete delete_ptr;

		m_List_ptr->m_length -= 1;
	}
	else
	/* Neu vi tri hien thoi khong nam trong danh sach.*/
	{
		cout << "Vi tri hien thoi khong nam trong danh sach." << endl;
	}
}
