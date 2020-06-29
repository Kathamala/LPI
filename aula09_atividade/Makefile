GCC = g++
GCC_FLAGS = -std=c++11
PROGRAM = diary

all: $(PROGRAM)

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Diary.o: src/Diary.cpp
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

Date.o: src/Date.cpp
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

App.o: src/App.cpp
	$(GCC) $(GCC_FLAGS) -c src/App.cpp	

Helper.o: src/Helper.cpp
	$(GCC) $(GCC_FLAGS) -c src/Helper.cpp	

Time.o: src/Time.cpp
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp	

$(PROGRAM): App.o Date.o Diary.o Helper.o Time.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAM) App.o Date.o Diary.o Helper.o Time.o main.o		