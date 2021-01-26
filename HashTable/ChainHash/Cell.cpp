#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class typeOfDataDictionary, class typeOfKeyDictionary>
class CCell
{
private:
public:
	typeOfDataDictionary m_data;
	typeOfKeyDictionary m_key;
	CCell *m_next;

	CCell();
	/* Contructor: rong.
	 * */

	CCell(const typeOfDataDictionary & data_parameter, const typeOfKeyDictionary & key_parameter);
	/* Constructor.
	 * */

	~CCell();
	/* Destructor.
	 * */
};

template <class typeOfDataDictionary, class typeOfKeyDictionary>
CCell<typeOfDataDictionary, typeOfKeyDictionary>::CCell()
{
	m_next = NULL;
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
CCell<typeOfDataDictionary, typeOfKeyDictionary>::CCell(const typeOfDataDictionary & data_parameter, const typeOfKeyDictionary & key_parameter)
{
	m_data = data_parameter;
	m_key = key_parameter;
	m_next = NULL;
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
CCell<typeOfDataDictionary, typeOfKeyDictionary>::~CCell()
{
	
}
