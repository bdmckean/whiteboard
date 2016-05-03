#include <stdlib.h> // NULL
#include <stdbool.h>

int main( int argc, char * * argv )
{

	return 0;

}

struct btree {
	int value;
	struct btree * left;
	struct btree * right;
	struct btree * parent;
};

bool is_in_large_tree( struct btree * b, int v)
{
	bool found = false;
	struct btree * n = b;

	if ( b == NULL ) return false;

	while (1){
		if (n->left){ n = n->left; continue; }
		// left most node check 
		if (n->value == v){ found = true; goto finish; }
		if (n->right) { n = n->right; continue;}
		while (1){
			if ( n == b ) {found = false; goto finish;}
			if ( n == n->parent->left){
				// I am the left node
				// check my parent next
				if (n->parent->value == v){
					found = true;
					goto finish;
				} 
			}
			// Checked left & parent try to go right
			if ( n->parent->right ){
				n = n->parent->right;
				break;
			}
			// No right -- go up one more level
			n = n->parent;
		}	
	}
finish:
	return found;
			
}

