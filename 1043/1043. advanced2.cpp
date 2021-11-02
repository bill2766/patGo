//https://blog.csdn.net/weixin_43878652/article/details/119710541

#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN=1e3+1;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode():left(NULL),right(NULL) {}
};

int N,preOrder[MAXN],inOrder[MAXN],flag,flagOut;
TreeNode* Create(int preLeft,int preRight,int inLeft,int inRight,int op) {
    if(flag!=1 || preLeft>preRight)
        return NULL;
    TreeNode* root = new TreeNode;
    root->data = preOrder[preLeft];
    int pos;
    for(pos=inLeft; pos<=inRight; pos++) {
        if(inOrder[pos]==preOrder[preLeft])
            break;
    }
    if(pos>inRight) {   // 不能构造一颗二叉排序树
        flag=0;
        return NULL;
    }
    if(op==0) {   // BST
        root->left = Create(preLeft+1,preLeft+(pos-inLeft),inLeft,pos-1,op);
        root->right = Create(preLeft+(pos-inLeft)+1,preRight,pos+1,inRight,op);
    } else {  // the mirror image of a BST
        root->left = Create(preLeft+1,preLeft+(inRight-pos),pos+1,inRight,op);
        root->right = Create(preLeft+(inRight-pos)+1,preRight,inLeft,pos-1,op);
    }
    return root;
}

//后序遍历
void Print(TreeNode* root) {
    if(root!=NULL) {
        Print(root->left);
        Print(root->right);
        if(flagOut==0)
            flagOut=1;
        else
            printf(" ");
        printf("%d",root->data);
    }
}
int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&preOrder[i]);
        inOrder[i] = preOrder[i];
    }
    sort(inOrder,inOrder+N);

    flag=1;
    TreeNode* root = Create(0,N-1,0,N-1,0);

    if(flag==1) {
        printf("YES\n");
        flagOut=0;
        Print(root);
    } else {
        //试试看是不是镜像的前序
        flag=1;
        root = Create(0,N-1,0,N-1,1);

        if(flag==1) {
            printf("YES\n");
            flagOut=0;
            Print(root);
        } else {
            printf("NO");
        }
    }
    printf("\n");
    return 0;
}