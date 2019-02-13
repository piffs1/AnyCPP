#include "Singleton.h"

SingletonDestroyer::~SingletonDestroyer() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    delete p_instance;
}

Singleton * Singleton::p_instance = 0;
SingletonDestroyer Singleton::destroyer;


void SingletonDestroyer::initialize( Singleton* p ) {

    std::cout << __PRETTY_FUNCTION__ << std::endl;
    p_instance = p;
}
Singleton& Singleton::getInstance() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(!p_instance)     {
        p_instance = new Singleton();
        destroyer.initialize( p_instance);
    }
    return *p_instance;
}
