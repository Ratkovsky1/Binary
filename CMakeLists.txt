# Project: Printing numbers in binary system.
# Author:  Lukas Ratkovsky
# Version: 1.0
# Date:    3.5.2022

cmake_minimum_required (VERSION 3.8)

PROJECT ("Binary")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "build/")
SET(CMAKE_COLOR_MAKEFILE ON)
ADD_EXECUTABLE(binary src/binary.c)

enable_testing()

# Arguments tests
# --------------------------------------------------------------------------
add_test(to_few_argument build/binary)
set_tests_properties(to_few_argument PROPERTIES WILL_FAIL TRUE)

add_test(too_much_arguments1 build/binary -d 0 8 1)
set_tests_properties(too_much_arguments1 PROPERTIES WILL_FAIL TRUE)

add_test(too_much_arguments2 build/binary 0 0 0 0 0 0 0 0)
set_tests_properties(too_much_arguments2 PROPERTIES WILL_FAIL TRUE)

add_test(invalid_argument build/binary -a)
set_tests_properties(invalid_argument PROPERTIES WILL_FAIL TRUE)

add_test(too_small_size_argument build/binary -d 1 0)
set_tests_properties(too_small_size_argument PROPERTIES WILL_FAIL TRUE)

add_test(too_large_size_argument build/binary -d 1 1024)
set_tests_properties(too_large_size_argument PROPERTIES WILL_FAIL TRUE)

add_test(char_size_argument build/binary -d 1 CHAR)
set_tests_properties(char_size_argument PROPERTIES WILL_FAIL FALSE)

add_test(short_size_argument build/binary -d 1 SHORT)
set_tests_properties(short_size_argument PROPERTIES WILL_FAIL FALSE)

add_test(int_size_argument build/binary -d 1 INT)
set_tests_properties(int_size_argument PROPERTIES WILL_FAIL FALSE)

add_test(long_size_argument build/binary -d 1 LONG_INT)
set_tests_properties(long_size_argument PROPERTIES WILL_FAIL FALSE)

# Values tests -d
# --------------------------------------------------------------------------
add_test(zero_to_eight_bites_d build/binary -d 0 8)
set_tests_properties(zero_to_eight_bites_d PROPERTIES PASS_REGULAR_EXPRESSION "0000000")

add_test(one_to_eight_bites_d_return_value build/binary -d 0 8)
set_tests_properties(one_to_eight_bites_d_return_value PROPERTIES WILL_FAIL FALSE)

add_test(one_to_eight_bites_d build/binary -d 1 8)
set_tests_properties(one_to_eight_bites_d PROPERTIES PASS_REGULAR_EXPRESSION "0000001")

add_test(one_to_eight_bites_d_return_value build/binary -d 1 8)
set_tests_properties(one_to_eight_bites_d_return_value PROPERTIES WILL_FAIL FALSE)

add_test(minus_one_to_eight_bites_d build/binary -d -1 8)
set_tests_properties(minus_one_to_eight_bites_d PROPERTIES PASS_REGULAR_EXPRESSION "11111111")

add_test(minus_one_to_eight_bites_d_return_value build/binary -d -1 8)
set_tests_properties(minus_one_to_eight_bites_d_return_value PROPERTIES WILL_FAIL FALSE)

add_test(minus_128_to_eight_bites_d build/binary -d -128 8)
set_tests_properties(minus_128_to_eight_bites_d PROPERTIES PASS_REGULAR_EXPRESSION "10000000")

add_test(minus_128_to_eight_bites_d_return_value build/binary -d -128 8)
set_tests_properties(minus_128_to_eight_bites_d_return_value PROPERTIES WILL_FAIL FALSE)

add_test(minus_129_to_eight_bites_d_return_value build/binary -d -129 8)
set_tests_properties(minus_129_to_eight_bites_d_return_value PROPERTIES WILL_FAIL TRUE)

add_test(plus_127_to_eight_bites_d build/binary -d 127 8)
set_tests_properties(plus_127_to_eight_bites_d PROPERTIES PASS_REGULAR_EXPRESSION "01111111")

add_test(plus_127_to_eight_bites_d_return_value build/binary -d 127 8)
set_tests_properties(plus_127_to_eight_bites_d_return_value PROPERTIES WILL_FAIL FALSE)

add_test(plus_128_to_eight_bites_d_return_value build/binary -d 128 8)
set_tests_properties(plus_128_to_eight_bites_d_return_value PROPERTIES WILL_FAIL TRUE)

# Values tests -s
# --------------------------------------------------------------------------
add_test(zero_to_eight_bites_s build/binary -s 0 8)
set_tests_properties(zero_to_eight_bites_s PROPERTIES PASS_REGULAR_EXPRESSION "0000000")

add_test(zero_to_eight_bites_s_return_value build/binary -s 0 8)
set_tests_properties(zero_to_eight_bites_s_return_value PROPERTIES WILL_FAIL FALSE)

add_test(one_to_eight_bites_s build/binary -s 1 8)
set_tests_properties(one_to_eight_bites_s PROPERTIES PASS_REGULAR_EXPRESSION "0000001")

add_test(one_to_eight_bites_s_return_value build/binary -s 1 8)
set_tests_properties(one_to_eight_bites_s_return_value PROPERTIES WILL_FAIL FALSE)

add_test(minus_one_to_eight_bites_s build/binary -s -1 8)
set_tests_properties(minus_one_to_eight_bites_s PROPERTIES PASS_REGULAR_EXPRESSION "10000001")

add_test(minus_one_to_eight_bites_s_return_value build/binary -s -1 8)
set_tests_properties(minus_one_to_eight_bites_s_return_value PROPERTIES WILL_FAIL FALSE)

add_test(minus_127_to_eight_bites_s build/binary -s -127 8)
set_tests_properties(minus_127_to_eight_bites_s PROPERTIES PASS_REGULAR_EXPRESSION "11111111")

add_test(minus_127_to_eight_bites_s_return_value build/binary -s -127 8)
set_tests_properties(minus_127_to_eight_bites_s_return_value PROPERTIES WILL_FAIL FALSE)

add_test(minus_128_to_eight_bites_s_return_value build/binary -s -128 8)
set_tests_properties(minus_128_to_eight_bites_s_return_value PROPERTIES WILL_FAIL TRUE)

add_test(plus_127_to_eight_bites_s build/binary -s 127 8)
set_tests_properties(plus_127_to_eight_bites_s PROPERTIES PASS_REGULAR_EXPRESSION "01111111")

add_test(plus_127_to_eight_bites_s_return_value build/binary -s 127 8)
set_tests_properties(plus_127_to_eight_bites_s_return_value PROPERTIES WILL_FAIL FALSE)

add_test(plus_128_to_eight_bites_s_return_value build/binary -s 128 8)
set_tests_properties(plus_128_to_eight_bites_s_return_value PROPERTIES WILL_FAIL TRUE)