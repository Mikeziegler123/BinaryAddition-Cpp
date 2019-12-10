// AUTHOR: Michael Ziegler
// FILE: binadd.cpp / Binary Number Addition Program
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

5835 ranger2$ 
5835 ranger2$ 
5835 ranger2$ 
5835 ranger2$ ls
add  binadd.cpp  binaddStart.cpp  binredux.cpp  ola212  ola212.log  redux.dat
5836 ranger2$ 
5836 ranger2$ 
5836 ranger2$ 
5836 ranger2$ cat binredux.cpp
// OLA212 BY Michael Ziegler,  CSCI2170-002,  Due: 04/24/2018
// PROGRAM ID:  binaddredux / Binary Number Addition Program w/Deques
// AUTHOR:  Michael Ziegler
// INSTALLATION:  MIDDLE TENNESSEE STATE UNIVERSITY
// 
// REMARKS:  Reading from a file (redux.dat), this program adds two or
// more binary numbers appearing on a line terminated with an equal sign
// and displays the binary sum on stdout. The binary numbers are assumed
// to be well-formed (valid) binary numbers; no error checking is performed
// on the arguments.
//  .    1    .    2    .    3    .    4    .    5    .    6    .    7    .
//3456789012345678901234567890123456789012345678901234567890123456789012345
                                                                        
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
using namespace std;

typedef deque<char> bindeque;

void Badd(const bindeque augend, const bindeque addend, bindeque& sum);
//        IN                     IN                     OUT

// Return a C++ string as a char vector (bindeque)
bindeque conv(const string& s)
{
    return bindeque(s.begin(), s.end());
}

int main( int argc, char* argv[] )
//        IN        IN
{
	ifstream input("redux.dat");   // Input file
	bindeque term;                 // Binary term (number vector)
	bindeque partialSum;           // Partial sum of the binary numbers
	bindeque sum;                  // Sum of the binary numbers
	string binaryNumber;           // Binary term (number string)

	input >> binaryNumber;
	while (input)
	{
		cout << binaryNumber;
		sum = conv(binaryNumber);
		input >> binaryNumber;
		while (input && binaryNumber[0] != '=')
		{
			cout << " + " << binaryNumber;
			term = conv(binaryNumber);

			partialSum = sum;

			// Add together the two binary numbers
			Badd( partialSum, term, sum );
		
			input >> binaryNumber;
		}

		// Print answer on standard output.
		cout << " = ";
		for (char digit: sum)
			cout << digit;
		cout << endl;

		input >> binaryNumber;
	}
	input.close();
	return 0;
} // end main


void Badd(const bindeque augend, const bindeque addend, bindeque& sum)
//        IN                     IN                     OUT
// Pre:  augend and addend are char deques representing valid binary numbers.
// Post: sum is a char deque representing the sum of augend + addend.
{
	sum.clear();   // Empty (clear) sum
	int num1 = augend.size()-1;
	int num2 = addend.size()-1;
	int carry;
	string strSum = "";
	
	while(num1 >= 0 || num2 >= 0)
		{
		
		carry += ((num1 >= 0)? augend[num1]-48: 0);
		
		carry += ((num2 >= 0)? addend[num2]-48: 0);
		
		strSum = char((carry%2) + 48) + strSum;
		
		carry /= 2;
		--num1;
		--num2;
		
	}
	//LAST CARRY!
	if(carry==1)
	{
		strSum = '1' + strSum;
	}		
	sum.assign(strSum.begin(), strSum.end());
return;
} // end Badd
