#include <iostream>
#include <fstream>
using namespace std;
int main()
{
   ofstream outFile("my.out",ios::out);//ofstream输出流 fstream执行输入输出的流 ifstream输入流
   if(!outFile) {
      cerr<<"cannot open my.out"<<endl;
   }
   int n = 0;
   float f = 30.2;
   outFile<<"n:"<<n<<endl;
   outFile<<"f:"<<f<<endl;
   if(1) {
      return OVERFLOW;
   }
}
