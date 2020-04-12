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
	
	
	CHECK(T.relation("Yosef") == string("me"));
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
    
    CHECK_THROWS(T.find("great-great-great-grandmother"));
    
    
}

TEST_CASE("Test case 2") {
    family::Tree T("b");
    T.addMother("b","c")
	.addFather("c","d")
	.addMother("d","e")
	.addFather("e","f")
	.addMother("f", "g")
	.addFather("g","h")
	.addMother("h", "i")
	.addFather("i", "j")
	.addMother("j","k")
	.addFather("k","l");
	
	 CHECK(T.relation("b") == string("me"));
    CHECK(T.relation("c") == string("mother"));
    CHECK(T.relation("d") == string("grandfather"));
    CHECK(T.relation("e") == string("great-grandmother"));
    CHECK(T.relation("f") == string("great-great-grandfater"));
    CHECK(T.relation("g") == string("great-great-great-grandmother"));
    CHECK(T.relation("h") == string("great-great-great-great-grandfather"));
    CHECK(T.relation("i") == string("great-great-great-great-great-grandmother"));
    CHECK(T.relation("j") == string("great-great-great-great-great-great-grandfather"));
    CHECK(T.relation("k") == string("great-great-great-great-great-great-great-grandmother"));
    CHECK(T.relation("l") == string("great-great-great-great-great-great-great-great-grandfather"));
    CHECK(T.relation("m") == string("unrelated"));
    
    CHECK(T.find("me") == string("b"));
    CHECK(T.find("mother") == string("c")); 
    CHECK(T.find("grandfather") == string("d"));
    CHECK(T.find("great-grandmother") == string("e"));
    CHECK(T.find("great-great-grandfather") == string("f"));
    CHECK(T.find("great-great-great-grandmother") == string("g"));
    CHECK(T.find("great-great-great-great-grandfather") == string("h")); 
    CHECK(T.find("great-great-great-great-great-grandmother") == string("i"));
    CHECK(T.find("great-great-great-great-great-great-grandfather") == string("j"));
    CHECK(T.find("great-great-great-great-great-great-great-grandmother") == string("k"));
    CHECK(T.find("great-great-great-great-great-great-great-great-grandfather") == string("l"));
    
    CHECK(T.relation("b") == string("me"));
    CHECK(T.relation("c") == string("mother"));
    CHECK(T.relation("d") == string("grandfather"));
    CHECK(T.relation("e") == string("great-grandmother"));
    CHECK(T.relation("f") == string("great-great-grandfater"));
    CHECK(T.relation("g") == string("great-great-great-grandmother"));
    CHECK(T.relation("h") == string("great-great-great-great-grandfather"));
    CHECK(T.relation("i") == string("great-great-great-great-great-grandmother"));
    CHECK(T.relation("j") == string("great-great-great-great-great-great-grandfather"));
    CHECK(T.relation("k") == string("great-great-great-great-great-great-great-grandmother"));
    CHECK(T.relation("l") == string("great-great-great-great-great-great-great-great-grandfather"));
    CHECK(T.relation("m") == string("unrelated"));
    
    CHECK(T.find("me") == string("b"));
    CHECK(T.find("mother") == string("c")); 
    CHECK(T.find("grandfather") == string("d"));
    CHECK(T.find("great-grandmother") == string("e"));
    CHECK(T.find("great-great-grandfather") == string("f"));
    CHECK(T.find("great-great-great-grandmother") == string("g"));
    CHECK(T.find("great-great-great-great-grandfather") == string("h")); 
    CHECK(T.find("great-great-great-great-great-grandmother") == string("i"));
    CHECK(T.find("great-great-great-great-great-great-grandfather") == string("j"));
    CHECK(T.find("great-great-great-great-great-great-great-grandmother") == string("k"));
    CHECK(T.find("great-great-great-great-great-great-great-great-grandfather") == string("l"));
    
    CHECK(T.relation("b") == string("me"));
    CHECK(T.relation("c") == string("mother"));
    CHECK(T.relation("d") == string("grandfather"));
    CHECK(T.relation("e") == string("great-grandmother"));
    CHECK(T.relation("f") == string("great-great-grandfater"));
    CHECK(T.relation("g") == string("great-great-great-grandmother"));
    CHECK(T.relation("h") == string("great-great-great-great-grandfather"));
    CHECK(T.relation("i") == string("great-great-great-great-great-grandmother"));
    CHECK(T.relation("j") == string("great-great-great-great-great-great-grandfather"));
    CHECK(T.relation("k") == string("great-great-great-great-great-great-great-grandmother"));
    CHECK(T.relation("l") == string("great-great-great-great-great-great-great-great-grandfather"));
    CHECK(T.relation("m") == string("unrelated"));
    
    CHECK(T.find("me") == string("b"));
    CHECK(T.find("mother") == string("c")); 
    CHECK(T.find("grandfather") == string("d"));
    CHECK(T.find("great-grandmother") == string("e"));
    CHECK(T.find("great-great-grandfather") == string("f"));
    CHECK(T.find("great-great-great-grandmother") == string("g"));
    CHECK(T.find("great-great-great-great-grandfather") == string("h")); 
    CHECK(T.find("great-great-great-great-great-grandmother") == string("i"));
    CHECK(T.find("great-great-great-great-great-great-grandfather") == string("j"));
    CHECK(T.find("great-great-great-great-great-great-great-grandmother") == string("k"));
    CHECK(T.find("great-great-great-great-great-great-great-great-grandfather") == string("l"));
    
    CHECK(T.relation("b") == string("me"));
    CHECK(T.relation("c") == string("mother"));
    CHECK(T.relation("d") == string("grandfather"));
    CHECK(T.relation("e") == string("great-grandmother"));
    CHECK(T.relation("f") == string("great-great-grandfater"));
    CHECK(T.relation("g") == string("great-great-great-grandmother"));
    CHECK(T.relation("h") == string("great-great-great-great-grandfather"));
    CHECK(T.relation("i") == string("great-great-great-great-great-grandmother"));
    CHECK(T.relation("j") == string("great-great-great-great-great-great-grandfather"));
    CHECK(T.relation("k") == string("great-great-great-great-great-great-great-grandmother"));
    CHECK(T.relation("l") == string("great-great-great-great-great-great-great-great-grandfather"));
    CHECK(T.relation("m") == string("unrelated"));
    
    CHECK(T.find("me") == string("b"));
    CHECK(T.find("mother") == string("c")); 
    CHECK(T.find("grandfather") == string("d"));
    CHECK(T.find("great-grandmother") == string("e"));
    CHECK(T.find("great-great-grandfather") == string("f"));
    CHECK(T.find("great-great-great-grandmother") == string("g"));
    CHECK(T.find("great-great-great-great-grandfather") == string("h")); 
    CHECK(T.find("great-great-great-great-great-grandmother") == string("i"));
    CHECK(T.find("great-great-great-great-great-great-grandfather") == string("j"));
    CHECK(T.find("great-great-great-great-great-great-great-grandmother") == string("k"));
    CHECK(T.find("great-great-great-great-great-great-great-great-grandfather") == string("l"));
    
    CHECK(T.relation("b") == string("me"));
    CHECK(T.relation("c") == string("mother"));
    CHECK(T.relation("d") == string("grandfather"));
    CHECK(T.relation("e") == string("great-grandmother"));
    CHECK(T.relation("f") == string("great-great-grandfater"));
    CHECK(T.relation("g") == string("great-great-great-grandmother"));
    CHECK(T.relation("h") == string("great-great-great-great-grandfather"));
    CHECK(T.relation("i") == string("great-great-great-great-great-grandmother"));
    CHECK(T.relation("j") == string("great-great-great-great-great-great-grandfather"));
    CHECK(T.relation("k") == string("great-great-great-great-great-great-great-grandmother"));
    CHECK(T.relation("l") == string("great-great-great-great-great-great-great-great-grandfather"));
    CHECK(T.relation("m") == string("unrelated"));
    
    CHECK(T.find("me") == string("b"));
    CHECK(T.find("mother") == string("c")); 
    CHECK(T.find("grandfather") == string("d"));
    CHECK(T.find("great-grandmother") == string("e"));
    CHECK(T.find("great-great-grandfather") == string("f"));
    CHECK(T.find("great-great-great-grandmother") == string("g"));
    CHECK(T.find("great-great-great-great-grandfather") == string("h")); 
    CHECK(T.find("great-great-great-great-great-grandmother") == string("i"));
    CHECK(T.find("great-great-great-great-great-great-grandfather") == string("j"));
    CHECK(T.find("great-great-great-great-great-great-great-grandmother") == string("k"));
    CHECK(T.find("great-great-great-great-great-great-great-great-grandfather") == string("l"));
}