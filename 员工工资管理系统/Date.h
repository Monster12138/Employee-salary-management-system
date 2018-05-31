#pragma once
#include<ctime>
using std::cout;
using std::cin;
using std::endl;

class Date {
private:
	int year;
	int month;
	int day;
public:
	void SetDate(int y, int m, int d);
	int GetYear();
	int GetMonth();
	int GetDay();
	int if_brithmonth();
};

void Date::SetDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::GetYear() {
	return year;
}

int Date::GetMonth() {
	return month;
}

int Date::GetDay() {
	return day;
}

int Date::if_brithmonth() {
	time_t t = time(NULL);
	struct tm* local;
	local = localtime(&t);
	if (local->tm_mon + 1== month)return 1;
	else return 0;
}