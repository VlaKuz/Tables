#ifndef __TABLE_STRUCT
#define __TABLE_STRUCT

#include "Polinom.h"
#include <string>
#include <list>
#include <vector>
using namespace std;

class TabNode
{
private:

	string Name;
	Polinom* Data;

public:

	TabNode();
	TabNode(const TabNode & );
	TabNode(string , Polinom* );
	string GetKey() const;
	Polinom* GetElement() const;
	TabNode& operator=(const TabNode &);
	bool operator==(const TabNode &);

};

/*-------------------------------------------------------------------------------------------------------------*/
class Table //виртуальный класс таблиц
{
protected:
	virtual int Find(string)=0; //поиск
public:	

	virtual void Insert(string, Polinom*)=0; //вставка
	virtual void Delete(string)=0; //удаление
	virtual Polinom* GetTabNode(string)=0; //получение эл-та табл.

};

/*-------------------------------------------------------------------------------------------------------------*/
class SortTable: public Table
{
private:
	int Count;
	int Max_Size;
	TabNode* Data_Pol;

	bool IsFull();
	void AddOrderly(string,Polinom *);
	void MoreMem();
	int Find(string);
public:
	int FindSort(string key) {return Find(key);}
	SortTable();
	int GetCountData();
	int GetMaxSize();
	TabNode GetData(int);
	void Insert(string,Polinom *);
	void Delete(string);
	Polinom* GetTabNode(string);
};

/*-------------------------------------------------------------------------------------------------------------*/
class HashTable : public Table
{
public:
	list<TabNode> **Data;
	int Max_Size;

	int HashFuncH(string );
	int Find(string key) { return 0; };

	HashTable();

	void Insert(string , Polinom *);
	void Delete(string);
	Polinom* GetTabNode(string);
};

/*-------------------------------------------------------------------------------------------------------------*/
//Звено таблицы
TabNode::TabNode() { //констр. без параметров
	Name = "";
	Data = new Polinom;
}

TabNode::TabNode(const TabNode& row){ //констр. копир.
	Name = row.GetKey();
	Polinom* pol = row.GetElement();
	Data = pol;
}

TabNode::TabNode(string name_, Polinom* data_)  //констр. с пар-рами
{
	Name = name_;
	Data = data_;
}

TabNode& TabNode::operator=(const TabNode& row) //присваивание
{
	if (this == &row) {
		return *this;
	}
	Name = row.GetKey();
	Data = row.GetElement();
	return *this;
}

bool TabNode::operator==(const TabNode& row) //сравнение
{
	return GetKey() == row.GetKey();
}

std::string TabNode::GetKey() const  //получить ID (уник. идентиф.) звена таблицы (факт. - полинома)
{
	return Name;
}
Polinom* TabNode::GetElement() const  //получить данные звена (полином)
{
	return Data;
}

/*-------------------------------------------------------------------------------------------------------------*/
//Сортированные



SortTable::SortTable() //конструктор
{
	Count = 0; //номер
	Max_Size = 1; //макс. раз-р
	Data_Pol = new TabNode[Max_Size]; //выдел. память
}

void SortTable::MoreMem() //выделение доп. памяти
{
	TabNode* tmp = new TabNode[Max_Size*2];
	for (int i = 0; i < Max_Size; i++)
	{
		tmp[i] = Data_Pol[i];
	}
	delete[] Data_Pol;
	Max_Size = 2 * Max_Size;
	Data_Pol = tmp;
}

TabNode SortTable::GetData(int Pos) //получение полинома
{
	return Data_Pol[Pos];
}

int SortTable::GetCountData() //получение номера
{
	return Count;
}
int SortTable::GetMaxSize() //раз-р
{
	return Max_Size;
}
bool SortTable::IsFull() //проверка на полноту таблицы
{
	if (Count == Max_Size) 
	{
		return true;
	}
	else
	return false;
}

int SortTable::Find(string key) //поиск по "ключу"
{
	if (Count==0) //пустая таблица
	{
		return -1;
	}
	int Left_Data = -1;                    
	int Right_Data = Count;
	int i;
	while (Left_Data < Right_Data - 1)  
	{            
		i = (Left_Data + Right_Data) / 2; //ищем среднее между 2 границами          
		if (Data_Pol[i].GetKey() < key) //сравниваем ключ данного полинома с нашим ключом и в зависимости от рез-тата двигаем границы
			Left_Data = i;
		else
			Right_Data = i;
	}
	return Right_Data; //возвращ. правую границу
}

void SortTable::AddOrderly(string key, Polinom *PolA)
{
	if (Count == 0)
	{
		Data_Pol[0] = TabNode(key, PolA); //вставка звена в пустую таблицу
		Count++;
		return;
	}
	if (key<Data_Pol[0].GetKey())
	{
		for (int i = Count; i > 0; i--) {
			Data_Pol[i] = Data_Pol[i - 1];
		}
		Data_Pol[0] = TabNode(key, PolA); //запись в начало
		Count++;
		return;
	}
	if (key>Data_Pol[Count-1].GetKey()) {
		Data_Pol[Count] = TabNode(key, PolA); //вставка в конец
		Count++;
		return;
	}

	int Ind = Find(key); //определяем индекс по ключу
	for (int i = Count; i > Ind; i--) { //сдвигаем
		Data_Pol[i] = Data_Pol[i - 1];
	}
	Data_Pol[Ind] = TabNode(key, PolA); //вставляем на позицию, соотв. этому индексу
	Count++;
	return;
}

void SortTable::Insert(string key, Polinom* PolA) //вставка
{

	if (Count==Max_Size)
	{
		MoreMem(); //выдел. доп. памяти если таблица заполнена
	}
	AddOrderly(key, PolA); //вставка
}

void SortTable::Delete(string key)
{
	int Ind = Find(key); //индекс полинома с зад. ключом
	for (int i = Ind; i < Count-1; i++)
	{
		Data_Pol[i] = Data_Pol[i + 1]; //сдвиг строк таблицы
	}
	Data_Pol[Count - 1] = TabNode("",NULL); 
	Count--;
}

Polinom* SortTable::GetTabNode(string key)
{
	int Ind = Find(key);
	if (Ind == -1) //случай пустой таблицы
	{
		return NULL;
	}
	return Data_Pol[Ind].GetElement(); //получаем содержимое
}

/*-------------------------------------------------------------------------------------------------------------*/

HashTable::HashTable() //конструктор
{
	Max_Size = 3;
	Data = new list<TabNode>*[Max_Size];
	for (int i = 0; i < Max_Size; i++)
	{
		Data[i] = new list<TabNode>;
	}
}

void HashTable::Insert(string key, Polinom* PolA) //вставка полинома
{
	int Hash = HashFuncH(key); 
	Data[Hash]->push_back(TabNode(key, PolA)); //вставка по "хешу"
}

void HashTable::Delete(string key)
{
	
	int Hash = HashFuncH(key);
	TabNode Node(key, NULL);
	Data[Hash]->remove(Node); //удаление по "хешу"
}

int HashTable::HashFuncH(string s) //сама ф-ия
{
	int Hash = 0;
	for (int i = 0; i < s.size(); i++)
	{
		Hash += s[i]; 
	}
	return Hash%Max_Size;
}

Polinom* HashTable::GetTabNode(string key) //получение звена
{
	int Hash = HashFuncH(key);
	list<TabNode>::const_iterator iterator;
	for (iterator = Data[Hash]->begin(); iterator != Data[Hash]->end(); ++iterator) {
		if (key == iterator->GetKey())
		{
			return iterator->GetElement();
		}
	}
	return NULL;
}


#endif