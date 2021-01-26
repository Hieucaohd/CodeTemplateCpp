#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Cell.cpp"

using namespace std;

template <class typeOfDataDictionary, class typeOfKeyDictionary>
class CDictionary
{
private:
public:
	void hieu();
	const int static SIZE = 811; // kich co cua mang.

	CDictionary();
	/* Constructor: rong.
	 * */

	CDictionary(const CDictionary &dic);
	/* Constructor copy.
	 * */

	void operator = (const CDictionary &dic);
	/* Dinh nghia toan tu gan.
	 * */

	~CDictionary();
	/* Destructor.
	 * */

	/* Cac phep toan tu dien: */

	bool search(const typeOfKeyDictionary & key, typeOfDataDictionary & take_data);
	/* Tim kiem du lieu co khoa la key.
	 * Luu du lieu vao bien data.
	 * Postcondition: tra ve true neu tim thay,
	 * va tra ve false neu khong tim thay.
	 * */

	void insert(const typeOfDataDictionary & data_parameter, const typeOfKeyDictionary & key_parameter, bool & is_success);
	/* Them du lieu data_parameter voi khoa key_parameter vao tu dien.
	 * Neu them thanh cong thi gan bien is_success gia tri la true,
	 * neu them khong thanh cong thi gan bien is_success gia tri la false.
	 * */
	
	void deleteElementByKey(const typeOfKeyDictionary & key);
	/* Xoa du lieu co khoa la key trong tu dien.
	 * */

	CCell<typeOfDataDictionary, typeOfKeyDictionary> *m_array_datas[SIZE]; // mang chua du lieu.

	int hash(const typeOfKeyDictionary & key);
	/* Ham bam.
	 * */
};

template <class typeOfDataDictionary, class typeOfKeyDictionary>
CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::CDictionary()
{
	for (int i = 0; i < SIZE; i++)
	{
		m_array_datas[i] = NULL;
	}
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::CDictionary(const CDictionary &dic)
{
	
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
void CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::operator = (const CDictionary &dic)
{
	
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::~CDictionary()
{
	/* Ta phai thu hoi toan bo day chuyen trong tu dien.*/
	for (int i = 0; i < SIZE; i++)
	{
		if (m_array_datas[i] != NULL)
		/* Neu day chuyen khong rong.*/
		{
			while (m_array_datas[i]->m_next != NULL)
			/* Lap cho den khi con 1 phan tu trong day chuyen.*/
			{
				CCell<typeOfDataDictionary, typeOfKeyDictionary> *old_ptr = m_array_datas[i];
				m_array_datas[i] = m_array_datas[i]->m_next;
				delete old_ptr;
			} // End while.

			/* Xoa phan tu cuoi cung trong day chuyen.*/
			delete m_array_datas[i];
			m_array_datas[i] = NULL;
		}
	}
	
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
bool CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::search(const typeOfKeyDictionary & key, typeOfDataDictionary & take_data)
{
	/* Tao bien chay.*/
	CCell<typeOfDataDictionary, typeOfKeyDictionary> *current_ptr = m_array_datas[hash(key)];

	while (current_ptr != NULL)
	/*comment*/
	{
		if (current_ptr->m_key == key)
		/* Neu tim thay phan tu can tim.*/
		{
		    take_data = current_ptr->m_data;
			return true;
		}

		/* Neu khong thi cho chay tiep.*/
		current_ptr = current_ptr->m_next;
	} // End while.

	return false;
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
void CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::insert(const typeOfDataDictionary & data_parameter, const typeOfKeyDictionary & key_parameter, bool & is_success)
{
	/* Tao bien de lay du lieu tu ham search.*/
	typeOfDataDictionary take_data;

	if (!search(key_parameter, take_data))
	/* Neu khoa chua co trong tu dien.*/
	{
		/* Tao phan tu moi.*/
		CCell<typeOfDataDictionary, typeOfKeyDictionary> *new_cell = new CCell<typeOfDataDictionary, typeOfKeyDictionary>(data_parameter, key_parameter);

		/* Them phan tu moi vao dau day chuyen.*/
		new_cell->m_next = m_array_datas[hash(key_parameter)];
		m_array_datas[hash(key_parameter)] = new_cell;

		is_success = true;
	}
	else
	/* Neu khoa da ton tai trong tu dien.*/
	{
		cout << "Khoa da co trong tu dien." << endl;
		is_success = false;
	}
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
void CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::deleteElementByKey(const typeOfKeyDictionary & key)
{
	/* Tao 2 con tro chay.*/
	CCell<typeOfDataDictionary, typeOfKeyDictionary> *precede_ptr = NULL; // con tro sau.
	CCell<typeOfDataDictionary, typeOfKeyDictionary> *current_ptr = m_array_datas[hash(key)]; // con tro truoc.

	/* Tao con tro the.*/
	CCell<typeOfDataDictionary, typeOfKeyDictionary> *old_ptr;

	while (current_ptr != NULL)
	/* Chay cho den het day chuyen.*/
	{
		if (current_ptr->m_key == key)
		/* Neu gap phan tu can xoa.*/
		{
		    if (current_ptr == m_array_datas[hash(key)])
		    /* Neu phan tu can xoa nam o dau day truyen.*/
		    {
				old_ptr = m_array_datas[hash(key)];
		        m_array_datas[hash(key)] = m_array_datas[hash(key)]->m_next;
				delete old_ptr;
		    }
			else
			/* Neu phan tu can xoa khong nam o dau day chuyen.*/
			{
				precede_ptr->m_next = current_ptr->m_next;
				delete current_ptr;
			}

			break; // ket thuc vong lap.
		}
		else
		/* Neu khong gap phan tu can xoa.*/
		{
			/* Thi ta di tiep.*/
			precede_ptr = current_ptr;
			current_ptr = current_ptr->m_next;
		}

	} // End while.
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
int CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::hash(const typeOfKeyDictionary & key)
{
	return (key % SIZE);
}
