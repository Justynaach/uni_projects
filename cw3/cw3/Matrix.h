#pragma once
#include <iostream>
using namespace std;
#include "Vector.h"
//tablica wektorow 
#define MAT_OTHER_ERROR 0X01
#define MAT_DIM_ERROR 0X02
#define MAT_INCOMP_DIM 0X04
#define MAT_ALLOC_ERROR 0X80
typedef unsigned short USHORT;

class MatrixException
{
public:
	MatrixException( USHORT mErr=MAT_OTHER_ERROR );
	const char* getReason();
private:
	USHORT mErrCode;
};


inline MatrixException::MatrixException ( USHORT mErr )
{
	mErrCode=mErr;
}

inline const char* MatrixException::getReason ()
{
	switch (mErrCode)
	{
	case MAT_DIM_ERROR: return "ERROR: improper matrix size!\n";
	case MAT_INCOMP_DIM: return "ERROR: incompatible matrix sizes!\n";
	case MAT_ALLOC_ERROR: return "ERROR: memory allocation error!\n";
	default: return "Other error!\n";
	}
}

class Matrix
{
private:
	int Row;
	Vector* m_pCoord;

public:
	Matrix ( int row=2, int col = 2, int elem=0 );
	Matrix ( const Matrix& m );
	virtual ~Matrix ( );

	Matrix& operator = (const Matrix& m );
	friend istream& operator >> ( istream& in, Matrix& v );
	friend ostream& operator << ( ostream& out, const Matrix& v );
	const Vector& operator[] ( int ix ) const;
	const Vector& operator[] ( int ix );
	//rzutowanie
	Vector* operator () ( const Matrix& m );


	//mnozenie
	friend const Vector operator * ( const Matrix& m, const Vector& v);
	friend const Matrix operator * ( const Matrix& m1,const Matrix& m2 );

	friend bool operator == ( const Matrix& m1, const Matrix& m2 );
	friend bool operator != ( const Matrix& m1, const Matrix& m2 );
public:
	int GetColNo ( ) const;
	int GetRowNo( ) const; 
private:
	void CopyMatrix ( const Matrix& m ); 
	void CreateMatrix ( int row, int col );
};


//INLINE FUNCTIONS
inline int Matrix::GetColNo ( ) const
{
	if ( !m_pCoord )
		return 0;
	return m_pCoord[0].getDim( );
}

inline int Matrix::GetRowNo ( ) const {
	return Row;
}

inline void Matrix::CopyMatrix ( const Matrix& m )
{
	for( int i=0; i<Row; i++ )
		m_pCoord[i]=m.m_pCoord[i];
}

inline const Vector& Matrix::operator[]( int ix ) const {
	if ( ix < 0 || ix >= GetRowNo ( ) ) {
		
		throw MatrixException(MAT_DIM_ERROR);
		return m_pCoord[0];
	}
	return m_pCoord[ix];
}

inline const Vector& Matrix::operator[]( int ix ) {
	if ( ix < 0 || ix >= GetRowNo ( ) ) {

		throw MatrixException( MAT_DIM_ERROR );
		return m_pCoord[0];
	}
	return m_pCoord[ix];
}

inline void Matrix::CreateMatrix ( int row, int col )
{
	if( row<2 || col<2 ){ 
		row=2;
		throw MatrixException(MAT_INCOMP_DIM);
	}
	Row=row;
	m_pCoord = new Vector[Row];

	for ( int i = 0; i < Row; ++i )
		m_pCoord[i] = Vector ( col, 0.0 );
}