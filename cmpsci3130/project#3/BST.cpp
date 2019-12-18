#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int key;
    struct node *leftChild, *rightChild;
};

//Function to build a new node
struct node *newNode(int item)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->key = item;
    tmp->leftChild = tmp->rightChild = NULL;
    return tmp;
}

//Function to insert a new node with specific key value
struct node* insert(struct node* node, int key)
{
    if ( node == NULL)
    {
        return newNode(key);
    }
    if (key < node->key){
        node->leftChild = insert(node->leftChild, key);
    }
    else if (key > node->key){
        node->rightChild = insert(node->rightChild, key);
    }
    return node;
}

//Function inorder traversal
void inorder(struct node *root){
    if(root != NULL)
    {
        inorder(root->leftChild);
        cout << root->key << endl;
        inorder(root->rightChild);
    }
}

//Function preorder traversal
void preorder(struct node *root)
{
    if(root != NULL){
        cout << root->key << endl;
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

//Function postorder traversal
void postorder(struct node *root)
{
    if(root != NULL){
        postorder(root->leftChild);
        postorder(root->rightChild);
        cout << root->key << endl;
    }
}

//Function search key in BST
bool search(struct node* root, int key)
{
    while(root != NULL){
        cout << root->key <<endl;
        if(root->key < key){
            root = root->rightChild;
        }
        else if(root->key > key){
            root = root->leftChild;
        }
        else{
            return true;
        }
    }
    return false;
}

//Function minimum key value
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while(current->leftChild != NULL){
        current = current->leftChild;
    }
    return current;
}

//Functio delete a key value
struct node* deleteNode(struct node* root, int key)
{
    if(root == NULL){
        return root;
    }
    if(key < root->key){
        root->leftChild = deleteNode(root->leftChild, key);
    }
    else if(key > root->key){
        root->rightChild = deleteNode(root->rightChild, key);
    }
    else{
        if(root->leftChild == NULL){
            struct node *tmp = root->rightChild;
            free(root);
            return tmp;
        }
        else if(root->rightChild == NULL){
            struct node *tmp = root->leftChild;
            free(root);
            return tmp;
        }
        struct node * tmp = minValueNode(root->rightChild);
        root->key = tmp->key;
        root->rightChild = deleteNode(root->rightChild, tmp->key);
    }
    return root;
    
}

int main()
{
    int arr[10] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12};
    int choice;
    struct node *root = NULL;
    root = insert(root, arr[0]);
    do{
        cout << "Enter your choice between 1 to 11 " <<endl;
        cout << "1. Insert element from array into Binary Search Tree" <<endl;
        cout << "2. Display the result of Inorder traversal" <<endl;
        cout << "3. Display the result of Postorder traversal" <<endl;
        cout << "4. Display the result of Preorder traversal" <<endl;
        cout << "5. Search the key value 38" <<endl;
        cout << "6. Search the key value 9" <<endl;
        cout << "7. Delete the key value 10" <<endl;
        cout << "8. New Inorder traversal after deletion" <<endl;
        cout << "9. New Postorder traversal after deletion" <<endl;
        cout << "10. New Preorder traversal after deletion" <<endl;
        cout << "11. Exit program" <<endl;
        cin >> choice;
        
        switch(choice)
        {
            case 1: {
                for(int i = 1; i < 10; i++){
                    insert(root, arr[i]);
                }
                break;
            }
            case 2: { cout << "The inorder traversal is:" <<endl;
                inorder(root);
                break;
            }
            case 3: {cout << "The postorder traversal is:" <<endl;
                postorder(root);
                break;
            }
            case 4: {cout << "The preorder traversal is:" <<endl;
                preorder(root);
                break;
            }
            case 5: {cout << "The search result for 38 and keys examined are:" <<endl;
                if (search(root, 38)){
                    cout << "Yes the key value existed in the tree" <<endl;
                }
                else cout << "Not found" <<endl;
                break;
            }
            case 6: {cout << "The search result for 9 and keys examined are:" <<endl;
                if (search(root, 9)){
                    cout << "Yes the key value existed in the tree" <<endl;
                }
                else cout << "Not found" <<endl;
                break;
            }
            case 7: {deleteNode(root, 10);
                cout << "Key 10 is deleted" <<endl;
                break;
            }
                
            case 8: {root = deleteNode(root, 10);
                cout << "The inorder traversal after deleting key 10:" <<endl;
                inorder(root);
                break;
            }
            case 9: {root = deleteNode(root, 10);
                cout << "The postorder traversal after deleting key 10:" <<endl;
                postorder(root);
                break;
            }
            case 10: {root = deleteNode(root, 10);
                cout << "The preorder traversal after deleting key 10:" <<endl;
                preorder(root);
                break;
            }
            case 11: {cout << "Program terminated" <<endl;
                break;
            }
            default: cout << "Invalid choice." <<endl;
        }
        

    }while(choice != 11);
    return 0;
}
