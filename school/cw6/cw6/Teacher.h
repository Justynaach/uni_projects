#pragma once
#include "Worker.h"
enum Subj { TPOLSKI,TMATEMATYKA,TFIZYKA,TCHEMIA,TINFORMATYKA,TANGIELSKI,TNIEMIECKI };

class Teacher: public Worker
{
public:
	Teacher( string name="",int age=0,double salary=0,int experience=0,Subj subject=TPOLSKI,bool wychowawca = 0 ,string klasa = "");
	Teacher( const Teacher& p );

	void Salary();

	void setTutor( bool wychowawca );
	void setClass( string klasa );
	void setSubject( Subj subject );


	bool getTutor( );
	Subj getSubject();
	string getClass();

	void print();

private:
	Subj m_subject;
	bool m_wychowawca;
	string m_klasa;
};

//-----------------------------------------------------------------
inline void Teacher::setTutor( bool wychowawca )
{
	this->m_wychowawca=wychowawca;
}

inline void Teacher::setClass( string klasa )
{
	this->m_klasa=klasa;
}

inline void Teacher::setSubject( Subj subject )
{
	this->m_subject=subject;
}

inline Subj Teacher::getSubject()
{
	return this->m_subject;
}

inline string Teacher::getClass()
{
	if(getTutor())
		return this->m_klasa;
	return "brak";
}

inline bool Teacher::getTutor( )
{
	return this->m_wychowawca;
}