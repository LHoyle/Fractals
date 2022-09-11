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

ascii_image: Image.o image_menu.h Image.h ascii_image.o image_output.o image_drawing.o user_io.o controllers.o
	g++ -g -o ascii_image.o Image.o image_output.o image_drawing.o user_io.o controllers.o

ascii_image.o: image_menu.h Image.h ascii_image.cpp
	g++ -g -c ascii_image.cpp

controllers.o:  image_menu.h Image.h  controllers.cpp
	g++ -g -c controllers.cpp

user_io.o: image_menu.h Image.h  user_io.cpp
	g++ -g -c user_io.cpp

image_drawing.o: image_menu.h Image.h  image_drawing.cpp
	g++ -g -c image_drawing.cpp

image_output.o:  image_menu.h Image.h  image_output.cpp
	g++ -g -c image_output.cpp

Image.o: Image.cpp image_menu.h Image.h  Image.cpp
	g++ -g -c Image.cpp