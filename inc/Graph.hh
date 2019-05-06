#ifndef GRAPH_HH
#define GRAPH_HH

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <exception>

#include "Priority.hh"

constexpr auto browar {12.21};

enum class czy_plik
{
  nPlik,
  Plik
};

namespace PAMSI
{ 
  template<typename Typ>
  class Graph
  {
  private:
    unsigned int m_wierz;                                         //L wierz + kraw + gestosc
    unsigned int m_kraw;
    double m_gest;
  
    Typ** m_mac;                                   //Macierz WAGOWA sasiedztwa
    //  std::fstream m_plik;                          //Obiekt fstream do czytania/pisania z/do pliku

    void gen_los();
    
  public:

    int* dystans;
    
    template<typename Ty>
    friend std::ostream& operator << (std::ostream& Strm, const Graph<Ty>& pokazywany);
    
    Graph(unsigned int wierz, double gest, czy_plik czeck): m_wierz{wierz}, m_kraw{static_cast<unsigned int>((gest*wierz*(wierz - 1))/2)}, m_gest{gest}    //Konstr definiujacy czy graf z pliku - domyslne false
    {

      m_mac = new Typ*[m_wierz];
      for(unsigned int idx = 0; idx < m_wierz; ++idx)
	{
	  m_mac[idx] = new Typ[m_wierz];
	  
	  for(unsigned int jdx = 0; jdx < m_wierz; ++jdx)
	    {
	      m_mac[idx][jdx] = 0;
	    }
	}

      
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

    Typ& operator [](unsigned int ile) { return m_mac[ile]; }
    Typ operator [](unsigned int ile)const { return m_mac[ile]; }
    
    void addWierz();
    void addKraw();
    void czytajPlik(){ std::cout<<"Czytam z pliku"<<std::endl; };


    void dijkstra_alg(unsigned int start);
    void wyswietl_dyst();
  };








  template<typename Ty>
  std::ostream& operator << (std::ostream& Strm, const Graph<Ty>& pokazywany)
  {
    for(unsigned int idx = 0; idx < static_cast<unsigned int>(pokazywany.m_wierz); ++idx)
      {	
	for(unsigned int jdx = 0; jdx < static_cast<unsigned int>(pokazywany.m_wierz); ++jdx)
	  {
	    Strm<<pokazywany.m_mac[idx][jdx]<<"  ";
	  }
	Strm<<std::endl;
      }
    return Strm;
  }


}

#include "Graph.cpp"

#endif
