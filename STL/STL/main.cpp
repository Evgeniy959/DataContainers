#include<iostream>
#include<string>
#include<array>
#include<vector>
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

//#define ARRAY
#define VECTOR

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
	std::vector<int> v{};//Function declaration
	//v.
#endif
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