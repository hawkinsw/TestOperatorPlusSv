cmake_minimum_required(VERSION 3.10)

project(TestOperatorPlusSv VERSION 1.0 DESCRIPTION "Testing the use of operator+ with string views")
add_executable(TestOperatorPlusSv test_operator_plus_sv.cpp)
set_property(TARGET TestOperatorPlusSv PROPERTY CXX_STANDARD 20)
