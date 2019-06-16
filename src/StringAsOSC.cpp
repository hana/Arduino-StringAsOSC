
#include "StringAsOsc.h"

StringAsOSC::StringAsOSC() {
  numArgs = 0;
  address = "";

}

void StringAsOSC::bind(const char * adr, const function<void(StringAsOSC &)>& callback ) {
  if(this->getAddress() == adr) {
    callback(*this);
  }
}

void StringAsOSC::setAddress(String adr) {
  address = adr.c_str();
}

void StringAsOSC::fill(String input) {
  //Separate input as address and arguments
  int firstSpace = input.indexOf(SPACE);
  address = input.substring(0, firstSpace).c_str();
  splitArgs(input.substring(firstSpace + 1).c_str(), SPACE);
}

string StringAsOSC::getAddress() {
  return address;
}

void StringAsOSC::splitArgs(string str, char separator) {
  int first = 0;
  int last = str.find_first_of(separator);

  while (first < str.size()) {
    string subStr(str, first, last - first);

    //    arguments.push_back(subStr);
    arguments[numArgs] = subStr;
    numArgs++;

    first = last + 1;
    last = str.find_first_of(separator, first);

    if (last == string::npos) {
      last = str.size();
    }
  }
}


float StringAsOSC::getArgAsFloat(int index) {
  return String(arguments[index].c_str()).toFloat();
}

int StringAsOSC::getArgAsInt(int index) {
  return String(arguments[index].c_str()).toInt();
}

String StringAsOSC::getArgAsString(int index) {
  return String(arguments[index].c_str());
}

String StringAsOSC::getString() {
  string text = address;

  for(int i = 0; i < numArgs; i++) {
    text += " ";
    text += arguments[i];
  }
  return String(text.c_str());
}
