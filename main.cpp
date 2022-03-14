#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n = 3;
    int operation;
    int choice;
    
    // original matrix
    int m[3][3] = {{8,7,4},
                   {2,5,6},
                   {1,9,3}};
    
    // temp matrix for operations
    int t[3][3];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            t[i][j] = m[i][j];
    
    // main program
    while(1)
    {
        cout << "Your matrix:" << endl;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout << t[i][j]<<",";
            cout << endl;
        }
        
        cout << endl;

        cout << "Please select operation:" << endl;
        cout << "(1) Transpose" << endl;
        cout << "(2) Determinant" << endl;
        cout << "(3) L1 norm" << endl;
        cout << "(4) L∞ norm" << endl;
        
        cin >> operation;
        
        
        if(operation == 1)
        {
            
            // transpose
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if(j<i)
                        swap(t[i][j],t[j][i]);
            
            cout << "Your new matrix:" << endl;
            
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                    cout << t[i][j]<<",";
                cout << endl;
            }
            cout << endl;
        }
        
        // Determinant
        if(operation == 2)
        {
            // solid lines
            int a, positive, c, d;
            int temp = 0;
            
            // solid lines
            a = 1;
            positive = 0;
            c = 0;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    d = j + c;
                    if(d >= n)
                        d = d - n;
                    
                    a = a * t[j][d];
                }
                positive = positive + a;
                a = 1;
                c++;
            }
            
            // dashed lines
            int negative;
            temp = 0;
            a = 1;
            negative = 0;
            
            // dashed lines
            for(int i=0; i<n; i++)
            {
                c = i+n-1;
                for(int j=0; j<n; j++)
                {
                    if(c >= n)
                        c = c - n;
                    if(c < 0)
                        c = c + n;
                    
                    a = a * t[j][c];
                    c--;
                }
                negative = negative + a;
                a = 1;
            }
            
            int determinant = positive - negative;
            cout << "Determinant: " << determinant << endl << endl;
        }
        
        // L1 norm
        if(operation == 3)
        {
            
            // L1 norm
            int L1 = 0;
            int L1_temp = 0;
            for(int j=0; j<n; j++)
            {
                for(int i=0; i<n; i++)
                    L1_temp = L1_temp + abs(t[i][j]);
                
                if(L1_temp > L1)
                    L1 = L1_temp;
                
                L1_temp = 0;
            }
            cout << "L1 norm: " << L1 << endl << endl;
        }
        
        // L∞ norm
        if(operation == 4)
        {
            // L∞ norm
            int Linf = 0;
            int Linf_temp = 0;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                    Linf_temp = Linf_temp + abs(t[i][j]);
                
                if(Linf_temp > Linf)
                    Linf = Linf_temp;
                
                Linf_temp = 0;
            }
            
            cout << "L∞ norm: " << Linf << endl << endl;
        }
        
        cout << "Do you want to continue operate with:" <<endl;
        cout << "(1) the new matrix" << endl;
        cout << "(2) the original matrix" << endl;
        cout << "(3) End program" << endl;
        
        cin >> choice;
        
        if(choice == 1)
        {
            // do nothing
        }
        
        if(choice == 2)
        {
            // replace the temp bacr to the original
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    t[i][j] = m[i][j];
        }
        
        cout << "========================================" << endl;
        
        if(choice == 3)
            return 0;
        
    }
    return 0;
}
