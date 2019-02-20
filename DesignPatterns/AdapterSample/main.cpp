#include <iostream>
#include "AdapterSample.h"
#include "AdapterCatGodSample.h"

using namespace std;

int main()
{
    Client _client; /// AdapterSample.h
    _client.Request(new Target()); /// OK
    _client.Request(new Adapter()); /// OK
    Animal _animal; /// AdapterCatGodSample.h
    _animal.Request(new Puppy()); /// OK
    _animal.Request(new AdapterPuppy()); /// OK
    return 0;
}
