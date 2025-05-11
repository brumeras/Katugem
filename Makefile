app.exe: main.o User.o Cat.o QuizDataLoader.o QuizStrategy.o
	g++ -std=c++17 -o app.exe main.o User.o Cat.o QuizDataLoader.o QuizStrategy.o

main.o: main.cpp User.hpp Cat.hpp QuizDataLoader.hpp
	g++ -std=c++17 -c main.cpp

QuizDataLoader.o: QuizDataLoader.cpp QuizDataLoader.hpp
	g++ -std=c++17 -c QuizDataLoader.cpp

User.o: User.cpp User.hpp Cat.hpp QuizStrategy.hpp
	g++ -std=c++17 -c User.cpp

Cat.o: Cat.cpp Cat.hpp
	g++ -std=c++17 -c Cat.cpp

QuizStrategy.o: QuizStrategy.cpp QuizStrategy.hpp
	g++ -std=c++17 -c QuizStrategy.cpp

clean:
	del /Q *.o *.exe 2> nul || rm -f *.o *.exe

