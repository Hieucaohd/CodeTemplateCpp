#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Entry.cpp"

using namespace std;

/* Tu dien duoc cai dat bang bang bam dia chi mo.*/
template <class typeOfDataDictionary, class typeOfKeyDictionary>
class CDictionary
{
public:
	const int static SIZE = 811; // Kich co cua mang.

	CDictionary();
	/* Constructor: khoi tao mot tu dien rong.
	 * */

	~CDictionary();
	/* Destructor.
	 * */

	bool search(typeOfKeyDictionary & key, typeOfDataDictionary & data);
	/* Tim du lieu co khoa la key.
	 * Neu tim thay thi bien data ghi lai du lieu can tim.
	 * Postcondition: tra ve true neu tim thay,
	 * va neu khong tim thay thi tra ve false.
	 * */
	
	void insert(const typeOfDataDictionary &data_parameter, const typeOfKeyDictionary &key_parameter, bool &is_success);
	/* Xen vao du lieu data_parameter.
	 * Postcondition: bien is_success nhan gia tri la true neu xen thanh cong,
	 * va false neu khong thanh cong.
	 * */
	
	void deleteElementByKey(typeOfKeyDictionary & key);
	/* Loai khoi tu dien du lieu co khoa la key.
	 * */

	CEntry<typeOfDataDictionary, typeOfKeyDictionary> *m_array_datas; // danh sach du lieu trong bang.

	bool find(const typeOfKeyDictionary & key, int & index_ACTIVE, int & index_EMPTY_DELETED);
	/* Ham thuc hien tham do du lieu co khoa key.
	 * Neu thanh cong, ham tra ve true va bien index ghi lai chi so tai do chua du lieu.
	 * Neu that bai, ham tra ve false va bien index_else ghi lai chi so dau tien ma o trang thai 
	 * EMPTY hoac DELETED neu tham do phat hien ra.
	 * */

	int probing(int & position, int & number);
	/* position la vi tri ban dau duoc xac dinh boi bam khoa key, position = h(key).
	 * Postcondition: tra ve vi tri tham do o lan bam thu number = 0, 1, 2, ...
	 * */
	
	int hash(const typeOfKeyDictionary & key);
	/* Ham bam.
	 * */
};

template <class typeOfDataDictionary, class typeOfKeyDictionary>
CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::CDictionary()
{
	m_array_datas = new CEntry<typeOfDataDictionary, typeOfKeyDictionary>[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		m_array_datas[i].m_state = EMPTY;
	}
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::~CDictionary()
{
	delete [] m_array_datas;
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
bool CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::search(typeOfKeyDictionary & key, typeOfDataDictionary & take_data)
{
	int index_ACTIVE, index_EMPTY_DELETED;
	if (find(key, index_ACTIVE, index_EMPTY_DELETED))
	/* Neu tim thay.*/
	{
	    /* Thi lay du lieu ra va ket thuc.*/
		take_data = m_array_datas[index_ACTIVE].m_data;
		return true;
	}
	else
	/* Neu khong tim thay.*/
	{
		/* Thi tra ve false.*/
		return false;
	}
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
void CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::insert(const typeOfDataDictionary &data_parameter, const typeOfKeyDictionary &key_parameter, bool &is_success)
{
	int index_ACTIVE, index_EMPTY_DELETED;
	
	if ( !find(key_parameter, index_ACTIVE, index_EMPTY_DELETED))
	{
		if (m_array_datas[index_EMPTY_DELETED].m_state == DELETED || m_array_datas[index_EMPTY_DELETED].m_state == EMPTY)
		/* Neu khoa chua ton tai trong mang.*/
		{
			m_array_datas[index_EMPTY_DELETED].m_state = ACTIVE;
			m_array_datas[index_EMPTY_DELETED].m_key = key_parameter;
			m_array_datas[index_EMPTY_DELETED].m_data = data_parameter;

			is_success = true;
		}
	}
	else
	/* Neu khoa da ton tai trong mang.*/
	{
		is_success = false;
	}
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
void CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::deleteElementByKey(typeOfKeyDictionary & key)
{
	int index_ACTIVE, index_EMPTY_DELETED;

	if (find(key, index_ACTIVE, index_EMPTY_DELETED))
	/* Neu tim thay phan tu can xoa.*/
	{
	    m_array_datas[index_ACTIVE].m_state = DELETED;
	}
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
bool CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::find(const typeOfKeyDictionary & key, int & index_ACTIVE, int & index_EMPTY_DELETED)
{
	int position = hash(key);
	index_EMPTY_DELETED = position; // dat o dau day tham do.

	for (int number = 0; number < SIZE; number++)
	{
		/* Vi tri tham do lan thu number.
		 * Khi number = 0 thi n = position.*/
		int n = probing(position, number); 

		if (m_array_datas[n].m_state == ACTIVE && m_array_datas[n].m_key == key)
		/* Neu tim thay phan tu co khoa can tim.*/
		{
			/* Thi ta danh dau vi tri do va ket thuc.*/
			index_ACTIVE = n;
			return true; 
		}
		else if (m_array_datas[n].m_state == EMPTY && m_array_datas[index_EMPTY_DELETED].m_state != DELETED)
		/* Neu gap vi tri EMPTY va truoc do khong gap vi tri DELETED.*/
		{
			/* Thi ta danh dau vi tri EMPTY nay va ket thuc.*/
			index_EMPTY_DELETED = n;
			return false;
		}
		else if (m_array_datas[n].m_state == DELETED && m_array_datas[index_EMPTY_DELETED].m_state != DELETED)
		/* Neu gap vi tri DELETED dau tien trong day.*/
		{
			/* Thi ta danh dau vi tri nay va tiep tuc lap.*/
			index_EMPTY_DELETED = n;
		}
	}

	/* Dung tham do ma van khong tim ra du lieu can tim va cung khong phat hien ra vi tri DELETED.*/
	return false;
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
int CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::probing(int & position, int & number)
{
	return ((position + number) % SIZE);
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
int CDictionary<typeOfDataDictionary, typeOfKeyDictionary>::hash(const typeOfKeyDictionary & key)
{
	return key % SIZE;
}
