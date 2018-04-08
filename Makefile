main:
	gcc -shared exampleProject/example.c -o exampleProject/example.so && g++ -ldl -rdynamic simulator/simulator.cpp -o simulator/simulator
