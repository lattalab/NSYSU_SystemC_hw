# SystemC LAB and Homework
* LAB1: Design a multiply accumulate unit (MAC) -> check MAC.h
* LAB2: Design a convolution operation unit (Conv.cpp and Conv.h)
  * Rom is used to store input data (index:0-8) and weight (index:9-18)
<img width="621" height="479" alt="image" src="https://github.com/user-attachments/assets/09dc5388-20ff-4439-927b-6405ac4afd87" />

* HW1: Design a XOR in neural network view. (Neural.cpp and Neural.h)  
  * After calculating the weighted sum, the neuron will pass to the activation function $sigmoid(x) = 1 +  \frac{1}{4}x - \frac{1}{48}x^3 + \frac{1}{480}x^5$
  * If the result of the sigmoid function is greater than 0.5, the output result is 1; otherwise, it is 0.
* HW2: Similar to LAB2, Doing convolution but with ReLU function. (Conv.cpp and Conv.h)
  * The size of ROM is 110(10x10 input data and 10 weight data) -> first 100 elements are input data while last 10 elements are weight.
