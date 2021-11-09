#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

class cat
{
	public:
		/*Ezilme var ise ezmek yerine bu method yok sayýlýr ve ezmeye çalýþýlan metod çalýþýr.*/
		virtual void GET_VOICE()
		{std::cout << "Miyav !" << std::endl;}	
};

class lion : public cat
{
	public:
		void GET_VOICE()
		{std::cout << "Kükreme !" << std::endl;}
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	cat c1; lion l1;
	c1.GET_VOICE();
	l1.GET_VOICE();
	cat *ary[2];
	ary[0] = &c1;
	ary[1] = &l1;
	ary[0]->GET_VOICE();
	ary[1]->GET_VOICE();
	return 0;
}











