#include <iostream>
using namespace std;

class Node
{
public:
    // Attributes of a node
    Node *parent;       //my parent
    Node *child[6];     //my children
    int childValues[6]; //my children's values
    int childCount;     //my number of children
    int value;          //my value

    //Constructors:
    // Default Constructor - constructs an empty node
    Node()
    {
        //No parent
        parent = NULL;
        //Setting nonexistent children leaves
        for (int x = 0; x < 6; x++)
        {
            child[x] = NULL;
            childValues[x] = -1;
        }
        //No children
        childCount = 0;
        //Not a leaf
        value = -1;
    }

    // Constructor with value
    Node(int val)
    {
        //No parent
        parent = NULL;
        //Setting nonexistent children leaves
        for (int x = 0; x < 6; x++)
        {
            child[x] = NULL;
            childValues[x] = -1;
        }
        //No children
        childCount = 0;
        //I am a leaf child equal to value
        value = val;
    }

    // Getters:
    //Get my left child
    Node *getLeft()
    {
        if (leftExists()) //I DO have a left child
            return child[0];
        else //I do NOT have a left child
            return NULL;
    }

    //Get my middle child
    Node *getMiddle()
    {
        if (middleExists()) //I DO have a middle child
            return child[1];
        else //I do NOT have a middle child
            return NULL;
    }

    //Get my right child
    Node *getRight()
    {
        if (middleExists()) //I DO have a right child (right of 3)
            return child[2];
        else if (rightExists()) //I DO have a left child (right of 2)
            return child[1];
        else //I do NOT have a right child (1 child)
            return NULL;
    }

    //Get my parent
    Node *getParent()
    {
        return parent;
    }

    //Get my value
    int getValue()
    {
        if (isLeaf()) //I am a leaf
            return value;
        else
        {
            if (childCount == 3) //3 children - "rightmost"
                return childValues[2];
            else if (childCount == 2) //2 children - "right"
                return childValues[1];
            else //1 child - "left"
                return childValues[0];
        }
    }

    //Setters:
    // Set my parent
    void setParent(Node *node)
    {
        parent = node;
    }

    // Set my child values
    void setChildValues()
    {
        for (int i = 0; i < 6; i++)
        {
            if (i < childCount)
                childValues[i] = child[i]->getValue();
            else
                childValues[i] = -1;
        }
    }

    //Helper Functions:
    // I am a leaf
    bool isLeaf()
    {
        if (value == -1) //I do not exist
            return false;
        else //I am an existing leaf
            return true;
    }

    // My left child exists
    bool leftExists()
    {
        if (isLeaf()) //I have no children
            return false;
        else //I have a left child
            return true;
    }

    // My middle child exists
    bool middleExists()
    {
        if (rightExists() && childCount > 2) //I have a middle child
            return true;
        else //I have no children
            return false;
    }

    // My right child exists
    bool rightExists()
    {
        if (leftExists() && childCount > 1) //I have a right child
            return true;
        else //I have no more than 1 child
            return false;
    }

    //Functions for Trees:
    // Add node to the parent
    void addChild(Node *node)
    {
        //Add node to the child list
        child[childCount++] = node;
        //Set the parent's value
        value = -1;
        //Set node's parent
        node->setParent(this);
        //Place children in sorted order
        if(childCount == 2)
            sort2(child[0], child[1]);
        if(childCount == 3)
            sort3(child[0], child[1], child[2]);
        if(childCount == 4)
            sort4(child[0], child[1], child[2], child[3]);
        //Reset Child Values
        setChildValues();
    }

    // Remove Child
    void removeChild(int pos)
    {
        //Removing the child by copying the children to the right
        childCount--;
        for (int x = pos; x < childCount; ++x)
        {
            child[pos] = child[pos + 1];
            childValues[pos] = childValues[pos + 1];
        }
        //Removing the last child (extra copy of last child)
        child[childCount] = NULL;
        childValues[childCount] = -1;
        return;
    }

    //Moves nodes in my parent's subtree around to adjust for my addition
    void adjustSubtree()
    {
        cout << " Adj" << endl;
        int myOldValue = getValue();
        setChildValues();
        int myNewValue = getValue();
        if (myOldValue != myNewValue && parent != NULL)
            parent->adjustSubtree();
    }

    //Shift my nodes
    void shiftUp(int oldChild, int newChild)
    {
        if (oldChild < newChild)
        {
            child[oldChild]->removeChild(child[oldChild]->childCount - 1);
            child[newChild]->addChild(child[oldChild]);
        }
        else
        {
            child[oldChild]->removeChild(0);
            child[newChild]->addChild(child[oldChild]);
        }
    }

    void sort2(Node *a, Node *b)
    {
        if (a->value > b->value)
        {
            Node *t = a;
            a = b;
            b = t;
        }
    }

    void sort3(Node *a, Node *b, Node *c)
    {
        sort2(a, b);
        sort2(a, c);
        sort2(b, c);
    }

    void sort4(Node *a, Node *b, Node *c, Node *d)
    {
        sort2(a, b);
        sort2(a, c);
        sort2(a, d);
        sort2(b, c);
        sort2(b, d);
        sort2(c, d);
    }
};