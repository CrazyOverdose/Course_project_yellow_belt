#include "date.h"


Date::Date(const int& year, const int& month, const int& day) :
	Year(year), Month(month), Day(day) {};

int Date::return_Day() const { return Day; }
int Date::return_Month() const { return Month; }
int Date::return_Year() const { return Year; }

Date ParseDate(std::istream& is) {

	int year, month, day;
	is >> year;
	is.ignore(1);
	is >> month;
	is.ignore(1);
	is >> day;

	return { year, month, day };
}

bool operator < (const Date& a, const Date& b) {
	if (a.return_Year() != b.return_Year())
		return a.return_Year() < b.return_Year();

	if (a.return_Month() != b.return_Month())
		return a.return_Month() < b.return_Month();

	if (a.return_Day() != b.return_Day())
		return a.return_Day() < b.return_Day();
	return false;
}

bool operator > (const Date& a, const Date& b) {
	if (a.return_Year() != b.return_Year())
		return a.return_Year() > b.return_Year();

	if (a.return_Month() != b.return_Month())
		return a.return_Month() > b.return_Month();

	if (a.return_Day() != b.return_Day())
		return a.return_Day() > b.return_Day();
	return false;
}

bool operator == (const Date& a, const Date& b) {
	if (a.return_Year() == b.return_Year() &&
		a.return_Month() == b.return_Month() &&
		a.return_Day() == b.return_Day())
		return true;
	return false;
}
bool operator != (const Date& a, const Date& b) {
	if (a.return_Year() == b.return_Year() &&
		a.return_Month() == b.return_Month() &&
		a.return_Day() == b.return_Day())
		return false;
	return true;
}

bool operator >= (const Date& a, const Date& b) {
	if (a > b || a == b)
		return true;
	return false;
}

bool operator <= (const Date& a, const Date& b) {
	if (a < b || a == b)
		return true;
	return false;
}

std::ostream& operator<< (std::ostream &out, const Date &date)
{
	out << std::setw(4) << std::setfill('0') << date.return_Year() <<
		"-" << std::setw(2) << std::setfill('0') << date.return_Month() <<
		"-" << std::setw(2) << std::setfill('0') << date.return_Day();
	return out;
}