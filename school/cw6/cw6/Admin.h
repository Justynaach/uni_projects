#pragma once
#include "Worker.h"
enum Stanowisko { mlodszy_specjalista, specjalista, starszy_specjalista };


class Admin: public Worker
{
public:
	Admin( string name="", int age=0, double salary=0, int experience=0, Stanowisko stanowisko=mlodszy_specjalista);
	Admin( const Admin& a );

	void Salary();
//	double Brutto();
//	double Netto();

	void print();

	Stanowisko getPost();
	void setPost( Stanowisko stanowisko );
private:
	Stanowisko m_stanowisko;
};

//-------------------------------

inline void Admin::setPost( Stanowisko stanowisko )
{
	this->m_stanowisko = stanowisko;
}

inline Stanowisko Admin::getPost(){
	return this->m_stanowisko;
}