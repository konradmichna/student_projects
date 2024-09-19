#!/bin/sh
rm main_test
clear
echo "----Kompilacja benchmarka testujacego----"

g++ -std=c++11 -O2 -lbenchmark -lpthread main_test.cpp -o main_test

echo "---Kompilacja benchmarka ukonczona----"
echo "---Uruchamianie beanchmarka---"
chmod +x main_test
./main_test
echo "---Zakonczono benchmark---"
