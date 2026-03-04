#include "Teacher.h"
#define koszty_u_przychodu 111.25

Teacher::Teacher( string name,int age,double salary,int experience,
    Subj subject,bool wychowawca,string klasa ):Worker(name,age,salary,experience)
{
	setSubject(subject);
	setTutor(wychowawca);
	setClass(klasa);
}

Teacher::Teacher( const Teacher& t )
{
    *this=t;
}

void Teacher::Salary()
{
    double podstawa = getSalary();
    int exp = getExperience();
    double bonus = Bonus(exp);
    double brutto = podstawa * (1 + bonus);

    if ( getTutor() )
    {
        brutto += 400;
    }
    double teacher = 0.8 * brutto * 0.5;
    double tax = Tax(0.8 * brutto, teacher ) + Tax(0.2 * brutto, koszty_u_przychodu);
    double netto = brutto - tax;

    cout << "brutto: " << brutto << "zl netto: " << netto << "zl "<< endl;
}

void Teacher::print()
{
    cout << "Nauczyciel: " << getName() 
        << ", wiek " << getAge() 
        << ", lata doswiadczenia " << getExperience()
        << "\nprowadzi przedmiot "; 
        switch (getSubject())
        {
            case TPOLSKI:       
                cout << "polski ";break;
            case TMATEMATYKA:   
                cout << "matematyka "; break;
            case TFIZYKA:       
                cout << "fizyka "; break;
            case TCHEMIA:       
                cout << "chemia "; 
                break;
            case TINFORMATYKA:  
                cout << "informatyka "; break;
            case TANGIELSKI:    
                cout << "angielski "; break;
            case TNIEMIECKI:    
                cout << "niemiecki "; break;
            default:
                cout <<"nieznane";
                break;
        }

    cout << "\nCzy jest wychowawca? " << (getTutor() ? "Tak" : "Nie");
    if (getTutor()) {
        cout << "\tklasy: " << getClass();
    }
    cout << endl;


}
