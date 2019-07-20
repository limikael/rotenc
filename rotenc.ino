#include "RotEnc.h"

RotEnc enc(3,2);
int last=0;

void setup() {
  Serial.begin(115200);
  Serial.println("start...");
}

void loop() {
  int v=enc.getValue();

  if (v!=last) {
    Serial.println(v);
    last=v;
  }
}
