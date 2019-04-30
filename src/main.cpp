#include <iostream>
#include <string>
#include <ctime>

#include "Alias.hh"
#include "Graph.hh"

using namespace std;

int main()
{
  int rozm;
  double gest;

  cout<<"Podaj ilosc wierzcholkow: \n";
  cin>>rozm;
  
  cout<<"Podaj gestosc grafu: \n";
  cin>>gest;

  if(gest < 0 or gest > 1) {cout<<"|***UWAGA***| Gestosc poza skala (ustawiono 0.5)\n"; gest = 0.5;}
    

  vector<PAMSI::Graph<pogon>> graffy;
 
  for(int idx = 0; idx < 3; ++idx)
    {
      PAMSI::Graph<pogon> testObj(rozm, gest, czy_plik::nPlik);
      graffy.push_back(testObj);
      //cout<<graffy[idx]<<endl;
    }


  vector<double> tab_czas(100);
  clock_t start, stop;
  

  for(auto& iter: graffy)
    {
      start = clock();
      iter.dijkstra_alg(rozm/2);
      stop = clock();
      tab_czas.push_back( double(stop-start)/CLOCKS_PER_SEC );
    }


  double czas_sr {0};
  for(auto& iter: tab_czas) czas_sr+= iter;

  cout<<"Sredni czas wykonywania pojedynczego algorytmu: "<<czas_sr/100<<endl;
}

