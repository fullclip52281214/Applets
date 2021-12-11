#include <iostream>
#include <cmath>
#include <stdio.h> /* 亂數相關函數 */
#include <time.h>  /* 時間相關函數 */

#define POPLUATION 4000
#define PI 3.1415926
using namespace std;



class best16{
	public:
		float SAE;
		float MFS[35];
	void assignMF(float* NMF){
		for(int i=0;i<35;i++){
			MFS[i]=*(NMF+i);
		}
	}
};

best16 v[16];
class person{
	public:
		float SAE;
		float MFS[35];
		
	person(){		
		for(int i=0;i<35;i++){
			MFS[i]=v[rand()%16].MFS[i]; 
			if(rand()%5==1){   //20% chance of mutation for each parameter
				MFS[i]*=(1-pow((double) rand() /( 1.2 * (RAND_MAX)),4));	
			}
			if(rand()%5==1){   //20% chance of mutation for each parameter to another direction
				MFS[i]/=(1-pow((double) rand() /( 1.2 * (RAND_MAX)),4));	
			}
			for(int i=0;i<35;i+=7){
				if((MFS[i+6])>360){
					MFS[i+6]-=360;
				}
			}
		}
	} 				
	
};

void initialGene(best16* v){
	float ptr0[35]={20-11*cos(PI/180*(0+36)),3,30-11*sin(PI/180*(0+36)),3,90+36,10,12,
					20-11*cos(PI/180*(72+36)),3,30-11*sin(PI/180*(72+36)),3,162+36,10,12,
					20-11*cos(PI/180*(144+36)),3,30-11*sin(PI/180*(144+36)),3,234+36,10,12,
					20-11*cos(PI/180*(216+36)),3,30-11*sin(PI/180*(216+36)),3,306+36,10,12,
					20-11*cos(PI/180*(288+36)),3,30-11*sin(PI/180*(288+36)),3,18+36,10,12};
	float ptr1[35]={20-9*cos(PI/180*(0+36)),3,30-11*sin(PI/180*(0+36)),3,90+36,10,12,
					20-9*cos(PI/180*(72+36)),3,30-11*sin(PI/180*(72+36)),3,162+36,10,12,
					20-9*cos(PI/180*(144+36)),3,30-11*sin(PI/180*(144+36)),3,234+36,10,12,
					20-9*cos(PI/180*(216+36)),3,30-11*sin(PI/180*(216+36)),3,306+36,10,12,
					20-9*cos(PI/180*(288+36)),3,30-11*sin(PI/180*(288+36)),3,18+36,10,12};
	float ptr2[35]={20-11*cos(PI/180*0),3,30-11*sin(PI/180*0),3,90+36,10,12,
					20-11*cos(PI/180*72),3,30-11*sin(PI/180*72),3,162+36,10,12,
					20-11*cos(PI/180*144),3,30-11*sin(PI/180*144),3,234+36,10,12,
					20-11*cos(PI/180*216),3,30-11*sin(PI/180*216),3,306+36,10,12,
					20-11*cos(PI/180*288),3,30-11*sin(PI/180*288),3,18+36,10,12};
	float ptr3[35]={20-9*cos(PI/180*0),3,30-11*sin(PI/180*0),3,90+36,10,12,
					20-9*cos(PI/180*72),3,30-11*sin(PI/180*72),3,162+36,10,12,
					20-9*cos(PI/180*144),3,30-11*sin(PI/180*144),3,234+36,10,12,
					20-9*cos(PI/180*216),3,30-11*sin(PI/180*216),3,306+36,10,12,
					20-9*cos(PI/180*288),3,30-11*sin(PI/180*288),3,18+36,10,12};	
	float ptr4[35]={20-11*cos(PI/180*(0+36)),3,30-11*sin(PI/180*(0+36)),3,90,10,12,
					20-11*cos(PI/180*(72+36)),3,30-11*sin(PI/180*(72+36)),3,162,10,12,
					20-11*cos(PI/180*(144+36)),3,30-11*sin(PI/180*(144+36)),3,234,10,12,
					20-11*cos(PI/180*(216+36)),3,30-11*sin(PI/180*(216+36)),3,306,10,12,
					20-11*cos(PI/180*(288+36)),3,30-11*sin(PI/180*(288+36)),3,18,10,12};
	float ptr5[35]={20-9*cos(PI/180*(0+36)),3,30-11*sin(PI/180*(0+36)),3,90,10,12,
					20-9*cos(PI/180*(72+36)),3,30-11*sin(PI/180*(72+36)),3,162,10,12,
					20-9*cos(PI/180*(144+36)),3,30-11*sin(PI/180*(144+36)),3,234,10,12,
					20-9*cos(PI/180*(216+36)),3,30-11*sin(PI/180*(216+36)),3,306,10,12,
					20-9*cos(PI/180*(288+36)),3,30-11*sin(PI/180*(288+36)),3,18,10,12};
	float ptr6[35]={20-11*cos(PI/180*0),3,30-11*sin(PI/180*0),3,90,10,12,
					20-11*cos(PI/180*72),3,30-11*sin(PI/180*72),3,162,10,12,
					20-11*cos(PI/180*144),3,30-11*sin(PI/180*144),3,234,10,12,
					20-11*cos(PI/180*216),3,30-11*sin(PI/180*216),3,306,10,12,
					20-11*cos(PI/180*288),3,30-11*sin(PI/180*288),3,18,10,12};
	float ptr7[35]={20-9*cos(PI/180*0),3,30-11*sin(PI/180*0),3,90,10,12,
					20-9*cos(PI/180*72),3,30-11*sin(PI/180*72),3,162,10,12,
					20-9*cos(PI/180*144),3,30-11*sin(PI/180*144),3,234,10,12,
					20-9*cos(PI/180*216),3,30-11*sin(PI/180*216),3,306,10,12,
					20-9*cos(PI/180*288),3,30-11*sin(PI/180*288),3,18,10,12};
					
	float ptr8[35]={20-11*cos(PI/180*(0+36)),3,30-11*sin(PI/180*(0+36)),3,90+36,10,11,
					20-11*cos(PI/180*(72+36)),3,30-11*sin(PI/180*(72+36)),3,162+36,10,11,
					20-11*cos(PI/180*(144+36)),3,30-11*sin(PI/180*(144+36)),3,234+36,10,11,
					20-11*cos(PI/180*(216+36)),3,30-11*sin(PI/180*(216+36)),3,306+36,10,11,
					20-11*cos(PI/180*(288+36)),3,30-11*sin(PI/180*(288+36)),3,18+36,10,11};
	float ptr9[35]={20-9*cos(PI/180*(0+36)),3,30-11*sin(PI/180*(0+36)),3,90+36,10,11,
					20-9*cos(PI/180*(72+36)),3,30-11*sin(PI/180*(72+36)),3,162+36,10,11,
					20-9*cos(PI/180*(144+36)),3,30-11*sin(PI/180*(144+36)),3,234+36,10,11,
					20-9*cos(PI/180*(216+36)),3,30-11*sin(PI/180*(216+36)),3,306+36,10,11,
					20-9*cos(PI/180*(288+36)),3,30-11*sin(PI/180*(288+36)),3,18+36,10,11};
	float ptr10[35]={20-11*cos(PI/180*0),3,30-11*sin(PI/180*0),3,90+36,10,11,
					20-11*cos(PI/180*72),3,30-11*sin(PI/180*72),3,162+36,10,11,
					20-11*cos(PI/180*144),3,30-11*sin(PI/180*144),3,234+36,10,11,
					20-11*cos(PI/180*216),3,30-11*sin(PI/180*216),3,306+36,10,11,
					20-11*cos(PI/180*288),3,30-11*sin(PI/180*288),3,18+36,10,11};
	float ptr11[35]={20-9*cos(PI/180*0),3,30-11*sin(PI/180*0),3,90+36,10,11,
					20-9*cos(PI/180*72),3,30-11*sin(PI/180*72),3,162+36,10,11,
					20-9*cos(PI/180*144),3,30-11*sin(PI/180*144),3,234+36,10,11,
					20-9*cos(PI/180*216),3,30-11*sin(PI/180*216),3,306+36,10,11,
					20-9*cos(PI/180*288),3,30-11*sin(PI/180*288),3,18+36,10,11};	
	float ptr12[35]={20-11*cos(PI/180*(0+36)),3,30-11*sin(PI/180*(0+36)),3,90,10,11,
					20-11*cos(PI/180*(72+36)),3,30-11*sin(PI/180*(72+36)),3,162,10,11,
					20-11*cos(PI/180*(144+36)),3,30-11*sin(PI/180*(144+36)),3,234,10,11,
					20-11*cos(PI/180*(216+36)),3,30-11*sin(PI/180*(216+36)),3,306,10,11,
					20-11*cos(PI/180*(288+36)),3,30-11*sin(PI/180*(288+36)),3,18,10,11};
	float ptr13[35]={20-9*cos(PI/180*(0+36)),3,30-11*sin(PI/180*(0+36)),3,90,10,11,
					20-9*cos(PI/180*(72+36)),3,30-11*sin(PI/180*(72+36)),3,162,10,11,
					20-9*cos(PI/180*(144+36)),3,30-11*sin(PI/180*(144+36)),3,234,10,11,
					20-9*cos(PI/180*(216+36)),3,30-11*sin(PI/180*(216+36)),3,306,10,11,
					20-9*cos(PI/180*(288+36)),3,30-11*sin(PI/180*(288+36)),3,18,10,11};
	float ptr14[35]={20-11*cos(PI/180*0),3,30-11*sin(PI/180*0),3,90,10,11,
					20-11*cos(PI/180*72),3,30-11*sin(PI/180*72),3,162,10,11,
					20-11*cos(PI/180*144),3,30-11*sin(PI/180*144),3,234,10,11,
					20-11*cos(PI/180*216),3,30-11*sin(PI/180*216),3,306,10,11,
					20-11*cos(PI/180*288),3,30-11*sin(PI/180*288),3,18,10,11};
	float ptr15[35]={20-9*cos(PI/180*0),3,30-11*sin(PI/180*0),3,90,10,11,
					20-9*cos(PI/180*72),3,30-11*sin(PI/180*72),3,162,10,11,
					20-9*cos(PI/180*144),3,30-11*sin(PI/180*144),3,234,10,11,
					20-9*cos(PI/180*216),3,30-11*sin(PI/180*216),3,306,10,11,
					20-9*cos(PI/180*288),3,30-11*sin(PI/180*288),3,18,10,11};
	float* initMF[]={ptr0,ptr1,ptr2,ptr3,ptr4,ptr5,ptr6,ptr7,ptr8,ptr9,ptr10,ptr11,ptr12,ptr13,ptr14,ptr15};
	
	for(int i=0;i<16;i++){
		v[i].assignMF(*(initMF+i));
	}
	for(int i=0;i<16;i++){
		v[i].SAE=5.5;//亂猜的，我沒算
	}
}



float initx=10,inity=30,initphi=90;
float caltheta(float,float,float,float*);
double tsk(float* MFS)
{	
	float x=initx,y=inity,phi=initphi;
	float theta=0;
	float SAE=0;
	for(int epoch=0;epoch<65;epoch++){
		theta=caltheta(x,y,phi,MFS);
		
		x=x+cos(PI/180*(phi+theta))+sin(PI/180*(theta))*sin(PI/180*(phi));
		y=y-sin(PI/180*(phi+theta))+sin(PI/180*(theta))*cos(PI/180*(phi));
		phi=phi-180/PI*asin(2*sin(PI/180*theta)/4);
		SAE+=pow(sqrt(pow(x-20,2)+pow(y-30,2))-10,2);
		
		
	}
	//printf("SAE=%.3f\n",SAE);
	return SAE;
}

double wei(float ,float ,float );
float caltheta(float x ,float y ,float phi ,float* MFS){
	float num=0;
	float den=0.0000000000000000000000000000000000000001;//會使軌跡些微彎折
	for(int i=0;i<5;i++){
		num+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4),*(MFS+i*7+5))*(*(MFS+i*7+6));
		num+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4)-360,*(MFS+i*7+5))*(*(MFS+i*7+6));
		num+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4)+360,*(MFS+i*7+5))*(*(MFS+i*7+6));
		den+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4),*(MFS+i*7+5));
		den+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4)-360,*(MFS+i*7+5));
		den+=wei(x,*(MFS+i*7+0),*(MFS+i*7+1))*wei(y,*(MFS+i*7+2),*(MFS+i*7+3))*wei(phi,*(MFS+i*7+4)+360,*(MFS+i*7+5));
		//den=1;
		
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



void updatabest16(int*,person*);

int main(int argc, char** argv) {

	initialGene(v);

	srand((unsigned)(time(NULL)+getpid()));

	/*
	for(int i=0;i<1000;i++){
		printf("NO.%d:\n",i);
		printf("%f\n",tsk(p[i].MFS));
	}*/
	float HisSAE=5.5;
	float HisMF[35]={5,3,30,3,126,10,14, 15,3,16,3,54,10,14, 32,3,21,3,342,10,14, 32,3,38,3,270,10,14, 15,3,44,3,198,10,14};
	for(int epoch=1;epoch<800;epoch++){
		//printf("\nepoch: %d\n",epoch);
		person p[POPLUATION];
		for(int i=0;i<POPLUATION;i++){
			p[i].SAE=tsk(p[i].MFS);
			//printf("%.0f\n",p[i].SAE);
		}
		int NewBestIndex[16];
		float NewBestSAE[16];
		for(int setV=0;setV<16;setV++){
			NewBestIndex[setV]=999999;
			NewBestSAE[setV]=999999;
		}
		for(int i=0;i<POPLUATION;i++){
			//printf("NO:%d\n",i);
			short flag=16;
			for(int index=0;index<16;index++){
				if((p[i].SAE) < NewBestSAE[index]){
					flag=index;
					break;
				}
			}
			for(int index=(16-1);index>=flag;index--){
				if(index>flag){
					NewBestIndex[index]=NewBestIndex[index-1];
					NewBestSAE[index]=NewBestSAE[index-1];
				}
				if(index==flag){
					NewBestIndex[index]=i;
					NewBestSAE[index]=p[i].SAE;
				}		
			}
		}
		/*show one epoch
		cout<<"bestSAE=";
		for(int index=0;index<16;index++)
			printf("%f ",NewBestSAE[index]);
		cout<<endl;
		cout<<"index=";
		for(int index=0;index<16;index++)
			printf("%d ",NewBestIndex[index]);
		cout<<endl;
		*/
		if(NewBestSAE[0]<HisSAE){
			//printf("newrecord \nSAE:%f\n",NewBestSAE[0]);
			HisSAE=NewBestSAE[0];
			for(int i=0;i<35;i++){
				HisMF[i]=p[NewBestIndex[0]].MFS[i];
			//	printf("%f,",HisMF[i]);
			}
			//cout<<endl;
		}
		
		updatabest16(NewBestIndex,p);
		//show best(V)
		/*
		cout<<"Next Best 16"<<endl;
		for(int i=0;i<16;i++){
			for(int j=0;j<35;j++)
				printf("%6.1f",v[i].MFS[j]);
			cout<<endl;
		}*/
		cout<<HisSAE<<"\n";
	}
	cout<<"\nBestMF\nRule :  x_mean x_standard y_mean y_standard phi_mean phi_standard theta_i\n"; 
	for(int i=0;i<5;i++){		
		for(int j=0;j<7;j++){
			printf("%f,",HisMF[i*7+j]);
		}
		cout<<endl;
	}
	printf("HisSAE=%f\n",HisSAE);
	system("pause"); 
	system("pause"); 
	system("pause"); 
	system("pause"); 
	return 0;
}

void updatabest16(int* index,person* p){
	for(int i=0;i<16;i++){
		v[i].assignMF(p[*(index+i)].MFS);
		v[i].SAE=p[*(index+i)].SAE;
	}
}


