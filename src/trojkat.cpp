#include <iostream>
#include <string>
auto main() -> int 
{
	int x,y,z;
	std::cout << "podaj 1 bok: \n";
	std::cin >> x;
	std::cout << "podaj 2 bok: \n";
	std::cin >> y;
	std::cout << "podaj 3 bok: \n";
	std::cin >> z; 
	if ((x*x)+(y*y) ==(z*z) ){
	std::cout << "TAK \n";
	}
	else{
	std::cout<<"NIE \n"; 
	}

}
