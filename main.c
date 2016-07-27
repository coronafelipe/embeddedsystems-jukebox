/*
 * CS145Lab2.c
 *
 * Created: 4/21/2016 3:54:15 PM
 * Author : toran
 */ 
#include "avr.h"
unsigned int speed = 1;
unsigned int convertKeypad(unsigned int input)
{
	unsigned int output = input;
	if(input == 5 || input == 6 || input == 7)
	{
		output = input - 1;
	}
	else if(input == 9 ||input == 10 || input == 11)
	{
		output = input - 2;
	}
	else if(input == 14)
	{
		output = 0;
	}
	
	
	return output;
	
}

unsigned char pressed(unsigned char r, unsigned char c)
{
	DDRC = 0;
	PORTC = 0;
	SET_BIT(DDRC, c + 4);
	SET_BIT(PORTC, r);
	CLR_BIT(PORTC, c + 4);
	//CLR_BIT(PORTC, r << 4);
	
	wait_avr(1);
	
	if(!(GET_BIT(PINC, r)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned char get_key()
{
	unsigned char r;
	unsigned char c;
	//char inputLine[32];
	//PORTC = 0x0b00001111;
	//SET_BIT(PORTC, 4);
	//SET_BIT(PORTC, 5);
	//SET_BIT(PORTC, 6);
	//SET_BIT(PORTC, 7);
	
	for(r = 0; r < 4; ++r)
	{
		for(c = 0; c < 4; ++c)
		{
			
			if (pressed(r, c))
			{
				/*
				pos_lcd(1,0);
				sprintf(inputLine, "%d  %d", r , c);
				puts_lcd2(inputLine);
				*/
				return (r * 4) + (c + 1);
			}
		}
	}
	return 0;
}


struct note
{
	unsigned int freq;
	unsigned int dur;
	unsigned int delay;
};


struct note mySong[41];
struct note mySong1[42];


						
void playNote(struct note theNote)
{
	for(unsigned long i = 0; i < theNote.dur; i++)
	{
		SET_BIT(PORTB, 3);
		wait_avr(theNote.freq);
		CLR_BIT(PORTB, 3);
		wait_avr(theNote.freq);
	}
	wait_avr2((theNote.delay / speed));
}
 
 int main (void)
 {
	 //map<unsigned int, unsigned int> song;
	 //song
	SET_BIT(DDRB, 3);
	
	mySong[0].freq = 76;
	mySong[0].dur = 100;
	mySong[0].delay = 150;
	
	mySong[1].freq = 76;
	mySong[1].dur = 100;
	mySong[1].delay = 300;
	
	mySong[2].freq = 76;
	mySong[2].dur = 100;
	mySong[2].delay = 300;
	
	mySong[3].freq = 95;
	mySong[3].dur = 100;
	mySong[3].delay = 100;
	
	mySong[4].freq = 76;
	mySong[4].dur = 100;
	mySong[4].delay = 300;
	
	mySong[5].freq = 63;
	mySong[5].dur = 100;
	mySong[5].delay = 550;
		
	mySong[6].freq = 131;
	mySong[6].dur = 100;
	mySong[6].delay = 575;
			
	mySong[7].freq = 98;
	mySong[7].dur = 100;
	mySong[7].delay = 450;

	mySong[8].freq = 131;
	mySong[8].dur = 100;
	mySong[8].delay = 400;

	mySong[9].freq = 156;
	mySong[9].dur = 100;
	mySong[9].delay = 500;

	mySong[10].freq = 113;
	mySong[10].dur = 100;
	mySong[10].delay = 300;

	mySong[11].freq = 104;
	mySong[11].dur = 80;
	mySong[11].delay = 330;

	mySong[12].freq = 111;
	mySong[12].dur = 100;
	mySong[12].delay = 150;

	mySong[13].freq = 116;
	mySong[13].dur = 100;
	mySong[13].delay = 300;

	mySong[14].freq = 131;
	mySong[14].dur = 100;
	mySong[14].delay = 200;

	mySong[15].freq = 76;
	mySong[15].dur = 80;
	mySong[15].delay = 200;

	mySong[16].freq = 66;
	mySong[16].dur = 50;
	mySong[16].delay = 150;

	mySong[17].freq = 58;
	mySong[17].dur = 100;
	mySong[17].delay = 300;

	mySong[18].freq = 71;
	mySong[18].dur = 80;
	mySong[18].delay = 150;

	mySong[19].freq = 66;
	mySong[19].dur = 50;
	mySong[19].delay = 350;

	mySong[20].freq = 76;
	mySong[20].dur = 80;
	mySong[20].delay = 300;

	mySong[21].freq = 96;
	mySong[21].dur = 80;
	mySong[21].delay = 150;

	mySong[22].freq = 86;
	mySong[22].dur = 80;
	mySong[22].delay = 150;

	mySong[23].freq = 104;
	mySong[23].dur = 80;
	mySong[23].delay = 500;
	
	mySong[24].freq = 98;
	mySong[24].dur = 100;
	mySong[24].delay = 450;

	mySong[25].freq = 131;
	mySong[25].dur = 100;
	mySong[25].delay = 400;

	mySong[26].freq = 156;
	mySong[26].dur = 100;
	mySong[26].delay = 500;

	mySong[27].freq = 113;
	mySong[27].dur = 100;
	mySong[27].delay = 300;

	mySong[28].freq = 104;
	mySong[28].dur = 80;
	mySong[28].delay = 330;

	mySong[29].freq = 111;
	mySong[29].dur = 100;
	mySong[29].delay = 150;

	mySong[30].freq = 116;
	mySong[30].dur = 100;
	mySong[30].delay = 300;

	mySong[31].freq = 131;
	mySong[31].dur = 100;
	mySong[31].delay = 200;

	mySong[32].freq = 76;
	mySong[32].dur = 80;
	mySong[32].delay = 200;

	mySong[33].freq = 66;
	mySong[33].dur = 50;
	mySong[33].delay = 150;

	mySong[34].freq = 58;
	mySong[34].dur = 100;
	mySong[34].delay = 300;

	mySong[35].freq = 71;
	mySong[35].dur = 80;
	mySong[35].delay = 150;

	mySong[36].freq = 66;
	mySong[36].dur = 50;
	mySong[36].delay = 350;

	mySong[37].freq = 76;
	mySong[37].dur = 80;
	mySong[37].delay = 300;

	mySong[38].freq = 96;
	mySong[38].dur = 80;
	mySong[38].delay = 150;

	mySong[39].freq = 86;
	mySong[39].dur = 80;
	mySong[39].delay = 150;

	mySong[40].freq = 104;
	mySong[40].dur = 80;
	mySong[40].delay = 500;
	
	mySong1[0].freq = 85;
	mySong1[0].dur = 100;
	mySong1[0].delay = 80;

	mySong1[1].freq = 72;
	mySong1[1].dur = 100;
	mySong1[1].delay = 80;

	mySong1[2].freq = 43;
	mySong1[2].dur = 200;
	mySong1[2].delay = 250;

	mySong1[3].freq = 85;
	mySong1[3].dur = 100;
	mySong1[3].delay = 80;

	mySong1[4].freq = 72;
	mySong1[4].dur = 100;
	mySong1[4].delay = 80;

	mySong1[5].freq = 43;
	mySong1[5].dur = 200;
	mySong1[5].delay = 250;

	mySong1[6].freq = 37;
	mySong1[6].dur = 200;
	mySong1[6].delay = 200;

	mySong1[7].freq = 36;
	mySong1[7].dur = 100;
	mySong1[7].delay = 100;

	mySong1[8].freq = 37;
	mySong1[8].dur = 100;
	mySong1[8].delay = 80;

	mySong1[9].freq = 36;
	mySong1[9].dur = 100;
	mySong1[9].delay = 80;

	mySong1[10].freq = 37;
	mySong1[10].dur = 100;
	mySong1[10].delay = 80;

	mySong1[11].freq = 48;
	mySong1[11].dur = 100;
	mySong1[11].delay = 80;

	mySong1[12].freq = 57;
	mySong1[12].dur = 100;
	mySong1[12].delay = 300;

	mySong1[13].freq = 57;
	mySong1[13].dur = 200;
	mySong1[13].delay = 100;

	mySong1[13].freq = 85;
	mySong1[13].dur = 200;
	mySong1[13].delay = 100;

	mySong1[14].freq = 72;
	mySong1[14].dur = 100;
	mySong1[14].delay = 100;

	mySong1[15].freq = 64;
	mySong1[15].dur = 100;
	mySong1[15].delay = 100;

	mySong1[16].freq = 57;
	mySong1[16].dur = 100;
	mySong1[16].delay = 500;

	mySong1[17].freq = 57;
	mySong1[17].dur = 200;
	mySong1[17].delay = 100;

	mySong1[18].freq = 85;
	mySong1[18].dur = 200;
	mySong1[18].delay = 100;

	mySong1[19].freq = 72;
	mySong1[19].dur = 100;
	mySong1[19].delay = 100;

	mySong1[20].freq = 64;
	mySong1[20].dur = 100;
	mySong1[20].delay = 100;

	mySong1[21].freq = 76;
	mySong1[21].dur = 100;
	mySong1[21].delay = 500;


	mySong1[22].freq = 85;
	mySong1[22].dur = 100;
	mySong1[22].delay = 80;

	mySong1[23].freq = 72;
	mySong1[23].dur = 100;
	mySong1[23].delay = 80;

	mySong1[24].freq = 43;
	mySong1[24].dur = 200;
	mySong1[24].delay = 250;

	mySong1[25].freq = 85;
	mySong1[25].dur = 100;
	mySong1[25].delay = 80;

	mySong1[26].freq = 72;
	mySong1[26].dur = 100;
	mySong1[26].delay = 80;

	mySong1[27].freq = 43;
	mySong1[27].dur = 200;
	mySong1[27].delay = 250;

	mySong1[28].freq = 37;
	mySong1[28].dur = 200;
	mySong1[28].delay = 200;

	mySong1[29].freq = 36;
	mySong1[29].dur = 100;
	mySong1[29].delay = 100;

	mySong1[30].freq = 37;
	mySong1[30].dur = 100;
	mySong1[30].delay = 80;

	mySong1[31].freq = 36;
	mySong1[31].dur = 100;
	mySong1[31].delay = 80;

	mySong1[32].freq = 37;
	mySong1[32].dur = 100;
	mySong1[32].delay = 80;

	mySong1[33].freq = 48;
	mySong1[33].dur = 100;
	mySong1[33].delay = 80;

	mySong1[34].freq = 57;
	mySong1[34].dur = 100;
	mySong1[34].delay = 300;

	mySong1[35].freq = 57;
	mySong1[35].dur = 200;
	mySong1[35].delay = 100;

	mySong1[36].freq = 85;
	mySong1[36].dur = 200;
	mySong1[36].delay = 100;

	mySong1[37].freq = 72;
	mySong1[37].dur = 100;
	mySong1[37].delay = 100;

	mySong1[38].freq = 64;
	mySong1[38].dur = 100;
	mySong1[38].delay = 100;

	mySong1[39].freq = 57;
	mySong1[39].dur = 300;
	mySong1[39].delay = 100;

	mySong1[40].freq = 57;
	mySong1[40].dur = 200;
	mySong1[40].delay = 100;

	mySong1[41].freq = 85;
	mySong1[41].dur = 300;
	mySong1[41].delay = 2000;
	
	for (int i = 0; i < 41; i++){
		mySong[i].delay = (mySong[i].delay / 2);
	}
	
	ini_lcd();
	int running = 1;
	unsigned int keypressed = 0;
	char line1[32];
	char line2[32];
	pos_lcd(0,0);
	clr_lcd();
	sprintf(line1, "%d: %s" ,1, "Super Mario Theme");
	puts_lcd2(line1);
	pos_lcd(1,0);
	sprintf(line2, "%d: %s" , 2, "Zelda - Song of Storms");
	puts_lcd2(line2);
	
	while(running)
	{
		if(!(keypressed = get_key()))
		{
				
		}
		else
		{
			if(convertKeypad(keypressed) == 1)
			{
				
				for(int i = 0; i < 41; i++)
				{
					playNote(mySong[i]);
				}
			}
			else if(convertKeypad(keypressed) == 2)
			{
				for(int i = 0; i < 42; i++)
				{
					playNote(mySong1[i]);
				}
			}
			else if(convertKeypad(keypressed) == 7)
			{
				speed--;
				if(speed < 1)
				{
					speed = 1;
				}
			}
			else if(convertKeypad(keypressed) == 8)
			{
				speed++;
				if(speed > 4)
				{
					speed = 4;
				}
				
			}
			
			
		}
	}
				
	 
	 return 0;
 }
