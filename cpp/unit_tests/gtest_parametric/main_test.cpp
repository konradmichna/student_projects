#include <gtest/gtest.h>
#include "functions.cpp"

#include <tuple>


// Klasa do przechowywania zestawów parametrów
class AddTest : public testing::TestWithParam<std::tuple<int, int, int>> {};

// Definicja zestawów parametrów
INSTANTIATE_TEST_CASE_P(ParametrizedTest, AddTest,
                        testing::Values(
                            std::make_tuple(1, 2, 3),
                            std::make_tuple(-1, 1, 0),
                            std::make_tuple(0, 0, 0)
                        ));

// Test parametryczny
TEST_P(AddTest, AddsNumbers) {
    int a = std::get<0>(GetParam());
    int b = std::get<1>(GetParam());
    int expected_sum = std::get<2>(GetParam());

    EXPECT_EQ(suma(a, b), expected_sum);
}

// Uruchomienie testów
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


