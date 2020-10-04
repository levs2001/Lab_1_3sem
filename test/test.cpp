#include "pch.h"
#include "../Lab_1_3sem/listInit.c"
#include "../Lab_1_3sem/ListFinding.c"

TEST(ListInitTest, InitListTest) {
	myList* man = InitList("tSurname", "tName", "tPatron");
	ASSERT_TRUE(man != NULL);
	EXPECT_STREQ("tSurname", man->surname);
	EXPECT_STREQ("tName", man->name);
	EXPECT_STREQ("tPatron", man->patron);
	DeleteList(man);
	/*EXPECT_TRUE(true);*/
}

TEST(ListInitTest, EnterSNPTest) {
	myList* man = InitList("", "", "");
	EnterSNP(man, "tSurname", "tName", "tPatron");
	EXPECT_STREQ("tSurname", man->surname);
	EXPECT_STREQ("tName", man->name);
	EXPECT_STREQ("tPatron", man->patron);
	DeleteList(man);
}


TEST(ListInitTest, FindPosForManWith1ManTest) {
	enum SNP_E snp_pos = SURNAME;
	myList* nMan = NULL;
	myList* pMan = NULL;
	SNP snp;

	strcpy(snp.surname, "Aa");

	myList* man = InitList("tSurname", "tName", "tPatron");

	FindPosForMan(&man, snp, &pMan, &nMan, snp_pos);
	EXPECT_TRUE(pMan == NULL);
	EXPECT_TRUE(nMan == man);

	DeleteList(man);
}


TEST(ListInitTest, AddManTest) {
	enum SNP_E snp_pos = SURNAME;
	myList *nextMan = NULL, *newMan = NULL;
	myList* pMan = NULL;

	SNP snp;

	strcpy(snp.surname, "Aa");
	strcpy(snp.name, "Aa");
	strcpy(snp.patron, "Aa");

	myList* man = InitList("tSurname", "tName", "tPatron");

	FindPosForMan(&man, snp, &pMan, &nextMan, snp_pos);
	newMan = AddMan(nextMan, pMan, snp.surname, snp.name, snp.patron);

	ASSERT_TRUE(newMan != NULL);
	EXPECT_TRUE((pMan == NULL) || (pMan->next == newMan));
	EXPECT_TRUE(newMan->next == nextMan);

	DeleteList(man);
}


TEST(ListInitTest, Add2ListTestNoChangeOrder) {
	myList* start = NULL;
	myList* man1 = NULL, *man2 = NULL;
	SNP snp;
	
	strcpy(snp.surname, "Aa");
	strcpy(snp.name, "Aa");
	strcpy(snp.patron, "Aa");
	start = InitList(snp.surname, snp.name, snp.patron);
	man1 = start;

	strcpy(snp.surname, "Bb");
	strcpy(snp.name, "Bb");
	strcpy(snp.patron, "Bb");
	man2 = Add2List(&start, snp);

	ASSERT_TRUE(man1 != NULL);
	ASSERT_TRUE(man2 != NULL);
	EXPECT_TRUE(man1==start);
	EXPECT_TRUE(man1->next != NULL);
	EXPECT_TRUE(man2->next == NULL);

	DeleteList(start);
		
}

TEST(ListInitTest, Add2ListTestWithChangeOrder) {
	myList* start = NULL;
	myList* man1 = NULL, * man2 = NULL;
	SNP snp;

	strcpy(snp.surname, "Bb");
	strcpy(snp.name, "Bb");
	strcpy(snp.patron, "Bb");
	start = InitList(snp.surname, snp.name, snp.patron);
	man1 = start;

	strcpy(snp.surname, "Aa");
	strcpy(snp.name, "Aa");
	strcpy(snp.patron, "Aa");
	man2 = Add2List(&start, snp);

	ASSERT_TRUE(man1 != NULL);
	ASSERT_TRUE(man2 != NULL);
	EXPECT_TRUE(man2 == start);
	EXPECT_TRUE(man2->next != NULL);
	EXPECT_TRUE(man1->next == NULL);
	
	DeleteList(start);

}


TEST(SearchListTest, StrSearchAnalysTest) {
	SNP searchSNP;
	char search[40];
	
	strcpy(search, "aa bb cc");
	StrSearchAnalys(&searchSNP, search);
		
	EXPECT_TRUE(searchSNP.surname[0] == 'a');
	EXPECT_TRUE(searchSNP.surname[1] == 'a');
	
	EXPECT_TRUE(searchSNP.name[0] == 'b');
	EXPECT_TRUE(searchSNP.name[1] == 'b');
	
	EXPECT_TRUE(searchSNP.patron[0] == 'c');
	EXPECT_TRUE(searchSNP.patron[1] == 'c');
	
}
