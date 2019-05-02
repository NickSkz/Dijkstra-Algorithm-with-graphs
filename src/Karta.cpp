namespace PAMSI
{
  template<typename Typ>
  void list<Typ> :: push_back(Typ& data)
  {
    Node* neu = new Node();
    neu->dane = data;
    
    if(head == nullptr)
      {
	head = neu;
	++rozm;
      }
    else
      {
	neu->next = head;
	head->prev = neu;
	head = neu;
	++rozm;
      }
  }


  template<typename Typ>
  Typ& list<Typ> :: operator [](int pos)
  {
    if(pos >= size()) throw "Iterator poza rozmiarem tablicy";
    
    int countnik{0};
    iterator = head;
    
    while(countnik != pos)
      {
	iterator = iterator->next;
	++countnik;
      }
    return (*iterator).dane;
  }
  
}
