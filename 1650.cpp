// Similar Question: 160
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *a = p, *b = q;
        while(a!=b){
            a = a==NULL? q: a->parent;
            b = b==NULL? p: b->parent;
        }
        return a;
    }
};