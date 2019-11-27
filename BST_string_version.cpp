// This program is created by Abdul Samad 
//  BST (Binary Search Tree)

#include <iostream>
#include <fstream>
#include <windows.h>
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
void printInOrder(tNode *t){
	if(t!=NULL){
		printInOrder(t->left);
		cout<<endl<<t->data;
		printInOrder(t->right);
	}
}

};
int main(){
	system("color 8b");
	BST b;
	string line;
	int i = 1;
	ifstream myfile("dict.txt");
	if(myfile.is_open()){
		while(getline(myfile,line)){
			if(i == 1){
				b.root = b.insert(line,b.root);	
			}else{
				b.insert(line,b.root);
			}
			i++;
		}
		myfile.close();
	}
	else{
		cout<<"not opened filr";
	}
	b.printInOrder(b.root);
	

  
	return 0;
	

}
