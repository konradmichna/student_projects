#include <gtest/gtest.h>
#include "functions.cpp"

// Test dla liczby podzielnej przez 3
TEST(FizzBuzzTest, MultiplesOf3) {
    ASSERT_EQ(fizzBuzz(3), "Fizz");
    ASSERT_EQ(fizzBuzz(9), "Fizz");
}

// Test dla liczby podzielnej przez 5
TEST(FizzBuzzTest, MultiplesOf5) {
    ASSERT_EQ(fizzBuzz(5), "Buzz");
    ASSERT_EQ(fizzBuzz(10), "Buzz");
}

// Test dla liczby podzielnej przez 3 i 5
TEST(FizzBuzzTest, MultiplesOf3And5) {
    ASSERT_EQ(fizzBuzz(15), "FizzBuzz");
    ASSERT_EQ(fizzBuzz(30), "FizzBuzz");
}

// Test dla liczby, która nie jest podzielna przez 3 ani 5
TEST(FizzBuzzTest, NeitherMultipleOf3Nor5) {
    ASSERT_EQ(fizzBuzz(1), "1");
    ASSERT_EQ(fizzBuzz(7), "7");
}

// Inicjalizacja testów
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
