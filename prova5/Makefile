GCC = g++
GCC_FLAGS = -std=c++11
PROGRAM = supermercado

all: $(PROGRAM)

main.o: src/main.cpp 
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

cliente.o: src/cliente.cpp include/cliente.hpp
	$(GCC) $(GCC_FLAGS) -c src/cliente.cpp

estabelecimento.o: src/estabelecimento.cpp include/estabelecimento.hpp
	$(GCC) $(GCC_FLAGS) -c src/estabelecimento.cpp	

produto.o: src/produto.cpp include/produto.hpp
	$(GCC) $(GCC_FLAGS) -c src/produto.cpp

fornecedor.o: src/fornecedor.cpp include/fornecedor.hpp
	$(GCC) $(GCC_FLAGS) -c src/fornecedor.cpp

$(PROGRAM): cliente.o estabelecimento.o produto.o fornecedor.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAM) cliente.o estabelecimento.o produto.o fornecedor.o main.o		

clean:
	rm -f *.o
	rm $(PROGRAM)