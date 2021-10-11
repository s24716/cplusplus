#include <iostream>
#include <string>
auto main() -> int 
{
	int x,y;
	std::cout << "podaj 1 liczbe: \n";
	std::cin >> x;
	std::cout << "podaj 2 liczbe:\n";
	std::cin >> y;
	if (x==y){
		std::cout <<  x<<"=="<< y;
		}
	else if(x>y){
		std::cout << x << ">"<< y;
		}
	else if(x<y){
		std::cout << x << "<" << y;
		}

}
