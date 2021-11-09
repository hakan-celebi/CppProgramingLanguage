#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Bu kodun anlamý standart isim uzayýný kullandýr.*/
//using namespace std; using sabit tüm kaynak kodda kullanýlan isim uzayýný belirler.

/*Ýsim uzaylarý örneðin bir ortak projede çalýþýyorsunuz ve farklý kaynak kodlarý üzerinde çalýþýyorsunuz örneðin projemiz içerisinde
for döngüsü kullanýrýz ve for döngüsü için alýþageldik olan i deðiþkenidir bu yüzden i yi her iki programcý da tanýmlar daha sonra program
birleþtirilip derlendiði zaman iki adet ayný isimli deðiþken tanýmlamasý yapýldýðý için hata verir bu yüzden isim uzaylarý kullanýlýr.
örneðin biz bir program yazalým programýn amacý 5 boyutlu bir int dizisine kullanýcýdan aldýðý deðerleri atan ve bu deðerleri sonrasýnda
ekrana yazan bir program. Yazma kýsmýný ayrý programcý atama iþlemini ayrý programcý yapsýn.*/

namespace programmerone
{
	int i;
	int dizi[5];
	void SET_VALUE(int *a)
	{
		std::cout << "Girmek istediðiniz deðer: "; std::cin >> *a;
	}
}

namespace programmertwo
{
	int i;
	int GET_VALUE(int *a)
	{
		return *a;
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	for(programmerone::i = 0; programmerone::i < 5; programmerone::i++)
		programmerone::SET_VALUE(&programmerone::dizi[programmerone::i]);
	for(programmertwo::i = 0; programmertwo::i < 5; programmertwo::i++)
		std::cout << programmertwo::GET_VALUE(&programmerone::dizi[programmertwo::i]) << std::endl;
	return 0;
}



