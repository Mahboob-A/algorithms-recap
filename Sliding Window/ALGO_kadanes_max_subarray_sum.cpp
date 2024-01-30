
// 230124, Tuesday, 09.30 pm
// Kadane's algorithm
// maximum sub of subarray

#include <bits/stdc++.h>

using namespace std;

vector<int> maxSubArraySum(int arr[], int n)
{
        cout << "Kadane's Algorithm" << endl;
        int sum = 0, maxSum = INT_MIN;

        // to hold the indexes to print the Subarray
        int maxSumStart = 0;
        int startIndex = -1, endIndex = -1;

        for (int i = 0; i < n; i++)
        {
                // as sum is 0, make maxSumStart to the current index
                if (sum == 0)
                        maxSumStart = i;

                sum += arr[i];

                if (sum > maxSum)
                {
                        maxSum = sum;

                        // as the maxSum is changed, make the startIndex to the maxSumStart point, and end index to the current index
                        // where the sum crossed the maxSum.
                        startIndex = maxSumStart;
                        endIndex = i;
                }

                if (sum < 0)
                        sum = 0;
        }
        vector<int> v(4);
        v[0] = startIndex;
        v[1] = endIndex;
        v[2] = maxSum;
        return v;
}

void calc_maxSubArraySum(int arr[], int n)
{
        vector<int> indexes(4);

        indexes = maxSubArraySum(arr, n);

        int startIndex = indexes[0];
        int endIndex = indexes[1];
        int maxSum = indexes[2];
        cout << "The maximum sum is: " << maxSum << endl;
        cout << "The subarray is below: " << endl;
        for (int i = startIndex; i <= endIndex; i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;
}

// this is the kadane's algo for max max subarray sum
int onlyMaxSubarraySum(int arr[], int n)
{
        // Write your code here.

        long long maxSum = LONG_MIN;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
                sum += arr[i];

                maxSum = max(maxSum, sum);

                if (sum < 0)
                        sum = 0;
        }

        if (maxSum < 0)
                maxSum = 0;

        return maxSum;
}

int main()
{
        cout << "Maximum Subarray Sum with Kadane's Algorithm: " << endl;
        int n;
        cin >> n;
        int arr[n];
        cout << "Enter array: " << endl;
        for (int i = 0; i < n; i++)
                cin >> arr[i];

        // function to kanane's alog with subarray printing
        calc_maxSubArraySum(arr, n);

        // int res = onlyMaxSubarraySum(arr, n);

        // cout<<"Max subarray sum is: "<<res<<endl;

        return 0;
}
