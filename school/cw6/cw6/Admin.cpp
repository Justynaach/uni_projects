#include "Admin.h"
#define koszty_u_przychodu 111.25

Admin::Admin( string name,int age,double salary,int experience, Stanowisko stanowisko)
    :Worker(name,age,salary,experience)
{
    setPost(stanowisko);
}

Admin::Admin( const Admin& a )
{
	*this=a;
}

void Admin::Salary()
{
    double podstawa = getSalary();
    int exp = getExperience();
    double bonus = Bonus(exp);
    double brutto = podstawa * (1 + bonus);
    double tax = Tax(brutto, koszty_u_przychodu);

    double netto = brutto - tax;
    
    cout << "brutto: " << brutto << "zl netto: " << netto << "zl" << endl;
}

void Admin::print()
{
    cout << "Pracownik administracyjny: " << getName()
        << ", wiek: " << getAge()
        << ", lata doswiadczenia: " << getExperience()
        << "\nstanowisko: ";

    switch (getPost())
    {
    case mlodszy_specjalista:
        cout << "mlodszy specjalista";
        break;
    case specjalista:
        cout << "specjalista";
        break;
    case starszy_specjalista:
        cout << "starszy specjalista";
        break;
    default:
        cout << "nieznane";
        break;
    }

    cout << endl;
}
