#include <string>
#include <iostream>
using namespace std;

namespace family
{


class Tree
{
 
  class Node
{
  public:
  string _name;
  string _relation;
  int _height; //branch height in the tree
  Node* _mother;
  Node* _father;
  ////////////
   Node();
   string getName(){return _name;}
   Node* getFather(){return _father;}
   Node* getMother(){return _mother;}
   string getRelation(){return _relation;}
   int getHeight(){return _height;}
};

  
    
    Node* _root;
   
    public:
      Tree(string name);
      Node* getRoot();
      Tree addFather(string childName ,string fatherName);
      Tree addMother(string childName,string motherName);
      Node* findNode(Node* node, string name);
      string calcRelation(char gender,int height);
      string relation(string name);
      void print2DUtil(Node *root, int space);
      void display();
      void remove(string name);
      void deleteNode(Node* node);
      string find(string relation);
    
};
}

