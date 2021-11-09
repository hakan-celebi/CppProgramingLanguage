#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*
	Taban sınıfta parametreli bir constructorumuz var ise ve türemiş sınıftan bir nesne alır isek default bir değer atılmamış veya parametre
olmayan constructor yok ise kod derlenmez. Bunun için ve eğer taban sınıfın constructorunu önce çağırmak istersek aşağıda.
*/

/*BASE CLASS*/
class base
{
	protected:
		int *bdata;
	public:
		base(int);
		base(const base &);
		~base(){delete bdata; std::cout << "Base destructor worked !" << std::endl << std::endl;}
		void SET_BDATA(int);
		int GET_BDATA(){return *bdata;}
};

base::base(int bdata = 0)
{this->bdata = new int(bdata); std::cout << "Base constructor worked !" << std::endl << "Data: " << *(this->bdata) << std::endl
<< std::endl;}

base::base(const base &b)
{this->bdata = new int(*(b.bdata)); std::cout << "Base copy constructor worked !" << std::endl << "Data: " << *(this->bdata) << std::endl
<< std::endl;}

void base::SET_BDATA(int bdata)
{*(this->bdata) = bdata;}

/*DERIVED_A CLASS*/
class derived_a : public base
{
	private:
		int *deriveddata;
	public:
		derived_a(int, int);
		~derived_a(){delete deriveddata; std::cout << "Derived_a destructor worked !" << std::endl << std::endl;}
		void SET_DERIVEDDATA(int);
		int GET_DERIVEDDATA(){return *deriveddata;}
};

derived_a::derived_a(int deriveddata = 0, int bdata = 0)
{
	/*Eğer constructorun müdahil olduğu değişken protected veya public ise buradaki taktik işe yarayabilir.*/
	this->bdata = new int(bdata); this->deriveddata = new int(deriveddata); 
	std::cout << "Derived_a constructor worked !" << std::endl << "Base Data: " 
	<< *(this->bdata) << std::endl << "Derived Data: " << *(this->deriveddata) << std::endl << std::endl;
}

void derived_a::SET_DERIVEDDATA(int deriveddata)
{(*this->deriveddata) = deriveddata;}

/*DERIVED_B CLASS*/
class derived_b : public base
{
	private:
		int *deriveddata;
	public:
		derived_b(int, int);
		~derived_b(){delete deriveddata; std::cout << "Derived_b destructor worked !" << std::endl << std::endl;}
		void SET_DERIVEDDATA(int);
		int GET_DERIVEDDATA(){return *deriveddata;}
};

/*Bu şekilde yapar isek base class constructor çalışmadan önce bdata parametresini almış olur.*/
derived_b::derived_b(int deriveddata = 0, int bdata = 0) : base(bdata)
{
	this->deriveddata = new int(deriveddata); std::cout << "Derived_b constructor worked !" << std::endl << "Base Data: " 
	<< *(this->bdata) << std::endl << "Derived Data: " << *(this->deriveddata) << std::endl << std::endl;
}

void derived_b::SET_DERIVEDDATA(int deriveddata)
{*(this->deriveddata) = deriveddata;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	std::cout << "Base Object !" << std::endl;
	base b1(5);
	std::cout << "Derived_a Object !" << std::endl;
	derived_a da1(3, 2);
	std::cout << "Derived_b Object !" << std::endl;
	derived_b da2(5, 8);
	std::cout << "Copy Derived_b Object !" << std::endl;
	derived_b da3 = da2;
	std::cout << "Copied Value !" << std::endl << "Base Data: " << da3.GET_BDATA() << std::endl 
	<< "Derived Data: " << da3.GET_DERIVEDDATA() << std::endl << std::endl;
	return 0;
}
