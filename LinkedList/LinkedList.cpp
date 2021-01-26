#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Nope.cpp"

using namespace std;

/* Khai bao truoc cong cu lap.*/
template <class typeOfDataList>
class CListIterator;

/* Cai dat boi danh sach lien ket kep, vong tron, dau gia.*/
template <class typeOfDataList>
class CLinkedList
{
private:
	int m_length; // do dai cua danh sach.
	CNopeList<typeOfDataList> *m_head; // con tro dau.
public:
	friend class CListIterator<typeOfDataList>;
	/* Khai bao cong cu lap.*/

	CLinkedList();
	/* Khoi tao mot danh sach rong.
	 * */

	CLinkedList (const CLinkedList &L);
	/* Constructor copy.
	 * */
		
	~CLinkedList();
	/* Destructor.
	 * */

	CLinkedList operator = (const CLinkedList &L);
	/* Dinh nghia toan tu gan.
	 * */

	bool isListEmpty();
	/* Postcondition: tra ve true neu danh sach rong 
	 * va false neu danh sach khong rong.
	 * */

	int length();
	/* Postcondition: tra ve so luong phan tu trong danh sach.
	 * */

	void insertElement(const typeOfDataList &data_parameter, int position);
	/* Chen phan tu data_parameter vao vi tri position 
	 * trong danh sach.
	 * Precondition: 1 <= position <= m_length.
	 * Postcondition: phan tu moi duoc chen vao vi tri position.
	 * */

	void appendElement(const typeOfDataList &data_parameter);
	/* Xen phan tu vao duoi danh sach.
	 * */
	
	void deleteElement(int position);
	/* Loai phan tu o vi tri postion trong danh sach.
	 * Precondition: 1 <= position <= m_length.
	 * Postcondition: phan tu o vi tri position 
	 * bi loai khoi danh sach.
	 * */
		
	typeOfDataList findElement(int postion);
	/* Tim phan tu o vi tri position trong danh sach.
	 * Precondition: 1 <= position <= m_length.
	 * Postcondition: tra ve phan tu o vi tri position 
	 * trong danh sach.
	 * */
};

template <class typeOfDataList>
CLinkedList<typeOfDataList>::CLinkedList()
{
	m_head = new CNopeList<typeOfDataList>(0); // 0 la con so bat ki.
	m_head->m_next = m_head;
	m_head->m_precede = m_head;
	
	/* Do dai danh sach ban dau bang 0.*/
	m_length = 0;
}

template <class typeOfDataList>
CLinkedList<typeOfDataList>::CLinkedList(const CLinkedList &L)
{
	if (L.m_length == 0)
	/* Neu L la danh sach rong.*/
	{
	    m_head = new CNopeList<typeOfDataList>(L.m_head->m_data);
		m_head->m_next = m_head;
		m_head->m_precede = m_head;

		m_length = 0;
	}
	else
	/* Neu L khong rong.*/
	{
		/* Tao con tro head.*/
		m_head = new CNopeList<typeOfDataList>(L.m_head->m_data);
		m_head->m_next = m_head;
		m_head->m_precede = m_head;

		m_length = 0;
		

		/* Tao con tro CHAY.*/
		CNopeList<typeOfDataList> *cur = L.m_head->m_next; 

		int count = 1; // bien chay.
		while (count <= L.m_length) 
		/* Chay het danh sach L.*/
		{
			appendElement(cur->m_data);
			cur = cur->m_next;
			count += 1;
		} // End while.
	}
}

template <class typeOfDataList>
CLinkedList<typeOfDataList>::~CLinkedList()
{
	/* Tao bien con tro CHAY.*/
	CNopeList<typeOfDataList> *cur = m_head->m_next;

	int count = 1;
	while (count <= length())
	/* Chay den het danh sach.*/
	{
		CNopeList<typeOfDataList> *delete_ptr = cur;
		cur = cur->m_next;
		count += 1;
		delete delete_ptr;
	} // End while.
}

template <class typeOfDataList>
CLinkedList<typeOfDataList> CLinkedList<typeOfDataList>::operator = (const CLinkedList &L)
{
	if (!isListEmpty())
	/* Neu danh sach hien tai khong rong, 
	 * thi ta xoa va thu hoi bo nho va copy
	 * tung phan tu cua L sang danh sach. */
	{
		/* Xoa danh sach cu.*/
		/* Tao bien con tro CHAY.*/
		CNopeList<typeOfDataList> *cur = m_head->m_next;

		int count = 1;
		while (count <= length())
		/* Chay den het danh sach.*/
		{
			CNopeList<typeOfDataList> *delete_ptr = cur;
			cur = cur->m_next;
			count += 1;
			delete delete_ptr;
		} // End while.
		/* Xoa xong.*/
	}

	/* Copy tu danh sach L.*/
	if (L.m_length == 0)
	/* Neu L la danh sach rong.*/
	{
	    m_head = new CNopeList<typeOfDataList>(L.m_head->m_data);
		m_head->m_next = m_head;
		m_head->m_precede = m_head;

		m_length = 0;
	}
	else
	/* Neu L khong rong.*/
	{
		/* Tao con tro head.*/
		m_head = new CNopeList<typeOfDataList>(L.m_head->m_data);
		m_head->m_next = m_head;
		m_head->m_precede = m_head;
		m_length = 0;
		

		/* Tao con tro CHAY.*/
		CNopeList<typeOfDataList> *cur = L.m_head->m_next; 

		int count = 1; // bien chay.
		while (count <= L.m_length) 
		/* Chay het danh sach L.*/
		{
			appendElement(cur->m_data);
			cur = cur->m_next;
			count += 1;
		} // End while.
	}
	
	return *this;
}

template <class typeOfDataList>
bool CLinkedList<typeOfDataList>::isListEmpty()
{
	return (m_length == 0);
}

template <class typeOfDataList>
int CLinkedList<typeOfDataList>::length()
{
	return m_length;
}

template <class typeOfDataList>
void CLinkedList<typeOfDataList>::insertElement(const typeOfDataList &data_parameter, int position)
{
	if (1 <= position && position <= m_length)
	/* Neu vi tri can chen nam trong danh sach.*/
	{
	    CNopeList<typeOfDataList> *new_nope = new CNopeList<typeOfDataList>(data_parameter);
		CNopeList<typeOfDataList> *cur = m_head; // tao con tro CHAY.

		int i = 1;
		while (i <= position)
		/* Dua con tro CHAY chay den vi tri can chen.*/
		{
			cur = cur->m_next;
			i += 1;
		} // End while.
		
		/* Chen vao vi tri position.*/
		/* Noi o phia truoc.*/
		cur->m_precede->m_next = new_nope;
		new_nope->m_precede = cur->m_precede;
		/* Noi o phia sau.*/
		new_nope->m_next = cur;
		cur->m_precede = new_nope;

		/* Tang do dai them 1 doi vi.*/
		m_length += 1;
	}
	else
	/* Neu vi tri can chen khong nam trong danh sach.*/
	{
		cout << "Vi tri can chen khong nam trong danh sach." << endl;
	}
}

template <class typeOfDataList>
void CLinkedList<typeOfDataList>::appendElement(const typeOfDataList &data_parameter)
{
	/* Tao mot thanh phan moi.*/
	CNopeList<typeOfDataList> *new_nope = new CNopeList<typeOfDataList>(data_parameter);
	
	/* Moc noi con tro duoi va new_nope.*/
	m_head->m_precede->m_next = new_nope;
	new_nope->m_precede = m_head->m_precede;
	
	/* Moc noi new_nope vao duoi danh sach.*/
	m_head->m_precede = new_nope;
	new_nope->m_next = m_head;

	/* Tang do dai cua danh sach them 1 don vi.*/
	m_length += 1; 
}

template <class typeOfDataList>
void CLinkedList<typeOfDataList>::deleteElement(int position)
{
	if (1 <= position && position <= m_length)
	/* Neu vi tri can xoa nam trong danh sach.*/
	{
		/* Khoi tao con tro CHAY.*/
		CNopeList<typeOfDataList> *cur = m_head;
		
		int count = 1;
		while (count <= position)
		/* Cho con tro CHAY chay den vi tri can xoa.*/
		{
			cur =cur->m_next;
			count += 1;
		} // End while.

		/* Xoa.*/
		cur->m_precede->m_next = cur->m_next;
		cur->m_next->m_precede = cur->m_precede;

		delete cur; // giai phong bo nho.
		m_length -= 1; // giam do dai cua danh di 1 don vi.
	}
	else
	/* Neu vi tri can xoa khong nam trong danh sach.*/
	{
		cout << "Vi tri can xoa khong nam trong danh sach." << endl;
	}
}

template <class typeOfDataList>
typeOfDataList CLinkedList<typeOfDataList>::findElement(int position)
{
	if (1 <= position && position <= m_length)
	/* Neu vi tri can xoa nam trong danh sach.*/
	{
		/* Khoi tao con tro CHAY.*/
		CNopeList<typeOfDataList> *cur = m_head;
		
		int count = 1;
		while (count <= position)
		/* Cho con tro CHAY chay den vi tri can tim.*/
		{
			cur =cur->m_next;
			count += 1;
		} // End while.

		return cur->m_data;
	}
	else
	/* Neu vi tri can tim khong nam trong danh sach.*/
	{
		cout << "Khong tim thay phan tu: ";
		typeOfDataList null_return;
		return null_return;
	}
}
