#include <iostream>
#include <string>

using namespace std;

class Wheel
{
    public:
        Wheel(){cout << __PRETTY_FUNCTION__ << endl;}
        virtual ~Wheel(){cout << __PRETTY_FUNCTION__ << endl;}

        int size;
};

class Engine
{
    public:
        Engine(){cout << __PRETTY_FUNCTION__ << endl;}
        virtual ~Engine(){cout << __PRETTY_FUNCTION__ << endl;}
        int horsepower;
};

class Body
{
    public:
        Body(){cout << __PRETTY_FUNCTION__ << endl;}
        virtual ~Body(){cout << __PRETTY_FUNCTION__ << endl;}
        std::string shape;
};

class Car
{
    public:
        Car(){cout << __PRETTY_FUNCTION__ << endl;}
        virtual ~Car()
        {
            delete _engine;
            delete _body;
            for(int i = 0; i < 4; i++)
                delete _wheels[i];
            cout << __PRETTY_FUNCTION__ << endl;
        }
        Wheel*   _wheels[4];
        Engine*  _engine;
        Body* _body;
        void specifications()
        {
            cout << "body:" << _body->shape << endl;
            cout << "engine horsepower:" << _engine->horsepower << endl;
            cout << "tire size:" << _wheels[0]->size << "'" << endl;
        }
};

/// Builder is responsible for constructing the smaller parts
class Builder
{
    public:
        Builder(){cout << __PRETTY_FUNCTION__ << endl;}
        virtual ~Builder(){cout << __PRETTY_FUNCTION__ << endl;}
        virtual Wheel* getWheel() = 0;
        virtual Engine* getEngine() = 0;
        virtual Body* getBody() = 0;
};


class Director
{
    public:
        Director(){cout << __PRETTY_FUNCTION__ << endl;}
        virtual ~Director()
        {
            cout << __PRETTY_FUNCTION__ << endl;
        }
        void setBuilder(Builder* builder)
        {
            _builder = builder;
        }

        Car* getCar()
        {
            Car* car = new Car();

            car->_body = _builder->getBody();

            car->_engine = _builder->getEngine();

            car->_wheels[0] = _builder->getWheel();
            car->_wheels[1] = _builder->getWheel();
            car->_wheels[2] = _builder->getWheel();
            car->_wheels[3] = _builder->getWheel();

            return car;
        }
    private:
        Builder* _builder;
};

class JeepBuilder : public Builder
{
    public:
        JeepBuilder(){cout << __PRETTY_FUNCTION__ << endl;}
        virtual ~JeepBuilder(){cout << __PRETTY_FUNCTION__ << endl;}
        Wheel* getWheel() override
        {
            Wheel* wheel = new Wheel();
            wheel->size = 22;
            return wheel;
        }

        Engine* getEngine() override
        {
            Engine* engine = new Engine();
            engine->horsepower = 400;
            return engine;
        }

        Body* getBody() override
        {
            Body* body = new Body();
            body->shape = "SUV";
            return body;
        }
};

class NissanBuilder : public Builder
{
    public:
        NissanBuilder(){cout << __PRETTY_FUNCTION__ << endl;}
        virtual ~NissanBuilder(){cout << __PRETTY_FUNCTION__ << endl;}
        Wheel* getWheel() override
        {
            Wheel* wheel = new Wheel();
            wheel->size = 16;
            return wheel;
        }

        Engine* getEngine() override
        {
            Engine* engine = new Engine();
            engine->horsepower = 85;
            return engine;
        }

        Body* getBody() override
        {
            Body* body = new Body();
            body->shape = "hatchback";
            return body;
        }
};

class VolgaBuilder : public Builder
{
    public:
        VolgaBuilder(){cout << __PRETTY_FUNCTION__ << endl;}
        virtual ~VolgaBuilder(){cout << __PRETTY_FUNCTION__ << endl;}
        Wheel* getWheel() override
        {
            Wheel* wheel = new Wheel();
            wheel->size = 15;
            return wheel;
        }

        Engine* getEngine() override
        {
            Engine* engine = new Engine();
            engine->horsepower = 151;
            return engine;
        }

        Body* getBody() override
        {
            Body* body = new Body();
            body->shape = "Sedan";
            return body;
        }
};

int main()
{
    Car* car; /// Final product

    /// A director who controls the process
    Director director;

    /// Concrete builders
    JeepBuilder jeepBuilder;
    NissanBuilder nissanBuilder;
    VolgaBuilder volgaBuilder;

    /// Build a Jeep
    cout << "Jeep" << endl;
    director.setBuilder(&jeepBuilder);
    car = director.getCar();
    car->specifications();

    delete car;

    cout << endl;

    /// Build a Nissan
    cout << "Nissan" << endl;
    director.setBuilder(&nissanBuilder);
    car = director.getCar(); /// be careful with Car* = must be deleted after
    car->specifications();

    delete car;

    cout << endl;


    /// Builder a Volga
    cout << "Volga" << endl;
    director.setBuilder(&volgaBuilder);
    car = director.getCar();
    car->specifications();

    delete car;

    return 0;
}
