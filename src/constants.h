#ifndef CONSTANTS_H
#define CONSTANTS_H

enum class Difficulty : int {
    EASY,
    MEDIUM,
    HARD,
    OVERKILL,
    IMPOSSIBLE
};

// Mine multi factor
// This is a factor of difficulty that will scale the number of mines
constexpr double MULTI_FACTOR_EASY {0.10}; // 10 percent of the map will be mines and so on
constexpr double MULTI_FACTOR_MEDIUM {0.15}; // 15%
constexpr double MULTI_FACTOR_HARD {0.20}; // 20%
constexpr double MULTI_FACTOR_OVERKILL {0.27}; // 27%
constexpr double MULTI_FACTOR_IMPOSSIBLE {0.40}; // 40%

// Number of tries of the user
extern int TRIES;


#endif