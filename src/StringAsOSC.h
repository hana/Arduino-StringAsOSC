#ifndef STRINGASOSC_H
#define STRINGASOSC_H

#include <Arduino.h>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class StringAsOSC {
  public:
    StringAsOSC();
    void setAddress(String adr);


    template <typename T>
    void addArg(T val) {
      arguments[numArgs] = String(val).c_str();
      numArgs++;
    }


    void fill(String input);
    void bind(const char * adr, const function<void(StringAsOSC &)>& callback );
    string getAddress();
    float getArgAsFloat(int index);
    int getArgAsInt(int index);
    String getArgAsString(int index);
    String getString();
    
  private:
    const char SPACE = ' ';
    string address;
    //    vector<string> arguments;
    int numArgs;
    string arguments[256];
    void splitArgs(string str, char separator);
};


#endif
