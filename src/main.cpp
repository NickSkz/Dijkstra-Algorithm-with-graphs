#include <iostream>
#include <string>

#include "Alias.hh"
#include "Graph.hh"
#include "Priority.hh"

using namespace std;

int main()
{
  PAMSI::Graph<pogon> testObj(10, 0.5, czy_plik::nPlik);
  cout<<testObj;

  /*
  PAMSI::Priority<string> p_queue;
  p_queue.insert("piwo", 7);
  p_queue.insert("wodka", 2);
  p_queue.insert("bimber", 6);
  p_queue.insert("sex", 9);
  p_queue.insert("narkotyki", 1);
  */


  PAMSI::Priority<int> p_que;
  p_que.insert(12,5);
  p_que.insert(6,12);
  p_que.insert(61,2);
  p_que.insert(4,7);
  p_que.insert(44,9);

  std::cout<<p_que.back()<<std::endl;
  std::cout<<p_que.front()<<std::endl;
}
