all: hello questions_3

hello: hello.o
	g++ -g -o hello hello.o


hello.o: hello.cpp
	g++ -g -c hello.cpp

questions_3: questions_3.o user_io.o controllers.o image_menu.h
	g++ -g -o questions_3 questions_3.o user_io.o controllers.o

questions_3.o: questions_3.cpp image_menu.h
	g++ -g -c questions_3.cpp

user_io.o: user_io.cpp image_menu.h
	g++ -g -c user_io.cpp

controllers.o: controllers.cpp image_menu.h
	g++ -g -c controllers.cpp