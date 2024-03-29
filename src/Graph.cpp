namespace PAMSI
{  
  
  /************************************************/
  /* METODA GENERUJACA MACIERZ ZEROWA + DAJE KRAW */ 
  /************************************************/
  
  template<typename Typ>
  void Graph<Typ> :: addWierz()
  {        
    addKraw();
  }



  
  /**************************************************/
  /* METODA GENERUJACA CO NAJMNIEJ 1 KRAW Z K WIERZ */ 
  /**************************************************/ 

  template<typename Typ>
  void Graph<Typ> :: addKraw()
  {
    std::random_device rnd;
    std::mt19937 eng(rnd());     
    Typ buff;

    
    //CO NAJMNIEJ 1 DROGA "OD A DO F" dla grafu nieskierowanego
    for(unsigned int idx{0}; idx < m_wierz; ++idx)
      {
	if(idx < m_wierz - 1)
	  {
	    std::uniform_real_distribution<> distr(1, 500);       //TU ZMIENIC NA WIECEJ
	    buff = distr(eng);
	    
	    m_mac[idx][idx + 1] = static_cast<Typ>(buff);
	    m_mac[idx + 1][idx] = static_cast<Typ>(buff);
	  }
      }
    
    gen_los();                                          //Zacznij generowac losowe krawedzie
   }





  
  /***************************************************/
  /* METODA GENERUJACA LOS KRAW TAM GDZIE ICH NIE MA */ 
  /***************************************************/
  
  template<typename Typ>
  void Graph<Typ> :: gen_los()
  {
    std::random_device rnd;
    std::mt19937 eng(rnd());     
    Typ buff;

    int x,y;

    //Wygenerowanie losowego grafu
    for(unsigned int iter{0}; iter < m_kraw - m_wierz + 1; ++iter)   //Bo juz mamy podst sciezke
      {
	std::uniform_int_distribution<> dtr(0, m_wierz - 1);
	x = dtr(eng);
	y = dtr(eng);
	
	
	std::uniform_real_distribution<> distr(1, 500);           //TU ZMIENIC NA WIECEJ
	buff = static_cast<Typ>(distr(eng));

	if(m_mac[x][y] == 0 and x != y)
	  {
	    m_mac[x][y] = buff;
	    m_mac[y][x] = buff;
	  }

	bool flag{true};

	if(m_mac[x][y] != 0 or x == y)         //Jezeli jest kraw + to przek = wstaw gdziekolwiek
	  {
	    for(unsigned int idx = 0; idx < m_wierz; ++idx)
	      {
		for(unsigned int jdx = 0; jdx < m_wierz; ++jdx)
		  {
		    if(m_mac[idx][jdx] == 0 and idx != jdx)    //Jezeli nie ma kraw. + nie przek.
		      {	    
			m_mac[idx][jdx] = buff;
			m_mac[jdx][idx] = buff;
			flag = false;                          //Zakoncz to
			break;
		      }
		  }
		if(flag == false) break;                   //Przekaz flage o zerwaniu petli
	      }

	  }
	
      }
        
  }



  /**************************************************/
  /* NAJKROTSZE DROGI W GRAFIE - DIJKSTRA ALGORITHM */ 
  /**************************************************/
    
  template<typename Typ>
  void Graph<Typ> ::  dijkstra_alg(unsigned int start)
  {
    Priority<Typ> kolejka(m_wierz);

    kolejka.insert(0,start);

    for(unsigned int idx = 0; idx < m_wierz; ++idx)
      {
	if(idx == start) dystans[idx] = 0;
	else
	  {
	    dystans[idx] = 9999999;	    
	    kolejka.insert(dystans[idx], idx);
	  }
      }
    

    while(kolejka.m_rozm > 0)
      {
	int minimal = kolejka.back();
	kolejka.pop_back();
	
	for(unsigned int iter = 0; iter < m_wierz; ++iter)	  
	  {
	    if(m_mac[minimal][iter] != 0)
	      {
		if(dystans[iter] > dystans[minimal] + m_mac[minimal][iter])
		  {
		    dystans[iter] = dystans[minimal] + m_mac[minimal][iter];
		    kolejka.changePriority(dystans[iter], iter);
		  }
	      }
	  }


      }

    
  }


  /*******************************************/
  /* WYSWIETLA DYSTANSE PO WYKONANIU DIJKSTRY*/ 
  /*******************************************/

  template<typename Typ>
  void Graph<Typ> :: wyswietl_dyst()
  {
    for(unsigned int idx = 0; idx < m_wierz; ++idx)
      {
	std::cout<<"Dystans do wierzcholka: "<<idx<<" ---------------> "<<dystans[idx]<<std::endl;
      }
  }


  
}  
  





