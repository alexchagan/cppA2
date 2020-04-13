#include <iostream>
#include <string>
#include "FamilyTree.hpp"
using namespace std;
using namespace family;

    
    Tree::Tree(string name)
    {
       
    }
    
    
    Tree Tree::addFather(string childName ,string fatherName)
    {
        return *this;
    }
    
    Tree Tree::addMother(string childName,string motherName)
    {
        return *this;
    }
    
    
       
    
    string Tree::relation(string name)
    {
        
          return "nothing";
    }
    



 void Tree::display()
 {
   
 }
 
 void Tree::remove(string name)
 {
    
 }
 

string Tree::find(string relation)
{
    return "nothing";
}








