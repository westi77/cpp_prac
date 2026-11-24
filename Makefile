main: src/main.cpp include/DynamicArray.h
	g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp -o main

run: main
	./main

# сборка с проверкой памяти
asan: src/main.cpp include/DynamicArray.h
	g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -Iinclude src/main.cpp -o main_asan
	./main_asan

clean:
	rm -f main main_asan
