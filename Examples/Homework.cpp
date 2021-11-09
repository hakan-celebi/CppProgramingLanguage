#include <iostream>
#include <string>
#include <locale>

class personel
{
	public:
		double maas;
		std::string ad;
		std::string soyad;
		std::string tc;
		personel()
		{maas = 2558.4;}	
};

class konut
{
	double birim;
	double birimfiyat;
	double satisfiyat;
	std::string adres;
	public:
		double set_satisfiyat()
		{satisfiyat = birim * birimfiyat; return satisfiyat;}
		void set_birim(double b)
		{birim = b;}
		void set_birimfiyat(double bf)
		{birimfiyat = bf;}
		void set_adres(std::string ad)
		{adres = ad;}
		double get_birim()
		{return birim;}
		double get_birimfiyat()
		{return birimfiyat;}
		std::string get_adres()
		{return adres;}	
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	personel *p1 = new personel;
	personel *p2 = new personel;
	konut *ev1 = new konut;
	konut *ev2 = new konut;
	p1->ad = "Ali"; p1->soyad = "AK"; p1->tc = "1111121211";
	std::cout << "İsim: " << p1->ad << "\nSoyisim: " << p1->soyad << "\n" << "TC: " << p1->tc << "\n" <<
	"Maaş: " << p1->maas << " TL\n" << std::endl;
	p2->ad = "Mehmet Ali"; p2->soyad = "CERAN"; p2->tc = "5152535546"; p2->maas = 5000;
	std::cout << "İsim: " << p2->ad << "\nSoyisim: " << p2->soyad << "\n" << "TC: " << p2->tc << "\n" <<
	"Maaş: " << p2->maas << " TL" << std::endl;
	delete p1; delete p2;
	ev1->set_adres("Elmahatun mah. 11.Blok 2.Kat");
	ev1->set_birim(145);
	ev1->set_birimfiyat(1000);
	std::cout << std::endl;
	std::cout << "Bu Konutun Adresi: " << ev1->get_adres() << "\nBu Konutun Büyüklüğü: " << ev1->get_birim()
	<< " Metrekare\nBu Konutun Metrekare Başı Fiyatı: " << ev1->get_birimfiyat() << " TL\nBu Konutun Değeri: " 
	<< ev1->set_satisfiyat() << " TL\n" << std::endl;
	std::string inpadres;
	double inpbirim; double inpbirimfiyat;
	std::cout << "Kaç Metrekare: "; std::cin >> inpbirim;
	std::cout << "Birim Fiyatı: "; std::cin >> inpbirimfiyat;
	std::cout << "Adres: "; std::cin.get(); getline(std::cin, inpadres);
	ev2->set_adres(inpadres);
	ev2->set_birim(inpbirim);
	ev2->set_birimfiyat(inpbirimfiyat);
	std::cout << std::endl;
	std::cout << "Bu Konutun Adresi: " << ev2->get_adres() << "\nBu Konutun Büyüklüğü: " << ev2->get_birim()
	<< " Metrekare\nBu Konutun Metrekare Başı Fiyatı: " << ev2->get_birimfiyat() << " TL\nBu Konutun Değeri: " 
	<< ev2->set_satisfiyat() << " TL";
	return 0;
}
