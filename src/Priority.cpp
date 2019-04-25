namespace PAMSI
{

  template<class Typ>
  void Priority<Typ> :: v_heap(int rozm, int idx_rodz)
  {
    int idx_min {idx_rodz};
    int leweD = idx_rodz * 2 + 1;
    int rightD = idx_rodz * 2 + 2;

    if(leweD < rozm and priority_queue[leweD].mm_klucz < priority_queue[idx_min].mm_klucz)
      {
	idx_min = leweD;
      }

    if(rightD < rozm and priority_queue[rightD].mm_klucz < priority_queue[idx_min].mm_klucz)
      {
	idx_min = rightD;
      }

    Wezl buff;

    if(idx_min != idx_rodz)
      {
	buff = priority_queue[idx_min];
	priority_queue[idx_min] = priority_queue[idx_rodz];
	priority_queue[idx_rodz] = buff;

	v_heap(rozm, idx_min);
      }
  }
  

  template<class Typ>
  void Priority<Typ> :: key_sort()
  {
    int N {length()};

    for(int idx {N/2 - 1}; idx >= 0; --idx)
      {
	v_heap(N, idx);
      }

    Wezl buff;
    
    for(int idx {N - 1}; idx > 0; --idx)
      {
	buff = priority_queue[0];
	priority_queue[0] = priority_queue[idx];
	priority_queue[idx] = buff;

	v_heap(--N, 0);
      }
  }


  

  
  template<class Typ>
  void Priority<Typ> :: insert(Typ klucz, int wierz)
  {
    Wezl wrzc(klucz, wierz);
    priority_queue.push_back(wrzc);
    key_sort();
  }

  
  template<class Typ>
  int& Priority<Typ> :: operator [](Typ kom)
  {
    unsigned int idx = 0;
    for(; priority_queue[idx].mm_klucz != kom; ++idx);
    
    return priority_queue[idx].mm_wierz;
  }

  
  template<class Typ>
  int Priority<Typ> :: operator [](Typ kom)const
  {
    unsigned int idx = 0;
    for(; priority_queue[idx].mm_klucz != kom; ++idx);
    
    return priority_queue[idx].mm_wierz;
  }
  
}
