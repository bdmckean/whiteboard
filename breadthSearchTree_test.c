#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include "btree.h"

extern bool is_in_tree(struct btree_node * tree, int value);

void test(struct btree_node * b)
{
	char  input[100];
	int 	number;

	while(1){
		printf("What number to search for?->");
		fgets(input, 100, stdin);
		scanf(input,"%d",number);
		printf("\n");
		if (number < 0 || number > 1000 ) break;
		if (is_in_tree(b, number)) {
			printf("%d is in the tree", number);
		} else {
			printf("%d is not in the tree", number);
		}	
	}		

}


int main (int argc, char ** argv)
{
	struct btree_node * b;

        b = make_btree(40, 1, 80);
        print_tree(b);

	test(b);

        delete_tree(b);


	return 0;
}



