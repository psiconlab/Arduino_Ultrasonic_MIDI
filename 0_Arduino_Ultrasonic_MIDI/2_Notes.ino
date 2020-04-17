#define NOTE_ON_CHNUM 0x93
#define NOTE_OFF_CHNUM 0x83

int noteCount = 0;
int playThisNote = 0;

#define NUM_NOTES 4
const byte notePitches[NUM_NOTES] = {60, 50, 52, 53};

#define NOTE_LENGTH 30
#define NOTE_BREAK 10

void loop_notes()
{ 
  //Simply loops the note sequence
  if (noteCount>NOTE_LENGTH+NOTE_BREAK)
  {
    noteCount = 0;
    playThisNote++;
    if(playThisNote==4) playThisNote=0;
  }
  
  //Simply loops the note sequence
  if (noteCount==0){
    noteOn(NOTE_ON_CHNUM, notePitches[playThisNote], 127);
  }
  else if (noteCount>NOTE_LENGTH)
  {
    noteOff(NOTE_OFF_CHNUM, notePitches[playThisNote], 0);
  }

  noteCount++;
}

void noteOn(byte channel, byte pitch, byte velocity)
{
  //Play an on note
  Serial.write(channel); //NON & Channel Num
  Serial.write(pitch); //Pitch
  Serial.write(velocity); // Velocity 
}

void noteOff(byte channel, byte pitch, byte velocity)
{
  //Play an off note
  Serial.write(channel); //NOTE OFF & Channel Num
  Serial.write(pitch); //Pitch
  Serial.write(velocity); // Velocity
}

