﻿/*В класс ForwardList добавить методы :
1. void erase(int index);		//Удаляет значение по заданному индексу
2. Написать деструктор таким образом, чтобы он очищал список
(удалял из него све элементы) перед удалением;				DONE
3. Оптимировать методы добавления элементов и проходы по списку;
4. CopyMethods		DONE
5. MoveMethods
6. Перегрузить оператор + таким образом, чтобы он выполнял конкатенацию списков;  TODO
7. (Hardcore - чик)Обеспечить создание списка следующим образом :
ForwardList list = { 3, 5, 8, 13, 21 };
8. (Hardcore)Обеспечить вывод списка на экран следующим образом :  TODO
for (int i : list)
cout << i << tab;
cout << endl;*/

#include<iostream>
using namespace std;

#define tab "\t"

class Element
{
	int Data;
	Element* pNext;
	static int count;
public:
	Element(int Data, Element* pNext = nullptr)
	{
		count++;
		this->Data = Data;	//Значение элемента
		this->pNext = pNext;//Указатель на следующий элемент
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class Iterator;
	friend class ForwardList;

};
int Element::count = 0; //Инициализация статической переменной 

class ForwardList
{
	Element* Head;	//Адрес начального элемента
	unsigned int size;	//Содержит размер списка
public:
	
	ForwardList()
	{
		Head = nullptr;	//Если Голова указывает на 0, то список пуст
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(initializer_list<int> initl) :ForwardList()//Делегирование конструктора по умолчанию
	{
		cout << typeid(initl.begin()).name() << endl;
		for (int const* it = initl.begin(); it != initl.end(); it++)
		{
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other)
	{
		Head = nullptr;
		size = 0;
		Element* Temp = other.Head;	//Итератор Temp будет проходить по списку other
		while (Temp)
		{
			push_back(Temp->Data);//Каждый элемент списка other добавляем в конец нашего списка
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	ForwardList(ForwardList&& other)noexcept
	{
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//				Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		Element* Temp = other.Head;	//Создаем итератор, который будет проходить по списку other
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	ForwardList& operator=(ForwardList&& other)noexcept
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}

	//				Adding elements:
	void push_front(int Data)
	{
		////1) Создаем новый элемент:
		//Element* New = new Element(Data);
		////2) Привязываем новый элемент к списку:
		//New->pNext = Head;
		////3) Говорим, что новый элемент будет начальным элементос списка:
		//Head = New;
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)	//Если список пуст, вызываем push_front
		{
			push_front(Data);
			return;
		}
		//1) Создаем новый элемент:
		//Element* New = new Element(Data);
		//2) Доходим до конца списка:
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
			Temp = Temp->pNext;
		//3) Прикрепляем новый элемент к последнему:
		//Temp->pNext = New;
		Temp->pNext = new Element(Data);
		size++;
	}

	void insert(int Index, int Data)
	{
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		if (Index > size)return;
		//1) Создаем новый элемент:
		//Element* New = new Element(Data);
		//2) Доходим до нужного элемента:
		Element* Temp = Head;
		/*for (int i = 0; i < Index - 1; i++)
		{
			Temp = Temp->pNext;
		}*/
		for (int i = 0; i < Index - 1; i++, Temp = Temp->pNext)
			if (Temp->pNext == nullptr)break;
		//3) Вставляем новый элемент на нужную позицию:
		/*New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element(Data, Temp->pNext);
		size++;
	}

	//				Erasing elements:
	void pop_front()
	{
		//1) Запоминаем адрес удаляемого элемента: 
		Element* to_del = Head;
		//2) Исключаем удаляемый элемент из списка:
		Head = Head->pNext;
		//3) Удаляем элемент из памяти:
		delete to_del;
		size--;
	}
	void pop_back()
	{
		//1) Доходим до предпоследнего элемента:
		Element* Temp = Head;
		while (Temp->pNext->pNext)
			Temp = Temp->pNext;
		//2) Удаляем последний элемент из памяти:
		delete Temp->pNext;
		//3) Зануляем указатель на последний элемент:
		Temp->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index > size)return;
		if (index == 0)
		{
			pop_front();
			return;
		}
		//1)Доходим до нужного элемента:
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
			Temp = Temp->pNext;
		//2)Запоминаем адрес удаляемого элемента:
		Element* to_del = Temp->pNext;
		//3)Исключаем удаляемый элемент из списка:
		Temp->pNext = Temp->pNext->pNext;
		//4)Удаляем элемент из памяти:
		delete to_del;
		size--;
	}

	//					Methods:
	void print()
	{
		//Element* Temp = Head;	//Temp - это итератор.
		//						//Итератор - это указатель, при помощи которого
		//						//можно получить доступ к элементам структуры данных.
		//while (Temp)
		//{
		//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		//	Temp = Temp->pNext;	//Переход на следующий элемент
		//}
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Количество элементов списка: " << size << endl;
		cout << "Общее количество элементов:  " << Element::count << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*int n;	//Размер списка
	cout << "Введите количество элементов списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}*/
	/*list = list;
	list.print();
	list.push_back(123);
	list.print();
	list.pop_front();
	list.print();
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	list.print();
	/*ForwardList list2 = list;	//CopyConstructor
	list2.print();
	ForwardList list3;
	list3 = list2;		//CopyAssignment
	list3.print();*/
	/*ForwardList list2;
	for (int i = 0; i < n; i++)
	{
		list2.push_back(rand() % 100);
	}
	list2.print();*/


	/*list3 = list2 + list;		//MoveAssignment
	list3.print();*/

	ForwardList list = { 3,5,8,13,21 };
	list.print();
}