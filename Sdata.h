#pragma once

#include <memory>


template< class T >
class Sdata
{  
  std::shared_ptr<T> coreData;

public:

  Sdata();
  ~Sdata();

};

#include "Sdata.it.h"