#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  public:

  LZespolona(double re=0, double im=0)
  {
    this->re=re;
    this->im=im;
  }
  double get_re() const {return re;}
  double get_im() const {return im;}
  double &set_re(){return re;}
  double &set_im(){return im;}
  bool operator == ( LZespolona  Skl2);

LZespolona  operator + ( LZespolona  Skl2);

LZespolona  operator - ( LZespolona  Skl2);

LZespolona  operator * ( LZespolona  Skl2);

LZespolona  operator / ( double  Skl2);

LZespolona  operator / ( LZespolona  Skl2);

double modul2();

LZespolona sprzezenie(LZespolona Skl1);

};





std::ostream &operator <<(std::ostream &Strm,LZespolona Skl1);
std::istream &operator >>(std::istream &Strm,LZespolona &Skl1);

#endif
