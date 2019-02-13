#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

class Singleton;  // опережающее объ€вление

class SingletonDestroyer
{
  private:
    Singleton* p_instance;
  public:
    SingletonDestroyer(){std::cout << __PRETTY_FUNCTION__ << std::endl;}
    ~SingletonDestroyer();
    void initialize( Singleton* p );
};

class Singleton
{
  private:
    static Singleton* p_instance;
    static SingletonDestroyer destroyer;
  protected:
    Singleton() {std::cout << __PRETTY_FUNCTION__ << std::endl;}
    Singleton( const Singleton& );
    Singleton& operator=( Singleton& );
   ~Singleton() {std::cout << __PRETTY_FUNCTION__ << std::endl;}
    friend class SingletonDestroyer;
  public:
    static Singleton& getInstance();
    void test(){std::cout << __PRETTY_FUNCTION__ << std::endl;};
    int a = 5;
};

#endif
