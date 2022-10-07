CXXFLAGS := -std=c++11 -Wall -Werror -Wextra -Wpedantic 

all: hello questions_3 ascii_image image_file buck flag_columbia_ascii ActionData.o MenuData.o




hello: hello.o
	g++ $(CXXFLAGS) -o hello hello.o

hello.o: hello.cpp
	g++ $(CXXFLAGS)  -c hello.cpp




questions_3: questions_3.o user_io.o controllers.o image_output.o Image.o image_drawing.o PPM.o
	g++ $(CXXFLAGS) -o questions_3 questions_3.o user_io.o controllers.o image_output.o Image.o image_drawing.o PPM.o

questions_3.o: questions_3.cpp image_menu.h Image.h PPM.h Image.o
	g++ $(CXXFLAGS) -c questions_3.cpp 




ascii_image:   ascii_image.o image_output.o image_drawing.o user_io.o controllers.o Image.o PPM.o
	g++ $(CXXFLAGS) -o ascii_image  ascii_image.o Image.o image_output.o image_drawing.o user_io.o controllers.o PPM.o

ascii_image.o: ascii_image.cpp image_menu.h Image.h PPM.h
	g++ $(CXXFLAGS) -c ascii_image.cpp

controllers.o: controllers.cpp image_menu.h Image.h PPM.h
	g++ $(CXXFLAGS) -c controllers.cpp

user_io.o: user_io.cpp image_menu.h Image.h  PPM.h
	g++ $(CXXFLAGS) -c user_io.cpp

image_drawing.o: image_drawing.cpp image_menu.h Image.h  PPM.h
	g++ $(CXXFLAGS) -c image_drawing.cpp 

Image.o: Image.cpp Image.h PPM.h image_menu.h
	g++ $(CXXFLAGS) -c Image.cpp


image_file: PPM.o image_output.o image_drawing.o controllers.o image_file.o user_io.o Image.o
	g++ $(CXXFLAGS) -o image_file PPM.o image_output.o image_drawing.o controllers.o image_file.o user_io.o Image.o

PPM.o: PPM.cpp image_menu.h PPM.h Image.h
	g++ $(CXXFLAGS) -c $<

image_output.o: image_output.cpp image_menu.h PPM.h Image.h 
	g++ $(CXXFLAGS) -c image_output.cpp 

image_file.o: image_file.cpp image_menu.h PPM.h Image.h
	g++ $(CXXFLAGS) -c image_file.cpp



buck: buck.o controllers.o user_io.o Image.o PPM.o image_drawing.o image_output.o
	g++ $(CXXFLAGS) -o buck  buck.o controllers.o user_io.o Image.o PPM.o image_drawing.o image_output.o

buck.o: buck.cpp image_menu.h PPM.h Image.h
	g++ $(CXXFLAGS) -c buck.cpp

flag_columbia_ascii: flag_columbia_ascii.o controllers.o user_io.o Image.o PPM.o image_drawing.o image_output.o
	g++ $(CXXFLAGS) -o flag_columbia_ascii flag_columbia_ascii.o controllers.o user_io.o Image.o PPM.o image_drawing.o image_output.o

flag_columbia_ascii.o: flag_columbia_ascii.cpp image_menu.h PPM.h Image.h
	g++ $(CXXFLAGS) -c flag_columbia_ascii.cpp
	
ActionData.o: ActionData.cpp ActionData.h PPM.h Image.h
	g++ $(CXXFLAGS) -c  $<

MenuData.o: MenuData.cpp MenuData.H
	g++ $(CXXFLAGS) -c  $<

clean: 
	rm *.o

