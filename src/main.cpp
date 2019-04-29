#include <iostream>
#include <string>

#include "Alias.hh"
#include "Graph.hh"

using namespace std;

int main()
{
  int rozm {10};
  double gest {0.5};
  PAMSI::Graph<pogon> testObj(rozm, gest, czy_plik::nPlik);
  cout<<testObj;
   
  try
    {
      testObj.dijkstra_alg(rozm/2);
    }
  catch(...)
    {
      cout<<"Cos nie dziala\n";
    }

  testObj.wyswietl_dyst();
  
}

