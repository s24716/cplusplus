#include <iostream>
#include <string>

auto main (int argc, char* argv[]) -> int
{
    if (argc == 0) {
        return 1;
    }
    int z = std::stoi(argv[1]);

    for (auto i=z; i>=0; i--){
        
        if (i==0){
            std::cout<<"No more bottles of beer on the wall, no more bottles of beer. \n"<<
            "Go to the store and buy some more, "<<z<<" bottles of beer on the wall..."<<"\n";
        } else if (i==1){
            std::cout<<i<<" bottles of beer on the wall, "<<i<<" bottles of beer."<<"\n";

        } else {
            std::cout<<i<<" bottles of beer on the wall, "<<i<<" bottles of beer."<<"\n"<<"Take one down, pass it around, ";
        }
    }
    return 0;
}
