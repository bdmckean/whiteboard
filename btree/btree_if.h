#ifndef BTREE_IF
#define BTREE_IF

struct btree;

struct btree * btree_init(void);
int btree_insert(struct btree * bt, int d);
void btree_print(struct btree * bt);




#endif





