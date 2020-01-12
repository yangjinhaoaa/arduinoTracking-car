
//140 255 255
#define SPEED 205


//no pid

// #define sig0 9

#define sig0 10
#define sig1 9
#define sig2 3
#define sig3 2
#define sig4 11

// #define sig1 3
// #define sig2 2
// #define sig3 10
// #define sig4 11

#define leftpinA 7
#define leftpinB 6
#define rightpinA 4
#define rightpinB 5
int sensorread();
void forward();
void turnsmallleft();
void turnsmallright();
void turnbigleft();
void turnbigright();
void turncircle();
void turnstop();

#define led 13
int halo;
int s[5];
int status;

void setup() {
	pinMode(sig0, INPUT);
	pinMode(sig1, INPUT);
	pinMode(sig2, INPUT);
	pinMode(sig3, INPUT);
	pinMode(sig4, INPUT);

	pinMode(led, OUTPUT);
	pinMode(leftpinA, OUTPUT);
	pinMode(leftpinB, OUTPUT);
	pinMode(rightpinA, OUTPUT);
	pinMode(rightpinB, OUTPUT);

	//Serial.begin(9600);
	//Serial.println("start ");
}

void loop() {
	static int getstatus = 0;

	getstatus = sensorread();
	switch (getstatus) {
	case 0: {forward();} break;
	case -2: {turnbigright();turnbigright();} break;
	case -1: {turnsmallright();} break;

	case 1: {turnsmallleft();} break;
	case 2: {turnbigleft();turnbigleft();} break;

	case 3: {forward();} break;//turnsmallleft();turnsmallright();
	case -3: {forward();} break;//turnsmallleft();turnsmallright();
	case 4: forward();; break;

	default: forward(); break;
	}



}

int sensorread() {
	s[0] = digitalRead(sig0);
	s[1] = digitalRead(sig1);
	s[2] = digitalRead(sig2);
	s[3] = digitalRead(sig3);
	s[4] = digitalRead(sig4);

	if ((s[0] == 0) && (s[1] == 0) && (s[2] == 0) && (s[3] == 0) && (s[4] == 1)) {
		status = 2;//          0 0 0 0 1
	} else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 0) && (s[3] == 1) && (s[4] == 0)) {
		status = 1;//          0 0 0 1 0
	} else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 1) && (s[3] == 0) && (s[4] == 0)) {
		status = 0;//          0 0 1 0 0
	} else if ((s[0] == 0) && (s[1] == 1) && (s[2] == 0) && (s[3] == 0) && (s[4] == 0)) {
		status = -1;//         0 1 0 0 0
	} else if ((s[0] == 1) && (s[1] == 0) && (s[2] == 0) && (s[3] == 0) && (s[4] == 0)) {
		status = -2;//         1 0 0 0 0

	} else if ((s[4] ==1)&&(s[0]==1)){
		status = 4;
	} 	else if ((s[0] == 0) && (s[1] == 0) && (s[2] == 0) && (s[3] == 0) && (s[4] == 0)) {


		if (status == -2) {//  0 0 0 0 0
			status = -3;
		} else {
			status = 3;
		}
	}

	// if(s[0]==1&&s[1]==1&&s[2]==1&&s[3]==1&&s[4]==1){ ///全黑线
	// 	status=4;
	// }else 	if(s[0]==0&&s[1]==0&&s[2]==0&&s[3]==0&&s[4]==0){
	// 	status=3;
	// }else	if(s[0]==1&&s[1]==0&&s[2]==0&&s[3]==0&&s[4]==0){
	// 	status=-2;
	// }else	if(s[0]==0&&s[1]==1&&s[2]==0&&s[3]==0&&s[4]==0){
	// 	status=-1;
	// }else	if(s[0]==0&&s[1]==0&&s[2]==1&&s[3]==0&&s[4]==0){
	// 	status=0;
	// }else	if(s[0]==0&&s[1]==0&&s[2]==0&&s[3]==1&&s[4]==0){
	// 	status=1;
	// }else	if(s[0]==0&&s[1]==0&&s[2]==0&&s[3]==0&&s[4]==1){
	// 	status=2;
	// }
	// else{
	// 	status=3;
	// }

	return status;
}


void forward() {
	analogWrite(leftpinA, 0);
	analogWrite(leftpinB, SPEED);
	analogWrite(rightpinA, 0);
	analogWrite(rightpinB, SPEED);
	//Serial.println("直行");

}

void turnsmallleft() {

	analogWrite(leftpinA, 0);
	analogWrite(leftpinB, 136);
	analogWrite(rightpinA, 0);
	analogWrite(rightpinB, 250);
	//Serial.println("左小转");
	//delay(100);


}
void turnsmallright() {

	analogWrite(leftpinA, 0);
	analogWrite(leftpinB, 250);
	analogWrite(rightpinA, 0);
	analogWrite(rightpinB, 136);
	//Serial.println("右小转");
	//delay(25);


}
void turnbigleft() {
	analogWrite(leftpinA, 0);
	analogWrite(leftpinB, 0);
	analogWrite(rightpinA, 0);
	analogWrite(rightpinB, 250);
	//Serial.println("左大转");
	//delay(25);
}
void turnbigright() {
	analogWrite(leftpinA, 0);
	analogWrite(leftpinB, 250);
	analogWrite(rightpinA, 0);
	analogWrite(rightpinB, 0);
	//Serial.println("右大转");
	//delay(10);
}
