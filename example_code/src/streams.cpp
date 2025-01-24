#include <iostream>
#include <sstream>

int main() {
  /// partial Bjarne Quote
  std::string initial_quote = "Shall I compare thee to a summer day";

  // create a string stream
  std::stringstream ss;
  ss << initial_quote;

  // data destinations
  std::string first;
  std::string second;
  std::string third, sentence;

  // extract from stream
  ss >> first >> second >> third;
  // extract sentence from stream
  std::getline(ss, sentence);

  //output
  std::cout << first << " " << second << " and " << third << ""
            << sentence << std::endl;

  
}