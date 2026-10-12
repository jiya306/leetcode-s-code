#include<iostream>
using namespace std;

void moveZeroes(int arr[],int n)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        
        if(arr[i] != 0)
        {
           swap(arr[i],arr[j]);
            j++;
        }
    }

    if(j<n)
    {
        for(int i=j;i<n;i++)
        {
            arr[i]=0;
        }
    }

    //display 
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

   moveZeroes(arr, n);

    return 0;
}