#pragma once
#include "Person.h"

enum Subjects { POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI };
#define MAXSUBJECTS NIEMIECKI + 1

class Pupil: public Person
{
public:
	Pupil( string name = "",int age = 0,string className = "" );
	Pupil(const Pupil& p);

	string getClassname() const;
	string getID() const;
	void setClassName( string newClassName );


	void clearNotes();
	void setNote(Subjects subj, double note);

	double calcAve();

	void printPupil();
	virtual void printOutfit() =0; //metoda przyrownana do 0

protected:
	string mID;

private:
	string mClassName;
	static int baseID;
	double mAve;
	double mNotes[MAXSUBJECTS];

};

//---------------------------------------------------
inline string Pupil::getID() const {

	return this->mID;
}

inline string Pupil::getClassname() const {

	return this->mClassName;
}

inline void Pupil::setClassName( string newClassName )
{

	this->mClassName=newClassName;

}