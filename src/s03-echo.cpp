#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int {
    auto const first = std::string{argv[1]};
    auto const second = std::string{argv[2]};    
    if((first == "-n" && second == "-r") || (first == "-r" && second == "-n")){
        for (int m=argc; m>0; m--){
            std::cout<<argv[m-1]<<" ";
        }
    }    
    else if((first == "-l" && second == "-r") || (first == "-r" && second == "-l")){
        for (int l=argc; l>0; l--){
            std::cout<<argv[l-1]<<"\n";
        }
    }
    else if (argc == 0){
        return 1;
    }


    if (first == "-n"){
        for (int i=0; i<=argc; i++){
            std::cout<<argv[i]<<" ";
        }    
    } 
    else if (first == "-r"){
        for (int j=argc; j>0; j--){
            std::cout<<argv[j-1]<<" ";      
        }
        std::cout<<"\n";    
    } 
    else if(first == "-l"){
        for (int k=0; k<=argc; k++){
            std::cout<<argv[k]<<"\n";
        }
    }
    
    
    return 0;
}


