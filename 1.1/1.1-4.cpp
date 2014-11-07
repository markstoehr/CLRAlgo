#include <iostream>

using std::cout; using std::endl;

int char2int(char *);
int addInts(int,int);
int addIntsOnebit(int, int);

int main(int argc,char *argv[]) {
  if (argc != 3) 
    cout << "Usage: 1.1-4 [int] [int]" << endl;
  else {
    int a = char2int(argv[1]);
    int b = char2int(argv[2]);
    //int c = ;
    cout << a << " + " << b << " = " << addIntsOnebit(a,b) <<  endl;

  }

  return 0;
  
}

int addIntsOnebit(int a, int b) {
  int carry = 0, x = 0,y = 0,alsb=0,blsb=0;
  for (int i=0; i<31; i++) {
    x <<= 1 ;
    alsb = a % 2; blsb = b % 2;
    x |= carry ^ alsb ^ blsb;
    carry = (carry & (alsb | alsb)) | (alsb & blsb);
    a >>= 1; b >>= 1;
  }

  for (int i=0; i< 31; i++) {
    y <<= 1;
    y = y | (x % 2);
    x >>= 1;
      
  }
  return y;
}

int addInts(int a,int b) {
  int carry = (a & b) << 1;
  int sum = (a ^ b);
  if (sum & carry)
    return addInts(sum, carry);
  else
    return sum ^ carry;
}

int char2int(char *s) {
   int x = 0;
for (char* sptr = s; *sptr != '\0'; sptr++) {
x = 10*x +  *sptr - '0';
}
return x;
}
