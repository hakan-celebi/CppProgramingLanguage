#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include "ary.h"

int main()
{
	setlocale(LC_ALL, "Turkish");
	int ary[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *pary = new int[10];
	for(int i = 0; i < 10; i++)
		*(pary + i) = i + 11;
	if(Contains(ary, 84))
		std::cout << "Ýçeriyor" << std::endl;
	else
		std::cout << "Ýçermiyor" << std::endl;
	if(Contains(pary, 12))
		std::cout << "Ýçeriyor" << std::endl;
	else
		std::cout << "Ýçermiyor" << std::endl;
	return 0;
}
