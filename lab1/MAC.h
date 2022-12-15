#include "systemc.h"

SC_MODULE( Adder ) {
	sc_in < sc_uint<8> > in1,in2;
	sc_out < sc_uint<9> > out;
	
	void run() {
		// vvvvv put your code here vvvvv
		out.write(in1.read()+in2.read());
		// ^^^^^ put your code here ^^^^^
	}

	SC_CTOR( Adder ) {
		SC_METHOD( run );
		sensitive << in1 << in2;
	}

};

SC_MODULE( Multiplier ) {
	sc_in < sc_uint<4> > in1,in2;
	sc_out < sc_uint<8> > out;
	
	void run() {
		// vvvvv put your code here vvvvv
		out.write(in1.read()*in2.read());
		// ^^^^^ put your code here ^^^^^
	}

	SC_CTOR( Multiplier ) {
		SC_METHOD( run );
		sensitive << in1 << in2;
	}

};

SC_MODULE( MAC ) {
	sc_in < sc_uint<4> > In1, In2;
	sc_in < sc_uint<8> > In3;
	sc_out < sc_uint<9> > Out;
    
	Adder *ADD_1;
	Multiplier *MUL_1;
    
	// vvvvv put your code here vvvvv
   sc_signal< sc_uint<8> > s1;
	// ^^^^^ put your code here ^^^^^
		
	SC_CTOR( MAC )
	{
		// vvvvv put your code here vvvvv
   ADD_1=new Adder("Add");
   MUL_1=new Multiplier("Mul");
   MUL_1->in1(In1);
   MUL_1->in2(In2);	
   MUL_1->out(s1);
   ADD_1->in1(s1);
   ADD_1->in2(In3);	
   ADD_1->out(Out);
		// ^^^^^ put your code here ^^^^^
	}
};
