/* You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a
method to set all bits between i and j in N equal to M (e.g., M becomes a substring of
N located at i and starting at j).
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100 */

void setBits(int& N, int M, int i, int j) {
	M = M << i; // shift M i positions to the left 
			   // since M is a substring we don't need to worry about j
	N = N | M; // set the bits in N according to M 
	return;
}

/* Write a function to determine the number of bits required to convert integer A to
integer B.
Input: 31, 14
Output: 2 */

int numberOfBitsRequired(int A, int B) {
	int c = A ^ B; // number of different bits between A and B is equal to number of 1s in c
	int count = 0;
	for ( ; c >= 0; c = c >> 1 )
		count = count + (c & 1); 
	return count;
}