#include <iostream>
#include <string>
auto main() -> int 
{
	int x;
	std::cout << "podaj 1 liczbe: \n";
	std::cin >> x; 
	if (x<0){
		x = (-1) * x;
		std::cout <<"wartosc absolutna: "<< x;
	} else{
		std::cout << "wartosc absolutna: "<< x;
	}


}
