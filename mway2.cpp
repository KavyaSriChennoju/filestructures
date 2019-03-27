#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
int getmin(int arr[],int size)
{
	int min=-1,mint=1000;
	
	for(int i=0;i<size;i++)
	{
	  if(arr[i]<mint&&arr[i]!=-1)
	  {
	  	min=i;mint=arr[i];
	  }	
	}
	return min;
}
int main()
{
	int m,a,b;
	cout<<"enter the value of m\n";
	cin>>m;
	const int size=m;
	int arr[size];
	ofstream out[size];ifstream in[size];
	ofstream out1("mdata.txt");
	cout<<"enter the no of numbers to be sorted\n";
	cin>>a;int cnt=a;
	for(int i=0;i<a;i++)
	{
		cout<<"enter the number "<<i+1<<endl;
		cin>>b;
		out1<<b<<" ";
	}
	out1.close();
	ifstream in1("mdata.txt");
	char mway[2*size][10];
	for(int i=1;i<=2 *size;i++)
	{
		itoa(i,mway[i-1],10);
		strcat(mway[i-1],"m2.txt");
	}
	in1>>b;
	for(int i=0;i<size;i++)
	out[i].open(mway[2*i]);
	int count=0,count1=0;
	while(!in1.eof())
	{
		arr[count++]=b;
		if(count==size)
		{
			for(int i=0;i<size-1;i++)
			for(int j=i+1;j<size;j++)
			if(arr[i]>arr[j])
			swap(arr[i],arr[j]);
			for(int i=0;i<size;i++)
			out[count1]<<" "<<arr[i];
			out[count1]<<" "<<"-1"<<endl;
			count1++;
			if(count1==m)
			count1=0;
			count=0;
		}
		in1>>b;
	}
	in1.close();int min;
	for(int i=0;i<count-1;i++)
	for(int j=i+1;j<count;j++)
	if(arr[i]>arr[j])
	swap(arr[i],arr[j]);
	for(int i=0;i<count;i++)
	out[count1]<<" "<<arr[i];
	if(count!=0)
	out[count1]<<" "<<"-1"<<endl;
	for(int i=0;i<size;i++)
	out[i].close();
	int count3=0;count1=0;
	while(count3!=0)
	{
		count3=0;count=0;
		if(count1%2==0)
		{
			for(int i=0;i<size;i++)
			{
			   in[i].open(mway[2*i]);
			   in[i]>>b;
			   if(!in[i].eof())
			   arr[i]=b;
			   out[i].open(mway[2*i+1]);count1++;	
			}
		}
		else
		{
			for(int i=0;i<size;i++)
			{
			   in[i].open(mway[2*i+1]);
			   in[i]>>b;
			   if(!in[i].eof())
			   arr[i]=b;
			   out[i].open(mway[2*i]);count1++;	
			}
		}
		while(count<cnt)
		{
			min=getmin(arr,size);
			if(min!=-1)
			{
				out[count3%m]<<arr[min]<<" ";
				count++;
				in[min]>>b;
				if(!in[min].eof())
				arr[min]=b;
			}
			else if(count<cnt)
			{
				out[count3%m]<<"-1"<<endl;
				count3++;
				for(int i=0;i<size;i++)
				{
					in[i]>>b;
					if(!in[i].eof())
					arr[i]=b;
					else
					arr[i]=-1;
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			in[i].close();out[i].close();
		}
	}
}
