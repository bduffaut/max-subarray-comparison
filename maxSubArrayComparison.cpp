#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>

// Original Brute Force algorithm
int maxSubArrayBruteForce(int *array, int size)
{
    int maxValue = INT_MIN;
    int curValue = 0;
    for (int i = 0; i < size; i++)
    {
        curValue = 0;
        for (int j = i; j < size; j++)
        {
            curValue += array[j];
            if (curValue > maxValue)
                maxValue = curValue;
        }
    }
    return maxValue;
}

// MaxCrossingSum algorithm as shown in the textbook
int maxCrossingSum(int nums[], int low, int mid, int high)
{
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += nums[i];
        if (sum > left_sum)
        {
            left_sum = sum;
        }
    }

    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += nums[i];
        if (sum > right_sum)
        {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

// Original recursive algorithm as described by the textbook
int maxSubArrayRecursive(int nums[], int low, int high)
{
    if (low == high)
    {
        return nums[low];
    }

    int mid = (low + high) / 2;
    int left_sum = maxSubArrayRecursive(nums, low, mid);
    int right_sum = maxSubArrayRecursive(nums, mid + 1, high);
    int cross_sum = maxCrossingSum(nums, low, mid, high);

    return std::max(left_sum, std::max(right_sum, cross_sum));
}

// New implementation with calling Brute Algorithm when n < 45
int maxSubArrayRecursiveWithBrute(int nums[], int low, int high)
{
    if (high - low + 1 < 45)
    {
        return maxSubArrayBruteForce(nums + low, high - low + 1);
    }
    if (low == high)
    {
        return nums[low];
    }

    int mid = (low + high) / 2;
    int left_sum = maxSubArrayRecursiveWithBrute(nums, low, mid);
    int right_sum = maxSubArrayRecursiveWithBrute(nums, mid + 1, high);
    int cross_sum = maxCrossingSum(nums, low, mid, high);

    return std::max(left_sum, std::max(right_sum, cross_sum));
}

// Used to generate arrays for testing
void generateRandomArray(int arr[], int size, int min, int max)
{
    std::srand(std::time(0));
    for (int i = 0; i < size; ++i)
    {
        arr[i] = min + std::rand() % (max - min + 1);
    }
}

int main()
{
    const int size = 45;
    int array[size];
    generateRandomArray(array, size, -500, 1000);

    double time1, timedif;

    // Brute Force
    time1 = static_cast<double>(clock());
    int max = maxSubArrayBruteForce(array, size);
    timedif = (static_cast<double>(clock()) - time1) / CLOCKS_PER_SEC;
    std::cout << "Max Sub Array Brute Force = " << max << std::endl;
    std::cout << "Time for brute: " << timedif << " seconds" << std::endl;

    // Recursive
    time1 = static_cast<double>(clock());
    max = maxSubArrayRecursive(array, 0, size - 1);
    timedif = (static_cast<double>(clock()) - time1) / CLOCKS_PER_SEC;
    std::cout << "Max Sub Array Recursive = " << max << std::endl;
    std::cout << "Time for recursive: " << timedif << " seconds" << std::endl;

    // Recursive with Brute base case
    time1 = static_cast<double>(clock());
    max = maxSubArrayRecursiveWithBrute(array, 0, size - 1);
    timedif = (static_cast<double>(clock()) - time1) / CLOCKS_PER_SEC;
    std::cout << "Max Sub Array Recursive With Brute = " << max << std::endl;
    std::cout << "Time for recursive with brute base case: " << timedif << " seconds" << std::endl;

    return 0;
}
