#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include "Image.h"
#include "PPM.h"
#include "ActionData.h"

std::string getString(ActionData& action_data, const std::string &prompt);

int getInteger(ActionData& action_data, const std::string &prompt);

double getDouble(ActionData& action_data, const std::string &prompt);

int askQuestions3(ActionData& action_data);

int assignment1(ActionData &action_data);

void drawAsciiImage(ActionData &action_data, const Image &image);

void diagonalQuadPattern(ActionData &action_data, Image &image);

int assignment2(ActionData &action_data);

void writeUserImage(ActionData &action_data, const PPM &p);

void stripedDiagonalPattern(ActionData &action_data, PPM &p);

int assignment3(ActionData &action_data);

int askUncleBuckQuestions(ActionData& action_data);
int buck(ActionData &action_data);
void flagColumbiaPattern(ActionData &action_data, Image &image);
int flag_columbia_ascii(ActionData &action_data);

std::string getChoice( ActionData& action_data );
void commentLine( ActionData& action_data );
void quit(ActionData& action_data); 