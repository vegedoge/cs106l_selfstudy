/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

#include "utils.h"

std::string kYourName = "Melon WU"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cout << "failed to open applicants.csv" << '\n';
  }

  std::set<std::string> applicants;
  std::string single_line;

  // iterate
  while(std::getline(ifs, single_line)) {
    applicants.insert(single_line);
  }

  ifs.close();
  return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string *> matches;

  // split name from ' '
  std::string first = name.substr(0, name.find(' '));
  std::string last = name.substr(name.find(' ') + 1);

  // ATTENTION: use reference to avoid local pointers.
  for (const auto& student : students) {
    std::string first_name = student.substr(0, student.find(' '));
    std::string last_name = student.substr(student.find(' ') + 1);
    if (first_name[0] == first[0] && last_name[0] == last[0]) {
      matches.push(&student);
      printf("match: %s\n", student.c_str());
    }
  }
  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }
  int love_number = 1024;
  int queue_size = matches.size();
  int chosen_number = love_number % queue_size;
  std::string chosen_one;
  printf("queue size: %d\n", queue_size);
  printf("chosen number: %d\n", chosen_number);
  for (int i = 0; i < queue_size; ++i) {
    const std::string* iter = matches.front();
    matches.pop();
    if (chosen_number == 0) {
      printf("chosen one: %s\n", iter->c_str());
      chosen_one = *iter;
      break;
    }
    chosen_number--;
    matches.push(iter);
  }
  return chosen_one.empty() ? "NO MATCHES FOUND." : chosen_one;
}

/* #### Please don't modify this call to the autograder! #### */
int main() {
  std::string first_name, last_name;
  std::cout << "Input your name:" << '\n';
  std::cin >> first_name >> last_name;
  kYourName = first_name + " " + last_name;
  return run_autograder();
}
