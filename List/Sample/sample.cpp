#include "Polinom.h"
#include "monom.h"
void main()
{
	Polinom polA, polB;

	setlocale(LC_ALL, "Russian");
 	cout << "ввод A & B" << endl;

	polA.Enter();
	polB.Enter();
	

	cout << polA << endl;

	cout << polB << endl;

	cout << "операция: +, -, * " << endl;
	char op;
	cin >> op;
	CheckOperation(op);

	Polinom polC;
	polC = polA.TypeChar(polB, op);
	
	cout << "ответ = " << polC << endl;
	//polC.Clear();
}