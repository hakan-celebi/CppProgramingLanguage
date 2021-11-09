#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

class coordinate
{
	private:
		int x;
		int y;
	public:
		/*Sýnýf içerisindeki deðiþkenler bir nesnenin özellikleri olurken, davranýþlarý ise methodlarý yani fonksiyonlarý olur. Her 
		tanýmlamada olduðu gibi methodlarýn da eriþim belirteçleri ile baðlantýsý vardýr. Eðer public olmaz ise nesne üzerinden direkt
		olarak methoda eriþilemez. Buradaki örnekte private olarak iki adet özellik x ve y deðiþkenlerini tanýmladýk fakat biz nesne
		üzerinden bu x ve y deðiþkenine eriþemeyiz bu yüzden set ve get metodlarý oluþturup bunlarý kullanýyoruz. Bir sýnýf içerisinde
		metod oluþturabilir veya prototipini oluþturup dýþarýda içeriðini belirtebilirsin. Bunun sebebi örneðin genel bir sýnýf var 
		baþka bir yerden aldýðýmýz sýnýf modelini kullanýyoruz, bu sýnýf modelindeki metodlarý tekrar deðiþtirmek isteyebiliriz bunun
		sebebi budur.*/
		/*Ýçeride oluþturulmuþ metodlar.*/
		void SET_X(int inpx)
		{x = inpx;}
		int GET_X()
		{return x;}
		
		/*Prototipi oluþturulmuþ metod.*/
		void SET_Y(int inpy);/*sadece int yazmamýz yeterli olur.*/
		int GET_Y();
};

/*Sýnýf içerisindeki bir yapýya olaþabilmek için :: kullanýlýr.*/
int coordinate::GET_Y(){return this->y;}
void coordinate::SET_Y(int inpy){this->y = inpy;}
/*This kodu bizim nesnemiz üzerinden bu metod çaðrýldýðý zaman nesne için anlamýna gelen bu nesnenin x özelliði anlamýna gelir.*/

int main()
{
	setlocale(LC_ALL, "Turkish");
	coordinate c1;
	int inpx; int inpy;
	std::cout << "X: "; std::cin >> inpx;
	std::cout << "Y: "; std::cin >> inpy;
	c1.SET_X(inpx); c1.SET_Y(inpy);
	std::cout << "Koordinatlar: (" << c1.GET_X() << ", " << c1.GET_Y() << ")" << std::endl;
	return 0;
}
