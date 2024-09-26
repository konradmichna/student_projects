# Dokumentacja Testów Wydajności Sortowania

## Wprowadzenie

Celem przeprowadzonych testów jest porównanie wydajności dwóch algorytmów sortujących: **Bubble Sort** i **Quick Sort**. Testy mierzą czas wykonania sortowania dla losowo wygenerowanych wektorów zawierających 10,000 elementów.

## Wymagania

- **C++11 lub nowszy**: Użycie nowoczesnych funkcji i kontenerów STL.
- **Google Test**: Framework do testowania jednostkowego w C++.

## Algorytmy

1. **Bubble Sort**:
   - Algorytm prosty, ale nieefektywny dla dużych zbiorów danych.
   - W przypadku sortowania bąbelkowego czas działania wynosi O(n²) w najgorszym przypadku.

2. **Quick Sort**:
   - Algorytm dziel i zwyciężaj.
   - Osiąga czas działania O(n log n) w przeciętnym przypadku, co czyni go znacznie bardziej efektywnym niż Bubble Sort.

## Opis Testów

### 1. Test Wydajności Quick Sort

**Opis**: Mierzy czas sortowania przy użyciu algorytmu Quick Sort.

- **Przygotowanie**: Generowanie wektora o rozmiarze 10,000 z losowymi liczbami całkowitymi.
- **Pomiar czasu**: Użycie `std::chrono` do pomiaru czasu wykonania sortowania.
- **Wynik**: Czas sortowania jest wyświetlany w sekundach.


