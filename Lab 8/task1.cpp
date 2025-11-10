#include "iostream"
using namespace std;

class Node
{
public:
    string data;
    Node *mother;
    Node *father;
    int height;
    Node(string val)
    {
        data = val;
        father = mother = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;

    void displayLeafNodes(Node *root)
    {
        if (root == nullptr)
            return;

        if (root->mother == nullptr && root->father == nullptr)
        {
            cout << root->data << " ";
            return;
        }
        displayLeafNodes(root->mother);
        displayLeafNodes(root->father);
    }

    void printLevel(Node *node, int level)
    {
        if (node == nullptr)
            return;
        if (level == 1)
            cout << node->data << " ";
        else
        {
            printLevel(node->mother, level - 1);
            printLevel(node->father, level - 1);
        }
    }

    void displayRoot()
    {
        cout << "Root (Youngest Person): " << root->data << endl;
    }

    int height(Node *root)
    {
        if (root == NULL)
            return 0;

        int h1 = height(root->mother);
        int h2 = height(root->father);
        if (h1 > h2)
        {
            return h1 + 1;
        }
        else
        {
            return h2 + 1;
        }
    }
    void createFamily()
    {
        root = new Node("Amna");
        root->mother = new Node("linda");
        root->father = new Node("Saim");

        root->mother->mother = new Node("Alfiya");
        root->mother->father = new Node("Majid");
        root->father->mother = new Node("Ava");
        root->father->father = new Node("Noah");
    }

    void showAncestors()
    {
        cout << "\nAncestors with no known parents (Leaf Nodes): ";
        displayLeafNodes(root);
        cout << endl;
    }

    void showHeight()
    {
        cout << "\nHeight of the Family Tree: " << height(root) << endl;
    }

    void showLevels()
    {
        int h = height(root);
        cout << "\nLevels (Generations):\n";
        for (int i = 1; i <= h; i++)
        {
            cout << "Generation " << i << ": ";
            printLevel(root, i);
            cout << endl;
        }
    }
};
int main()
{
    BinaryTree family;
    family.createFamily();

    family.displayRoot();
    family.showAncestors();
    family.showHeight();
    family.showLevels();
}
