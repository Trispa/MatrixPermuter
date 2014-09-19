/**
 * \file ListeSimpleTesteur.cpp
 * \brief Les tests unitaires de Liste.
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \version 0.3
 * \date mai 2014
 *
 * Implémentation des tests unitaires pour Liste
 */

#include "gtest/gtest.h"
#include <exception>
#include "Liste.h"


 using namespace labo3;
class ListeTest: public ::testing::Test {
protected:
	virtual void SetUp() {
		liste.ajouter(10, 1);
		liste.ajouter(20, 2);
		liste.ajouter(30, 3);
	}
	// virtual void TearDown() {}
	Liste<int> listeVide;
	Liste<int> liste;
};

TEST_F(ListeTest, constructeurVideOK) {
	EXPECT_TRUE(listeVide.taille() == 0);
	EXPECT_TRUE(listeVide.estVide());
}

TEST_F(ListeTest, ajouterElement) {
	listeVide.ajouter(10, 1);

	EXPECT_EQ(1, listeVide.taille());
	EXPECT_FALSE(listeVide.estVide());

//	EXPECT_THROW(listeVide.ajouter(20, -1), PreconditionException);
//	EXPECT_THROW(listeVide.ajouter(20, 10), PreconditionException);
}

TEST_F(ListeTest, ajouter2ElementsEnTete) {
	listeVide.ajouter(10, 1);
	listeVide.ajouter(20, 1);
	EXPECT_TRUE(listeVide.appartient(10));
	EXPECT_TRUE(listeVide.appartient(20));
	EXPECT_EQ(1, listeVide.position(20));
	EXPECT_EQ(2, listeVide.position(10));
	EXPECT_EQ(2, listeVide.taille());
	EXPECT_FALSE(listeVide.estVide());
}

TEST_F(ListeTest, ajouter3ElementsEnTete) {
	listeVide.ajouter(10, 1);
	listeVide.ajouter(20, 1);
	listeVide.ajouter(30, 1);

	EXPECT_TRUE(listeVide.appartient(10));
	EXPECT_TRUE(listeVide.appartient(20));
	EXPECT_TRUE(listeVide.appartient(30));
	EXPECT_EQ(1, listeVide.position(30));
	EXPECT_EQ(2, listeVide.position(20));
	EXPECT_EQ(3, listeVide.position(10));
	EXPECT_EQ(3, listeVide.taille());
	EXPECT_FALSE(listeVide.estVide());
}

TEST_F(ListeTest, ajouter3ElementsEnQueue) {
	listeVide.ajouter(10, 1);
	listeVide.ajouter(20, 2);
	listeVide.ajouter(30, 3);

	EXPECT_TRUE(listeVide.appartient(10));
	EXPECT_TRUE(listeVide.appartient(20));
	EXPECT_TRUE(listeVide.appartient(30));
	EXPECT_EQ(3, listeVide.position(30));
	EXPECT_EQ(2, listeVide.position(20));
	EXPECT_EQ(1, listeVide.position(10));
	EXPECT_EQ(3, listeVide.taille());
	EXPECT_FALSE(listeVide.estVide());
}

TEST_F(ListeTest, ajouter3ElementsAuMilieu) {
	listeVide.ajouter(10, 1);
	listeVide.ajouter(20, 2);
	listeVide.ajouter(30, 2);

	EXPECT_TRUE(listeVide.appartient(10));
	EXPECT_TRUE(listeVide.appartient(20));
	EXPECT_TRUE(listeVide.appartient(30));
	EXPECT_EQ(2, listeVide.position(30));
	EXPECT_EQ(3, listeVide.position(20));
	EXPECT_EQ(1, listeVide.position(10));

	EXPECT_EQ(3, listeVide.taille());
	EXPECT_FALSE(listeVide.estVide());
}

TEST_F(ListeTest, AppartientOK) {
	EXPECT_TRUE(liste.appartient(10));
	EXPECT_TRUE(liste.appartient(20));
	EXPECT_TRUE(liste.appartient(30));
	EXPECT_FALSE(liste.appartient(40));
}

TEST_F(ListeTest, positionOK) {
	EXPECT_EQ(1, liste.position(10));
	EXPECT_EQ(2, liste.position(20));
	EXPECT_EQ(3, liste.position(30));

	EXPECT_THROW(liste.position(40), std::logic_error);
}

TEST_F(ListeTest, elementOK) {
	EXPECT_EQ(10, liste.element(1));
	EXPECT_EQ(20, liste.element(2));
	EXPECT_EQ(30, liste.element(3));
//	EXPECT_THROW(liste.element(0), PreconditionException);
//	EXPECT_THROW(liste.element(4), PreconditionException);
}

TEST_F(ListeTest, enlever1elementEleverElOK) {
	EXPECT_THROW(listeVide.enleverEl(10), std::logic_error);

	listeVide.ajouter(10, 1);
	listeVide.enleverEl(10);

	EXPECT_TRUE(listeVide.estVide());
}

TEST_F(ListeTest, elever2elementsParQueueEnleverElOK) {
	liste.enleverEl(30);
	EXPECT_EQ(2, liste.taille());

	liste.enleverEl(20);
	EXPECT_EQ(1, liste.taille());

	liste.enleverEl(10);
	EXPECT_TRUE(liste.estVide());
}

TEST_F(ListeTest, elever3elementsParQueueEnleverElOK) {
	liste.enleverEl(30);
	EXPECT_FALSE(liste.appartient(30));
	EXPECT_TRUE(liste.appartient(20));
	EXPECT_TRUE(liste.appartient(10));
	EXPECT_EQ(1, liste.position(10));
	EXPECT_EQ(2, liste.position(20));
	liste.enleverEl(20);
	EXPECT_FALSE(liste.appartient(20));
	EXPECT_TRUE(liste.appartient(10));
	EXPECT_EQ(1, liste.position(10));
	liste.enleverEl(10);
	EXPECT_FALSE(liste.appartient(10));
	EXPECT_TRUE(liste.estVide());
}

TEST_F(ListeTest, elever3elementsParTeteEnleverElOK) {
	liste.enleverEl(10);
	EXPECT_FALSE(liste.appartient(10));
	EXPECT_TRUE(liste.appartient(20));
	EXPECT_TRUE(liste.appartient(30));
	EXPECT_EQ(1, liste.position(20));
	EXPECT_EQ(2, liste.position(30));
	liste.enleverEl(20);
	EXPECT_FALSE(liste.appartient(20));
	EXPECT_TRUE(liste.appartient(30));
	EXPECT_EQ(1, liste.position(30));
	liste.enleverEl(30);
	EXPECT_FALSE(liste.appartient(30));
	EXPECT_TRUE(liste.estVide());
}

TEST_F(ListeTest, enlever1elementEleverPosOK) {
//	EXPECT_THROW(listeVide.enleverPos(1), PreconditionException);
//	EXPECT_THROW(listeVide.enleverPos(0), PreconditionException);

	listeVide.ajouter(10, 1);
	listeVide.enleverPos(1);

	EXPECT_TRUE(listeVide.estVide());
}

TEST_F(ListeTest, elever2elementsParQueueEnleverPosOK) {
	listeVide.ajouter(10, 1);
	listeVide.ajouter(20, 2);

	listeVide.enleverPos(2);

	EXPECT_EQ(1, listeVide.taille());
	listeVide.enleverPos(1);

	EXPECT_TRUE(listeVide.estVide());
}

TEST_F(ListeTest, elever3elementsParQueueEnleverPosOK) {
	liste.enleverPos(3);
	liste.enleverPos(2);
	liste.enleverPos(1);

	EXPECT_TRUE(liste.estVide());
}

TEST_F(ListeTest, elever3elementsParTeteEnleverPosOK) {
	liste.enleverPos(1);
	EXPECT_FALSE(liste.appartient(10));
	liste.enleverPos(1);
	EXPECT_FALSE(liste.appartient(20));
	liste.enleverPos(1);
	EXPECT_FALSE(liste.appartient(30));

	EXPECT_TRUE(liste.estVide());
}

TEST_F(ListeTest, ConstructeurCopieOK) {
	Liste<int> liste2(liste);

	EXPECT_EQ(liste.taille(), liste2.taille());
	EXPECT_EQ(liste.position(10), liste2.position(10));
	EXPECT_EQ(liste.position(20), liste2.position(20));
	EXPECT_EQ(liste.position(30), liste2.position(30));
	EXPECT_EQ(liste.element(1), liste2.element(1));
	EXPECT_EQ(liste.element(2), liste2.element(2));
	EXPECT_EQ(liste.element(3), liste2.element(3));

}

TEST_F(ListeTest, OperateurAssignationObjetVideOK) {
	Liste<int> liste2;
	liste2 = liste;
	EXPECT_EQ(liste.taille(), liste2.taille());
	EXPECT_EQ(liste.position(10), liste2.position(10));
	EXPECT_EQ(liste.position(20), liste2.position(20));
	EXPECT_EQ(liste.position(30), liste2.position(30));
	EXPECT_EQ(liste.element(1), liste2.element(1));
	EXPECT_EQ(liste.element(2), liste2.element(2));
	EXPECT_EQ(liste.element(3), liste2.element(3));
}

TEST_F(ListeTest, OperateurAssignationObjetNonVideOK) {
	Liste<int> liste2;
	liste2.ajouter(40, 1);
	liste2.ajouter(50, 2);
	liste2.ajouter(60, 3);
	liste2 = liste;
	EXPECT_EQ(liste.taille(), liste2.taille());
	EXPECT_EQ(liste.position(10), liste2.position(10));
	EXPECT_EQ(liste.position(20), liste2.position(20));
	EXPECT_EQ(liste.position(30), liste2.position(30));
	EXPECT_EQ(liste.element(1), liste2.element(1));
	EXPECT_EQ(liste.element(2), liste2.element(2));
	EXPECT_EQ(liste.element(3), liste2.element(3));
}

TEST_F(ListeTest, afficherOk) {
	std::cout << liste << std::endl;

