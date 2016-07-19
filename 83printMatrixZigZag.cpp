#include<iostream>
using namespace std;

void printLevel(int m[3][4],int tR,int tC,int dR,int dC,bool f);
int main()
{
	int matrix[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int tR=0;
	int tC=0;
	int dR=0;
	int dC=0;
	int endR = 2;//Rowlength-1
	int endC = 3;
	bool fromUp = false;
	while(tR != endR+1){
		printLevel(matrix,tR,tC,dR,dC,fromUp);
		tR = tC==endC ? tR+1 : tR; //change position
		tC = tC==endC ? tC : tC+1;
		dC = dR==endR ? dC+1 : dC;
		dR = dR==endR ? dR : dR+1;
		fromUp = !fromUp;
	}
	cout<<endl;
}

void printLevel(int m[3][4],int tR,int tC,int dR,int dC,bool f)
{
	if(f){//righttop to leftbottom
		while(tR != dR+1){
			cout<<m[tR++][tC--]<<" ";
		}
	}else{
		while(dR != tR-1){
			cout<<m[dR--][dC++]<<" ";
		}
	}

}
