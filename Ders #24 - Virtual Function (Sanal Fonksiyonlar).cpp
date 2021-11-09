#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

class base
{
	public:
		void print()
		{std::cout << "Base Class Is Printed !" << std::endl;}
		void show()
		{std::cout << "Base Class Is Shown !" << std::endl;}	
};

class derived : public base
{
	public:
		void print()
		{std::cout << "Derived Class Is Printed !" << std::endl;}
		void show()
		{std::cout << "Derived Class Is Shown !" << std::endl;}	
};

class vbase
{
	public:
		vbase()
		{print();}
		void virtual print()
		{std::cout << "VBase Class Is Printed !" << std::endl;}
		void show()
		{std::cout << "VBase Class Is Shown !" << std::endl;}	
};

class vderived : public vbase
{
	public:
		void print()
		{std::cout << "VDerived Class Is Printed !" << std::endl;}
		void show()
		{std::cout << "VDerived Class Is Shown !" << std::endl;}	
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	/*Not:
		Ýki adet farklý türetilmiþ sýnýfý ayný anda bir dizi içerisinde tutmamýz gerekebilir bunu gelecek derste göreceðiz. 
	*/
	derived d;
	base *bptr = &d;
	/*
		bptr pointerý bir base sýnýfý tutabilecek kadar yer ayrýlmýþ ve adres tutan deðiþkendir ve d nesnesi ise bir base sýnýfý ve bir
	derived sýnýfý tutabilecek boyuttadýr ram de ki þekli ise 
	->bptr[CLASS BASE]
			   [CLASS BASE]
	->Object d 
			   [CLASS DERIVED]
		Bir deðiþkenin adresi eðer dizi ise bile baþlangýç adresini gösterir bu yüzden biz yukardaki bptr = &d; yaptýðýmýz zaman bptr
	pointerý d nesnesinin base sýnýfýný tutar.	
	*/
	bptr->print();
	bptr->show(); 
	std::cout << std::endl;
	vderived vd;
	vbase *vbptr = &vd;
	vbptr->print();
	vbptr->show();
	return 0;
}












