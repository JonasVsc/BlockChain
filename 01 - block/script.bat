g++ -c -Iinclude lib/hash.cpp -o bin/hash.o
g++ -Iinclude .\src\block_main.cpp  bin/hash.o lib/block.cpp -lssl -lcrypto
start a.exe