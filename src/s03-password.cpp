#include <iostream>
#include <string>

auto getValue(std::string value) ->std::string{
    std::cout<<value<<"password =  ";
    auto n = std::string{};
    std::getline(std::cin, n); 
    return n;
}

auto main(int argc, char* argv[]) -> int{
    if (argc == 0){
        return 1;
    }
    auto const password = std::string{argv[1]};
        std::string passTyped = "";
    do{
        passTyped = getValue("");
            if(passTyped==password){
                std::cout<<"Pomysle logowanie \n";
            }
    }while(password!=passTyped);


    return 0;
}
