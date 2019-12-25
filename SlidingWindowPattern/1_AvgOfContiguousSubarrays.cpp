#include<iostream>
#include<vector>
using namespace std;

/* Problem statement
Given an array, find the average of all contiguous subarrays of size ‘K’ in it.
*/
class ArrayAvg
{
public:
    //Brute force solution
    //Time Complexity O(N * k)
    //Space Complexity O(1)
    static vector<double> cal_avg(const vector<int> &vec, int k)
    {
        int size = vec.size();
        vector<double> result;

        //negative case
        if(k > size)
        {
            cout << "Error " << endl;
            return result;
        }

        for(int i=0;i<=size-k;i++)
        {
            double sum = 0;
            for(int j=i;j<i+k;j++)
            {
                sum += vec[j];
            }
            sum = sum/k;
            result.push_back(sum);
        }
        return result;
    }

    //Efficient solution
    //Time Complexity O(N)
    //Space Complexity O(1)
    static vector<double> cal_avg_eff(const vector<int> &vec, int k)
    {
        int size = vec.size();
        vector<double> result;

        //negative case
        if(k > size)
        {
            cout << "Error " << endl;
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
                result.push_back(sum/k);
                sum = sum - vec[j] + vec[i];
                ++j;
            }
        }

        result.push_back(sum/k);
        return result;
    }
};

int main()
{
    vector<double> result = ArrayAvg::cal_avg(vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2},5);

    for(double res : result)
    {
        cout << res << " ";
    }
    cout << endl;

    vector<double> result2 = ArrayAvg::cal_avg_eff(vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2},5);

    for(double res : result2)
    {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
