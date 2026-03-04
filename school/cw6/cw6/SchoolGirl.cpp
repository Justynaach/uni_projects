#include "SchoolGirl.h"

SchoolGirl::SchoolGirl( string name,int age,string className): Pupil( name,age,className )
{
	Pupil::mID = "F_" + Pupil::mID;
}
void SchoolGirl::printOutfit()
{
	cout << "biala bluzka, krawat szkolny i marynarka, czarna/granatowa spodnica, plaskie obuwie";
}