using namespace std;
#include <iostream>

#include "Matrix.h"

int main()
{
    Matrix m1( 2,2,0 );
    cout << "podaj macierz m1 wpisujac wiersz po wierszu (2x2): " << endl;
    cin >> m1;
    cout << "m1: " << m1 << endl;

    //testowanie macierzy
    Matrix m2 ( 3, 3, 6);
    cout<< "m2: " << m2 << endl;

    Matrix m3 ( 3, 3, -2 );
    cout << "m3: " << m3 << endl;

    Matrix m4(3,3,0);
    m4=m2*m3;
    cout <<"m4=m2*m3 " << m4 << endl;

    //macierz razy wektor 
    Vector v5(3, 0);
    cout << "wpisz wartosci wektora v5 (rozm 3): " << endl;
    cin >> v5;
    Vector v6;
    v6 =m3 * v5;
    cout << "v6=m3*v5=  " << v6 << endl;

    //wektory 
    Vector v1;
    cout << "v1= " << v1 << endl;

    Vector v2( 4,1 );
    cout << "v2= " << v2 << endl;

    Vector v3(5,3);
    Vector v4( v3 );    //vector v3=v4; 
    cout << "v4= " << v4 << endl;

    v2=v4;
    cout << "v2=v4= " << v2 << endl;

    v3=v2+v4;
    cout << "v3=v2+v4= " << v3 << endl;

    v3=v3+(-2);
    cout << "v3+(-2)= " << v3 << endl;

    cout << "Podaj wspolrzedne wektora o rozmiarze: " << v2.getDim( ) << " : ";
    cin >> v2;
    cout << "v2= " << v2 << endl;

    v3=v3-1;
    cout << "v3=v3-1= " << v3 << endl;

    v3=v3 * 2;
    cout << "v3=v3*2= " <<  v3 << endl;

    cout << "v2*v3= " <<  v2*v3 << endl;

    v3[1]=20;
    v3[2]=v3[0]-1;
    cout << "v3= " << v3 << endl;

    return 0;
}

