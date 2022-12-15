#include "Conv.h"

void Conv::run() {
	// vvvvv put your code here vvvvv
 
  if(rst)
  {
  rom_rd=0;
  rom_addr=0;
  data_out=0;
  data_out_signal=0;
  state=0;
  }
  else
  {
  if(state<=19)
  {
  rom_rd.write(1);
  rom_addr=state;
  data_out=0;
  data_out_signal=0;
    if(state!=0)
    input[state-1]=data_in;
  state++;
  }
  else
  {
  rom_rd=0;
  rom_addr=0;

  data_out=input[0]*input[9]+input[1]*input[10]+input[2]*input[11]+input[3]*input[12]+input[4]*input[13]+input[5]*input[14]+input[6]*input[15]+input[7]*input[16]+input[8]*input[17]+input[18];
  
  data_out_signal.write(1);
  }
  
  }
  /*rom_rd=0;
  rom_addr=0;

  temp=input[0]*input[9]+input[1]*input[10]+input[2]*input[11]+input[3]*input[12]+input[4]*input[13]+input[5]*input[14]+input[6]*input[15]+input[7]*input[16]+input[8]*input[17];
  
  temp+=bias;
  data_out.write(temp);
  data_out_signal.write(1);*/
  
	// ^^^^^ put your code here ^^^^^
}


