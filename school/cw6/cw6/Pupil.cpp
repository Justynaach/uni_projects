#include "Pupil.h"

int Pupil::baseID=10000;

Pupil::Pupil( string name,int age ,string className):Person(name,age)
{
	setClassName( className );
	mID = to_string( baseID++ );

}

Pupil::Pupil( const Pupil& p )
{
	*this=p;
}

void Pupil::clearNotes()
{
	memset( mNotes, 0, MAXSUBJECTS * sizeof( double ) );
	mAve = 0;
}

void Pupil::setNote( Subjects subj,double note )
{
	if (subj >= POLSKI && subj < NIEMIECKI) {
		if( note >1 )
			mNotes[subj] = note;
	}
}

double Pupil::calcAve()
{
	double sum=0;
	int no=0;
	for (int subj = POLSKI; subj < MAXSUBJECTS;subj++) {
		if (mNotes[subj] > 1) {
			sum += mNotes[subj];
			no++;

		}
	}
	return mAve= (no) ? sum / no : 0;
}

void Pupil::printPupil()
{
	cout << getID() << ' ' << getName() << " (" << getClassname() << ")" << mAve << endl;
	cout << "\t";
	printOutfit();

}

