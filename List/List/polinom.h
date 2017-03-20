#ifndef __POLINOM_STRUCT
#define __POLINOM_STRUCT

#include <iostream>
#include "monom.h"

using namespace std;

struct PNode
{

	Monom Mon; //�����
	PNode *next; //��. �� ��.

	PNode(); //������. �� �����.
	PNode(Monom, PNode *); //������. � ���-����
	PNode (Monom); //������. � ���-���
	~PNode(); //�����.
	void SetMonom(Monom); //�����. �����
	void SetNext(PNode *); //���. ��.
	PNode * GetNext(); //�������� ����.
	Monom GetMonom(); //�������� �����
	
};

class Polinom
{
public:
	PNode* Head; //��. �� ��.


	Polinom(); //������. �� ��.
	Polinom(Polinom &); //������. �����.
	Polinom(PNode *); //������. � ���-���
	~Polinom(); //�����.
	Polinom TypeChar(Polinom, char); //����������� ���� ����.

	
	void AddWithLastMon(PNode *, Monom &); //���������� ������ � �����
	void AddWithBeginMon(Monom &); //���������� ������ � ������
	void Add(PNode *, Monom &); //���������� ������ � � �����. �����.

	void DeleteMonWithBegin(); //�������� ������ �� ������
	void DeleteMons();  //�������� �������
	void DeleteMonWithPos(PNode *&); //�������� ������ � �������� �������

	Polinom operator+ (const Polinom&) const; //�����
	Polinom operator-(const Polinom&) const; //��������
	Polinom operator*(const Monom&) const; //��������� �� �����
	Polinom operator*(const Polinom&) const; //��������� �� �������
	Polinom& operator=(const Polinom &); //������������
	Polinom Enter(); //���� �������� ��� ���������� �������
	friend ostream &operator<<(ostream &, const Polinom&); //�����
	void Clear(); //�������
};
	void CheckOperation(char); //�������� �� ������������ ��������
	
	
	PNode* PNode :: GetNext() //����. ����. �� ����.
{
	return next;
}/*---------------------------------------------------------------*/
Monom PNode :: GetMonom() //�������� ����� �� �����
{
	return Mon;
}/*---------------------------------------------------------------*/

PNode :: PNode() //������. �� �����.
{
	SetMonom(Monom());
	SetNext(NULL);
}/*---------------------------------------------------------------*/

void PNode :: SetMonom(Monom MonA) //�������� ��. ������ � ��.
{
	this->Mon = MonA;
}/*---------------------------------------------------------------*/
void PNode :: SetNext(PNode *n) //���. ��. �� ����.
{
	next = n;
}/*---------------------------------------------------------------*/
PNode :: PNode(Monom MonA) // ������. � ���-��� ���.
{
	this->SetMonom(MonA);
	this->SetNext(NULL);
}/*---------------------------------------------------------------*/
PNode :: PNode(Monom MonA, PNode* n) //������. � ���-���� ������� � ����.
{
	SetMonom(MonA);
	SetNext(n);
}/*---------------------------------------------------------------*/


PNode :: ~PNode() //�����.
{
}/*---------------------------------------------------------------*/

Polinom :: Polinom (PNode *next) //�����. �������� � ���.
{

	if (next != NULL)
	this->Head = next;	
	else
		throw "1";
}/*---------------------------------------------------------------*/
Polinom :: Polinom() //������. �� �����.
{
	Head = NULL;
}/*---------------------------------------------------------------*/

Polinom :: Polinom(Polinom &PolA) //������. �����������
{
	PNode *temp = PolA.Head->next;
	PNode *temp_this;
	if (!PolA.Head) 
	{
		this->Head = NULL;
		return;
	}
	this->Head = new PNode(PolA.Head->Mon); //�����. �����. ������
	temp_this = this->Head;
	while(temp != NULL){
		this->AddWithLastMon(temp_this, temp->Mon); //��������� � ����� �������� ������ �����������
		temp_this = temp_this->next;
		temp = temp->next;
	}
	temp_this->next = NULL;
}/*---------------------------------------------------------------*/
Polinom :: ~ Polinom()
{
	DeleteMons();
}/*---------------------------------------------------------------*/
void Polinom :: AddWithLastMon(PNode *tek, Monom &data)
{
	if (!tek)
		throw "1";
	tek->next = new PNode(data);

}/*---------------------------------------------------------------*/
void Polinom :: Add(PNode *tek, Monom &data)
{
	PNode *elem = new PNode(data, tek->next); 
	tek->next =  elem;
}/*---------------------------------------------------------------*/
void Polinom :: AddWithBeginMon(Monom &data)
{
	PNode *elem = new PNode(data, Head);
	Head = elem;
	
}/*---------------------------------------------------------------*/
void Polinom :: DeleteMonWithBegin()
{
	PNode *temp = Head;
	Head = Head->next;
	delete temp;
	
}/*---------------------------------------------------------------*/
void Polinom :: DeleteMons()
{
	while(Head != NULL)
	DeleteMonWithBegin();

}/*---------------------------------------------------------------*/
void Polinom :: DeleteMonWithPos(PNode *&pos)
{
	PNode *temp = pos; 
	pos->next = temp->next;
	delete temp;
	/*if ((pos) && (Head!=0))
	{
		PNode* node=pos->next->next;
		delete pos->next;
		(pos->next)=node;

	}
	else
		throw 1;*/
}/*---------------------------------------------------------------*/
void CheckOperation(char oper) //�������� ����� �������� ��������
{
		if ((oper != '+') && (oper != '-') && (oper != '*'))
			throw "1";
}/*---------------------------------------------------------------*/
Polinom	Polinom :: TypeChar(Polinom PolB, char oper) //����������� ���������� �������� ��� ���������
{
	Polinom Temp;
	if (oper == '+')
		Temp = *this + PolB;
	if (oper == '-')
		Temp = *this - PolB;
	if (oper == '*')
		Temp = *this * PolB;
	return Temp;
}/*---------------------------------------------------------------*/
void Polinom:: Clear()
{
	if ((Head->Mon.coef != 0) && (Head->next != NULL))
		while (Head != NULL){
			if (Head->Mon.coef == 0)
				DeleteMonWithBegin();
	}
}/*---------------------------------------------------------------*/
Polinom Polinom ::  Enter() //��������� ����� � ����������� � �������
{
	bool flag = true;
	int i = 0;
	while (flag == true)
	{
		Monom MonA;
		MonA.MonomMake();
		this->AddWithBeginMon(MonA);
		int couts;
		cout<<"1.end"<<endl<<"2.continue"<<endl;
		cin >> couts;
		if (couts != 2)
		flag = false;
	}
	return *this;
}/*---------------------------------------------------------------*/

Polinom Polinom :: operator-(const Polinom& PolB) const //�������� ���������
{
	Polinom Res;
	if (PolB.Head == NULL) //���� ������� ������, �� ������������ ���������� �������
	{
		return Res = *this;
	}
	if (this->Head == NULL) //���� ���. ������, �� ������ ������� � � ������������� ������
	{
		Monom Mon_temp(-1,0,0,0);
		Res = PolB * Mon_temp;
		return Res;
	}
	Monom Mon_temp(-1,0,0,0); //� ���� ������� ������ �������� � ������ �������� ������� � � ��������. ������ (��������� �� ����� � ����. -1)
	Res = (*this) + PolB * Mon_temp;
	return Res;
}/*---------------------------------------------------------------*/

Polinom Polinom :: operator*( const Monom& MonB) const //��������� �������� �� �����
{
	Polinom Res;
	PNode *Current_Res;
	PNode* Current = this->Head;
	Res.AddWithBeginMon(Monom()); //�����. ������ ����� � �������. �������
	Current_Res = Res.Head;
	while (Current != NULL) //���� ������ �� ��������� ��������� �� � ��������������, ������� �� ����� �
	{
		Res.AddWithLastMon(Current_Res, Current->Mon * MonB);
		Current = Current->next;
		Current_Res = Current_Res->next;
	}
	Res.DeleteMonWithBegin(); //���� �������
	return Res;
}/*---------------------------------------------------------------*/
Polinom& Polinom :: operator=(const Polinom &PolA)
{
	if (this != &PolA) 
	 {
		this->DeleteMons(); //������� ������

		PNode *temp;
		PNode *temp_this;
		if (!PolA.Head) //�������
		{
			this->Head = NULL;
			return *this;
		}

		this->Head = new PNode(PolA.Head->Mon); //�������� ������
		temp = PolA.Head->next;
		temp_this = this->Head; 
		while(temp != NULL){ //���������� �����������
			this->AddWithLastMon(temp_this, temp->Mon);
			temp_this = temp_this->next;
			temp = temp->next;
		}
		temp_this->next = NULL;
	}
	else
	{
		return *this;
	}
	return *this;
}/*---------------------------------------------------------------*/

Polinom Polinom :: operator + (const Polinom& PolA) const
{
	Polinom Res;
	PNode* Current_this = this->Head;
	PNode* Current_PolA = PolA.Head;
	PNode* Current_Res;

	if (this->Head == 0) //��� ������
	{
		return Res = PolA;
	}
	if (PolA.Head == 0) //� ������ 
	{
		return Res = *this;
	}

	Res.AddWithBeginMon(Monom()); //����. ����. �����
	Current_Res = Res.Head;

	while ((Current_this != NULL) && (Current_PolA != NULL))
	{
		if (Current_this->Mon < Current_PolA->Mon) //���� ����� �� � "������" "���"-�
		{
			Res.AddWithLastMon(Current_Res, Current_this->Mon); //�������� � ��������� ����.
			Current_this = Current_this->next;
			Current_Res = Current_Res->next;
		} 
		else 
			if (Current_this->Mon > Current_PolA->Mon) //�������� ��������
		{
			Res.AddWithLastMon(Current_Res,Current_PolA->Mon); //�������� � ��������� ����.
			Current_PolA = Current_PolA->next;
			Current_Res = Current_Res->next;
		}
		else 
		{
			if ((Current_this->Mon + Current_PolA->Mon) != 0) //���� ������ �� �������� ������� ������������ ����������� � ������ ���������� ��������
			{ 
				Res.AddWithLastMon(Current_Res, Current_this->Mon + Current_PolA->Mon);
				Current_this = Current_this->next;
				Current_PolA = Current_PolA->next;
				Current_Res = Current_Res->next;
			}
		}
	}
	while (Current_this != NULL) //������ ���������� ���� ��. ������� ���������� 
	{ 
		Res.AddWithLastMon(Current_Res, Current_this->Mon);
		Current_this = Current_this->next;
		Current_Res = Current_Res->next;
	}
	while (Current_PolA != NULL) //������ ���������� ���� ��. ������� ���������� 
	{
		Res.AddWithLastMon(Current_Res, Current_PolA->Mon);
		Current_PolA = Current_PolA->next;
		Current_Res = Current_Res->next;
	}
	Res.DeleteMonWithBegin(); //������ ������



	Current_Res=Res.Head;
	PNode * Temp1=Current_Res;
	//int * Temp2;
	
	//Res1.AddWithBeginMon(Monom()); 
	//Current_Res1 = Res1.Head;
	while ((Temp1!=NULL) && (Current_Res != NULL))
	{
		Current_Res = Current_Res->next;
		while (Current_Res!=NULL)
		{
			if(Temp1->Mon == Current_Res->Mon)
			{
				Temp1->Mon=Temp1->Mon+Current_Res->Mon;
				Current_Res->Mon.coef=0;
			}
			Current_Res = Current_Res->next;
		}
		/*	Res1.AddWithLastMon(Current_Res1, Temp1->Mon);
			Current_Res1 = Current_Res1->next;*/

		Temp1 = Temp1->next;
		
	}

	return Res;
}/*---------------------------------------------------------------*/





Polinom Polinom :: operator*(const Polinom& PolA) const
{
	Polinom Res;
	Polinom temp;
	PNode* Current = this->Head;

	while (Current != NULL) {
		cout<<Current->Mon;

		temp = PolA * Current->Mon; //�������� ������� � �� ������ ����� ���
		
		cout << "temp " << temp << "\n";
		cout << "res before plus " << Res << "\n";
		
		Res = temp + Res; //���������� ���-����, � ����� ����. ��������

		cout << "all result " << Res << "\n";

		Current = Current->next;
	}

	return Res;
}/*---------------------------------------------------------------*/

ostream &operator<<(ostream &ostr,  const Polinom& PolA) 
{
	PNode* temp = PolA.Head;
	while (temp != NULL)
	{
		ostr << temp->Mon;
		ostr << "  ";
		temp = temp->next;
	}
	ostr << endl;
	return ostr;
}/*---------------------------------------------------------------*/

#endif