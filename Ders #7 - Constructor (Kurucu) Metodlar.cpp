#include <iostream>
#include <string>
#include <locale>

/*Constructor kurucu anlamýna gelir bir sýnýftan nesne türetildiði anda otomatik olarak çalýþan metoddur varsayýlan olarak sýnýf içerisine
bir kurucu tanýmlamasý yapmaz isek default olarak gövdesi boþ olarak bir kurucu tanýmlanýr. Kurucu fonksiyonlarda dikkat edilmesi gerekenler

-Kurucu fonksiyonlar public eriþim belirteci altýna yazýlmak zorundadýr.
-Kurucu fonksiyonlar sýnýfýn ismi ile ayný olmak zorundadýr.
-Kurucu fonksiyonlar geriye bir tip döndermez.
-Bir kurucu fonksiyon var ise ve 2 adet parametre alýyor ise o sýnýftan parametresiz bir nesne türetemeyiz veya parametresiz bir kurucu
fonksiyon oluþturmak zorundayýz.*/

class test
{
	private:
		int x;
		int y;
	public:
		test(); /*Paramatresiz kurucu*/
		test(int, int); /*Ýki parametreli kurucu*/
		int GET_X(){return x;}
		int GET_Y(){return y;}
		/*Prototip olarak tanýmlamayabiliriz içeride direkt olarak iþlem yapabiliriz.*/
};

test::test()
{
	std::cout << "Parametresiz Constructor Çalýþtý !" << std::endl;
	x = y = 5;
}

test::test(int x, int y = 5)
{
	std::cout << "Parametreli Constructor Çalýþtý !" << std::endl;
	this->x = x;
	this->y = y;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	test t1;
	return 0;
}




