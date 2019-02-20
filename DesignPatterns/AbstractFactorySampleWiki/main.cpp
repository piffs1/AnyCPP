#include <iostream>

using namespace std;

class AbstractProductA;
class AbstractProductB;

class AbstractFactory
{
public:
    AbstractFactory(){cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~AbstractFactory(){cout << __PRETTY_FUNCTION__ << endl;}
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
};

class AbstractProductA //iface
{
public:
    AbstractProductA(){cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~AbstractProductA(){cout << __PRETTY_FUNCTION__ << endl;}

};

class AbstractProductB //iface
{
public:
    AbstractProductB(){cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~AbstractProductB(){cout << __PRETTY_FUNCTION__ << endl;}
};

class ProductA1 : public AbstractProductA
{
public:
    ProductA1(){cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~ProductA1(){cout << __PRETTY_FUNCTION__ << endl;}
};

class ProductA2 : public AbstractProductA
{
public:
    ProductA2(){cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~ProductA2(){cout << __PRETTY_FUNCTION__ << endl;}
};

class ProductB1 : public AbstractProductB
{
public:
    ProductB1(){cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~ProductB1(){cout << __PRETTY_FUNCTION__ << endl;}
};

class ProductB2 : public AbstractProductB
{
public:
    ProductB2(){cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~ProductB2(){cout << __PRETTY_FUNCTION__ << endl;}
};

class ConcreteFactory1 : public AbstractFactory
{
public:
    virtual AbstractProductA* CreateProductA() override;
    virtual AbstractProductB* CreateProductB() override;
    ConcreteFactory1(){cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~ConcreteFactory1(){cout << __PRETTY_FUNCTION__ << endl;}
};

AbstractProductA* ConcreteFactory1::CreateProductA()
{
    return new ProductA1();
}

AbstractProductB* ConcreteFactory1::CreateProductB()
{
    return new ProductB1();
}

class ConcreteFactory2 : public AbstractFactory
{
public:
    ConcreteFactory2(){cout << __PRETTY_FUNCTION__ << endl;}
    virtual AbstractProductA* CreateProductA() override;
    virtual AbstractProductB* CreateProductB() override;
    virtual ~ConcreteFactory2(){cout << __PRETTY_FUNCTION__ << endl;};
};

AbstractProductA* ConcreteFactory2::CreateProductA()
{
    return new ProductA2();
}

AbstractProductB* ConcreteFactory2::CreateProductB()
{
    return new ProductB2();
}

class Client
{
public:
    Client(AbstractFactory *factory){_factory = factory; _productA = _factory->CreateProductA(); _productB = _factory->CreateProductB();  cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~Client()
    {
        if(_factory!=nullptr)
            delete _factory;
        if(_productA!=nullptr)
            delete _productA;
        if(_productB!=nullptr)
            delete _productB;
    cout << __PRETTY_FUNCTION__ << endl;}
private:
    AbstractFactory *_factory;
    AbstractProductA *_productA;
    AbstractProductB *_productB;

};

int main()
{
    Client _client(new ConcreteFactory1()); /// OK
    Client* _client1 = new Client(new ConcreteFactory2()); ///OK
    delete _client1; /// OK
    return 0;
}
