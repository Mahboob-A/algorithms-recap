// recap on 300124, Tuesday, 09.30 pm
// Moore's Vooting Algorithm (Find Majority Element Algorithm)

#include <bits/stdc++.h>
using namespace std;

vector<int> findMajorityElement(int *arr, int n)
{
        int count = 1;
        // index 
        int possible_major_elem = 0;

        for (int i = 0; i < n; i++)
        {
                if(arr[possible_major_elem] == arr[i])
                {
                        count++;
                }
                else
                {
                        count--;
                }

                if(count == 0)
                {
                        count = 1;
                        possible_major_elem = i;
                }
        }

        count = 0; 
        for (int i = 0; i < n; i++)
        {
                if(arr[possible_major_elem] == arr[i])
                        count++;
        }


        vector<int> v(2, 0);
        if(count > n/2)
        {
                v[0] = arr[possible_major_elem];  // the majority element
                v[1] = possible_major_elem;  // the index of the majority element 
        }
        return v;
}

int main()
{

        // a majority element in array which has occurance in the array more than (n/2) times. 
        cout << "Moore's Voting Algorithm" << endl;
        cout << "Enter array size and array elements to find majority element in the array" << endl
             << endl; 

        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
                cin >> arr[i];

        // call DNF function
        cout << "\nFinding Majority Element in the Array..." << endl;
        vector<int> major_elem(2, 0);
        major_elem = findMajorityElement(arr, n);

        if(major_elem[0] != 0)
        {
                cout << "The majority element in the array is: " << major_elem[0] << endl;
                cout << "And the index of the element is: " << major_elem[1] << endl;
        }
        else
        {
                cout << "There is no majority element in the array" << endl; 
        }

        return 0;
}
