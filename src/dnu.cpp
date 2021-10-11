#include <iostream>
#include <string>
auto main() -> int 
{
	int x;
	std::cout << "podaj 1 liczbe: \n";
	std::cin >> x;
	
	if (x==0){
		std::cout << "0";
		}
	else if(x>0){
		std::cout << "1";
		}
	else if(x<0){
		std::cout << "-1";
		}

}
