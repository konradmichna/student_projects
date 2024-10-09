#include <gtest/gtest.h>
#include "functions.cpp"

// Test dla liczby podzielnej przez 3
TEST(FizzBuzzTest, MultiplesOf3) {
    EXPECT_EQ(fizzBuzz(3), "Fizz");
    EXPECT_EQ(fizzBuzz(9), "Fizz");
}

// Test dla liczby podzielnej przez 5
TEST(FizzBuzzTest, MultiplesOf5) {
    EXPECT_EQ(fizzBuzz(5), "Buzz");
    EXPECT_EQ(fizzBuzz(10), "Buzz");
}

// Test dla liczby podzielnej przez 3 i 5
TEST(FizzBuzzTest, MultiplesOf3And5) {
    EXPECT_EQ(fizzBuzz(15), "FizzBuzz");
    EXPECT_EQ(fizzBuzz(30), "FizzBuzz");
}

// Test dla liczby, która nie jest podzielna przez 3 ani 5
TEST(FizzBuzzTest, NeitherMultipleOf3Nor5) {
    EXPECT_EQ(fizzBuzz(1), "1");
    EXPECT_EQ(fizzBuzz(7), "7");
}

// Inicjalizacja testów
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
