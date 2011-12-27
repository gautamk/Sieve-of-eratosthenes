Sieve of eratosthenes
=====================

#### Implementation

This is a simple implementation of Sieve of eratosthenes.
It uses a byte array ( char array in `c`) for storage of prime numbers .
This is a _Bit Twiddling_ implementation.

#### Usage 
Refer the main method( _main_ function in `c` ) for general usage .

#### Working
The _initialize_ method initilizes the whole array with 0xff .

The _generate_ method sets _prime_ numbered bits as **1** and _composite_ numbered bits as **0** using **Sieve of eratosthenes algorithm**

So the _initilize_ method and then the _generate_ method have to be called before checking for primes. 


Google code Repo : http://code.google.com/p/bit-twiddling-sieve-of-eratosthenes/
