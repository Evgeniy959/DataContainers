#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

class Element
{
	int Data;		//Значение элемента
	Element* pNext;	//Указатель на следующий элемент
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) 
	{
		count++;
		this->Data = Data;
		this->pNext = pNext;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	
	friend class ForwardList;
};
int Element::count = 0;	//Инициализация статической переменной
   
class ForwardList
{
	Element* Head;
	
public:
	ForwardList()
	{
		
		Head = nullptr; // Если голова указывает на 0, то список пуст
		
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		
		cout << "LDestructor:\t" << this << endl;
	}
	//			Adding elements:
	void push_front(int Data)
	{
		//1. Создаем новый элемент
		Element* New = new Element(Data);
		//2. Привязываем новый элемент к списку
		New->pNext = Head;
		//3
		Head = New;

	}
	void push_back(int Data)
	{
		if (Head == nullptr)	//ЕСЛИ список пуст
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
			Temp = Temp->pNext;
		Temp->pNext = New; //new Element(Data);
		
	}
	//					Erasing elements:
	void pop_front()
	{
		//1)  запоминаем адрес уаляемого элемента.
		Element* to_del = Head;
		//2) Исключаем удаляемый элемент из списка:
		Head = Head->pNext;
		//3) Удаляем элемент из памяти:
		delete to_del;
		
	}
	void pop_back()
	{
		Element* to_del = Head;
		while (to_del->pNext->pNext != nullptr)
			to_del = to_del->pNext;
		delete to_del->pNext;
		to_del->pNext = nullptr;	
	}
	void insert(int Data, int index)
	{
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		//Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++, Temp = Temp->pNext)
			if (Temp->pNext == nullptr)break;
		//Temp = Temp->pNext;
		/*New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element(Data, Temp->pNext);
	}

	//			Methods:
	void print()
	{
		Element* Temp = Head;	//Temp - это итератор.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
		cout << "Общее количество элементов:  " << Element::count << endl;
	}
};
//#define BASE_CHECK
void main()
{
	setlocale(LC_ALL, "");
	int n; //размер списка
	int value;
	int index;
	cout << "Введите размер списка: "; cin >> n;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
			//list.push_front(rand() % 100);
			list.push_back(rand() % 100);
	}
	list.print();
	list.push_back(123);
	list.print();
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();
	list.insert(value, index);
	list.print();
}