#include <iostream>
#include <queue>
#include <stack>


struct Node {
   int data;
    Node* left, * right;

    Node(const int& data, Node* left = nullptr, Node* right = nullptr): data(data), left(left), right(left)
    {}

};

// top view task
struct NodePos {
    Node* n;
    int pos;
    NodePos(){}
    NodePos(Node* n, int pos ) : n(n),pos(pos){}
};

void topView(Node* root) {
    if(root != nullptr) {
        std::queue<NodePos> q;
        std::stack<Node*> topViewLeft;
        std::queue<Node*> topViewRight;
        q.push(NodePos(root,0));
        topViewLeft.push(root);
        int left = 0, right = 0;

        NodePos current;

        while(!q.empty()) {
            current = q.front();
            q.pop();
            if(current.n->left != nullptr){
                int newPos = current.pos - 1;
                if(newPos < left) {
                    left = newPos;
                    topViewLeft.push(current.n->left);
                }
                q.push(NodePos(current.n->left, newPos));
            }

            if(current.n->right != nullptr) {
                int newPos = current.pos + 1;
                if (newPos > right) {
                    right = newPos;
                    topViewRight.push(current.n->right);
                }
                q.push(NodePos(current.n->right, newPos));
            }
        }

        while(!topViewLeft.empty()) {
            std::cout << "%d , " << topViewLeft.top()->data << "\n";
            topViewLeft.pop();
        }
        while(!topViewRight.empty()) {
            std::cout << "%d , " << topViewRight.front()->data << "\n";
            topViewRight.pop();
        }
    }
}
// end of topview task

//lowest common anscestor task
Node* lca(Node* root, int v1, int v2) {
    if(root == nullptr) {return nullptr;}

    if(root->data > v1 && root->data > v2) {
        return lca(root->left, v1, v2);
    }
    
    if(root->data < v1 && root->data < v2) {
        return lca(root->right, v1, v2);
    }
    return root;
}


