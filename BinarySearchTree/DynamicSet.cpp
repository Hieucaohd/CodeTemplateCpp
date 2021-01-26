#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Nope.cpp"

using namespace std;

/* Lop tap dong duoc cai dat boi CTDL cay tim kiem nhi phan.*/
template <class typeOfDataSet>
class CDynamicSet
{
private:
	CNopeSet<typeOfDataSet> *m_root;

	/* Cac ham an phuc vu cho viec cai dat ham public.*/

	void makeEmpty(CNopeSet<typeOfDataSet> * &root_ptr);
	/* Lam cho cay co goc tro boi root_ptr thanh rong, thu hoi cac te bao nho
	 * da cap phat cho cac dinh cua cay.
	 * */

	void insert(const typeOfDataSet & data_parameter, const int & key_parameter, CNopeSet<typeOfDataSet> * &root_ptr);
	/* Xen du lieu moi data_parameter vao cay co goc tro boi root_ptr.
	 * */
	
	void deleteElementByKey(const int & key, CNopeSet<typeOfDataSet> * &root_ptr);
	/* Loai du lieu co khoa key khoi cay co goc tro boi root_ptr.
	 * */
	
	CNopeSet<typeOfDataSet> * deleteMin(CNopeSet<typeOfDataSet> * &root_ptr);
	/* Loai du lieu co khoa nho nhat khoi cay co goc tro boi root_ptr.
	 * */

	bool search(const int & key, typeOfDataSet &take_data, CNopeSet<typeOfDataSet> * &root_ptr);
	/* Tim kiem du lieu co khoa la key trong cay co goc tro boi root_ptr.
	 * */
	
	typeOfDataSet min(CNopeSet<typeOfDataSet> * &root_ptr);
	/* Tra ve du lieu co khoa nho nhat tren cay co goc tro boi root_ptr.
	 * */

	typeOfDataSet max(CNopeSet<typeOfDataSet> * &root_ptr);
	/* Tra ve du lieu co khoa lon nhat tren cay co goc tro boi root_ptr.
	 * */

public:
	CDynamicSet();
	/* Constructor: khoi tao mot tap rong.
	 * */

	CDynamicSet(const CDynamicSet & set);
	/* Constructor copy.
	 * */

	 CDynamicSet(const CDynamicSet * set_ptr);
	/* Constructor copy cua con tro.
	 * */

	CDynamicSet operator = (const CDynamicSet &set);
	/* Dinh nghia toan tu gan.
	 * */

	friend void copyTree(const CNopeSet<typeOfDataSet> * from_root_ptr, CNopeSet<typeOfDataSet> * &to_root_ptr)
	{
		if (from_root_ptr != NULL)
		{
			to_root_ptr = new CNopeSet<typeOfDataSet>(from_root_ptr->m_data, from_root_ptr->m_key);
			copyTree(from_root_ptr->m_left, to_root_ptr->m_left);
			copyTree(from_root_ptr->m_right, to_root_ptr->m_right);
		}
		else
		{
			return;
		}
	}

	~CDynamicSet();
	/* Destructor.
	 * */
	
	bool isSetEmpty();
	/* Kiem tra xem tap co rong khong.
	 * Postcondition: tra ve true neu tap rong,
	 * tra ve false neu tap khong rong.
	 * */

	void insert(const typeOfDataSet & data_parameter, const int & key_parameter);
	/* Xem du lieu moi vao tap.
	 * */

	void deleteElementByKey(const int & key);
	/* Xoa du lieu co khoa la key.
	 * */

	CNopeSet<typeOfDataSet> * deleteMin();
	/* Loai du lieu co khoa nho nhat, dong thoi tra ve du lieu nay.
	 * Precondition: tap khong rong.
	 * Postcondition: du lieu co khoa nho nhat bi loai ra khoi tap,
	 * tra ve du lieu co khoa nho nhat.
	 * */

	bool search(const int & key, typeOfDataSet &take_data);
	/* Tim du lieu co khoa la key, bien take_data luu lai du lieu do.
	 * Precondition: tap khong rong.
	 * Postcondition: tra ve true neu ton tai du lieu co khoa key trong tap,
	 * tra ve false neu khong.
	 * */

	typeOfDataSet min();
	/* Precondition: cay khong rong.
	 * Postcondition: tra ve du lieu co khoa nho nhat trong tap.
	 * */

	typeOfDataSet max();
	/* Precondition: cay khong rong.
	 * Postcondition: tra ve du lieu co khoa lon nhat trong tap.
	 * */
};

template <class typeOfDataSet>
CDynamicSet<typeOfDataSet>::CDynamicSet()
{
	m_root = NULL;
}

template <class typeOfDataSet>
CDynamicSet<typeOfDataSet>::CDynamicSet(const CDynamicSet & set)
{
	m_root = NULL;
	copyTree(set.m_root, this->m_root);
}

template <class typeOfDataSet>
CDynamicSet<typeOfDataSet>::CDynamicSet(const CDynamicSet * set_ptr)
{
	m_root = NULL;
	copyTree(set_ptr->m_root, this->m_root);
}

template <class typeOfDataSet>
CDynamicSet<typeOfDataSet> CDynamicSet<typeOfDataSet>::operator = (const CDynamicSet & set)
{
	if (!isSetEmpty())
	/* Neu tap cu khong rong.*/
	{
	    /* Thi ta phai xoa tap cu di.*/
		makeEmpty(m_root);
	}

	copyTree(set.m_root, this->m_root);
	return *this;
}

/* Destructor.*/
template <class typeOfDataSet>
CDynamicSet<typeOfDataSet>::~CDynamicSet()
{
	makeEmpty(m_root);
}

template <class typeOfDataSet>
void CDynamicSet<typeOfDataSet>::makeEmpty(CNopeSet<typeOfDataSet> * &root_ptr)
{
	if (root_ptr != NULL)
	/* Neu cay khong rong.*/
	{
	    makeEmpty(root_ptr->m_left);
		makeEmpty(root_ptr->m_right);
		delete root_ptr;
		root_ptr = NULL;
	}
}

/* Kiem tra xem tap co rong khong.*/
template <class typeOfDataSet>
bool CDynamicSet<typeOfDataSet>::isSetEmpty()
{
	return m_root == NULL;
}

/* Ham insert.*/
template <class typeOfDataSet>
void CDynamicSet<typeOfDataSet>::insert(const typeOfDataSet & data_parameter, const int & key_parameter)
{
	insert(data_parameter, key_parameter, m_root);
}

template <class typeOfDataSet>
void CDynamicSet<typeOfDataSet>::insert(const typeOfDataSet & data_parameter, const int & key_parameter, CNopeSet<typeOfDataSet> * &root_ptr)
{
	if (root_ptr == NULL)
	/* Neu cay rong.*/
	{
	    root_ptr = new CNopeSet<typeOfDataSet>(data_parameter, key_parameter);
	}
	else if (key_parameter < root_ptr->m_key)
	/* Neu khoa truyen vao nho hon khoa o dinh.*/
	{
		/* Thi ta them vao cay con trai.*/
		return insert(data_parameter, key_parameter, root_ptr->m_left);
	}
	else if (key_parameter > root_ptr->m_key)
	/* Neu khoa truyen vao lon hon khoa o dinh.*/
	{
		/* Thi ta them vao cay con phai.*/
		return insert(data_parameter, key_parameter, root_ptr->m_right);
	}
}

/* Ham delete.*/
template <class typeOfDataSet>
void CDynamicSet<typeOfDataSet>::deleteElementByKey(const int & key)
{
	deleteElementByKey(key, m_root);
}

template <class typeOfDataSet>
void CDynamicSet<typeOfDataSet>::deleteElementByKey(const int & key, CNopeSet<typeOfDataSet> * &root_ptr)
{
	if (key < root_ptr->m_key)
	/* Neu khoa can xoa nho hon khoa o dinh.*/
	{
		/* Thi ta chay xuong cay con trai.*/
		deleteElementByKey(key, root_ptr->m_left);
	}
	else if (key > root_ptr->m_key)
	/* Neu khoa can xoa lon hon khoa o dinh.*/
	{
		/* Thi ta chay xuong cay con phai.*/
		deleteElementByKey(key, root_ptr->m_right);
	}
	else if (root_ptr->m_left != NULL && root_ptr->m_right != NULL)
	/* Neu khoa can xoa bang khoa o dinh, dong thoi cay con trai
	 * va cay con phai deu khong rong.*/
	{
		/* Tim phan tu co khoa be nhat trong cay con phai,
		 * dong thoi xoa no di.*/
		CNopeSet<typeOfDataSet> *take_element = deleteMin(root_ptr->m_right);

		/* Gan gia tri o dinh can xoa bang gia tri cua phan tu co 
		 * khoa be nhat trong cay con phai.*/
		root_ptr->m_data = take_element->m_data;
		root_ptr->m_key = take_element->m_key;
	}
	else if (root_ptr->m_left == NULL)
	/* Neu cay con trai rong.*/
	{
		CNopeSet<typeOfDataSet> *old_root = root_ptr;
		root_ptr = root_ptr->m_right;
		delete old_root;
	}
	else if (root_ptr->m_right == NULL)
	/* Neu cay con phai rong.*/
	{
		CNopeSet<typeOfDataSet> *old_root = root_ptr;
		root_ptr = root_ptr->m_left;
		delete old_root;
	}
}

/* Ham xoa phan tu co khoa nho nhat trong tap.*/
template <class typeOfDataSet>
CNopeSet<typeOfDataSet> * CDynamicSet<typeOfDataSet>::deleteMin()
{
	deleteMin(m_root);
}

template <class typeOfDataSet>
CNopeSet<typeOfDataSet> * CDynamicSet<typeOfDataSet>::deleteMin(CNopeSet<typeOfDataSet> * &root_ptr)
{
	while (root_ptr->m_left != NULL)
	/* Chay cho den khi gap la ngoai cung ben trai cua cay.*/
	{
		return deleteMin(root_ptr->m_left);
	} // End while.

	CNopeSet<typeOfDataSet> *take_element = new CNopeSet<typeOfDataSet>(root_ptr->m_data, root_ptr->m_key); // lay du lieu.

	CNopeSet<typeOfDataSet> *old_left = root_ptr; // dinh vi con tro cu.

	root_ptr = root_ptr->m_right; // noi voi cay con phai.

	delete old_left; // thu hoi bo nho.

	return take_element;
}

/* Ham tim kiem.*/
template <class typeOfDataSet>
bool CDynamicSet<typeOfDataSet>::search(const int & key, typeOfDataSet &take_data)
{
	search(key, take_data, m_root);
}

template <class typeOfDataSet>
bool CDynamicSet<typeOfDataSet>::search(const int & key, typeOfDataSet &take_data, CNopeSet<typeOfDataSet> * &root_ptr)
{
	if (root_ptr != NULL)
	/* Neu cay khong rong.*/
	{
		if (root_ptr->m_key == key)
		/* Neu gap dinh can tim.*/
		{
			take_data = root_ptr->m_data;
			return true;
		}
		else if (key < root_ptr->m_key)
		/* Neu khoa can tim nho hon khoa o dinh.*/
		{
			/* Thi ta tim o cay con trai.*/
			return search(key, take_data, root_ptr->m_left);
		}
		else if (key > root_ptr->m_key)
		/* Neu khoa can tim lon hon khoa o dinh.*/
		{
			/* Thi ta tim o cay con phai.*/
			return search(key, take_data, root_ptr->m_right);
		}
	}
	else 
	/* Neu cay rong.*/
	{
		return false;
	}
}

/* Ham tim kiem phan tu co khoa nho nhat trong tap.*/
template <class typeOfDataSet>
typeOfDataSet CDynamicSet<typeOfDataSet>::min()
{
	min(m_root);
}

template <class typeOfDataSet>
typeOfDataSet CDynamicSet<typeOfDataSet>::min(CNopeSet<typeOfDataSet> * &root_ptr)
{
	while (root_ptr->m_left != NULL)
	/* Chay cho den la ngoai cung ben trai cua cay.*/
	{
		return min(root_ptr->m_left);
	} // End while.

	return root_ptr->m_data;
}

/* Ham tim kiem phan tu co khoa lon nhat trong tap.*/
template <class typeOfDataSet>
typeOfDataSet CDynamicSet<typeOfDataSet>::max()
{
	max(m_root);
}

template <class typeOfDataSet>
typeOfDataSet CDynamicSet<typeOfDataSet>::max(CNopeSet<typeOfDataSet> * &root_ptr)
{
	while (root_ptr->m_right != NULL)
	/* Chay cho den la ngoai cung ben phai cua cay.*/
	{
		return max(root_ptr->m_right);
	} // End while.

	return root_ptr->m_data;
}