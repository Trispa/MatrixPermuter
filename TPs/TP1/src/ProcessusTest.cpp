//!\File_listeChaineTesteur..cpp
//!\ Created on: 2014-09-30
//!\  Author: Patrice Diouf

#include <gtest/gtest.h>
#include "Processus.h"

using namespace  tp1;
/****************************FIXTURE******************************
 *
 */

class ProcessusTest: public ::testing::Test
{
public:
	Processus  processusVide; //Processus vide

	Processus * processus = new Processus("pe1", 5, 3);
};



TEST_F(ProcessusTest, constructeurVide)
{
	ASSERT_EQ(processusVide.getPid(),"");
	ASSERT_EQ(processusVide.getEtat(),"nouveau");
	ASSERT_EQ(processusVide.getPriorite(),0);
	ASSERT_EQ(processusVide.getTempsAttente(),0);
	ASSERT_EQ(processusVide.getTempsConsomme(),0);
	ASSERT_EQ(processusVide.getDuree(),0);
}

TEST_F(ProcessusTest, constructeurAvecParametre)
{
	ASSERT_EQ(processus->getDuree(),5);
	ASSERT_EQ("pe1", processus->getPid());
	ASSERT_EQ(processus->getEtat(),"nouveau");
	ASSERT_EQ(processus->getPriorite(),3);
	ASSERT_EQ(processus->getTempsAttente(),0);
	ASSERT_EQ(processus->getTempsConsomme(),0);
}
