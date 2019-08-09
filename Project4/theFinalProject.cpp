#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
using namespace std;

int main() {
    //Seed for random leaves (nodes)
    srand (0);

    //Setup the root leaf (node)
    const static int rootValue = 2000;

    // Setup the leaves to sprout and die (nodes to insert and delete)
    int newLeaves [12];
    int deadLeaves [12];
    for(int i = 0; i < 12; i++) {
        newLeaves[i] = rand()%2000;
        if(i % 2 == 0)
            deadLeaves[i] = newLeaves[i];
        else
            deadLeaves[i] = rand()%2000;
    }

    //  Main Program
    cout << "Finding a seed..." << endl;
	Node* root = new Node(rootValue);
    cout << "Seed found. Planting seed " << rootValue  << "..." << endl;
	Tree tree(root);
	cout << "Tree Rooted. A sprout has begun. See?" << endl;
	tree.Print();
    for(int i = 0; i < 12; i++) {
        cout << "Tree is growing. Adding a " << newLeaves[i] << " to the tree." << endl;
        tree.Insert(newLeaves[i]);
        cout << "Tree may have grew some more! See below." << endl;
        tree.Print();
        cout << endl;
    }
    for(int i = 0; i < 20; i++) {
        cout << "Tree is dying. Deleting a " << newLeaves[i] << " from the tree." << endl;
        tree.Delete(deadLeaves[i]);
        cout << "Tree may have died a bit! See below." << endl;
        tree.Print();
        cout << endl;
    }

    //Cleanup
    delete root;

	return 0;
}