#include <iostream>
#include <string>
#include <locale>

/*Sýnýf içerisindeki metodlara gönderilen deðerleri inpx þeklinde tutuyorduk bunun yerine programa sýnýftaki anlamýna gelen this iþaretini
kullanabiliriz.*/

class test
{
	private:
		int x;
		int y;
	public:
		void SET_X(int x)
		{this->x = x;}
		int GET_X()
		{return this->x;}
		void SET_Y(int);
		int GET_Y();
};

void test::SET_Y(int y)
{this->y = y;}

int test::GET_Y()
{return this->y;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	test t1;
	t1.SET_X(5);
	t1.SET_Y(8);
	std::cout << "Koordinat: (" << t1.GET_X() << ", " << t1.GET_Y() << ")" << std::endl;
	return 0;
}
