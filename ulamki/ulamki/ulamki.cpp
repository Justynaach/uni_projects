#include <iostream>
using namespace std;
#include "Rational.h"


int main()
{
    Rational r1(1,3);
    cout << "r1= " << r1 << endl;

    Rational r2( 6,3 );
    cout << "r2= " << r2 << endl;

    Rational suma;
    suma=r1 + r2;
    cout << "r1+r2= " << suma << endl;

    Rational roznica;
    roznica=r1 - r2;
    cout << "r1-r2= " << roznica << endl;

    Rational iloczyn;
    iloczyn=r1 * r2;
    cout << "r1*r2= " << iloczyn << endl;

    Rational iloraz;
    iloraz=r1 / r2;
    cout << "r1/r2= " << iloraz << endl;

    cout << "postac dziesietna r1: " << r1.Value() << endl;

    return 0;
}



