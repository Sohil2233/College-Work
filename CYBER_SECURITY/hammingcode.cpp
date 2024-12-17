#include<iostream>
#include<vector>
using namespace std;
int xor_func(vector<int>val)
{
	int count=0;
	for(int i=0;i<val.size();i++)
	{
		if(val[i]==1)
		{
			count++;
		}
	}
	if(count%2==0) return 0;
	else return 1;
}
void sender(vector<int>&dataword)
{
	cout<<"Enter the data word : ";
	for(int i=0;i<4;i++)
	{
		int a;
		cin>>a;
        dataword.push_back(a);
	}
	vector<int>p1;
	p1.push_back(dataword[0]);
	p1.push_back(dataword[1]);
	p1.push_back(dataword[2]);
	int a=xor_func(p1);

	vector<int>p2;
	p2.push_back(dataword[1]);
	p2.push_back(dataword[2]);
	p2.push_back(dataword[3]);
	int b=xor_func(p2);

	vector<int>p3;
	p3.push_back(dataword[2]);
	p3.push_back(dataword[3]);
	p3.push_back(dataword[0]);
	int c=xor_func(p3);
    
	dataword.push_back(a);
	dataword.push_back(b);
	dataword.push_back(c);
	cout<<"Sender Side : ";
	for(int i=0;i<dataword.size();i++)
	{
		
        cout<<dataword[i];
	}
}
void receiver(vector<int>&codeword)
{
	// cout<<"\nReceiver side -----> ";
	cout<<"\nEnter the codeword : ";
	for(int i=0;i<7;i++)
	{
		int a;
		cin>>a;
        codeword.push_back(a);
	}
	vector<int>s1;
	s1.push_back(codeword[0]);
	s1.push_back(codeword[1]);
	s1.push_back(codeword[2]);
	s1.push_back(codeword[4]);
	int x=xor_func(s1);

	vector<int>s2;
	s2.push_back(codeword[1]);
	s2.push_back(codeword[2]);
	s2.push_back(codeword[3]);
	s2.push_back(codeword[5]);
	int y=xor_func(s2);

	vector<int>s3;
	s3.push_back(codeword[2]);
	s3.push_back(codeword[3]);
	s3.push_back(codeword[0]);
	s3.push_back(codeword[6]);
	int z=xor_func(s3);
	
	if(x==1 && y==0 && z==0)
	{
		cout<<"Error at :  P1"<<endl;
		if(codeword[4]==1)
		{
			codeword[4]=0;
		}
		else
		{
			codeword[4]=1;
		}
		
	}
	else if(x==0 && y==1 && z==0)
	{
		cout<<"Error at :  P2"<<endl;
		if(codeword[5]==1)
		{
			codeword[5]=0;
		}
		else
		{
			codeword[5]=1;
		}
	}
	else if(x==0 && y==0 && z==1)
	{
		cout<<"Error at :  P3"<<endl;
		if(codeword[6]==1)
		{
			codeword[6]=0;
		}
		else
		{
			codeword[6]=1;
		}
	}
	else if(x==1 && y==1 && z==0)
	{
		cout<<"Error at :  D2"<<endl;
		if(codeword[1]==1)
		{
			codeword[1]=0;
		}
		else
		{
			codeword[1]=1;
		}
	}
	else if(x==1 && y==0 && z==1)
	{
		cout<<"Error at :  D1"<<endl;
		if(codeword[0]==1)
		{
			codeword[0]=0;
		}
		else
		{
			codeword[0]=1;
		}
	}
	else if(x==0 && y==1 && z==1)
	{
		cout<<"Error at :  D4"<<endl;
		if(codeword[3]==1)
		{
			codeword[3]=0;
		}
		else
		{
			codeword[3]=1;
		}
	}
	else if(x==1 && y==1 && z==1)
	{
		cout<<"Error at :  D3"<<endl;
		if(codeword[2]==1)
		{
			codeword[2]=0;
		}
		else
		{
			codeword[2]=1;
		}
	}
	else
	{
		cout<<"no error"<<endl;
	}
	cout<<"Correct Codeword is : ";
	for(int i=0;i<codeword.size();i++)
	{
		
        cout<<codeword[i];
	}
}
int main()
{
	vector<int>dataword;
	vector<int>codeword;
	sender(dataword);
	receiver(codeword);
	
	return 0;
}
