#pragma once
#include <string>
using namespace std;
#include <iostream>
#include "Person.h"

class Worker: public Person
{
public:
	Worker( string name="", int age=0, double salary=0, int experience=0);
	virtual ~Worker();
	Worker( const Worker& e);

	double getSalary();
	int getExperience();

	void setSalary( double new_salary );
	void setExperience( int new_exp );

//	virtual double Brutto();	//to tak samo(sortowanie)

	double Tax(double brutto, double kup);
	double Bonus(int x_exp);

	virtual void print() = 0;
	virtual void Salary() = 0;

protected:
	double m_Salary;
	int m_exp;	//experience

};

//-----------------------------------------------------------
inline double Worker::getSalary()
{
	return this->m_Salary;
}

inline int Worker::getExperience()
{
	return this->m_exp;
}

inline void Worker::setSalary( double new_salary)
{
	this->m_Salary=new_salary;
}

inline void Worker::setExperience( int new_exp )
{
	this->m_exp=new_exp;
}
