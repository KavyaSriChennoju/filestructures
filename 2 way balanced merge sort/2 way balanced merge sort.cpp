#include<iostream>
#include<fstream>
using namespace std;
void sort(int  arr[],int asize)
{
	for(int i=0;i<asize-1;i++)
	for(int j=i+1;j<asize;j++)
	{
		if(arr[i]>arr[j])
		{
			int t=arr[i];
			arr[i]=arr[j];
			arr[j]=t;
		}
	}
}
int main()
{ 
    int n,a,b,size,asize,count=0,count1=0,count2=0,arr[20];
	ofstream fout,fout1,fout2;fout.open("data.txt");fout1.open("file1.txt");fout2.open("file2.txt");
	cout<<"enter no of no.s\n";
	cin>>n;
	size=n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter no  " <<i+1<<"\n";
		cin>>a;
		fout<<a<<"  ";
	}
	fout.close();
	ifstream fin,fin1,fin2;fin.open("data.txt");
	cout<<"enter the array size\n";
	cin>>asize;
	fin>>a;
	while(!fin.eof())
	{   
	    arr[count1++]=a;
		if(count1==asize)
		{
	     sort(arr,asize);
		if(count%2==0)
		{
		for(int i=0;i<asize;i++)
		fout1<<arr[i]<<"  ";
		fout1<<-1<<"  ";
		}
		if(count%2==1)
		{
	    for(int i=0;i<asize;i++)
		fout2<<arr[i]<<"  ";
		fout2<<-1<<"  ";
		}
		count++;count1=0;	
		}
		fin>>a;	
	}
    sort(arr,count1);
	if(count%2==0)
	{
		for(int i=0;i<count1;i++)
		fout1<<arr[i]<<"  ";
		fout1<<-1<<"  ";
	}
	if(count%2==1)
	{
	    for(int i=0;i<count1;i++)
		fout2<<arr[i]<<"  ";
		fout2<<-1<<"  ";
	}
    fout1.close();fout2.close();fin.close();
  count=0;count1=0;
    while(count<size)
    {
    	count=0;
    	if(count1%2==0)
    	{
    		fin1.open("file1.txt");
    		fin2.open("file2.txt");
			fout1.open("file3.txt");
			fout2.open("file4.txt");
    	}
    	if(count1%2==1)
    	{
    		fin1.open("file3.txt");
    		fin2.open("file4.txt");
			fout1.open("file1.txt");
			fout2.open("file2.txt");
    	}
    	fin1>>a;fin2>>b;
    	 while(!fin1.eof()||!fin2.eof())
    	 {
         	if(a>b)
         	{
    		if(count2%2==0)
    		{
    			if(b!=-1 &&!fin2.eof())
    			{
    				fout1<<b<<"  ";count++;
    				fin2>>b;
    			}
    			else
    			{
    				while(a!=-1 && !fin1.eof())
    		    	{
    				fout1<<a<<"  ";
					count++;
					fin1>>a;
    		     	}	
    			if(count!=size)
    			fout1<<-1<<"  ";
    			fin1>>a;fin2>>b;
    			count2++;
    			}
    		}
    		else if(count!=size && count2%2==1)
    		{
    			if(b!=-1 )
    			{
    				fout2<<b<<"  ";
    				if(!fin2.eof())
    				fin2>>b;
    			}
    			else
    			{
    				while(a!=-1 && !fin1.eof())
    		    	{
    				fout2<<a<<"  ";
					fin1>>a;
    		     	}	
    			if(count!=size)
    			fout2<<-1<<"  ";
    			fin1>>a;fin2>>b;
    			count2++;
    			}
    			
    		}
    	}
      else
    	{
    		if(count2%2==0)
    		{
    			if(a!=-1 )
    			{
    				fout1<<a<<"  ";count++;
    				if(!fin1.eof())
    				fin1>>a;
    			}
    			else
    			{
    			while(b!=-1 && !fin2.eof())
    		    	{
    				fout1<<b<<"  ";
					count++;
					fin2>>b;
    		     	}	
    			if(count!=size)
    			fout1<<-1<<"  ";
    			fin1>>a;fin2>>b;
    			count2++;
    			}
    		}
    		else if(count!=size && count2%2==1)
    		{
    			if(a!=-1 &&!fin1.eof())
    			{
    				fout2<<a<<"  ";
    				fin1>>a;
    			}
    			else
    			{
					while(b!=-1 && !fin2.eof())
    		    	{
    				fout2<<b<<"  ";
					fin2>>b;
    		     	}	
    			if(count!=size)
    			fout2<<-1<<"  ";
    			fin1>>a;fin2>>b;
    			count2++;
			
    			}	
    		}
         	}
    	 }
    fin1.close();fin2.close();fout1.close();fout2.close();count1++;
    
    }
    
	
}

