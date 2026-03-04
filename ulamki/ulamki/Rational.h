#pragma once
#include <iostream>
using namespace std;

class Rational
{
private:
	int m_Numerator;
	int m_Denominator;
	int nwd ( int num,int denum );

public:
	Rational ( int numerator=0,int denominator=1 );
	Rational ( const Rational& r );
	virtual ~Rational();

	Rational& operator=( const Rational& r );

	friend istream& operator >> ( istream& in,Rational& r );
	friend ostream& operator << ( ostream& out,const Rational& r );

	//operatory +
	friend Rational operator +( const Rational& r1,const Rational& r2 );
	Rational& operator += ( const Rational& r );

	//operatory -
	friend Rational operator -( const  Rational& r1,const Rational& r2 );
	Rational& operator -= ( const Rational& r );

	//operator /
	friend Rational operator /( const Rational& r1,const Rational& r2 );
	Rational& operator /= ( const Rational& r );

	//operator *
	friend const Rational operator *( const Rational& r1 ,const Rational& r2 );
	Rational& operator *= ( const Rational& r );

	int GetNumerat () const;		
	int GetDenominat () const;

	void SetNumerat ( int Num );
	void SetDenominat ( int Denum );
	void SetRational ( int num,int denum );

	double Value ();
	void Reduce ();
};


//---------------inline functions------------------------

inline int Rational::GetNumerat() const
{
	return m_Numerator;
}

inline int Rational::GetDenominat() const
{
	return m_Denominator;
}

inline void Rational::SetNumerat( int Num )
{
	m_Numerator=Num;
}

inline void Rational::SetDenominat( int Denum )
{
	m_Denominator=Denum;

}

inline void Rational::SetRational( int num,int denum )
{
	if (denum == 0) {
		cerr << "ERROR: mianownik nie moze byc zerem!";
		m_Denominator = 1;
	}

	int d = nwd( num,denum );

	m_Numerator = num;
	m_Denominator = denum;

	Reduce();
}
