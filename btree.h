#ifndef BTREE_H
#define BTREE_H

struct btree_node {
	int value;
	struct btree_node * left;
	struct btree_node * right;
	struct btree_node * parent;
};

struct btree2_node  {
	void * data;
	struct btree_node * left;
	struct btree_node * right;
	struct btree_node * parent;
};

struct btree_node * make_btree( int num_nodes, int seed, int prob_leaf);

void delete_tree(struct btree_node * b);

void print_tree(struct btree_node * b);

#endif
