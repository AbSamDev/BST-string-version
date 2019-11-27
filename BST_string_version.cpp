// This program is created by Abdul Samad 
//  BST (Binary Search Tree)

#include <iostream>
using namespace std;

class tNode
{
public:
    string data;
    tNode *left;
    tNode *right;
    };
class BST{
	public:
		tNode *root;
	public:
	
		BST(){
			root=NULL;
		}

tNode* insert(string x, tNode* t)
    {
    	int k = 0;
 //   	cout<<k << endl << x << endl << t->data;
    	
    	
        if(t == NULL)
        {
            t = new tNode;
            t->data = x;
            t->left = t->right = NULL;
        }
        else{
        	k = x.compare(t->data);
	        if(k==1){
	            t->left = insert(x, t->left);
	        }
	        else if(k==-1){
	            t->right = insert(x, t->right);
	        }
	    }
        return t;
    }

tNode *search(string d, tNode *t){
	if(t == NULL)
	return t;
	else if(t -> data == d)
	return t;
	else{
		if(t -> data < d)
		search(d , t -> right);
		else
		search(d , t -> left);
	}
}
void test(){
	cout<<root->right->data;
}

};
int main(){
	BST b;
	b.root=b.insert("C", b.root);
    b.insert("S", b.root);
    b.insert("B", b.root);
//	b.insert("S", b.root);
//	b.insert("S", b.root);
//	b.insert("S", b.root);
    b.test();
	return 0;
	

}
