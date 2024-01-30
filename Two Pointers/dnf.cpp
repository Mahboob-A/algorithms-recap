// recap on 300124, Tuesday, 09.30 pm 
// DNF algorithm 

#include <bits/stdc++.h>
using namespace std;

void sortDNF(int *arr, int n)
{
        int low = 0, mid = 0, high = n - 1; 
        while(mid <= high)
        {
                if(arr[mid] == 2)
                {
                        swap(arr[mid], arr[high]);
                        high--;
                }
                else if(arr[mid] == 0)
                {
                        swap(arr[mid], arr[low]);
                        low++;
                        mid++;
                }
                else if(arr[mid] == 1) 
                {
                        mid++;
                }
        }
}

int main(){

        cout << "Dutch National Flag Algorithm" << endl;
        cout << "Enter array size and array elements (only 0, 1 and 2) to sort the array" << endl;

        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
                cin >> arr[i];

        // print the array before sort
        cout << "Array before sort using DNF algorithm" << endl;
        for (int i = 0; i < n; i++)
                cout << arr[i] << " ";

        // call DNF function
        cout << "\nSorting the array..." << endl;
        sortDNF(arr, n);

        // print the sorted array
        cout << "\nArray after sorting using DNF algorithm" << endl;
        for (int i = 0; i < n; i++)
                cout << arr[i] << " "; 

                return 0;
}
