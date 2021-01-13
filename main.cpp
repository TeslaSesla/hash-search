#include <iostream>
#include <string>
#include <bits/stdc++.h>

#include "hash-library/sha256.h"
#define ITERATIONS_DEFAULT 1000

using namespace std;

string get_chars_string(int ch_amount, char ch)
{
    string out_str = "";

    for (int i = 0; i < ch_amount; i++)
        out_str.push_back(ch);

    return out_str;
}

bool validate_hash(string str, string validation_str)
{
    if (str.substr(0, validation_str.length()) == validation_str)
        return true;

    return false;
}

int main()
{
    SHA256 sha256;

    int ch_amount = 2;
    char ch = 'a';
    unsigned long long max_iterations = 0;


    cout << "Enter char, that will be used in string: ";
    cin >> ch;
    cout << "Enter amount of chars in string: ";
    cin >> ch_amount;
    cout << "Enter a iterations amount [" << ITERATIONS_DEFAULT << "]: ";
    cin >> max_iterations;

    if (max_iterations == 0)
        max_iterations = ITERATIONS_DEFAULT;

    string search_string = get_chars_string(ch_amount, ch);

    cout << "Programm will search something like this: " << search_string << "..." << endl
         << "In a " << max_iterations << " iterations." << endl;

    string hash_str = "";
    unsigned long long matched_lines = 0;

    for (unsigned long long i = 0; i < max_iterations; i++)
    {
        hash_str = sha256(to_string(i));

        if (validate_hash(hash_str, search_string))
        {
            cout << i << " - " << hash_str << endl;
            matched_lines++;
        }
    }

    cout << endl << "Found matching lines: " << matched_lines << endl;

    return 0;
}
