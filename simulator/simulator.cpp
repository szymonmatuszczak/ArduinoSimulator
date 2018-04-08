#include <iostream>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>
#include <dlfcn.h>
using namespace std;
#include "../libarduino/libarduino.cpp"

int main(int argc, char* argv[])
{
    void* programToSimulate = dlopen("./exampleProject/example.so", RTLD_LAZY);

    if(!programToSimulate)
    {
        cout << "Błąd ładowania programu do symulacji!" << endl;
        exit(1);
    }

    void(*setup)() = (void(*)())dlsym(programToSimulate, "setup");
    void(*loop)() = (void(*)())dlsym(programToSimulate, "loop");

    if(!setup || !loop)
    {
        cout << "Program nie zawiera funkcji setup() i loop()!" << endl;
        exit(1);
    }

    onUpdate();
    setup();
    while(true) loop();

    dlclose(programToSimulate);
}
