

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    const char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i',' j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
        'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

    char string[500];
    string[499] = '\0';

    cout << "Enter the string: ";
    gets_s(string);

    const int string_length = strlen(string);
    const int alphabet_length = 26;
    
    for (int i = 0; i < string_length; i++)
    {
        for (int j = 0; j < alphabet_length; j++)
        {
            if (string[i] == alphabet[j])
            {
                string[i] = alphabet[alphabet_length - (j + 1)];
            }
        }
    }

    cout << string;
    return 0;
}