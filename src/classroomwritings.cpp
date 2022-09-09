#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int maim(){
        std::vector<std::string> words = {"the","quick","brown","fox"};
    std::ofstream fout("bit-patterns.txt") //creates an output stream. associated with the file hit-patterns.txt
    int i //an int is a 4 byte entity. 
    for ( i = 0; i < 256; i++)
    { fout <<words[i]<< " ";
    }
    fou<<std::endl;
    fout.close()
    return 0;
}

int main(){
        std::vector<std::string> words = {"the","quick","brown","fox"};
    std::ofstream fout("bit-patterns.txt") //creates an output stream. associated with the file hit-patterns.txt
    int i //an int is a 4 byte entity. 
    for ( i = 0; i < 256; i++)
    {
        unsigned char byte; //char is a one byte int. this stores from 0 to 255
        byte = i; //this is saving the 4 bites to one, so only the least significant byte will be saved. 
        fout.write((char *)&byte,1); //not byte(variable) itself but its location because thats how it works. the & is a evil device and its useage depends on location. in this case it maeks it compute its location in storage. the second argument is how many bytes (unit) we want stored.
        //we could instead of having the 1 have the streamsize variable it needs. its built in to the standard C liberary. We also need to turn the unsigned Char into a signed char for the argument 
    }
    
    fout.close()
    return 0;
}


/*void fill(std::vector<int> nums){
    for (i=0: i<nums.size()/2;i++;){
        std::cout << "number please: ";
        std::cin>> nums[i]
    }
}

void show(){
    for (i=0: i<nums.size();i++;){
        std::cout <<nums[i]<<std::endl;
    }
}
int main(){
    std::vector<int> nums(10);
}*/

/*int main(){
    //create 2d point ebject
    Point p(3.14,2.71);
    //diisplay the coordinates of the point object

    return 0;
}*/