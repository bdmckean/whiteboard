#include <stdbool.h>
#include <stdio.h>

int main(int argc, char * * argv)
{
	return 0;
}


struct btree{
	int value;
	struct btree * left;
	struct btree * right;
};

struct q {
	struct btree * b;
	struct q * next;
};

struct q * thisq;
struct q * nextq;

void pushq(struct btree * b) {}
void pushnq(struct btree * b){}
bool q_elem(){ return false;}
struct btree * popq(){ return (struct btree * )NULL;}
void swapq(){}
void freeqs(){}
void initq(struct q * q){}

bool is_in_tree(struct btree * node, int v)
{
	if( node == NULL) return false;
	bool found = false;
	initq(thisq); initq(nextq);
	pushq(node);
	while (q_elem())
	{
		struct btree * this_node = popq();
		if ( this_node->value == v ) 
		{
			found = true;
			break;	
		}
		if (this_node->left) pushnq(this_node->left);
		if (this_node->right) pushnq(this_node->right);
		if (!q_elem()) swapq();

	}
	freeqs();
	return found;
}


