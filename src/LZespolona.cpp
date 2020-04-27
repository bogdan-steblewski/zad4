#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + ( LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = re+ Skl2.get_re();
  Wynik.set_im() = im + Skl2.get_im();
  return Wynik;
}


LZespolona  LZespolona::operator - ( LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.set_re() = re- Skl2.get_re();
  Wynik.set_im() = im - Skl2.get_im();
  return Wynik;
}



LZespolona  LZespolona::operator * ( LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = re*Skl2.get_re()-im *Skl2.get_im();
  Wynik.set_im() = re*Skl2.get_im()+im *Skl2.get_re();
  return Wynik;
}


LZespolona  LZespolona::operator / ( double  Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = re / Skl2;
  Wynik.set_im() = im / Skl2;
  return Wynik;
}

double LZespolona::modul2()
{
  return im*im+re*re;
}

LZespolona LZespolona::sprzezenie(LZespolona Skl1)
{
  Skl1.set_im()=-Skl1.get_im();
  return Skl1;
}

LZespolona  LZespolona::operator / ( LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik=*this*Skl2.sprzezenie(Skl2)/Skl2.modul2();
  return Wynik;
}

bool LZespolona::operator == ( LZespolona  Skl2)
{
  if(im==Skl2.get_im() && re== Skl2.get_re())
  {
    return true;
  }

  return false;
}

std::ostream &operator <<(std::ostream &Strm,LZespolona Skl1)
{

    Strm<<"("<<Skl1.get_re()<<std::showpos<<Skl1.get_im()<<std::noshowpos<<"i)";
    return Strm;
}

std::istream &operator >>(std::istream &Strm,LZespolona &Skl1)
{
  char znak;
  Strm>>znak;
  if(znak!='(')
  {
    Strm.setstate(std::ios_base::badbit);
  }
  Strm>>Skl1.set_re()>>Skl1.set_im();
    Strm>>znak;
  if(znak!='i')
  {
    Strm.setstate(std::ios_base::badbit);
  }
    Strm>>znak;
  if(znak!=')')
  {
    Strm.setstate(std::ios_base::badbit);
  }

  return Strm;
}