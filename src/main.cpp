#include <iostream>

#include "Alias.hh"
#include "Graph.hh"

using namespace std;

int main()
{
  PAMSI::Graph<pogon> testObj(10, 0.5, czy_plik::nPlik);

  cout<<testObj;
}
