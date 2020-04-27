#ifndef SWektor_HH
#define SWektor_HH

#include "rozmiar.h"
#include "LZespolona.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename Typ, int Swymiar>
class SWektor{
  Typ Tablica[Swymiar];
  public:

  Typ operator [](int i) const 
  {return Tablica[i];} 

  Typ & operator [](int i)  
  {return Tablica[i];} 
 
SWektor<Typ,Swymiar> operator +(SWektor<Typ,Swymiar> Skl);
SWektor<Typ,Swymiar> operator -(SWektor<Typ,Swymiar> Skl);
Typ operator *(SWektor<Typ,Swymiar> Skl);
SWektor<Typ,Swymiar> operator *(Typ Skl);
SWektor<Typ,Swymiar> operator /(Typ Skl);

};

template <typename Typ, int Swymiar>
SWektor<Typ,Swymiar> SWektor<Typ,Swymiar>::operator+(SWektor<Typ,Swymiar> Skl)
{
    SWektor<Typ,Swymiar> wynik;
    for (int i = 0; i < Swymiar; i++)
    {
        wynik[i] = Tablica[i] + Skl[i];
    }
    return wynik;
}
template <typename Typ, int Swymiar>
SWektor<Typ,Swymiar> SWektor<Typ,Swymiar>::operator-(SWektor<Typ,Swymiar> Skl)
{
    SWektor<Typ,Swymiar> wynik;
    for (int i = 0; i < Swymiar; i++)
    {
        wynik[i] = Tablica[i] - Skl[i];
    }
    return wynik;
}
template <typename Typ, int Swymiar>
Typ SWektor<Typ,Swymiar>::operator*(SWektor<Typ,Swymiar> Skl)
{
    Typ wynik = 0;
    for (int i = 0; i < Swymiar; i++)
    {
        wynik = wynik + Tablica[i] * Skl[i];
    }
    return wynik;
}
template <typename Typ, int Swymiar>
SWektor<Typ,Swymiar> SWektor<Typ,Swymiar>::operator*(Typ Skl)
{

    SWektor<Typ,Swymiar> wynik;
    for (int i = 0; i < Swymiar; i++)
    {
        wynik[i] = Tablica[i] * Skl;
    }
    return wynik;
}
template <typename Typ, int Swymiar>
SWektor<Typ,Swymiar> SWektor<Typ,Swymiar>::operator/(Typ Skl)
{
    SWektor<Typ,Swymiar> wynik;
    for (int i = 0; i < Swymiar; i++)
    {
        wynik[i] = Tablica[i] / Skl;
    }
    return wynik;
}
template <typename Typ, int Swymiar>
std::istream &operator>>(std::istream &Strm, SWektor<Typ,Swymiar> &Wek)
{
    for (int i = 0; i < Swymiar; i++)
        Strm >> Wek[i];

    return Strm;
}
template <typename Typ, int Swymiar>
std::ostream &operator<<(std::ostream &Strm, const SWektor<Typ,Swymiar> &Wek)
{
    for (int i = 0; i < Swymiar; i++)
        Strm << Wek[i] << "\t";

    return Strm;
}
#endif
