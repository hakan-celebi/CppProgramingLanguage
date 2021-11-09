#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Copy Consturctor;
	Bu constructor bir class dan türetilen nesnedeki özellikleri diğer bir nesneye taşıyabilmemizi sağlar. Default olarak class
tanımlamasında bir copy constructor vardır fakat class içerisinde pointer bir özellik değişken kullanır isek burada hata verir.
Örneğin;
class test
{
	private:
		int *x;
}
şeklinde bir sınıfımız olsun ve test t1; test t2; şeklinde iki adet sınıfımız olsun. x için ram de yer ayrılmış olsun ve değer
olarak 5 atılmış olsun copy constructor çalıştığı anda yani
t1 = t2; veya t1(t2); yapıldığı anda *(this->x) = *(t2.x) olur ve bu durumda bu nesne için x de yer ayrılmadığı için t2 nin
x pointerını kullanır. Bu durumda eğer constructor içerisinde delete kullanır isek ilk olarak ilk nesnenin sonra ise diğer
nesnenin x pointer ı için ram de ayrılan yer silinir. İlk olarak silindiği için ikinci olarak silinemez ve program hata verir.
	Copy Consturtor Tanımlaması:
test(test & veya test *) şeklinde tanımlanır fakat bunların başlarında const olması gerekir çünkü kopyalama sırasında kopyalanan
nesne üzerinde değişiklik yapılmaması gerekir.
*/

class test2
{
	public:
		int x;
		test2(int);	
};

test2::test2(int x) : x(x){}

class test
{
	private:
		int x;
		int *ptr;
	public:
		test(int, int);
		test(test &);
		test(test2 &);
		~test(){std::cout << "Destructor Çalıştı !\nDeğerler: " << x << ", " << *ptr << std::endl; delete ptr;}
		void SET_VALUE(int, int);
};

test::test(int x = 0, int ptr = 0)
{
	this->ptr = new int(ptr); this->x = x; 
	std::cout << "Constructor Çalıştı !\nDeğerler: " << this->x << ", " << *(this->ptr) << std::endl;
}

test::test(test &t)
{
	this->ptr = new int(*(t.ptr)); this->x = t.x;
	std::cout << "Copy Constructor Çalıştı !\nDeğerler: " << this->x << ", " << *(this->ptr) << std::endl;
}

test::test(test2 &t)
{
	this->x = t.x; this->ptr = new int(-5);
	std::cout << "Test2 Copy Constructor Çalıştı !\nDeğerler: " << this->x << ", " << *(this->ptr) << std::endl;	
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	test t1(35, 48);
	test t2 = t1;
	test2 t3(11);
	test t4(t3);
	return 0;
}

