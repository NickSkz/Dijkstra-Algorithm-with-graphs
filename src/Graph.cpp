namespace PAMSI
{ 
  template<typename Typ>
  void Graph<Typ> :: addWierz()
  {    
    std::vector<Typ> neues;

    // MACIERZ ZEROWA
    for(unsigned int idx{0}; idx < m_wierz; ++idx)
      {
	m_mac.push_back(neues);
	
	for(unsigned int jdx{0}; jdx < m_wierz; ++jdx)
	  {
	    m_mac[idx].push_back(0);
 	  }
      }
    
    addKraw();
  }


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
	    std::uniform_real_distribution<> distr(1, 9);       //TU ZMIENIC NA WIECEJ
	    buff = distr(eng);
	    
	    m_mac[idx][idx + 1] = static_cast<Typ>(buff);
	    m_mac[idx + 1][idx] = static_cast<Typ>(buff);
	  }
      }

    int x,y;

    //Wygenerowanie losowego grafu
    for(unsigned int iter{0}; iter < m_kraw - m_wierz + 1; ++iter)   //Bo juz mamy podst sciezke
      {
	std::uniform_int_distribution<> dtr(0, m_wierz - 1);
	x = dtr(eng);
	y = dtr(eng);
	
	
	std::uniform_real_distribution<> distr(1, 9);           //TU ZMIENIC NA WIECEJ
	buff = distr(eng);

	if(m_mac[x][y] == 0 and x != y)
	  {
	    m_mac[x][y] = buff;
	    m_mac[y][x] = buff;
	    //std::cout<<"Kurwwa"<<std::endl;
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
		if(flag == false) break;
	      }
	  }
      }

  }
  
  
}  
  





















  /*


    if(m_mac[x][y] == 0)    //By byl prosty - nie mial petli
    {                                 //Wloz krawedz tam gdzie jej nie ma i nie na przek.
    if(x != y) m_mac[x][y] = static_cast<Typ>(buff);            
    else
    {
    flag = true;
	    
    for(unsigned int idx = 0; idx < m_wierz; ++idx)
    {
    for(unsigned int jdx = 0; jdx < m_wierz; ++jdx)     
    {                                        //daj to gdziekolwiek byle nie na przek
    if(m_mac[idx][jdx] == 0 and idx != jdx)
    {
    m_mac[x][y] = static_cast<Typ>(buff);
    flag = false;
    break;
    }
    }
    if(flag == false) break;
    }
    }
    }


    if(m_mac[x][y] == 0)    //By byl prosty - nie mial petli
    {                                 //Wloz krawedz tam gdzie jej nie ma i nie na przek.
    if(x != y) m_mac[x][y] = static_cast<Typ>(buff);            

    }


  */
