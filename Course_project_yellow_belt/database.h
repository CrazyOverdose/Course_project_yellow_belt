#pragma once
#include "date.h"

#include <set>
#include <map>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

std::ostream& operator<< (std::ostream &out, const std::pair <Date, std::string> res);

class Database {
public:
	void Add(const Date& date, const std::string& event);
	std::ostream& Print(std::ostream &out) const;

	std::pair <Date, std::string> Last(const Date& date) const;

	template <class Func>
	int RemoveIf(Func func) {

		int result = 0;

		for (auto i = database.begin(); i != database.end();) {

			Date b = i->first;

			auto it = std::stable_partition(order[i->first].begin(), order[i->first].end(), [b, func](std::string a) {
				if (func(b, a))
					return false;
				return true;
			});

			if (it == order[i->first].begin()) {
				result += database[i->first].size();
				order.erase(i->first);
				i = database.erase(i);
			}

			else {

				std::set <std::string> res(order[i->first].begin(), it);

				order[i->first].erase(it, order[i->first].end());
				result += database[i->first].size() - order[i->first].size();
				database[i->first] = res;

				++i;
			}
		}
		return result;
	}

	template <class Func>
	std::vector <std::pair <Date, std::string>> FindIf(Func func) const {

		std::vector <std::pair <Date, std::string>> result;

		if (order.empty())
			return result;

		auto it = order.at(order.begin()->first).begin();
		for (auto i = order.begin(); i != order.end();) {

			Date b = i->first;
			auto it1 = std::find_if(it, i->second.end(), [b, func](std::string a) {
				if (func(b, a))
					return true;
				return false;
			});

			if (it1 == i->second.end()) {
				++i;
				if (i != order.end())
					it = order.at(i->first).begin();
			}

			else {
				result.push_back({ b, *it1 });
				it = next(it1, 1);
			}
		}
		return result;
	}

private:
	std::map <Date, std::set <std::string>> database;
	std::map<Date, std::vector<std::string>> order;
};