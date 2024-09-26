#include <iostream>
#include <vector> // Biblioteka potrzebna do użycia std::vector

int main() {
    // Tworzenie pustego wektora przechowującego liczby całkowite
    std::vector<int> numbers;

    // Dodawanie elementów do wektora
    numbers.push_back(10); // Dodaje 10 na końcu wektora
    numbers.push_back(20); // Dodaje 20 na końcu wektora
    numbers.push_back(30); // Dodaje 30 na końcu wektora

    // Wyświetlanie elementów wektora
    std::cout << "Elementy wektora: ";
    for (int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " "; // Dostęp do elementów za pomocą operatora indeksowania
    }
    std::cout << std::endl;

    // Sprawdzanie liczby elementów w wektorze
    std::cout << "Liczba elementów w wektorze: " << numbers.size() << std::endl;

    // Usuwanie ostatniego elementu z wektora
    numbers.pop_back(); // Usuwa ostatni element (30)
    std::cout << "Po usunięciu ostatniego elementu: ";
    for (int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Dostęp do pierwszego i ostatniego elementu wektora
    if (!numbers.empty()) { // Sprawdzenie, czy wektor nie jest pusty
        std::cout << "Pierwszy element: " << numbers.front() << std::endl;
        std::cout << "Ostatni element: " << numbers.back() << std::endl;
    }

    // Usunięcie wszystkich elementów wektora
    numbers.clear(); // Czyści cały wektor
    std::cout << "Wektor po wyczyszczeniu: " << (numbers.empty() ? "pusty" : "niepusty") << std::endl;

    return 0;
}

