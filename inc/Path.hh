#ifndef PATH_HH
#define PATH_HH

#include <iostream>
#include <memory>

#include "Graph.hh"
#include "Priority.hh"

namespace PAMSI
{
  template<class Typ>
  class Path
  {
  public:
    static void dijkstra_alg(const Graph<Typ>& graff, unsigned int start);
  };
}
#include "Path.cpp"

#endif
