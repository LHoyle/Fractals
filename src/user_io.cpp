#include "image_menu.h"

std::string getString( std::istream& is, std::ostream& os, const std::string& prompt ){
    std::string value;
    os <<prompt;
    is >> value;
    //os <<std::endl;
    return value;
}

int getInteger( std::istream& is, std::ostream& os, const std::string& prompt ){
    int value;
    os <<prompt;
    is >> value;
    
    return value;
}

double getDouble(std::istream& is, std::ostream& os,const std::string& prompt){
    double value;
    os <<prompt;
    is >> value;
    //os <<std::endl;
    return value;
}

int askQuestions3(std::istream& is, std::ostream& os){

    std::string stringprompt="What is your favorite color? ";
    std::string stringvalue=getString(is, os,stringprompt);
    std::string doubleprompt="What is your favorite integer? ";
    int intvalue=getInteger(is, os,doubleprompt);
    std::string intprompt="What is your favorite number? ";
    double doublevalue=getDouble(is, os,intprompt);
    //os <<std::endl;
    int i;
    std::string space=" ";
    if (intvalue<=0){
        return intvalue;
    }
    /*if (intvalue==1){
        std::cout << intvalue<< space << stringvalue << space << doublevalue << std::endl;
        return intvalue;
    }*/
    for (i=1; i<=intvalue;i++){
        std::cout << i<< space << stringvalue << space << doublevalue;
       //os <<std::endl;
    }
    os <<std::endl;
    return intvalue;
}