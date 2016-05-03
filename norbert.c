#include <stdbool.h>
#include <stdlib.h>

int main( int argc, char * * argv)
{



	exit(0);
}


struct io{
	int lba;
	int length;
	int wait_count;
	void (* call_back)();
	struct io * waiters;
	enum io_state { UNUSED, ACITIVE, WAITING, NEW } state;
};
struct io  sys_io[1000];


bool overlap( struct io * io1, struct io * io2 ){
	return true;
}
void add_io_to_waiters(struct io *wait_io, struct io *io){


}

int handle_io(struct io * this_io)
{
	struct io * tmp;
	int i;
	bool wait = false; 
	
	for (i = 0; i < 1000; i++){
		tmp = &(sys_io[i]);
		if (tmp->state != UNUSED &&
			tmp != this_io &&
				overlap(this_io, tmp) ) {
			if(wait == false) {
				wait = true;
				this_io->state = WAITING;
			}
			add_io_to_waiters(this_io, tmp);
			this_io->wait_count++;
			add_io_to_waiters(this_io, tmp);
		} 
	}	
	if ( wait == false ){
		this_io->call_back();
	}	
	return (0);
}
