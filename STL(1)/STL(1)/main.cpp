#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<list>
#include<map>
#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//STL - Standard Template Library (Стандартная шаблонная библиотека).
//Container - это объект, который организует хранение других объектов в памяти.
//Iterator  - 
//Algorithms

/*
-------------------------------------------------------------------------
Sequence containers:   array, vector, deque, list, forward_list;
Associative containers:map, multimap, set, multiset;
Container adaptors:	   stack, queue, priority_queue;
-------------------------------------------------------------------------
*/

template<typename T>void vector_properties(const std::vector<T>& vec);	//Прототип
template<typename T>void vector_print(const std::vector<T>& vec);
template<typename T>void vector_reverse_print(const std::vector<T>& vec);

template<typename T>void list_properties(const std::list<T>& list);
template<typename T>void list_print(const std::list<T>& list);
template<typename T>void list_reverse_print(const std::list<T>& list);

//#define ARRAY
//#define VECTOR
//#define LIST
#define MAP

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef ARRAY
	//array - это линейный контейнер, который хранит объекты в виде статического массива.
	const int n = 5;
	std::array<int, n> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif

#ifdef VECTOR
	//vector - это линейный контейнер, который хранит данные в виде динамического массива.
	/*std::vector<int> vec = { 0,1,1,2,3,5,8,13,21, 34 };
	vector_properties(vec);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	vec.push_back(55);
	vector_properties(vec);
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cout << endl;
		std::cerr << "Error:" << e.what() << endl;
	}*/

	std::vector<std::string> s_vec = { "Хорошо", "живет", "на", "свете", "Винни", "Пух" };
	vector_print(s_vec);
	vector_reverse_print(s_vec);
	s_vec.size();


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int index;
	std::string value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	std::vector<std::string>::iterator position = s_vec.begin() + index;
	s_vec.insert(s_vec.begin() + index, 3, value);
	vector_print(s_vec);
	s_vec.insert(s_vec.begin() + 4, { "Ты", "заходи", "если", "что" });
	vector_print(s_vec);
	vector_properties(s_vec);
	s_vec.assign(3, "Ёшкин 20");
	s_vec.shrink_to_fit();
	vector_print(s_vec);
	vector_properties(s_vec);
	//v.
#endif

#ifdef LIST
	//List - это контейнер, который хранит данные в виде двусвязного списка.
	std::list<int> my_list = { 3,5,8,13,21 };
	list_properties(my_list);
	my_list.push_front(2);
	my_list.push_back(34);
	list_print(my_list);
	list_reverse_print(my_list);
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	std::list<int>::iterator position = my_list.begin();
	for (int i = 0; i < index; i++)++position;
	my_list.insert(position, value);
	list_print(my_list);
#endif // LIST

#ifdef MAP
	//map - это контейнер, который хранит элементы в виде бинарного дерева.
	//Кадый элемент map содержит ПАРУ "ключ - значение" (key - value).
	std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(1, "Monday"),
		std::pair<int, std::string>(2, "Tuesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(4, "Thursday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(6, "Saturday")
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
	{
		cout << it->first << tab << it->second << endl;
	}
#endif // MAP

}

template<typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:    " << vec.size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;	//Емкость, вместительность
	cout << "Max size:" << vec.max_size() << endl;
}
template<typename T>void vector_print(const std::vector<T>& vec)
{
	for (typename std::vector<T>::const_iterator it = vec.cbegin(); it != vec.cend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}
template<typename T>void vector_reverse_print(const std::vector<T>& vec)
{
	for (typename std::vector<T>::const_reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
	{
		cout << *rit << tab;
	}
	cout << endl;
}

template<typename T>void list_properties(const std::list<T>& list)
{
	cout << "Size:    " << list.size() << endl;;
	cout << "MaxSize: " << list.max_size() << endl;;
}
template<typename T>void list_print(const std::list<T>& list)
{
	for (typename std::list<T>::const_iterator it = list.begin(); it != list.end(); it++)
		cout << *it << tab;
	cout << endl;
}
template<typename T>void list_reverse_print(const std::list<T>& list)
{
	for (typename std::list<T>::const_reverse_iterator it = list.crbegin(); it != list.crend(); it++)
		cout << *it << tab;
	cout << endl;
}