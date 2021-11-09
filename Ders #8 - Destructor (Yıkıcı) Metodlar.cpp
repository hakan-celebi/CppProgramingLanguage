#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Destructor Metodlar;
	Consturctor sýnýftan nesne türetildiði anda yani baþlangýç olarak çalýþan ve özellik veya metodlarýna eriþerek iþlem yapabilen
bir metoddur. Destructor ise bu sýnýftan üretilen nesnenin ömrü son bulunca yani ramden silinmeden hemen önce çalýþan iþlemlerdir.
pointerlar için;
	delete komutu çalýþtýðý zaman çalýþýr.
deðiþkenler için;
	program bitirildiði anda deðiþkenler de silinir bu sýranda çalýþýr.
	
	Genellikle nesne içerisinde pointer bir deðiþken kullanarak ve yer ayýrarak baþlamamýz gerekiyor constructor ile bunu
saðladýktan sonra ramin þiþmesini engellemek için yine delete yapmamýz gerekir. Bunu ise destructor metodunda saðlýyoruz.
~sýnýfismi() -> þeklinde tanýmlanýr.
*/

class coordinate
{
	private:
		int *x;
		int *y;
	public:
		coordinate(int, int);
		~coordinate()
		{delete x; delete y; std::cout << "Destructor çalýþtý ve bellek temizlendi. koordinat = (" << *x << ", " << *y << ")"
		<< std::endl;}
		void SET_COORDINATE(int, int);
		int GET_X(){return *x;}
		int GET_Y(){return *y;}
};

coordinate::coordinate(int x = 0, int y = 0)
{
	this->x = new int(); this->y = new int();
	*(this->x) = x; *(this->y) = y;
	std::cout << "Consturctor çalýþtý ve bellekte yer ayrýldý. koordinat = (" << *(this->x) << ", " << *(this->y) << ")"
	<< std::endl;
}

void coordinate::SET_COORDINATE(int x, int y)
{
	*(this->x) = x; *(this->y) = y; 
	std::cout << "(" << *(this->x) << ", " << *(this->y) << ") koordinatlarý ayarlandý !" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	int inpx; int inpy;
	coordinate *c1 = new coordinate(5, 2);
	coordinate c2;
	std::cout << "Koordinat x: "; std::cin >> inpx;
	std::cout << "Koordinat y: "; std::cin >> inpy;
	c2.SET_COORDINATE(inpx, inpy);
	delete c1;	
	return 0;
}


