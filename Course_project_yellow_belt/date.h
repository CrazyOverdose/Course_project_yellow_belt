#pragma once

#include <string>
#include <cstdlib>
#include <sstream>
#include <utility>
#include <iomanip>
#include <memory>

class Date {
public:
	Date(const int& year, const int& month, const int& day);

	int return_Day() const;
	int return_Month() const;
	int return_Year() const;

private:
	const int Year;
	const int Month;
	const int Day;
};

Date ParseDate(std::istream& is);

std::ostream& operator<< (std::ostream &out, const Date &date);

bool operator < (const Date& a, const Date& b);
bool operator > (const Date& a, const Date& b);
bool operator == (const Date& a, const Date& b);
bool operator != (const Date& a, const Date& b);
bool operator >= (const Date& a, const Date& b);
bool operator <= (const Date& a, const Date& b);