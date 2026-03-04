#include "Matrix.h"

Matrix::Matrix ( int row, int col, int elem )
{
	if( col < 2 || row < 2 )
		throw MatrixException( MAT_DIM_ERROR ); 
	Row = row;
	m_pCoord = new Vector[Row];
	for(int i=0; i<Row;i++ )
		m_pCoord[i] = Vector(col, elem );
}

Matrix::Matrix ( const Matrix& m )
{
	m_pCoord = nullptr;
	Row = 0;
	*this = m;
}

Matrix::~Matrix ( )
{
	delete[] m_pCoord;
}

istream& operator >> ( istream& in, Matrix& m )
{
	for( int i=0; i < m.GetRowNo(); i++ ){
		in >> m.m_pCoord[i];
		
	}
	return in;
}

ostream& operator << ( ostream& out, const Matrix& v )
{
	out << "\n";
	for( int i=0; i< v.GetRowNo( );i++){ 
		out << v.m_pCoord[i]; out << " ";
		if ( i < v.GetRowNo( ) - 1 ) 
			out << " \n";
	}
	return out;
}

Matrix& Matrix::operator = ( const Matrix& m )
{
	if((GetRowNo( ) != m.GetRowNo( )) || (GetColNo() != m.GetColNo( ))){ 
		delete[] m_pCoord;
		CreateMatrix( m.GetRowNo( ), m.GetColNo( ) );
	}
	CopyMatrix( m );
	return *this;
}

bool operator ==( const Matrix& m1, const Matrix& m2 )
{
	if (( m2.GetRowNo( ) != m1.GetRowNo ( ) ) || ( m1.GetColNo ( ) != m2.GetColNo ( ) ))
		return false;
	for ( int i = 0; i < m1.GetRowNo( ); ++i ) {
		if ( m1.m_pCoord[i] != m2.m_pCoord[i] )
			return false;
	}
	return true;
}

bool operator != ( const Matrix& m1, const Matrix& m2 )
{
	return !( m1 == m2 );
}

Vector* Matrix::operator () ( const Matrix& m )
{
	return m.m_pCoord;
}

//mnozenie---------------------------------------------------
const Vector operator * ( const Matrix& m,const Vector& v )
{
	if (m.GetColNo() != v.getDim())
	{
		throw MatrixException( MAT_DIM_ERROR );
	}

	Vector vec( m.GetRowNo(), 0 );

	for (int i = 0; i < m.GetRowNo(); i++)
	{
			vec[i] = m.m_pCoord[i] * v;
	}
	return vec;
}


const Matrix operator *( const Matrix& m1,const Matrix& m2 )
{
	if ( m1.GetColNo() != m2.GetRowNo() )
		throw MatrixException( MAT_INCOMP_DIM );

	Matrix res(m1.GetRowNo(), m2.GetColNo());

	for ( int i=0; i < m1.GetRowNo(); i++ )
	{
		for (int j=0; j < m2.GetColNo(); j++)
		{
			double sum=0;
			for( int k=0;k<m1.GetColNo() ;k++ )
			{
				sum+= m1.m_pCoord[i][k] * m2.m_pCoord[k][j];
			}
			res.m_pCoord[i][j]=sum;
		}
	}
	return res;
}

