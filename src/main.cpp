#include <iostream>
#include <string>

#include "Alias.hh"
#include "Graph.hh"

using namespace std;

int main()
{
  PAMSI::Graph<pogon> testObj(10, 0.5, czy_plik::nPlik);
  cout<<testObj;

  PAMSI::Priority<string> p_queue;
  p_queue.insert("piwo", 7);
  p_queue.insert("wodka", 2);
  p_queue.insert("bimber", 6);
  p_queue.insert("sex", 9);
  p_queue.insert("narkotyki", 1);

  cout<<p_queue["bimber"]<<endl;

  try
    {
      testObj.dijkstra_alg(0);
    }
  catch(...)
    {
      cout<<"Cos nie dziala\n";
    }

  testObj.wyswietl_dyst();
}

