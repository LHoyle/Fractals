#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include "Image.h"
#include "PPM.h"
#include "ActionData.h"
#include "MenuData.h"
void showMenu( MenuData& menu_data, ActionData& action_data );

void takeAction(const std::string& choice, MenuData& menu_data, ActionData& action_data);

oid configureMenu( MenuData& menu_data );

int imageMenu(std::istream& is, std::ostream& os);

void copyImage(ActionData &action_data);

void readUserImage1(ActionData &action_data);

void setSize(ActionData &action_data);

void setMaxColorValue(ActionData &action_data);

void setChannel(ActionData &action_data);

void setPixel(ActionData &action_data);

void clearAll(ActionData &action_data);

std::string getChoice(ActionData &action_data);

void commentLine(ActionData &action_data);

void quit(ActionData &action_data);

std::string getString(ActionData &action_data, const std::string &prompt);

int getInteger(ActionData &action_data, const std::string &prompt);

double getDouble(ActionData &action_data, const std::string &prompt);

int askQuestions3(ActionData &action_data);

int assignment1(ActionData &action_data);

void drawAsciiImage(ActionData &action_data);

void diagonalQuadPattern(ActionData &action_data);

int assignment2(ActionData &action_data);

void writeUserImage(ActionData &action_data);

void stripedDiagonalPattern(ActionData &action_data);

int assignment3(ActionData &action_data);

int askUncleBuckQuestions(ActionData &action_data);

int buck(ActionData &action_data);

void flagColumbiaPattern(ActionData &action_data);

int flag_columbia_ascii(ActionData &action_data);
