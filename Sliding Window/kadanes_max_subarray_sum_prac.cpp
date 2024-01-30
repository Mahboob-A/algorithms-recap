// recap on 300124, Tuesday, 09.30 pm
// Kadane's Max SubArray Sum 


#include <bits/stdc++.h>
using namespace std;


int maximumSubArraySum(int *arr, int n)
{
        int curr_sum = 0;
        int max_sum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
                curr_sum += arr[i]; 
                if(curr_sum > max_sum)
                        max_sum = curr_sum; 

                if(curr_sum < 0) 
                        curr_sum = 0; 
        }

        if(max_sum < 0)
                max_sum = -1;
        return max_sum;
}


int main()
{

        cout << "Kadane's Maximum SubArray Sum Algorithm" << endl;
        cout << "Enter array size and array elements to maximum subarray sum in the array" << endl
             << endl;

        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
                cin >> arr[i];

        // call DNF function
        cout << "\nFinding Maximum SubArray Sum in the Array..." << endl;
        int max_sum = maximumSubArraySum(arr, n);

        if(max_sum != -1)
                cout << "Maximum sum is: " << max_sum << endl;
        else 
                cout<<"There is no maximum sum in the array (The maximum sum is negative)"<<endl;  

        return 0;
}