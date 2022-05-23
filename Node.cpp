#include "Node.h"

Node::Node(Accident value)
{
    key = value; 
}

Accident Node::GetAccident()
{
    return key; 
}
