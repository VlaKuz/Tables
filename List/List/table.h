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
class Table //����������� ����� ������
{
protected:
	virtual int Find(string)=0; //�����
public:	

	virtual void Insert(string, Polinom*)=0; //�������
	virtual void Delete(string)=0; //��������
	virtual Polinom* GetTabNode(string)=0; //��������� ��-�� ����.

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
//����� �������
TabNode::TabNode() { //������. ��� ����������
	Name = "";
	Data = new Polinom;
}

TabNode::TabNode(const TabNode& row){ //������. �����.
	Name = row.GetKey();
	Polinom* pol = row.GetElement();
	Data = pol;
}

TabNode::TabNode(string name_, Polinom* data_)  //������. � ���-����
{
	Name = name_;
	Data = data_;
}

TabNode& TabNode::operator=(const TabNode& row) //������������
{
	if (this == &row) {
		return *this;
	}
	Name = row.GetKey();
	Data = row.GetElement();
	return *this;
}

bool TabNode::operator==(const TabNode& row) //���������
{
	return GetKey() == row.GetKey();
}

std::string TabNode::GetKey() const  //�������� ID (����. �������.) ����� ������� (����. - ��������)
{
	return Name;
}
Polinom* TabNode::GetElement() const  //�������� ������ ����� (�������)
{
	return Data;
}

/*-------------------------------------------------------------------------------------------------------------*/
//�������������



SortTable::SortTable() //�����������
{
	Count = 0; //�����
	Max_Size = 1; //����. ���-�
	Data_Pol = new TabNode[Max_Size]; //�����. ������
}

void SortTable::MoreMem() //��������� ���. ������
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

TabNode SortTable::GetData(int Pos) //��������� ��������
{
	return Data_Pol[Pos];
}

int SortTable::GetCountData() //��������� ������
{
	return Count;
}
int SortTable::GetMaxSize() //���-�
{
	return Max_Size;
}
bool SortTable::IsFull() //�������� �� ������� �������
{
	if (Count == Max_Size) 
	{
		return true;
	}
	else
	return false;
}

int SortTable::Find(string key) //����� �� "�����"
{
	if (Count==0) //������ �������
	{
		return -1;
	}
	int Left_Data = -1;                    
	int Right_Data = Count;
	int i;
	while (Left_Data < Right_Data - 1)  
	{            
		i = (Left_Data + Right_Data) / 2; //���� ������� ����� 2 ���������          
		if (Data_Pol[i].GetKey() < key) //���������� ���� ������� �������� � ����� ������ � � ����������� �� ���-���� ������� �������
			Left_Data = i;
		else
			Right_Data = i;
	}
	return Right_Data; //�������. ������ �������
}

void SortTable::AddOrderly(string key, Polinom *PolA)
{
	if (Count == 0)
	{
		Data_Pol[0] = TabNode(key, PolA); //������� ����� � ������ �������
		Count++;
		return;
	}
	if (key<Data_Pol[0].GetKey())
	{
		for (int i = Count; i > 0; i--) {
			Data_Pol[i] = Data_Pol[i - 1];
		}
		Data_Pol[0] = TabNode(key, PolA); //������ � ������
		Count++;
		return;
	}
	if (key>Data_Pol[Count-1].GetKey()) {
		Data_Pol[Count] = TabNode(key, PolA); //������� � �����
		Count++;
		return;
	}

	int Ind = Find(key); //���������� ������ �� �����
	for (int i = Count; i > Ind; i--) { //��������
		Data_Pol[i] = Data_Pol[i - 1];
	}
	Data_Pol[Ind] = TabNode(key, PolA); //��������� �� �������, �����. ����� �������
	Count++;
	return;
}

void SortTable::Insert(string key, Polinom* PolA) //�������
{

	if (Count==Max_Size)
	{
		MoreMem(); //�����. ���. ������ ���� ������� ���������
	}
	AddOrderly(key, PolA); //�������
}

void SortTable::Delete(string key)
{
	int Ind = Find(key); //������ �������� � ���. ������
	for (int i = Ind; i < Count-1; i++)
	{
		Data_Pol[i] = Data_Pol[i + 1]; //����� ����� �������
	}
	Data_Pol[Count - 1] = TabNode("",NULL); 
	Count--;
}

Polinom* SortTable::GetTabNode(string key)
{
	int Ind = Find(key);
	if (Ind == -1) //������ ������ �������
	{
		return NULL;
	}
	return Data_Pol[Ind].GetElement(); //�������� ����������
}

/*-------------------------------------------------------------------------------------------------------------*/

HashTable::HashTable() //�����������
{
	Max_Size = 3;
	Data = new list<TabNode>*[Max_Size];
	for (int i = 0; i < Max_Size; i++)
	{
		Data[i] = new list<TabNode>;
	}
}

void HashTable::Insert(string key, Polinom* PolA) //������� ��������
{
	int Hash = HashFuncH(key); 
	Data[Hash]->push_back(TabNode(key, PolA)); //������� �� "����"
}

void HashTable::Delete(string key)
{
	
	int Hash = HashFuncH(key);
	TabNode Node(key, NULL);
	Data[Hash]->remove(Node); //�������� �� "����"
}

int HashTable::HashFuncH(string s) //���� �-��
{
	int Hash = 0;
	for (int i = 0; i < s.size(); i++)
	{
		Hash += s[i]; 
	}
	return Hash%Max_Size;
}

Polinom* HashTable::GetTabNode(string key) //��������� �����
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