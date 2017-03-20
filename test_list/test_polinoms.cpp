#include <gtest.h>
#include "monom.h"
#include "Polinom.h"
TEST (List, can_create_monoms)
{
	ASSERT_NO_THROW (Monom TestMonom(5,2,1,1));
}

TEST (List, cannot_create_monoms)
{
	ASSERT_ANY_THROW (Monom TestMonom(5,-1,-3,1));
}

TEST(List, Can_create_copy_monoms){
	Monom TestMonom1(5, 2, 1, 1);
	ASSERT_NO_THROW(Monom TestMonom2(TestMonom1));
}

TEST (List, equal_monoms)
{
	Monom TestMonom(5,2,3,1);
	Monom TestMonom_2(5,2,3,1);
	EXPECT_EQ(true,TestMonom==TestMonom_2);
}

TEST (List, non_equal_monoms)
{
	Monom TestMonom(5,3,3,1);
	Monom TestMonom_2(5,2,3,1);
	EXPECT_EQ(true,TestMonom!=TestMonom_2);
}

TEST(List, set_and_get_coeffs)
{
 	int TestStep[3];
	TestStep[0] = 1;
	TestStep[1] = 0;
	TestStep[2] = 1;
	double TestCoef = 0;
	Monom TestMonom(TestCoef, TestStep);
 	TestMonom.SetCoeffic(3);
 	EXPECT_EQ(3, TestMonom.GetCoeffic());
 }

TEST (List, sum_monoms)
{
	Monom TestMonom(6,2,3,1);
	Monom TestMonom_2(5,2,3,1);
	Monom TempMonom(11,2,3,1);
	Monom TestMonom_Res=TestMonom+TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
}

TEST (List, sum_monoms_2)
{
	Monom TestMonom(-6,2,3,1);
	Monom TestMonom_2(5,2,3,1);
	Monom TempMonom(-1,2,3,1);
	Monom TestMonom_Res=TestMonom+TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
}

TEST (List, mult_monoms)
{
	Monom TestMonom(6,2,3,1);
	Monom TestMonom_2(5,2,3,1);
	Monom TempMonom(30,4,6,2);
	Monom TestMonom_Res=TestMonom*TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
}

TEST (List, mult_monoms_2_9_9_9)
{
	Monom TestMonom(6,2,6,8);
	Monom TestMonom_2(5,7,3,1);
	Monom TempMonom(30,9,9,9);
	Monom TestMonom_Res=TestMonom*TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
	ASSERT_NO_THROW(TestMonom_Res = TestMonom * TestMonom_2);
}

TEST(List, can_not_mult_monoms_because_too_large_res_degree) 
{
	Monom TestMonom(12, 9, 0, 1);
	Monom TestMonom_2(3, 2, 0, 9);
	Monom TestMonom_Res;
	ASSERT_ANY_THROW(TestMonom_Res = TestMonom * TestMonom_2);
}

TEST(List, mult_monoms_2_large_deg) 
{
	Monom TestMonom(5, 9, 6, 1);
	Monom TestMonom_2(2, 1, 3, 9);
	Monom TestMonom_Res;
	ASSERT_ANY_THROW(TestMonom_Res = TestMonom * TestMonom_2);
}
TEST (List, minus_monoms)
{
	Monom TestMonom(6,2,3,1);
	Monom TestMonom_2(5,2,3,1);
	Monom TempMonom(1,2,3,1);
	Monom TestMonom_Res=TestMonom-TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
}

TEST (List, minus_monoms_2)
{
	Monom TestMonom(6,2,3,1);
	Monom TestMonom_2(-5,2,3,1);
	Monom TempMonom(11,2,3,1);
	Monom TestMonom_Res=TestMonom-TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
}

TEST(List, can_no_equality_monoms_on_step_sravn) 
{
 	Monom TestMonom(1, 1, 1, 2);
 	Monom TestMonom_2(1, 1, 2, 3);
 	EXPECT_TRUE(TestMonom < TestMonom_2);
}

TEST(List, can_no_equality_monoms_on_step_sravn_2) 
{
 	Monom TestMonom(1, 1, 1, 2);
 	Monom TestMonom_2(1, 1, 2, 3);
 	EXPECT_FALSE(TestMonom > TestMonom_2);
}

TEST(List, can_no_equality_monoms_on_step_sravn_3) 
{
 	Monom TestMonom(1, 5, 3, 3);
 	Monom TestMonom_2(1, 1, 2, 3);
 	EXPECT_TRUE(TestMonom > TestMonom_2);
  }

TEST(List, can_no_equality_monoms_on_step_sravn_4) 
{
 	Monom TestMonom(1, 5, 3, 3);
 	Monom TestMonom_2(1, 1, 2, 3);
 	EXPECT_FALSE(TestMonom < TestMonom_2);
}
/*-------------------------------------------------------------*/

TEST(List, can_create_pnode)
{
	ASSERT_NO_THROW(new PNode);
}

TEST(List, can_create_pnode_on_monoms)
{
	Monom TestMonom(1,1,2,3);

	ASSERT_NO_THROW(new PNode(TestMonom));
}

TEST(List, can_copy_node)
{
	Monom TestMonom(3, 1, 1, 1);
	PNode TestNode(TestMonom);
	ASSERT_NO_THROW(new PNode(TestNode));
}

TEST(List, can_create_polinoms)
{
	ASSERT_NO_THROW(Polinom TestPolinom);
}

TEST(List, can_create_polinom_with_parametres)
{
	PNode *Head = 0;
	ASSERT_ANY_THROW(Polinom TestPolinom(Head));
}

TEST(List, can_copy_polinom){
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(3, 5, 0, 0));
	TestPolinomA.AddWithBeginMon(Monom(1, 1, 0, 0));
	Polinom TestPolinomB(TestPolinomA);
	EXPECT_EQ(TestPolinomB.Head->Mon, TestPolinomA.Head->Mon);
	EXPECT_EQ(TestPolinomB.Head->next->Mon, TestPolinomA.Head->next->Mon);
	EXPECT_EQ(TestPolinomB.Head->Mon.coef, TestPolinomA.Head->Mon.coef);
	EXPECT_EQ(TestPolinomB.Head->next->Mon.coef, TestPolinomA.Head->next->Mon.coef);
}

TEST(List, operation_plus) {
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(2, 2, 1, 2));
	TestPolinomA.AddWithBeginMon(Monom(2, 1, 0, 0));
	Polinom TestPolinomB;
	TestPolinomB.AddWithBeginMon(Monom(4, 2, 1, 2));
	TestPolinomB.AddWithBeginMon(Monom(2, 1, 0, 0));
	Polinom TestPolinomC;
	
	TestPolinomC = TestPolinomA + TestPolinomB;

	EXPECT_EQ(4, TestPolinomC.Head->Mon.coef);
	EXPECT_EQ(6, TestPolinomC.Head->next->Mon.coef);
}

TEST(List, operation_plus1) {
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(2, 3, 0, 0));
	TestPolinomA.AddWithBeginMon(Monom(1, 1, 0, 0));
	Polinom TestPolinomB;
	TestPolinomB.AddWithBeginMon(Monom(1, 3, 0, 0));
	TestPolinomB.AddWithBeginMon(Monom(2, 0, 2, 0));
	Polinom TestPolinomC;
	
	TestPolinomC = TestPolinomA + TestPolinomB;

	EXPECT_EQ(2, TestPolinomC.Head->Mon.coef);
	EXPECT_EQ(1, TestPolinomC.Head->next->Mon.coef);
	EXPECT_EQ(3, TestPolinomC.Head->next->next->Mon.coef);
}

TEST(List, operation_minus) {
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(2, 2, 1, 2));
	TestPolinomA.AddWithBeginMon(Monom(2, 1, 0, 0));
	Polinom TestPolinomB;
	TestPolinomB.AddWithBeginMon(Monom(4, 2, 1, 2));
	TestPolinomB.AddWithBeginMon(Monom(2, 1, 0, 0));
	Polinom TestPolinomC;
	
	TestPolinomC = TestPolinomA - TestPolinomB;

	EXPECT_EQ(0, TestPolinomC.Head->Mon.coef);
	EXPECT_EQ(-2, TestPolinomC.Head->next->Mon.coef);
}

TEST(List, operation_minus2) {
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(2, 3, 0, 0));
	TestPolinomA.AddWithBeginMon(Monom(1, 1, 0, 0));
	Polinom TestPolinomB;
	TestPolinomB.AddWithBeginMon(Monom(1, 3, 0, 0));
	TestPolinomB.AddWithBeginMon(Monom(2, 0, 2, 0));
	Polinom TestPolinomC;
	
	TestPolinomC = TestPolinomA - TestPolinomB;

	EXPECT_EQ(-2, TestPolinomC.Head->Mon.coef);
	EXPECT_EQ(1, TestPolinomC.Head->next->Mon.coef);
	EXPECT_EQ(1, TestPolinomC.Head->next->next->Mon.coef);
}

TEST(List, equal_polinom){
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(2, 3, 2, 1));
	TestPolinomA.AddWithBeginMon(Monom(1, 1, 0, 0));
	Polinom TestPolinomB;
	TestPolinomB.AddWithBeginMon(Monom(1, 0, 0, 0));
	TestPolinomB = TestPolinomA;

	EXPECT_EQ(TestPolinomB.Head->Mon, TestPolinomA.Head->Mon);
	EXPECT_EQ(TestPolinomB.Head->next->Mon, TestPolinomA.Head->next->Mon);
	EXPECT_EQ(TestPolinomB.Head->Mon.coef, TestPolinomA.Head->Mon.coef);
	EXPECT_EQ(TestPolinomB.Head->next->Mon.coef, TestPolinomA.Head->next->Mon.coef);
}

TEST(List, mult_polinom_with_polinom){
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(2, 3, 0, 0));
	TestPolinomA.AddWithBeginMon(Monom(3, 4, 0, 0));
	Polinom TestPolinomB(TestPolinomA);
	Polinom TestPolinomC(TestPolinomA*TestPolinomB);


	EXPECT_EQ(12, TestPolinomC.Head->Mon.coef);
	EXPECT_EQ(4, TestPolinomC.Head->next->Mon.coef);
	EXPECT_EQ(9, TestPolinomC.Head->next->next->Mon.coef);

	EXPECT_EQ(7, TestPolinomC.Head->Mon.step[0]);
	EXPECT_EQ(6, TestPolinomC.Head->next->Mon.step[0]);
	EXPECT_EQ(8, TestPolinomC.Head->next->next->Mon.step[0]);
}

TEST(List, mult_polinom_with_polinom1){
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(2, 4, 0, 0));
	TestPolinomA.AddWithBeginMon(Monom(5, 3, 0, 0));
	Polinom TestPolinomB(TestPolinomA);
	Polinom TestPolinomC(TestPolinomA*TestPolinomB);


	EXPECT_EQ(25, TestPolinomC.Head->Mon.coef);
	EXPECT_EQ(20, TestPolinomC.Head->next->Mon.coef);
	EXPECT_EQ(4, TestPolinomC.Head->next->next->Mon.coef);

	EXPECT_EQ(6, TestPolinomC.Head->Mon.step[0]);
	EXPECT_EQ(7, TestPolinomC.Head->next->Mon.step[0]);
	EXPECT_EQ(8, TestPolinomC.Head->next->next->Mon.step[0]);
}

TEST(List, mult_polinom_monom){
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(2, 1, 0, 0));
	TestPolinomA.AddWithBeginMon(Monom(2.5, 3, 2, 0));
	Monom TestPolinomB(4, 1, 2, 3);
	Polinom TestPolinomC;

	TestPolinomC = TestPolinomA * TestPolinomB;

	EXPECT_EQ(10, TestPolinomC.Head->Mon.coef);
	EXPECT_EQ(8, TestPolinomC.Head->next->Mon.coef);

	EXPECT_EQ(4, TestPolinomC.Head->Mon.step[0]);
	EXPECT_EQ(4, TestPolinomC.Head->Mon.step[1]);
	EXPECT_EQ(3, TestPolinomC.Head->Mon.step[2]);

	EXPECT_EQ(2, TestPolinomC.Head->next->Mon.step[0]);
	EXPECT_EQ(2, TestPolinomC.Head->next->Mon.step[1]);
	EXPECT_EQ(3, TestPolinomC.Head->next->Mon.step[2]);
}

TEST(List, Can_delete_list){
	Polinom TestPolinomA;
	ASSERT_NO_THROW(TestPolinomA.DeleteMons());
}
TEST(List, Can_not_add_first_monom_as_last){
	Monom TestMonomA(3, 2, 1, 2);
	PNode TestNode(TestMonomA);
	Polinom TestPolinomA;
	ASSERT_ANY_THROW(TestPolinomA.AddWithLastMon(TestPolinomA.Head, TestMonomA));
}

TEST(List, Can_add_monom_first){
	Monom TestMonomA(3, 2, 1, 2);
	PNode TestNode(TestMonomA);
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(TestMonomA);

	EXPECT_EQ(TestMonomA, TestPolinomA.Head->Mon);
}

TEST(List, Can_add_monom_last){
	Monom TestMonomA(3, 2, 1, 2);
	Monom TestMonomB(1.1, 2, 2, 2);
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(TestMonomA);
	PNode *current = TestPolinomA.Head;
	
	TestPolinomA.AddWithLastMon(current, TestMonomB);
	EXPECT_EQ(1.1, TestPolinomA.Head->next->Mon.coef);
}

TEST(List, Can_add_monom_middle){
	Monom TestMonomA(3, 2, 1, 2);
	Monom TestMonomB(1.1, 2, 2, 2);
	Monom TestMonomC(2.3, 2, 1, 5);
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(TestMonomC);
	TestPolinomA.AddWithBeginMon(TestMonomA);

	TestPolinomA.Add(TestPolinomA.Head, TestMonomB);
	EXPECT_EQ(TestMonomB.coef, TestPolinomA.Head->next->Mon.coef);
}
