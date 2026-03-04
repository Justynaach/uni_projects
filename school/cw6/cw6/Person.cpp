#include "Person.h"

Person::Person( string name,int age )
{
	setPerson( name,age );
}

Person::~Person()
{

}

Person::Person( const Person& p )
{
	*this=p;
}

void Person:: setPerson( string newName,int newAge ) {

	setName( newName );
	setAge( newAge );
}
