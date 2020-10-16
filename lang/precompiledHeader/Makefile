# with PCH, compile pch.h first and then main.cpp, time will give the amount of time
mainpch: main.cpp
	g++ -std=c++17 pch.h
	time g++ -std=c++17 main.cpp -o mainpch 

# without PCH, time will give the amount of time
main: main.cpp
	time g++ -std=c++17 main.cpp -DNOPCH -o main

all: main mainpch

clean:
	rm -rf main mainpch *.gch
