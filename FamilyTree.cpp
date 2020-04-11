#include <iostream>
#include <string>
#include "FamilyTree.hpp"
using namespace std;


namespace family
{
    class Node;
    class Tree;
}

class family::Node
{
  private:
  string _name;
  string _relation;
  int _height; //branch height in the tree
  Node* _mother;
  Node* _father;
  public:
  Node()
  {
      _name = "";
      _relation = "";
      _mother = NULL;
      _father = NULL;
      _height = 0;
  }
  
  Node(string name, Node* mother, Node* father)
  {
      _name = name;
      _mother = mother;
      _father = father;
  }
  
  string getName()
  {
      return _name;
  }
  
  Node* getFather()
  {
      return _father; 
  }
  
  Node* getMother()
  {
      return _mother;
  }
  
  string getRelation()
  {
      return _relation;
  }
  
  int getHeight()
  {
      return _height;
  }
  
  void setFather(Node* father)
  {
      _father = father;
  }
  
  void setMother(Node* mother)
  {
      _mother = mother;
  }
  void setRelation(string str)
  {
      _relation = str;
  }
  void setHeight(int height)
  {
      _height = height;
  }
  
};


class family::Tree
{
    private:
    string _name;
    Node* _root;
    public:
    Tree(string name)
    {
        Node* node = new Node(name,NULL,NULL);
        _root = node; 
        _root->setRelation("me");
        _root->setHeight(0);
        _name = name;
    }
    string getRootName()
    {
        return _name;
    }
    Node* getRoot()
    {
        return _root;
    }
    void addFather(string childName ,string fatherName)
    {
        Node* newNode = new Node(fatherName,NULL,NULL);
        Node* childNode = findNode(_root,childName);
        if(childNode->getFather()==NULL)
        childNode->setFather(newNode);
        
        childNode->getFather()->setHeight(childNode->getHeight()+1);
        childNode->getFather()->setRelation(calcRelation('m',childNode->getFather()->getHeight()));
    }
    
    void addMother(string childName,string motherName)
    {
        Node* newNode = new Node(motherName,NULL,NULL);
        Node* childNode = findNode(_root,childName);
        if(childNode->getMother()==NULL)
        childNode->setMother(newNode);
        
        childNode->getMother()->setHeight(childNode->getHeight()+1);
        childNode->getMother()->setRelation(calcRelation('f',childNode->getMother()->getHeight()));
    }
    
    Node* findNode(Node* node, string name)
    {
        if(node == nullptr) return nullptr;
        if(node->getName() == name) return node;
        
        Node* found = findNode(node->getFather(),name);
        if(found != nullptr) return found;
        return findNode(node->getMother(),name);
    }
       
    string calcRelation(char gender,int height)
    {
        if(gender == 'm')
        {
            if(height == 1)
              return "father";
            else if(height == 2)
               return "grandfather";
               else
               {
                   string rel = "";
                   for(int i=0; i<height-2; i=i+1)
                    rel = rel + "great-";
                
                    return rel + "grandfather";
                    
               }
        }
        else
        {
            if(height == 1)
              return "mother";
            else if(height == 2)
              return "grandmother";
             else
               {
                   string rel = "";
                   for(int i=0; i<height-2; i=i+1)
                    rel = rel + "great-";
                
                    return rel + "grandmother";
               } 
        }
    }
    
    string relation(string name)
    {
        Node* node = findNode(_root,name);
        if(node == NULL)
          return "unrelated" ;
        else
          return node->getRelation();
    }
    
//https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/    
void print2DUtil(Node *root, int space)  
{  
    
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += 15;  
  
    // Process right child first  
    print2DUtil(root->getMother(), space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = 15; i < space; i++)  
        cout<<" ";  
    cout<<root->getName()<<"\n";  
  
    // Process left child  
    print2DUtil(root->getFather(), space);  
}  

//wrapper function
 void display()
 {
   print2DUtil(_root,0);
 }
 
 void remove(string name)
 {
     Node* node = findNode(_root,name);
     deleteNode(node);
 }
 
 void deleteNode(Node* node)  
{  
      if (node == NULL) return;
    /* first delete both subtrees */
    deleteNode(node->getFather());  
    deleteNode(node->getMother());  
    /* then delete the node */
    delete node;
    
    
}  



};




// int main() {
// 	family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
// 	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
// 	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
// 	 .addFather("Yaakov", "Isaac")
// 	 .addMother("Yaakov", "Rivka")
// 	 .addFather("Isaac", "Avraham")
// 	 .addFather("Avraham", "Terah");

// 	T.display();                        // displays the tree in a human-friendly format.

// 	cout << T.relation("Yaakov") << endl;  // prints "father"
// 	cout << T.relation("Rachel") << endl;  // prints "mother"
// 	cout << T.relation("Rivka") << endl;  // prints "grandmother"
// 	cout << T.relation("Avraham") << endl;  // prints "great-grandfather"
// 	cout << T.relation("Terah") << endl;  // prints "great-great-grandfather"
// 	cout << T.relation("xyz") << endl;  // prints "unrelated"
// 	cout << T.relation("Yosef") << endl;  // prints "me"

// 	 cout << T.find("mother") << endl;  // prints "Rachel"
// 	 cout << T.find("great-great-grandfather") << endl;  // prints "Avraham"
// 	 try {
// 	 	cout << T.find("uncle") << endl;  // throws an exception
// 	 } catch (const exception& ex) {
// 	  	cout << ex.what() << endl;  // prints "The tree cannot handle the 'uncle' relation"
// 	 }

// 	T.remove("Avraham"); // removes Avraham and Terah
// 	cout << T.relation("Terah") << endl;  // prints "unrelated"

//     return 0;
// }