#include <iostream>
#include <cmath>

#define PI 3.1415926
using namespace std;


char* mapinit();
char* map=mapinit();

float initx,inity,initphi;
float caltheta(float,float,float,float*);
double tsk(float* MFS)
{	
	float x=initx,y=inity,phi=initphi;
	float theta=0;
	float SAE=0;
	for(int epoch=0;epoch<65;epoch++){
		theta=caltheta(x,y,phi,MFS);
		//theta=10.5;
		x=x+cos(PI/180*(phi+theta))+sin(PI/180*(theta))*sin(PI/180*(phi));
		y=y-sin(PI/180*(phi+theta))+sin(PI/180*(theta))*cos(PI/180*(phi));
		phi=phi-180/PI*asin(2*sin(PI/180*theta)/4);
		SAE+=pow(sqrt(pow(x-20,2)+pow(y-30,2))-10,2);
		printf("%2.4f,\t%2.4f,\t%2.4f\n",x,y,phi);
		*(map+50*int(x)+int(y))='*';
		
	}
	printf("SAE=%f\n",SAE);
}

double wei(float ,float ,float );
float caltheta(float x ,float y ,float phi ,float* MFS){
	float num=0;
	float den=0.0000000000000000000000000000000000000001;
	for(int i=0;i<5;i++){
		num+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4),*(MFS+i*7+5))*(*(MFS+i*7+6));
		num+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4)-360,*(MFS+i*7+5))*(*(MFS+i*7+6));
		num+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4)+360,*(MFS+i*7+5))*(*(MFS+i*7+6));
		den+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4),*(MFS+i*7+5));
		den+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4)-360,*(MFS+i*7+5));
		den+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4)+360,*(MFS+i*7+5));
		
	}
	//printf("%.30f\n",num/den);
	if(num/den>20)
		return 20;
	else if(num/den<-20)
		return -20;
	else
		return num/den;
}

double wei(float v,float mean,float standard){
	return exp(-(v-mean)*(v-mean)/(standard*standard));
}




void showImg(char* );

int main(int argc, char** argv) {

	printf("input the initial position(x y phi)[ÄY¸T­t¼Æ]\n");
	scanf("%f %f %f",&initx,&inity,&initphi);
	
	
	float MFS[35]={3.102373,34.912926,0.386399,101.375404,87.189606,0.833177,18.456774,
35.592289,3369.644287,20.027702,124.049515,221.566956,28.442076,11.296500,
3.456865,48.802990,4.467012,2.291202,505.497559,38.740540,11.449064,
20.996389,0.017950,46.596443,54.101460,5708.147461,22.577671,2.273324,
1.103522,280.730194,11.117827,195.369125,74.655830,2.787043,10.923265 
};
	
	/*
	float MFS[35]={	20-9*cos(PI/180*(0+36)),3,30-11*sin(PI/180*(0+36)),3,90+36,10,11.5,
					20-9*cos(PI/180*(72+36)),3,30-11*sin(PI/180*(72+36)),3,162+36,10,11.5,
					20-9*cos(PI/180*(144+36)),3,30-11*sin(PI/180*(144+36)),3,234+36,10,11.5,
					20-9*cos(PI/180*(216+36)),3,30-11*sin(PI/180*(216+36)),3,306+36,10,11.5,
					20-9*cos(PI/180*(288+36)),3,30-11*sin(PI/180*(288+36)),3,18+36,10,11.5
	};*/
	tsk(MFS);
	

	
	
	showImg(map);
	system("PAUSE");
	return 0;
}

char* mapinit()
{
	static char m[50][50];	
	char* mp[50];	
	for(int x=0;x<50;x++){
		mp[x]=m[x]; 
		for(int y=0;y<50;y++){ 
			m[x][y]=' ';	
		}	
	}
	return &m[0][0];
}


void showImg(char* m){//Transpose display
	for(int i=0;i<50;i++) cout<<"__";
	cout<<endl;
	for(int x=0;x<50;x++){
		cout<<"|";
			for(int y=0;y<50;y++)
				printf("%c ",*(m+y*50+x));
		cout<<"|"<<endl;	
	}	
	for(int i=0;i<50;i++) cout<<"--";
	cout<<endl;
	for(int i=0;i<50;i++) cout<<" ";
	cout<<'X';	
	cout<<endl;
}
