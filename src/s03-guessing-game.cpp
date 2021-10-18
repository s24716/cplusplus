#include <iostream>
#include <string>
#include <random>

auto getValue(std::string value) -> int
{
    std::cout<<value<<"guess :  ";
    auto n = std::string{};
    std::getline(std::cin, n); 
    return std::stoi(n);
}

auto main() -> int
{
    std::random_device rd;
    std :: uniform_int_distribution < int > d100 (1 , 100);

    auto const randNumb = d100(rd);
    int userInput;
    do{
        userInput = getValue("");
        if(userInput>randNumb){
            std::cout<<"number to big! \n";
        } else if(userInput<randNumb){
            std::cout<<"number to small! \n";
        } else { std::cout<<"just right! \n"; }

    } while (randNumb != userInput);


    return 0;
}
