
#ifndef __HDC1080_H__
#define __HDC1080_H__

#include "ClosedCube_HDC1080.h"

//#include "Arduino.h"



class HDC1080 {
  ClosedCube_HDC1080 hdc1080;
public:
  bool begin(void);
  bool init(void);
  float readTemperature(void);
  float readHumidity(void);
protected:
  
};

#endif
