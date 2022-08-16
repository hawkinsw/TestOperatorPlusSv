#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

bool test_sv_left_non_move() {
  std::string str{"string"};
  std::string_view view{"view"};

  auto result = view + str;

  return std::is_same_v<decltype(str), decltype(result)> && ("viewstring" == result);
}

bool test_sv_right_non_move() {
  std::string str{"string"};
  std::string_view view{"view"};

  auto result = str + view;

  return std::is_same_v<decltype(str), decltype(result)> && ("stringview" == result);
}

bool test_sv_left_move() {
  std::string str{"string"};
  std::string_view view{"view"};

  auto result = view + std::move(str);

  return std::is_same_v<decltype(str), decltype(result)> && ("viewstring" == result);
}

bool test_sv_right_move() {
  std::string str{"string"};
  std::string_view view{"view"};

  auto result = std::move(str) + view;

  return std::is_same_v<decltype(str), decltype(result)> && ("stringview" == result);
}

int main() {
  bool sv_left_move_result = true,
       sv_left_non_move_result = true,
       sv_right_move_result = true,
       sv_right_non_move_result = true;
  if ((sv_left_non_move_result = test_sv_left_non_move()) && 
      (sv_right_non_move_result = test_sv_right_non_move()) &&
      (sv_left_move_result = test_sv_left_move()) &&
      (sv_right_move_result = test_sv_right_move())) {
    std::cout << "All tests passed!\n";
  } else {
    std::cout << "sv left non move:  " << (sv_left_non_move_result ? "PASSED" : "FAILED") << "\n";
    std::cout << "sv right non move: " << (sv_right_non_move_result ? "PASSED" : "FAILED") << "\n";
    std::cout << "sv left move:      " << (sv_left_move_result ? "PASSED" : "FAILED") << "\n";
    std::cout << "sv right move:     " << (sv_right_non_move_result ? "PASSED" : "FAILED") << "\n";
  }
  return 0;
}