#include<bits/stdc++.h>
using namespace std; 
 vector<int> v;
struct Node 
{ 
    int key; 
    struct Node* left, *right; 
}; 
struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}; 
void inorder(struct Node* temp) 
{ 
    if (!temp)
        return; 
    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
} 
void deletedeepest(struct Node *root,struct Node *val)
{
    queue<struct Node*> q;
    q.push(root);
    while(!q.empty())
    {
        struct Node *temp=q.front();
        q.pop();
        if(temp->right)
        {
            if(temp->right==val)
            {
                temp->right=NULL;   
                delete(val);
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
        if(temp->left)
        {
            if(temp->left==val)
            {
                temp->left=NULL;
                delete(val);
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }
    }

}
void deletion(struct Node* root,int key)
{
    queue<struct Node*> q;
    q.push(root);
    struct Node *temp;
    struct Node *keynode=NULL;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->key==key)
            keynode=temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    int x=temp->key;
    deletedeepest(root,temp);
    keynode->key=x;
}
Node * InsertBST(struct Node *temp,int key)
{
    if(temp==NULL)
    {
        temp=newNode(key);
        return temp;
    }
    else
    {
        if(key<temp->key)
            temp->left=InsertBST(temp->left,key);
        if(key>temp->key)
            temp->right=InsertBST(temp->right,key);
        return temp;

    }
}
  
Node * insert(struct Node* temp, int key) 
{ 
    if (temp==NULL)
    {
        temp=newNode(key);
        return temp;
    }
    else
    {
    queue<struct Node*> q; 
    q.push(temp); 
        
        while (!q.empty()) 
        { 

        struct Node* temp = q.front(); 
        q.pop(); 
  
        if (!temp->left) 
        { 
            temp->left = newNode(key); 
            break; 
        } 
        else
            q.push(temp->left); 
  
        if (!temp->right) 
        { 
            temp->right = newNode(key); 
            break; 
        } 
        else
            q.push(temp->right); 
        }
    return temp; 
   } 
} 
    int size(struct Node * root)
    {
        if(root==NULL)
            return 0;

        else
        {
            int leftsize=size(root->left);
            int rightsize=size(root->right);
            return (leftsize+rightsize+1);
        }

    }
   
    int isize(struct Node * root)
    {
        int count =0;
        if(root==NULL)
            return 0;

        else
        {
            queue<struct Node*> q;
            q.push(root);

            while(!q.empty())
            {
                struct Node * temp=q.front();
                q.pop();
                count=count+1;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }

        }
        return count;
    }
    int compare(struct Node* root,struct Node * root1)
    {
        if(root==NULL && root1==NULL)
            return 1;
        if(root==NULL || root1==NULL)
            return 0;
        return(root->key==root1->key &&compare(root->left,root1->left) && compare(root->right ,root1->right));
    }
    int height(struct Node * root)
    {
        if(root ==NULL)
            return 0;
        else
        {
            int l=height(root->left);
            int r=height(root->right);
            return 1+max(l,r);
        }
    }
    void levelordert(struct Node* root)
    {
        queue<struct Node*> q;
        q.push(root);
        while(!q.empty())
        {
            struct Node *temp=q.front();
            q.pop();
            cout<<temp->key<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    void iterativein(struct Node* root)
    {
        struct Node * temp=root;
        stack<struct Node *> s;
        while(temp!=NULL || s.empty()==false)
        {
         while(temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;
            }
            temp=s.top();
            s.pop();
            cout<<temp->key<<" ";
            temp=temp->right;
        }
    }
    void iterativepre(struct Node * root)
    {
        struct Node * temp=root;
        stack<struct Node*> s;

        s.push(temp);
        while(!s.empty())
        {
            temp=s.top();
            cout<<temp->key<<" ";
            s.pop();
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
    }
    void iterativepost(struct Node * root)
    {
        struct Node * temp=root;
        stack <struct Node *> s1;
        stack <struct Node *> s2;
        s1.push(temp);
        while(!s1.empty())
        {
            temp=s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
        while(!s2.empty())
        {
            temp=s2.top();
            s2.pop();
            cout<<temp->key<<" ";
        }
    }
    Node * search(struct Node *temp,int key)
    {
        if(temp==NULL || temp->key==key)
            return temp;
        if(key>temp->key)
            return search(temp->right,key);
        if(key<temp->key)
            return search(temp->left,key);
    }
    Node* isBST(struct Node * temp)
    {
        int ans=1;
        if(temp==NULL)
            return NULL;
       
        isBST(temp->left);
       v.push_back(temp->key);
        isBST(temp->right);   
     }
     Node *lca(struct Node * temp,int a,int b)
     {
        if(temp->key>max(a,b))
            return lca(temp->left,a,b);
        else if(temp->key<min(a,b))
            return lca(temp->right,a,b);
        else
            return temp;
     }
int main() 
{ 
    int n,key;
    int choice;
    struct Node* root = NULL; 
    struct Node* root1=NULL;
    struct Node* root2=NULL;
    do
    {
    	cout<<"\n\n\t\tMain Menu"<<endl;
    	cout<<"**********************************************\n\n";
    	cout<<"\t1)Insertion 1\n\t2)Deletion\n\t3)Inorderrec\n\t4)Size\n\t5)Sizeiter\n\t6)Insertion 2\n\t7)Compare two trees\n\t8)Height of tree\n\t9)Level Order Traversal\n\t10)Iterative Inorder Traversal\n\t11)Iterative Preorder Traversal\n\t12)Iterative Postorder Traversal\n\t13)InsertBST\n\t14)Search\n\t15)Binary is BST\n\t16)Lowest common ancestor in BST\n\n";
    	cout<<"\t\tEnter your choice:--";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:{
    				    cout<<"\nEnter the no of nodes to insert into tree:--";
					    cin>>n;

					  
					    for(int i=0;i<n;i++)
					    {
					        cout<<"\nEnter the node value:--";
					      cin>>key;

					       root=insert(root, key); 
					    }
					    break;
                    }

            case 2:
                    {
                        cout<<"\nEnter the key to be delete from binary tree";
                        cin>>key;
                        deletion(root,key);
                    }

            case 3:
                    {
                        cout<<"\nRecursive Inorder Traversal:--";
                        inorder(root2);
                        break;
                    }

            case 4:
                    {
                        cout<<"\nSize of the tree is:--";
                        int s1=size(root);
                        cout<<s1<<endl;
                        break;
                    }

            case 5:
                    {
                        cout<<"\nSize of tree is iterative:--";
                        int s2=isize(root);
                        cout<<s2<<endl;
                        break;
                    }

            case 6:
                    {

                        cout<<"\nEnter the no of nodes to insert into tree:--";
                        cin>>n;

                      
                        for(int i=0;i<n;i++)
                        {
                            cout<<"\nEnter the node value:--";
                          cin>>key;

                           root1=insert(root1, key); 
                        }
                        break;
                    }

            case 7:
                    {
                        int c=compare(root,root1);
                        if(c==1)
                        {
                            cout<<"\nTrees are equal\n";
                        }
                        else
                        {
                             cout<<"\nTrees are not equal\n";
                        }
                         break;
                    }

            case 8:
                    {
                        int h=height(root);
                        cout<<"Height of tree is"<<h<<endl;
                        break;
                    }

            case 9:
                    {
                        levelordert(root);
                        break;
                    }

            case 10:
                    {
                       iterativein(root);
                       break;
                    }

            case 11:
                    {
                       iterativepre(root);
                       break;
                    }

            case 12:
                    {
                       iterativepost(root);
                       break;
                    }

            case 13:
                    {
                        cout<<"\nEnter the no of nodes to insert into Binary Search tree:--";
                        cin>>n;
                        for(int i=0;i<n;i++)
                        {
                            cout<<"\nEnter the node value:--";
                            cin>>key;
                            root2=InsertBST(root2,key); 
                        }
                        break;
                    }

            case 14:
                    {
                        cout<<"\nEnter the value to search:--";
                        cin>>key;
                        root2=search(root2,key);
                        if(root2==NULL)
                            cout<<"\nNO";
                        else
                            cout<<"\nYes";

                        break;
                    }

            case 15:
                    {

                        root=isBST(root);
                        if(is_sorted(v.begin(),v.end()))
                            {
                                cout<<"\nBinary tree is BST\n";
                            }
                        else
                        {
                            cout<<"\nBinary tree is not BST\n";
                        }
                        break;
                    }

            case 16:
                    {
                        int a,b;
                        cout<<"\nEnter the values of nodes:--";
                        cin>>a>>b;
                        root2=lca(root2,a,b);
                        cout<<root2->key<<" ";
                        break;
                    }


            case 0:
                        return 0;
		}

    }while(1);
   
   
  
    return 0; 
} 
