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
	friend class ForwardList;
};
int Element::count = 0;

class ForwardList
{
	Element* Head;	//Адрес начального элемента
public:
	ForwardList()
	{
		Head = nullptr;	//Если Голова указывает на 0, то список пуст
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const ForwardList& other)
	{
		Head = nullptr;
		Element* Temp = other.Head;	//Итератор Temp будет проходить по списку other
		while (Temp)
		{
			push_back(Temp->Data);//Каждый элемент списка other добавляем в конец нашего списка
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}
	//				Adding elements:
	void push_front(int Data)
	{
		//1) Создаем новый элемент:
		Element* New = new Element(Data);
		//2) Привязываем новый элемент к списку:
		New->pNext = Head;
		//3) Говорим, что новый элемент будет начальным элементос списка:
		Head = New;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)	//Если список пуст, вызываем push_front
		{
			push_front(Data);
			return;
		}
		//1) Создаем новый элемент:
		Element* New = new Element(Data);
		//2) Доходим до конца списка:
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
			Temp = Temp->pNext;
		//3) Прикрепляем новый элемент к последнему:
		Temp->pNext = New;
	}

	void insert(int Index, int Data)
	{
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		if (Index > Element::count)return;
		//1) Создаем новый элемент:
		Element* New = new Element(Data);
		//2) Доходим до нужного элемента:
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		//3) Вставляем новый элемент на нужную позицию:
		New->pNext = Temp->pNext;
		Temp->pNext = New;
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
	}

	//					Methods:
	void print()
	{
		Element* Temp = Head;	//Temp - это итератор.
								//Итератор - это указатель, при помощи которого
								//можно получить доступ к элементам структуры данных.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
		cout << "Количество элементов списка: " << Element::count << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;	//Размер списка
	cout << "Введите количество элементов списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	/*list.push_back(123);
	list.print();
	list.pop_front();
	list.print();
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();*/

	ForwardList list2 = list;
	list2.print();
}