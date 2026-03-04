#include "Rational.h"

Rational::Rational( int numerator,int denominator )
{
	SetRational( numerator,denominator );
}

Rational::Rational( const Rational& r )
{
	*this=r;
}

Rational::~Rational()
{
	

}

Rational& Rational::operator=( const Rational& r )
{
	SetRational( r.GetNumerat(), r.GetDenominat());
	return *this;

}
istream& operator >> ( istream& in,Rational& r )
{
	int temp;
	in >> temp; r.SetNumerat( temp );
	in >> temp; r.SetDenominat( temp );

	return in;
}
ostream& operator << ( ostream& out,const Rational& r )
{
	out << r.GetNumerat() << '/' << r.GetDenominat();
	return out;
}

Rational operator+(const Rational& r1, const Rational& r2)
{
	Rational res(r1);
	return res+=r2;
}


Rational& Rational::operator+=(const Rational& r)
{
	SetNumerat(GetNumerat() * r.GetDenominat() + r.GetNumerat() * GetDenominat());

	SetDenominat(GetDenominat() * r.GetDenominat());

	Reduce();
	return *this;
}


//operatory -
Rational operator-(const Rational& r1, const Rational& r2)
{
	Rational res(r1);
	return res-=r2;
}

Rational& Rational::operator-=(const Rational& r)
{
	SetNumerat(GetNumerat() * r.GetDenominat() - r.GetNumerat() * GetDenominat());
	SetDenominat(GetDenominat() * r.GetDenominat());
	Reduce();
	return *this;
}


//operator /
Rational operator/( const Rational& r1, const Rational& r2)
{
	Rational res(r1);
	return res/=r2;
}

Rational& Rational::operator/=( const Rational& r )
{
	SetNumerat(GetNumerat() * r.GetDenominat());
	SetDenominat(GetDenominat() * r.GetNumerat());
	Reduce();
	return *this;
}

//operator *
const Rational operator*( const Rational& r1, const Rational& r2)
{
	Rational res(r1);
	return res*=r2;
}

Rational& Rational::operator*=(const Rational& r)
{
	SetNumerat( GetNumerat() * r.GetNumerat());
	SetDenominat( GetDenominat() * r.GetDenominat());
	Reduce();
	return *this;
}


double Rational::Value()
{
	return (double)m_Numerator/(double)m_Denominator;
}

void Rational::Reduce()
{
	int d= nwd( GetNumerat(),GetDenominat() );
	if( d ==1 ) return;
	m_Numerator /= d;
	m_Denominator /= d;

}
int Rational::nwd( int num,int denum )
{

	if (denum == 0) {
		cerr << "ERROR: mianownik nie moze byc zerem!";
		m_Denominator = 1;
	}
	num = num < 0 ? -num : num;
	denum = denum < 0 ? -denum : denum;

	if (num == 0) return denum;

	while (num != denum)
	{
		if (num > denum)
			num = num - denum;
		else
			denum = denum - num;
	}

	return num;


}