#include "Conv.h"

void Conv::run() {
	// vvvvv put your code here vvvvv
	if(rst) //all reset to zero
  {
  rom_rd=0;
  rom_addr=0;
  data_out=0;
  data_out_signal=0;
  state=0;
  }
  else
  {
    if(state<=101) //read input data 10*10
    {
    rom_rd.write(1);
    rom_addr=state;
    data_out.write(0);
    data_out_signal.write(0);
    if(state>=2)
    input[state-2]=data_in.read();
    state++;
    }
    else if(state>101&& state <111) //read kernel data (3*3)
    {
    rom_rd.write(1);
    rom_addr=state;
    data_out.write(0);
    data_out_signal.write(0);
    if(state>=102)
    weight[state-102]=data_in.read();
    state++;
    }
    else if(state==111) //read bias data
    {
    rom_rd.write(1);
    rom_addr=state;
    data_out.write(0);
    data_out_signal.write(0);
    bias=data_in;
    state++;
    }
    else 
    {
    rom_rd=0;
    rom_addr=0;
    int control=0;
    for(int j=0;j<64;j++) 
    {
    //do convolution operation
    control=(j/8)*10+(j%8);
    output[j]=(int)(input[control]*weight[0]+input[1+control]*weight[1]+input[2+control]*weight[2]+input[10+control]*weight[3]+input[11+control]*weight[4]+input[12+control]*weight[5]+input[20+control]*weight[6]+input[21+control]*weight[7]+input[22+control]*weight[8]+bias);
    //do ReLU function
    if(output[j]<0)
    output[j]=0;
  
    }
    
    if(index<64) //write output data
    data_out=output[index];
  
    index++;
    data_out_signal.write(1);
    state++;
   
    }
   }
	// ^^^^^ put your code here ^^^^^
 
}



