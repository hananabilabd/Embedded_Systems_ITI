Music player using ATmega32 &  2-2R DAC &  LedMatrix of heart animation . 
-trimmed 6 second of  .mp3 song 6 using Audicity.
- saved it as song.raw  encoding 8 bit unsigned , headerless.
- converted song.raw into an array using XXD with command 
xxd -i song.raw > song.h
- include song.h 
- to put the array in ROM open song.h and edit it to be 
unsigned char song_raw[4087] __attribute__ (( __progmem__))= {...}
- to access array from ROM 
asm("LPM %0,Z" "\n\t" : "=r" (PORTD): "z" (&song_raw[i]))
- put this line of code in overflow or compare match timer interrupt function
- If you are sampling say with 4KHZ and you clock frequency is 12MHZ , and you timer clock with prescaler say equals 8 , then you want to play sample every = (1/4000) / (8/12*10^6) = 375 
- you want to play sample every 375 of timer tick 