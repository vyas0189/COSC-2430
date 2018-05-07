/*
Help from Sarah Syed
https://www.geeksforgeeks.org/sum-two-large-numbers/
https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
https://stackoverflow.com/questions/49270173/multidigits-postfix-expression/49271448#49271448
http://www.csegeek.com/csegeek/view/tutorials/algorithms/stacks_queues/stk_que_part5.php
https://www.geeksforgeeks.org/divide-large-number-represented-string/
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "StackHeader.h"
#include "ArgumentManager.h"
using namespace std;

//Check to see if the parantheses and the signs are balances.
//Postcondition: returns true or false if the  parantheses and the signs are balances.
bool AreParanthesesBalanced(string exp)
{
	Stack<char> s;
	int size = exp.length();
	int lastSub = 0;

	for (int i = 0; i < size; i++)
	{
		if (exp[i] == '(')
		{
			s.push(exp[i]);
		}
		else if ((exp[i] == ')') && (!s.isEmpty()))
		{
			s.pop();
		}
		// Check for unbalanced close parenthesis.
		else if ((exp[i] == ')') && (s.isEmpty()))
		{
			return false;
		}
		// Check for Double Negatives
		if (i != 0)
		{
			if ((exp[i] == '-') && (exp[i - 1] == '-'))
			{
				return false;
			}
		}
	}

	if (s.isEmpty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Sepeartes each operater and operands into seperate strings
//Postcondition: strArr will have an array of strings
void convertLineToStringArray(string &str, string *&strArr)
{
	int len = str.length();
	stringstream ss;
	strArr = new string[len];
	bool isSign = false;
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(str[i]))
		{
			if (i > 0 && (str[i] == '+' || str[i] == '-') && (str[i - 1] == ')'))
			{
				isSign = false;
			}
			else if (i > 0 && (str[i] == '+' || str[i] == '-') && !isdigit(str[i - 1]))
			{
				isSign = true;
			}
			if (i == 0 && (str[i] == '+' || str[i] == '-'))
			{
				isSign = true;
			}
			if (!isSign)
				ss << " " << str[i] << " ";
			else
				ss << str[i];
			isSign = false;
		}
		else
			ss << str[i];
	}
	int i = 0;
	string s;
	while (ss >> s)
	{
		strArr[i++] = s;
	}
}

//Return the the pritory of the operator
int getWeight(string ch)
{

	if (ch == "+" || ch == "-")
	{
		return 1;
	}
	else if (ch == "*" || ch == "/")
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

//Convert each expression to postfix
//Postcondition: Returns a string of array
void infixToPostfix(string *infix, int size, string *&post, int &num)
{
	Stack<string> s;
	int weight;
	int i = 0;
	int k = 0;
	string ch;

	post = new string[size];
	// iterate over the infix expression
	while (i < size && infix[i] != "")
	{
		ch = infix[i];
		if (ch == "(")
		{
			// simply push the opening parenthesis
			s.push(ch);
			i++;
			continue;
		}
		if (ch == ")")
		{
			// if we see a closing parenthesis,
			// pop of all the elements and append it to
			// the postfix expression till we encounter
			// a opening parenthesis
			while (!s.isEmpty() && s.top() != "(")
			{
				post[k++] = s.top();
				s.pop();
			}
			// pop off the opening parenthesis also
			if (!s.isEmpty())
			{
				s.pop();
			}
			i++;
			continue;
		}
		weight = getWeight(ch);
		if (weight == 0)
		{
			// we saw an operand
			// simply append it to postfix expression
			post[k] = ch;
			k++;
		}
		else
		{
			// we saw an operator
			if (s.isEmpty())
			{
				// simply push the operator onto Stack if
				// Stack is isEmpty
				s.push(ch);
			}
			else
			{
				// pop of all the operators from the Stack and
				// append it to the postfix expression till we
				// see an operator with a lower precedence that
				// the current operator
				while (!s.isEmpty() && s.top() != "(" &&
					weight <= getWeight(s.top()))
				{
					post[k++] = s.top();
					s.pop();
				}
				// push the current operator onto Stack
				s.push(ch);
			}
		}
		i++;
		num++;
	}
	// pop of the remaining operators present in the Stack
	// and append it to postfix expression
	while (!s.isEmpty())
	{
		post[k++] = s.top();
		s.pop();
		num++;
	}
}

//Changes the signs of the number
void changeSign(string &num)
{
	if (num[0] == '-')
	{
		num = num.substr(1, num.length() - 1);
	}
	else
	{
		num = "-" + num;
	}
}

//Fill in zeros in the numbers to have the same length
void placeZeros(string &num1, string &num2)
{
	if (num1.length() > num2.length())
	{
		int size = num1.length() - num2.length();
		for (int i = 0; i < size; i++)
		{
			num2 = "0" + num2;
		}
	}
	else if (num1.length() < num2.length())
	{
		int size = num2.length() - num1.length();
		for (int i = 0; i < size; i++)
		{
			num1 = "0" + num1;
		}
	}
}

//Clear all leading zeros
string finalAnswer(string &st)
{
	if (st[0] == '0')
	{
		int cut = st.find_first_not_of('0', 0);
		if (cut == string::npos)
		{
			return "0";
		}
		else
		{
			return st.substr(cut, st.length() - cut);
		}
	}
	else
	{
		return st;
	}
}

//Check if the number is postive or negative
bool negtive(string &num)
{
	if (num[0] == '-')
	{
		return true;
	}
	else
	{
		return false;
	}

	if (num[0] == '+')
	{
		num = num.substr(1, num.length() - 1);
	}
}

string addNumber(string &str1, string &str2)
{
	// Before proceeding further, make sure length
	// of str2 is larger.
	if (str1.length() > str2.length())
		swap(str1, str2);

	// Take an empty string for storing result
	string str = "";

	// Calculate lenght of both string
	int n1 = str1.length(), n2 = str2.length();
	int diff = n2 - n1;

	// Initialy take carry zero
	int carry = 0;

	// Traverse from end of both strings
	for (int i = n1 - 1; i >= 0; i--)
	{
		// Do school mathematics, compute sum of
		// current digits and carry
		int sum = ((str1[i] - '0') +
			(str2[i + diff] - '0') +
			carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	// Add remaining digits of str2[]
	for (int i = n2 - n1 - 1; i >= 0; i--)
	{
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	// Add remaining carry
	if (carry)
		str.push_back(carry + '0');

	// reverse resultant string
	reverse(str.begin(), str.end());

	return str;
}

string subtract(const string &n1, const string &n2)
{
	int len1 = n1.length();
	int carry = 0, num1, num2, answer;
	string result = "";

	for (int i = len1 - 1; i >= 0; i--)
	{
		num1 = n1[i] - '0';
		num2 = n2[i] - '0';
		num1 -= carry;

		if (num2 > num1)
		{
			carry = 1;
			num1 += 10;
		}
		else
		{
			carry = 0;
		}

		answer = num1 - num2;
		result = to_string(answer) + result;
	}
	return result;
}
string multiply(const string &num1, const string &num2)
{

	long long int n1 = num1.size();
	long long int n2 = num2.size();
	if (n1 == 0 || n2 == 0)
		return "0";

	// will keep the result number in vector
	// in reverse order
	vector<long long int> result(n1 + n2, 0);

	// Below two indexes are used to find positions
	// in result.
	int i_n1 = 0;
	int i_n2 = 0;

	// Go from right to left in num1
	for (int i = n1 - 1; i >= 0; i--)
	{
		long long int carry = 0;
		long long int n1 = num1[i] - '0';

		// To shift position to left after every
		// multiplication of a digit in num2
		i_n2 = 0;

		// Go from right to left in num2
		for (int j = n2 - 1; j >= 0; j--)
		{
			// Take current digit of second number
			long long int n2 = num2[j] - '0';

			// Multiply with current digit of first number
			// and add result to previously stored result
			// at current position.
			long long int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

			// Carry for next iteration
			carry = sum / 10;

			// Store result
			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}

		// store carry in next cell
		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		// To shift position to left after every
		// multiplication of a digit in num1.
		i_n1++;
	}

	// ignore '0's from the right
	long long int i = result.size() - 1;
	while (i >= 0 && result[i] == 0)
		i--;

	// If all were '0's - means either both or
	// one of num1 or num2 were '0'
	if (i == -1)
		return "0";

	// generate the result string
	string s = "";
	while (i >= 0)
		s += to_string(result[i--]);

	return s;
}

string divide(string number, string divs)
{
	unsigned long long int divisor = 0;

	stringstream ss(divs);
	ss >> divisor;
	// As result can be very large store it in string
	string ans;

	// Find prefix of number that is larger
	// than divisor.
	unsigned long long int idx = 0;
	unsigned long long int temp = number[idx] - '0';
	while (temp < divisor)
		temp = temp * 10 + (number[++idx] - '0');

	// Repeatedly divide divisor with temp. After
	// every division, update temp to include one
	// more digit.
	while (number.size() > idx)
	{
		// Store result in answer i.e. temp / divisor
		ans += (temp / divisor) + '0';

		// Take next digit of number
		temp = (temp % divisor) * 10 + number[++idx] - '0';
	}

	// If divisor is greater than number
	if (ans.length() == 0)
		return "0";

	// else return ans
	return ans;
}

string add(string &num1, string &num2)
{

	if (!(negtive(num1)) && !(negtive(num2)))
	{
		//placeZeros(num1, num2);
		string sum = addNumber(num1, num2);
		sum = finalAnswer(sum);
		return sum;
	}
	else if (!(negtive(num1)) && (negtive(num2)))
	{
		changeSign(num2);
		if (num2 > num1)
		{
			placeZeros(num1, num2);
			string sum = subtract(num2, num1);
			sum = finalAnswer(sum);
			changeSign(sum);
			return sum;
		}
		else
		{
			placeZeros(num1, num2);
			string sum = subtract(num1, num2);
			sum = finalAnswer(sum);
			return sum;
		}
	}
	else if ((negtive(num1)) && !(negtive(num2)))
	{
		changeSign(num1);
		if (num1 > num2)
		{
			placeZeros(num1, num2);
			string sum = subtract(num1, num2);
			sum = finalAnswer(sum);
			changeSign(sum);
			return sum;
		}
		else
		{
			placeZeros(num1, num2);
			string sum = subtract(num2, num1);
			sum = finalAnswer(sum);
			return sum;
		}
	}
	else if ((negtive(num1)) && (negtive(num2)))
	{
		changeSign(num1);
		changeSign(num2);
		//placeZeros(num1, num2);
		string result = addNumber(num1, num2);
		result = finalAnswer(result);
		changeSign(result);
		return result;
	}
}

string sub(string &n1, string &n2)
{
	if ((!negtive(n1)) && (!negtive(n2)))
	{
		placeZeros(n1, n2);
		if (n2 > n1)
		{
			string result = subtract(n2, n1);
			result = finalAnswer(result);
			changeSign(result);
			return result;
		}
		else
		{
			string result = subtract(n1, n2);
			result = finalAnswer(result);
			return result;
		}
	}
	else if ((negtive(n1)) && (!negtive(n2)))
	{
		changeSign(n1);
		placeZeros(n1, n2);
		string result = addNumber(n1, n2);
		result = finalAnswer(result);
		changeSign(result);
		return result;
	}
	else if ((!negtive(n1)) && (negtive(n2)))
	{
		changeSign(n2);
		placeZeros(n1, n2);
		string result = addNumber(n1, n2);
		result = finalAnswer(result);
		return result;
	}
	else if ((negtive(n1)) && (negtive(n2)))
	{
		changeSign(n1);
		changeSign(n2);
		placeZeros(n1, n2);
		if (n1 > n2)
		{
			string result = subtract(n1, n2);
			result = finalAnswer(result);
			changeSign(result);
			return result;
		}
		else
		{
			string result = subtract(n2, n1);
			finalAnswer(result);
			return result;
		}
	}
}

string mult(string num1, string num2)
{
	finalAnswer(num1);
	finalAnswer(num2);
	if ((num1 == "0") || (num2 == "0"))
	{
		return "0";
	}
	else if (num1 == "1")
	{
		return num2;
	}
	else if (num2 == "1")
	{
		return num1;
	}
	else
	{
		if ((!negtive(num1)) && (!negtive(num2)))
		{
			string result = multiply(num1, num2);
			result = finalAnswer(result);
			return result;
		}
		else if (negtive(num1) && !negtive(num2))
		{
			changeSign(num1);
			string result = multiply(num1, num2);
			result = finalAnswer(result);
			changeSign(result);
			return result;
		}
		else if (!negtive(num1) && negtive(num2))
		{
			changeSign(num2);
			string result = multiply(num1, num2);
			result = finalAnswer(result);
			changeSign(result);
			return result;
		}
		if (negtive(num1) && negtive(num2))
		{
			changeSign(num1);
			changeSign(num2);
			string result = multiply(num1, num2);
			result = finalAnswer(result);
			return result;
		}
	}
}

string div(string &n1, string &n2)
{
	if (n2 == n1)
	{
		return "1";
	}

	if ((!negtive(n1)) && (!negtive(n2)))
	{
		string result = divide(n1, n2);
		result = finalAnswer(result);
		return result;
	}
	else if (negtive(n1) && !negtive(n2))
	{
		changeSign(n1);
		string result = divide(n1, n2);
		changeSign(result);
		return result;
	}
	else if (!negtive(n1) && negtive(n2))
	{
		changeSign(n2);
		string result = divide(n1, n2);
		result = finalAnswer(result);
		changeSign(result);
		return result;
	}
	else if (negtive(n1) && negtive(n2))
	{
		changeSign(n1);
		changeSign(n2);
		string result = divide(n1, n2);
		result = finalAnswer(result);
		return result;
	}
}

string calculate(string num1, string num2, string op)
{
	if (op == "+")
	{
		return add(num1, num2);
	}
	else if (op == "-")
	{
		return sub(num1, num2);
	}
	else if (op == "*")
	{
		return mult(num1, num2);
	}
	else if (op == "/")
	{
		return div(num1, num2);
	}
}
void operation(string *post, int size, string &total)
{
	string postop = "";
	for (int i = 0; i < size && post[i] != ""; i++)
	{
		postop += post[i] + " ";
	}

	Stack<string> ans;
	string num1, num2, token, op, result;
	stringstream ss(postop);

	while (getline(ss, token, ' '))
	{
		if ((token[0] == '+' && isdigit(token[1])))
		{
			token = token.substr(1, token.length() - 1);
		}
		if (isdigit(token[0]))
		{
			ans.push(token);
		}
		else if (token[0] == '-' && isdigit(token[1]))
		{
			ans.push(token);
		}
		else
		{
			op = token;
			num2 = ans.top();
			ans.pop();
			num1 = ans.top();
			ans.pop();
			result = calculate(num1, num2, op);
			ans.push(result);
		}
	}
	total = ans.top();
	ans.pop();
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << " ./infinitearithmetic input=input1.txt " << endl;
		return -1;
	}
	ArgumentManager am(argc, argv);
	const string input = am.get("input");

	ifstream ifs(input);
	string expressions;
	int size = 0;

	vector<string> line;
	while (getline(ifs, expressions))
	{
		line.push_back(expressions);
	}
	size = line.size();

	for (int i = 0; i < size; i++)
	{
		string *a = NULL;
		string *post = NULL;
		string expression = line[i];
		int numPost = 0;
		int len = expression.length();
		string total;
		if (AreParanthesesBalanced(expression))
		{
			convertLineToStringArray(line[i], a);
			infixToPostfix(a, len, post, numPost);
			operation(post, numPost, total);
			cout << expression << "=" << total << endl;
		}
		delete[] a;
		delete[] post;
	}
}