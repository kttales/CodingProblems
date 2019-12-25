#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

/* Problem statement
find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘k’
*/
class SmallestSubArray
{
public:
    //Brute force solution
    //Time Complexity O(N * N)
    //Space Complexity O(1)
    static int cal_smallest(const vector<int> &arr, int k)
    {
        int size = arr.size();
        int result = INT_MAX;
        int sum = 0;
        int count = 0;
        
        for(int i=0;i<size;i++)
        {
            sum = 0;
            for(int j=i;j<size;j++)
            {
               sum+=arr[j];
               if(sum>=k)
               {
                   count = j-i+1;
                   if(result > count)
                   {
                       result = count; 
                   }
                   break;
               }
            }
        }

        if(result == INT_MAX)
        {
            return -1;
        }
        return result;
    }

    //Efficient solution
    //Time Complexity O(N)
    //Space Complexity O(1)
    static int cal_smallest_eff(const vector<int> &arr, int k)
    {
        int size = arr.size();
        int result = INT_MAX;
        int sum = 0;
        int count = 0;
        int j = 0;
        
        for(int i=0;i<size;i++)
        {
            sum += arr[i];      

            while(sum >= k)
            {
                count = i-j+1;
                if(result > count)
                {
                    result = count;
                }
                sum = sum - arr[j];
                j++;
            }
        }
        
        if(result == INT_MAX)
        {
            return -1;
        }
        return result;
    }
};

int main()
{
    int result = SmallestSubArray::cal_smallest(vector<int>{2, 1, 5, 2, 3, 2},7);
    cout << "SmallestSubArray Length = " << result << endl;
   
    result = SmallestSubArray::cal_smallest(vector<int>{2, 1, 5, 2, 8},7);
    cout << "SmallestSubArray Length = " << result << endl;
   
    result = SmallestSubArray::cal_smallest(vector<int>{3,4,1,1,6},8);
    cout << "SmallestSubArray Length = " << result << endl;
   
    result = SmallestSubArray::cal_smallest(vector<int>{2, 1, 5, 2, 3, 2},75);
    cout << "SmallestSubArray Length = " << result << endl;

    int result2 = SmallestSubArray::cal_smallest_eff(vector<int>{2, 1, 5, 2, 3, 2},7);
    cout << "2- SmallestSubArray Length = " << result2 << endl;
    
    result2 = SmallestSubArray::cal_smallest_eff(vector<int>{2, 1, 5, 2, 8},7);
    cout << "2- SmallestSubArray Length = " << result2 << endl;
    
    
    result2 = SmallestSubArray::cal_smallest_eff(vector<int>{3,4,1,1,6},8);
    cout << "2- SmallestSubArray Length = " << result2 << endl;
    
    result2 = SmallestSubArray::cal_smallest_eff(vector<int>{2, 1, 5, 2, 3, 2},75);
    cout << "2- SmallestSubArray Length = " << result2 << endl;
    
    return 0;
}
