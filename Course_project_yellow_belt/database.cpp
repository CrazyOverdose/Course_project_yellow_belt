#include "database.h"

std::string ParseEvent(std::istream& is) {
	std::string event;

	getline(is, event);

	event = event.substr(event.find_first_not_of(" "));

	return event;
}

void Database::Add(const Date& date, const std::string& event) {

	if (database[date].count(event) == 0)
		order[date].push_back(event);

	database[date].insert(event);
}

std::ostream& Database::Print(std::ostream &out) const {
	for (auto i = database.begin(); i != database.end(); ++i) {
		for (auto j = order.at(i->first).begin(); j != order.at(i->first).end(); ++j) {
			out << i->first << " " << *j << std::endl;
		}
	}

	return out;
}
std::pair <Date, std::string> Database::Last(const Date& date) const {

	auto it = order.upper_bound(date);

	if (it == order.begin())
		return { {000,00,0}, "" };

	it = prev(it, 1);

	return std::make_pair(it->first, it->second.back());
}

std::ostream& operator<< (std::ostream &out, const std::pair <Date, std::string> res)
{
	if (res.second.empty())
		out << "No entries";
	else
		out << res.first << " " << res.second;
	return out;
}