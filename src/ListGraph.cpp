namespace PAMSI
{
      
  
  /************************************************/
  /* METODA GENERUJACA MACIERZ ZEROWA + DAJE KRAW */ 
  /************************************************/
  
  template<typename Typ>
  void ListGraph<Typ> :: addWierz()
  {    
    std::list<Wezl<Typ>> neues;

    // Lista ZEROWA
    for(unsigned int idx{0}; idx < m_wierz; ++idx)
      {
	m_mac.push_back(neues);
      }
    
    addKraw();
  }



  
  /**************************************************/
  /* METODA GENERUJACA CO NAJMNIEJ 1 KRAW Z K WIERZ */ 
  /**************************************************/ 

  template<typename Typ>
  void ListGraph<Typ> :: addKraw()
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
	    
	    Wezl<Typ> neu(buff, idx + 1);
	    Wezl<Typ> prime_neu(buff, idx);
	    
	    m_mac[idx].push_back(neu);
	    m_mac[idx + 1].push_back(prime_neu);
	  }
      }
    
    gen_los();                                          //Zacznij generowac losowe krawedzie
   }





  
  /***************************************************/
  /* METODA GENERUJACA LOS KRAW TAM GDZIE ICH NIE MA */ 
  /***************************************************/
  
  template<typename Typ>
  void ListGraph<Typ> :: gen_los()
  {
    std::random_device rnd;
    std::mt19937 eng(rnd());     
    Typ buff;

    int wezelo, prim_wezelo;                 //Losowy wezel

    //Wygenerowanie losowego grafu
    for(unsigned int iter{0}; iter < m_kraw - m_wierz + 1; ++iter)   //Bo juz mamy podst sciezke
      {
	std::uniform_int_distribution<> dtr(0, m_wierz - 1);
        wezelo = dtr(eng);
	prim_wezelo = dtr(eng);
	
	
	std::uniform_real_distribution<> distr(1, 500);           //TU ZMIENIC NA WIECEJ
	buff = static_cast<Typ>(distr(eng));

	Wezl<Typ> neu(buff, wezelo);
	Wezl<Typ> prime_neu(buff, prim_wezelo);



	//	std::cout<<wezelo<<" "<<prim_wezelo<<std::endl;
	    
	if(m_mac[wezelo].size() < m_wierz - 1 and m_mac[prim_wezelo].size() < m_wierz - 1)
	  {
	    m_mac[wezelo].push_back(neu);
	    m_mac[prim_wezelo].push_back(prime_neu); 
	  }

	else
	  {	    		
	    for(unsigned int idx = 0; idx < m_wierz; ++idx)
	      {
		if(m_mac[wezelo].size() < m_wierz and m_mac[prim_wezelo].size() < m_wierz)
		  {
		    m_mac[wezelo].push_back(neu);
		    m_mac[prim_wezelo].push_back(prime_neu);
		    break;
		  }
	      }
	  }
	
      	
      }
        
  }




  /**************************************************/
  /* NAJKROTSZE DROGI W GRAFIE - DIJKSTRA ALGORITHM */ 
  /**************************************************/
    
  template<typename Typ>
  void ListGraph<Typ> ::  dijkstra_alg(unsigned int start)
  {
    Priority<Typ> kolejka;

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
    

    while(!kolejka.empty())
      {
	int minimal = kolejka.back();
	kolejka.pop_back();

	for(typename std::list<Wezl<Typ>>::iterator iter = m_mac[minimal].begin(); iter != m_mac[minimal].end(); ++iter)
	  {
	    if(dystans[(*iter).mm_wierz] > dystans[minimal] + (*iter).mm_klucz)
	      {
		dystans[(*iter).mm_wierz] = dystans[minimal] + (*iter).mm_klucz;
		kolejka.changePriority(dystans[(*iter).mm_wierz], (*iter).mm_wierz); 
	      }
	  }

      }
    
  }


  /*******************************************/
  /* WYSWIETLA DYSTANSE PO WYKONANIU DIJKSTRY*/ 
  /*******************************************/

  template<typename Typ>
  void ListGraph<Typ> :: wyswietl_dyst()
  {
    for(unsigned int idx = 0; idx < m_wierz; ++idx)
      {
	std::cout<<"Dystans do wierzcholka: "<<idx<<" ---------------> "<<dystans[idx]<<std::endl;
      }
  }

}
