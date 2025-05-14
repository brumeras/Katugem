tests.exe: src/Tests.o src/User.o src/Cat.o src/QuizStrategy.o src/DataManager.o src/TreatShop.o
	g++ -std=c++17 -o tests.exe src/Tests.o src/User.o src/Cat.o src/QuizStrategy.o src/DataManager.o src/TreatShop.o

src/Tests.o: src/Tests.cpp src/User.hpp src/DataManager.hpp
	g++ -std=c++17 -c src/Tests.cpp -o src/Tests.o

src/TreatShop.o: src/TreatShop.cpp src/TreatShop.hpp src/User.hpp
	g++ -std=c++17 -c src/TreatShop.cpp -o src/TreatShop.o

src/DataManager.o: src/DataManager.cpp src/DataManager.hpp src/User.hpp
	g++ -std=c++17 -c src/DataManager.cpp -o src/DataManager.o

src/User.o: src/User.cpp src/User.hpp src/Cat.hpp src/QuizStrategy.hpp
	g++ -std=c++17 -c src/User.cpp -o src/User.o

src/Cat.o: src/Cat.cpp src/Cat.hpp
	g++ -std=c++17 -c src/Cat.cpp -o src/Cat.o

src/QuizStrategy.o: src/QuizStrategy.cpp src/QuizStrategy.hpp
	g++ -std=c++17 -c src/QuizStrategy.cpp -o src/QuizStrategy.o

clean:
	del /Q src\*.o *.exe 2> nul || rm -f src/*.o *.exe
