#include <iostream>
#include <stack>

using namespace std;

// Function to perform the described string transformation
// Time Complexity: O(N), where N is the length of the input string
// Space Complexity: O(N), where N is the length of the input string (space required for the stack)
string solution(string &S) {
    // Initialize a stack to keep track of characters during transformations
    stack<char> charStack;

    // Iterate through each character in the input string
    for (char character : S) {
        // Check if the current character forms a valid pair with the top of the stack
        if (!charStack.empty() &&
            ((character == 'B' && charStack.top() == 'A') || (character == 'A' && charStack.top() == 'B') ||
             (character == 'D' && charStack.top() == 'C') || (character == 'C' && charStack.top() == 'D'))) {
            // Skip the pair to be removed
            charStack.pop();
        } else {
            // Add the current character to the stack
            charStack.push(character);
        }
    }

    // Reconstruct the result string from the stack
    string result = "";
    while (!charStack.empty()) {
        result = charStack.top() + result;
        charStack.pop();
    }

    // Return the final stabilized string after transformations
    return result;
}

// Example usage in main function
int main() {
    // Example input string
    string inputString = "CBACD";

    // Call the solution function to obtain the result
    string result = solution(inputString);

    // Display the input and result
    cout << "Input: " << inputString << ", Result: " << result << endl;

    // Return 0 to indicate successful program execution
    return 0;
}

