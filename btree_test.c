#include <stdio.h>
#include "btree.h"

int main(int argc, char ** arcgv)
{

	struct btree_node * tree;

	tree = make_btree(1, 1, 90);
	print_tree(tree);
	delete_tree(tree);
	
	tree = make_btree(3, 1, 90);
	print_tree(tree);
	delete_tree(tree);

	tree = make_btree(20, 1, 90);
	print_tree(tree);
	delete_tree(tree);

	tree = make_btree(40, 1, 80);
	print_tree(tree);
	delete_tree(tree);

	return 0;
}
