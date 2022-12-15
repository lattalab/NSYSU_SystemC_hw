#include "Neuron.h"

void Neuron::neuron() {
 
	// vvvvv put your code here vvvvv
	output_temp=w1*input1+w2*input2+b;
  y=0.5+ 0.25*output_temp - output_temp*output_temp*output_temp/48 + output_temp*output_temp*output_temp*output_temp*output_temp/480;
  if(y>0.5)
  output.write(1);
  else
  output.write(0);
 
   //my original idea:
  /*if(output_temp<=0)
  y=0;
  else
  y=1;
  output.write(y);*/
	// ^^^^^ put your code here ^^^^^
}