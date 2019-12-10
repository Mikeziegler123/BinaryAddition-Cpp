
// AUTHOR: Michael Ziegler
// FILE: Binary Number Addition Program w/Deque
// This PROGRAM:  Reads from a file (redux.dat), this program adds two or
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
