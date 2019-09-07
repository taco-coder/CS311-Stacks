//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Tahwab Noori
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"

//Purpose of the program: To evaluate postfix expressions using a stack and to output any appropriate error messages
//Algorithm: while loop evaluating each char of an expression
int main()
{
	stack postfixstack;  // integer stack
	string expression;   // user entered expression

	cout << "type a postfix expression: ";
	cin >> expression;

	int i = 0;  // character position within expression
	char item;  // one char out of the expression
	int box1;  // receive things from pop
	int box2;  // receive things from pop
	int result; //result when 2 operands are correctly popped and operated on

	while (expression[i] != '\0')
	{
		try
		{
			item = expression[i];  // current char
			
			//2.  if it is an operand (number), 
			//    push it (you might get Overflow exception)
			if ((item >= 48) && (item <= 57)) {
				int elem = item - 48;
				postfixstack.push(elem);
			}

			//3.  else if it is an operator,
			//    pop the two operands (you might get Underflow exception), and
			//	apply the operator to the two operands, and
			//    push the result.
			else if ((item == '+') || (item == '-') || (item == '*'))
			{
				postfixstack.pop(box1);
				postfixstack.pop(box2);

				//cases for different operators follow:
				if (item == '-') { result = box2 - box1; }
				else if (item == '+') { result = box2 + box1; }
				else if (item == '*') { result = box2 * box1; }
				// ** Finally push the result		 
				postfixstack.push(result);
			}
			else throw "invalid item";
		} // this closes try

		  // Catch exceptions and report problems and quit the program now. 
		  // Error messages describe what is wrong with the expression.
		catch (stack::Overflow)
		{
			cout << "Error: Too many operands [OVERFLOW]" << endl;
			return 0;
		}
		catch (stack::Underflow) // for too few operands
		{
			cout << "Error: Too few operands [UNDERFLOW]" << endl;
			return 0;
		}
		catch (char const* errorcode) // for invalid item
		{
			cout << "Error: Invalid Item" << endl;
			return 0;
		}
		// go back to the loop after incrementing i
		i++;
	}// end of while

  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
	postfixstack.pop(result);
	// If anything is left on the stack, an incomplete expression was found.
	// Inform the user.
	if (!postfixstack.isEmpty()) {
		cout << "Error: Incomplete Expression" << endl;
		return 0;
	}
	else {
		cout << result << endl;
	}

}// end of the program
