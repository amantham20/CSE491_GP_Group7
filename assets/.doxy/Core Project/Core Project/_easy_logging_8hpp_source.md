

# File EasyLogging.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**EasyLogging.hpp**](_easy_logging_8hpp.md)

[Go to the documentation of this file](_easy_logging_8hpp.md)

```C++


#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

namespace clogged {

enum class LogLevel { DEBUG, INFO, WARNING, ERR, NA };

enum class Team {
  TEAM_1,
  TEAM_2,
  TEAM_3,
  TEAM_4,
  TEAM_5,
  TEAM_6,
  TEAM_7,
  TEAM_8,
  TEAM_9,
  GENERAL,
  NA
};

enum class Color { RESET = 0, BLUE = 34, GREEN = 32, RED = 31 };

const LogLevel LOGLEVEL = LogLevel::DEBUG;

#ifndef NDEBUG

#define LOGLINE "File: " << __FILE__ << "::->::Line(" << __LINE__ << ")"

#define RELATIVE_PATH(file)                                                  \
  (std::string(file).find_last_of("/\\") != std::string::npos                \
       ? std::string(file).substr(std::string(file).find_last_of("/\\") + 1) \
       : std::string(file))

#define LOG_RELLINE "File: " << RELATIVE_PATH(__FILE__) << "::->::Line(" << __LINE__ << ")"

#define LOG_FNC "Function: " << __func__ << " "


class Logger {
public:
  Logger &operator<<(Team team) {
    currentTeam = team;
    metaPrinted = false;
    //         std::cout << endl; //TODO: Might have to enable this so that we
    //         can have same line logging when endl is not used
    return *this;
  }

  Logger &operator<<(LogLevel logLevel) {
    currentLogLevel = logLevel;
    metaPrinted = false;
    return *this;
  }

  Logger &operator<<(Color color) {
    currentColor = color;
    return *this;
  }

  Logger &operator<<(std::ostream &(*manipulator)(std::ostream &)) {
    typedef std::ostream &(*EndlManipulator)(std::ostream &);

    // Compare the function pointers
    if (manipulator == static_cast<EndlManipulator>(std::endl) || manipulator == endl) {
      // Handle std::endl here
      currentTeam = Team::NA;
      currentLogLevel = LogLevel::DEBUG;
      currentColor = Color::RESET;

      std::cout << std::endl;

      metaPrinted = false;
    }

    return *this;
  }

  template <typename T>
  Logger &operator<<(const T &value) {
    // TODO: Define when to log by loglevel comparison. Goal is to send it in as
    // a flag in the CMakeLists.txt
    if (currentLogLevel >= LOGLEVEL) {
      // added additional flag in case one wants to compile without colors (or)
      // if the terminal does not support colors
#ifndef D_ANSI_COLOR_CODES
      std::string colorStart = "\033[" + std::to_string(static_cast<int>(currentColor)) + "m";
      std::string colorEnd = "\033[0m";
#else
      std::string colorStart = "";
      std::string colorEnd = "";
#endif
      std::ostringstream logMessage;
      logMessage << colorStart;
      if (!metaPrinted) {
        logMessage << teamToString(currentTeam) << logToString(currentLogLevel);
        metaPrinted = true;
      }

      logMessage << value << colorEnd;
      std::cout << logMessage.str();  // << std::endl;  //TODO: Might have to
                                      // make enable this so that we can have
                                      // same line logging when endl is not used
    }

    return *this;
  }

  static Logger &Log() {
    static Logger instance;  // Guaranteed to be initialized only once.
    return instance;
  }

  template <typename T, typename... EXTRA_Ts>
  static Logger &Log(T &&arg1, EXTRA_Ts &&...extra_args) {
    Log() << std::forward<T>(arg1);            // Log the first argument.
    if constexpr (sizeof...(EXTRA_Ts) == 0) {  // No arguments left.
      return Log() << Logger::endl;            // Trigger a flush.
    } else {
      return Log(std::forward<EXTRA_Ts>(extra_args)...);  // Log remaining arguments.
    }
  }

  static std::ostream &endl(std::ostream &os) {
    Log() << std::endl;  // Call the custom Logger::endl to reset values
    return os;
  }

private:
  Team currentTeam = Team::NA;

  LogLevel currentLogLevel = LogLevel::DEBUG;

  Color currentColor = Color::RESET;

  bool metaPrinted = false;

  std::map<Team, std::string> teamToStringMap = {
      {Team::TEAM_1, "Team 1"},  {Team::TEAM_2, "Team 2"}, {Team::TEAM_3, "Team 3"},
      {Team::TEAM_4, "Team 4"},  {Team::TEAM_5, "Team 5"}, {Team::TEAM_6, "Team 6"},
      {Team::TEAM_7, "Team 7"},  {Team::TEAM_8, "Team 8"}, {Team::TEAM_9, "Team 9"},
      {Team::GENERAL, "General"}};

  std::string teamToString(Team team) {
    auto it = teamToStringMap.find(team);
    if (it != teamToStringMap.end()) {
      return "[" + it->second + "]";
    }

    return "";
  }

  std::string logToString(LogLevel logLevel) {
    if (logLevel == LogLevel::DEBUG) {
      return "(DEBUG) ";
    } else if (logLevel == LogLevel::INFO) {
      return "(INFO) ";
    } else if (logLevel == LogLevel::WARNING) {
      return "(WARNING) ";
    } else if (logLevel == LogLevel::ERR) {
      return "(ERROR) ";
    } else {
      return "";
    }
  }
};

#else

#define LOGLINE ""
#define LOG_RELLINE ""
#define LOG_FNC ""

// #define log Log()

class Logger {
public:
  template <typename T>
  Logger &operator<<(const T & /*value*/) {
    return *this;
  }

  Logger &operator<<(std::ostream &(* /*manipulator*/)(std::ostream &)) { return *this; }

  static std::ostream &endl(std::ostream &os) { return os; }

  static Logger &Log() {
    static Logger instance;  // Guaranteed to be initialized only once.
    return instance;
  }
};

// Logger Logger::log;
#endif

}  // namespace clogged

```

