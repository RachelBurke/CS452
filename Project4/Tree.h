
#include "Node.h"

using namespace std;

class Tree
{
private:
    // Attributes of a tree
    Node *root;

    // Functions for Insert and Delete
    // Insert - Absorb node a into node b
    void absorb(Node *a, Node *b)
    {
        if (b == root) //Adding a to root
        {
            // Create a new root called mega root
            Node *megaRoot = new Node();
            // Set left child of mega root to a
            megaRoot->addChild(a);
            // Set right child of mega root to b
            megaRoot->addChild(b);

            // Mega root is the new root
            megaRoot->setChildValues();
            root = megaRoot;
            return;
        }
        else //Adding a to a subroot
        {
            //Let p be the parent of b
            Node *p = b->getParent();
            //Add the child
            p->addChild(a);
            cout<< "Expand" << endl;
            //Simple Case of adding a child
            if (p->parent != NULL && p->childCount <= 3) //If my parent isn't root, adjust my subtree
                p->parent->adjustSubtree();
            else //Rebalance the subtree? (Recursive)
            {
                Node *pLeft = new Node();                         //New pLeft to absorb
                int leftChildren = p->childCount / 2;             //Count my left children
                int rightChildren = p->childCount - leftChildren; //Count my right children

                for (int i = 0; i < leftChildren; i++)
                {
                    pLeft->addChild(p->child[i]);             //Add left children to subtree of lefts
                    p->child[i] = p->child[i + leftChildren]; //Shifted the right children to the left in parent
                }

                if (leftChildren < rightChildren) //Odd number of children case shift
                    p->child[leftChildren] = p->child[p->childCount - 1];

                for (int x = rightChildren; x < p->childCount; ++x) //Remove copies of children (account for shift)
                    p->child[x] = NULL;

                p->childCount = rightChildren;
                p->setChildValues();
                absorb(pLeft, p);
            }
        }
    }

    // Delete - discard a from the tree
    void discard(Node *a)
    {
        // Let p be the parent of a
        Node *p = a->getParent();

        // Remove the connection between p and a by searching for a in the parent
        for (int i = 0; i < p->childCount; i++)
            if (p->child[i] == a)
                p->removeChild(i);

        // Cleanup
        delete a;

        bool recurse; 

        //Parent could remove child
        if (p->childCount >= 2){
            return;
        }
        else if (p->getParent() == NULL)    //Deleted the root value (2 case)
        {
            if (!p->child[0]->isLeaf())     //Set root to left child
            {
                root = p->child[0];
                delete (p);
            }
            return;
        }

        //Find the totnumber of children among all siblings of p
        Node *totchildren = p->getParent();
        int totalChildren = 0;
        int grandChild;

        //Calculate the total number of grandchildren
        for (int x = 0; x < totchildren->childCount; x++)
        {
            totalChildren += totchildren->child[x]->childCount;
            if (totchildren->child[x]->childCount == 1)
                grandChild = x;
        }

        if (totalChildren >= 4)
        {
            if (totchildren->childCount == 2)
                if (totchildren->child[0]->childCount == 3)
                    totchildren->shiftUp(0, 1);
                else
                    totchildren->shiftUp(1, 0);
            else if (totalChildren == 5)
                if (grandChild == 2)
                    totchildren->shiftUp(grandChild, 1);
                else
                    totchildren->shiftUp(grandChild, grandChild+1);
            else
                if (grandChild == 0)
                {
                    totchildren->shiftUp(1, 0);
                    if (totchildren->child[1]->childCount == 1)
                        totchildren->shiftUp(2, 1);
                }
                else if (grandChild == 2)
                {
                    totchildren->shiftUp(1, 2);
                    if (totchildren->child[1]->childCount == 1)
                        totchildren->shiftUp(0, 1);
                }
                else
                    if (totchildren->child[0]->childCount > totchildren->child[2]->childCount)
                        totchildren->shiftUp(0, 1);
                    else
                        totchildren->shiftUp(1, 1);
                    
        }
        else //Allocate b to the sibling of p
        {
            if (grandChild == 0)
                totchildren->shiftUp(0, 1);
            else
                totchildren->shiftUp(1, 0);
            discard(p);
            recurse = false;
        }

        if (recurse)
            totchildren->adjustSubtree();
    }

public:
    //Constructors:
    // Default constructor
    Tree()
    {
        root = NULL;
    }

    // Construct a tree at the given root
    Tree(Node *r)
    {
        root = r;
    }

    //2-3 Tree Functions:
    // Search
    Node *Search(Node *root, int valToFind)
    { //I found a leaf at least my value
        if (root->isLeaf())
            return root;

        // Find where in my node to recurse
        if (root->getLeft()->getValue() >= valToFind)
            return Search(root->getLeft(), valToFind);
        else if (root->middleExists() && root->getMiddle()->getValue() >= valToFind)
            return Search(root->getMiddle(), valToFind);
        else
            return Search(root->getRight(), valToFind);
    }

    // Insert
    void Insert(int valToAdd)
    {
        //new leaf a
        Node *a = new Node(valToAdd);
        Node *b = Search(root, valToAdd);
        if (a == b) //I already am in the tree
            return;
        else //Absorb me into the tree
            absorb(a, b);
    }

    // Delete
    void Delete(int valToRemove)
    {
        //Find a leaf at least my value in the tree
        Node *a = Search(root, valToRemove);

        //I exist in the tree so delete me
        if (a->getValue() == valToRemove)
            discard(a);
    }

    //Print Functions:
    // Print a 2-3 tree
    void Print() {
        print(root);
    }

    void print(Node * r) {
        //No Tree
        if(r == NULL)
            cout << "The seedling does not exist." << endl;
        else {
            Node * parent = r;
            if(parent->childCount < 2)
                cout << "One Child: " << parent->getValue() << endl;
            else if(parent->childCount == 2) {
                cout << "Two Child: " << parent->getLeft()->getValue() << " " << parent->getRight()->getValue() << endl;
                print(parent->getLeft());
                print(parent->getRight());
                cout << endl;
            }
            else {
                cout << "Three Child: " << parent->getLeft()->getValue() << " " << parent->getMiddle()->getValue() << " " << parent->getRight()->getValue() << endl;
                print(parent->getLeft());
                print(parent->getMiddle());
                print(parent->getRight());
                cout << endl;
            }
        }
    }
};