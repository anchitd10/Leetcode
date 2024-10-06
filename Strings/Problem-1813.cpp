// Problem-1813: Sentence Similarity II

// You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.
// Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.
// For example,
// s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
// s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
// Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

class Solution {
public:
    //here the only the words in the middle will be missing
    bool areSentencesSimilar(string sentence1, string sentence2) {
        //length of sentence1 should always be greater
        if(sentence1.length() < sentence2.length()){
            swap(sentence1, sentence2);
        }

        vector<string> words1, words2;
        string word;

        stringstream stream1(sentence1);
        while(stream1 >> word){
            words1.push_back(word);
        }

        stringstream stream2(sentence2);
        while(stream2 >> word){
            words2.push_back(word);
        }

        int i=0, j=words1.size()-1;
        int k=0, l=words2.size()-1;

        while(i < words1.size() && k < words2.size() && words1[i] == words2[k]){
            i++;
            k++;
        }
        while(l >= k && words1[j] == words2[l]){
            j--;
            l--;
        }
        return l<k;
    }
};