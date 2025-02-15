#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */
std::ostream &operator<<(std::ostream& outStream, User& target) {
  outStream << "User(name=" << target.get_name() << ", friends=[";
  for (size_t i = 0; i < target.size(); ++i) {
    outStream << target._friends[i];
    if (i != target.size() - 1) {
      outStream << ", ";
    }
  }
  outStream << "])";
  return outStream;
}

/**
 * Destructor for the User class.
 */
User::~User() {
  delete[] _friends;
}

/**
 * Copy constructor for the User class.
 */
User::User(const User& user)
  : _name(user._name),
  _size(user._size),
  _capacity(user._capacity),
  _friends(new std::string[user._capacity]) {
  for (size_t i = 0; i < _size; ++i) {
    _friends[i] = user._friends[i];
  }
}

/**
 * Copy assignment operator for the User class.
 */
User& User::operator=(const User& user) {
  if (this != &user) {
    delete[] _friends;
    _name = user._name;
    _size = user._size;
    _capacity = user._capacity;
    _friends = new std::string[user._capacity];
    std::copy(user._friends, user._friends + user._size, _friends);
  }
  return *this;
}

/**
 * += operator for the User class.
 */
User& User::operator+=(const User& other) {
  add_friend(other.get_name());
  // cast const type to non-const type
  const_cast<User&>(other).add_friend(_name);
  return *this;
}

/**
 * < operator for the User class.
 */
bool User::operator<(const User& other) const{
  return _name < other.get_name();
}