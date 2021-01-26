#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class typeOfDataSet>
class CNopeSet
{
public:
	typeOfDataSet m_data;
	int m_key;
	CNopeSet *m_left;
	CNopeSet *m_right;

	CNopeSet(const typeOfDataSet & data_parameter, const int & key_parameter);
	/* Constructor.
	 * */

	~CNopeSet();
	/* Destructor.
	 * */
};

template <class typeOfDataSet>
CNopeSet<typeOfDataSet>::CNopeSet(const typeOfDataSet & data_parameter, const int & key_parameter)
{
	m_key = key_parameter;
	m_data = data_parameter;
	m_left = NULL;
	m_right = NULL;
}

template <class typeOfDataSet>
CNopeSet<typeOfDataSet>::~CNopeSet()
{
	
}