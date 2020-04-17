uint8_t velocity = 100;
#define CC_CHNUM 0xB3
#define CC_CONTROLLER_NUM 0x01
#define CH_NUM 1

void loop_controller()
{
  //This sends the control change message including the reading from the ultrasonic

  controlChange(CC_CHNUM, CC_CONTROLLER_NUM, velocity);
}

void controlChange(byte channel, byte control, byte value) {  
  Serial.write(channel); //CC & Channel Num (starts at zero, so 0xB3 = channel 2)
  Serial.write(control); //Controller Num
  Serial.write(value); // Value
}
