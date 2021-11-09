#ifndef _MYTIME_
#define _MYTIME_
#include <ctime>
std::string GET_NOW_DATE()
{
	time_t time = std::time(NULL);
	struct tm *tmtime = localtime(&time);
	char mDate[50];
	strftime(mDate, sizeof(mDate), "%d-%m-%Y", tmtime);
	return mDate;
}

int GET_NOW_DAY(std::string date)
{
	std::string day = ""; int factor = 1; int daynumber = 0;
	for(int i = 0; date[i] != '-'; i++)
		day += date[i];
	for(int i = day.length() - 1; i >= 0; i--, factor *= 10)
		daynumber += (day[i] - '0') * factor;
	return daynumber;
}

int GET_NOW_MONTH(std::string date)
{
	std::string month = ""; int factor = 1; int monthnumber = 0; int i;
	for(i = 0; date[i] != '-'; i++)
	{}
	for(i += 1; date[i] != '-'; i++)
		month += date[i];
	for(i = month.length() - 1; i >= 0; i--, factor *= 10)
		monthnumber += (month[i] - '0') * factor;
	return monthnumber;
}

int GET_NOW_YEAR(std::string date)
{
	std::string year = ""; int factor = 1; int yearnumber = 0; int i;
	for(i = date.length() - 1; date[i] != '-'; i--)
	{}
	for(i += 1; i < date.length(); i++)
		year += date[i];
	for(i = year.length() - 1; i >= 0; i--, factor *= 10)
		yearnumber += (year[i] - '0') * factor;
	return yearnumber;
}

bool Is_Right_Format(std::string date)
{
	int day = GET_NOW_DAY(date);
	int month = GET_NOW_MONTH(date);
	int year = GET_NOW_YEAR(date);
	if(month <= 12 && month > 0 && day <= 31 && day > 0 && year >= 1900 && year <= GET_NOW_YEAR(GET_NOW_DATE()))
		return true;
	else
		return false;
}
#endif
