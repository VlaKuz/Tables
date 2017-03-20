#ifndef __MONOM_STRUCT
#define __MONOM_STRUCT

#include <iostream>

using namespace std;

class Monom
{
public:
	double coef; //���.
	int *step; //����.


	Monom(double, int*); //������. � ���-����
	Monom(double cef=0, int a=0, int b=0, int c=0); //������. � ���-���� 2
	Monom(Monom &); //������. �����.
	~Monom(); //����������

	Monom operator + (const Monom &); //�����
 	Monom operator - (const Monom &); //��������
	Monom operator * (const Monom &); //������������
	Monom & operator=(const Monom&); //������������

	Monom MonomMake(); //�������� ������
	double GetCoeffic() const; //�����. ����.
	int * GetStep() const; //�����. �������
	void SetCoeffic(double); //����/������ ����.
	void SetStep(int*); //����/������ �������
	friend ostream &operator<<(ostream &, const Monom); //�����
	friend bool operator == (const Monom&, const Monom&); //���-��
 	friend bool operator != (const Monom&, const Monom&); //�����-��
	friend bool operator < (const Monom&, const Monom&); //�������� ������ (����� �� ������� �� ����. ������ ��� ������)
 	friend bool operator > (const Monom&, const Monom&); //�������� ������ (����� �� ������� �� ����. ������ ��� ������)
};


double Monom ::GetCoeffic() const //���. ���.
 {
 	return coef;
 }/*---------------------------------------------------------------*/
 
 int* Monom ::GetStep() const //���. ����.
 {
 	return step;
 }/*---------------------------------------------------------------*/
 
 void Monom :: SetCoeffic(double cout) //������ ���.
 {
 	coef = cout;
 }/*---------------------------------------------------------------*/
 
 void Monom :: SetStep(int *deg) //������ ����.
 {
	 for(int i = 0; i < 3; i++)
 		step[i] = deg[i];
 }/*---------------------------------------------------------------*/

Monom::Monom(double cout, int a, int b, int c) //������.
{

	if ((a < 0) || (b < 0) || (c < 0))
		throw "1";
	
		this->step = new int [3];	
		this->step[0] = a;
		this->step[1] = b;
		this->step[2] = c;
		this->coef = cout;
	
}/*---------------------------------------------------------------*/
Monom :: Monom(double cout, int *new_step){ //����������� � ���.
	this->step = new int[3];
	for (int i = 0; i < 3; i++)
		this->step[i] = new_step[i];
	this->coef = cout;
}/*---------------------------------------------------------------*/
Monom :: ~Monom(){ //�����.
	delete []this->step;
}/*---------------------------------------------------------------*/
Monom :: Monom(Monom & MonA){ //�����. �����.
	this->step = new int [3];

	for (int i = 0; i < 3; i++)
		step[i] = MonA.step[i];
	this->coef = MonA.coef;
}/*---------------------------------------------------------------*/

 
 Monom& Monom :: operator=(const Monom& MonA) //�����.
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
 
 bool operator==(const Monom& MonA,const Monom& MonB) //�����. �� ���-��
 {
	for (int i = 0; i < 3; i++)
		 if (MonA.step[i] != MonB.step[i])
			 return false;
 	return true;
 }/*---------------------------------------------------------------*/
 
bool operator!=(const Monom& MonA,const Monom& MonB) //�����. �� �����-��
 {
	for (int i = 0; i < 3; i++)
		 if (MonA.step[i] != MonB.step[i])
			 return true;
 	return false;
 }/*---------------------------------------------------------------*/
 

Monom Monom :: operator+(const Monom &MonB) //������� 2 ������
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
 
Monom Monom :: operator-(const Monom &MonB) //�������� ���� �������
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

Monom Monom :: operator*(const Monom& MonB) //������� ������
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

Monom Monom :: MonomMake() //������� �����
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
