class Solution {
public:
    int lengthOfLastWord(string s) {
            // Create a stringstream object
    stringstream ss(s);
    
    // Variable to hold each word
    string word;
    
    // Vector to store the words
    vector<string> words;
    
    // Extract words from the sentence
    while (ss >> word) {
      
        // Add the word to the vector
        words.push_back(word);
    }

    int n = words.size();
    string last_word = words[n-1];

    return last_word.size();
    }
};