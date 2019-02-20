#include <iostream>
#include <memory>
using namespace std;

int countFreeClasses = 0;

void CheckFreeClasses()
{
    cout << "Count free classes is " << countFreeClasses << endl;
}

class Product
{
public:
    Product(){countFreeClasses++; cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~Product(){countFreeClasses--; cout << __PRETTY_FUNCTION__ << endl;}
    virtual void Print() = 0;
};

class ProductX : public Product
{
public:
    ProductX(){countFreeClasses++; cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~ProductX(){countFreeClasses--; cout << __PRETTY_FUNCTION__ << endl;}
    virtual void Print() override
    {
        cout << "I'm PRODUCT X" << endl;
    }
};

class ProductY : public Product
{
public:
    ProductY(){countFreeClasses++; cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~ProductY(){countFreeClasses--; cout << __PRETTY_FUNCTION__ << endl;}
    virtual void Print() override
    {
        cout << "I'm PRODUCT Y" << endl;
    }
};

class FactoryProduct
{
public:
    FactoryProduct(){countFreeClasses++; cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~FactoryProduct(){countFreeClasses--; cout << __PRETTY_FUNCTION__ << endl;}
    virtual Product* CreateProduct() = 0;
};

class FactoryX : public FactoryProduct
{
public:
    FactoryX(){countFreeClasses++; cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~FactoryX(){countFreeClasses--; cout << __PRETTY_FUNCTION__ << endl;}
    virtual Product* CreateProduct()
    {return new ProductX();}
};

class FactoryY : public FactoryProduct
{
public:
    FactoryY(){countFreeClasses++; cout << __PRETTY_FUNCTION__ << endl;}
    virtual ~FactoryY(){countFreeClasses--; cout << __PRETTY_FUNCTION__ << endl;}
    virtual Product* CreateProduct()
    {return new ProductY();}
};

class Client
{
public:
    Client(FactoryProduct *factory)
    {
        countFreeClasses++;
        _factory = factory;
        _product = _factory->CreateProduct();
        cout << __PRETTY_FUNCTION__ << endl;
        cout << "ADDRESSES _FACTORY " << _factory << endl;
        cout << "ADDRESSES _product " << _product << endl;
        _product->Print();
    }
    virtual ~Client(){
        cout << "DELETING FACTORY " <<_factory << endl;
        if(_factory!=nullptr)
            delete _factory;
        if(_product!=nullptr)
            delete _product;
        cout << __PRETTY_FUNCTION__ << endl;
        countFreeClasses--;
        CheckFreeClasses();
        }
private:
    FactoryProduct* _factory;
    Product* _product;
};

int main()
{

    Client *client = new Client(new FactoryX()); /// OK
    delete client; /// OK
    CheckFreeClasses();
    Client _client(new FactoryY()); /// OK

    /*FactoryX X;
    cout << "FACTORY X ADDRESS " << &X << endl;
    Client _client2(&X); /// PROBLEM CLASS TWICE DELETING
    */
    return 0;
}
