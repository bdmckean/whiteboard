#include <stdbool.h>    // bool
#include <stdio.h>      // NULL
#include <stdlib.h>     // malloc

#include "btree_if.h"

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct btree {
    struct node * root;
    int num_elements;
};

bool int_comp(void * d1, void * d2){
    int * x, * y;
    x = (int *)d1;
    y = (int *)d2;
    return *x > *y;
}

int int_print(void * d1){
    return printf("%d ",*((int *)d1) );
}

struct btree * btree_init(void){
    struct btree * myTree = (struct btree *)malloc(sizeof( struct btree));
    //ASSERT(myTree != NULL);
    myTree->root = NULL; 
    return myTree;
}

int btree_insert(struct btree * bt, int data){ 
    // ASSERT( bt != NULL)
    struct node * node = bt->root;
    struct node * new_node = (struct node * )malloc(sizeof(struct node));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    // ASSERT(new_node != NULL)
    
    if (bt->root == NULL) {
        bt->root = new_node;     
    } else {
        node = bt->root;
        while(true){
            if ( node->data < data ){
                if (node->left == NULL ) {
                    node->left = new_node;
                    break;
                } else {
                    node = node->left;
                    continue;
                }
            } else { // node->data <= data
                if ( node->right == NULL) {
                    node->right = new_node;
                    break;
                } else {
                    node = node->right;
                    continue;
                }
            }

        }
    } 
    return 0;
}

void print_nodes(struct node * n){
    //ASSERT (bt != NULL)
    if ( n->left != NULL){
       print_nodes(n->left); 
    }
    printf("%d ",n->data);
    if (n->right != NULL){
        print_nodes(n->right);
    }
}

void btree_print(struct btree * bt){
    // ASSERT (bt != NULL)
    printf("Btree->");
    print_nodes(bt->root);
    printf("\n");
}

void btree_print_levels(struct btree * bt){
    (struct btree * arr1)[1000];
    struct btree * arr2[1000];
    struct btree * this_level = arr1;
    struct btree * next_level = arr2;

    int num_1 = 0;
    int num_2 = 0;
    int * this_num = &num_1;
    int * next_num = &num_2;

    if (bt == NULL) return;

    struct node * node = bt;


    arr1[num_1] = bt;
    num_1++;

    this_level = arr1;
    this_num = &num_1;

    while( *this_num){
        printf("%d ",(this_level[*this_num])->data); 
        if ( this_level[*this_num])->left){
            next_level[*next_num]= this_level[*this_num])->left;
            *next_num++;
        }
        if ( this_level[*this_num])->right){
            next_level[*next_num]= this_level[*this_num])->right;
            *next_num++;
        }
        *this_num--
        if (*this_num == 0){
            printf("\n");
            int * tmpi = next_num;
            struct btree * tmpb = next_level;
            next_num = this_num;
            this_num = tmpi;
            next_level = this_level;
            this_level = tmpb; 
        }
    }

}
