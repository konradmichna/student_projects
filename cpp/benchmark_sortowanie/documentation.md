# Dokumentacja Testów Wydajności Sortowania

## Wprowadzenie

Celem przeprowadzonych testów jest porównanie wydajności dwóch algorytmów sortujących: **Bubble Sort** i **Quick Sort**. Testy mierzą czas wykonania sortowania dla losowo wygenerowanych wektorów zawierających 10,000 elementów.

## Wymagania
- **Google Test**: Framework do testowania jednostkowego w C++.

## Algorytmy

1. **Bubble Sort**:
   - Algorytm prosty, ale nieefektywny dla dużych zbiorów danych.

2. **Quick Sort**:
   - Algorytm dziel i zwyciężaj.

## Opis Testów

### 1. Test Wydajności Quick Sort

**Opis**: Mierzy czas sortowania przy użyciu algorytmu Quick Sort.

- **Przygotowanie**: Generowanie wektora o rozmiarze 10,000 z losowymi liczbami całkowitymi.
- **Pomiar czasu**: Użycie `std::chrono` do pomiaru czasu wykonania sortowania.
- **Wynik**: Czas sortowania jest wyświetlany w sekundach.

### 2. Test Wydajności Bubble Sort

**Opis**: Mierzy czas sortowania przy użyciu algorytmu Bubble Sort.

- **Przygotowanie**: Generowanie wektora o rozmiarze 10,000 z losowymi liczbami całkowitymi.
- **Pomiar czasu**: Użycie `std::chrono` do pomiaru czasu wykonania sortowania.
- **Wynik**: Czas sortowania jest wyświetlany w sekundach.

### 3. Wyniki testów

<img width="100%" src="./wynik_sortowanie.png"/>

### 4. Wnioski dotyczące wydajności i algorytmów

### Porównanie Algorytmów Sortujących

### BubbleSort
- Jest to algorytm, którego czas działania znacznie rośnie wraz z liczbą elementów do posortowania. Przy podwojeniu liczby elementów czas wykonania może wzrosnąć czterokrotnie, co czyni go mało efektywnym dla dużych zbiorów danych.
- W praktyce może działać szybciej dla małych wektorów, zwłaszcza gdy dane są częściowo posortowane, dzięki zastosowaniu flagi `swapped`, która pozwala na wcześniejsze zakończenie sortowania.

### QuickSort
- Wykazuje znacznie lepszą wydajność i działa szybko, nawet na dużych zbiorach danych. Czas wykonania rośnie wolniej w miarę wzrostu liczby elementów.
- Implementacja wykorzystuje podział na podzbiory, co zwiększa czytelność kodu, ale w przypadku już posortowanych danych może prowadzić do obniżonej wydajności. Z tego powodu zaleca się losowe wybieranie elementu jako pivota.

### Testy Wydajności
- Oba algorytmy sortujące zostały przetestowane na wektorze o rozmiarze 10,000 elementów. Czas wykonania mierzono przy użyciu zegara o wysokiej rozdzielczości, co zapewnia dokładne pomiary wydajności.
- Wyniki testów można porównać, aby zobaczyć różnice w czasie wykonania między algorytmami.

### Losowość Danych
- Użycie generatora liczb losowych do wypełnienia wektora danymi testowymi zapewnia różnorodność przypadków testowych, co jest ważne dla wiarygodnych wyników pomiarów wydajności.

### Możliwości Rozwoju
- Można rozważyć dodanie innych algorytmów sortujących do porównania, takich jak MergeSort czy HeapSort, co może dostarczyć szerszego kontekstu dotyczącego wydajności sortowania.
- Warto również zbadać różne strategie wyboru pivota w QuickSort (np. mediana, losowy element) i ich wpływ na wydajność.

### Uwagi dotyczące implementacji

## Zarządzanie Pamięcią
- QuickSort wykorzystuje dodatkowe wektory do przechowywania podzbiorów, co może zwiększać zużycie pamięci w przypadku dużych danych. W przyszłości można rozważyć in-place QuickSort, aby zminimalizować wykorzystanie pamięci.

### Konstrukcja Testów
- Zastosowanie frameworka Google Test umożliwia łatwe rozszerzanie testów oraz ich automatyzację, co jest korzystne w większych projektach.

### Przykładowy Kod Testów

Poniżej przedstawiono przykładowy kod do przeprowadzenia testów wydajności dla obu algorytmów:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

using namespace std;

// Funkcja sortująca wektor za pomocą BubbleSort
void bubbleSort(vector<int>& vec) {
    int n = vec.size();
    bool swapped;
    
    for(int i = 0; i < n - 1; i++) {
        swapped = false;
        
        for(int j = 0; j < n - i - 1; j++) {
            if(vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

// Funkcja sortująca wektor za pomocą QuickSort
void quickSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    int pivot = vec[vec.size() / 2];
    std::vector<int> left, right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < pivot) left.push_back(vec[i]);
        else if (vec[i] > pivot) right.push_back(vec[i]);
    }
    quickSort(left);
    quickSort(right);
    vec.clear();
    vec.insert(vec.end(), left.begin(), left.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), right.begin(), right.end());
}

// Test wydajności sortowania QuickSort
TEST(BenchmarkTest, QuickSortBenchmark) {
    std::vector<int> vec(10000);
    std::srand(std::time(0)); 
    std::generate(vec.begin(), vec.end(), std::rand);

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania QuickSort: " << elapsed_seconds.count() << "s\n";
}

// Test wydajności sortowania BubbleSort
TEST(BenchmarkTest, BubbleSortBenchmark) {
    std::vector<int> vec(10000);
    std::srand(std::time(0)); 
    std::generate(vec.begin(), vec.end(), std::rand);

    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania BubbleSort: " << elapsed_seconds.count() << "s\n";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
