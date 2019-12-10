// AUTHOR: Michael Ziegler
// FILE: binadd.cpp / Binary addition program
// THIS PROGRAM:  Adds two or more binary numbers appearing as command-line
// arguments.  The resulting sum is sent to stdout.  The arguments are
// assumed to be well-formed (valid) binary numbers; no error checking
// is performed on the arguments.
//
//    For example:       binadd 100 1 1101 0
//    should print       10010
//
//  .    1    .    2    .    3    .    4    .    5    .    6    .    7    .
//3456789012345678901234567890123456789012345678901234567890123456789012345
                                                                        
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_DIGITS = 36;  // Maximum digits in (output) sum

bool Badd( const char augend[], const char addend[], char sum[] );
//         IN                   IN                   OUT


int main( int argc, char* argv[] )                   
//        IN        IN
{
	char   partialSum[MAX_DIGITS+1];   // Partial sum of the binary numbers
	char   sum[MAX_DIGITS+1];          // Sum of the binary numbers
	bool   noError;                    // No error flag

	// Exit if insufficient arguments were supplied.
	if (argc < 3)
	{
		cout << "Error: insufficient arguments.\n";
		return 1;
	}

	// Add together the first two binary numbers on the command-line.
	noError = Badd( argv[1], argv[2], sum );
		
	// Add any additional binary numbers to the partial sum.
	for (int counter = 3; noError && counter < argc; counter++)
	{
		strcpy( partialSum, sum );
		noError = Badd( partialSum, argv[counter], sum );
	}

	// Print answer on standard output.
	if (noError)
		cout << sum << endl;
	else
		cout << 'E' << endl;

	return 0;
} // end main


bool Badd( const char augend[], const char addend[], char sum[] )
{
//         IN                   IN                   OUT
// Pre:  augend and addend are strings representing valid binary numbers.
// Post: sum is a string representing the sum of augend + addend.
// Returns true if successful in addition, false otherwise.

	sum[0] = '0';
	sum[1] = '\0';

	int adj, adju;
	int carry, sizeDiff = 0;
	char addSpace[MAX_DIGITS+1];
	
	//adj variable to account for single digit accuracy in augend.
	//if (strlen(augend) > 0)
	//{
	//	adj = 1;
	//}
	//if (strlen(augend) == 1)
	//{
	//	adj = 0;
	//}
		
	//adju variable to account for single digit accuracy in addend.
	//if (strlen(addend) > 0)
	//{
	//	adju = 1;
	//}
	//if (strlen(addend) == 1)
	//{
	//	adju = 0;
	//}
	
	
	//Find Size Difference (sizeDiff). Case: aug > add.
	if (strlen(augend) > strlen(addend))
	{
		sizeDiff = (strlen(augend) - strlen(addend));
		
		for(int j = 0; j < sizeDiff; j++)
		{
				addSpace[j] = '0';
		}
		//Add the difference in space(as '0's) to augend.
		for (int i = 0; i < (MAX_DIGITS-sizeDiff); i++)
		{
			addSpace[sizeDiff + i] = addend[i] + 1;
		}
	}	
	
	
	//Find the Size Difference (sizeDiff). Case: add > aug.
	else
	{
		sizeDiff = (strlen(addend) - strlen(augend));
		
		for(int k = 0; k < sizeDiff + 1; k++)
		{
				addSpace[k] = '0';
		}
		//Add the difference in space (as '0's) to augend.
		for (int l = 0; l < (MAX_DIGITS-sizeDiff); l++)
		{
			addSpace[sizeDiff + l] = augend[l];
		}
	}
		
		
	//Begin arithmetic.
	if(strlen(addend) >= strlen(augend))
	{
		carry = 0;
		for(int i = strlen(addend)-1; i >= 0; i--)
		{
			//cout << "TEST1 : addend[" << i << "]-'0': " << (addend[i]-'0') << endl;
			//cout << "TEST1 : augend[" << i << "]-'0': " << (augend[i]-'0') << endl;
			
			if((augend[i]-'0') + (addend[i]-'0') + carry <= 0)
			{
				sum[i] = '0';
				carry = 0;
			}
			if((augend[i]-'0') + (addend[i]-'0') + carry == 1)
			{
				sum[i] = '1';
				carry = 0;
			}
			if((augend[i]-'0') + (addend[i]-'0') + carry == 2)
			{
				sum[i] = '0';
				carry = 1;
			}
			if((augend[i]-'0') + (addend[i]-'0') + carry == 3)
			{
				sum[i] = '1';
				carry = 1;
			}
		}
	}
	
	
	//length of augend > length of addend.
	else
	{
		carry = 0;
		
		for(int i = strlen(augend)-1; i >= 0; i--)
		{
			//cout << "TEST2 : addend[" << i << "]-'0': " << (addend[i]-'0') << endl;
			//cout << "TEST2 : augend[" << i << "]-'0': " << (augend[i]-'0') << endl;
			if((augend[i]-'0') + (addend[i]-'0') + carry == 0)
			{
				sum[i] = '0';
				carry = 0;
			}
			if((augend[i]-'0') + (addend[i]-'0') + carry == 1)
			{
				sum[i] = '1';
				carry = 0;
			}
			if((augend[i]-'0') + (addend[i]-'0') + carry == 2)
			{
				sum[i] = '0';
				carry = 1;
			}
			if((augend[i]-'0') + (addend[i]-'0') + carry == 3)
			{
				sum[i] = '1';
				carry = 1;
			}
		}
	}
	return true;
	
	//fix negative numbers from length differences
	for(int j = strlen(sum)-adj; j>=0; j--)
	{
		if((sum[j]-'0') < 0 && strlen(augend) > strlen(addend))
		{
			sum[j] = augend[j];
		}
		if((sum[j]-'0') < 0 && strlen(addend) > strlen(augend))
		{	
			sum[j] = addend[j];
		}
	}

} // end Badd
