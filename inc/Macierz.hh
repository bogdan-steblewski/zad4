#ifndef Macierz_HH
#define Macierz_HH

#include "rozmiar.h"
#include <iostream>
#include <algorithm>
#include "Wektor.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename Typ, int Swymiar>
class SMacierz {
  SWektor<Typ, Swymiar> Tablica[Swymiar];
  Typ wyznacznik;
  public:
    SWektor<Typ, Swymiar> operator [](int i) const 
  {return Tablica[i];} 

  SWektor<Typ, Swymiar> & operator [](int i)  
  {return Tablica[i];} 
  Typ zwroc_wyzn()
  {return wyznacznik;}
void wyznacznik_Gauss();

SWektor<Typ, Swymiar> operator *(SWektor<Typ, Swymiar> Skl);

};
template <typename Typ, int Swymiar>
std::istream &operator>>(std::istream &Strm, SMacierz<Typ, Swymiar> &Mac)
{
    for (int i = 0; i < Swymiar; i++)
        Strm >> Mac[i];

    return Strm;
}
template <typename Typ, int Swymiar>
std::ostream &operator<<(std::ostream &Strm, const SMacierz<Typ, Swymiar> &Mac)
{
    for (int i = 0; i < Swymiar; i++)
        Strm << Mac[i] << std::endl;

    return Strm;
}
template <typename Typ, int Swymiar>
SWektor<Typ, Swymiar> SMacierz<Typ, Swymiar>::operator*(SWektor<Typ, Swymiar> Skl)
{
    SWektor<Typ, Swymiar> wynik;
    for (int i = 0; i < Swymiar; i++)
        wynik[i] = 0;
    for (int i = 0; i < Swymiar; i++)
        for (int j = 0; j < Swymiar; j++)
            wynik[i] = wynik[i] + Tablica[j][i] * Skl[j];

    return wynik;
}
template <typename Typ, int Swymiar>
void SMacierz<Typ, Swymiar>::wyznacznik_Gauss()
{
    SMacierz<Typ, Swymiar> tmp = *this;
    for (int i = 0; i < Swymiar; i++) // przejscie po wszystkich wierszach SMacierz<Typ, Swymiar>y
    {
        for (int j = i + 1; j < Swymiar; j++) // przejscie i spradzenie czy na przekontnej jest 0 jesli tak to zamiana wierszy
        {
            if (tmp[i][i] == 0)
                std::swap(tmp[i], tmp[j]);
        }
        if (tmp[i][i] == 0) // jesli nadal po zamainach na przekatnej ejst 0 wzynacznik jest rowny 0
        {
            wyznacznik = 0;
            return;
        }
        /**
         * 2 3 4
         * 1 3 1
         * 2 1 5

         */
        for (int j = i + 1; j < Swymiar; j++) // zerowanie itej kolumny
        {
            tmp[j] = tmp[j] - tmp[i] * (tmp[j][i] / tmp[i][i]);
        }
    }

    wyznacznik = 1;
    for (int i = 0; i < Swymiar; i++)
        wyznacznik = wyznacznik * tmp[i][i];
}
#endif
