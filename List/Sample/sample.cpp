#include "Polinom.h"
#include "monom.h"
void main()
{
	Polinom polA, polB;

	setlocale(LC_ALL, "Russian");
 	cout << "���� A & B" << endl;

	polA.Enter();
	polB.Enter();
	

	cout << polA << endl;

	cout << polB << endl;

	cout << "��������: +, -, * " << endl;
	char op;
	cin >> op;
	CheckOperation(op);

	Polinom polC;
	polC = polA.TypeChar(polB, op);
	
	cout << "����� = " << polC << endl;
	//polC.Clear();
}