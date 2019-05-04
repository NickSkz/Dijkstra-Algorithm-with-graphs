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

    Wezl* priority_queue;

    void v_heap(int rozm, int idx_rodz);
    void key_sort();
    
  public:
    int m_rozm;
    
    Priority(int rozm): m_rozm{0}{ priority_queue = new Wezl[rozm];};
    
    void insert(Typ klucz, int wierz);
    
    int length(){ return m_rozm; };
    int back(){ return priority_queue[m_rozm - 1].mm_wierz; };
    void pop_back(){ --m_rozm; key_sort(); };
    //bool empty(){ return (priority_queue.empty() ? true:false); };
    void changePriority(Typ klucz, int wierz);
    
    int& operator [](Typ kom);
    int operator [](Typ kom)const;
    
  };


  
  
}

#include "Priority.cpp"

#endif
