#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
void add(ofstream &out,int arr[],int s)
{
	for(int i=0;i<s;i++)
	out<<" "<<arr[i];
	out<<" "<<"-1"<<endl;
}
int min(int arr[],int size)
{
	int min=0;
	int p;
	for(int i=0;i<size;i++)
	if((arr[i]<=min||min==0)&&arr[i]!=-1)
	{
		min=arr[i];p=i;
	}
	return p;
}
void sort (int arr[],int a)
{
	for(int i=0;i<a-1;i++)
	for(int j=i+1;j<a;j++)
	if(arr[i]>arr[j])
	{
	    int t=arr[i];arr[i]=arr[j];arr[j]=t;
	}
}
int isemp(int arr[],int size)
{
	int p;
	for(p=0;p<size;p++)
	if(arr[p]!=-1)
	break;
	if(p==size)
	return 1;
	else 
	return 0;
}
int main()
{   
	int m;
    cout<<"enter the value of m\n";
    cin>>m;
    const int size=m;
    int d,count=0,cnt=0,count2=0;
	int arr[size];
	ofstream out[size];ofstream out2("output.txt");
	ifstream in1[size],in("data.txt");
	char mway[2*size][10];
	for(int i=1;i<=2*size;i++)
	{
		itoa(i,mway[i-1],10);
		strcat(mway[i-1],"m.txt");
	}
	in>>d;
	for(int i=0;i<m;i++)
	out[i].open(mway[2*i]);
	while(!in.eof())
	{
	 arr[cnt++]=d;
	 if(cnt==size)
	 {
		sort(arr,cnt);
		add(out[count],arr,cnt);
		cnt=0;count++;
		if(count==m)
		count=0;
	 }
	 count2++;
	 in>>d;	
	}
	in.close();
	if(cnt!=0)
	{
	 sort(arr,cnt);
	 add(out[count],arr,cnt);
	}
	for(int i=0;i<m;i++)
	out[i].close();
	for(int i=0;i<m;i++)
	{
	 out[i].open(mway[2*i+1]);
	 in1[i].open(mway[2*i]);
	 in1[i]>>arr[i];
	}	
    while(cnt<count2)
	{
	 cnt=0;
	 count=0;
	 d=1;
	 while(d)
	 {
		d=0;
		while (!isemp(arr,size))
	    {   
		 int j;                       
		 j=min(arr,size);
		 out[count]<<arr[j]<<" ";
		 in1[j]>>arr[j];
		 if(count==0)
		 cnt++;
		}
		out[count++]<<"-1"<<endl;
		for(int i=0;i<m;i++)
	    {
	     if(!in1[i].eof())
	     {
		  in1[i]>>arr[i];
		  d=1;
		 }
		}
		if(count==m)
		count=0;
	 }
	 for(int i=0;i<m;i++)
	 {
	  out[i].close();
	  in1[i].close();
	 }
	 if(cnt<count2)
	 {
	   for(int i=0;i<m;i++)
	   {
		out[i].open(mway[2*i]);
		in1[i].open(mway[2*i+1]);
		in1[i]>>arr[i];
	   }
	   cnt=0;
	   count=0;
	   d=1;
	   while(d)
	   {
		 d=0;
		 while (!isemp(arr,size))
	     {   
			int j;                       
		    j=min(arr,size);
			out[count]<<arr[j]<<" ";
			in1[j]>>arr[j];
			if(count==0)
			cnt++;
		 }
		 out[count++]<<"-1"<<endl;
		 for(int i=0;i<m;i++)
	     {
	       if(!in1[i].eof())
	       {
			in1[i]>>arr[i];
			d=1;
		   }
		 }
		 if(count==m)
		 count=0;
	   }	
	   for(int i=0;i<m;i++)
	   {
		 out[i].close();
		 in1[i].close();
	   }
	 }
	 if(cnt<count2)
	 {
	   for(int i=0;i<m;i++)
	   {
		 out[i].open(mway[2*i+1]);
		 in1[i].open(mway[2*i]);
		 in1[i]>>arr[i];
	   }
	 }
	}
	out2.close();
	return 0;
}
