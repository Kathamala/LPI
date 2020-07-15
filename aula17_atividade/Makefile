GCC = g++
GCC_FLAGS = -std=c++11
PROGRAM = banco

all: $(PROGRAM)

main.o: src/main.cpp 
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Cliente.o: src/cliente.cpp include/cliente.hpp
	$(GCC) $(GCC_FLAGS) -c src/cliente.cpp

ClientePJ.o: src/clientePJ.cpp include/clientePJ.hpp
	$(GCC) $(GCC_FLAGS) -c src/clientePJ.cpp

Conta.o: src/conta.cpp include/conta.hpp
	$(GCC) $(GCC_FLAGS) -c src/conta.cpp	

$(PROGRAM): Cliente.o ClientePJ.o Conta.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAM) Cliente.o ClientePJ.o Conta.o main.o

clean:
	rm -f *.o
	rm $(PROGRAM)