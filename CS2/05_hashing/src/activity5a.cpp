/**
 * Activity 5: Example Hashing
 */
#include <iostream>
#include <string>

/* hash function maps strings to unsigned ints */
unsigned int hash(std::string key) {
  unsigned int rtnVal = 3253;
  for (int i = 0; i < key.size(); i++) {
    rtnVal *= 28277;
    rtnVal += key[i] * 2749;
  }
  return rtnVal;
}

/**
 * main gets data to hash at command line
 * usage: h string (table size)
 */
int main(int argc, char *argv[]) {
  unsigned int modNum = 100;  // default hash table size
  if (argc == 2) {
    // hash with default table size
  } else if (argc == 3) {
    modNum = atoi(argv[2]);
  } else {
    std::cout << "Need one or two arguments" << std::endl;
    return EXIT_FAILURE;
  }
  unsigned int hashVal = hash(argv[1]);
  unsigned int moddedHashVal = hashVal % modNum;
  std::cout << "Hash slot for '" << argv[1] << "' is " << moddedHashVal
            << " (hash value=" << hashVal << ")" << std::endl;
  return EXIT_SUCCESS;
}
