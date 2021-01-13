#include <iostream>
#include <string>
#include <bits/stdc++.h>

#include "hash-library/sha256.h"

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

    string hash_str = "";

    for (int i = 0; i < INT_MAX - 1; i++)
    {
        hash_str = sha256(to_string(i));

        if (validate_hash(hash_str, "0123456"))
            cout << i << ") " << hash_str << endl;
    }

    return 0;
}
