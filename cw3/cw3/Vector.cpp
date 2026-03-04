#include "Vector.h"

Vector::Vector ( int nSize, double nElem )
{
	createVec( nSize );
	if( !m_pCoord )
		throw VectorException( VEC_ALLOC_ERROR );
	for( int i=0; i<getDim( ); i++ )
		m_pCoord[i] = nElem;

}
Vector::Vector ( const Vector& v )
{
	m_pCoord = nullptr;
	mDim = 0;
	*this = v;
}
Vector::~Vector ( )
{
	delete [] m_pCoord;

}

Vector& Vector::operator = ( const Vector& v )
{
	if ( getDim ( ) != v.getDim ( ) )
	{
		//if( m_pCoord)
		delete [] m_pCoord;	//usuwa stara tablice
		createVec(v.getDim( ) );	//towrzy nowa zgodna z rozmiarem

	}
	copyVec( v );
	return *this;
}

istream& operator >> ( istream& in, Vector& v )
{
	for ( int i = 0; i < v.getDim ( ); i++ )
		in >> v.m_pCoord[i];
	return in;
}

ostream& operator << ( ostream& out, const Vector& v )
{
	out << '[' ;
	for ( int i = 0; i < v.getDim ( ); i++ )
	{
		out << v.m_pCoord[i];
		if( i<v.getDim( )-1 ) out <<",";
	}
	out << "]";
	return out;
}

const Vector operator + ( const Vector& v1, const Vector& v2 )
{
	Vector res ( v1 );
	return res += v2;
}
//v1+4
const Vector operator + ( const Vector& v1, double x )
{
	Vector res ( v1 );
	return res += x;
}
//4+v1 do kazdej wspolrzednej
const Vector operator + ( double x, const Vector& v )
{
	return v + x;

}
// funkcje klasy v1.operator += (v2)
//+=4		v1.operator += (4)
Vector& Vector::operator += ( double x )
{
	for( int i = 0; i<getDim( ); i++ )
		m_pCoord[i]+=x;
	return *this;

}
//+=v2 
Vector& Vector::operator += ( const Vector& v ) {
	if ( this->getDim ( ) != v.getDim ( ) )
	{
		throw VectorException(VEC_INCOMP_DIM);
	}
	for ( int i = 0; i < getDim ( ); i++ )
		m_pCoord[i] += v.m_pCoord[i];
	return *this;
}



const Vector operator - ( const Vector& v1, const Vector& v2 )
{
	Vector res ( v1 );
	return res -= v2;

}
const Vector operator - ( const Vector& v1, double x )
{
	Vector res( v1 );
	return res += -x;
}
Vector& Vector::operator -= ( double x )
{
	for ( int i = 0; i < getDim ( ); i++ )
		m_pCoord[i] -= x;
	return *this;
}
Vector& Vector::operator -= ( const Vector& v )
{
	if ( this->getDim ( ) != v.getDim ( ) )
	{
		throw VectorException(VEC_DIM_ERROR);
		return *this;
	}
	for ( int i = 0; i < getDim ( ); i++ )
		m_pCoord[i] -= v.m_pCoord[i];
	return *this;
}
const Vector operator - ( const Vector& v )
{
	Vector res(v);
	for ( int i = 0; i < res.getDim( ); i++ )
		res.m_pCoord[i] = -res.m_pCoord[i];
	return res;
}

const Vector operator * ( double x, const Vector& v )
{
	return v*x;
}

const Vector operator * ( const Vector& v, double x )
{
	Vector res(v);
	return res*=x;
}

Vector& Vector::operator *= ( double x )
{
	for ( int i = 0; i < getDim ( ); i++ )
		m_pCoord[i] *= x;
	return *this;
}

double operator * ( const Vector& v1, const Vector& v2 )
{
	if( v1.getDim( ) != v2.getDim( ) ){ 
		//cerr << "ERROR: incompatible vector sizes!\n";
		throw VectorException ( VEC_INCOMP_DIM );
	}
	double res =0;
	for ( int i = 0; i < v1.getDim ( ); i++ )
		res+=v1.m_pCoord[i]*v2.m_pCoord[i];
	return res;
}


bool operator == ( const Vector& v1, const Vector& v2 )
{
	if( v1.getDim( ) != v2.getDim( ) )
		return false;

	for ( size_t i = 0; i < v1.getDim( ); ++i ) {
		if ( v1.m_pCoord[i] != v2.m_pCoord[i] )
			return false;
	}
	return true;
}

bool operator != ( const Vector& v1, const Vector& v2 )
{
	return !( v1 == v2 );
}
