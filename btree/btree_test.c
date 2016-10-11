#include "btree_if.h"


int main ( int argc, char ** argv){
    struct btree * b;


    b = btree_init();


    btree_insert(b,3);
    btree_print(b);
    btree_insert(b,5);
    btree_print(b);
    btree_insert(b,7);
    btree_print(b);
    btree_insert(b,1);
    btree_print(b);
    btree_insert(b,2);
    btree_print(b);
    btree_insert(b,0);
    btree_print(b);
    btree_insert(b,9);

    btree_print(b);

    return 0;
}
