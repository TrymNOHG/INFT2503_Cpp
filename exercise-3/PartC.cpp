//
// Created by Trym Hamer Gudvangen on 8/20/23.
//
#include <cstring>
#include <iostream>
#include <cstring>
#include <vector>

void print_word(const char *word);
void copy_word_to_char_ptr(const char *word, char *sentence);
char *create_sentence(const char* word1, const char* word2, const char* word3);
void make_text_confidential(char *text, char blurChar, int startElement, int endElement);
void copyStrFrom(const char *startPlace, int length, char *newLocation);
bool containsWord(const char *sentence, const char *word);
std::vector<int> find_all_instance_of(const char *phrase, const char *sentence);

int main() {
    std::string word1("Hello");
    std::string word2("Im");
    std::string word3("Trym");

    std::cout << "Oppgave 4.\n\nDel A. \n\n";

    std::cout << word1 << "\n";
    std::cout << word2 << "\n";
    std::cout << word3 << "\n";

    std::cout << "\nDel B\n";

    std::string sentence(word1 + " " + word2 + " " + word3 + ".");
    std::cout << "\nThe sentence is:\n" << sentence << "\n";

    std::cout << "\nDel C\n";
    std::cout << "\nLength of word 1: " << word1.length() << "\n";
    std::cout << "Length of word 2: " << word2.length() << "\n";
    std::cout << "Length of word 3: " << word3.length() << "\n";
    std::cout << "Length of sentence: " << sentence.length() << "\n";

    //Del D
    std::string sentence2 = sentence;

    std::cout << "\nDel E\n";

    //Change characters 10-12 in sentence 2 to x's
    sentence2.replace(10, 3, "xxx");

    std::cout << "\nSentence is:\n" << sentence << "\n";

    std::cout << "\nSentence2 is:\n" << sentence2 << "\n";


    std::string sentence_start = sentence.substr(0, 5);

    std::cout << "\nDel F\n";

    std::cout << "\nSentence is:\n" << sentence << "\n";

    std::cout << "\nSentence_start is:\n" << sentence_start << "\n";

    std::cout << "\nDel G\n";

    size_t firstOccurrence = sentence.find("hallo");
    if(firstOccurrence == std::string::npos) {
        std::cout << "No matches" << "\n";
    } else {
        std::cout << "Yes, there is a match, where the first one is: " << firstOccurrence << "\n";
    }

    std::cout << "\nDel H\n";

    std::cout << "\nIndex of instances of phrase 'Im' in Hello Im Trym." << "\n";

    for(auto &index : find_all_instance_of("Im", sentence.c_str())){
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}

void print_word(const char *word) {
    for(unsigned int i = 0; i < strlen(word); i++) {
        std::cout << *(word+i);
    }
    std::cout << std::endl;
}

void copy_word_to_char_ptr(const char *word, char *sentence) {
    for(unsigned int i = 0; i < strlen(word); i++) {
        *(sentence+i) = *(word+i);
    }
}

char *create_sentence(const char* word1, const char* word2, const char* word3) {
    unsigned int lengthOfWords = strlen(word1) + strlen(word2) + strlen(word3);
    unsigned int lengthOfSentence = lengthOfWords + 3;
    char *sentence = (char *)malloc(sizeof(char) * lengthOfSentence);

    unsigned int currentIndex = 0;

    copy_word_to_char_ptr(word1, sentence);

    currentIndex = strlen(word1);

    copy_word_to_char_ptr(" ", sentence+currentIndex++);
    copy_word_to_char_ptr(word2, sentence+currentIndex);
    currentIndex += strlen(word2);
    copy_word_to_char_ptr(" ", sentence+currentIndex++);
    copy_word_to_char_ptr(word3, sentence+currentIndex);
    currentIndex+= strlen(word3);
    copy_word_to_char_ptr(".", sentence+currentIndex);

    return sentence;
}

void make_text_confidential(char *text, char blurChar, int startElement, int endElement) {
    if ((unsigned) endElement > strlen(text)) return;

    for (int i = startElement; i < endElement + 1; i++) {
        *(text + i) = blurChar;
    }
}

void copyStrFrom(const char *startPlace, int length, char *newLocation){
    for(int i = 0; i < length; i++) {
        *(newLocation+i) = *(startPlace+i);
    }
}

bool containsWord(const char *sentence, const char *word) {
    int numMatches = 0;

    for(unsigned int i = 0; i < strlen(sentence); i++) {
        for(unsigned int j = 0; j < strlen(word); j++) {
            if(*(word+j) == *(sentence+i)){
                numMatches++;
            }
            else {
                numMatches = 0;
                break;
            }
            i++;
        }
        if(numMatches == strlen(word)) {
            return true;
        }
    }

    return false;

}

std::vector<int> find_all_instance_of(const char *phrase, const char *sentence){
    std::vector<int> indices;
    int numMatches = 0;

    for(unsigned int i = 0; i < strlen(sentence); i++) {
        for(unsigned int j = 0; j < strlen(phrase); j++) {
            if(*(phrase+j) == *(sentence+i)){
                numMatches++;
            }
            else {
                numMatches = 0;
                break;
            }
            i++;
        }
        if(numMatches == strlen(phrase)) {
            indices.emplace_back(i - strlen(phrase));
        }
    }
    return indices;
}
