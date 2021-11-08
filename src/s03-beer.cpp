#include <iostream>
#include <string>

auto main (int argc, char* argv[]) -> int
{
    if (argc == 0) {
        return 1;
    }
    int z = std::stoi(argv[1]);

    for (auto i=z; i>=0; i--){
        std::cout<<i<<" bottles of beer on the wall, "<<i<<" bottles of beer."<<"\n"<<"Take one down, pass it around, ";
 
    }
    return 0;
}
