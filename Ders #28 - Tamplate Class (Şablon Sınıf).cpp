#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Biz bir sayýyý +1 arttýran bir fonksiyon yazdýðýmýzý farz edelim ve hem double hem int için özel olarak bunu
yazmamýz gerekir bunun yerine derleyici otomatik algýlasýn diye tamplate vardýr.*/

template <typename T>
T Increase(T &val)
{
	val++;
}
/*Bunu class için yapalým.*/

template <class T>
class test
{
	private:
		T data;
	public:
		test(T inpdata) : data(inpdata)
		{}
		void SET_DATA(T inpdata)
		{data = inpdata;}
		T GET_DATA()
		{return data;}	
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	int val = 5;
	std::cout << val << std::endl;
	Increase(val);
	std::cout << val << std::endl;
	test<int> t(25);
	std::cout << t.GET_DATA() << std::endl;
	test<std::string> tt("Hakan");
	std::cout << tt.GET_DATA() << std::endl;
	return 0;
}
