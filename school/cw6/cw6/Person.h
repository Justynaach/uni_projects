#pragma once
#include <string>
using namespace std;
#include <iostream>

class Person
{
public:
	Person( string name = " ",int age = 0 );
	virtual ~Person();
	Person( const Person& p );

	Person& operator= ( const Person& p ) = default;

	void setName( string newName );
	void setAge( int newAge );

	string getName() const;
	int getAge() const;

	void setPerson( string newName,int newAge );

private:
	string mName;
	int mAge;
};

inline void Person::setName( string newName ) {

	this->mName = newName;

}

inline void Person::setAge( int newAge ) {

	this->mAge = newAge;
}

inline string Person::getName() const {

	return this->mName;
}

inline int Person::getAge() const {

	return this->mAge;
}
