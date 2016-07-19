#include<iostream>
using namespace std;

void printEdge(int m[4][4],int tR,int tC,int dR,int dC);
int main()
{
	int matrix[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int tR=0;
	int tC=0;
	int dR=3;
	int dC=3;
	while(tR<=dR &&  tC<=dC)
		printEdge(matrix,tR++,tC++,dR--,dC--);
}

void printEdge(int m[4][4],int tR,int tC,int dR,int dC)
{
	int i;
	if(tR==dR){//只有一行
		for(i=tC;i<=dC;i++){
			cout<<m[tR][i]<<" ";
		}
	}else if(tC==dC){//只有一列
		for(i=tR;i<=dR;i++){
			cout<<m[i][tC]<<" ";
		}
	}else{//一般情况
		int curC = tC;
		int curR = tR;
		while(curC != dC){
			cout<<m[tR][curC]<<" ";
			curC++;
		}
		while(curR != dR){
			cout<<m[curR][dC]<<" ";
			curR++;
		}
		while(curC != tC){
			cout<<m[dR][curC]<<" ";
			curC--;
		}
		while(curR != tR){
			cout<<m[curR][tC]<<" ";
			curR--;
		}
	}

}
