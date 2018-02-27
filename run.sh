# this just makes C++ complation a bit easier.
g++ --std=c++17 -o $1.out $1.cpp && ./$1.out && rm ./$1.out
