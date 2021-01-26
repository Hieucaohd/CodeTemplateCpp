#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class typeOfDataQueue>
class CNopeQueue
{
public:
	typeOfDataQueue m_data; // phan du lieu.
	CNopeQueue *m_next; 

	CNopeQueue(const typeOfDataQueue &data_parameter);
	/* Constructor.
	 * */

	~CNopeQueue();
	/* Destructor.
	 * */
};

template <class typeOfDataQueue>
CNopeQueue<typeOfDataQueue>::CNopeQueue(const typeOfDataQueue &data_parameter)
{
	m_data = data_parameter;
	m_next = NULL;
}

template <class typeOfDataQueue>
CNopeQueue<typeOfDataQueue>::~CNopeQueue()
{
	
}