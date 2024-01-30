
// 190124, Friday, 10.30 pm

/*

Moor's voting algorithm
Problem: Find majority element greater than n / 2.
Explanation: we need to find an element which is present in the array greater than n / 2 times.

The algorithm:

The algorithm has two phase.

Phase 01:
    In the first phase, we will try to find the possible majority element in the array.
    we will assume the 0'th index is the majority element (the possible_majority_element_index = 0), and take count = 1.

    Now, loop through the array and check if arr[possible_majority_element_index] == arr[i]:
        then increemnt the count.
    If we find arr[possible_majority_element_index] != arr[i]:
        decrement the count.

    Then check if count is equal to 0:
        if true:
            then make count back to 1.
            make the possible_majority_element_index to current i index.


    The item in possible_majority_element_index after the loop is our possible candidate for majority element in the array.

    The phase 01 always tells us a possible majority element index, but it needs to be verified.
    If the question states there is always a major element in the array, the arr[possible_majority_element_index] is the answer
    and there might be a possibility that the n-1'th element is the majority element (it is a just possibility).

Phase o2:
    As the phase 01 tells us a possible index for the majority element in the array, but there might be cases there is no majority element
    in the array.

    So, we will set count to 0 and run a loop and count the frequcy of arr[possible_majority_element_index] value.
    If now the count is greater than n / 2, return arr[possible_majority_element_index] else -1.


*/

#include <bits/stdc++.h>

using namespace std;

int findMajorityElement(int *arr, int n)
{
        // phase 01: find the possible candidate
        int count = 1, possible_majority_element_index = 0;
        for (int i = 1; i < n; i++)
        {
                if (arr[possible_majority_element_index] == arr[i])
                {
                        count++;
                }
                else
                {
                        count--;
                }

                if (count == 0)
                {
                        count = 1;
                        possible_majority_element_index = i;
                }
        }

        // if question guarantees there is always a Majority element in the array, arr[possible_majority_element_index] is the element
        // then no need for phase 02.

        // phase 02:
        count = 0;
        for (int i = 0; i < n; i++)
        {
                if (arr[possible_majority_element_index] == arr[i])
                        count++;
        }

        if (count > n / 2)
                return arr[possible_majority_element_index];
        else
                return -1;
}

int main()
{
        cout << "Moore's Algorithm: Find Majority Element (element > n / 2 in array): " << endl;
        int n;
        cout << "Input size for array: " << endl;
        cin >> n;
        cout << "Input array: " << endl;
        int arr[n];
        for (int i = 0; i < n; i++)
                cin >> arr[i];

        int major_element = findMajorityElement(arr, n);

        if (major_element != -1)
        {
                cout << "The majority element in the array is: " << major_element << endl;
        }
        else
        {
                cout << "There is no majority element in the array." << endl;
        }

        return 0;
}
