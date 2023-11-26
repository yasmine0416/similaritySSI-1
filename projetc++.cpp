/*#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

// Function to tokenize a string into words
vector<string> tokenize(const string &text) {
    vector<string> words;
    stringstream ss(text);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

// Function to compute the dot product of two document vectors
double computeDotProduct(const map<string, int> &document1, const map<string, int> &document2) {
    double dotProduct = 0.0;
    for (const auto &entry : document1) {
        if (document2.count(entry.first)) {
            dotProduct += entry.second * document2.at(entry.first);
        }
    }
    return dotProduct;
}

// Function to compute the magnitude of a document vector
double computeMagnitude(const map<string, int> &document) {
    double magnitude = 0.0;
    for (const auto &entry : document) {
        magnitude += entry.second * entry.second;
    }
    return sqrt(magnitude);
}

int main() {
    // Replace "document1.txt" and "document2.txt" with the paths to your files
    const string file1_path = "C:/Users/welly/Downloads/y.txt";
    const string file2_path = "C:/Users/welly/Downloads/yas.txt";

    // Read the content of two documents from files
    ifstream file1(file1_path);
    ifstream file2(file2_path);

    string content1, content2;
    getline(file1, content1, '\0'); // Read the entire file content
    getline(file2, content2, '\0');

    // Tokenize the documents to create lists of words
    vector<string> words1 = tokenize(content1);
    vector<string> words2 = tokenize(content2);

    // Count word frequencies in each document
    map<string, int> document1;
    map<string, int> document2;

    for (const string &word : words1) {
        document1[word]++;
    }

    for (const string &word : words2) {
        document2[word]++;
    }

    // Compute the dot product and magnitude of the document vectors
    double dotProduct = computeDotProduct(document1, document2);
    double magnitude1 = computeMagnitude(document1);
    double magnitude2 = computeMagnitude(document2);

    // Compute the angle between the vectors
    double theta = acos(dotProduct / (magnitude1 * magnitude2));

    // Compute the cosine similarity and similarity percentage
    double cosine_similarity = dotProduct / (magnitude1 * magnitude2);
    double similarity_percentage = cosine_similarity * 100.0;

    // Output the results
    cout << "Dot Product: " << dotProduct << endl;
    cout << "Magnitude of Document 1: " << magnitude1 << endl;
    cout << "Magnitude of Document 2: " << magnitude2 << endl;
    cout << "Angle (in radians) between the documents: " << theta << endl;
    cout << "Cosine Similarity: " << cosine_similarity << endl;
    cout << "Similarity Percentage: " << similarity_percentage << "%" << endl;

    return 0;
}
*/
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
