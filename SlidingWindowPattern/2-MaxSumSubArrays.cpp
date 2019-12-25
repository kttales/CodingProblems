#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

/* Problem statement
Given an array, find the Maximum Sum Subarray of Size K
*/
class MaxSum
{
public:
    //Brute force solution
    //Time Complexity O(N * k)
    //Space Complexity O(1)
    static int cal_max_sum(const vector<int> &vec, int k)
    {
        int size = vec.size();
        int result = INT_MIN;

        //negative case
        if(k > size)
        {
            return -1;
        }

        for(int i=0;i<=size-k;i++)
        {
            double sum = 0;
            for(int j=i;j<i+k;j++)
            {
                sum += vec[j];
            }

            if(sum > result)
            {
                result = sum;   
            }
        }
        return result;
    }

    //Efficient solution
    //Time Complexity O(N)
    //Space Complexity O(1)
    static int cal_max_sum_eff(const vector<int> &vec, int k)
    {
        int size = vec.size();
        int result = INT_MIN;

        //negative case
        if(k > size)
        {
            return result;
        }

        int count = 0;
        double sum = 0;
        int j = 0;

        for(int i=0;i<size;i++)
        {
            //counter is less than k
            if(count < k)
            {
                sum+=vec[i];
                ++count;
            }
            else
            {
                sum = sum - vec[j] + vec[i];
                if(result > sum)
                {
                   result = sum; 
                }
                ++j;
            }
        }

        if(result > sum)
        {
           result = sum; 
        }
        return result;
    }
};

int main()
{
    int result = MaxSum::cal_max_sum(vector<int>{2, 1, 5, 1, 3, 2},3);
    cout << "max sum = " << result << endl;

    int result2 = MaxSum::cal_max_sum_eff(vector<int>{2, 1, 5, 1, 3, 2},3);
    cout << "max sum = " << result << endl;
    
    return 0;
}