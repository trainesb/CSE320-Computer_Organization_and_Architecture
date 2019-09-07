/*
	Project08
	Ben Traines
	6/19/2018
	
	All error conditions return "0x80000000"

*/


#include "/user/cse320/Projects/project08.support.h"
#include <stdio.h>

int main(){
//NEGATE
	printf("\n----NEGATE( N )----\n");
	
	// ~(+)
	int N = 10;
	printf( "\nN: %d\n", N );
	int negated = negate( N );
	printf( "Negated: %d Hex: %08x\n", negated, negated );
	
	// ~(-)
	N = -10;
	printf( "\nN: %d\n", N );
	negated = negate( N );
	printf( "Negated: %d Hex: %08x\n", negated, negated );
	
	
	
	
//ABSOLUTE
	printf( "\n\n\n----ABSOLUTE( N )----\n");
	
	// |+|
	N = 10;
	printf( "\nN: %d\n", N );
	int absoluted = absolute( N );
	printf( "Absolute: %d Hex: %08x\n", absoluted, absoluted );
	
	// |-|
	N = -10;
	printf( "\nN: %d\n", N );
	absoluted = absolute( N );
	printf( "Absolute: %d Hex: %08x\n", absoluted, absoluted );
	
	
	
	
//ADD
	printf( "\n\n\n----ADD( A + B )----\n" );
	
	// (+) + (+)
	int A, B;
	A = 10;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	int added = add( A, B );
	printf( "Add: %d Hex: %08x\n", added, added );
	
	// (+) + (-)
	A = -10;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	added = add( A, B );
	printf( "Add: %d Hex: %08x\n", added, added );
	
	// (-) + (+)
	A = 10;
	B = -6;
	printf( "\nA: %d B: %d\n", A, B );
	added = add( A, B );
	printf( "Add: %d Hex: %08x\n", added, added );
	
	// (-) + (-)
	A = -10;
	B = -6;
	printf( "\nA: %d B: %d\n", A, B );
	added = add( A, B );
	printf( "Add: %d Hex: %08x\n", added, added );
	
	//Overflow
	A = 0x7fffffff;
	B = 0x00000002;
	printf( "\nA: %08x B: %08x\n", A, B );
	added = add( A, B );
	printf( "Add Overflow: %d Hex: %08x\n", added, added );
	
	
	
	
//SUB
	printf( "\n\n\n----SUB( B - A )----\n" );
	
	// (+) - (+)
	A = 10;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	int subed = sub( A, B );
	printf( "Sub: %d Hex: %08x\n", subed, subed );
	
	// (+) - (-)
	A = -10;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	subed = sub( A, B );
	printf( "Sub: %d Hex: %08x\n", subed, subed );
	
	// (-) - (+)
	A = 10;
	B = -6;
	printf( "\nA: %d B: %d\n", A, B );
	subed = sub( A, B );
	printf( "Sub: %d Hex: %08x\n", subed, subed );
	
	// (-) - (-)
	A = -10;
	B = -6;
	printf( "\nA: %d B: %d\n", A, B );
	subed = sub( A, B );
	printf( "Sub: %d Hex: %08x\n", subed, subed );
	
	//Overflow
	A = 0x60000001;
	B = 0x9fffffff;
	printf( "\nA: %08x B: %08x\n", A, B );
	subed = sub( A, B );
	printf( "Overflow: %d Hex: %08x\n", subed, subed );
	
	
	
	
//MUL
	printf( "\n\n\n----MUL( A * B )----\n");
	
	// + * +
	A = 10;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	int mult = mul( A, B );
	printf( "Mul: %d Hex: %08x\n", mult, mult );
	
	// + * -
	A = 10;
	B = -6;
	printf( "\nA: %d B: %d\n", A, B );
	mult = mul( A, B );
	printf( "Mul: %d Hex: %08x\n", mult, mult );
	
	// - * +
	A = -10;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	mult = mul( A, B );
	printf( "Mul: %d Hex: %08x\n", mult, mult );
	
	// - * -
	A = -10;
	B = -6;
	printf( "\nA: %d B: %d\n", A, B );
	mult = mul( A, B );
	printf( "Mul: %d Hex: %08x\n", mult, mult );
	
	// Overflow ( -*- )
	A = 0x7fffffff;
	B = 0x7fffffff;
	printf( "\nA: %d B: %d\n", A, B );
	mult = mul( A, B );
	printf( "Mul: %d Hex: %08x\n", mult, mult );
	
	// Overflow ( +*+ )
	A = 0x60000001;
	B = 0x60000001;
	printf( "\nA: %d B: %d\n", A, B );
	mult = mul( A, B );
	printf( "Mul: %d Hex: %08x\n", mult, mult );
	
	
	
		
//DIVIDE
	printf( "\n\n\n----DIVIDE( A \ B )----\n");

	// + / +
	A = 10;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	int divided = divide( A, B );
	printf( "Divide: %d Hex: %08x\n", divided, divided );
	
	// + / -
	A = 10;
	B = -6;
	printf( "\nA: %d B: %d\n", A, B );
	divided = divide( A, B );
	printf( "Divide: %d Hex: %08x\n", divided, divided );
	
	// - / +
	A = -10;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	divided = divide( A, B );
	printf( "Divide: %d Hex: %08x\n", divided, divided );
	
	// - / -
	A = -10;
	B = -6;
	printf( "\nA: %d B: %d\n", A, B );
	divided = divide( A, B );
	printf( "Divide: %d Hex: %08x\n", divided, divided );
	
	// + / 0
	A = 10;
	B = 0;
	printf( "\nA: %d B: %d\n", A, B );
	divided = divide( A, B );
	printf( "Divide: %d Hex: %08x\n", divided, divided );
	
	// 0 / 0
	A = 0;
	B = 0;
	printf( "\nA: %d B: %d\n", A, B );
	divided = divide( A, B );
	printf( "Divide: %d Hex: %08x\n", divided, divided );
	
	// 0 / +
	A = 0;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	divided = divide( A, B );
	printf( "Divide: %d Hex: %08x\n", divided, divided );
	
	
	
//REMAIN
	printf( "\n\n\n----REMAIN( A \ B )----\n");

	// + / +
	A = 10;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	int remainder = remain( A, B );
	printf( "Remains: %d Hex: %08x\n", remainder, remainder );
		
	// + / -
	A = 10;
	B = -6;
	printf( "\nA: %d B: %d\n", A, B );
	remainder = remain( A, B );
	printf( "Remains: %d Hex: %08x\n", remainder, remainder );
	
	// - / +
	A = -10;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	remainder = remain( A, B );
	printf( "Remains: %d Hex: %08x\n", remainder, remainder );
	
	// - / -
	A = -10;
	B = -6;
	printf( "\nA: %d B: %d\n", A, B );
	remainder = remain( A, B );
	printf( "Remains: %d Hex: %08x\n", remainder, remainder );
	
	// + / 0
	A = 10;
	B = 0;
	printf( "\nA: %d B: %d\n", A, B );
	remainder = remain( A, B );
	printf( "Remains: %d Hex: %08x\n", remainder, remainder );
	
	// 0 / 0
	A = 0;
	B = 0;
	printf( "\nA: %d B: %d\n", A, B );
	remainder = remain( A, B );
	printf( "Remains: %d Hex: %08x\n", remainder, remainder );
	
	// 0 / +
	A = 0;
	B = 6;
	printf( "\nA: %d B: %d\n", A, B );
	remainder = remain( A, B );
	printf( "Remains: %d Hex: %08x\n", remainder, remainder );
	
	
	
	
//POWER
	printf( "\n\n\n----POWER( N ^ I )----\n");
	
	// +^+
	N = 2;
	int I = 2;
	printf( "\nN: %d I: %d\n", N, I );
	int powered = power( N, I );
	printf( "Power: %d Hex: %08x\n", powered, powered );
	
	// +^-
	N = 2;
	I = -2;
	printf( "\nN: %d I: %d\n", N, I );
	powered = power( N, I );
	printf( "Power: %d Hex: %08x\n", powered, powered );
	
	// -^+
	N = -2;
	I = 2;
	printf( "\nN: %d I: %d\n", N, I );
	powered = power( N, I );
	printf( "Power: %d Hex: %08x\n", powered, powered );
	
	// -^-
	N = -2;
	I = -2;
	printf( "\nN: %d I: %d\n", N, I );
	powered = power( N, I );
	printf( "Power: %d Hex: %08x\n", powered, powered );
	
	
	
	
//FACTORIAL
	printf( "\n\n\n----FACTORIAL( N! )----\n");
	
	// +!
	N = 2;
	printf( "\nN: %d\n", N );
	int factorialed = factorial( N );
	printf( "Factorial: %d Hex: %08x\n", factorialed, factorialed );
	
	// -!
	N = -2;
	printf( "\nN: %d\n", N );
	factorialed = factorial( N );
	printf( "Factorial: %d Hex: %08x\n", factorialed, factorialed );
	
	// 0!
	N = 0;
	printf( "\nN: %d\n", N );
	factorialed = factorial( N );
	printf( "Factorial: %d Hex: %08x\n\n\n", factorialed, factorialed );
}
