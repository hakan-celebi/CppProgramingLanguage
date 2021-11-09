#include <iostream>
#include <string>
#include <locale>
class test_b; /*test_a sýnýfý içerisinde friend tanýmlamasý yapacaðýmýz için yukarýsýnda tanýmlamak zorundayýz.*/

class test_a
{
	private:
		int x;
	public:
		int GET_X(){return x;}
		friend void SET_X(test_a &, int);
		void SET_Y(test_b &, int); /*fonksiyon prototipi tanýmlandý çünkü burada deðil dýþarýda fonksiyon içeriði yazýlmalýdýr.*/
		friend std::ostream& operator<<(std::ostream &, test_a &);
		friend std::istream& operator>>(std::istream &, test_a &);
};

class test_b
{
	private:
		int y;
	public:
		int GET_Y(){return y;}
		void SET_Y(int inpy){y = inpy;}
		friend class test_a; /*test_a sýnýfýnýn bu sýnýfa arkadaþ olduðunu bu sýnýftan ödünç alabileceðini belirttik.*/
};
/*Friends fonksiyonlarý görmüþtük bu sefer de sýnýflar içerisinde arkadaþlýk nasýl oluyor bakalým. Bir sýnýf diðer sýnýf ile arkadaþ
ise diðer sýnýfýn metodlarý veya deðiþkenleri üzerinde deðiþiklik yapabilme yetisine sahip olur örnek olarak burda yapalým.*/

void SET_X(test_a &t, int inpx)
{t.x = inpx;} /*friend fonksiyon.*/

void test_a::SET_Y(test_b &t, int inpy)
{t.y = inpy;}

std::ostream& operator<<(std::ostream& o, test_a &t)
{o << t.x; return o;}

std::istream& operator>>(std::istream &i, test_a &t)
{i >> t.x; return i;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	test_a t1; test_b t2;
	SET_X(t1, 15);
	std::cout << "x: " << t1.GET_X() << std::endl;
	t1.SET_Y(t2, 18);/*Friend sýnýfý içerisinden set edildi.*/
	std::cout << "y: " << t2.GET_Y() << std::endl;
	t2.SET_Y(5); /*Kendi üzerinden set edildi.*/
	std::cout << "y: " << t2.GET_Y() << std::endl;
	std::cout << t1 << std::endl;
	std::cin >> t1;
	std::cout << t1 << std::endl;
	/*
	Eðer referans & parametreye:
		pointer ise *isim ile
		normal ise sadece isim ile
	Eðer pointer * parametreye
		pointer ise sadece isim ile
		normal ise &isim ile
		
		iki iþlem de referans olarak alýr ve üzerinde deðiþiklik yapabilmemize olanak saðlar.
	*/
	return 0;
}
