#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class typeOfDataPriority>
class CNopePriority
{
public:
	typeOfDataPriority m_data; // bien luu lai du lieu cua phan tu.
	int m_priority; // bien luu lai gia tri uu tien cua phan tu.
	CNopePriority *m_left; 
	CNopePriority *m_right;

	CNopePriority();
	/* Constructor rong.
	 * */

	CNopePriority(const typeOfDataPriority &data_parameter, const int &priority_parameter);
	/* Constructor.
	 * */

	~CNopePriority();
	/* Destructor.
	 * */

	CNopePriority operator = (const CNopePriority &nope_parameter);
	/* Dinh nghia toan tu gan.
	 * Khi muon su dung toan tu gan, ta nen tao constructor truoc.
	 * Khong nen gan luon nhu the nay: CNopePriority nope_2 = nope_1;
	 * Ma nen lam nhu the nay:
	 * 		Cnope nope_2;
	 * 		nope_2 = nope_1;
	 * */
};

template <class typeOfDataPriority>
CNopePriority<typeOfDataPriority>::CNopePriority()
{
	typeOfDataPriority data_default = ' ';
	int priority_default = 403;

	m_data = data_default;
	m_priority = priority_default;
	m_left = NULL;
	m_right = NULL;
}

template <class typeOfDataPriority>
CNopePriority<typeOfDataPriority>::CNopePriority(const typeOfDataPriority &data_parameter, const int &priority_parameter)
{
	m_data = data_parameter;
	m_priority = priority_parameter;
	m_left = NULL;
	m_right = NULL;
}

template <class typeOfDataPriority>
CNopePriority<typeOfDataPriority>::~CNopePriority()
{
	
}

template <class typeOfDataPriority>
void copyTree(CNopePriority<typeOfDataPriority> * from_nope, CNopePriority<typeOfDataPriority> * &to_nope)
{
	if (from_nope == NULL)
	{
	 	to_nope = NULL;   
	}
	else
	{
		to_nope = new CNopePriority<typeOfDataPriority>(from_nope->m_data, from_nope->m_priority);
		copyTree(from_nope->m_left, to_nope->m_left);
		copyTree(from_nope->m_right, to_nope->m_right);
	}
}

template <class typeOfDataPriority>
CNopePriority<typeOfDataPriority> CNopePriority<typeOfDataPriority>::operator = (const CNopePriority &nope_parameter)
{
	m_data = nope_parameter.m_data;
	m_priority = nope_parameter.m_priority;
	
	copyTree(nope_parameter.m_left, m_left);
	copyTree(nope_parameter.m_right, m_right);

	return *this;
}

template <class typeOfDataPriority>
ostream &operator << (ostream &output, CNopePriority<typeOfDataPriority> nope_parameter)
{
	output << nope_parameter.m_data << "(" << nope_parameter.m_priority << ")";
	return output;
}

template <class typeOfDataPriority>
ostream &operator << (ostream &output, CNopePriority<typeOfDataPriority> *nope_parameter)
{
	output << nope_parameter->m_data << "(" << nope_parameter->m_priority << ")";
	return output;
}