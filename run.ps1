# Compilando bibliotecas
g++ -c -I. ./include/*.h
# Compilando main.cpp
g++ -o ./bin/blockchain ./src/main.cpp
# Run
start ./bin/blockchain