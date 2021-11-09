#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*
Const Nesneler;
	Sabit olarak tanýmlanan nesneler için sadece constructor metodu ve destructor metodu çaðrýlýr ve iþlmler yapýlýr. Farklý bir
þekilde nesnemizin hiç bir özelliðine sýnýf dýþarýsýndan eriþemeyiz.

Const Metodlar;
	Eðer bir metod const olarak belirtilir ise o metod içerisinden sýnýfýn giçbir özelliðine müdahale veya deðiþtirme
uygulayamaz. Yani return std::cout gibi iþlemler yapabiliriz fakat this->x = val; þeklinde atama yapamayýz.
*/

int testvariable;

class test
{
	private:
		int x;
		int y;
	public:
		test(int, int);
		void SET_VALUE(int, int);
		/*Burada getter metodlarýnda sadece dýþarýya deðer dönderebilir olmasý gerekir yani bir deðeri set edememesi gerekir.*/
		int GET_X()const{testvariable = 8; /*Sýnýf dýþýndaki deðer deðiþtirildi.*/ return x;}
		int GET_Y()const{/*x = val; yapamýyoruz fakat sýnýf dýþýndaki bir deðiþken deðeri deðiþtirilebilir.*/ return y;}
};

test::test(int x = 0, int y = 0) : x(x), y(y)
{std::cout << "Constructor çalýþtý deðerler: " << this->x << ", " << this->y << std::endl;}

void test::SET_VALUE(int x = 0, int y = 0){this->x = x; this->y = y;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	testvariable = 0;
	const test t1(3, 2);
	test t2;
	t2.SET_VALUE(8, 9);
	std::cout << "testvariable = " << testvariable << std::endl;
	t2.GET_X(); /*Burada testvariable deðiþkeni deðiþtirildi.*/
	std::cout << "testvariable = " << testvariable << std::endl;
	/*Bu noktada t1 tanýmlandýktan sonra ne get ne set hiçbir metod ve özellik tekrardan çalýþtýrýlamaz.*/
	std::cout << "t2 için deðerler: " << t2.GET_X() << ", "	<< t2.GET_Y() << std::endl;
	return 0;
}

