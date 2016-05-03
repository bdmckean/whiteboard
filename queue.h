#ifndef QUEUE_H
#define QUEUE_H

struct q {
	void * info;
	struct q * next;
	struct q * prev;
};


#endif
