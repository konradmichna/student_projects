
# Dokumentacja projektu FizzBuzz

## 1. Opis projektu

Projekt implementuje funkcję `fizzBuzz`, która dla pojedynczej liczby zwraca odpowiedni ciąg znaków na podstawie zasad klasycznej gry "FizzBuzz":

- Dla liczb podzielnych przez 3, funkcja zwraca `"Fizz"`.
- Dla liczb podzielnych przez 5, funkcja zwraca `"Buzz"`.
- Dla liczb podzielnych zarówno przez 3, jak i 5, funkcja zwraca `"FizzBuzz"`.
- Dla wszystkich pozostałych liczb, funkcja zwraca tę liczbę w postaci tekstu.

Ponadto projekt zawiera testy jednostkowe oparte na frameworku **Google Test**.

## 2. Struktura projektu

Projekt składa się z następujących plików:

1. **`functions.cpp`**: Zawiera implementację funkcji `fizzBuzz`.
2. **`main.cpp`**: Zawiera główną funkcjonalność programu, umożliwiającą wprowadzenie liczby i wyświetlenie wyniku działania funkcji.
3. **`main_test.cpp`**: Zawiera testy jednostkowe, które weryfikują poprawność działania funkcji `fizzBuzz` dla różnych przypadków.

## 3. Implementacja funkcji `fizzBuzz`

**Plik**: `functions.cpp`

Funkcja `fizzBuzz` przyjmuje jeden argument typu `int` i zwraca wynik w postaci typu `std::string`:

- Jeśli liczba jest podzielna przez 3 i 5, funkcja zwraca `"FizzBuzz"`.
- Jeśli liczba jest podzielna tylko przez 3, funkcja zwraca `"Fizz"`.
- Jeśli liczba jest podzielna tylko przez 5, funkcja zwraca `"Buzz"`.
- Jeśli liczba nie jest podzielna ani przez 3, ani przez 5, funkcja zwraca liczbę w postaci tekstowej.

### Kod funkcji:

```cpp
// functions.cpp

#include <string>

// Funkcja fizzBuzz
std::string fizzBuzz(int n) {
    if (n % 3 == 0 && n % 5 == 0) {
        return "FizzBuzz";
    } else if (n % 3 == 0) {
        return "Fizz";
    } else if (n % 5 == 0) {
        return "Buzz";
    } else {
        return std::to_string(n);
    }
}
```

## 4. Główna funkcja programu

**Plik**: `main.cpp`

Program główny pobiera liczbę od użytkownika, a następnie wywołuje funkcję `fizzBuzz`, aby obliczyć odpowiedni wynik na podstawie wprowadzonej liczby.

### Kod `main.cpp`:

```cpp
// main.cpp

#include <iostream>
#include <string>
#include "functions.cpp"

using namespace std;

int main() {
    int n;
    cout << "Podaj liczbę: ";
    cin >> n;

    // Wywołanie funkcji fizzBuzz i wypisanie wyniku
    string result = fizzBuzz(n);
    cout << result << endl;

    return 0;
}
```

## 5. Testy jednostkowe

**Plik**: `main_test.cpp`

Testy jednostkowe sprawdzają poprawność działania funkcji `fizzBuzz` przy użyciu różnych danych wejściowych. Używane są asercje `ASSERT_EQ` w Google Test, które przerywają test, gdy warunek nie jest spełniony.

### Zestawy testów:

- Testy dla liczb podzielnych przez 3.
- Testy dla liczb podzielnych przez 5.
- Testy dla liczb podzielnych przez 3 i 5 (FizzBuzz).
- Testy dla liczb, które nie są podzielne przez 3 ani 5.

### Kod testów:

```cpp
// main_test.cpp

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
```

## 6. Instrukcja uruchamiania

- **Uruchomienie programu głównego**:
  ```bash
  ./kompiluj_test.sh
  ```
  Program poprosi o wprowadzenie liczby i wyświetli wynik funkcji `fizzBuzz` dla tej liczby.

- **Uruchomienie testów jednostkowych**:
  ```bash
  ./main_test
  ```
  Testy sprawdzą, czy funkcja `fizzBuzz` działa poprawnie w różnych przypadkach.

## 7. Wymagania

- Kompilator C++ (np. `g++`)
- Biblioteka Google Test
- System operacyjny z obsługą narzędzi do kompilacji (np. Linux, macOS, Windows z odpowiednim środowiskiem)

## 8. Działanie programu

- Program prosi użytkownika o podanie liczby.
- Wywołuje funkcję `fizzBuzz`, która:
  - Zwraca `"FizzBuzz"`, jeśli liczba jest podzielna przez 3 i 5.
  - Zwraca `"Fizz"`, jeśli liczba jest podzielna przez 3.
  - Zwraca `"Buzz"`, jeśli liczba jest podzielna przez 5.
  - Zwraca liczbę w postaci tekstu, jeśli nie jest podzielna przez 3 ani 5.
- Program wyświetla wynik na ekranie.

## 9. Wnioski

Ten projekt jest prostym przykładem implementacji klasycznego zadania FizzBuzz, a testy jednostkowe zapewniają poprawność działania funkcji w różnych przypadkach. Dzięki wykorzystaniu Google Test możliwe jest automatyczne sprawdzanie funkcjonalności oraz szybkie wykrywanie błędów.

W projekcie pokazano:
- Rozdzielenie funkcji od logiki głównego programu.
- Stosowanie testów jednostkowych w celu zapewnienia jakości kodu.
