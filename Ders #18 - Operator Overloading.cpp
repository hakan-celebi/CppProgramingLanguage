#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include "test.h"

/*Operator Overloading:
*, /, +, -, < vb. gibi operatörlerin iþlevlerini bir sýnýf için deðiþtirebiliyoruz buna ise overloading denir.
*/

int main()
{
	setlocale(LC_ALL, "Turkish");
	test t1(3, 2, 9, 52);
	test t2(8, 5);
	test total(t1 + t2);
	test difference = t1 - t2;
	test product = t1 * t2;
	test divided = t1 / t2;
	std::cout << "\nt1 x: " << t1.GET_X() << " t1 y: " << t1.GET_Y() << "\nt2 x: " << t2.GET_X() << " t2 y: " << t2.GET_Y() << std::endl;
	std::cout << std::endl;
	t1++; t2++;
	std::cout << "++ operatöründen sonra" << std::endl;
	std::cout << "\nt1 x: " << t1.GET_X() << " t1 y: " << t1.GET_Y() << "\nt2 x: " << t2.GET_X() << " t2 y: " << t2.GET_Y() << std::endl;
	std::cout << std::endl;
	t1--; t2--;
	std::cout << "-- operatöründen sonra" << std::endl;
	std::cout << "\nt1 x: " << t1.GET_X() << " t1 y: " << t1.GET_Y() << "\nt2 x: " << t2.GET_X() << " t2 y: " << t2.GET_Y() << std::endl;
	std::cout << std::endl;
	std::cout << "Toplam x: " << total.GET_X() << " Toplam y: " << total.GET_Y() << std::endl;
	std::cout << std::endl;
	std::cout << "Fark x: " << difference.GET_X() << " Fark y: " << difference.GET_Y() << std::endl;
	std::cout << std::endl;
	std::cout << "Çarpým x: " << product.GET_X() << " Çarpým y: " << product.GET_Y() << std::endl;
	std::cout << std::endl;
	std::cout << "Bölüm x: " << divided.GET_X() << " Bölüm y: " << divided.GET_Y() << std::endl;
	std::cout << std::endl;
	if(t1 < t2)
		std::cout << "t1 < t2 = true" << std::endl;
	else
		std::cout << "t1 < t2 = false" << std::endl;
	if(t1 <= t2)
		std::cout << "t1 <= t2 = true" << std::endl;
	else
		std::cout << "t1 <= t2 = false" << std::endl;
	if(t1 > t2)
		std::cout << "t1 > t2 = true" << std::endl;
	else
		std::cout << "t1 > t2 = false" << std::endl;
	if(t1 >= t2)
		std::cout << "t1 >= t2 = true" << std::endl;
	else
		std::cout << "t1 >= t2 = false" << std::endl;
	std::cout << "t1 = t2 den sonra" << std::endl;
	t1 = t2;
	std::cout << "\nt1 x: " << t1.GET_X() << " t1 y: " << t1.GET_Y() << "\nt2 x: " << t2.GET_X() << " t2 y: " << t2.GET_Y() << std::endl;
	return 0;
}
