#ifndef LISTGRAPH_HH
#define LISTGRAPH_HH

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <exception>
#include <list>

#include "Priority.hh"

namespace PAMSI
{
  template<typename Typ>
  struct Wezl
  {      
    Typ mm_klucz;
    int mm_wierz;

    Wezl(Typ klucz, int wierz): mm_klucz{klucz}, mm_wierz{wierz} {};
    Wezl(): mm_klucz{0}, mm_wierz{0} {};
      
    int& operator [](Typ klucz) {return mm_wierz;};
    int operator [](Typ klucz)const {return mm_wierz;};
  };


  
  template<typename Typ>
  class ListGraph
  {
  private:

    template<typename Ty>
    friend std::ostream& operator << (std::ostream& Strm, ListGraph<Ty>& pokazywany);
    
    
    int m_wierz;                                         //L wierz + kraw + gestosc
    int m_kraw;
    double m_gest;
  
    std::vector<std::list<Wezl<Typ>>> m_mac;                                   //Macierz WAGOWA sasiedztwa
    //  std::fstream m_plik;                          //Obiekt fstream do czytania/pisania z/do pliku

    void gen_los();
    
  public:

    int* dystans;
    
    
    ListGraph(int wierz, double gest, czy_plik czeck): m_wierz{wierz}, m_kraw{static_cast<int>((gest*wierz*(wierz - 1))/2)}, m_gest{gest}    //Konstr definiujacy czy graf z pliku - domyslne false
    {
      try
	{
	  czeck == czy_plik::nPlik ? addWierz() : czytajPlik();
	}
      catch(std::bad_alloc)
	{
	  std::cout<<"Cos sie popsulo i nie bylo mnie slychac - bad alloc - klasa Graph"<<std::endl;
	}

      dystans = new int[m_wierz];
    };

    Typ& operator [](int ile) { return m_mac[ile]; }
    Typ operator [](int ile)const { return m_mac[ile]; }
    
    void addWierz();
    void addKraw();
    void czytajPlik(){ std::cout<<"Czytam z pliku"<<std::endl; };


    void dijkstra_alg(int start);
    void wyswietl_dyst();
  };



  
  template<typename Ty>
  std::ostream& operator << (std::ostream& Strm, ListGraph<Ty>& pokazywany)
  {
    for(int idx = 0; idx < pokazywany.m_wierz; ++idx)
      {	
	for(typename std::list<Wezl<Ty>>::iterator iter = pokazywany.m_mac[idx].begin(); iter != pokazywany.m_mac[idx].end(); ++iter)
	  {
	    Strm<<"["<<(*iter).mm_klucz<<", "<<(*iter).mm_wierz<<"]"<<" -----> ";
	  }	  
	Strm<<std::endl;
      }
    return Strm;
  }


}

#include "ListGraph.cpp"

#endif
