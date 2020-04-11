#include <string>
#include <iostream>
using namespace std;

class Node
{
  private:
  string _name;
  string _relation;
  int _height; //branch height in the tree
  Node* _mother;
  Node* _father;
  
  public:
   Node();
   Node(string name, Node* mother, Node* father);
   string getName();
   Node* getFather();
   Node* getMother();
   string getRelation();
   int getHeight();
   void setFather(Node* father);
   void setMother(Node* mother);
   void setRelation(string str);
   void setHeight(int height);
};

class Tree
{
  private:
    string _name;
    Node* _root;
   
    public:
      Tree(string name);
      string getRootName();
      Node* getRoot();
      void addFather(string childName ,string fatherName);
      void addMother(string childName,string motherName);
      Node* findNode(Node* node, string name);
      string calcRelation(char gender,int height);
      string relation(string name);
      void print2DUtil(Node *root, int space);
      void display();
      void remove(string name);
      void deleteNode(Node* node);
    
};


