#include <Arduino.h>
#include <Servo.h>

Servo YATAY;
Servo DIKEY;

int pos1 = 90;
int pos2 = 90;

const int LDR_SOL = A0;
const int LDR_SAG = A1;
const int LDR_YUKARI = A2;
const int LDR_ASAGI = A3;

int SOL = 0;
int SAG = 0;
int YUKARI = 0;
int ASAGI = 0;


void setup() {

	YATAY.attach(9);
	DIKEY.attach(10);
	Serial.begin(9600);
}

void loop() {

	SOL = analogRead(LDR_SOL);
	SAG = analogRead(LDR_SAG);
	YUKARI = analogRead(LDR_YUKARI);
	ASAGI = analogRead(LDR_ASAGI);

	if (SOL > SAG){
		if (pos1 > 0){
			pos1 -= 1;
			YATAY.write(pos1);
		}
	}

	if (SAG > SOL){
			if (pos1 < 180){
				pos1++;
				YATAY.write(pos1);
			}
		}


	if (ASAGI > YUKARI){
			if (pos2 > 60){
				pos2 -= 1;
				DIKEY.write(pos2);
			}
	}

	if (YUKARI > ASAGI){
			if (pos2 < 110){
				pos2++;
				DIKEY.write(pos2);
			}
		}


	delay(15);
}


