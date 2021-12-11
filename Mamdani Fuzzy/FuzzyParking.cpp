#include <iostream>
#include <cmath>
using namespace std; 
#define PI 3.14159
//map size
#define XL 100
#define YL 100
//stepsize
#define R 1

char* initial();
void showImg(char*);
float calphi(float,float);

class control{
	public:
		int x[5][3]={{-35,0,35},{30,40,50},{45,50,55},{50,60,70},{65,100,135}};
		int phi[7][3]={{-100,-45,10},{-10,25,60},{40,65,90},{70,90,110},{90,115,140},{120,155,190},{170,225,280}};
		int theda[7][3]={{-45-30,-15},{-25,-15,-5},{-10,-5,0},{-5,0,5},{0,5,10},{5,15,25},{15,30,45}};		
		int mat[7][5]={
			{4,5,5,6,6},
			{2,4,5,6,6},
			{1,2,4,5,6},
			{1,1,3,5,5},
			{0,1,2,4,5},
			{0,0,1,2,4},
			{0,0,1,1,2}
			};	//phi first then x		
};
control c;



int main() {
	printf("which working mode you want?(1:one times  2:1932times ) \n");
	char mode;
	scanf("%c",&mode);
	
	if(mode=='2'){
		printf("running\n");
		int times=0;
		float TrajectoryError[7*5*69]={};
		float DockingError[7*5*69]={};
		for(int orix=20;orix<=80;orix+=10){
			for(int oriy=20;oriy<=50;oriy+=10){
				for(int oriphi=-80;oriphi<=260;oriphi+=5){
					
					float carx=orix,cary=oriy,carphi=oriphi;
					int epoch=0;
					while((carx>=0 && carx<=100)&&(cary>=0 && cary<=100)){
						
						carphi=calphi(carx,carphi);
						carx=carx+R*cos((carphi)/180*PI);
						cary=cary+R*sin((carphi)/180*PI);
						//printf("%f , %f, %f \n",carx,cary,carphi);
						
						epoch++;
						
					}
					TrajectoryError[times]=epoch/sqrt(pow(orix-50,2)+pow((oriy-100),2));
					//cout<<TrajectoryError[times]<<endl;
					DockingError[times]=sqrt(pow(((carphi-90)/180),2)+pow(((carx-50)/50),2)+pow(((cary-100)/100),2));
					//BUG dectector
					if(TrajectoryError[times]<1)
						printf("when %d %d %d \n",orix,oriy,oriphi);			
					
		
					times++;			
				}
				printf("progress=%.3f%%\n",100*times/1932.0);				
			}		
		}
		double AvgTrajectoryError=0,AvgDockingError=0;
		for(int i=0;i<1932;i++){
			//cout<<TrajectoryError[i]<<endl;
			AvgTrajectoryError+=TrajectoryError[i]/1932.0;
			AvgDockingError+=DockingError[i]/1932.0;
		}
		printf("AvgTrajectoryError=%.3lf\n",AvgTrajectoryError);	
		printf("AvgDockingError=%.3lf\n",AvgDockingError);		
	}
	else{
		
		float carx,cary,carphi;
		
		printf("input car located(x y phi)\n");
		scanf("%f %f %f",&carx,&cary,&carphi);
		cout<<endl;
		
		float orix=carx,oriy=cary,oriphi=carphi;
		int epoch=0;
		char* map;
		map=initial();
		while((carx>=0 && carx<=100)&&(cary>=0 && cary<=100)){
			
			carphi=calphi(carx,carphi);
			carx=carx+R*cos((carphi)/180*PI);
			cary=cary+R*sin((carphi)/180*PI);
			*(map+YL*int(carx)+int(cary))='*';
			printf("%f , %f, %f \n",carx,cary,carphi);
			
			epoch++;
		}
		printf("\nTrajectory error=%.3lf\n",epoch/sqrt(pow(orix-50,2)+pow((oriy-100),2)));
		printf("Docking error =%.3lf\n",sqrt(pow(((carphi-90)/180),2)+pow(((carx-50)/50),2)+pow(((cary-100)/100),2)));
		showImg(map);	
	}

	system("PAUSE");
	return 0;
	}

char* initial()
{
	static char m[XL][YL];	
	char* mp[XL];	
	for(int x=0;x<XL;x++){
		mp[x]=m[x]; 
		for(int y=0;y<YL;y++){ 
			m[x][y]=' ';	
		}	
	}
	return &m[0][0];
}



float calphi(float carx,float carphi){
	int xamo=int(sizeof(c.x)/sizeof(c.x[0]));
	int phiamo=int(sizeof(c.phi)/sizeof(c.phi[0]));
	int thedaamo=int(sizeof(c.theda)/sizeof(c.theda[0]));
	
	bool xready[5]={0,0,0,0,0};
	for(int i=0;i<xamo;i++){
		if(carx>c.x[i][0] && carx<c.x[i][2]){
			xready[i]=1;
		}		
	}
	
	bool phiready[7]={0,0,0,0,0,0,0};
	for(int j=0;j<phiamo;j++){
		if(carphi>c.phi[j][0] && carphi<c.phi[j][2]){
			phiready[j]=1;
		}		
	}
	
	//-30~+30 degree
	static float deg[61];
	float degstd;
	for(int d=-30;d<=30;d++)
		deg[d]=0;			
	//min and max
	float min=0,xweight,phiweight,weight;
	int thetaindex;
	for(int i=0;i<xamo;i++){
		for(int j=0;j<phiamo;j++){
			if(xready[i] && phiready[j]){
				if(carx>=c.x[i][1])
					xweight=1*(c.x[i][2]-carx)/(c.x[i][2]-c.x[i][1]);
				else
					xweight=1*(carx-c.x[i][0])/(c.x[i][1]-c.x[i][0]);

				if(carphi>=c.phi[j][1])
					phiweight=1*(c.phi[j][2]-carphi)/(c.phi[j][2]-c.phi[j][1]);
				else
					phiweight=1*(carphi-c.phi[j][0])/(c.phi[j][1]-c.phi[j][0]);

				if(xweight>phiweight)//smallest
					weight=phiweight;
				else
					weight=xweight;
				
				//---------------theta calculating-----------------
				thetaindex=c.mat[j][i];
				//printf("running %d\n",thetaindex);

				for(int d=c.theda[thetaindex][0]+1;d<=c.theda[thetaindex][2]-1;d++){
					if(d<-30)
						d=-30;
					if(d>30)
						break;
					if(d<=c.theda[thetaindex][1])
						degstd=1.0*(d-c.theda[thetaindex][0])/(c.theda[thetaindex][1]-c.theda[thetaindex][0]);
					else
						degstd=1.0*(c.theda[thetaindex][2]-d)/(c.theda[thetaindex][2]-c.theda[thetaindex][1]);
					
					
					
					if(degstd>deg[d])
						if(degstd>weight)
							deg[d]=weight;
						else
							deg[d]=degstd;
					//printf("%.2f\n",deg[d]);	
					
				}
			
			}
		}
	}
	
	
	//------------fuzzy centroid output ---------------
	float mol=0,den=0;
	
	for(int d=-30;d<=30;d++){
		//printf("%d:\t%.3f\n",d,deg[d]); 
		mol+=(deg[d]*d);
		den+=deg[d];
	}
	//printf("deg=%f",mol/den);
	
	return carphi+mol/den;

}



void showImg(char* m){//Transpose display
	for(int i=0;i<100;i++) cout<<"_";
	cout<<endl;
	for(int x=0;x<XL;x++){
		cout<<"|";
			for(int y=0;y<YL;y++)
				printf("%c",*(m+y*XL+x));
		cout<<"|"<<endl;	
	}	
	for(int i=0;i<100;i++) cout<<"-";
	cout<<endl;
	for(int i=0;i<50;i++) cout<<" ";
	cout<<'X';	
	cout<<endl;
}




/*
void showImg(char* m){
	for(int i=0;i<100;i++) cout<<"_";
	cout<<endl;
	for(int x=0;x<XL;x++){
		cout<<"|";
			for(int y=0;y<YL;y++)
				printf("%c",*(m+x*YL+y));
		printf("|\n");	
	}	
	for(int i=0;i<100;i++) cout<<"-";
	cout<<endl;
}
*/
