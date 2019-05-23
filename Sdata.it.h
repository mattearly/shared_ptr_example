#include "Sdata.h"

#include <iostream>

template <class T>
inline Sdata<T>::Sdata() : coreData( new T(0) , [this](T* ptr){ std::cout << "constructor deleter called\n"; delete ptr; } )
{

  std::cout << "------init with T(0)-------\n";

  if (!coreData.get()) 
  { 
    std::cout << "coreData is null\n"; 
  }
  else 
  {
    std::cout << "-> the value of coreData is " << *coreData.get() << std::endl;
    std::cout << "-> the address of coreData stuff is " << coreData.get() << std::endl;
    std::cout << "-> number of users holding coreData " << coreData.use_count() << std::endl;
  }

  std::cout << "------coreData.reset(new T(15), [this]...); -----\n";
  coreData.reset(new T(15), [this](T* ptr){ std::cout << "reset custom deleter called\n"; delete ptr; });
  
  std::cout << "-> the value of coreData is " << *coreData.get() << std::endl;
  std::cout << "-> the address of coreData stuff is " << coreData.get() << std::endl;
  std::cout << "-> number of users holding coreData " << coreData.use_count() << std::endl;

  std::cout << "------std::shared_ptr<T> sup = coreData;------\n";
  std::shared_ptr<T> sup = coreData;

  std::cout << "-> the value of sup is " << *sup << std::endl;
  std::cout << "-> the value of coreData is " << *coreData << std::endl;
  std::cout << "-> the address of coreData stuff is " << coreData.get() << std::endl;
  std::cout << "-> number of users holding coreData " << coreData.use_count() << std::endl;
  std::cout << "-> the addres of sup is " << sup.get() << std::endl;

  std::cout << "------*sup = 400-----\n"; 
  *sup = 400;

  std::cout << "-> the value of sup is " << *sup << std::endl;
  std::cout << "-> the value of coreData is " << *coreData << std::endl;
  std::cout << "-> the address of coreData stuff is " << coreData.get() << std::endl;
  std::cout << "-> number of users holding coreData " << coreData.use_count() << std::endl;

  auto deleter = [this](T* ptr){ std::cout << "VAR custom deleter called\n"; delete ptr; };
  std::cout << "------sup.reset(new T(16), deleter);------\n";
  sup.reset(new T(16), deleter);
  
  std::cout << "-> the value of sup is " << *sup << std::endl;
  std::cout << "-> the address of sup is " << sup.get() << std::endl;
  std::cout << "-> number of users holding sup " << sup.use_count() << std::endl;
  std::cout << "-----\n";
  std::cout << "-> the value of coreData is " << *coreData.get() << std::endl;
  std::cout << "-> the address of coreData stuff is " << coreData.get() << std::endl;
  std::cout << "-> number of users holding coreData " << coreData.use_count() << std::endl;

  std::cout << "------coreData.reset(new T[2], [this]...);------\n";
  coreData.reset(new T[3]{5, 10, 4}, [this](T* ptr){ std::cout << "custom deleter for arrays called\n"; delete[] ptr; });

  std::cout << "-> the value of array coreData is " << *coreData << " should be 5 " << std::endl;
  std::cout << "-> the value of array coreData + 1 is " << *(coreData.get() + 1) << " should be 10 " << std::endl;
  std::cout << "-> the value of array coreData + 2 is " << *(coreData.get() + 2) << " should be 4 " << std::endl;
  std::cout << "-> the address of coreData stuff is " << coreData.get() << std::endl;
  std::cout << "-> number of users holding coreData " << coreData.use_count() << std::endl;

  std::cout << "---------*(coreData.get() +1) = 20;--------\n";
  *(coreData.get() + 1) = 20;

  std::cout << "-> the value of array coreData + 1 is " << *(coreData.get() + 1) << " should be 20 " << std::endl;

  std::cout << "ZZZZ exiting constructor demo.\n";
}

template <class T>
inline Sdata<T>::~Sdata()
{

}
