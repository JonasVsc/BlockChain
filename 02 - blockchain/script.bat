g++ -c -Iinclude lib/hash.cpp -o bin/hash.o
g++ -Iinclude .\src\blockchain_main.cpp  bin/hash.o lib/blockchain.cpp -lssl -lcrypto
start a.exe