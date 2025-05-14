app.exe: main.o User.o Cat.o QuizStrategy.o DataManager.o TreatShop.o
	g++ -std=c++17 -o app.exe main.o User.o Cat.o QuizStrategy.o DataManager.o TreatShop.o

main.o: main.cpp User.hpp DataManager.hpp
	g++ -std=c++17 -c main.cpp

TreatShop.o: TreatShop.cpp TreatShop.hpp User.hpp
	g++ -std=c++17 -c TreatShop.cpp

DataManager.o: DataManager.cpp DataManager.hpp User.hpp
	g++ -std=c++17 -c DataManager.cpp

User.o: User.cpp User.hpp Cat.hpp QuizStrategy.hpp
	g++ -std=c++17 -c User.cpp

Cat.o: Cat.cpp Cat.hpp
	g++ -std=c++17 -c Cat.cpp

QuizStrategy.o: QuizStrategy.cpp QuizStrategy.hpp
	g++ -std=c++17 -c QuizStrategy.cpp

clean:
	del /Q *.o *.exe 2> nul || rm -f *.o *.exe

