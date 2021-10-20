#ifndef CORNERGROCER_H
#define CORNERGROCER_H

using namespace std;

//Functions used and declared in default CPP file - CallProcedure and CallIntFunc
void CallProcedure(string pName);
int CallIntFunc(string proc, string param);

//Functions written for this project - DisplayMenu, NumberOfTimesEach, NumberOfTimesSpecific, DisplayHistogram
void DisplayMenu();
void NumberOfTimesEach();
int NumberOfTimesSpecific(string itemName);
void DisplayHistogram();

#endif