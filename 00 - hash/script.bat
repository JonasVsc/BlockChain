g++ -c -Iinclude lib/hash.cpp -o bin/hash.o
g++ -Iinclude .\src\hash_main.cpp  bin/hash.o -lssl -lcrypto
start a.exe