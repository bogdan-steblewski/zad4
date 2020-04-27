#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;



int main()
{
  char znak;
  cin>>znak;
  if( znak =='r')
  {
  UkladRownanLiniowych<double,5>   UklRown;   // To tylko przykladowe definicje zmiennej

  
  cout << endl << " Start programu " << endl << endl;
  cin>>UklRown;
  cout<<UklRown;
  if(UklRown.Oblicz())
  {
    cout<<"wynik :"<<endl;
    cout<<UklRown.zwroc_wynik()<<endl;
    UklRown.blad(); 
  }
  }
  else if(znak =='z')
  {
      UkladRownanLiniowych<LZespolona,5>   UklRown;   // To tylko przykladowe definicje zmiennej

  
  cout << endl << " Start programu " << endl << endl;
  cin>>UklRown;
  cout<<UklRown;
  if(UklRown.Oblicz())
  {
    cout<<"wynik :"<<endl;
    cout<<UklRown.zwroc_wynik()<<endl;
    UklRown.blad(); 
  }
  }
  
}
