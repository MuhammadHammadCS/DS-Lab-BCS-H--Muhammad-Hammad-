#include <iostream>
using namespace std;

class Node
{
    public:
    int playCount;
    string songName;
    Node *left;
    Node *right;
    Node(int p, string n)
    {
        playCount = p;
        songName = n;
        left = right = NULL;
    }
};

class BST
{
    public:
    Node *root;
    BST() 
    { 
        root = NULL; 
    }

    Node *insert(Node *root, int p, string n)
    {
        if (root == NULL)
        {
            return new Node(p, n);
        }
        if (p < root->playCount)
        {
            root->left = insert(root->left, p, n);
        }
        else if (p > root->playCount)
        {
            root->right = insert(root->right, p, n);
        }
        return root;
    }

    Node *search(Node *root, int p)
    {
        if (root == NULL || root->playCount == p)
        {
            return root;
        }
        if (p < root->playCount)
        {
            return search(root->left, p);
        }
        else
        {
            return search(root->right, p);
        }
    }

    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->songName << " (" << root->playCount << ")\n";
        inorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->songName << " (" << root->playCount << ")\n";
    }

    Node *findMin(Node *root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }

    Node *deleteNode(Node *root, int p)
    {
        if (root == NULL)
        {
            return root;
        }
        if (p < root->playCount)
        {
            root->left = deleteNode(root->left, p);
        }
        else if (p > root->playCount)
        {
            root->right = deleteNode(root->right, p);
        }
        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = findMin(root->right);
            root->playCount = temp->playCount;
            root->songName = temp->songName;
            root->right = deleteNode(root->right, temp->playCount);
        }
        return root;
    }

    void insertSong(int p, string n)
    {
        root = insert(root, p, n);
    }

    void searchSong(int p)
    {
        Node *res = search(root, p);
        if (res)
            cout << "Found: " << res->songName << " (" << res->playCount << ")\n";
        else
            cout << "Song not found\n";
    }

    void displayInorder()
    {
        inorder(root);
    }

    void displayPostorder()
    {
        postorder(root);
    }

    void deleteSong(int p)
    {
        root = deleteNode(root, p);
    }
};

int main()
{
    BST musicApp;
    musicApp.insertSong(50, "Crimson Flame");
    musicApp.insertSong(30, "Echoes of Time");
    musicApp.insertSong(70, "Neon Skies");
    musicApp.insertSong(20, "Midnight Drive");
    musicApp.insertSong(40, "Whispered Dreams");
    musicApp.insertSong(60, "Golden Horizon");
    musicApp.insertSong(80, "Silent Voyage");

    cout << "Inorder (Least to Most Played):\n";
    musicApp.displayInorder();

    cout << "\nPostorder (Reverse Popularity Removal):\n";
    musicApp.displayPostorder();

    cout << "\n\nSearching for play count 50:\n";
    musicApp.searchSong(50);

    cout << "\nDeleting song with play count 60:\n";
    musicApp.deleteSong(60);

    cout << "\nUpdated Inorder:\n";
    musicApp.displayInorder();

    return 0;
}
