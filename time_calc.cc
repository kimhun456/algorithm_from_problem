#include <iostream>
#include <time.h>
 
using namespace std;
 
int main()
{
    clock_t begin, end;
    begin = clock();        // 시간설정
 
    /************************************************************************/
    /*                              측정 코드                               */
    /************************************************************************/
 
    
    end = clock();          // 시간설정
    cout<<"수행시간 : "<<(double)((end-begin)/(double)CLOCKS_PER_SEC)<<endl;
 
    return 0;
}