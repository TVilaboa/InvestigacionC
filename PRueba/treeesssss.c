#include<stdlib.h>
#include<stdio.h>
#include "lightbulb.h"
#include "List.h"
struct bin_tree {
struct lightbulb data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, struct lightbulb val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val.type < (*tree)->data.type)
    {
        insert(&(*tree)->left, val);
    }
    else if(val.type > (*tree)->data.type)
    {
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree)
{
    if (tree)
    {
        printlightBulb(tree);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printlightBulb(tree);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printlightBulb(tree);
    }
}

void printlightBulb(node * tree){
    if(tree->data.active==1){
    printf("\nCode:%s\n",tree->data.code);
        printf("Watts:%d\n",tree->data.watts);
        printf("Type:%d\n",tree->data.type);
        printf("Stock:%d\n\n",tree->data.cant);
    }
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, struct lightbulb val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val.type < (*tree)->data.type)
    {
        search(&((*tree)->left), val);
    }
    else if(val.type > (*tree)->data.type)
    {
        search(&((*tree)->right), val);
    }
    else if(val.type == (*tree)->data.type)
    {
        return *tree;
    }
}

void main()
{
    node *root;
    List mylist;
    initlist(&mylist);
    root = NULL;
    int n=length(mylist);
    int i=0;
    for(i;i<n;i++){


        insert(&root,getitem(mylist,i));
    }





    int menu;
    do{printf("\n\n1- Add lightbulb \n2- Delete lightbulb \n3- Edit lightbulb \n4- Print tree\n5- Compress tree\n\n");
    scanf("%d",&menu);
    switch(menu){
    case 1: addbulb(&root); break;
    case 2: deletebulb(root); break;
    case 3: editbulb(root);break;
    case 4: printtree(root);break;
    case 5: compresstree(root);break;
    }}
     while(menu<6);
}

void addbulb(node ** root){
    struct lightbulb bulb;
    createBulb(&bulb);
    insert(root, bulb);

}

void deletebulb(node * root){
    struct lightbulb find;
    createBulb(&find);
    node *tmp;
    tmp = search(&root, find);
    if (tmp)
    {
        tmp->data.active=0;
        printf("Data succesfully deleted.\n");
    }
    else
    {
        printf("Data Not found in tree.\n");
    }

}

void editbulb(node * root){
    struct lightbulb find;
    createBulb(&find);
    node *tmp;
    tmp = search(&root, find);
    if (tmp)
    {
        printf("\nInsert new values\n");
        createBulb(&root->data);
        printf("Data succesfully edited.\n");
    }
    else
    {
        printf("Data Not found in tree.\n");
    }

}

void printtree(node *root){
    printf("Pre Order Display\n");
    print_preorder(root);

    printf("In Order Display\n");
    print_inorder(root);

    printf("Post Order Display\n");
    print_postorder(root);
}

void compresstree(node *root){
        node *newroot;
        newroot=NULL;
        compress(root,newroot);
        root=newroot;

}

void compress(node *tree,node *newroot){
    if (tree)
    {
        insert(&newroot,tree->data);
        compress(tree->left,newroot);
        compress(tree->right,newroot);

    }
}


