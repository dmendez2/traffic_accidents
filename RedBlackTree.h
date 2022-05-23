#include "Node.h"
#include <vector>
#pragma once

class RedBlackTree
{
private:
    Node* mainRoot = nullptr;
    void BalanceTree(Node* root, Node* node);
    void RotateLeft(Node* root, Node* node);
    void RotateRight(Node* root, Node* node);
    Node* Insert(Node* root, Node* node);
    Node* getUncle(Node* root);
    Node* getGrandparent(Node* root);
    void printingInorder(Node* root);
    //SEARCH FUNCTIONS
    Node* Search(Node* root, int severitytoFind);
    Node* GetmostSevereAccident(Node* root);
    Node* GetleastSevereAccident(Node* root);
    void GetXmostSevereAccidents(Node* root, int& numAccidents, vector<Node*>& Accidents);
    void GetXleastSevereAccidents(Node* root, int& numAccidnets, vector<Node*>& Accidents);
    void GetXmostSevereCityAccidents(Node* root, int& numAccidents, string city, vector<Node*>& Accidents);
    void GetXmostSevereStateAccidents(Node* root, int& numAccidents, string state, vector<Node*>& Accidents);
 

public:
   // ~RedBlackTree(); 
   // void DeleteTree(Node* root);
    RedBlackTree();
    void InsertNode(Node* newNode);
    Node* SearchNode(int severitytoFind);
    Node* FindMostSevereAccident();
    Node* FindLeastSevereAccident();
    void FindXMostSevereAccidents(int numAccidents, vector<Node*>& Accidents);
    void FindXLeastSevereAccidents(int numAccidents, vector<Node*>& Accidents);
    void FindXMostSevereAccidentsInCity(int numAccidents, string city, vector<Node*>& Accidents);
    void FindXMostSevereAccidentsInState(int numAccidents, string state, vector<Node*>& Accidents);
 

    //TESTING
    int treesize = 0;
    void PrintPreorder();
    void PrintPostorder();
    void PrintInorder();
};