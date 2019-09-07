#include "/user/cse320/Projects/project06.support.h"
#include <stdio.h>

int main(){
	unsigned int bit = 0xe086a007, bit2 = 0xA6, bit3 = 0xe096a007, bit4 = 0xe286a007, bit5 = 0xe1520003, bit6 = 0xe1a01003;
	char ary[80]={0}, ary2[80]={0}, ary3[80]={0}, ary4[80]={0}, ary5[80]={0}, ary6[80]={0};
	decode( bit, ary );
	printf( "Instruction		Human-readable form\n");
	int i;
	for(i=0; i<80; i++){
		printf( "%c", ary[i] );
	}
	
	decode( bit3, ary3 );

	for(i=0; i<80; i++){
		printf( "%c", ary3[i] );
	}
	
	decode( bit4, ary4 );

	for(i=0; i<80; i++){
		printf( "%c", ary4[i] );
	}	
	
	decode( bit5, ary5 );

	for(i=0; i<80; i++){
		printf( "%c", ary5[i] );
	}	
	
	decode( bit6, ary6 );

	for(i=0; i<80; i++){
		printf( "%c", ary6[i] );
	}
	
	decode( bit2, ary2 );

	for(i=0; i<80; i++){
		printf( "%c", ary2[i] );
	}
}
