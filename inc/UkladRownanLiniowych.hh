#ifndef UkladRownanLiniowych_HH
#define UkladRownanLiniowych_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"
#include <cmath>

template <typename Typ, int Swymiar>
class UkladRownanLiniowych {
  SMacierz<Typ, Swymiar> Mac;
  SWektor<Typ, Swymiar> Wek;
  SWektor<Typ, Swymiar> wynik;
  public:
  void blad();
 SWektor<Typ, Swymiar> zwroc_wynik() const
  {
    return wynik;
  }

  SMacierz<Typ, Swymiar> zwroc_mac() const
  {
    return Mac;
  }

  SMacierz<Typ, Swymiar> & ustaw_mac() 
  {
    return Mac;
  }

  SWektor<Typ, Swymiar> zwroc_SWektor()const
  {
    return Wek;
  }

  SWektor<Typ, Swymiar> & ustaw_SWektor() 
  {
    return Wek;
  }
  bool Oblicz();
};
template <typename Typ, int Swymiar>
std::istream &operator>>(std::istream &Strm, UkladRownanLiniowych<Typ,Swymiar> &UklRown)
{
    Strm >> UklRown.ustaw_mac() >> UklRown.ustaw_SWektor();
    return Strm;
}
template <typename Typ, int Swymiar>
std::ostream &operator<<(std::ostream &Strm, const UkladRownanLiniowych<Typ,Swymiar> &UklRown)
{
    Strm << "M^T" << std::endl;
    Strm << UklRown.zwroc_mac() << std::endl;
    Strm << "SWektor<Typ, Swymiar> wyrazow wolnych" << std::endl;
    Strm << UklRown.zwroc_SWektor() << std::endl;
    return Strm;
}
template <typename Typ, int Swymiar>
void UkladRownanLiniowych<Typ,Swymiar>::blad()
{
    std::cout<<"SWektor<Typ, Swymiar> bledu "<<Mac*wynik-Wek<<std::endl;
   
}
template <typename Typ, int Swymiar>
 bool UkladRownanLiniowych<Typ,Swymiar>::Oblicz()
 {
    Typ Wyz;
    SMacierz<Typ, Swymiar> tmp;
    Mac.wyznacznik_Gauss();
    Wyz=Mac.zwroc_wyzn();
    if(Wyz==0)
    {
        for(int i=0; i<Swymiar; i++)
        {
            tmp=Mac;
            tmp[i]=Wek;
            tmp.wyznacznik_Gauss();
            if(tmp.zwroc_wyzn()==0)
            {
            std::cout<<"uklad nieoznaczony"<<std::endl;
            return false;
            }

        }

            std::cout<<"brak rozwiazan"<<std::endl;
            return false;
    }


        for(int i=0; i<Swymiar; i++)
        {
            tmp=Mac;
            tmp[i]=Wek;
            tmp.wyznacznik_Gauss();
            wynik[i]=tmp.zwroc_wyzn()/Mac.zwroc_wyzn();
        }
        return true;
 }

#endif
