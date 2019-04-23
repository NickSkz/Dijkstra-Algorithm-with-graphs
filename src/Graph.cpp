namespace PAMSI
{
  /**************************************************************************/
                              /*ZROBIC W POCIAGU*/
  /**************************************************************************/
  
  template<typename Typ>
  void Graph<Typ> :: addWierz()
  {
    std::random_device rnd;
    std::mt19937 eng(rnd());
    
    std::vector<Typ> neues;

    Typ buff;
        
    for(unsigned int idx{0}; idx < m_wierz; ++idx)
      {
	m_mac.push_back(neues);
	
	for(unsigned int jdx{0}; jdx < m_wierz; ++jdx)
	  {
	    std::uniform_real_distribution<> distr(0, 20);
	    buff = distr(eng);
	    m_mac[idx].push_back( static_cast<Typ>(buff) );
 	  }
      }
  }



  
  
  


  
}
