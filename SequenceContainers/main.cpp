#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include<iterator>

using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimiter "\n------------------------------------------------\n"

template<typename T>void vector_info(const std::vector<T>& vec);
template<typename T>void deque_info(const std::deque<T>& vec);

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
//#define STL_LIST
#define STL_FORWARD_LIST


void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	throw;
	const int n = 5;
	std::array<int, n> arr;
	for (int i = 0;i < arr.size();i++)
	{
		arr.at(i) = rand() % 100;
	}
	try
	{
		for (int i = 0; i < arr.size() * 2;i++)
		{
			cout << arr.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	/*catch (...)
	{
		std::cout << "Error: Something went wrong" << endl;
	}*/

	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
	std::string str;

#endif // STL_ARRAY

#ifdef STL_VECTOR
	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	vector_info(vec);
	vec.push_back(55);

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << *it << tab;
	cout << endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		cout << *it << tab;
	cout << endl;
	vector_info(vec);
	//vec.shrink_to_fit();  // ������� capacity �� ������������ �������
	vec.reserve(14);
	//vec.push_back(1024);
	//vec.resize(18);
	for (int i : vec)cout << i << tab; cout << endl;
	vector_info(vec);
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	///////////////////////////////////
	int index;
	int value;
	do
	{
		cout << "������� ������ ������������ ��������: "; cin >> index;
		cout << "������� �������� ������������ ��������: "; cin >> value;
	} while (index > vec.capacity());
	vec.insert(vec.begin() + index, value );
	for (int i : vec)cout << i << tab; cout << endl;
	
	do
	{
		cout << "������� ������ ���������� ��������: "; cin >> index;
	} while (index > vec.capacity());
	vec.erase(vec.begin() + index);
	for (int i : vec)cout << i << tab; cout << endl;
	




#endif // STL_VECTOR

#ifdef STL_DEQUE
	std::deque<int> deque = { 3, 5, 8, 13, 21 };
	deque.push_back(34);
	deque.push_front(2);

	/*std::vector<int>vec;
	cout << typeid(vec.data()).name() << endl;*/
	deque_info(deque);
	deque.assign(vec.begin()+3, vec.end()-3);
	for (int i : deque)cout << i << tab; cout << endl;

#endif // STL_DEQUE


#ifdef STL_LIST

	std::list<int> list = { 3, 5, 8, 13, 21, 34, 55, 89 };
	list.push_front(2);
	list.push_front(1);
	list.push_front(1);
	list.push_front(0);
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		cout << *it << tab;
	cout << endl;
	for (std::list<int>::reverse_iterator it = list.rbegin(); it != list.end(); ++it)
		cout << *it << tab;
	cout << endl;


	int index;
	int value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	//list.insert(list.begin() + index, value); //������ �� ������������ ���������� ����������
	std::list<int>::iterator position = list.begin();
	//for (int i = 0; i < index; i++) position++;
	//std::advance(position, index); // advance ������� �������� ������ �� �������� ����� 
	//list.insert(position, value);

	std::list<int>::reverse_iterator r_position = list.rbegin();
	std::advance(r_position, list.size() - index);
	position = r_position.base();
	list.insert(position, value);

	for (int i : list)cout << i << tab; cout << endl;


	cout << "������� ������ ���������� ��������: "; cin >> index;
	position = list.begin();
	std::advance(position, index);
	list.erase(position);


	for (int i : list)cout << i << tab; cout << endl;

#endif // STL_LIST

#ifdef STL_FORWARD_LIST
	std::forward_list<int> list = { 3, 5, 8, 13, 21 };
	list.push_front(2);
	list.push_front(1);
	list.push_front(1);
	list.push_front(0);
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); ++it)
		cout << *it << tab;
	cout << endl;

	int index;
	int value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	std::forward_list<int>::iterator position = list.before_begin();
	std::advance(position, index);
	list.insert_after(position, value);
	//list.insert_after(list.begin(), 16384);
	for (int i : list)cout << i << tab; cout << endl;

	cout << "������� ������ ���������� ��������: "; cin >> index;
	position = list.before_begin();
	std::advance(position, index);
	list.erase_after(position);
	for (int i : list)cout << i << tab; cout << endl;
	
#endif // STL_FORWARD_LIST


}
template<typename T>void vector_info(const std::vector<T>& vec)
{
	cout << "Size:\t" << vec.size() << endl;
	cout << "MaxSize:\t" << vec.max_size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << delimiter << endl;
}
template<typename T>void deque_info(const std::deque<T>& vec)
{
	cout << "Size:\t" << vec.size() << endl;
	cout << "MaxSize:\t" << vec.max_size() << endl;
	cout << delimiter << endl;

}