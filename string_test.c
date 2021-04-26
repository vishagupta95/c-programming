// C++ program to print words in a sentence
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void removeDupWord(string str)
{
    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            cout << word << endl;
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    cout << word << endl;
}

using namespace std;

void removeDupWord2(char str[])
{
    // Returns first token
    char *token = strtok(str, " ");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
}

// Driver code
int main()
{
    string str = "india is best";
    removeDupWord(str);

    std::string name;

    std::cout << "Please, enter your full name: ";
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!\n";

    string s1, s2, result;

    cout << "Enter string s1: ";
    getline (cin, s1);

    cout << "Enter string s2: ";
    getline (cin, s2);

    result = s1 + s2;

    cout << "Resultant String = "<< result;

    return 0;
}