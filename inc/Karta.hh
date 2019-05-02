#ifndef KARTA_HH
#define KARTA_HH

#include "ListGraph.hh"

namespace PAMSI
{
  template<typename Typ>
  class list
  {
  private:
    struct Node
    {
      Typ dane;
      Node* next;
      Node* prev;
    };

    Node* head;
    int rozm;
    
  public:

    Node* iterator;
    
    list(){ head = nullptr; rozm = 0; iterator = nullptr; };
    void push_back(Typ& data);
    int size(){ return rozm; };

    Typ& operator [](int pos);
    Typ operator [](int pos)const{};
  };
}

#include "Karta.cpp"

#endif

