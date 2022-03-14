#include <iostream>
#include <string>
#include <map>
#include <utility>

std::string DateFormatter(std::string A) 
{
	std::map<std::string, std::string> days;
	days.insert(std::make_pair("1st", "01"));
	days.insert(std::make_pair("2nd", "02"));
	days.insert(std::make_pair("3rd", "03"));
	days.insert(std::make_pair("4th", "04"));
	days.insert(std::make_pair("5th", "05"));
	days.insert(std::make_pair("6th", "06"));
	days.insert(std::make_pair("7th", "07"));
	days.insert(std::make_pair("8th", "08"));
	days.insert(std::make_pair("9th", "09"));
	days.insert(std::make_pair("10th", "10"));
	days.insert(std::make_pair("11th", "11"));
	days.insert(std::make_pair("12th", "12"));
	days.insert(std::make_pair("13th", "13"));
	days.insert(std::make_pair("14th", "14"));
	days.insert(std::make_pair("15th", "15"));
	days.insert(std::make_pair("16th", "16"));
	days.insert(std::make_pair("17th", "17"));
	days.insert(std::make_pair("18th", "18"));
	days.insert(std::make_pair("19th", "19"));
	days.insert(std::make_pair("20th", "20"));
	days.insert(std::make_pair("21th", "21"));
	days.insert(std::make_pair("22th", "22"));
	days.insert(std::make_pair("23th", "23"));
	days.insert(std::make_pair("24th", "24"));
	days.insert(std::make_pair("25th", "25"));
	days.insert(std::make_pair("26th", "26"));
	days.insert(std::make_pair("27th", "27"));
	days.insert(std::make_pair("28th", "28"));
	days.insert(std::make_pair("29th", "29"));
	days.insert(std::make_pair("30th", "30"));
	days.insert(std::make_pair("31th", "31"));

	std::map<std::string, std::string> months;
	months.insert(std::make_pair("Jan", "01"));
	months.insert(std::make_pair("Feb", "02"));
	months.insert(std::make_pair("Mar", "03"));
	months.insert(std::make_pair("Apr", "04"));
	months.insert(std::make_pair("May", "05"));
	months.insert(std::make_pair("Jun", "06"));
	months.insert(std::make_pair("Jul", "07"));
	months.insert(std::make_pair("Aug", "08"));
	months.insert(std::make_pair("Sep", "09"));
	months.insert(std::make_pair("Oct", "10"));
	months.insert(std::make_pair("Nov", "11"));
	months.insert(std::make_pair("Dec", "12"));

	std::string output = A.substr(A.length()-4, 4) + '-';
	int spaceAt = A.find(" ");
	output += months[A.substr(spaceAt+1, 3)] + '-';
	output += days[A.substr(0, spaceAt)];

	return output;
}

int main() 
{
	std::cout << DateFormatter("25th Apr 2217");
	return 0;
}