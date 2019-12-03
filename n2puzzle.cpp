#include <iostream>

using namespace std;

#define row(i,N) i/N
#define col(i,N) i%N

int N = 4;
int N2 = 16;

struct node
{
	int * arr;
	int zpos;
	int g;
	int h;
	node * parent;
};

// Counts number of inversions in the array
int inversionsort(int* arr, int start, int end)
{
	// for(int i=start;i<end;i++)
	// 	cout<<arr[i]<<" ";
	// cout<<"\n";
	if(end - start <= 1)
	{
		// cout<<"SORT DONE\n";
		// for(int i=start;i<end;i++)
		// 	cout<<arr[i]<<" ";
		// cout<<"\nInversions : 0\n";
		return 0;
		
	}
	else
	{
		int mid = (start + end) / 2;
		
		int inv1 = inversionsort(arr, start, mid);
		int inv2 = inversionsort(arr, mid, end);

		int inv3 = 0;
		int idx1 = start;
		int idx2 = mid;

		int temp[end-start];
		int i=0;

		while(idx1<mid && idx2<end)
		{
			if(arr[idx1] > arr[idx2])
			{
				inv3 += mid - idx1;
				temp[i++] = arr[idx2++];
			}
			else
			{
				temp[i++] = arr[idx1++];
			}
		}

		while(idx1<mid)
		{
			temp[i++] = arr[idx1++];
		}

		while(idx2<end)
		{
			temp[i++] = arr[idx2++];
		}

		for(int j=start;j<end;j++)
		{
			arr[j] = temp[j-start];
		}

		// cout<<"SORT DONE\n";
		// for(int j=start;j<end;j++)
		// 	cout<<arr[j]<<" ";
		// cout<<"\nInversions : "<<inv3+inv2+inv1;
		// cout<<"\n";
		return inv3+inv2+inv1;
	}
}

// check if current configuration is solvable
// think carefully, only needed once
int isSolvable(int * temparr, int zpos)
{
	int inv = inversionsort(temparr, 0, N2);
	if(N%2 == 1 && inv%2 == 0)
	{
		return 1;
	}
	if(N%2 == 0)
	{
		if((N-row(zpos, N))%2 == 0 && inv%2 == 1)
		{
			return 1;
		}
		if((N-row(zpos, N))%2 == 1 && inv%2 == 0)
		{
			return 1;
		}
	}
	return -1;
}

// calculates Manhatten distance for the configuration
int Manhatten(int * arr)
{
	
}



int main()
{
	int n;
	cin>>n;
	N = n;
	N2 = n*n;
	int * arr = new int[N2];
	int * temparr = new int[N2];
	int zpos;
	// get the input
	for(int i=0;i<N2;i++)
	{
		cin>>arr[i];
		if(arr[i]==0)
		{
			arr[i]=N2;
			zpos=i;
		}
		temparr[i]=arr[i];
	}
}