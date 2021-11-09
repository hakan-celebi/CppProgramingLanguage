#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include "test.h" /*kendi kütüphanemizi include ediyoruz.*/

/*Class Libary:
	Biz bu not kýsmýnda sürekli olarak bir test sýnýfýný tekrar tekrar tanýmlýyoruz bunun yerine bir libary oluþturarak ordan
eriþim saðamayý gösterelim.
	Öncelikle bir libary kullanýrken eðer sadece tanýmlama var ise direkt olarak .h uzantýlý bir kütüphane oluþturulur eðer 
bunun içerisinde fonksiyonlar da var ise fonksiyonlarý da bir cpp dosyasýna kaydetmemiz gerekir.


class test
{
	private:
		int x;
		int y;
		int *ptr;
		const int cs;
	public:
		test(int, int, int, int);
		test(test &);
		~test()
		{
			std::cout << "Destructor çalýþtý !\nDeðerler: " << x << ", " << y << ", " << *ptr << ", " << cs << std::endl;
			delete ptr;
		}
		void SET_VALUE(int, int, int);
		int GET_X(){return x;}
		int GET_Y(){return y;}
		int GET_PTR(){return *ptr;}
		int GET_CS(){return cs;}	
};

test::test(int x = 0, int y = 0, int ptr = 0, int cs = 0) : x(x), y(y), cs(cs)
{
	this->ptr = new int(ptr);
	std::cout << "Constructor çalýþtý !\nDeðerler: " << this->x << ", " << this->y << ", " << *(this->ptr) << ", " << this->cs
	<< std::endl;
}

test::test(test &t) : x(t.x), y(t.y), cs(t.cs)
{
	this->ptr = new int((*(t.ptr)));
	std::cout << "Copy Constructor çalýþtý !\nDeðerler: " << this->x << ", " << this->y << ", " << *(this->ptr) << ", "
	<< this->cs << std::endl;
}

void test::SET_VALUE(int x, int y, int ptr)
{this->x = x; this->y = y; *(this->ptr) = ptr;}
*/

int main()
{
	setlocale(LC_ALL, "Turkish");
	test t1(25, 23, 45, 58);
	std::cout << "t1 için\nx: " << t1.GET_X() << "\ny: " << t1.GET_Y() << "\nptr: " << t1.GET_PTR() << "\ncs: " << t1.GET_CS()
	<< std::endl;
	test t2(t1);
	std::cout << "t2 için\nx: " << t2.GET_X() << "\ny: " << t2.GET_Y() << "\nptr: " << t2.GET_PTR() << "\ncs: " << t2.GET_CS()
	<< std::endl;
	test t3;
	t3.SET_VALUE(5, 8, 45);
	std::cout << "t3 için\nx: " << t3.GET_X() << "\ny: " << t3.GET_Y() << "\nptr: " << t3.GET_PTR() << "\ncs: " << t3.GET_CS()
	<< std::endl;
	test t4(1, 2, 3);
	std::cout << "t4 için\nx: " << t4.GET_X() << "\ny: " << t4.GET_Y() << "\nptr: " << t4.GET_PTR() << "\ncs: " << t4.GET_CS()
	<< std::endl;
	return 0;
}
