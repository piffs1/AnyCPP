#include <iostream>
#include <queue>
/* My realisation binary tree.
* Need rework all structure of tree
* Check destructor
* Need upgrade BFS. OK
* Need rework functions with return Node<T>*
* Need add function remove and others
* Need rework static int nodes
* ---------------------------------------
* 15.10.2018
* realized BFS.
* realized height() of three
* added function remove only for node with 0-1 child
*/

using namespace std;

template<typename T>
struct Node // binary node
{
    static int count;
    T data;
    Node *pParent;
    Node *pLeft;
    Node *pRight;
    Node(T data = T(), Node *pParent = nullptr, Node *pLeft = nullptr, Node *pRight = nullptr)
    {
        this->data = data;
        this->pParent = pParent;
        this->pLeft = pLeft;
        this->pRight = pRight;
        count++;
    }
};
template<typename T>
int Node<T>::count=0; // for check nodes
template<typename T>
class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();
    void insert(const T &data);
    void remove(Node<T> *current);
    bool has(const T &data) const;
    Node<T>* find_min();
    Node<T>* find_max();
    Node<T>* find(const T &data) const;
    void InOrderPrint();
    void PreOrderPrint();
    void PostOrderPrint();
    void BFS();
    void DFS();
    int height() const; // height for root
    bool has2(const T &data);
    int countNodes() {return Node<T>::count;}

private:
    void clear();
    void clear(Node<T> *current);
    void InOrderPrint(Node<T> *current);
    void PreOrderPrint(Node<T> *current);
    void PostOrderPrint(Node<T> *current);
    void BFS(Node<T> *current);
    void DFS(Node<T> *current);
    int height(const Node<T> *current) const; //
    Node<T>* find_min(Node<T> *current);
    Node<T>* find_max(Node<T> *current);
    bool has2(const Node<T> *current, const T &data);
    Node<T> *root;
};
template<typename T>
Node<T>* BinaryTree<T>::find(const T &data) const
{
    if(root == nullptr) return nullptr;
    Node<T> *current = root;
    while(current->data!=data)
    {
        if(current->data > data)
        {
            if(current->pLeft==nullptr) return nullptr;
            current = current->pLeft;
        }
        if(current->data < data)
        {
            if(current->pRight==nullptr) return nullptr;
            current = current->pRight;
        }
    }
    return current;
}


template<typename T>
void BinaryTree<T>::remove(Node<T> *current)
{
    if(current->pLeft==nullptr && current->pRight==nullptr) //if current children are nullptr
    {
        Node<T>* parent = current->pParent;
        if(parent->pLeft == current)
        {
            parent->pLeft = nullptr;
        }
        if(parent->pRight == current)
        {
            parent->pRight = nullptr;
        }
        delete current;
        Node<T>::count--; // need rework later
    }
    if(current->pLeft==nullptr && current->pRight!=nullptr) // if current have 1 child(right)
    {
        Node<T> *parent = current->pParent; //take the parent
        Node<T> *kid = current->pRight; // take the kid
        if(parent->pLeft == current) // check parent left of right
        {
            parent->pLeft = kid;
        }
        if(parent->pRight == current)
        {
            parent->pRight = kid;
        }
        kid->pParent = parent; // link kid with parent
        delete current; // delete current node
        Node<T>::count--;
    }
    if(current->pLeft!=nullptr && current->pRight==nullptr) // if current have 1 child(left)
    {
        Node<T> *parent = current->pParent; //take the parent
        Node<T> *kid = current->pLeft; // take the kid
        if(parent->pLeft == current) // check parent left of right
        {
            parent->pLeft = kid;
        }
        if(parent->pRight == current)
        {
            parent->pRight = kid;
        }
        kid->pParent = parent; // link kid with parent
        delete current; // delete current node
        Node<T>::count--;
    }
}

template<typename T>
void BinaryTree<T>::insert(const T &data)
{
    if(!has(data))
    {
        Node<T> *newNode = new Node<T>(data);
        if(root==nullptr){root = newNode;return;}
        Node<T> *current = root;
        if(current->data > data && current->pLeft == nullptr) {newNode->pParent = root; root->pLeft = newNode;return;}//cout << "left kid " << newNode << " data " << newNode->data << ".Parent " << newNode->pParent << endl;return;}
        if(current->data < data && current->pRight == nullptr) {newNode->pParent = root; root->pRight = newNode;return;}//cout << "right kid " <<newNode << " data " << newNode->data << ".Parent " << newNode->pParent << endl;return;}
        //if(current->data == data) return;
        Node<T> *parent = root; /// current->pParent = parent. Чтобы не терялся указатель на отчий узел.
        while(current!=nullptr)
        {
            parent = current;
            if(parent->data > data)
                current = current->pLeft;
            if(parent->data < data)
                current = current->pRight;
            //if(parent->data == data) return;
        }
        //cout << "p " << parent << " data " << parent->data << " c " << newNode << " data " << newNode->data << endl;
        //current = newNode;
        newNode->pParent = parent;
        if(parent->data > data){parent->pLeft = newNode; }//return;}//связываем отчий узел с новым
        if(parent->data < data){parent->pRight = newNode; }//return;}
        //cout << "parent node. address node " << parent << ".Left child " << parent->pLeft << ".Right child " << parent->pRight << endl;
        //cout << "node created. address node " << newNode << ".Parent address " << newNode->pParent << endl;
    }
}

template<typename T>
bool BinaryTree<T>::has(const T &data) const
{
    if(root == nullptr) return false;
    Node<T> *current = root;
    while(current->data!=data)
    {
        if(current->data > data)
        {
            if(current->pLeft==nullptr) return false;
            current = current->pLeft;
        }
        if(current->data < data)
        {
            if(current->pRight==nullptr) return false;
            current = current->pRight;
        }
    }
    return true;
}

template<typename T>
int BinaryTree<T>::height() const
{
    if(root==nullptr) return 0;
    height(root);
}

template<typename T>
int BinaryTree<T>::height(const Node<T> *current) const
{
    int heightLeft=0,heightRight=0;
    if(current->pLeft!=nullptr)
        heightLeft = height(current->pLeft);
    if(current->pRight!=nullptr)
        heightRight = height(current->pRight);
    return(max(heightLeft,heightRight)+1); // +1 for
}


template<typename T>
bool BinaryTree<T>::has2(const T &data)
{
    cout << "HAS2(CTD)\n";
    if(root == nullptr) return false;
    if(root->data > data)
    {
        cout << "root->data " << root->data << endl;
        //if(root->pLeft==nullptr){if(root->data==data) return true;}
        cout << "TURN LEFT\n";
        //cout << has2(root->pLeft,data) << endl;
        return has2(root->pLeft,data);
    }
    if(root->data < data)
    {
        cout << "root->data " << root->data << endl;
        //if(root->pRight==nullptr){if(root->data==data) return true;}
        cout << "TURN RIGHT\n";
        //cout << has2(root->pRight,data) << endl;
        return has2(root->pRight,data);
    }
    if(root->data == data)
        return true;
}
template<typename T>
bool BinaryTree<T>::has2(const Node<T>* current,const T &data)
{
    //cout << "HAS2(CNC,CTD)\n";
    if(current == nullptr) return false;
    if(current->data > data)
    {
        //cout << "current->data " << current->data << endl;
        //if(current->pLeft==nullptr){if(current->data==data) return true;}
        //cout << "TURN LEFT\n";
        //cout << has2(root->pLeft,data) << endl;
        return has2(current->pLeft,data);
    }
    if(current->data < data)
    {
        //cout << "current->data " << current->data << endl;
        //if(current->pRight==nullptr){if(current->data==data) return true;}
        //cout << "TURN RIGHT\n";
        //cout << has2(root->pRight,data) << endl;
        return has2(current->pRight,data);
    }
    if(current->data == data)
        return true;
}

template<typename T>
Node<T>* BinaryTree<T>::find_min()
{
    if(root == nullptr)
        throw;
    if(root->pLeft == nullptr) return root;
    find_min(root->pLeft);
}

template<typename T>
Node<T>* BinaryTree<T>::find_min(Node<T> *current)
{
    if(current->pLeft == nullptr) return current;
    find_min(current->pLeft);
}
template<typename T>
Node<T>* BinaryTree<T>::find_max()
{
    if(root == nullptr)
        throw;
    if(root->pRight == nullptr) return root;
    find_max(root->pRight);
}

template<typename T>
Node<T>* BinaryTree<T>::find_max(Node<T> *current)
{
    if(current->pRight == nullptr) return current;
    find_max(current->pRight);
}

template<typename T>
void BinaryTree<T>::InOrderPrint()
{
    if (root == nullptr)
        return;
    InOrderPrint(root->pLeft);
    cout << root->data << ' '; ///
    InOrderPrint(root->pRight);
}
template<typename T>
void BinaryTree<T>::InOrderPrint(Node<T> *current)
{
    if (current == nullptr)
        return;
    InOrderPrint(current->pLeft);
    cout << current->data << ' ';
    InOrderPrint(current->pRight);
}
template<typename T>
void BinaryTree<T>::PreOrderPrint()
{
    if (root == nullptr)
        return;
    cout << root->data << ' ';
    PreOrderPrint(root->pLeft);
    PreOrderPrint(root->pRight);
}
template<typename T>
void BinaryTree<T>::PreOrderPrint(Node<T> *current)
{
    if (current == nullptr)
        return;
    cout << current->data << ' ';
    PreOrderPrint(current->pLeft);
    PreOrderPrint(current->pRight);
}
template<typename T>
void BinaryTree<T>::PostOrderPrint()
{
    if (root == nullptr)
        return;
    PostOrderPrint(root->pLeft);///
    PostOrderPrint(root->pRight);
    cout << root->data << ' ';
}
template<typename T>
void BinaryTree<T>::PostOrderPrint(Node<T> *current)
{
    if (current == nullptr)
        return;
    PostOrderPrint(current->pLeft);
    PostOrderPrint(current->pRight);
    cout << current->data << ' ';
}
template<typename T>
void BinaryTree<T>::DFS()
{
    if(root == nullptr)
        return;
    DFS(root);
}
template<typename T>
void BinaryTree<T>::DFS(Node<T> *current) //Depth-first search
{
    if (current == nullptr)
        return;
    cout << current->data << ' ';
    DFS(current->pRight);
    DFS(current->pLeft);
}
template<typename T>
void BinaryTree<T>::BFS()
{
    if (root == nullptr)
        return;
    BFS(root);
}
template<typename T>
void BinaryTree<T>::BFS(Node<T> *current) //upd later
{
    queue<Node<T>*> q;
    q.push(current);
    while(!q.empty())
    {
        Node<T> *cur = q.front();
        cout << cur->data << ' ';
        q.pop();
        if(cur->pLeft!=nullptr)
            q.push(cur->pLeft); // for(auto child : childs) push
        if(cur->pRight!=nullptr)
            q.push(cur->pRight);
    }
}

template<typename T>
void BinaryTree<T>::clear()
{
    if(root==nullptr) return;
    Node<T> *right = root->pRight;
    Node<T> *left = root->pLeft;
    delete root;
    Node<T>::count--;
    if(right!=nullptr)
        clear(right);
    if(left!=nullptr)
        clear(left);

}

template<typename T>
void BinaryTree<T>::clear(Node<T> *current)
{
    Node<T> *right = current->pRight;
    Node<T> *left = current->pLeft;
    delete current;
    Node<T>::count--;
    if(right!=nullptr)
        clear(right);
    if(left!=nullptr)
        clear(left);
}

template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
    clear();
    cout << "~BinaryTree(). Count nodes = " << countNodes() << endl;
}

int main(){
    BinaryTree<int> BT;
    setlocale(0,"");
    /*BT.insert(3);
    BT.insert(3);
    BT.insert(1);
    BT.insert(4);
    BT.insert(6);
    BT.insert(2);
    BT.insert(5);
    BT.insert(22);
    BT.insert(165);
    BT.insert(4);
    BT.insert(1);*/
    BT.insert(10);
    BT.insert(14);
    BT.insert(13);
    BT.insert(16);
    BT.insert(15);
    BT.insert(8);
    BT.insert(9);
    BT.insert(5);
    BT.insert(7);
    BT.insert(3);
    BT.insert(6);
    cout << "PreOrderPrint\t";
    BT.PreOrderPrint();
    cout << endl;
    cout << "InOrderPrint\t";
    BT.InOrderPrint();
    cout << endl;
    cout << "PostOrderPrint\t";
    BT.PostOrderPrint();
    cout << endl;
    cout << "Depth-F Search\t";
    BT.DFS();
    cout << endl;
    cout << "BF Search\t";
    BT.BFS();
    cout << endl;
    cout << "Height of tree is " << BT.height() << endl;
    cout << "BT.MIN IS " << BT.find_min()->data << endl;
    BT.remove(BT.find_min());
    cout << "BT.MIN IS " << BT.find_min()->data << endl;
    cout << "BT FIND(2323) " << BT.find(2323) << endl; // danger
    cout << "BT FIND(7) " << BT.find(7)->pParent->data << "->" << BT.find(7)->data << "->" << BT.find(7)->pLeft->data << endl;
    BT.remove(BT.find(7)); // check work
    cout << "BT FIND(7) " << BT.find(7) << endl; // ok. need rework
    cout << "BT.FIND(5) " << BT.find(5)->data << "->" << BT.find(5)->pRight->data << endl;
    cout << "Count nodes = " << BT.countNodes() << endl;

	return 0;
}
