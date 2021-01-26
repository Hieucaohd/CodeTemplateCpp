#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Khai bao truoc lop CLinkedList.*/
template <class typeOfDataList>
class CLinkedList;

/* Khai bao truoc cong cu lap.*/
template <class typeOfDataList>
class CListIterator;

template <class typeOfDataList>
class CNopeList
{
private:
	typeOfDataList m_data; // phan du lieu.
	CNopeList *m_next; 
	CNopeList *m_precede;
public:
	friend class CLinkedList<typeOfDataList>;
	/* Khai bao lop CLinkedList la lop ban.
	 * */

	friend class CListIterator<typeOfDataList>;
	/* Khai bao cung cu lap la lop ban.
	 * */

	CNopeList(const typeOfDataList &data_parameter);
	/* Constructor.
	 * */

	~CNopeList();
	/* Destructor.
	 * */
};

template <class typeOfDataList>
CNopeList<typeOfDataList>::CNopeList(const typeOfDataList &data_parameter)
{
	m_data = data_parameter;
	m_next = NULL;
	m_precede = NULL;
}

template <class typeOfDataList>
CNopeList<typeOfDataList>::~CNopeList()
{
	
}
