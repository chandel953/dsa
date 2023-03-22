#include <bits/stdc++.h>
using namespace std;

	struct Node
{
   int data;
   struct Node *left;
   struct Node *right;
};
Node* newnode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

	void pre(struct Node* root){
		if(root== NULL){
			return  ;
		}
		cout<<root->data<<" " ;
		pre(root->left) ;
		pre(root->right) ;
	}
	void post(struct Node* root){
		if(root== NULL){
			return  ;
		}
		pre(root->left) ;
		pre(root->right) ;
		cout<<root->data<<" " ;

	}
	void in(struct Node* root){
		if(root== NULL){
			return  ;
		}
		pre(root->left) ;
		cout<<root->data<<" " ;
		pre(root->right) ;
		
	}
	void lvl(struct Node* root,vector<vector<int>>&ans){
		queue<struct Node*>q ;
		q.push(root) ;
		if(root==NULL) return  ;
		while(!q.empty()){
			int n = q.size() ;
			
			vector<int>lvl ;
			for(int i= 0 ;i<n ;i++){
				struct Node* node = q.front() ;
				q.pop() ;
				if(node->left!=NULL) q.push(node->left) ;
				if(node->right!=NULL) q.push(node->right) ;
				lvl.push_back(node->data) ;
				// cout<<node->data ;

			}
			ans.push_back(lvl) ;

		}
	}

	void vertical(struct Node* root ,vector<vector<int>>&ver){
		map<int,map<int,multiset<int>>>nod ;
		queue<pair<struct Node* ,pair<int,int>>>q ;
		q.push({root ,{0 ,0}}) ;
		while(!q.empty()){
			auto it = q.front() ;
			q.pop() ;
			struct Node* node =it.first ;
			int x = it.second.first ;
			int y = it.second.second  ;
			nod[x][y].insert(node->data) ;
			if(node->left){
				q.push({node->left , {x-1  ,y+1}}) ;
			}
			if(node->right){
				q.push({node->right ,{x+1 ,y+1}}) ;
			}
		}
		for(auto it : nod){
			vector<int>col ;
			for(auto p : it.second){
				col.insert(col.end() ,p.second.begin() ,p.second.end()) ;
			}
			ver.push_back(col) ;
		}
	}
	int height(struct Node* root){
		if(root==NULL){
			return 0 ;
		}
		int lh = (height(root->left)) ;
		int rh = (height(root->right)) ;
		return (1 + max(lh,rh) ) ;
	}
	int size(struct Node* root){
		if(root==NULL){
			return 0 ;
		}
		else
		return (size(root->left) +1+ size(root->right)) ;
	
	}
	int main(){
		struct Node* root = newnode(1) ;
		root->right = newnode(2) ;
		root->left   = newnode(3) ;
		root->left->left = newnode(4) ;
		root->left->right = newnode(5) ;
		root->right->left = newnode(6) ;
		root->right->right = newnode(7) ;

		cout<<"preorder "<<endl  ;
		pre(root) ;
		cout<<endl ;
		cout<<"postorder "<<endl ;
		post(root) ;
		cout<<endl ;
		cout<<"inorder "<<endl  ;
		in(root) ;
			cout<<endl ;
		vector<vector<int>>ans ;
		cout<<"lvlorder"<<endl ;
		lvl(root ,ans);

		for (int i = 0; i <ans.size(); i++)
		{
			for(int j = 0 ;j<ans[i].size() ;j++){
				cout<<ans[i][j]<<" " ;
			}
			cout<<endl ;
		}
		cout<<"left view"<<endl ;
		for (int i = 0; i <ans.size(); i++)
		{
			for(int j = 0 ;j<ans[i].size() ;j++){
				if(j==0){
					cout<<ans[i][j]<<" " ;
				}
			}
			cout<<endl ;
		}
		cout<<"right view"<<endl ;
		for (int i = 0; i <ans.size(); i++)
		{
			for(int j = 0 ;j<ans[i].size() ;j++){
				if(j==ans[i].size()-1){
					cout<<ans[i][j]<<" " ;
				}
			}
			cout<<endl ;
		}
		cout<<"vertical"<<endl ;
		vector<vector<int>>ver ;
		vertical(root ,ver) ;
		for (int i = 0; i <ver.size(); i++)
		{
			for(int j = 0 ;j<ver[i].size() ;j++){
				
					cout<<ver[i][j]<<" " ;
				
			}
			cout<<endl ;
		}
			cout<<endl ;

		cout<<"height of a tree" ;
		cout<<height(root)<<endl ;
				cout<<"size of a tree" ;
		
		cout<<size(root)<<endl ;
		return 0 ;
	}
	
