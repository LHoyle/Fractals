CXXFLAGS := -std=c++11 -Wall -Werror -Wextra -Wpedantic 
HhFiles :=   image_menu.h PPM.h Image.h ActionData.h MenuData.h NumberGrid.h ColorTable.h
OoFiles :=   image_output.o image_drawing.o controllers.o  user_io.o Image.o ActionData.o MenuData.o PPM.o image_filters.o NumberGrid.o ColorTable.o

all: hello questions_3 ascii_image image_file buck flag_columbia_ascii ActionData.o MenuData.o ppm_menu.o 


ppm_menu:ppm_menu.o $(OoFiles)
	g++ $(CXXFLAGS) -o ppm_menu  $^ $(OoFiles)

ppm_menu.o: ppm_menu.cpp  $(HhFiles)
	g++ $(CXXFLAGS)  -c $<

hello: hello.o
	g++ $(CXXFLAGS) -o hello hello.o

hello.o: hello.cpp
	g++ $(CXXFLAGS)  -c hello.cpp




questions_3: questions_3.o $(OoFiles)
	g++ $(CXXFLAGS) -o questions_3 questions_3.o $(OoFiles)

questions_3.o: questions_3.cpp $(HhFiles)  ActionData.cpp 
	g++ $(CXXFLAGS) -c questions_3.cpp   ActionData.cpp




ascii_image:   ascii_image.o $(OoFiles)
	g++ $(CXXFLAGS) -o ascii_image  ascii_image.o $(OoFiles)

ascii_image.o: ascii_image.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c ascii_image.cpp

controllers.o: controllers.cpp $(HhFiles) ActionData.cpp image_filters.cpp MenuData.cpp
	g++ $(CXXFLAGS) -c controllers.cpp ActionData.cpp MenuData.cpp image_filters.cpp

user_io.o: user_io.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c user_io.cpp

image_drawing.o: image_drawing.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c image_drawing.cpp 

Image.o: Image.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c Image.cpp


image_file: ppm_menu.o $(OoFiles)
	g++ $(CXXFLAGS) -o image_file ppm_menu.o $(OoFiles)

PPM.o: PPM.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c $<

image_output.o: image_output.cpp $(HhFiles) PPM.cpp ActionData.cpp
	g++ $(CXXFLAGS) -c image_output.cpp PPM.cpp ActionData.cpp

image_file.o: image_file.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c image_file.cpp
 
buck: buck.o $(OoFiles)
	g++ $(CXXFLAGS) -o buck  buck.o $(OoFiles)

buck.o: buck.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c buck.cpp

flag_columbia_ascii: flag_columbia_ascii.o $(OoFiles)
	g++ $(CXXFLAGS) -o flag_columbia_ascii flag_columbia_ascii.o $(OoFiles)

flag_columbia_ascii.o: flag_columbia_ascii.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c flag_columbia_ascii.cpp
	
ActionData.o: ActionData.cpp PPM.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c  ActionData.cpp PPM.cpp 

MenuData.o: MenuData.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c  $<

image_filters.o:  image_filters.cpp  $(HhFiles)
	g++ $(CXXFLAGS) -c  $<



NumberGrid.o:  NumberGrid.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c $<

ColorTable.o: ColorTable.cpp $(HhFiles)
	g++ $(CXXFLAGS) -c $<
	
clean: 
	rm *.o *.ppm rm -f hello questions_3 ascii_image image_file buck flag_columbia_ascii ppm_menu
 
