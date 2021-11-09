/*Örnek: Bir veya daha fazla oyunculu düþmanlarýn var olduðu bir oyun.*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
/*Written by Hakan ÇELEBÝ*/

/*Ýnsan, köpek, kedi gibi hayvan yada insanlar vardýr bunlarýn ortak özelliði canlýlýktýr yanli canli sýnýfý*/
class canli
{
	/*Sadece sýnýf içerisinden eriþilebilen tanýmlamalar.*/
	private:
		int age;
	/*Her yerden yani oluþturulan nesne veya kalýtým yapýlan sýnýf tan eriþilebilen tanýmlamalar.*/
	public:
		std::string fullname;
		/*Dýþardan age deðiþkenine eriþilemediði için set metodu ile yaþ ayarlanýyor.*/
		bool SET_AGE(int inpage)
		{
			age = inpage;
			return (age > -1);
		}
		/*Dýþardan age deðiþkenine eriþilemediði için get metodu ile yaþ deðiþkenin deðerine eriþilebiliyor.*/
		int GET_AGE()
		{return age;}
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	/*Pointer ile canli sýnýfýndan türetilen insan nesnesi oluþturuldu*/
	canli *insan = new canli();
	int inpage;
	/*Kullanýcýdan ismi alýnýp insan nesnesinin ismine atanýyor.*/
	std::cout << "Ýsimi: "; getline(std::cin, insan->fullname);
	/*Yaþ 0'dan küçük olamaz set metodu içerisinde bu kontrol ediliyor ve eðer yaþ 0'dan küçük ise geriye 0 deðil ise geriye
	1 dönderiyor geriye dönderilen deðer 0 ise while tekrarlanýyor böylelikle yaþýn 0'dan küçük girilmesi engelleniyor.*/
	do
	{
		std::cout << "Yaþý: "; std::cin >> inpage;
	}while(!insan->SET_AGE(inpage));
	system("CLS");
	/*Get metodu ise geriye int bir deðer yani age dönderiyor bu þekilde age deðiþkenine eriþilebiliyor.*/
	std::cout << "Ýsimi: " << insan->fullname << "\nYaþý: " << insan->GET_AGE() << std::endl;
	delete insan;
	return 0;
}
