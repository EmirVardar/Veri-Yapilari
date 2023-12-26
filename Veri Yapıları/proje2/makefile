all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/avlAgaci.cpp -o ./lib/avlAgaci.o
	g++ -c -I "./include" ./src/avlDugum.cpp -o ./lib/avlDugum.o
	g++ -c -I "./include" ./src/yiginDugum.cpp -o ./lib/yiginDugum.o
	g++ -c -I "./include" ./src/yigin.cpp -o ./lib/yigin.o	
bagla:
	g++ ./lib/avlDugum.o	./lib/yiginDugum.o ./lib/yigin.o  ./lib/avlAgaci.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program