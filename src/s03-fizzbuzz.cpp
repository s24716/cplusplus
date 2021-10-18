#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int 
{
    if (argc == 0){
        return 1;
    }
    int n = std::stoi(argv[1]);
    for (auto i=1; i<=n; i++){
        std::cout<<i<<"\n";
        if (i%3==0 && i%5==0){std::cout<<"Fizz Buzz \n";}
        else if (i%5==0){std::cout<<"Buzz \n";}
        else if (i%3==0){std::cout<<"Fizz \n";}
        std::cout<<"---------------------- \n";
    
    }
    return 0;
}
