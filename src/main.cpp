#include <iostream>

#include "Graph.hh"

using namespace std;

int main()
{
  PAMSI::Graph<int> testObj(10, 0.5, czy_plik::nPlik);

  cout<<testObj;
}
