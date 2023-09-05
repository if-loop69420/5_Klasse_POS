#include <iostream>
#include <experimental/random>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>

using namespace std;
using std::experimental::randint;


vector<int> find_letter_pos_in_string(char letter, char* string) {
  vector<int> positions = vector<int>();

  for(int i = 0; i < strlen(string); i++) {
    if(string[i] == letter) {
      positions.push_back(i);
    }
  }

  return positions;
}


void draw_galgen(int galgen_state) {
  const string states[9] = {
    "",
    "\
      \n \
      \n \
      \n \
      \n \
      \n \
      \n \
    =====      \n \
    |   |      ",
    "\
      ________ \n \
      |      | \n \
      |        \n \
      |        \n \
      |        \n \
      |        \n \
    =====      \n \
    |   |      ",
    "\
      ________  \n \
      |      |  \n \
      |      O  \n \
      |         \n \
      |         \n \
      |         \n \
    =====       \n \
    |   |       ",
    "\
      ________  \n \
      |      |  \n \
      |      O  \n \
      |      |  \n \
      |         \n \
      |         \n \
    =====       \n \
    |   |       ",
    "\
      ________  \n \
      |      |  \n \
      |      O  \n \
      |     \\|  \n \
      |         \n \
      |         \n \
    =====       \n \
    |   |       ",
    "\
      ________  \n \
      |      |  \n \
      |      O  \n \
      |     \\|/ \n \
      |         \n \
      |         \n \
    =====       \n \
    |   |       ",
    "\
      ________  \n \
      |      |  \n \
      |      O  \n \
      |     \\|/ \n \
      |     /   \n \
      |         \n \
    =====       \n \
    |   |       ",
    "\
      ________  \n \
      |      |  \n \
      |      O  \n \
      |     \\|/ \n \
      |     / \\\n \
      |         \n \
    =====       \n \
    |   |       "
  };

  cout << states[galgen_state] << endl;
}


int main() { 
  srand(time(nullptr));
  string solutions[4] = {"Hello", "World", "Debug", "Command"};
  int index = randint(0,3);

  string word_to_guess = solutions[index];
  char* word_as_char = new char[word_to_guess.length()];
  char* guess_word = new char[word_to_guess.length()];
  for(int i = 0; i < word_to_guess.length(); i++) {
    guess_word[i] = '_';
  }
  strncpy(word_as_char, word_to_guess.c_str(), sizeof(word_as_char));
  word_as_char[sizeof(word_as_char) - 1] = 0;
  cout << "\033c";
  cout << "The word is " << word_to_guess.length() << " long" << endl;

  int max_guesses = 8;
  int current_guesses = 0;
  while(strcmp(word_as_char,guess_word) != 0 && current_guesses < max_guesses) {
    draw_galgen(current_guesses);
    cout << guess_word << endl;
    string input = "";
    cout << "Please input a guess letter" << endl;
    cin >> input;
    if(input.length() > 1) {
      cout << "Only one letter" << endl;
      continue;
    }
    vector<int> occurences = find_letter_pos_in_string(input.at(0), word_as_char);
    if(occurences.empty()) {
      cout << "Letter not in word" << endl;
      current_guesses++;
    } else {
      for(auto occurence : occurences) {
        guess_word[occurence] = input.at(0);
      }
    }
    cout << "\033c";
  }

  draw_galgen(current_guesses);
  if(current_guesses < max_guesses) { 
    cout << "You won. The word is: " << word_to_guess << endl;
    cout << "You got it wrong " << current_guesses << " times" << endl << endl;;
  } else {
    cout << "You lost. You got " << current_guesses << " wrong" << endl; 
  }

  delete word_as_char;
  delete guess_word;
}
