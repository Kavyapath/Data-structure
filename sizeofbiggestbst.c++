
#include<bits/stdc++.h>
using namespace std;
  
  struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isbst(TreeNode* root,TreeNode*min=NULL,TreeNode*max=NULL,int*count,int*size){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->val<=min->val){
        return false;

    }
    if(max!=NULL && root->val>=max->val){
        return false;
    }
    
    bool leftvalid=isbst(root->left,min,root,count,size);
    bool rightvalid=isbst(root->right,root,max,count,size);
         if(leftvalid || rightvalid){
            count++;
            if(size<count){
                size=count;
            }
            
        }
        else{
            count=0;
        }
       
    return leftvalid and rightvalid;


}
    
    int maxSumBST(TreeNode* root) {
        
        int count=0;
        int lsize=0;
        int rsize=0;
        TreeNode* min;
        TreeNode* max;
        bool leftvalid=isbst(root->left,min,max,&count,&lsize);
    bool rightvalid=isbst(root->right,min,max,&count,&rsize);
        if(leftvalid && rightvalid){
            return (lsize+rsize+1);
        }
        else{
            if(lsize>rsize){
                return lsize;
            }
            else{
                rsize;
            }
        }
            
    }
};