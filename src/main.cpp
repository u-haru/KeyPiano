#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
// status
#define NOTE_OFF	0x8
#define NOTE_ON		0x9
#define MODULATION		0x1
#define RELEASETIME		0x48
#define CONTROL_CHANGE	0xb
#define PROGRAM_CHANGE	0xc
 
#define MAKESMSG(st,ch,d1,d2) ((st)<<4|(ch)|(d1)<<8|(d2)<<16)
#define MAKESMSG_(d1,d2) ((d1)|(d2)<<8)

void Help(int d1){
	switch(d1){
		case 0:{
			printf("0	Acoustic Piano\n");
			printf("1	Bright Piano\n");
			printf("2	Electric Grand Piano\n");
			printf("3	Honky-tonk Piano\n");
			printf("4	Electric Piano\n");
			printf("5	Electric Piano 2\n");
			printf("6	Harpsichord\n");
			printf("7	Clavi\n\n");
			printf("8   Celesta\n");
			printf("9	Glockenspiel\n");
			printf("A	Musical box\n");
			printf("B	Vibraphone\n");
			printf("C	Marimba\n");
			printf("D	Xylophone\n");
			printf("E	Tubular Bell\n");
			printf("F	Dulcimer\n");
			break;
		}
		case 1:{
			printf("0	Drawbar Organ\n");
			printf("1	Percussive Organ\n");
			printf("2	Rock Organ\n");
			printf("3	Church organ\n");
			printf("4	Reed organ\n");
			printf("5	Accordion\n");
			printf("6	Harmonica\n");
			printf("7	Tango Accordion\n\n");
			printf("8   Acoustic Guitar (nylon)\n");
			printf("9	Acoustic Guitar (steel)\n");
			printf("A	Electric Guitar (jazz)\n");
			printf("B	Electric Guitar (clean)\n");
			printf("C	Electric Guitar (muted)\n");
			printf("D	Overdriven Guitar\n");
			printf("E	Distortion Guitar\n");
			printf("F	Guitar harmonics\n");
			break;
		}
		case 2:{
			printf("0	Acoustic Bass\n");
			printf("1	Electric Bass (finger)\n");
			printf("2	Electric Bass (pick)\n");
			printf("3	Fretless Bass\n");
			printf("4	Slap Bass 1\n");
			printf("5	Slap Bass 2\n");
			printf("6	Synth Bass 1\n");
			printf("7	Synth Bass 2\n\n");
			printf("8	Violin\n");
			printf("9	Viola\n");
			printf("A	Cello\n");
			printf("B	Double bass\n");
			printf("C	Tremolo Strings\n");
			printf("D	Pizzicato Strings\n");
			printf("E	Orchestral Harp\n");
			printf("F	Timpani\n");
			break;
		}
		case 3:{
			printf("0	String Ensemble 1\n");
			printf("1	String Ensemble 2\n");
			printf("2	Synth Strings 1\n");
			printf("3	Synth Strings 2\n");
			printf("4	Voice Aahs\n");
			printf("5	Voice Oohs\n");
			printf("6	Synth Voice\n");
			printf("7	Orchestra Hit\n\n");
			printf("8	Trumpet\n");
			printf("9	Trombone\n");
			printf("A	Tuba\n");
			printf("B	Muted Trumpet\n");
			printf("C	French horn\n");
			printf("D	Brass Section\n");
			printf("E	Synth Brass 1\n");
			printf("F	Synth Brass 2\n");
			break;
		}
		case 4:{
			printf("0	Soprano Sax\n");
			printf("1	Alto Sax\n");
			printf("2	Tenor Sax\n");
			printf("3	Baritone Sax\n");
			printf("4	Oboe\n");
			printf("5	English Horn\n");
			printf("6	Bassoon\n");
			printf("7	Clarinet\n\n");
			printf("8	Piccolo\n");
			printf("9	Flute\n");
			printf("A	Recorder\n");
			printf("B	Pan Flute\n");
			printf("C	Blown Bottle\n");
			printf("D	Shakuhachi\n");
			printf("E	Whistle\n");
			printf("F	Ocarina\n");
			break;
		}
		case 5:{
			printf("0	Lead 1 (square)\n");
			printf("1	Lead 2 (sawtooth)\n");
			printf("2	Lead 3 (calliope)\n");
			printf("3	Lead 4 (chiff)\n");
			printf("4	Lead 5 (charang)\n");
			printf("5	Lead 6 (voice)\n");
			printf("6	Lead 7 (fifths)\n");
			printf("7	Lead 8 (bass + lead)\n\n");
			printf("8	Pad 1 (Fantasia)\n");
			printf("9	Pad 2 (warm)\n");
			printf("A	Pad 3 (polysynth)\n");
			printf("B	Pad 4 (choir)\n");
			printf("C	Pad 5 (bowed)\n");
			printf("D	Pad 6 (metallic)\n");
			printf("E	Pad 7 (halo)\n");
			printf("F	Pad 8 (sweep)\n");
			break;
		}
		case 6:{
			printf("0	FX 1 (rain)\n");
			printf("1	FX 2 (soundtrack)\n");
			printf("2	FX 3 (crystal)\n");
			printf("3	FX 4 (atmosphere)\n");
			printf("4	FX 5 (brightness)\n");
			printf("5	FX 6 (goblins)\n");
			printf("6	FX 7 (echoes)\n");
			printf("7	FX 8 (sci-fi)\n\n");
			printf("8	Sitar\n");
			printf("9	Banjo\n");
			printf("A	Shamisen\n");
			printf("B	Koto\n");
			printf("C	Kalimba\n");
			printf("D	Bagpipe\n");
			printf("E	Fiddle\n");
			printf("F	Shanai\n");
			break;
		}
		case 7:{
			printf("0	Tinkle Bell\n");
			printf("1	Agogo\n");
			printf("2	Steel Drums\n");
			printf("3	Woodblock\n");
			printf("4	Taiko Drum\n");
			printf("5	Melodic Tom\n");
			printf("6	Synth Drum\n");
			printf("7	Reverse Cymbal\n\n");
			printf("8	Guitar Fret Noise\n");
			printf("9	Breath Noise\n");
			printf("A	Seashore\n");
			printf("B	Bird Tweet\n");
			printf("C	Telephone Ring\n");
			printf("D	Helicopter\n");
			printf("E	Applause\n");
			printf("F	Gunshot\n");
			break;
		}
	}
}

DWORD ToneChoise(){
	u_int tone = 0;
	u_int phase = 0;
	char buf[3];
	u_int d1=0,d2=0;
	while(phase != 3)
		switch(phase){
			case 0:{
				printf("\n\nSelect Tone in 00~7f\n");
				printf("0.  Piano		   Chromatic Percussion\n");
				printf("1.  Organ		   Guitar\n");
				printf("2.  Bass			Strings\n");
				printf("3.  Ensemble		Brass\n");
				printf("4.  Reed			Pipe\n");
				printf("5.  Synth Lead	  Synth Pad\n");
				printf("6.  Synth Effects   Ethnic\n");
				printf("7.  Percussive	  Sound effects\n");
				phase++;
				break;
			}
			case 1:{
				memset(&buf,0,sizeof(buf));
				while(_kbhit())_getch();
				printf("Data Bit 1:");
				scanf("%2s%*[^\n]",(char*)&buf);
				sscanf(buf,"%x",&d1);
				if(d1>0x7f)
					break;
				if(strlen(buf)==2){
					tone = d1&0xff;
					phase+=2;
				}else{
					Help(d1);
					phase++;
				}
				break;
			}
			case 2:{
				printf("\nData Bit 1:");
				scanf("%1x%*[^\n]",&d2);
				tone = (d1<<4 | d2) & 0xff;
				phase++;
				break;
			}
		}
	
	printf("\nSelected:%x\n",tone);
	return tone;
}

unsigned short int SelectNumber(const char *str,unsigned short int max){
	u_int number = 0;
	u_int phase = 0;
	while(phase != 2)
		switch(phase){
			case 0:{
				printf("\n\nSelect %s in 0~%d\n",str,max);
				phase++;
				break;
			}
			case 1:{
				while(_kbhit())_getch();
				printf("%s:",str);
				scanf("%d%*[^\n]",&number);
				if(number>max||number<0)
					break;
				phase++;
				break;
			}
		}
	printf("\nSelected:%d\n",number);
	Sleep(300);
	while(_kbhit())_getch();
	return number;
}
u_int SelectC4(){
	int C4 = -1;
	char keyb[8] = {(char)VK_LSHIFT,'Z','X','C','V','B','N','M'};
	
	printf("\n\nSelect C4 in L_Shift ~ M\n");
	while(C4==-1){
		for(int i = 0;i<8;i++)
			if(GetAsyncKeyState(keyb[i]&0xff))
				C4=2*i;
		
	}
	printf("\nSelected:%c\n",keyb[C4/2]);
	Sleep(300);
	while(_kbhit())_getch();
	return C4;
}
int main( int argc, char *argv[] )
{
	u_int CH = 0;
	int C4 = 4;
	bool beforeState[29] = {0};
	const char keyb[25] = {(char)VK_LSHIFT,'A','Z','S','X','D','C','F','V','G','B','H','N','J','M','K',(char)VK_OEM_COMMA,'L',(char)VK_OEM_PERIOD,(char)VK_OEM_PLUS,(char)VK_OEM_2,(char)VK_OEM_1,(char)VK_OEM_102,(char)VK_OEM_6,(char)VK_RSHIFT};
	u_int volume = 127;
	int pitch = 0;
	HMIDIOUT hmo;
	u_int note = 0;
	u_int speckey = sizeof(keyb)/sizeof(const char);
	midiOutOpen(&hmo, MIDI_MAPPER, NULL, 0, CALLBACK_NULL);
	midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, 0x0, 0));
	memset(beforeState,0,sizeof(beforeState));
	printf("Welcome to Keyboard!!\nPress keys to ring.\nFor example,'%c' is C4.\n",keyb[C4]);
	printf("Press R or keypad to  change Musical instruments.\nPress W,Q to increase/decrease the pitch.");
	
	while(!GetAsyncKeyState(VK_ESCAPE)){
		midiOutShortMsg(hmo, MAKESMSG(NOTE_ON, CH, 0, 0));
		for(int i = 0 ;i < 25;i++){
			note = i;
			if(i-C4>=0)
			for(int j = 0;j<=(i/14);j++){
				if(i-C4-(j*14)>5)note--;
				if(i-C4-(j*14)>13)note--;
			}else
			for(int j = 0;j<=(i/14);j++){
				if(C4-i+(j*14)>9)note++;
				if(C4-i+(j*14)>1)note++;
			}
			if(GetAsyncKeyState(keyb[i]&0xff) && !beforeState[i]){
				// printf("pressed:%c\nnote:%d\ni:%d\n",keyb[i],note,i);
				beforeState[i] = TRUE;
				if((i-C4)%14!=5&&(i-C4)%14!=13&&(i-C4)%14!=-9&&(i-C4)%14!=-1)
					midiOutShortMsg(hmo, MAKESMSG_(60 - C4 + note + pitch*12, volume));
			}
		}
		midiOutShortMsg(hmo, MAKESMSG(NOTE_OFF, CH, 0, 0));
		for(int i = 0 ;i < 25;i++){
			note = i;
			if(i-C4>=0)
			for(int j = 0;j<=(i/14);j++){
				if(i-C4-(j*14)>5)note--;
				if(i-C4-(j*14)>13)note--;
			}else
			for(int j = 0;j<=(i/14);j++){
				if(C4-i+(j*14)>9)note++;
				if(C4-i+(j*14)>1)note++;
			}
			if(!GetAsyncKeyState(keyb[i]&0xff) && beforeState[i]){
				for(int j = -2;j<=2;j++)
				if(!GetAsyncKeyState(VK_SPACE))midiOutShortMsg(hmo, MAKESMSG_(60 - C4 + note + (pitch+j)*12, volume));
				// printf("released:%c\nnote:%d\n",keyb[i],note);
				beforeState[i] = FALSE;
			}else if(!GetAsyncKeyState(VK_SPACE) && !GetAsyncKeyState(keyb[i]&0xff))
			if((i-C4)%14!=5&&(i-C4)%14!=13&&(i-C4)%14!=-9&&(i-C4)%14!=-1)
				midiOutShortMsg(hmo, MAKESMSG_(60 - C4 + note + pitch*12, volume));
		}
			
		for(int i = 0 ;i < 10;i++)
			if(GetAsyncKeyState(i+96))
				switch(i){
					case 1: midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, 0x0, 0));break;
					case 2: midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, 0x1a, 0));break;
					case 3: midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, 0x34, 0));break;
					case 4: midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, 0x38, 0));break;
					case 5: midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, 0x4a, 0));break;
					case 6: midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, 0x59, 0));break;
					case 7: midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, 0x5d, 0));break;
					case 8: midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, 0x65, 0));break;
					case 9: midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, 0x61, 0));break;
				}
		for(int i = 0 ;i < 10;i++)
			if(GetAsyncKeyState(i+48))
				volume = (12*i + 127)%128;
		if(GetAsyncKeyState('Q') && !beforeState[speckey]){
			pitch--;
			beforeState[speckey] = TRUE;
		}else if(!GetAsyncKeyState('Q'))beforeState[speckey] = FALSE;

		if(GetAsyncKeyState('W') && !beforeState[speckey+1]){
			pitch++;
			beforeState[speckey+1] = TRUE;
		}else if(!GetAsyncKeyState('W'))beforeState[speckey+1] = FALSE;

		if(GetAsyncKeyState('E') && !beforeState[speckey+2]){
			pitch = 0;
			beforeState[speckey+2] = TRUE;
		}else if(!GetAsyncKeyState('E'))beforeState[speckey+2] = FALSE;

		if(GetAsyncKeyState('R')){
			midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, ToneChoise(), 0));
		}
		if(GetAsyncKeyState('Y')){
			midiOutReset(hmo);
		}
		if(GetAsyncKeyState('T')){
			midiOutShortMsg(hmo, MAKESMSG(CONTROL_CHANGE, CH, MODULATION, SelectNumber("Modulation",127)));
		}
		if(GetAsyncKeyState('U')){
			midiOutShortMsg(hmo, MAKESMSG(CONTROL_CHANGE, CH, RELEASETIME, SelectNumber("ReleaseTime",127)));
		}
		if(GetAsyncKeyState('I')){
			C4 = SelectC4();
		}
		if(GetAsyncKeyState('P') && !beforeState[speckey+3]){
			if(CH == 9) CH = 0;
			else if(CH == 0) CH = 9;
			printf("\nCH : %d",CH);
			midiOutShortMsg(hmo, MAKESMSG(PROGRAM_CHANGE, CH, 0x0, 0));
			beforeState[speckey+3] = TRUE;
		}else if(!GetAsyncKeyState('P'))beforeState[speckey+3] = FALSE;
	}
	midiOutReset(hmo);
	midiOutClose(hmo);
	return 0;
}