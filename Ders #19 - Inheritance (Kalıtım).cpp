#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>

/*Inheritance:
	Kalýtým örneðin bir insan sýnýfý var ve biz bir otomasyon sistemi yapýyoruz bu otomasyon sisteminde bizde müþteri ve personel olmasý
gerekir ve personel içerisinde yüksek yönetici, yönetici, ve iþçi sýnýfý olmasý gerekir bunun gibi sistemler için kalýtým kullanýlýr.
*/

typedef enum s
{
	male = 0,
	famale = 1,
	null = 2	
}sex;

typedef enum r
{
	turk = 0,
	british = 1,
	italy = 2,
	french = 3,
	nulls = 4
}race;

typedef enum e
{
	middleschool = 0,
	highschool = 1,
	university = 2,
	nullss = 3
}education;

class human
{
	protected:
		std::string passportno;
		std::string name;
		int age;
		sex gender;	
		race nationality;
	public:
		human(std::string, std::string, int, sex, race);
		void SET_PASSPORTNO(std::string);
		void SET_NAME(std::string);
		void SET_AGE(int);
		void SET_GENDER(sex);
		void SET_NATIONALITY(race);
		std::string GET_PASSPORTNO(){passportno.empty() ? passportno = "NULL" : passportno ; return passportno;}
		std::string GET_NAME(){name.empty() ? name = "NULL" : name; return name;}
		int GET_AGE(){age == 0 ? age = -987789 : age; return age;}
		std::string GET_GENDER()
		{
			switch(gender)
			{
				case 0:
					return "Erkek";
					break;
				case 1:
					return "Kadýn";
					break;
				default:
					return "NULL";
					break;
			}
		}
		std::string GET_NATIONALITY()
		{
			switch(nationality)
			{
				case 0:
					return "Türk";
					break;
				case 1:
					return "Ýngiliz";
					break;
				case 2:
					return "Ýtalyan";
					break;
				case 3:
					return "Fransýz";
					break;
				default:
					return "NULL";
					break;
			}
		}
};

human::human(std::string passportno = "", std::string name = "", int age = 0, sex gender = null, race nationality = nulls)
{this->passportno = passportno; this->name = name; this->age = age; this->gender = gender; this->nationality = nationality;}

void human::SET_PASSPORTNO(std::string passportno)
{this->passportno = passportno;}

void human::SET_NAME(std::string name)
{this->name = name;}

void human::SET_AGE(int age)
{this->age = age;}

void human::SET_GENDER(sex gender)
{this->gender = gender;}

void human::SET_NATIONALITY(race nationality)
{this->nationality = nationality;}

/*: public anasýnýfismi yaptýðýmýz zaman burdaki public eriþim belirteci sýnýfýn nasýl miras alacaðýna dayanýr yani biz student class
ýndan bir nesne türettiðimiz zaman human özelliklerine nasýl eriþeceðimizi belirtir.*/
class student : public human
{
	private:
		std::string studentnumber;
		education educationstatus;
		short int grade;
	public:
		student(std::string, education, short int, std::string, std::string, int, sex, race);
		void SET_STUDENTNUMBER(std::string);
		void SET_EDUCATIONSTATUS(education);
		void SET_GRADE(short int);
		std::string GET_STUDENTNUMBER(){return studentnumber;}
		std::string GET_EDUCATIONSTATUS()
		{
			switch(educationstatus)
			{
				case 0:
					return "Ortaokul";
					break;
				case 1:
					return "Lise";
					break;
				case 2:
					return "Üniversite";
					break;
			}
		}
		short int GET_GRADE(){return grade;}
};

/*
Constructor Methodunun Kalýtýmda Davranýþý
	Ýlk olarak temel sýnýfýn constructoru çalýþýr ve daha sonra miras alan yani diðer türetilmiþ sýnýflarýn constructoru çalýþýr.
Burada ise student sýnýfý human sýnýfýndan miras alýyor ve human temel student türetilmiþ sýnýftýr yani baþlangýç olarak human sýnýfýnýn
constructoru çalýþacaktýr yani biz eðer türetilmiþ sýnýftan bir nesne türetirsek temel sýnýfýn construcoru na default olarak parametre
verilmez ise þu deðerleri al gibi = deðer yazar isek veya parametresiz bir constructor yazar isek kodumuz sýkýntýsýz çalýþýr fakat
baþlangýç olarak nesne türetilirken parametre veremeyiz. Bunu engellemenin yolu ise student sýnýfýnýn kurucusuna baþlangýç olarak bir
parametreli constructor çaðýrmak olacaktýr yani nesne türetildiði an itibari ile nesneye deðer atabileceðiz. Hatýrlarsak const bir
deðiþken tanýmlarken : þeklinde atama yapýyorduk yani türetilmiþ sýnýfýn nesnesi türetilmeden önce özellikleri ve metodlarý belirtilmeden
önce tanýmlama anýnda direkt olarak const a deðer atarak read-only den önce bir deðer atabilmeyi baþarýyorduk. Bu da bu þekildedir.

Destructor Methodunun Kalýtýmda Davranýþý
	Ýlk olarak türetilmiþ sýnýf sonlanýr daha sonra ise temel sýnýf sonlanýr.
*/
student::student(std::string studentnumber = "", education educationstatus = nullss, short int grade = 1, 
std::string passportno = "", std::string name = "", int age = 0, sex gender = null, race nationality = nulls) : human(passportno, name, 
age, gender, nationality)
{this->studentnumber = studentnumber; this->educationstatus = educationstatus; this->grade = grade;}

void student::SET_STUDENTNUMBER(std::string studentnumber)
{this->studentnumber = studentnumber;}

void student::SET_EDUCATIONSTATUS(education educationstatus)
{this->educationstatus = educationstatus;}

void student::SET_GRADE(short int grade)
{this->grade = grade;}

int main()
{
	setlocale(LC_ALL, "Turkish");
	student m1("181312025", university, 2, "14501321120", "Hakan ÇELEBÝ", 20, male, turk);
	/*m1.SET_AGE(20);
	m1.SET_GENDER(male);
	m1.SET_NAME("Hakan ÇELEBÝ");
	m1.SET_NATIONALITY(turk);
	m1.SET_PASSPORTNO("14501321120");*/
	std::cout << "Ýsim: " << m1.GET_NAME() << "\nYaþ: " << m1.GET_AGE() << "\nCinsiyet: " << m1.GET_GENDER() << "\nMilliyet: "
	<< m1.GET_NATIONALITY() << "\nPasaport Numarasý: " << m1.GET_PASSPORTNO() << "\nEðitim Durumu: " << m1.GET_EDUCATIONSTATUS()
	<< "\nÖðrenci No: " << m1.GET_STUDENTNUMBER() << "\nSýnýf: " << m1.GET_GRADE() << std::endl;
	return 0;
}
