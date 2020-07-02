GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAM = diary

all: $(PROGRAM)

main.o: src/main.cpp 
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

Date.o: src/Date.cpp include/Date.h
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp	

Helper.o: src/Helper.cpp include/Helper.h
	$(GCC) $(GCC_FLAGS) -c src/Helper.cpp	

Time.o: src/Time.cpp include/Time.h
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp	

$(PROGRAM): App.o Date.o Diary.o Helper.o Time.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAM) App.o Date.o Diary.o Helper.o Time.o main.o		

clean:
	rm -f *.o
	rm $(PROGRAM)