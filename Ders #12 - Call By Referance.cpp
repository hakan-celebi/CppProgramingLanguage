#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*
	Call By Referance fonksiyonlarýný görmüþtük tanýmlanmasý örneðin bir int x deðiþkeninin deðerinin deðiþtirilmesi gerekiyor.
1.Yol
void referancesetvalue(int *x)
{
	std::cout << "Deðiþtirilicek deðer: "; std::cin >> *x;
}
Bu þekilde bir fonksiyon ile return gibi diðer iþlemler kullanýlmadan direkt olarak deðiþkenin deðeri deðiþtirilebilir.
fakat fonksiyon çaðrýlýrken:
referancesetvalue(&x); þeklinde çaðýrmamýz gerekiyor. Bu çaðýrým bize
pointerlar bir kendi adresleri birde gösterdiði adresleri vardýr.
*ptr -> gösterdiði adresteki deðer.
ptr -> gösterdiði adres.
&ptr ->kendi adresi.
deðiþkenler ise deðer ve kendi adreslerini tutar.
x -> deðeri
&x -> kendi adresi
yani bu çaðýrýmda *x = &x; þeklinde atama yapmýþ olduk. x pointerýnýn gösterdiði adres x deðiþkeninin adresi oldu. Bu sayede
x pointer ý üzerinde deðiþiklik yapar isek x deðiþkeni de deðiþmiþ olur.
farklý bir biçimde Call By Referance yapmak istersek;

2.Yol
void referancesetvalue(int &x)
{
	std::cout << "Deðiþtirilecek deðer: "; std::cin << x;
}
Burada ise fonksiyondaki x deðiþkeninin adresine parametredeki x deðerinin adresini atmamýz gerekir yani çaðrýlýrken:
referancesetvalue(&x) þeklinde olmak zorundadýr.
*/

void firstway(int *x)
{
	int a = *x;
	std::cout << "Deðiþtirilecek deðer: "; std::cin >> *x;
	std::cout << "x deðiþkeni " << a << " deðerinden " << *x << " deðeri ile deðiþtirildi" << std::endl;
}

void secondway(int &x)
{
	int a = x;
	std::cout << "Deðiþtirilecek deðer: "; std::cin >> x;
	std::cout << "x deðiþkeni " << a << " deðerinden " << x << " deðeri ile deðiþtirildi" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	int x; int selection;
	std::cout << "Baþlangýç deðeri: "; std::cin >> x;
	do
	{
		std::cout << "Ýlk yol[1]\nÝkinci yol[2]\nYaz[3]\nÇýkýþ[4]\nSeçim: "; std::cin >> selection;
		switch(selection)
		{
			case 1:
				firstway(&x);
				break;
			case 2:
				secondway(x);
				break;
			case 3:
				std::cout << "x deðeri: " << x << std::endl;
				break;
			case 4:
				std::cout << "Çýkýþ gerçekleþti." << std::endl;
				break;
			default:
				std::cout << "Geçerli bir seçim yapýnýz !\n" << std::endl;
				break;
		}
	}while(selection != 4);
	return 0;
}




