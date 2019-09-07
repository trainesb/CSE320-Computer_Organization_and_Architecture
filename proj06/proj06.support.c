/*
 * Project06
 * Ben Traines
 * 6/8/18
 * 
 * void decode( unsigned int, char[] ): takes two paramaters, int that 
 * is a 32-bit value. The function then decodes this value into human
 * readable instructions. If they are real instructions, they are stored
 * in the array char[].
 */
#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"



void decode( unsigned int bits, char result[] ){
	
	
	unsigned int cond, copy_bits=bits;
	cond = (bits & 0xF0000000)>> 28;
	
	unsigned int num_Rn;
	num_Rn = (bits & 0x000F0000) >> 16;
	
	unsigned int num_Rd;
	num_Rd = (bits & 0x0000F000)>>12;
	
	unsigned int num_Rm;
	num_Rm = (bits & 0x0000000F);
	
	unsigned int num_im;
	num_im = (bits & 0x000000FF);

	int i;
	char binary[32];
	for (i=0; i<32; i++){
		if ((bits & 0x00000001) == 0x00000001){
			binary[i] = '1';
		}
		else{
			binary[i] = '0';
		}
		bits = bits >> 1;
	}
	
	if( (binary[27] & binary[26]) != '0' ){
		sprintf( result, "Error in Bit string: Bit 27:26 not 0 \n");

		return 0;
	}
	
	
	//check if bits 31:26 correct
	if( cond != 14 ){
		if( binary[3] && binary[4] == '0' ){
			sprintf( result, "Error in Bit string: Bits 31:26 (111000)\n");
			
			return 0;
		}
	}
	
	char i_bit = binary[25];
	
	char opcode[4];
	opcode[0] = binary[24];
	opcode[1] = binary[23];
	opcode[2] = binary[22];
	opcode[3] = binary[21];
	
	char s_bit = binary[20];

	
	//get Mnemonic from Opcode
	if(opcode[0] == '0'){
		if(opcode[1] == '0'){
			if(opcode[2] == '0'){
				if(opcode[3] == '0'){
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "ands", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "ands", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "and", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "and", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "and", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "and", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "ands", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "ands", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%20s  r%d,  r%d\n", copy_bits, "and", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "and", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "and", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "and", num_Rn, num_Rm );
							}
						}
					}
				}
				else{
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "eors", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "eors", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%20s  r%d,  r%d\n", copy_bits, "eor", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "eor", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "eor", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "eor", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "eors", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "eors", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%20s  r%d,  r%d\n", copy_bits, "eor", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "eor", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "eor", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "eor", num_Rn, num_Rm );
							}
						}
					}
				}
			}
			else{
				if( opcode[3] == '0' ){
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "subs", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "subs", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%20s  r%d,  r%d\n", copy_bits, "sub", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "sub", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "sub", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "sub", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "subs", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "subs", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%20s  r%d,  r%d\n", copy_bits, "sub", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "sub", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "sub", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "sub", num_Rn, num_Rm );
							}
						}
					}
				}
				else{
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "rsbs", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s r%d,  r%d\n", copy_bits, "rsbs", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%20s  r%d,  r%d\n", copy_bits, "rsb", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "rsb", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "rsb", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "rsb", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "rsbs", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "rsbs", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "rsb", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "rsb", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "rsb", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "rsb", num_Rn, num_Rm );
							}
						}
					}
				}
			}
		}
		else{
			if( opcode[2] == '0' ){
				if( opcode[3] == '0' ){
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "adds", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "adds", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "add", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "add", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "add", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "add", num_Rn, num_Rm );
							}
						}
					}	
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "adds", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "adds", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "add", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "add", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "add", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "add", num_Rn, num_Rm );
							}
						}
					}
				}
				else{
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "adcs", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "adcs", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "adc", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "adc", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "adc", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "adc", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "adcs", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "adcs", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "adc", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "adc", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "adc", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "adc", num_Rn, num_Rm );
							}
						}
					}
				}
			}
			else{
				if( opcode[3] == '0' ){
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "sbcs", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "sbcs", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "sbc", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "sbc", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "sbc", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "sbc", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "sbcs", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "sbcs", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "sbc", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "sbc", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "sbc", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "sbc", num_Rn, num_Rm );
							}
						}
					}
				}
				else{
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "rscs", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "rscs", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "rsc", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "rsc", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "rsc", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "rsc", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "rscs", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "rscs", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "rsc", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "rsc", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "rsc", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "rsc", num_Rn, num_Rm );
							}
						}
					}
				}
			}
			
		}
	}
	else{
		if( opcode[1] == '0' ){
			if( opcode[2] == '0' ){
				if( opcode[3] == '0' ){
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "tsts", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "tsts", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "tst", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "tst", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "tst", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "tst", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "tsts", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "tsts", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "tst", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "tst", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "tst", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "tst", num_Rn, num_Rm );
							}
						}
					}
				}
				else{
					if( i_bit == '1'){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "teqs", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s  r%d,  %#0x\n", copy_bits, "teqs", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "teq", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "teq", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "teq", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "teq", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "teqs", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "teqs", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "teq", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "teq", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "teq", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "teq", num_Rn, num_Rm );
							}
						}
					}
				}
			}
			else{
				if( opcode[3] == '0' ){
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "cmps", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "cmps", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "cmp", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "cmp", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "cmp", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "cmp", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s  r%d, r%d, r%d\n", copy_bits, "cmps", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s  r%d,  r%d\n", copy_bits, "cmps", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "cmp", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "cmp", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "cmp", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "cmp", num_Rn, num_Rm );
							}
						}
					}
				}
				else{
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "cmns", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "cmns", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "cmn", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "cmn", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "cmn", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "cmn", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "cmns", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "cmns", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "cmn", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "cmn", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "cmn", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "cmn", num_Rn, num_Rm );
							}
						}
					}
				}
			}
		}
		else{
			if( opcode[2] == '0' ){
				if( opcode[3] == '0' ){
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "orrs", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "orrs", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "orr", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "orr", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "orr", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "orr", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "n%x%20s r%d, r%d, r%d\n", copy_bits, "orrs", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "n%x%20s r%d,  r%d\n", copy_bits, "orrs", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "n%x%19s  r%d,  r%d\n", copy_bits, "orr", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "orr", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "orr", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "orr", num_Rn, num_Rm );
							}
						}
					}
				}
				else{
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "movs", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "movs", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "mov", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "mov", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "mov", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "mov", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "movs", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "movs", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "mov", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "mov", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "mov", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "mov", num_Rn, num_Rm );
							}
						}
					}
				}
			}
			else{
				if( opcode[3] == '0' ){
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "bics", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "bics", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "bic", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "bic", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "bic", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "bic", num_Rn, num_Rm );
							}
						}
					}
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "bics", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "bics", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "bic", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "bic", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "bic", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "bic", num_Rn, num_Rm );
							}
						}
					}
				}
				else{
					if( i_bit == '1' ){
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, %#0x\n", copy_bits, "mvns", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%20s r%d,  %#0x\n", copy_bits, "mvns", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "mvn", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, %#0x\n", copy_bits, "mvn", num_Rd, num_Rn, num_im );
								}
								else{
									sprintf( result, "%x%19s  r%d,  %#0x\n", copy_bits, "mvn", num_Rd, num_im );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "mvn", num_Rn, num_Rm );
							}
						}
					}	
					else{
						if( s_bit == '1' ){
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%20s r%d, r%d, r%d\n", copy_bits, "mvns", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%20s r%d,  r%d\n", copy_bits, "mvns", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "mvn", num_Rn, num_Rm );
							}
						}
						else{
							if( num_Rd != 0 ){
								if( num_Rn != 0 ){
									sprintf( result, "%x%19s  r%d, r%d, r%d\n", copy_bits, "mvn", num_Rd, num_Rn, num_Rm );
								}
								else{
									sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "mvn", num_Rd, num_Rm );
								}
							}
							else{
								sprintf( result, "%x%19s  r%d,  r%d\n", copy_bits, "mvn", num_Rn, num_Rm );
							}
						}
					}
				}
			}
		}
	}
}
