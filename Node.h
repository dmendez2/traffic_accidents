#include <vector>
#include <string>
#include "Accidents.h"
#pragma once

using namespace std;
struct Node
{
    
    /*****************************TREE STRUCTURES**********************************/
    /*enum Color
    {
        black,
        red
    };
    */
    Accident key;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    bool color = false;
    Node(vector<string> InitialzationVector);
    Accident GetAccident();

    //TESTING
    Node(Accident value);
};