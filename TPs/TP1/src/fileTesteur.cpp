//!\File_listeChaineTesteur..cpp
//!\ Created on: 2014-09-30
//!\  Author: Patrice Diouf

#include <gtest/gtest.h>
#include "File.h"

using namespace  tp1;
/****************************FIXTURE******************************
 *
 */


class maFileTesteur : public ::testing::Test
{
public:
	File<int> uneFile;
};


TEST_F(maFileTesteur, constructeurVide)
{
	ASSERT_EQ(uneFile.taille(),0);
	ASSERT_TRUE(uneFile.estVide());
}

TEST_F(maFileTesteur, enfiler)
{

		File <int> maFile;
		maFile.enfiler(1);
		ASSERT_EQ(1, maFile.taille());
		maFile.enfiler(2);
		ASSERT_EQ(2, maFile.taille());
		maFile.enfiler(3);
		ASSERT_EQ(3, maFile.taille());

}


TEST_F(maFileTesteur, defiler)
{
		File <int> maFile;
		maFile.enfiler(1);
		maFile.enfiler(2);
		maFile.enfiler(3);

		maFile.defiler();
		ASSERT_EQ(2, maFile.taille());
		maFile.defiler();
		ASSERT_EQ(1, maFile.taille());
		maFile.defiler();
		ASSERT_EQ(0, maFile.taille());

		ASSERT_TRUE(maFile.estVide());

		EXPECT_THROW(maFile.defiler(), std::logic_error);
}

TEST_F(maFileTesteur, PremierElement)
{
	File <int> maFile;
			maFile.enfiler(1);
			maFile.enfiler(2);
			maFile.enfiler(3);
		ASSERT_EQ(maFile.premier(), 1);

}
TEST_F(maFileTesteur, enlverPosition)
{
	File <int> maFile;
				maFile.enfiler(1);
				maFile.enfiler(8);
				maFile.enfiler(3);
				maFile.enfiler(10);
				maFile.enleverPos(3);
				cout <<" le dernier element de la file est maintenent  : "<<maFile.dernier()<<endl;
			ASSERT_EQ(maFile.taille(), 3);
}




