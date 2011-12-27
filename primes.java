/**
*
*
*/

class Primes {
	private final static int SIZE_OF_BYTE = 8;
	private final static int PRIME_CONTAINER_MAX = 1000000;
	private final static byte[] PRIME_CONTAINER= new byte[PRIME_CONTAINER_MAX];

	static void initializeContainer(){
		for(int i=0;i<PRIME_CONTAINER_MAX;i++){
			PRIME_CONTAINER[i] =(byte) 0xff;
		}
	}
	static void setBit(int bit_number){
		PRIME_CONTAINER[bit_number / SIZE_OF_BYTE ] |= (byte)(0x01 << (bit_number % SIZE_OF_BYTE));
	}
	static void unsetBit(int bit_number){
		PRIME_CONTAINER[ bit_number / SIZE_OF_BYTE ] &= (byte) ~(0x01 << (bit_number % SIZE_OF_BYTE));
	}
	static int getBit(int bit_number){
		int b =(int) PRIME_CONTAINER[bit_number / SIZE_OF_BYTE];
		b = b >> (bit_number % SIZE_OF_BYTE);
		b &= 0x01;
		return b;
	}

	static void generatePrimes(){
		int i,j;
		for(i=2;i<(PRIME_CONTAINER_MAX * SIZE_OF_BYTE);i++){
			for(j=2;i*j<(PRIME_CONTAINER_MAX * SIZE_OF_BYTE);j++){
				unsetBit(i*j);
			}			
		}
	}

	static boolean isPrime(int number){
		return number<2?
						false:
						getBit(number)==0 ? false : true;
	}
	public static void main(String [] Args){
		initializeContainer();
		generatePrimes();
		for (int i=0;i<1500000;i++){
			if(i%100 == 0) System.out.println();
			if(isPrime(i)){
				System.out.print(i+" ");
			}
		}
	}
}
