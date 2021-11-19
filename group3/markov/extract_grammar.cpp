#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

string sanitize = "\":,@#$%^&*()_=+[]\\;></`~";

string getSanitized(const string& word) {
    string sanitized;
    for (char ch : word) {
        bool add = true;
        for (char no : sanitize) {
            if (no == ch) {
                add = false;
            }
        }
        if (add) {
            sanitized.push_back(ch);
        }
    }
    return sanitized;
}

map<string, int> category;

int main() {
    ifstream nouns("nouns");
    ifstream adjectives("adjectives");
    ifstream adverbs("adverbs");
    ifstream verbs("verbs");

    string word;
    int currCategory = 0;

    while (nouns >> word) {
        category[word] = currCategory;
    }
    currCategory++;
    while (adjectives >> word) {
        category[word] = currCategory;
    }
    currCategory++;
    while (adverbs >> word) {
        category[word] = currCategory;
    }
    currCategory++;
    while (verbs >> word) {
        category[word] = currCategory;
    }
    currCategory++;

    string marks = ".?!";
    for (char mark : marks) {
        category[""+mark] = currCategory++;
    }

    ofstream sentences("sentences");
    vector<int> currSentence;

    while (cin >> word) {
        word = getSanitized(word);

        if (currSentence.size() == 0) {
            word[0] = tolower(word[0]); 
        }

        bool terminate = false;
        for (char mark : marks) 
            if (word[word.size()-1] == mark) {
                terminate = true;
            }

        if (terminate) {
            currSentence.push_back(category[word.substr(0,word.size()-1)]);
            currSentence.push_back(category[""+word[word.size()-1]]);
            for (int num : currSentence) {
                sentences << num;
            }
            sentences << "\n";
            currSentence.clear();
        } else {
            currSentence.push_back(category[word]);
        }
    }
}
