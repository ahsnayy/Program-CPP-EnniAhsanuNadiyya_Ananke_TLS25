#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string reverseString(string text) {
    string result = "";
    for (int i = text.size() - 1; i >= 0; i--) {
        result += text[i];
    }
    return result;
}

bool isVowel(char c) {
    string vowels = "aiueoAIUEO";
    for (char v : vowels) if (c == v) return true;
    return false;
}

string extractDigits(const string &s, int &start, int &end) {
    start = -1; end = -1;
    for (int i = 0; i < (int)s.size(); i++) {
        if (isdigit((unsigned char)s[i])) {
            if (start == -1) start = i;
            end = i;
        } else {
            if (start != -1) break;
        }
    }
    if (start == -1) return "";
    return s.substr(start, end - start + 1);
}

string encrypt(const string &word) {
    string consonants = "";
    for (int i = 0; i < word.size(); i++) {
        if (!isVowel(word[i])) { 
            consonants += word[i];
        }
    }

    string reversed = reverseString(consonants);
    string number = to_string(int(word[0]));
    string encrypted = "";
    int mid = reversed.size() / 2;

    if (reversed.size() % 2 == 0) {
        for (int i = 0; i < mid; i++) encrypted += reversed[i];
        encrypted += number;
        for (int i = mid; i < reversed.size(); i++) encrypted += reversed[i];
    } else {
        for (int i = 0; i <= mid; i++) encrypted += reversed[i];
        encrypted += number;
        for (int i = mid + 1; i < reversed.size(); i++) encrypted += reversed[i];
    }

    return encrypted;
}

string decrypt(const string &password) {
    int start = -1, end = -1;
    string digits = extractDigits(password, start, end);
    if (digits.empty()) return "";

    int convertedDigits = stoi(digits); 
    char charVal = (char)convertedDigits;

    string withoutDigits = password.substr(0, start) + password.substr(end + 1);
    string oriConsonant = reverseString(withoutDigits);

    string decodedPass = string(1, charVal) + oriConsonant;
    return decodedPass;
}

int main() {
    cout << "---Mysterious Machine---\n";
    int choice;
    cout << "What do you wanna do?\n1. Encrypt\n2. Decrypt\nChoose: ";
    cin >> choice;

    if (choice == 1) {
        string word;
        cout << "Enter the word: ";
        cin >> word;
        string pw = encrypt(word);
        cout << "Generated password: " << pw << endl;
    }
    else if (choice == 2) {
        string pw;
        cout << "Enter password: ";
        cin >> pw;

        int start, end;
        string digits = extractDigits(pw, start, end);
        if (!digits.empty()) {
            int asciiVal = stoi(digits);
            char charVal = (char)asciiVal;
            cout << "Extracted ASCII code: " << asciiVal << " = '" << charVal << "'" << endl;
        }

        cout << "Reconstructed: " << decrypt(pw) << "\n";
    }
    else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
