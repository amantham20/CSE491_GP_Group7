

# File Serialize.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**Serialize.hpp**](_serialize_8hpp.md)

[Go to the documentation of this file](_serialize_8hpp.md)

```C++


#pragma once

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

namespace cse491 {

// --- Pre-declarations of Functions ---
template <typename T> static void SerializeValue_Vector(std::ostream &, const std::vector<T> &);
template <typename T> static void SerializeValue_Map(std::ostream &, const T &);
template <typename T> static void DeserializeValue_Vector(std::istream &, std::vector<T> &);
template <typename T> static void DeserializeValue_Map(std::istream &, T &);


// --- Type Traits ---

template <typename T> struct is_vector : std::false_type {};
template <typename T> struct is_vector<std::vector<T>> : std::true_type {};

template <typename T>
struct is_any_map : std::false_type {};
template <typename KEY_T, typename VALUE_T>
struct is_any_map<std::map<KEY_T, VALUE_T>> : std::true_type {};
template <typename KEY_T, typename VALUE_T>
struct is_any_map<std::unordered_map<KEY_T, VALUE_T>> : std::true_type {};

template <typename STREAM_T, typename OBJ_T>
concept CanStreamTo = requires(STREAM_T & stream, OBJ_T value) {
  { stream << value } -> std::convertible_to<std::ostream&>;
};

template <typename STREAM_T, typename OBJ_T>
concept CanStreamFrom = requires(STREAM_T & stream, OBJ_T value) {
  { stream >> value } -> std::convertible_to<std::istream&>;
};

template <typename OBJ_T>
concept HasSerialize = requires(OBJ_T value) {
  { value.Serialize(std::cout) } -> std::same_as<void>;
};

template <typename OBJ_T>
concept HasDeserialize = requires(OBJ_T value) {
  { value.Deserialize(std::cin) } -> std::same_as<void>;
};

template <typename T>
static void SerializeValue(std::ostream & os, const T & var) {
  if constexpr (std::is_enum<T>()) {
    os << static_cast<int>(var) << std::endl;
  } else if constexpr (is_vector<T>()) {
    SerializeValue_Vector(os, var);
  } else if constexpr (is_any_map<T>()) {
    SerializeValue_Map(os, var);
  } else if constexpr (HasSerialize<T>) {
    var.Serialize(os);
  } else if constexpr (CanStreamTo<std::stringstream, T>) {
    os << var << '\n';
  } else {
  }
}

template <typename T>
static void SerializeValue_Vector(std::ostream & os, const std::vector<T> & var) {
  SerializeValue(os, var.size());
  for (const auto & x : var) {
    SerializeValue(os, x);
  }
}

template <typename T>
static void SerializeValue_Map(std::ostream & os, const T & var) {
  SerializeValue(os, var.size());
  for (const auto & [key, value] : var) {
    SerializeValue(os, key);
    SerializeValue(os, value);
  }
}

template <typename T>
static void DeserializeValue(std::istream & is, T & var) {
  static_assert(!std::is_const<T>(), "Cannot deserialize const variables.");

  // If we are loading a string, load it directly.
  if constexpr (std::is_same<std::decay_t<T>, std::string>()) {
    std::getline(is, var, '\n');
  } else if constexpr (is_vector<T>()) {
    DeserializeValue_Vector(is, var);
  } else if constexpr (is_any_map<T>()) {
    DeserializeValue_Map(is, var);
  } else if constexpr (HasDeserialize<T>) {
    var.Deserialize(is);
  } else {
    // @CAO: This can be streamlined to use only the original is, and based on type.
    //       For example, "is << var" followed by "is.peek()" to make sure we have a
    //       newline, and then "is.ignore()" to skip the newline.
    std::string str;
    std::getline(is, str, '\n');
    std::stringstream ss(str);
    if constexpr (std::is_enum<T>()) { // enums must be converted properly.
      int enum_val;
      ss >> enum_val;
      var = static_cast<T>(enum_val);
    } else if constexpr (CanStreamFrom<std::stringstream, T>) {
      ss >> var;
    } else if constexpr (std::is_pointer<T>()) {
      std::cerr << "Warning: Attempting to deserialize pointer." << std::endl;
    } else { 
      // Finally, ignore this value?  Most likely a pointer.
      std::cerr << "Warning: Attempting to deserialize unknown type." << std::endl;
    }
  }
}

template <typename T>
static void DeserializeFunction(std::istream & is, std::function<void(T)> set_fun) {
  std::string str;
  std::getline(is, str, '\n');
  if constexpr (std::is_same<std::decay_t<T>, std::string>()) {
    set_fun(str);
  } else if constexpr (std::is_same<std::decay_t<T>, int>()) {
    set_fun(stoi(str));
  } else if constexpr (std::is_same<std::decay_t<T>, double>()) {
    set_fun(stod(str));
  } else {
    T var;
    std::stringstream ss(str);
    ss >> var;
    set_fun(var);
  }
}

template <typename T>
static T DeserializeAs(std::istream & is) {
  T value;
  DeserializeValue(is, value);
  return value;
}

template <typename T>
static void DeserializeValue_Vector(std::istream & is, std::vector<T> & var) {
  DeserializeFunction<size_t>(is, [&var](size_t in_size){ var.resize(in_size); } );
  for (auto & x : var) {
    DeserializeValue(is, x);
  }
}

template <typename MAP_T>
static void DeserializeValue_Map(std::istream & is, MAP_T & var) {
  size_t map_size = 0;
  typename MAP_T::key_type key;
  typename MAP_T::mapped_type value;
  DeserializeValue(is, map_size);
  for (size_t i = 0; i < map_size; ++i) {
    DeserializeValue(is, key);
    DeserializeValue(is, value);
    var[key] = value;
  }
}

}  // End of namespace cse491

```

