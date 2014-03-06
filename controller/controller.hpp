#include <serial.hpp>
#include <iostream>
#include <string.h>

class Controller{

private:
  Serial serialPort; // serial class object
  char status; //Current status byte
  

public:
  Controller(std::string file);
  int drive(unsigned char s1, unsigned char s2, char dir1, char dir2);
  int steer(char a1, char a2, char a3, char a4);
  int getSensor(unsigned char sensor, unsigned short* sensorValue);
  int getStatus(char* statusArray);

};  
