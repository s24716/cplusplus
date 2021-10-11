#include <iostream>
#include <string>
auto main() -> int 
{
	int x,y,z;
	std::cout << "podaj 1 liczbe: \n";
	std::cin >> x;
	std::cout << "podaj 2 liczbe:\n";
	std::cin >> y;
	std::cout << "podaj 3 liczbe: \n";
	std::cin >> z;
	if (x>y && x>z){
		std::cout << x;
		}
	else if(y>x && y>z){
		std::cout << y;
		}
	else if(z>x && z>y){
		std::cout << z;
		}
	return 0;
}
