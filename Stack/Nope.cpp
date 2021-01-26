#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class typeOfDataStack>
class CNopeStack
{
public:
	typeOfDataStack m_data; // phan du lieu.
	CNopeStack *m_next; 

	CNopeStack(const typeOfDataStack &data_parameter);
	/* Constructor.
	 * */

	~CNopeStack();
	/* Destructor.
	 * */
};

template <class typeOfDataStack>
CNopeStack<typeOfDataStack>::CNopeStack(const typeOfDataStack &data_parameter)
{
	m_data = data_parameter;
	m_next = NULL;
}

template <class typeOfDataStack>
CNopeStack<typeOfDataStack>::~CNopeStack()
{
	
}