#include <iostream>

using namespace std;

//Used to calculate the majority value in each register's majoritB indeA
int majority(int LFSR1, int LFSR2, int LFSR3){
        int m;
        if(LFSR1 == 0){
                if(LFSR2 == 0 || LFSR3 == 0)
                    m = 0;
                else
                    m = 1;                
        }else{
                if(LFSR2 == 1 || LFSR3 == 1)
                    m = 1;
                else
                    m = 0;
        }
        return m;
}

int main(){

    const int n1 = 19, n2 = 22, n3 = 23;                          //Sizes of LFSR's

    int A[n1] = {1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};          //LFSR1
    int B[n2] = {0,1,0,1,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,1};    //LFSR2
    int C[n3] = {1,0,1,1,0,1,0,0,1,0,1,1,1,0,1,1,0,0,1,1,0,0,0};  //LFSR3
    int keystream[2000000];                                          //Keystream array
    freopen( "Keystream.txt", "w", stdout );

    int k = 0,m;

    for(int i = 0; i < 2000001; i++){
        m  = majority(A[8], B[10], C[10]);                 // Clocking bits: (8,10,10)

        if(A[8] == m){
            int t = A[13] ^ A[16] ^ A[17] ^ A[18];
            for(int j = n1-1 ; j >= 0; j--){
                if(j == 0)
                    A[j] = t;
                else
                    A[j] = A[j-1];
            } 
        }

        if(B[10] == m){
            int t = B[20] ^ B[21];
            for(int j = n2-1 ; j >= 0; j--){
                if(j == 0)
                    B[j] = t;
                else
                    B[j] = B[j-1];
            }

        }


        if(C[10] == m){
            int t = C[7] ^ C[20] ^ C[21] ^ C[22];
            for(int j = n3-1 ; j >= 0; j--){
                if(j == 0)
                    C[j] = t;
                else
                    C[j] = C[j-1];
            }
        }

		
		if(i < 2000000){
            int key = A[n1-1] ^ B[n2-1] ^ C[n3-1];        // Key = A[n1-1] XOR B[n2-1] XOR C[n3-1]
            keystream[k++] = key;   
		}
    }

    cout<<endl;
    for(int i=0;i<2000000;i++)
        cout<<keystream[i]<<" ";
    cout<<endl;

    return 0;
}