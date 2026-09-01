#include <iostream>
#include <vector>
#include <string>

using namespace std;

void seqSearchString(const string &s, char &foundChar, int &comparisons) {
    comparisons = 0;
    int len = s.length();
    
    if (len == 1) {
        comparisons = 1;
        foundChar = s[0];
        return;
    }
    
    for (int i = 0; i < len; i += 2) {
        comparisons++;
        if (i + 1 >= len || s[i] != s[i + 1]) {
            foundChar = s[i];
            return;
        }
    }
    foundChar = s[0];
}

void binSearchString(const string &s, char &foundChar, int &comparisons) {
    comparisons = 0;
    int left = 0;
    int right = s.length() - 1;
    int len = s.length();
    
    if (len == 1) {
        comparisons = 1;
        foundChar = s[0];
        return;
    }

    while (left < right) {
        comparisons++; // incrementar por la iteración de búsqueda
        int mid = left + (right - left) / 2;
        
        if (mid % 2 == 1) {
            mid--;
        }
        
        comparisons++; // incrementar por la comparación de adyacencia
        if (s[mid] == s[mid + 1]) {
            left = mid + 2;
        } else {
            right = mid;
        }
    }
    foundChar = s[left];
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<string> cadenas(n);
    for (int i = 0; i < n; i++) {
        cin >> cadenas[i];
    }
    
    for (int i = 0; i < n; i++) {
        char charSeq, charBin;
        int compSeq = 0, compBin = 0;
        
        seqSearchString(cadenas[i], charSeq, compSeq);
        binSearchString(cadenas[i], charBin, compBin);
        
        cout << charSeq << " " << compSeq << " " << charBin << " " << compBin << endl;
    }
    
    return 0;
}