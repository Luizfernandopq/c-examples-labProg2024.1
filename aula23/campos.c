#include <stdio.h>

struct bitCard {
unsigned face : 4;
unsigned suit : 2;
unsigned color : 1;
};

struct exemplo {
unsigned a : 13;
unsigned : 19;
unsigned b : 4;
};

struct exemplo1 {
unsigned a : 13;
//unsigned : 0;
unsigned b : 4;
};

int main(){
		struct bitCard b1;
	    printf("%ld\n", sizeof(b1));
		
		struct exemplo e;
	    printf("%ld\n", sizeof(e));

	    struct exemplo1 e1;
	   	printf("%ld\n", sizeof(e1));
	    
	
}
