// task3_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

char italian[] = { ' ', 'A', 'B', 'C', 'D', //0 to 4
                  'E', 'F', 'G', 'H',       // 5to8
                  'I', 'L', 'M', 'N',       //9to12
                  'O', 'P', 'Q', 'R',       //13to16
                  'S', 'T', 'U', 'V',       //17to20
                  'Z', 0 };                 


char italianExtended[] = { ' ', 'A', 'B', 'C', 'D',
                        'E', 'F', 'G', 'H',
                        'I', 'L', 'M', 'N',
                        'O', 'P', 'Q', 'R',
                        'S', 'T', 'U', 'V',
                        'Z', 'a', 'b', 'c', 'd',
                        'e', 'f', 'g', 'h',
                        'i', 'l', 'm', 'n',
                        'o', 'p', 'q', 'r',
                        's', 't', 'u', 'v',
                        'z', '.', ',', '?',
                        '!', ':', ';', '\'',
                        '0', '1', '2', '3', '4',
                        '5', '6', '7', '8', '9', 0 };

// bey3ed the number of characters in an array
int size_of(char arr[]) {
    int size = 0;
    for (int i = 0; arr[i] != 0; i++) { //le8ayet ma el terminator yeb2a be-zero
        size++;
    }
    return size;
}

int findNo(char c, char arr[]) {
    for (int i = 0; i < size_of(arr); i++) {
        if (arr[i] == c) return i; //returns the index i where the match is found
    }
}

// el bey cipher
string cipher(string& word, int a, int b, char arr[]) {
    int n = size_of(arr);
    string collect; // stores the encryptes text
    for (char letter : word) { // beylef 3ala kol 7arf fe word, and word is the inputted text
        collect += arr[(a * findNo(letter, arr) + b) % n]; //affine cypher formula
    }
    return collect;
}


int main()
{
    string word;
    int a, b;

    cout << "Enter the text to cipher: ";
    getline(cin, word);

    cout << "Enter key a: ";
    cin >> a;

    cout << "Enter key b: ";
    cin >> b;

    cout << cipher(word, a, b, italian);
    return 0;
}