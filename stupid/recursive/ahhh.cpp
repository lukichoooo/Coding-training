#include <iostream>
#include <vector>
#include <numeric> // For accumulate (alternative method)


void printVec(const std::vector<int> &v)
{
    for (int n : v)
        std::cout << n << " ";
    std::cout << std::endl;
}

// Recursive function to calculate the sum of elements in a vector
int sum(const std::vector<int> &numbers)
{
    if (numbers.empty())
    {
        return 0;
    }
    else
    {
        // Create a sub-vector excluding the first element
        std::vector<int> remaining_numbers(numbers.begin() + 1, numbers.end());
        printVec(remaining_numbers);
        std::cout<<"numbers[0] = "<<numbers[0]<<std::endl;
        return numbers[0] + sum(remaining_numbers);
    }
}

int main()
{
    std::vector<int> numbers = {1, 2, 7, 9};
    printVec(numbers);

    // Call the recursive function
    int recursive_sum = sum(numbers);
    std::cout<<numbers[0]<<std::endl;

    std::cout << "Recursive Sum: " << recursive_sum << std::endl; // Output: 19

    return 0;
}
