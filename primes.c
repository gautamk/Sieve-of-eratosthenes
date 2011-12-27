/*
	Bit Twiddling sieve of eratosthenes.

	This is a an implementation of sieve of eratosthenes.
	This stores the results in a char array .
	
	Each bit in the char array represents a number .
	
	The Generate function computes the prime numbers .

		If the bit is set the bit number is a prime number
		else it is composite.

		For Example bit 7 in PRIME CONTAINER would be set so 7 is a prime number 
		On the other hand Bit 10 would be unset so 10 is composite.

*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define PRIME_CONTAINER_MAX 1000000

/* Allocate 8 Million Bits(1 Million Bytes) */
unsigned char PRIME_CONTAINER[ PRIME_CONTAINER_MAX ];

/* Set all bits to 1 */
void initialize_container(){
	unsigned int i;
	for(i=0;i<PRIME_CONTAINER_MAX;i++){
		PRIME_CONTAINER[i] = 0xff;
	}
}

void set_bit(unsigned int bit_number ){
	/*
	bit_number / CHAR_BIT = byte number 
	bit_number % CHAR_BIT = bit number in the selected byte 
	0x01 = 0000 0001 
	*/
	PRIME_CONTAINER[bit_number / CHAR_BIT] |= (0x01 << (bit_number % CHAR_BIT ));
}

void unset_bit(unsigned int bit_number ){
	/*
	bit_number / CHAR_BIT = byte number 
	bit_number % CHAR_BIT = bit number in the selected byte 
	0xfe = 1111 1110
	*/
	PRIME_CONTAINER[ bit_number / CHAR_BIT ] &= ~(0x01 << (bit_number % CHAR_BIT ));
}

int get_bit(unsigned int bit_number){
	char byte = PRIME_CONTAINER[ bit_number/CHAR_BIT ];
	byte = byte >> (bit_number % CHAR_BIT);
	byte &= 0x01;
	return byte;
}

void generate_primes(){
	unsigned int i ,j;
	for(i=2;i< (PRIME_CONTAINER_MAX * CHAR_BIT) / 2 ;i++){
		if(get_bit(i) != 0 ){
			for(j=2;i*j<(PRIME_CONTAINER_MAX * CHAR_BIT);j++){
				unset_bit(i*j);
			}
		}		
	}	
}

int is_prime(unsigned int number){
	return number<2?0:get_bit(number);
}
int main(){
	int i;
	initialize_container();
	generate_primes();
	
	for(i=0;i<1500000;i++){
		if(i%100 == 0) printf("\n");
		if(is_prime(i) )
			printf("%d ",i);
	}
}