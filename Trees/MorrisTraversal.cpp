/*
Morris Traversal basically sets the temporary link between node and its predecessor we set 
predecessor->right = node 
i)we start with the root node 
ii)if there is left child of the node   
    1)we compute it's predecessor 
    2)check is there any link between node and its predecessor 
        a)if there's no link set the link and move to the left subtree
        b)if there's link break the link and go to the right subtree
iii)if there is no left child simply go to the right child
*/
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        val=0;
        left=right=NULL;
    }

    TreeNode(int x){
        val=x;
        left=right=NULL;
    }

    TreeNode(int x,TreeNode *left,TreeNode *right){
        val=x;
        this->left=left;
        this->right=right;
    }
};

class Solution{
    void morrisTraversal(TreeNode *root){
        TreeNode *predecessor;

        while(root!=NULL){
            if(root->left!=NULL){
                predecessor=root->left;
                while(predecessor->right!=NULL && predecessor->right!=root){
                    predecessor=predecessor->right;
                }

                if(predecessor->right==NULL){
                    //here we can do operation as per problem statment as here we're on intermediate nodes
                    predecessor->right=root;
                    root=root->left;
                }

                else{
                    //here we can do operaions if this is our leaf than 
                    if(predecessor->left==NULL){
                        //we can do our operation here
                    }

                    predecessor->right=NULL;
                    root=root->right;
                }
            }

            else{
                root=root->right;
            }
        }
    }
}