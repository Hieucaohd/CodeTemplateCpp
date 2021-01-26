#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Dinh nghia kieu cua trang thai ung voi moi vi tri trong mang.*/
enum stateType {ACTIVE, EMPTY, DELETED};

template <class typeOfDataDictionary, class typeOfKeyDictionary>
class CEntry
{
public:
	typeOfDataDictionary m_data;
	typeOfKeyDictionary m_key;
	stateType m_state;

	CEntry();
	/* Constructor: rong.
	 * */
	
	CEntry(typeOfDataDictionary & data_parameter, typeOfKeyDictionary & key_parameter, stateType & state_parameter);
	/* Constructor: khoi tao doi tuong bao gom day du du lieu.
	 * */

	~CEntry();
	/* Destructor.
	 * */
};

template <class typeOfDataDictionary, class typeOfKeyDictionary>
CEntry<typeOfDataDictionary, typeOfKeyDictionary>::CEntry()
{
	
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
CEntry<typeOfDataDictionary, typeOfKeyDictionary>::CEntry(typeOfDataDictionary & data_parameter,typeOfKeyDictionary & key_parameter, stateType & state_parameter)
{
	m_data = data_parameter;
	m_key = key_parameter;
	m_state = state_parameter;
}

template <class typeOfDataDictionary, class typeOfKeyDictionary>
CEntry<typeOfDataDictionary, typeOfKeyDictionary>::~CEntry()
{
	
}