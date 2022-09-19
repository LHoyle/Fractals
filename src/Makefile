CXXFLAGS := -std=c++11 -Wall -Werror -Wextra -Wpedantic

all: hello questions_3 ascii_image PPM




hello: hello.o
	g++ $(CXXFLAGS) -o hello hello.o

hello.o: hello.cpp
	g++ $(CXXFLAGS)  -c hello.cpp




questions_3: questions_3.o user_io.o controllers.o image_output.o Image.o image_drawing.o PPM.o
	g++ $(CXXFLAGS)  -o questions_3 questions_3.o user_io.o controllers.o image_output.o Image.o image_drawing.o PPM.o

questions_3.o: questions_3.cpp image_menu.h Image.h PPM.h Image.o PPM.cpp Image.cpp
	g++ $(CXXFLAGS)  -c questions_3.cpp PPM.cpp Image.cpp




ascii_image:   ascii_image.o image_output.o image_drawing.o user_io.o controllers.o Image.o PPM.o
	g++ $(CXXFLAGS)  -o ascii_image  ascii_image.o Image.o image_output.o image_drawing.o user_io.o controllers.o PPM.o

ascii_image.o: ascii_image.cpp image_menu.h Image.h PPM.h
	g++ $(CXXFLAGS)  -c ascii_image.cpp

controllers.o: controllers.cpp image_menu.h Image.h PPM.h
	g++ $(CXXFLAGS)  -c controllers.cpp

user_io.o: user_io.cpp image_menu.h Image.h  PPM.h
	g++ $(CXXFLAGS)  -c user_io.cpp

image_drawing.o: image_drawing.cpp image_menu.h Image.h  PPM.h PPM.cpp Image.cpp
	g++ $(CXXFLAGS)  -c image_drawing.cpp PPM.cpp Image.cpp

Image.o: Image.cpp Image.h PPM.h image_menu.h
	g++ $(CXXFLAGS)  -c Image.cpp


PPM: PPM.o image_output.o image_drawing.o controllers.o image_file.o user_io.o Image.o
	g++ $(CXXFLAGS) -o PPM PPM.o image_output.o image_drawing.o controllers.o image_file.o user_io.o Image.o

PPM.o: PPM.cpp image_menu.h PPM.h Image.h Image.cpp
	g++ $(CXXFLAGS)  -c PPM.cpp Image.cpp

image_output.o: image_output.cpp image_menu.h PPM.h Image.h PPM.cpp Image.cpp user_io.cpp
	g++ $(CXXFLAGS)  -c image_output.cpp PPM.cpp Image.cpp user_io.cpp

image_file.o: image_file.cpp image_menu.h PPM.h Image.h  controllers.cpp PPM.cpp Image.cpp
	g++ $(CXXFLAGS) -c image_file.cpp controllers.cpp PPM.cpp Image.cpp

clean: 
	rm *.o