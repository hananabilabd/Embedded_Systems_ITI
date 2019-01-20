#include <util/delay.h>
#define F_CPU 8000000
#include "std_types.h"
#include "registers.h"
#include "DIO.h"
#include "KeyPad.h"
#include "KeyPad_cfg.h"
void KeybPadInit(void){
DIOSetPinDirection(KeyPadPort,R0,0);
DIOSetPinValue(KeyPadPort,R0,1);// to activate the Internal Pull Up Resistor of UC
DIOSetPinDirection(KeyPadPort,R1,0);
DIOSetPinValue(KeyPadPort,R1,1);
DIOSetPinDirection(KeyPadPort,R2,0);
DIOSetPinValue(KeyPadPort,R2,1);
DIOSetPinDirection(KeyPadPort,R3,0);
DIOSetPinValue(KeyPadPort,R3,1);

DIOSetPinDirection(KeyPadPort,C0,1);
DIOSetPinDirection(KeyPadPort,C1,1);
DIOSetPinDirection(KeyPadPort,C2,1);
DIOSetPinDirection(KeyPadPort,C3,1);
}
u8 keyPadGetStatus (u8 button){
	u8 value=0;
	u8 row=button/4;
	u8 col=button%4;
u8 rows[]={R0,R1,R2,R3};
u8 cols[]={C0,C1,C2,C3};
	DIOSetPinValue(KeyPadPort,C0,1);
	DIOSetPinValue(KeyPadPort,C1,1);
	DIOSetPinValue(KeyPadPort,C2,1);
	DIOSetPinValue(KeyPadPort,C3,1);
	DIOSetPinValue(KeyPadPort,cols[col],0);

 u8 x=DIOGetPinValue(KeyPadPort,rows[row]);
if(x==0) {                      // because we use Pull Up Resistor
_delay_ms(25);
 x=DIOGetPinValue(KeyPadPort,rows[row]);
if(x==0){
value=1;}
}
return value;
}

