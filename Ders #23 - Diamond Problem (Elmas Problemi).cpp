#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*
Diamond Problem:
	A isminde bir taban sýnýfýndan miras alan B ve C sýnýflarý var olsun ve B ve C sýnýflarýndan miras alan D sýnýfý var olduðunu düþünelim.
class D : public B, public C
{

};
þeklinde ise D sýnýfýndan bir nesne üretildiði zaman ilk olarak B den kalýtým alýndýðý için B sýnýfý, B sýnýfý da A sýnýfýndan kalýtým
aldýðý için A sýnýfý üretilir özellik ve metodlarý tanýmlanýr daha sonra B, sonra ise C sýnýfýna geçer ve C sýnýfý da A sýnýfýndan miras
aldýðý için A sýnýfý üretilir özellik ve metodlarý tanýmlanýr daha sonra C sýýnýfý tanýmlanýr sonra ise D sýnýfý tanýmlanýr yani ram de
Görüntü Þu Þekildedir.
Variable			Value			Type
 >D					{...}			  D
   >B				{...}			  B
     >A				{...}			  A
   >C				{...}			  C
   	 >A				{...}			  A
   	Yani ram de iki adet A sýnýfý tanýmlanmýþ oldu biri B için diðeri ise C için Bunun önüne geçmemiz gerekiyor bunun için ise virtual
class yani sanal sýnýf kullanmamýz gerekiyor.
*/

class A
{
	protected:
		int val;
		static int derivedval; /*A sýnýfýndan üretilme sayýsýný tutan deðiþken.*/
	public:
		A(int);
		~A()
		{std::cout << "A's Destructor Worked !" << std::endl;}
		void SET_VAL(int);
		int GET_VAL(){return val;}	
};
int A::derivedval = 0;

A::A(int val = 1) : val(val)
{
	this->derivedval++;
	std::cout << "A's Constructor Worked !" << std::endl << "Val's Value: " << this->val << std::endl << "A Class " << this->derivedval 
	<< " More Derived !" << std::endl;
}

void A::SET_VAL(int val)
{this->val = val;}

class B : virtual public A /*Türetilen sýnýf eðer bir kez türetildi ise sanal olarak yani gerçek olarak türetme anlamýna gelir.*/
{
	public:
		B(int);
		~B()
		{std::cout << "B's Destructor Worked !" << std::endl;}	
};

B::B(int val = 1) : A(val)
{std::cout << "B's Constructor Worked !" << std::endl << "Val's Value: " << this->val << std::endl;}

class C : virtual public A
{
	public:
		C(int);
		~C()
		{std::cout << "C's Destructor Worked !" << std::endl;}	
};

C::C(int val = 1) : A(val)
{std::cout << "C's Constructor Worked !" << std::endl << "Val's Value: " << this->val << std::endl;}

/*
	B ve C sýnýflarýnýn ikisi için de virtual yaptýk çünkü D sýnýfý ilk kalýtýmý hangi sýnýf dan alacaðýný bilemeyiz. Ýlk olarak bu
durumda B sýnýfý kalýtým alýnýr ve ordan A sýnýfý üretilir bakýlýr eðer üretilmemiþ ise direkt üretilir sonra ise B sýnýfý üretilir.
C sýnýfýna geçilir ve A sýnýfý üretilir bakýlýr üretilmiþ bu yüzden sanal olarak üretilir.
*/

class D : public B, public C
{
	public:
		D(int);	
		~D()
		{std::cout << "D's Destructor Worked !" << std::endl;}
};

D::D(int val = 1) : D::A(val) /*Burada hangi sýnýf için olduðunu belirmemiz gerekir.  	*/
{std::cout << "D's Constructor Worked !" << std::endl << "Val's Value: " << this->val << std::endl;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	std::cout << "Derived A Class" << std::endl;
	A a(3);
	std::cout << std::endl << "Derived B Class" << std::endl;
	B b(5);
	std::cout << std::endl << "Derived C Class" << std::endl;
	C c(7);
	std::cout << std::endl << "Derived D Class" << std::endl;
	D d(10);
	return 0;
}


















