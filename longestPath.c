
struct dep_task {
	struct task * dep_task;
	struct dep_task * next_dep;
};


struct task {
	int duration;
	struct dep_task * dep_list;
};


int main ( int argc, char ** argv ) 
{
	return 0;
}


int longest;
struct task * start;
struct task * end;
void find_longest_subpath(struct task * t, int l);

int find_longest(struct task * t)
{
	int this_length = 0;
	longest = 0;

	find_longest_subpath(t, this_length);
	return longest;
}

void find_longest_subpath(struct task * t, int l)
{
	struct dep_task * dep;
	
	l += t->duration;	
	if ( t == end ) {
		if ( l > longest ) longest = l;
	} else {
		dep = t->dep_list;
		while (dep) {
			find_longest_subpath( dep->dep_task, l);
			dep = dep->next_dep;
		}
	} 
}
