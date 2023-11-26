
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

struct WordCount {
    string word;
    int count;
};

vector<WordCount> tokenize(const string& text) {
    vector<WordCount> words;

    stringstream ss(text);
    string word;
    int count = 0;

    while (ss >> word) {
        if (count > 0) {
            words.push_back({word, count});
            count = 0;
        } else {
            if (word != "") {
                count = 1;
            }
        }
    }

    if (count > 0) {
        words.push_back({word, count});
    }

    return words;
}

double computeDotProduct(const vector<WordCount>& document1, const vector<WordCount>& document2) {
    double dotProduct = 0.0;

    for (const WordCount& word1 : document1) {
        for (const WordCount& word2 : document2) {
            if (word1.word == word2.word) {
                dotProduct += word1.count * word2.count;
                break;
            }
        }
    }

    return dotProduct;
}

double computeMagnitude(const vector<WordCount>& document) {
    double magnitude = 0.0;

    for (const WordCount& word : document) {
        magnitude += word.count * word.count;
    }

    return sqrt(magnitude);
}

int main() {
    const string file1_path ="C:/Users/welly/Downloads/y.txt";
    const string file2_path ="C:/Users/welly/Downloads/y.txt";

    ifstream file1(file1_path);
    ifstream file2(file2_path);

    if (!file1 || !file2) {
        cerr << "Error opening files" << endl;
        return 1;
    }

    string content1, content2;
    getline(file1, content1, '\0');
    getline(file2, content2, '\0');

    vector<WordCount> words1 = tokenize(content1);
    vector<WordCount> words2 = tokenize(content2);

    double dotProduct = computeDotProduct(words1, words2);
    double magnitude1 = computeMagnitude(words1);
    double magnitude2 = computeMagnitude(words2);
    double theta = acos(dotProduct / (magnitude1 * magnitude2));
    double cosine_similarity = dotProduct / (magnitude1 * magnitude2);
    double similarity_percentage = cosine_similarity * 100.0;
     cout << "Dot Product: " << dotProduct << endl;
    cout << "Magnitude of Document 1: " << magnitude1 << endl;
    cout << "Magnitude of Document 2: " << magnitude2 << endl;
    cout << "Angle (in radians) between the documents: " << theta << endl;
    cout << "Cosine Similarity: " << cosine_similarity << endl;
    cout << "Similarity Percentage: " << similarity_percentage << "%" << endl;

    return 0;
}
