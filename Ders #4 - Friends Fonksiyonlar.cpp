#include <iostream>
#include <string>
#include <locale>

/*Program içerisinde acil çýkýþ kapýsý oluþtursun oluþturmasýn bir nedenden ötürü private olan bir deðere ulaþmak istiyoruz bunun için
arkadaþ yani friends fonksiyonlar kullanýlýr. Bir arkadaþýn ile birþeylerini paylaþýr gibi sýnýf içerisindeki bir çok þeyi yaplayabilir.
Fonksiyonun kullaným örneðini yapalým.*/

class test
{
	private:
		int x;
	public:
		int GET_X(){return x;}
		friend void SET_X(test &, int);
};

void SET_X(test &t, int inpx)
{t.x = inpx;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	test *t1 = new test;
	SET_X(*t1, 12);
	std::cout << t1->GET_X() << std::endl;
	return 0;
}
