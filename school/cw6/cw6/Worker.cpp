#include "Worker.h"
#define kwota_wolna 46.34

Worker::Worker( string name,int age,double salary,int experience ):Person(name,age)
{
	setSalary(salary);
	setExperience(experience);
}

Worker::~Worker()
{

}

Worker::Worker( const Worker& e )
{
	*this=e;
}

double Worker::Tax(double brutto, double kup)
{
	double tax = (brutto - kup)*0.18- kwota_wolna;
	if (tax < 0)
		return 0;
	return tax;
}

double Worker::Bonus(int x_exp)
{
	double bonusP = 0;
	if (x_exp >= 5 && x_exp <= 20)
		bonusP = x_exp * 0.01;
	if (x_exp > 20)
		bonusP = 0.20;
	return bonusP;

}