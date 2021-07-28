#ifdef RaspberryPi

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>

char device[]="/dev/ttyACM0";
int fd;
unsigned long baud=9600;
unsigned long time=0;

void setup(){
	printf("%s \n","Raspberry Startup!");
	fflush(stdout);
	
	if((fd=serialOpen(device,baud))<0){
		fprintf(stderr,"Unable to open serial device : %s\n",strerror(errno));
		exit(1);
	}

	if(wiringPiSetup()==-1){
		fprintf(stdout,"Unable to start wiringPi : %s\n",strerror(errno));
		exit(1);
	}
}

void loop(){
	if(millis()-time>=3000){
		serialPuts(fd,"Pong!\n");
		serialPutchar(fd,65);
		time=millis();
	}

	if(serialDataAvail(fd)){
		char newChar=serialGetchar(fd);
		printf("%c",newChar);
		fflush(stdout);
	}
}

int main(){
	setup();
	while(1)
	       	loop();
	return 0;
}

#endif
