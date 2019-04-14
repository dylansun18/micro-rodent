int motorCount = 0;
int prevTime = 0;
int currTime = 0;
int timeTol = 5; //works pretty well for 70 pwm but not as wellf or 30 pwm tmp38


int calculatePwm(unsigned long ct, unsigned long pt){
  
  int changeInPwm = floor(1.0*verror.back() + 0.1*((verror.back()- verror[verror.size() - 2])/(ct-pt)) + 0*currTime*esum);
  int newPwm = vCalc + changeInPwm;
  return newPwm;
}

void my_isr(){
  currTime = millis();
  if(currTime - prevTime > timeTol){
    motorCount++;
    Serial.print(motorCount);
    Serial.print(" Interrupts, ");
    
    //vread is the angular velocity given by motor encoders (1/12 of a rotation per change in time)
    vread = (1.0/12.0)/((currTime-prevTime)/1000.0); //not accurate rn
    verror.push_back(vref-vread);
    esum += (vref - vread);

    Serial.print("vread: ");
    Serial.println(vread);
    prevTime = currTime;

  }
}
