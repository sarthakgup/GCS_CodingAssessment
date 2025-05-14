#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &numbers)
{
    int n = numbers.size();
  
    //implementing bubble sort (O(N^2))
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

double sortAndFindMedian(vector<int>& numbers)
{
    //bubble sorting
    sort(numbers);  //CALL sort(numbers)
    
    int n = numbers.size(); //DEFINE n as length of numbers
    
    if(n % 2 == 0)  //IF n mod 2 == 0
    {
        return (numbers[n/2 - 1]+numbers[n/2])/2.0; //follows pseudocode
    }
    else
    {
        return numbers[n/2];  //follows pseudocode
    }
}

int main()
{
    vector<int> nums = {7, 1, 3, 5, 2};
    
    double median = sortAndFindMedian(nums);
    cout << "Median: " << median << endl;
    
    return 0;
}

/*
UNUSED CODE FUNCTIONS: (to demonstrate thought process later)

void sort(vector<int> &numbers)
{
    //quick select sort to find the median
}

/quick select (since we only want to select the median) (O(n))
//quickselect partition:
int partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[right];
    int i = left;

    for(int j = left; j < right; ++j)
    {
        if(nums[j] < pivot)
        {
            swap(nums[i], nums[j]);
            ++i;
        }
    }

    swap(nums[i], nums[right]);
    return i;
}

//quickselect sort algorithm:
int quickSelect(vector<int>& nums, int left, int right, int k)
{
    if (left == right)
    {
        return nums[left];
    }

    int pivotIndex = left + rand() % (right - left + 1);
    swap(nums[pivotIndex], nums[right]); // Move pivot to end
    pivotIndex = partition(nums, left, right);

    if (k == pivotIndex)
    {
        return nums[k];
    }
    else if (k < pivotIndex)
    {
        return quickSelect(nums, left, pivotIndex - 1, k);
    }
    else
    {
        return quickSelect(nums, pivotIndex + 1, right, k);
    }
}
*/