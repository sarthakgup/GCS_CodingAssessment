#include <iostream>
#include <vector>
using namespace std;

double sortAndFindMedian(vector<int>& numbers)
{
    //bubble sorting
    sort(numbers);  //CALL sort(numbers)
    
    int n = numbers.size(); //DEFINE n as length of numbers
    
    if(n % 2 == 0)  //IF n mod 2 == 0
    {
        return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    }
    else
    {
        return numbers[n / 2];
    }
}

void sort(vector<int> &numbers)
{
    int n = numbers.size();
  
    //implementing bubble sort  
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (numbers[j] > numbers[j + 1])
            {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int> nums = {7, 1, 3, 5, 2};
    
    double median = sortAndFindMedian(nums);
    cout << "Median: " << median << endl;
    
    return 0;
}
