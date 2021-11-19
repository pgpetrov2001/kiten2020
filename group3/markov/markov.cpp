#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

string sanitize = "\":,@#$%^&*()_-=+[]\\;></`~";

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
map<string, int> occ;
map<string, map<string, int>> next_word[10];

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

    string filename;
    cin >> filename;
    ifstream textfile(filename);

    string word, prevword="";

    while (textfile >> word) {
        word = getSanitized(word);
        if (word[word.size()-1] == '.' || word[word.size()-1] == '?' || 
            word[word.size()-1] == '!') {
            string mark = ""+word[word.size()-1];
            next_word [category[mark]] [word] [mark] ++;
            word = word.substr(0, word.size()-1);
        }
        occ[word]++;

        if (prevword != "") {
            next_word [category[word]] [prevword] [word] ++;
        }
    }

    string startword;
    cin >> startword;

    ifstream sentencesfile("sentences");
    vector<vector<int>> sentences;
    string sentenceStr;

    while (sentencesfile >> sentenceStr) {
        sentences.push_back({});
        for (char ch : sentence) {
            sentences.back().push_back(ch-'0');
        }
    }

    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(0, sentences.size());

    vector<int> sentence;

    do {
        sentence = sentences[dist(rng)];
    } while (sentence[0] != category[startword]); 

    string prevword = startword, currword;
    int i = 1;

    for (int partOfSpeech : sentence) {
        if (sentence[i] == category["."] || sentence[i] == category["!"] || 
            sentence[i] == category["?"]) {
            break;
        }

        uniform_int_distribution<int> dist(0, occ[prevword]);
        int selection = dist(rng);
        int currsz = 0;

        for (auto element : next_word [sentence[i]] [prevword]) {
            currsz += element.second;
            if (selection < currsz) {
                currword = element.first;
                break;
            }
        }

        prevword = currword;
        cout << currword << " ";
    }

    cout << "\n";

}


