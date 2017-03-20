#ifndef __MONOM_STRUCT
#define __MONOM_STRUCT

#include <iostream>

using namespace std;

class Monom
{
public:
	double coef; //кэф.
	int *step; //степ.


	Monom(double, int*); //констр. с пар-рами
	Monom(double cef=0, int a=0, int b=0, int c=0); //констр. с пар-рами 2
	Monom(Monom &); //констр. копир.
	~Monom(); //деструктор

	Monom operator + (const Monom &); //сумма
 	Monom operator - (const Monom &); //разность
	Monom operator * (const Monom &); //произведение
	Monom & operator=(const Monom&); //присваивание

	Monom MonomMake(); //создание монома
	double GetCoeffic() const; //получ. коэф.
	int * GetStep() const; //подуч. степень
	void SetCoeffic(double); //ввод/замена кэфа.
	void SetStep(int*); //ввод/замена степени
	friend ostream &operator<<(ostream &, const Monom); //вывод
	friend bool operator == (const Monom&, const Monom&); //рав-во
 	friend bool operator != (const Monom&, const Monom&); //нерав-во
	friend bool operator < (const Monom&, const Monom&); //условный меньше (какой из мономов по степ. больше или меньше)
 	friend bool operator > (const Monom&, const Monom&); //условный больше (какой из мономов по степ. больше или меньше)
};


double Monom ::GetCoeffic() const //пол. кэф.
 {
 	return coef;
 }/*---------------------------------------------------------------*/
 
 int* Monom ::GetStep() const //пол. степ.
 {
 	return step;
 }/*---------------------------------------------------------------*/
 
 void Monom :: SetCoeffic(double cout) //задаем кэф.
 {
 	coef = cout;
 }/*---------------------------------------------------------------*/
 
 void Monom :: SetStep(int *deg) //задаем степ.
 {
	 for(int i = 0; i < 3; i++)
 		step[i] = deg[i];
 }/*---------------------------------------------------------------*/

Monom::Monom(double cout, int a, int b, int c) //констр.
{

	if ((a < 0) || (b < 0) || (c < 0))
		throw "1";
	
		this->step = new int [3];	
		this->step[0] = a;
		this->step[1] = b;
		this->step[2] = c;
		this->coef = cout;
	
}/*---------------------------------------------------------------*/
Monom :: Monom(double cout, int *new_step){ //конструктор с пар.
	this->step = new int[3];
	for (int i = 0; i < 3; i++)
		this->step[i] = new_step[i];
	this->coef = cout;
}/*---------------------------------------------------------------*/
Monom :: ~Monom(){ //дестр.
	delete []this->step;
}/*---------------------------------------------------------------*/
Monom :: Monom(Monom & MonA){ //конст. копир.
	this->step = new int [3];

	for (int i = 0; i < 3; i++)
		step[i] = MonA.step[i];
	this->coef = MonA.coef;
}/*---------------------------------------------------------------*/

 
 Monom& Monom :: operator=(const Monom& MonA) //присв.
 {
 	if (this == &MonA) 
	{
 		return *this;
 	}
 	coef = MonA.GetCoeffic();
 	
	if (!step)
		step = new int[3];
	for (int i = 0; i < 3; i++)
		this->step[i] = MonA.step[i];
	
 	return *this;
 }/*---------------------------------------------------------------*/
 
 bool operator==(const Monom& MonA,const Monom& MonB) //сравн. на рав-во
 {
	for (int i = 0; i < 3; i++)
		 if (MonA.step[i] != MonB.step[i])
			 return false;
 	return true;
 }/*---------------------------------------------------------------*/
 
bool operator!=(const Monom& MonA,const Monom& MonB) //сравн. на нерав-во
 {
	for (int i = 0; i < 3; i++)
		 if (MonA.step[i] != MonB.step[i])
			 return true;
 	return false;
 }/*---------------------------------------------------------------*/
 

Monom Monom :: operator+(const Monom &MonB) //сложить 2 монома
 {
	int changeA = (this->step[0]*100) + (this->step[1]*10) + (this->step[2]);
	int changeB = (MonB.step[0]*100) + (MonB.step[1]*10) + (MonB.step[2]);
	if (changeA != changeB)
	{
 		throw "1";
 	}
 	Monom res(this->GetCoeffic()+MonB.GetCoeffic(), this->GetStep());
 	return res;
 }/*---------------------------------------------------------------*/
 
Monom Monom :: operator-(const Monom &MonB) //разность пары мономов
 {
	int changeA = (this->step[0]*100) + (this->step[1]*10) + (this->step[2]);
	int changeB = (MonB.step[0]*100) + (MonB.step[1]*10) + (MonB.step[2]);
	if (changeA != changeB)
	{
 		throw "1";
 	}
 	Monom res(this->GetCoeffic()-MonB.GetCoeffic(), this->GetStep());
 	return res;
 }/*---------------------------------------------------------------*/

Monom Monom :: operator*(const Monom& MonB) //умножим мономы
{ 
	double Mon = this->GetCoeffic() * MonB.GetCoeffic();
	Monom res(Mon, 0, 0, 0);
	for (int i = 0; i <3; i++ )
	{
		res.step[i] = this->step[i] + MonB.step[i];
		if (res.step[i] > 9)
			throw "1";
	}
	return res;
}/*---------------------------------------------------------------*/

Monom Monom :: MonomMake() //сделаем моном
{	
		cin >> this->coef;
		for (int i = 0; i < 3; i++)
		{
			cin >> this->step[i];
			if ((step[i] > 9) || (step[i] < 0))
				throw "1";
		}
		return *this;
}/*---------------------------------------------------------------*/

bool operator < (const Monom& MonA,const Monom& MonB)
{
	 int changeA = MonA.step[0]*100 + MonA.step[1]*10 + MonA.step[2];
	 int changeB = MonB.step[0]*100 + MonB.step[1]*10 + MonB.step[2];
	 if (changeA < changeB)
 		return true;
	 return false;
}/*---------------------------------------------------------------*/
 
bool operator > (const Monom& MonA,const Monom& MonB)
 {
	 int changeA = MonA.step[0]*100 + MonA.step[1]*10 + MonA.step[2];
	 int changeB = MonB.step[0]*100 + MonB.step[1]*10 + MonB.step[2];
	 if (changeA > changeB)
 		return true;
	 return false;
 }/*---------------------------------------------------------------*/


ostream &operator<<(ostream &ostr, const Monom head)
{
		if (head.coef==0)
		ostr<<"";
		else
		{
		ostr << "coef = " << head.coef << ", ";
		ostr << "step = ";
		if (!head.step) ostr << "NULL deg";
		for(int i = 0; i < 3; i++ )
		ostr  << head.step[i];
		ostr << " ";
		}
	return ostr;
}/*---------------------------------------------------------------*/

#endif 
