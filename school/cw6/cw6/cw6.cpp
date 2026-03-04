#include <iostream>
using namespace std;
#include "SchoolGirl.h"
#include "SchoolBoy.h"
#include "Teacher.h"
#include "Admin.h"


void printAllPupils( Pupil** pupils, int pupilsNo);
void printAllWorkers( Worker** workers,int workersNo );
void sortByBrutto(Worker** workers, int workersNo);


int main()
{
    SchoolGirl g1( "Nowak Agnieszka",17,"3A" );
    g1.setNote( POLSKI,3.5 );
    g1.setNote( MATEMATYKA,4.5 );
    g1.setNote( CHEMIA,4.0 );
    g1.setNote( ANGIELSKI,3.5 );
    g1.setNote( NIEMIECKI,3.0 );


    SchoolGirl g2( "Sobota Paulina",18,"4B" );
    g2.setNote( POLSKI,3.0 );
    g2.setNote( INFORMATYKA,4.5 );
    g2.setNote( FIZYKA,4.5 );
    g2.setNote( NIEMIECKI,4.0 );


    SchoolGirl g3( "Kozub Maria",18,"3b" );
    g3.setNote( MATEMATYKA,4.5 );
    g3.setNote( FIZYKA,4.0 );
    g3.setNote( INFORMATYKA,4.5 );

    SchoolBoy b1( "Kowalski Marcin",17,"3B" );
    b1.setNote( INFORMATYKA,5.0 );
    b1.setNote( FIZYKA, 5);
    b1.setNote( ANGIELSKI,5 );

    SchoolBoy b2( "Pawelek Krzysztof",18,"4B" );
    b2.setNote( POLSKI, 5 );
    b2.setNote( MATEMATYKA,3.5 );
    b2.setNote( ANGIELSKI,4.0 );
    b2.setNote( NIEMIECKI,4.0 );


    Pupil* pupils[] = {&g1,&g2,&g3,&b1,&b2};
    printAllPupils( pupils,sizeof( pupils ) / sizeof( Pupil* ) );

    cout <<"---------------------Pracownicy------------------------------\n";
    Teacher t1( "Kowalski Marian",30,3000,5,TPOLSKI,true,"2B");
    Teacher t2( "Kowalski Marek",50,4000,25,TFIZYKA );
    Teacher t3( "Ciesla Marek",35,3000,7,TMATEMATYKA, true, "4A");
    Teacher t4( "Ryga Renata",60,4000,33,TNIEMIECKI );
    Teacher t5( "Kozub Marlena",44,3500,18,TCHEMIA, true, "3C");

    //pracownicy administracyjni
    Admin a1("Dziwulski Andrzej", 60, 3500, 32, starszy_specjalista);
    Admin a2( "Piatkowski Damian",30,2000,2,mlodszy_specjalista );


    Worker* workers[] = {&t1,&t2,&t3,&t4,&t5, &a1, &a2}; 
    printAllWorkers( workers, sizeof(workers)/sizeof(Worker*));

    return 0;
}

void printAllPupils( Pupil** pupils,int pupilsNo ){
    for (int i = 0; i < pupilsNo;i++) {

        pupils[i]->calcAve();
        pupils[i]->printPupil();
        cout << endl;
    }
    cout << endl;

}

void sortByBrutto(Worker** workers, int workersNo)
{
    for (int i = 0; i < workersNo - 1; i++)
    {
        for (int j = i + 1; j < workersNo; j++)
        {
            if (workers[j]->getSalary() > workers[i]->getSalary())
                swap(workers[i], workers[j]);
        }
    }
}

void printAllWorkers( Worker** workers,int workersNo )
{
    for (int i = 0; i < workersNo; i++)
    {
        workers[i]->print();
        workers[i]->Salary();
        cout << endl;
    }
}
