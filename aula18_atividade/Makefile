GCC = g++
GCC_FLAGS = -std=c++11
PROGRAM = banco

all: $(PROGRAM)

main.o: src/main.cpp 
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Cliente.o: src/cliente.cpp include/cliente.hpp
	$(GCC) $(GCC_FLAGS) -c src/cliente.cpp	

ClientePF.o: src/clientePF.cpp include/clientePF.hpp
	$(GCC) $(GCC_FLAGS) -c src/clientePF.cpp

ClientePJ.o: src/clientePJ.cpp include/clientePJ.hpp
	$(GCC) $(GCC_FLAGS) -c src/clientePJ.cpp

Conta.o: src/conta.cpp include/conta.hpp
	$(GCC) $(GCC_FLAGS) -c src/conta.cpp

Funcionario.o: src/funcionario.cpp include/funcionario.hpp
	$(GCC) $(GCC_FLAGS) -c src/funcionario.cpp		

$(PROGRAM):Cliente.o ClientePF.o ClientePJ.o Conta.o Funcionario.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAM) Cliente.o ClientePF.o ClientePJ.o Conta.o Funcionario.o main.o

clean:
	rm -f *.o
	rm $(PROGRAM)