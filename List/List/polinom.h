#ifndef __POLINOM_STRUCT
#define __POLINOM_STRUCT

#include <iostream>
#include "monom.h"

using namespace std;

struct PNode
{

	Monom Mon; //моном
	PNode *next; //ук. на сл.

	PNode(); //констр. по умолч.
	PNode(Monom, PNode *); //констр. с пар-рами
	PNode (Monom); //констр. с пар-ром
	~PNode(); //дестр.
	void SetMonom(Monom); //измен. моном
	void SetNext(PNode *); //изм. ук.
	PNode * GetNext(); //получить указ.
	Monom GetMonom(); //получить моном
	
};

class Polinom
{
public:
	PNode* Head; //ук. на зв.


	Polinom(); //констр. по ум.
	Polinom(Polinom &); //констр. копир.
	Polinom(PNode *); //констр. с пар-ром
	~Polinom(); //дестр.
	Polinom TypeChar(Polinom, char); //определение типа опер.

	
	void AddWithLastMon(PNode *, Monom &); //добавление монома в конец
	void AddWithBeginMon(Monom &); //добавление монома в начало
	void Add(PNode *, Monom &); //добавление монома в с задан. позиц.

	void DeleteMonWithBegin(); //удаление монома из начала
	void DeleteMons();  //удаление мономов
	void DeleteMonWithPos(PNode *&); //удаление монома с заданной позиции

	Polinom operator+ (const Polinom&) const; //сумма
	Polinom operator-(const Polinom&) const; //разность
	Polinom operator*(const Monom&) const; //умножение на моном
	Polinom operator*(const Polinom&) const; //умножение на полином
	Polinom& operator=(const Polinom &); //присваивание
	Polinom Enter(); //ввод полинома или добавление звеньев
	friend ostream &operator<<(ostream &, const Polinom&); //вывод
	void Clear(); //очистка
};
	void CheckOperation(char); //проверка на соответствие операций
	
	
	PNode* PNode :: GetNext() //верн. указ. на след.
{
	return next;
}/*---------------------------------------------------------------*/
Monom PNode :: GetMonom() //получить моном из звена
{
	return Mon;
}/*---------------------------------------------------------------*/

PNode :: PNode() //констр. по умолч.
{
	SetMonom(Monom());
	SetNext(NULL);
}/*---------------------------------------------------------------*/

void PNode :: SetMonom(Monom MonA) //изменить зн. монома в зв.
{
	this->Mon = MonA;
}/*---------------------------------------------------------------*/
void PNode :: SetNext(PNode *n) //изм. ук. на след.
{
	next = n;
}/*---------------------------------------------------------------*/
PNode :: PNode(Monom MonA) // констр. с пар-ром мон.
{
	this->SetMonom(MonA);
	this->SetNext(NULL);
}/*---------------------------------------------------------------*/
PNode :: PNode(Monom MonA, PNode* n) //констр. с пар-рами мономом и указ.
{
	SetMonom(MonA);
	SetNext(n);
}/*---------------------------------------------------------------*/


PNode :: ~PNode() //дестр.
{
}/*---------------------------------------------------------------*/

Polinom :: Polinom (PNode *next) //костр. полинома с пар.
{

	if (next != NULL)
	this->Head = next;	
	else
		throw "1";
}/*---------------------------------------------------------------*/
Polinom :: Polinom() //констр. по умолч.
{
	Head = NULL;
}/*---------------------------------------------------------------*/

Polinom :: Polinom(Polinom &PolA) //констр. копирования
{
	PNode *temp = PolA.Head->next;
	PNode *temp_this;
	if (!PolA.Head) 
	{
		this->Head = NULL;
		return;
	}
	this->Head = new PNode(PolA.Head->Mon); //выдел. соотв. памяти
	temp_this = this->Head;
	while(temp != NULL){
		this->AddWithLastMon(temp_this, temp->Mon); //добавляем в конец полинома мономы копируемого
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
void CheckOperation(char oper) //проверка верно введеной операции
{
		if ((oper != '+') && (oper != '-') && (oper != '*'))
			throw "1";
}/*---------------------------------------------------------------*/
Polinom	Polinom :: TypeChar(Polinom PolB, char oper) //определение выполнения операции над полиномом
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
Polinom Polinom ::  Enter() //создается моном и вставляется в полином
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

Polinom Polinom :: operator-(const Polinom& PolB) const //разность полиномов
{
	Polinom Res;
	if (PolB.Head == NULL) //если полином пустой, то возвращается вычитаемый полином
	{
		return Res = *this;
	}
	if (this->Head == NULL) //если исх. пустой, то вернем полином В с противополным знаком
	{
		Monom Mon_temp(-1,0,0,0);
		Res = PolB * Mon_temp;
		return Res;
	}
	Monom Mon_temp(-1,0,0,0); //в иных случаях просто прибавим к нашему полиному полином В с противоп. знаком (домножили на моном с коэф. -1)
	Res = (*this) + PolB * Mon_temp;
	return Res;
}/*---------------------------------------------------------------*/

Polinom Polinom :: operator*( const Monom& MonB) const //умножение полинома на моном
{
	Polinom Res;
	PNode *Current_Res;
	PNode* Current = this->Head;
	Res.AddWithBeginMon(Monom()); //помещ. пустой моном в результ. полином
	Current_Res = Res.Head;
	while (Current != NULL) //пока мономы не кончились вставляем их в результирующий, умножив на моном В
	{
		Res.AddWithLastMon(Current_Res, Current->Mon * MonB);
		Current = Current->next;
		Current_Res = Current_Res->next;
	}
	Res.DeleteMonWithBegin(); //снос пустого
	return Res;
}/*---------------------------------------------------------------*/
Polinom& Polinom :: operator=(const Polinom &PolA)
{
	if (this != &PolA) 
	 {
		this->DeleteMons(); //удаляем мономы

		PNode *temp;
		PNode *temp_this;
		if (!PolA.Head) //пустота
		{
			this->Head = NULL;
			return *this;
		}

		this->Head = new PNode(PolA.Head->Mon); //выделили память
		temp = PolA.Head->next;
		temp_this = this->Head; 
		while(temp != NULL){ //производим копирование
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

	if (this->Head == 0) //зис пустой
	{
		return Res = PolA;
	}
	if (PolA.Head == 0) //А пустой 
	{
		return Res = *this;
	}

	Res.AddWithBeginMon(Monom()); //созд. пуст. моном
	Current_Res = Res.Head;

	while ((Current_this != NULL) && (Current_PolA != NULL))
	{
		if (Current_this->Mon < Current_PolA->Mon) //если моном из А "больше" "зис"-а
		{
			Res.AddWithLastMon(Current_Res, Current_this->Mon); //закинули и подвинули указ.
			Current_this = Current_this->next;
			Current_Res = Current_Res->next;
		} 
		else 
			if (Current_this->Mon > Current_PolA->Mon) //обратная ситуация
		{
			Res.AddWithLastMon(Current_Res,Current_PolA->Mon); //закинули и подвинули указ.
			Current_PolA = Current_PolA->next;
			Current_Res = Current_Res->next;
		}
		else 
		{
			if ((Current_this->Mon + Current_PolA->Mon) != 0) //если мономы по степеням совпали производится дописывание с учетом приведения подобных
			{ 
				Res.AddWithLastMon(Current_Res, Current_this->Mon + Current_PolA->Mon);
				Current_this = Current_this->next;
				Current_PolA = Current_PolA->next;
				Current_Res = Current_Res->next;
			}
		}
	}
	while (Current_this != NULL) //просто дописываем если др. полином закончился 
	{ 
		Res.AddWithLastMon(Current_Res, Current_this->Mon);
		Current_this = Current_this->next;
		Current_Res = Current_Res->next;
	}
	while (Current_PolA != NULL) //просто дописываем если др. полином закончился 
	{
		Res.AddWithLastMon(Current_Res, Current_PolA->Mon);
		Current_PolA = Current_PolA->next;
		Current_Res = Current_Res->next;
	}
	Res.DeleteMonWithBegin(); //сносим пустой



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

		temp = PolA * Current->Mon; //умножаем полином А на каждый моном зис
		
		cout << "temp " << temp << "\n";
		cout << "res before plus " << Res << "\n";
		
		Res = temp + Res; //складываем рез-таты, а также прив. подобных

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