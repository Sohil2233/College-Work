#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int xor_fun(vector<int> a)
{
	int count = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == 1)
		{
			count++;
		}
	}
	if (count % 2 == 0)
		return 0;
	else
		return 1;
}
vector<int> dataword;
void sender_division(vector<int> dataword1, vector<int> &divisor, int j)
{
	vector<int> result;
	static int a = 4;
	if (j < 4)
	{
		if (dataword1[0] == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				vector<int> xorval;
				xorval.push_back(dataword1[i]);
				xorval.push_back(divisor[i]);
				int x = xor_fun(xorval);
				xorval.clear();
				result.push_back(x);
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				result.push_back(dataword1[i]);
			}
		}
		reverse(result.begin(), result.end());
		result.pop_back();
		reverse(result.begin(), result.end());
		if (a < dataword.size())
		{
			result.push_back(dataword[a]);
			a++;
		}
		// cout << "\nresult : ";
		// for (int i = 0; i < result.size(); i++)
		// {
		// 	cout << result[i];
		// }
		sender_division(result, divisor, j + 1);
	}
	else
	{
		for (int i = 0; i < dataword1.size(); i++)
		{
			result.push_back(dataword1[i]);
		}
		cout << "\nRemainder: ";
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
		}
		int p1=result[0];
		int p2=result[1];
		int p3=result[2];
		cout<<"\np1 : "<<p1<<endl;
		cout<<"p2 : "<<p2<<endl;
		cout<<"p3 : "<<p3<<endl;
	}
}
vector<int> codeword;
void receiver_division(vector<int> codeword1, vector<int> &divisor, int j)
{
	vector<int> result;
	static int a = 4;
	if (j < 4)
	{
		if (codeword1[0] == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				vector<int> xorval;
				xorval.push_back(codeword1[i]);
				xorval.push_back(divisor[i]);
				int x = xor_fun(xorval);

				xorval.clear();
				result.push_back(x);
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				result.push_back(codeword1[i]);
			}
		}
		reverse(result.begin(), result.end());
		result.pop_back();
		reverse(result.begin(), result.end());
		if (a < codeword.size())
		{
			result.push_back(codeword[a]);
			a++;
		}
		// cout << "\nresult : ";
		// for (int i = 0; i < result.size(); i++)
		// {
		// 	cout << result[i];
		// }
		receiver_division(result, divisor, j + 1);
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			result.push_back(codeword1[i]);
		}
		cout << "Remainder: ";
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
		}
		int s1 = result[0];
		int s2 = result[1];
		int s3 = result[2];
		cout << "\ns1 : " << s1 << endl;
		cout << "s2 : " << s2 << endl;
		cout << "s3 : " << s3 << endl;
		if (s1 == 0 && s2 == 0 && s3 == 0)
		{
			cout << "No Error";
		}
		else
		{
			cout << "Error is present";
		}
	}
}
int main()
{
	vector<int> divisor;
	cout<<"SENDER SIDE ======> "<<endl;
	// input dataword
	cout << "Enter Dataword(4 bit): ";
	for (int i = 0; i < 4; i++)
	{
		int a;
		cin >> a;
		dataword.push_back(a);
	}
	// input divisor
	cout << "Enter Divisor: ";
	for (int i = 0; i < 4; i++)
	{
		int a;
		cin >> a;
		divisor.push_back(a);
	}
	// push 3 zeros
	for (int i = 0; i < 3; i++)
	{
		dataword.push_back(0);
	}
	// dataword at sender
	cout << "Dataword at Sender(7 bit): ";
	for (int i = 0; i < 7; i++)
	{
		cout << dataword[i];
	}

	// calling to function
	sender_division(dataword, divisor, 0);

	//------------------------receiver side-------------------------
	// input codeword
	// cout << "RECEIVER SIDE ======> ";
	// cout << "\nEnter codeword(7 bit): ";
	// for (int i = 0; i < 7; i++)
	// {
	// 	int a;
	// 	cin >> a;
	// 	codeword.push_back(a);
	// }
	// // calling to function
	// receiver_division(codeword, divisor, 0);
	return 0;
}
