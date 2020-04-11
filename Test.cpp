#include "doctest.h"
#include "FamilyTree.hpp"
using namespace ariel;

TEST_CASE("Test case 1") {
   	family::Tree T("Yosef");
	T.addMother("Yosef","Sarah")
	.addFather("Yosef","Adam")
	.addFather("Sarah","Adam")
	.addMother("Adam","Ronit")
	.addMother("Adam", "Zeava")
	.addFather("Zeava","Shmuel")
	.addFather("Adam", "Tom")
	.addMother("Sarah", "Revital");
	
    CHECK(T.relation("Sarah") == string("mother"));
    CHECK(T.relation("Adam") == string("father"));
    CHECK(T.relation("Revital") == string("grandmother"));
    CHECK(T.relation("Zeava") == string("great-grandmother"));
    CHECK(T.relation("Tom") == string("grandfather"));
    CHECK(T.relation("Ronit") == string("grandmother"));
    CHECK(T.relation("Shmuel") == string("great-great-grandfather"));
    CHECK(T.relation("Dani") == string("unrelated"));
    CHECK(T.relation("Zeev") == string("unrelated"));
    CHECK(T.relation("abcd") == string("unrelated"));
  
    CHECK(T.find("mother") == string("Sarah"));
    CHECK(T.find("father") == string("Adam")); 
    CHECK(T.find("grandfather") == string("Tom"));
    CHECK(T.find("great-grandmother") == string("Zeava"));
    CHECK(T.find("great-great-grandfather") == string("Shmuel"));
    
    CHECK_THROWS(t.find("great-great-great-grandmother"));
    
    
}

TEST_CASE("Test case 2") {
    FamilyTree T("Yosef");
    T.addMother("Yosef","Sarah")
	.addFather("Yosef","Adam")
	.addFather("Sarah","Adam")
	.addMother("Adam","Ronit")
	.addMother("Adam", "Zeava")
	.addFather("Zeava","Shmuel")
	.addFather("Adam", "Tom")
	.addMother("Sarah", "Revital");
}