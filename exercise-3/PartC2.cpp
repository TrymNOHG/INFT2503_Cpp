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
    char word1[] = "Hello";
    char word2[] = "Im";
    char word3[] = "Trym";

    print_word(word1);
    print_word(word2);
    print_word(word3);

    char *sentence = create_sentence(word1, word2, word3);
    std::cout << "\nThe sentence is:\n";
    print_word(sentence);

    std::cout << "\nLength of word 1: " << strlen(word1) << "\n";
    std::cout << "Length of word 2: " << strlen(word2) << "\n";
    std::cout << "Length of word 3: " << strlen(word3) << "\n";
    std::cout << "Length of sentence: " << strlen(sentence) << "\n";

    char *sentence2 = (char *) malloc(sizeof(char) * strlen(sentence));

    copy_word_to_char_ptr(sentence, sentence2);

    //Change characters 10-12 in sentence 2 to x's
    make_text_confidential(sentence2, 'x', 10, 12);

    std::cout << "\nSentence is:\n";
    print_word(sentence);
    std::cout << "\n";

    std::cout << "Sentence2 is:\n";
    print_word(sentence2);

    int length = 5;
    char *sentence_start = (char *) malloc(sizeof(char) * length);
    copyStrFrom(sentence, length, sentence_start);

    std::cout << "\nsentence is:\n";
    print_word(sentence);

    std::cout << "\nsentence_start is:\n";
    print_word(sentence_start);
    std::cout << "\n";

    std::cout << containsWord("Hello my name is Trym", "hallo") << "\n";
    std::cout << containsWord("Hello my name is Trym", "my name") << "\n";

    std::cout << "\nIndex of instances of phrase 'Im' in Hello Im Trym." << "\n";
    for(auto &index : find_all_instance_of("Im", sentence)){
        std::cout << index;
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
