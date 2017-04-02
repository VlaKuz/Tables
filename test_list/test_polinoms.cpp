#include <gtest.h>
#include "monom.h"
#include "Polinom.h"
#include "table.h"
TEST (Monom, can_create_monoms)
{
	ASSERT_NO_THROW (Monom TestMonom(5,2,1,1));
}

TEST (Monom, cannot_create_monoms)
{
	ASSERT_ANY_THROW (Monom TestMonom(5,-1,-3,1));
}

TEST(Monom, Can_create_copy_monoms){
	Monom TestMonom1(5, 2, 1, 1);
	ASSERT_NO_THROW(Monom TestMonom2(TestMonom1));
}

TEST (Monom, equal_monoms)
{
	Monom TestMonom(5,2,3,1);
	Monom TestMonom_2(5,2,3,1);
	EXPECT_EQ(true,TestMonom==TestMonom_2);
}

TEST (Monom, non_equal_monoms)
{
	Monom TestMonom(5,3,3,1);
	Monom TestMonom_2(5,2,3,1);
	EXPECT_EQ(true,TestMonom!=TestMonom_2);
}

TEST(Monom, set_and_get_coeffs)
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

TEST (Monom, sum_monoms)
{
	Monom TestMonom(6,2,3,1);
	Monom TestMonom_2(5,2,3,1);
	Monom TempMonom(11,2,3,1);
	Monom TestMonom_Res=TestMonom+TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
}

TEST (Monom, sum_monoms_2)
{
	Monom TestMonom(-6,2,3,1);
	Monom TestMonom_2(5,2,3,1);
	Monom TempMonom(-1,2,3,1);
	Monom TestMonom_Res=TestMonom+TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
}

TEST (Monom, mult_monoms)
{
	Monom TestMonom(6,2,3,1);
	Monom TestMonom_2(5,2,3,1);
	Monom TempMonom(30,4,6,2);
	Monom TestMonom_Res=TestMonom*TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
}

TEST (Monom, mult_monoms_2_9_9_9)
{
	Monom TestMonom(6,2,6,8);
	Monom TestMonom_2(5,7,3,1);
	Monom TempMonom(30,9,9,9);
	Monom TestMonom_Res=TestMonom*TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
	ASSERT_NO_THROW(TestMonom_Res = TestMonom * TestMonom_2);
}

TEST(Monom, can_not_mult_monoms_because_too_large_res_degree) 
{
	Monom TestMonom(12, 9, 0, 1);
	Monom TestMonom_2(3, 2, 0, 9);
	Monom TestMonom_Res;
	ASSERT_ANY_THROW(TestMonom_Res = TestMonom * TestMonom_2);
}

TEST(Monom, mult_monoms_2_large_deg) 
{
	Monom TestMonom(5, 9, 6, 1);
	Monom TestMonom_2(2, 1, 3, 9);
	Monom TestMonom_Res;
	ASSERT_ANY_THROW(TestMonom_Res = TestMonom * TestMonom_2);
}
TEST (Monom, minus_monoms)
{
	Monom TestMonom(6,2,3,1);
	Monom TestMonom_2(5,2,3,1);
	Monom TempMonom(1,2,3,1);
	Monom TestMonom_Res=TestMonom-TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
}

TEST (Monom, minus_monoms_2)
{
	Monom TestMonom(6,2,3,1);
	Monom TestMonom_2(-5,2,3,1);
	Monom TempMonom(11,2,3,1);
	Monom TestMonom_Res=TestMonom-TestMonom_2;
	EXPECT_EQ (true,TempMonom==TestMonom_Res);
}

TEST(Monom, can_no_equality_monoms_on_step_sravn) 
{
 	Monom TestMonom(1, 1, 1, 2);
 	Monom TestMonom_2(1, 1, 2, 3);
 	EXPECT_TRUE(TestMonom < TestMonom_2);
}

TEST(Monom, can_no_equality_monoms_on_step_sravn_2) 
{
 	Monom TestMonom(1, 1, 1, 2);
 	Monom TestMonom_2(1, 1, 2, 3);
 	EXPECT_FALSE(TestMonom > TestMonom_2);
}

TEST(Monom, can_no_equality_monoms_on_step_sravn_3) 
{
 	Monom TestMonom(1, 5, 3, 3);
 	Monom TestMonom_2(1, 1, 2, 3);
 	EXPECT_TRUE(TestMonom > TestMonom_2);
  }

TEST(Monom, can_no_equality_monoms_on_step_sravn_4) 
{
 	Monom TestMonom(1, 5, 3, 3);
 	Monom TestMonom_2(1, 1, 2, 3);
 	EXPECT_FALSE(TestMonom < TestMonom_2);
}
/*-------------------------------------------------------------*/

TEST(PNode, can_create_pnode)
{
	ASSERT_NO_THROW(new PNode);
}

TEST(PNode, can_create_pnode_on_monoms)
{
	Monom TestMonom(1,1,2,3);

	ASSERT_NO_THROW(new PNode(TestMonom));
}

TEST(PNode, can_copy_node)
{
	Monom TestMonom(3, 1, 1, 1);
	PNode TestNode(TestMonom);
	ASSERT_NO_THROW(new PNode(TestNode));
}

TEST(Polinom, can_create_polinoms)
{
	ASSERT_NO_THROW(Polinom TestPolinom);
}

TEST(Polinom, Can_create_polinom_2)
{
	Polinom TestPolinomA;
	ASSERT_NO_THROW (TestPolinomA.AddWithBeginMon(Monom(1,1,1,1)));
}

TEST(Polinom, can_create_polinom_with_parametres)
{
	PNode *Head = 0;
	ASSERT_ANY_THROW(Polinom TestPolinom(Head));
}

TEST(Polinom, can_copy_polinom){
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(3, 5, 0, 0));
	TestPolinomA.AddWithBeginMon(Monom(1, 1, 0, 0));
	Polinom TestPolinomB(TestPolinomA);
	EXPECT_EQ(TestPolinomB.Head->Mon, TestPolinomA.Head->Mon);
	EXPECT_EQ(TestPolinomB.Head->next->Mon, TestPolinomA.Head->next->Mon);
	EXPECT_EQ(TestPolinomB.Head->Mon.coef, TestPolinomA.Head->Mon.coef);
	EXPECT_EQ(TestPolinomB.Head->next->Mon.coef, TestPolinomA.Head->next->Mon.coef);
}

TEST(Polinom, operation_plus) {
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

TEST(Polinom, operation_plus1) {
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

TEST(Polinom, operation_minus) {
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

TEST(Polinom, operation_minus2) {
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

TEST(Polinom, equal_polinom){
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

TEST(Polinom, mult_polinom_with_polinom){
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

TEST(Polinom, mult_polinom_with_polinom1){
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

TEST(Polinom, mult_polinom_monom){
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

TEST(Polinom, Can_delete_list){
	Polinom TestPolinomA;
	ASSERT_NO_THROW(TestPolinomA.DeleteMons());
}
TEST(Polinom, Can_not_add_first_monom_as_last){
	Monom TestMonomA(3, 2, 1, 2);
	PNode TestNode(TestMonomA);
	Polinom TestPolinomA;
	ASSERT_ANY_THROW(TestPolinomA.AddWithLastMon(TestPolinomA.Head, TestMonomA));
}

TEST(Polinom, Can_add_monom_first){
	Monom TestMonomA(3, 2, 1, 2);
	PNode TestNode(TestMonomA);
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(TestMonomA);

	EXPECT_EQ(TestMonomA, TestPolinomA.Head->Mon);
}

TEST(Polinom, Can_add_monom_last){
	Monom TestMonomA(3, 2, 1, 2);
	Monom TestMonomB(1.1, 2, 2, 2);
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(TestMonomA);
	PNode *current = TestPolinomA.Head;
	
	TestPolinomA.AddWithLastMon(current, TestMonomB);
	EXPECT_EQ(1.1, TestPolinomA.Head->next->Mon.coef);
}

TEST(Polinom, Can_add_monom_middle){
	Monom TestMonomA(3, 2, 1, 2);
	Monom TestMonomB(1.1, 2, 2, 2);
	Monom TestMonomC(2.3, 2, 1, 5);
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(TestMonomC);
	TestPolinomA.AddWithBeginMon(TestMonomA);

	TestPolinomA.Add(TestPolinomA.Head, TestMonomB);
	EXPECT_EQ(TestMonomB.coef, TestPolinomA.Head->next->Mon.coef);
}
/*-------------------------------------------------------------*/

TEST(SortTable, Can_create_nodetable)
{
	Polinom TestPolinomA;
	
	Monom TestMonomA (1,1,2,3);
	TestPolinomA.AddWithBeginMon(TestMonomA);
	TabNode TestNodeA("a",&TestPolinomA);
	EXPECT_EQ(TestNodeA.GetKey(),"a");
	EXPECT_EQ(TestNodeA.GetElement()->Head->Mon.step[0],1);
	EXPECT_EQ(TestNodeA.GetElement()->Head->Mon.step[1],2);
	EXPECT_EQ(TestNodeA.GetElement()->Head->Mon.step[2],3);
}

TEST(SortTable, Can_equal_nodetable)
{
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(1,1,2,3));
	TabNode TestNodeA("a",&TestPolinomA);
	TabNode TestNodeB("a",&TestPolinomA);
	TabNode TestNodeC("b",&TestPolinomA);
	EXPECT_TRUE(TestNodeA.operator==(TestNodeB));
	EXPECT_FALSE(TestNodeA.operator==(TestNodeC));
}

TEST(SortTable, can_equality)
{
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(1,1,2,3));
	TabNode TestNodeA("a",&TestPolinomA);
	TabNode TestNodeB;
	TestNodeB=TestNodeA;
	EXPECT_TRUE(TestNodeA.operator==(TestNodeB));
}

TEST(SortTable, Can_create_sort_table)
{
	Polinom TestPolinomA,TestPolinomB,TestPolinomC;
	TestPolinomA.AddWithBeginMon(Monom(1,1,2,3));
	TestPolinomB.AddWithBeginMon(Monom(2,2,3,4));
	TestPolinomC.AddWithBeginMon(Monom(3,3,5,6));
	SortTable TestSortTable;
	TestSortTable.Insert("b",&TestPolinomB);
	TestSortTable.Insert("a",&TestPolinomA);
	TestSortTable.Insert("c",&TestPolinomC);
	EXPECT_EQ(TestSortTable.GetData(0).GetKey(),"a");
	EXPECT_EQ(TestSortTable.GetData(0).GetElement()->Head->Mon.step[0],1);
	EXPECT_EQ(TestSortTable.GetData(0).GetElement()->Head->Mon.step[1],2);
	EXPECT_EQ(TestSortTable.GetData(0).GetElement()->Head->Mon.step[2],3);
	EXPECT_EQ(TestSortTable.GetData(1).GetKey(),"b");
	EXPECT_EQ(TestSortTable.GetData(1).GetElement()->Head->Mon.step[0],2);
	EXPECT_EQ(TestSortTable.GetData(1).GetElement()->Head->Mon.step[1],3);
	EXPECT_EQ(TestSortTable.GetData(1).GetElement()->Head->Mon.step[2],4);
	EXPECT_EQ(TestSortTable.GetData(2).GetKey(),"c");
	EXPECT_EQ(TestSortTable.GetData(2).GetElement()->Head->Mon.step[0],3);
	EXPECT_EQ(TestSortTable.GetData(2).GetElement()->Head->Mon.step[1],5);
	EXPECT_EQ(TestSortTable.GetData(2).GetElement()->Head->Mon.step[2],6);
}

TEST(SortTable, Can_insert_with_memory)
{
	Polinom TestPolinomA,TestPolinomB,TestPolinomC;
	TestPolinomA.AddWithBeginMon(Monom(1,1,1,1));
	TestPolinomB.AddWithBeginMon(Monom(2,2,2,2));
	TestPolinomC.AddWithBeginMon(Monom(3,3,3,3));
	SortTable TestSortTable;
	int TestSize1=0;
	int TestSize2=0;
	TestSortTable.Insert("b",&TestPolinomB);
	TestSize1=TestSortTable.GetMaxSize();
	TestSortTable.Insert("a",&TestPolinomA);
	TestSortTable.Insert("c",&TestPolinomC);
	TestSize2=TestSortTable.GetMaxSize();
	EXPECT_EQ(TestSize1,1);
	EXPECT_EQ(TestSize2,4);
	
}

TEST(SortTable, can_delete_node_from_sort_table)
{
	Polinom TestPolinomA,TestPolinomB,TestPolinomC;
	TestPolinomA.AddWithBeginMon(Monom(1,1,2,3));
	TestPolinomB.AddWithBeginMon(Monom(2,2,3,3));
	TestPolinomC.AddWithBeginMon(Monom(3,3,5,6));
	SortTable TestSortTable;
	TestSortTable.Insert("b",&TestPolinomB);
	TestSortTable.Insert("a",&TestPolinomA);
	TestSortTable.Insert("c",&TestPolinomC);
	TestSortTable.Delete("b");
	EXPECT_EQ(TestSortTable.GetData(0).GetKey(),"a");
	EXPECT_EQ(TestSortTable.GetData(0).GetElement()->Head->Mon.step[0],1);
	EXPECT_EQ(TestSortTable.GetData(0).GetElement()->Head->Mon.step[1],2);
	EXPECT_EQ(TestSortTable.GetData(0).GetElement()->Head->Mon.step[2],3);
	EXPECT_EQ(TestSortTable.GetData(1).GetKey(),"c");
	EXPECT_EQ(TestSortTable.GetData(1).GetElement()->Head->Mon.step[0],3);
	EXPECT_EQ(TestSortTable.GetData(1).GetElement()->Head->Mon.step[1],5);
	EXPECT_EQ(TestSortTable.GetData(1).GetElement()->Head->Mon.step[2],6);
}

TEST(SortTable, can_find_node_in_table)
{
	Polinom TestPolinomA,TestPolinomB,TestPolinomC;
	TestPolinomA.AddWithBeginMon(Monom(1,1,1,1));
	TestPolinomB.AddWithBeginMon(Monom(2,2,2,2));
	TestPolinomC.AddWithBeginMon(Monom(3,3,3,3));
	SortTable TestSortTable;
	TestSortTable.Insert("b",&TestPolinomB);
	TestSortTable.Insert("a",&TestPolinomA);
	EXPECT_EQ(TestSortTable.FindSort("a"),0);
	EXPECT_EQ(TestSortTable.FindSort("b"),1);
}

/*-------------------------------------------------------------*/

TEST(HashTable, can_create_hash_table) 
{
	HashTable TestHashTable;
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(1,1,2,3));
	TestHashTable.Insert("a",&TestPolinomA);
	EXPECT_EQ(TestHashTable.GetTabNode("a")->Head->Mon.step[0],1);
	EXPECT_EQ(TestHashTable.GetTabNode("a")->Head->Mon.step[1],2);
	EXPECT_EQ(TestHashTable.GetTabNode("a")->Head->Mon.step[2],3);
}

TEST(List, can_insert_node) 
{
	HashTable TestHashTable;
	Polinom TestPolinomA,TestPolinomB;
	TestPolinomA.AddWithBeginMon(Monom(1,1,2,3));
	TestPolinomB.AddWithBeginMon(Monom(2,2,3,4));
	TestHashTable.Insert("a",&TestPolinomA);
	TestHashTable.Insert("b",&TestPolinomB);
	EXPECT_EQ(TestHashTable.GetTabNode("a")->Head->Mon.step[0],1);
	EXPECT_EQ(TestHashTable.GetTabNode("a")->Head->Mon.step[1],2);
	EXPECT_EQ(TestHashTable.GetTabNode("a")->Head->Mon.step[2],3);
	EXPECT_EQ(TestHashTable.GetTabNode("b")->Head->Mon.step[0],2);
	EXPECT_EQ(TestHashTable.GetTabNode("b")->Head->Mon.step[1],3);
	EXPECT_EQ(TestHashTable.GetTabNode("b")->Head->Mon.step[2],4);
}
TEST(List, can_insert_collisions) 
{
	HashTable TestHashTable;
	Polinom TestPolinomA,TestPolinomB;
	TestPolinomA.AddWithBeginMon(Monom(1,1,2,3));
	TestPolinomB.AddWithBeginMon(Monom(2,2,3,4));
	TestHashTable.Insert("bc",&TestPolinomA);
	TestHashTable.Insert("ad",&TestPolinomB);
	EXPECT_EQ(TestHashTable.HashFuncH("bc"),strlen("bc"));
	EXPECT_EQ(TestHashTable.HashFuncH("bc"),strlen("ad"));
}

TEST(HashTable, can_delete)
{
	Polinom TestPolinomA,TestPolinomB,TestPolinomC;
	TestPolinomA.AddWithBeginMon(Monom(1,1,2,3));
	TestPolinomB.AddWithBeginMon(Monom(2,2,3,4));
	TestPolinomC.AddWithBeginMon(Monom(3,3,4,5));
	HashTable TestHashTable;
	TestHashTable.Insert("a",&TestPolinomA);
	TestHashTable.Insert("b",&TestPolinomB);
	TestHashTable.Insert("c",&TestPolinomC);
	TestHashTable.Delete("b");
	EXPECT_EQ(TestHashTable.GetTabNode("c")->Head->Mon.step[0],3);
	EXPECT_EQ(TestHashTable.GetTabNode("c")->Head->Mon.step[1],4);
	EXPECT_EQ(TestHashTable.GetTabNode("c")->Head->Mon.step[2],5);
}

TEST(HashTable, can_hashfunch) 
{
	HashTable TestHashTable;
	Polinom TestPolinomA;
	TestPolinomA.AddWithBeginMon(Monom(1,1,2,3));
	TestHashTable.Insert("ab",&TestPolinomA);
	int Res=0;
	Res=(int)('a')+(int)('b');
	EXPECT_EQ(Res%TestHashTable.Max_Size,TestHashTable.HashFuncH("ab"));
}

