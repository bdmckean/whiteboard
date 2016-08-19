#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char * * argv){

	char s[1000];

	scanf("%s",s);

	int count = 1;
	char unique[1000];
	int length = strlen(s);

	unique[0] = s[0];
	printf("Length = %d\n", length);
	for ( int i = 1; i < length; i++){
		for (int j = 0; j < count; j++){
			if (s[i] == unique[j]){
				break;
			}
			if (j == count-1){
				unique[count] = s[i];
				count++;
			}
		}
	}
	printf("method 1 = %d\n",count);
	bool found[256];
	count = 0;
	for (int i = 0; i < 256; i++) found[i] = false;
	for (int i = 0; i < length; i ++){
		if ( (int)s[i] >= 256 ) {
			printf("Error - not ascii!\n");
			return 1;
		}
		if ( !found[(int)s[i]]){
			found[(int)s[i]] = true;
			count++;
		}
	}
	printf("method 2 = %d\n",count);
					
	return 0;


}
