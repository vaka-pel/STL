#include<iostream>
#include<map>
#include<list>
using std ::cin;
using std ::cout;
using std ::endl;

#define tab       "\t"
#define delimiter "\n-------------------------------------------\n"
#define STL_MAP

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_MAP
	std::multimap<int, std::string> week =
	{
		std::pair<int, std::string>(0, "воскресенье"),
		std::pair<int, std::string>(1, "понедельник"),
		std::pair<int, std::string>(2, "вторник"),
		std::pair<int, std::string>(3, "среда"),
		{4, "четверг"},
		{5, "пятница"},
		{5, "пятница"},
		{5, "пятница"},
		{5, "пятница"},
		{5, "пятница"},
		{5, "пятница"},
		{5, "пятница"},
		{5, "пятница"},
		{5, "пятница"},
		{5, "пятница"},
		{5, "пятница"},
		{5, "пятница"},
		{5, "пятница"},
		{6, "суббота"},
		{7, "воскресенье"},
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end();++it)
	{
		cout << it->first << tab << it->second << endl;
	}
	cout << delimiter << endl;
	for (std::pair<int, std::string> i : week)
	{
		cout << i.first << tab << i.second << endl;
	}
	cout << delimiter << endl;

	std::map<std::string, std::list<std::string>> dictionary =
	{
		{"occasionaly",{"иногда","время от времени", "случайно", "изредка"}},
		{"causes",{"причина","приводить к..."}},
		{"space",{"космос","пространство", "пробел"}},
		{"void",{"пустота","вакуум"}},
		{"sequense",{"последовательность","ряд", "эпизод", "череда"}},
		{"consequense",{"следствие", "последствие", "вывод"}},
	}
#endif // STL_MAP

}