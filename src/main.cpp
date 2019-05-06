#include <iostream>
#include <string>
#include <ctime>

#include "Alias.hh"
#include "Graph.hh"
#include "ListGraph.hh"
#include "Karta.hh"

using namespace std;

int main()
{
  int rozm[] = {10, 50, 100, 150, 200, 280, 350, 420, 500};
  double gest[] = {0.25, 0.5, 0.75, 1};
  /*
  cout<<"Podaj ilosc wierzcholkow: \n";
  cin>>rozm;
  
  cout<<"Podaj gestosc grafu: \n";
  cin>>gest;
  
  if(gest < 0 or gest > 1) {cout<<"|***UWAGA***| Gestosc poza skala (ustawiono 0.5)\n"; gest = 0.5;}
  */
  /*
  PAMSI::Graph<pogon> testObj(rozm, gest, czy_plik::nPlik);
  cout<<testObj;
  testObj.dijkstra_alg(rozm/2);
  testObj.wyswietl_dyst();
  */
  /*
  PAMSI::Wezl<pogon> nodinho(12, 4);
  PAMSI::list<PAMSI::Wezl<pogon>> testList;
  testList.push_back(nodinho);
  testList.push_back(nodinho);
  testList.push_back(nodinho);
  
  cout<<testList[1].mm_wierz<<endl;
  */

  for(int iiidx = 0; iiidx < 9; ++iiidx)
    {
      for(int jjjdx = 0; jjjdx < 4; ++jjjdx)
	{
  
	  vector<PAMSI::ListGraph<pogon>> graffy;
 
	  for(int idx = 0; idx < 100; ++idx)
	    {
	      PAMSI::ListGraph<pogon> testObj(rozm[iiidx], gest[jjjdx], czy_plik::nPlik);
	      graffy.push_back(testObj);
	      //cout<<graffy[idx]<<endl;
	    }


	  vector<double> tab_czas;
	  clock_t start, stop;

   

	  for(auto& iter: graffy)
	    {
	      start = clock();
	      iter.dijkstra_alg(rozm[iiidx]/2);
	      stop = clock();
	      tab_czas.push_back( double(stop-start)/CLOCKS_PER_SEC );
	    }


	  double czas_sr {0};
	  for(auto& iter: tab_czas) czas_sr+= iter;

	  cout<<"ROZMIAR: "<<rozm[iiidx]<<"  GESTOSC: "<<gest[jjjdx]<<"  Sredni czas wykonywania pojedynczego algorytmu: "<<czas_sr/100<<endl;
	}
    }
}

