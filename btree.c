#include <stdio.h> // NULL
#include <stdlib.h> // rand()
#include <stdbool.h> // bool
#include <time.h> // clock()
#include <assert.h> // assert()
#include "btree.h"
#include "queue.h"

static int qcount = 0;
static struct q * q = NULL;

void initq(){
	q = NULL;
}

void pushq(void * info){

	struct q * tmp, * tmp2;
	tmp = (struct q *) malloc (sizeof (struct q));

	tmp->info = info;
	tmp->next = NULL;
	tmp->prev = NULL;
	qcount++;

	if ( q == NULL ) q = tmp;
	else {
		tmp2 = q;
		while (tmp2->next != NULL) tmp2 = tmp2->next; 
		tmp->prev = tmp2;
		tmp2->next = tmp;
	}

}

void * popq(){
	void * info;
	struct q * tmp;
	
	if ( q == NULL) return NULL;
	
	tmp = q;
	if ( tmp->next != NULL) {
		while ( tmp->next != NULL) tmp = tmp->next;
		tmp->prev->next = NULL;
	}
	info = tmp->info;
	free (tmp);
	qcount--;
	return info;
}

int qelem(void){
	return qcount;
}


struct btree_node * make_btree(int num_nodes, int seed, int prob_leaf)
{
	struct btree_node * root, * tmp, * tmp2, *tmp3; 
	int nodes = 0;

	if (seed) srand(seed);
	else srand(clock());

	if (!prob_leaf) prob_leaf = 90;

	if (num_nodes < 1 ) return NULL;

	tmp = (struct btree_node * )malloc(sizeof(struct btree_node));
	tmp->value = rand();
	tmp->right = tmp->left = tmp->parent = NULL;

	root = tmp;
	pushq(tmp);
	
	nodes = 1;	
	// root is set up
	while(nodes < num_nodes) {
		tmp = popq();
		
		tmp2 = NULL;
		tmp3 = NULL;
		// Set up leaf nodes -- mabe	
		if ( rand()%100 < prob_leaf ){
			tmp2 = (struct btree_node * )malloc(sizeof(struct btree_node));	
			tmp2->value =  rand();
			tmp2->parent = tmp;
			tmp2->left = tmp2->right = NULL;
			pushq(tmp2);
			nodes++;
		}
		if ( rand()%100 < prob_leaf ){
			tmp3 = (struct btree_node * )malloc(sizeof(struct btree_node));
			tmp3->value =  rand();
			tmp3->parent = tmp;
			tmp3->left = tmp3->right = NULL;
			pushq(tmp3);
			nodes++;
		}
		tmp->left = tmp2;	
		tmp->right = tmp3;

	}
	// Get rid of extra elements on the queue, we have enough nodes
	while (qelem()){
		tmp = popq();
	}
	return root;
	
}
void delete_tree(struct btree_node * b)
{
	if (!b ) return;
	if (b->left) delete_tree(b->left);
	if (b->right) delete_tree(b->right);	
	// No leaf nodes, delete this node
	// Delete pointers to this node if this is not the root
	if (b->parent != NULL){
		if (b->parent->left == b) {
			b->parent->left = NULL;
		} else {
			assert(b->parent->right == b);
			b->parent->right = NULL;
		}
	}
	// Free node
	free(b);
}
void print_tree(struct btree_node * b)
{
	int x,y;

	if (!b ) return;
	while (1) {
		x = y = -1;
		if ( b->left ) { pushq( b->left); x = b->left->value;}
		if ( b->right ){ pushq( b->right); y = b->right->value;} 
		printf( "%5d -> %5d, %5d\n", b->value, x, y );
		if (qelem()){
			b = popq();
		} else {
			break;
		}
	}

}
