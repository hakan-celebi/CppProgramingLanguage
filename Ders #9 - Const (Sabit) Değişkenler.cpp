#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Const deðiþken;
	Program içerisinde pi sayýsý gibi nesneye özel bir deðer vermemiz gerekebilir bu iþlemler için const kullanýlýr.
*/

class test
{
	private:
		int *x;
	public:
		const int y; /*const sadece okunabilir olduðu için private yapmaya gerek yok.*/
		test(int, int);	
		~test()
		{delete x; std::cout << "Yýkýcý çalýþtý.\n\tx = " << *x << " ve sabit y = " << y << std::endl;}
};

test::test(int x = 0, int y = 0): y(y)
{
	/*x ve y için deðerleri buradan yapamayýz çünkü tanýmlama yapýldýðý anda deðerini deðiþtiremeyiz yani
	const int y kýsmýna  gelerek tanýmlama yapýlmadan önce biz deðer atmamýz gerekiyor bunu ise kurucu fonksiyonun yanýna :
	karakteri ile yazarak fonksiyonmuþ gibi deðer atayabiliri.*/
	this->x = new int(x);
	std::cout << "Kurucu çalýþtý.\n\tx = " << *(this->x) << " ve sabit y = " << this->y << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	test *t1 = new test();
	
	delete t1;
	return 0;
}

