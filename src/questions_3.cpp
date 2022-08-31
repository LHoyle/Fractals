#include <string>
#include <iostream>


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

double GetDouble(std::istream& is, std::ostream& os,const std::string& prompt){
    double value;
    os <<prompt;
    is >> value;
    //os <<std::endl;
    return value;
}

int askQuestions3(std::istream& is, std::ostream& os){

    std::string stringprompt="What is your favorite color? ";
    std::string stringvalue=getString(std::cin, std::cout,stringprompt);
    std::string doubleprompt="What is your favorite integer? ";
    int intvalue=GetDouble(std::cin, std::cout,doubleprompt);
    std::string intprompt="What is your favorite number? ";
    double doublevalue=GetDouble(std::cin, std::cout,intprompt);
    int i;
    std::string space=" ";
    for (i=0; i<=intvalue;i++){
        std::cout << i+1<< space << stringvalue << space << doublevalue << std::endl;
       
    }

    return 0;
}

int main(){
    int value=askQuestions3(std::cin, std::cout);
    
    return 0;
}



/*int stringitteration():{
        std::string s ="Hello world.";
        //for i in range(len(s))
        //for(initilization;test; increment;)
        unsigned int i;
        for(i=0;i<3;i++){
            int numberl
            std::cout<<"number please: "
            std::cin>>number;
            nums.push_back(number)
        }
        for(i=0;i<s.size(),i++){
            //if(s[i]='o'){
            if (s[i]1 >= 97 && s[i]<=122){
            std::cout<<s[i]<<std::endl;
            }
        }
        std::string outmess = "~~~~~~~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~~~~~~~~~~~~~~~~"
        std::cout<<std::endl<<outmess<<std::endl;
        return 0;


    for (i=0;i<nums.size();i++{
        std::count<<"Number please: "
        std::cin<<
    })

}*/