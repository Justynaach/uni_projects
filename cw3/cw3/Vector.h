using namespace std;
#include <iostream>
#define VEC_OTHER_ERROR 0X01
#define VEC_DIM_ERROR 0X02
#define VEC_INCOMP_DIM 0X04
#define VEC_ALLOC_ERROR 0X80
typedef unsigned short USHORT;

class VectorException
{
public:
	VectorException( USHORT mErr=VEC_OTHER_ERROR );
	const char* getReason( );
private:
	USHORT mErrCode;
};


inline VectorException::VectorException ( USHORT mErr )
{
	mErrCode=mErr;
}

inline const char* VectorException::getReason ( )
{
	switch ( mErrCode )
	{
		case VEC_DIM_ERROR: return "ERROR: improper vector size!\n";
		case VEC_INCOMP_DIM: return "ERROR: incompatible vector sizes!\n";
		case VEC_ALLOC_ERROR: return "ERROR: memory allocation error!\n";
		default: return "Other error!\n";
	}
}


class Vector
{
public:
	Vector ( int nSize = 2, double nElem = 0 );
	Vector ( const Vector& v );
	virtual ~Vector ( );

	Vector& operator = ( const Vector& v );
	friend istream& operator >> ( istream& in, Vector& v );
	friend ostream& operator << ( ostream& out, const Vector& v );

	int getDim ( ) const;
	//operatory +
	friend const Vector operator + ( const Vector& v1, const Vector& v2 );	//v1+v2
	friend const Vector operator + ( const Vector& v1, double x );		//v1+4
	friend const Vector operator + ( double x, const Vector& v );		//4+v1 do kazdej wspolrzednej
	// funkcje klasy v1.operator += (v2)
	Vector& operator += ( double x );//+=4		v1.operator += (4)
	Vector& operator += ( const Vector& v );	//+=v2 

	//operatory -
	friend const Vector operator - ( const Vector& v1, const Vector& v2 );
	friend const Vector operator - ( const Vector& v1, double x );
	Vector& operator -= ( double x ); 
	Vector& operator -= ( const Vector& v );

	friend const Vector operator - ( const Vector&  );


	//operator *
	friend const Vector operator * ( double x, const Vector& v );
	friend const Vector operator * ( const Vector& v, double x );
	Vector& operator *= ( double x );

	//iloczyn skalarny
	friend double operator * ( const Vector& v1, const Vector& v2);
	//rzutowanie
	explicit operator double * ( ) const { return m_pCoord; }
	//indeksowanie
	double& operator[] (int ix );
	const double& operator[]( int ix ) const;

	//porownanie
	friend bool operator == (const Vector& v1, const Vector& v2 );
	friend bool operator != ( const Vector& v1, const Vector& v2 );

private:
	void copyVec ( const Vector& v );
	void createVec ( int nSize );
private:
	double* m_pCoord; //tab dynamiczna wspolrzednych wektora
	int mDim; //rozmiar wektora
	
};

//jakie struktury danych beda reprezentowac obiekt tej klasy
//konstrukcja obiektu tej klasy
//ew destruktor (np gdy sa skladowe dynamiczne)
//ew operator podstawienia (powinien byc gdy sa skladowe dynamiczne)
//moga byc operatory we wy i inne
//settery gettery
//inne metody publiczne
//metody prywatne 


inline int Vector::getDim ( ) const
{
	return mDim;
}
inline void Vector::createVec ( int nSize )

{
	if ( nSize < 2 )
	{
		nSize=2;
		//cerr << "ERROR: inproper vector size!\n";
		throw VectorException(VEC_DIM_ERROR);
	}
	mDim=nSize;
	m_pCoord=new double[mDim];
}

inline void Vector::copyVec ( const Vector& v )
{
	memcpy(this->m_pCoord, v.m_pCoord, v.getDim()*sizeof(double) );
}

inline double& Vector::operator[] ( int ix )
{
	if( ix < 0 || ix>= getDim( ) )
	{
		throw VectorException(VEC_DIM_ERROR);
		return m_pCoord[0];
	}
	return this->m_pCoord[ix];
}

inline const double& Vector::operator [] ( int ix ) const {
	if ( ix < 0 || ix >= getDim ( ) ) {
		throw VectorException(VEC_DIM_ERROR);
		return m_pCoord[0];
	}
	return this->m_pCoord[ix];
}
