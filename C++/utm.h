#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

namespace penrose {
  const std::vector<int> delimiter { 1, 1, 1, 1, 1, 0 };

  const std::vector<int> un1 { 1,0,1,0,1,1,0,1,0,1,1,1,1,0,1,0,1,0 };

  const std::vector<int> xn2 {
    1,0,0,1,1,0,1,0,1,1,0,1,0,0,0,1,1,0,1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,1 };

  const std::vector<int> un2 {
    1,0,0,1,1,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,1,0,1,0,1,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,1,1,1,1,0,1,\
    0,1,0,1,0,1,1,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,1,0,1 };

  const std::vector<int> xn1 {
    1,0,1,0,1,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,1,1,0,1,0,1,1,1,1,0,1,0,0,0,\
    0,1,1,1,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,1,0,1,0,0,1,0,1,1,0,1,1,0,\
    1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0 };

  const std::vector<int> euc {
    1,0,1,0,1,1,1,0,1,0,0,1,0,1,1,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,0,1,1,0,1,0,1,0,0,1,1,0,1,0,0,0,\
    0,1,1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,1,1,1,0,1,0,1,0,0,\
    1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,1,1,0,1,0,0,0,0,1,0,1,1,1,0,\
    1,0,0,0,1,0,0,1,1,1,0,1,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,1,0,1,0,1,0,1,1,1,0,1,1,1,1,0,1,0,0,1,\
    0,0,1,0 };

  const std::vector<int> utm {
    1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,0,0,1,1,0,1,0,\
    0,0,1,0,1,0,0,0,0,0,1,1,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,0,0,0,1,1,0,1,\
    0,0,0,1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,\
    0,0,1,1,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,\
    1,0,1,1,0,1,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,1,0,\
    1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1,0,1,0,0,1,\
    0,1,0,0,1,1,0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,0,1,0,0,0,0,1,1,1,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,\
    1,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1,0,\
    1,1,0,1,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,1,0,\
    1,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,0,\
    0,0,1,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,1,0,1,0,0,1,0,\
    0,0,0,1,0,1,0,0,1,1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,0,0,0,1,0,1,1,0,1,0,1,0,0,0,1,0,1,\
    1,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,0,0,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1,\
    0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,1,0,0,0,1,0,1,1,0,1,0,\
    1,0,0,0,0,1,0,1,1,0,1,0,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,1,0,1,0,0,1,0,1,0,\
    1,0,0,1,0,0,1,0,1,1,0,1,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,1,1,0,1,0,1,0,0,1,\
    0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,\
    0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,0,1,0,\
    1,1,1,0,1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0,1,0,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,\
    1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,\
    1,1,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,1,1,\
    1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,1,\
    1,0,1,0,0,0,1,0,0,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1,1,0,1,\
    0,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,\
    1,0,0,1,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,0,1,1,0,1,0,0,\
    1,0,0,0,1,0,1,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,1,0,\
    0,0,1,1,0,1,0,0,0,0,0,1,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,\
    0,1,0,0,1,0,1,0,1,0,0,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0,0,0,1,0,0,1,1,1,0,1,0,0,\
    1,0,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,0,\
    0,0,1,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,\
    1,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,1,0,0,1,0,1,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,\
    1,1,0,1,0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,1,0,0,0,1,0,1,1,0,1,0,1,0,0,1,0,1,0,0,1,1,0,1,0,1,0,1,\
    0,0,0,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,1,1,0,1,0,1,0,1,\
    0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,0,\
    1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,0,0,\
    1,0,1,1,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,1,0,0,0,0,\
    1,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,\
    0,1,0,0,1,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,0,0,0,1,1,0,1,0,0,1,0,0,\
    0,1,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,0,0,1,1,0,1,\
    0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,0,\
    0,1,0,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,0,1,1,1,0,1,0,1,0,1,0,0,1,1,0,1,0,0,0,0,0,1,0,1,\
    0,1,0,1,1,0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,\
    1,0,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1,1,0,1,0,0,0,0,1,0,1,\
    0,0,1,0,1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,\
    1,0,0,1,1,0,1,0,0,0,1,0,0,1,0,0,1,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,\
    0,1,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,\
    0,0,0,0,1,0,1,1,0,1,0,1,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,0,1,1,0,1,\
    0,1,0,0,0,0,1,0,0,0,1,0,1,1,0,1,0,1,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,1,0,1,0,1,0,1,0,\
    0,1,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,\
    1,0,1,0,0,0,1,1,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1,0,0,1,1,0,1,0,0,1,0,0,0,1,\
    0,0,1,0,1,1,1,0,1,0,0,1,0,0,0,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,0,1,0,1,0,\
    0,1,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,\
    0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,0,1,0,0,1,1,0,1,0,1,0,1,\
    0,1,0,0,0,0,1,0,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,\
    0,0,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,\
    1,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,0,1,\
    0,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,0,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,\
    1,0,1,0,1,1,1,0,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,0,1,0,1,0,0,0,0,0,0,1,0,\
    1,1,1,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,0,0,\
    0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,1,0,1,0,1,0,0,1,1,0,1,0,1,\
    0,0,0,1,0,0,0,1,0,1,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,1,0,1,0,0,\
    0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,1,\
    0,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1,0,1,0,0,0,1,1,\
    1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,0,\
    1,0,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,1,0,1,0,\
    0,0,1,0,1,1,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,1,\
    0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,1,0,0,0,\
    0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,\
    0,1,0,0,0,0,0,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,1,0,1,0,1,0,1,0,\
    0,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,0,\
    1,0,0,1,0,0,0,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,1,1,1,0,1,0,1,\
    0,0,1,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,\
    1,1,0,1,0,0,0,0,0,0,1,0,0,1,1,0,1,0,1,0,1,0,1,0,0,1,0,0,1,1,1,0,1,0,1,0,0,1,1,0,1,0,1,0,1,0,\
    1,0,0,1,0,0,1,0,1,1,0,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,\
    0,1,0,1,0,0,1,0,1,0,1,1,0,1,0,1,0,0,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,0,1,0,\
    0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,\
    0,1,0,1,0,1,0,1,1,0,1,0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,0,\
    0,1,1,1,0,1,0,0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,\
    1,0,0,0,1,0,1,0,0,1,1,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,\
    1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,0,\
    0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,0,0,0,1,0,0,1,0,1,\
    0,1,1,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,0,1,1,1,1,0,1,0,0,0,0,1,\
    0,0,0,0,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,\
    0,1,0,1,0,0,1,0,1,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1,1,0,1,0,0,\
    0,1,0,0,0,0,1,1,1,0,1,0,1,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,1,\
    0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,1,0,1,0,0,0,1,0,0,1,0,\
    1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,1,1,\
    0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,\
    1,0,0,0,0,0,0,1,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,0,1,\
    0,1,1,1,0,1,0,0,1,0,0,0,0,0,1,1,1,0,1,0,1,0,0,1,0,0,1,0,0,1,1,0,1,0,0,0,0,0,0,1,0,1,0,1,1,1,\
    0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,0,1,1,1,0,1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,\
    1,0,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,\
    1,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,1,0,1,0,1,0,1,0,0,1,1,0,1,\
    0,0,0,1,0,1,0,0,1,0,0,1,0,1,1,0,1,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,1,0,0,1,1,\
    0,1,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,1,1,0,\
    1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,0,1,1,0,1,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,\
    1,1,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,1,0,1,0,0,1,0,0,\
    0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,1,0,1,0,0,1,0,1,0,1,0,\
    1,1,0,1,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,\
    1,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,1,0,1,0,1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,1,0,1,0,0,\
    1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,0,1,0,0,\
    1,0,0,1,0,0,1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,1,0,1,0,0,1,0,1,1,0,\
    1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,1,1,0,0,1,1,0,\
    1,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,1,0,1,1,1,0,0,1,1,\
    0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,1,1,0,0,1,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,1,1,0,1,0,0,\
    0,1,0,0,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,1,0,1,0,\
    0,0,1,0,1,0,1,1,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,\
    1,1,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,1,1,1,0,0,1,1,0,1,0,0,1,0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,0,\
    0,1,1,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,0,0,1,1,0,1,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,1,1,0,\
    1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,0,1,\
    0,0,1,0,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,1,1,0,0,1,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,\
    1,0,0,1,1,0,1,0,1,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,\
    1,1,0,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,0,\
    1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,1,0,0,1,\
    1,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,1,0,1,0,0,0,0,0,\
    0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,0,0,1,1,0,1,0,1,\
    0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,1,0,0,0,1,1,1,0,1,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0,0,1,1,0,1,\
    0,1,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,\
    0,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,\
    1,0,0,0,0,1,1,0,1,0,1,0,0,0,1,0,0,1,0,1,0 };

  class tape {
  public:
    virtual int pop() = 0;
    virtual void push(int x) = 0;
    virtual void insert(const std::vector<int>& in) = 0;
    virtual std::string toString() = 0;//左テープの整形
  };

  //listを使ってテープを表現する。
  //テープの先頭（ヘッド側）はlistの先頭。
  class listTape : public tape {
  private:
    std::list<int> data;
  public:
    std::string toString() {
      std::string result;
      std::copy(find(data.rbegin(), data.rend(), 1), data.rend(), back_inserter(result));
      for (auto& c : result) {
        c += '0';
      }
      return result;
    }
    void insert(const std::vector<int>& in) {
      std::copy(in.cbegin(), in.cend(), back_inserter(data));
    }
    int pop() {
      if (data.empty()) return 0;
      else {
        auto tmp = data.front();
        data.pop_front();
        return tmp;
      }
    }
    void push(int x) {
      data.push_front(x);
    }
  };

  //文字列を使ってテープを表現する。
  //テープの先頭（ヘッド側）は文字列の末尾。
  //右テープの表示（未実装）に注意。
  class stringTape : public tape {
  private:
    std::string data;
  public:
    std::string toString() {
      auto tmp = data.substr(data.find(1));
      for (auto& c : tmp) {
        c += '0';
      }
      return tmp;
    }
    void insert(const std::vector<int>& in) {
      for (auto x : in) {
        data.insert(data.begin(), x);
      }
    }
    int pop() {
      if (data.empty()) return 0;
      else {
        auto tmp = data.back();
        data.pop_back();
        return tmp;
      }
    }
    void push(int x) {
      data += x;//faster
      //data.push_back(x);
    }
  };

  class machine {
  public:
    machine(tape* l, tape* r) : lTape(l), rTape(r) {}

    void emulate(const std::vector<int>& tm, const std::vector<int>& input) {
      insert(tm);
      insert(delimiter);
      insert(input);
      run();
    }

    void emulate(const std::vector<int>& tm1, const std::vector<int>& tm2, const std::vector<int>& input) {
      insert(tm1);
      insert(delimiter);
      emulate(tm2, input);
    }

    void insert(const std::vector<int>& data) {
      rTape->insert(data);
    }

    void run() {
      auto state = 0;
      auto head = rTape->pop();
      while (1) {
        steps++;
        //auto newHead = rTable[state][head][1];
        //auto direction = rTable[state][head][2];
        //state = rTable[state][head][0];
        auto p = &rTable[state][head][0];//faster
        state = *(p++);
        auto newHead = *(p++);
        auto direction = *p;
        if (direction == 1) {
          head = rTape->pop();
          lTape->push(newHead);
        }
        else if (direction == -1) {
          head = lTape->pop();
          rTape->push(newHead);
        }
        else {
          lTape->push(newHead);
          break;
        }
      }
    }

    auto getSteps() { return steps; }
    auto getLTape() { return lTape->toString(); }
  private:
    long long int steps = 0;
    tape *lTape, *rTape;
    const int L = -1, R = 1, STOP = 0;
    const int rTable[201][2][3] = {
      { { 0, 0, R },{ 128, 1, L } },
      { { 1, 0, R },{ 75, 1, R } },
      { { 2, 0, R },{ 152, 0, R } },
      { { 3, 0, R },{ 78, 1, R } },
      { { 4, 0, R },{ 77, 1, R } },
      { { 5, 0, L },{ 90, 1, L } },
      { { 6, 0, L },{ 117, 1, L } },
      { { 7, 0, R },{ 153, 1, R } },
      { { 8, 0, R },{ 161, 1, R } },
      { { 9, 0, L },{ 177, 1, L } },
      { { 10, 0, L },{ 184, 1, L } },
      { { 11, 0, R },{ 68, 0, L } },
      { { 12, 0, L },{ 197, 0, L } },
      { { 19, 1, R },{ 13, 1, R } },
      { { 8, 0, R },{ 14, 1, R } },
      { { 42, 0, R },{ 64, 0, R } },
      { { 16, 0, L },{ 55, 1, L } },
      { { 17, 0, L },{ 191, 1, L } },
      { { 35, 1, L },{ 140, 1, L } },
      { { 19, 0, R },{ 163, 0, R } },
      { { 45, 0, R },{ 20, 1, R } },
      { { 12, 1, L },{ 21, 1, L } },
      { { 22, 0, L },{ 109, 0, L } },
      { { 60, 0, R },{ 23, 1, L } },
      { { 52, 1, R },{ 24, 1, R } },
      { { 25, 0, R },{ 124, 1, R } },
      { { 186, 1, R },{ 26, 1, L } },
      { { 29, 1, L },{ 27, 0, R } },
      { { 28, 0, L },{ 149, 1, L } },
      { { 29, 1, L },{ 56, 0, L } },
      { { 104, 0, R },{ 30, 1, L } },
      { { 13, 1, R },{ 74, 0, L } },
      { { 32, 0, L },{ 183, 1, L } },
      { { 181, 1, L },{ 33, 1, L } },
      { { 34, 0, L },{ 135, 0, L } },
      { { 35, 0, L },{ 132, 1, L } },
      { { 36, 0, L },{ 139, 0, L } },
      { { 72, 1, R },{ 38, 1, L } },
      { { 38, 1, R },{ 80, 1, R } },
      { { 157, 0, R },{ 39, 1, L } },
      { { 40, 0, L },{ 87, 1, L } },
      { { 15, 0, R },{ 41, 1, R } },
      { { 42, 1, R },{ 64, 1, R } },
      { { 66, 0, R },{ 66, 1, R } },
      { { 128, 0, R },{ 44, 1, L } },
      { { 46, 0, R },{ 45, 1, R } },
      { { 33, 0, L },{ 46, 1, R } },
      { { 5, 0, L },{ 193, 1, L } },
      { { 48, 0, R },{ 115, 1, R } },
      { { 11, 1, R },{ 49, 1, L } },
      { { 53, 1, L },{ 50, 1, R } },
      { { 104, 1, L },{ 16, 0, L } },
      { { 52, 1, R },{ 27, 0, R } },
      { { 28, 1, L },{ 54, 1, L } },
      { { 112, 1, L },{ 112, 1, L } },
      { { 16, 0, L },{ 113, 1, L } },
      { { 11, 1, R },{ 56, 1, L } },
      { { 51, 1, L },{ 58, 1, L } },
      { { 60, 0, L },{ 96, 0, L } },
      { { 84, 0, R },{ 84, 1, R } },
      { { 31, 0, L },{ 128, 1, R } },
      { { 20, 0, R },{ 62, 1, L } },
      { { 20, 0, R },{ 83, 1, L } },
      { { 34, 0, L },{ 36, 0, L } },
      { { 4, 0, R },{ 64, 1, R } },
      { { 66, 1, L },{ 59, 1, R } },
      { { 146, 1, L },{ 33, 0, L } },
      { { 7, 0, R },{ 67, 1, R } },
      { { 68, 0, L },{ 162, 0, L } },
      { { 63, 0, L },{ 69, 0, L } },
      { { 148, 0, L },{ 70, 1, R } },
      { { 140, 0, L },{ 31, 1, L } },
      { { 37, 0, R },{ 37, 0, R } },
      { { 54, 1, L },{ 73, 1, L } },
      { { 32, 0, L },{ 74, 1, L } },
      { { 1, 0, R },{ 168, 1, R } },
      { { 15, 0, R },{ 76, 1, L } },
      { { 4, 0, R },{ 196, 1, R } },
      { { 3, 0, R },{ 118, 1, R } },
      { { 7, 0, R },{ 21, 1, L } },
      { { 1, 0, R },{ 80, 1, R } },
      { { 158, 0, L },{ 81, 1, R } },
      { { 65, 0, R },{ 82, 1, L } },
      { { 20, 0, R },{ 194, 1, L } },
      { { 43, 0, R },{ 43, 1, R } },
      { { 1, 0, R },{ 86, 1, R } },
      { { 1, 0, R },{ 176, 1, R } },
      { { 40, 0, L },{ 13, 0, R } },
      { { 120, 1, L },{ 88, 1, L } },
      { { 23, 1, L },{ 50, 1, R } },
      { { 5, 0, L },{ 92, 1, L } },
      { { 9, 0, L },{ 24, 1, R } },
      { { 5, 0, L },{ 47, 1, L } },
      { { 10, 0, L },{ 94, 1, L } },
      { { 10, 0, L },{ 195, 1, L } },
      { { 0, 0, R },{ 48, 1, R } },
      { { 5, 0, L },{ 96, 1, L } },
      { { 2, 1, R },{ 97, 1, R } },
      { { 22, 1, L },{ 98, 1, L } },
      { { 4, 0, R },{ 200, 1, R } },
      { { 3, 0, R },{ 100, 1, R } },
      { { 30, 1, L },{ 102, 1, R } },
      { { 39, 1, L },{ 81, 1, R } },
      { { 12, 1, L },{ 107, 1, L } },
      { { 58, 1, L },{ 6, 0, L } },
      { { 6, 0, L },{ 106, 1, L } },
      { { 6, 0, L },{ 108, 1, L } },
      { { 12, 1, L },{ 98, 1, L } },
      { { 6, 0, L },{ 76, 1, L } },
      { { 22, 1, L },{ 110, 1, L } },
      { { 95, 1, R },{ 199, 1, R } },
      { { 17, 0, L },{ 143, 1, L } },
      { { 57, 1, L },{ 57, 1, L } },
      { { 16, 0, L },{ 114, 1, L } },
      { { 16, 0, L },{ 116, 1, L } },
      { { 48, 0, R },{ 24, 1, R } },
      { { 16, 0, L },{ 160, 1, L } },
      { { 6, 0, L },{ 105, 1, L } },
      { { 3, 0, R },{ 121, 1, R } },
      { { 8, 0, R },{ 123, 1, R } },
      { { 65, 0, R },{ 61, 0, L } },
      { { 3, 0, R },{ 122, 1, R } },
      { { 3, 0, R },{ 21, 0, L } },
      { { 8, 0, R },{ 125, 1, R } },
      { { 25, 0, R },{ 155, 1, L } },
      { { 8, 0, R },{ 126, 1, R } },
      { { 18, 0, L },{ 159, 1, R } },
      { { 18, 0, L },{ 17, 1, L } },
      { { 148, 0, L },{ 1, 0, R } },
      { { 129, 0, L },{ 130, 1, L } },
      { { 147, 0, L },{ 130, 1, L } },
      { { 190, 1, R },{ 71, 1, L } },
      { { 150, 1, L },{ 132, 1, L } },
      { { 14, 1, R },{ 73, 0, L } },
      { { 133, 1, L },{ 131, 1, R } },
      { { 34, 0, L },{ 0, 0, STOP } },
      { { 136, 0, L },{ 69, 0, L } },
      { { 134, 1, L },{ 134, 1, R } },
      { { 137, 1, L },{ 137, 0, R } },
      { { 36, 0, L },{ 0, 1, STOP } },
      { { 138, 1, L },{ 138, 1, L } },
      { { 129, 1, L },{ 142, 0, R } },
      { { 18, 1, L },{ 136, 0, L } },
      { { 17, 0, L },{ 144, 1, L } },
      { { 14, 1, R },{ 144, 1, L } },
      { { 71, 1, L },{ 131, 1, L } },
      { { 145, 1, L },{ 145, 1, L } },
      { { 40, 0, L },{ 53, 0, R } },
      { { 65, 1, L },{ 146, 1, L } },
      { { 28, 0, L },{ 13, 1, R } },
      { { 188, 0, R },{ 67, 0, R } },
      { { 32, 0, L },{ 133, 0, L } },
      { { 2, 1, R },{ 166, 1, R } },
      { { 7, 0, R },{ 154, 1, R } },
      { { 7, 0, R },{ 156, 1, R } },
      { { 0, 0, R },{ 26, 1, L } },
      { { 7, 0, R },{ 79, 1, R } },
      { { 0, 0, R },{ 51, 1, R } },
      { { 0, 0, R },{ 167, 1, L } },
      { { 18, 0, L },{ 175, 1, R } },
      { { 182, 0, R },{ 160, 1, L } },
      { { 8, 0, R },{ 119, 1, R } },
      { { 11, 1, R },{ 164, 1, L } },
      { { 19, 1, R },{ 97, 1, R } },
      { { 72, 0, R },{ 41, 1, R } },
      { { 17, 0, L },{ 111, 1, L } },
      { { 2, 1, R },{ 169, 1, R } },
      { { 0, 0, R },{ 171, 1, L } },
      { { 1, 0, R },{ 85, 1, R } },
      { { 2, 1, R },{ 170, 1, R } },
      { { 2, 1, R },{ 172, 1, R } },
      { { 0, 0, R },{ 173, 1, L } },
      { { 9, 1, L },{ 10, 1, L } },
      { { 0, 0, R },{ 174, 1, L } },
      { { 0, 0, R },{ 179, 1, L } },
      { { 18, 0, L },{ 70, 1, R } },
      { { 44, 1, L },{ 89, 1, R } },
      { { 9, 0, L },{ 178, 1, L } },
      { { 9, 0, L },{ 180, 1, L } },
      { { 0, 0, R },{ 82, 0, L } },
      { { 9, 0, L },{ 91, 1, L } },
      { { 0, 0, R },{ 88, 0, L } },
      { { 0, 0, R },{ 15, 1, R } },
      { { 32, 0, L },{ 187, 1, L } },
      { { 10, 0, L },{ 93, 1, L } },
      { { 0, 0, R },{ 141, 0, R } },
      { { 0, 0, R },{ 24, 0, R } },
      { { 32, 0, L },{ 189, 1, L } },
      { { 0, 0, R },{ 100, 0, R } },
      { { 32, 0, L },{ 151, 1, L } },
      { { 18, 0, L },{ 127, 1, R } },
      { { 17, 0, L },{ 165, 1, L } },
      { { 185, 0, R },{ 192, 1, R } },
      { { 5, 0, L },{ 49, 1, L } },
      { { 20, 0, R },{ 192, 1, R } },
      { { 10, 0, L },{ 26, 1, L } },
      { { 4, 0, R },{ 99, 1, R } },
      { { 12, 1, L },{ 198, 1, L } },
      { { 12, 1, L },{ 103, 1, L } },
      { { 0, 0, R },{ 25, 1, R } },
      { { 4, 0, R },{ 101, 1, R } } };
  };
}