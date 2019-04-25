#ifndef PRIORITY_HH
#define PRIORITY_HH

#include <iostream>
#include <vector>


namespace PAMSI
{

  template<class Typ>
  class Priority
  { 
  private:
    class Wezl
    {
    public:
      Typ mm_klucz;
      int mm_wierz;

      Wezl(Typ klucz, int wierz): mm_klucz{klucz}, mm_wierz{wierz} {};
      Wezl(): mm_klucz{0}, mm_wierz{0} {};

      int& operator [](Typ klucz) {return mm_wierz;};
      int operator [](Typ klucz)const {return mm_wierz;};
    };

    std::vector<Wezl> priority_queue;

    void v_heap(int rozm, int idx_rodz);
    void key_sort();
    
  public:
    Priority(){};
    
    void insert(Typ klucz, int wierz);
    
    int length(){return priority_queue.size();};
    int back(){return priority_queue.back().mm_wierz;};
    int front(){return priority_queue.front().mm_wierz;};

    int& operator [](Typ kom);
    int operator [](Typ kom)const;
    
  };


  
  
}

#include "Priority.cpp"

#endif
