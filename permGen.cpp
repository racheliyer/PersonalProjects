#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Map to convert numbers to words
map<int, string> numberToWord = {
    {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"},
    {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"},
    {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"},
    {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"},
    {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"}, {30, "thirty"},
    {40, "forty"}, {50, "fifty"}, {60, "sixty"}, {70, "seventy"},
    {80, "eighty"}, {90, "ninety"}
};

// Function to convert numbers to their word equivalents
string numberToString(int num) {
    if (num <= 19) {
        return numberToWord[num];
    }
    else if (num < 100) {
        int tens = (num / 10) * 10;  // Get the tens place (e.g., 20, 30, 40...)
        int ones = num % 10;  // Get the ones place
        if (ones == 0) {
            return numberToWord[tens];
        } else {
            return numberToWord[tens] + "-" + numberToWord[ones];
        }
    }
    return ""; // for numbers 100 and above, which we can extend later
}

// Function to print a permutation of numbers as words
void printPermutation(const vector<string>& d) {
    for (const string& num : d) {
        cout << num << " ";
    }
    cout << endl;
}

// Permutation generator function that works with string representations of numbers
void PermGenerator(vector<string>& nums) {
    // Sort the input strings lexicographically (alphabetically)
    sort(nums.begin(), nums.end());

    // Print the first permutation (sorted)
    printPermutation(nums);

    // Generate and print all remaining permutations in lexicographical order
    while (true) {
        // Find the first pair (i, j) from right to left such that nums[i] < nums[i + 1]
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        // If no such pair exists, we've generated all permutations
        if (i < 0) {
            break;
        }

        // Find the largest index j such that nums[i] < nums[j]
        int j = nums.size() - 1;
        while (nums[i] >= nums[j]) {
            --j;
        }

        // Swap nums[i] and nums[j]
        swap(nums[i], nums[j]);

        // Reverse the sequence from nums[i + 1] to nums[nums.size() - 1]
        reverse(nums.begin() + i + 1, nums.end());

        // Print the current permutation
        printPermutation(nums);
    }
}

int main() {
    int n;

    // Prompt user to enter the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    // Prompt user to input the elements as integers
    cout << "Enter " << n << " numbers (integers):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Convert the numbers to their word equivalents
    vector<string> wordNums;
    for (int i = 0; i < n; ++i) {
        wordNums.push_back(numberToString(nums[i]));
    }

    // Call the PermGenerator function to generate and print all permutations of words
    PermGenerator(wordNums);

    return 0;
}
