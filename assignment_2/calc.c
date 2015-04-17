#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add(struct DynArr *stack)
{
    TYPE tmp, sum;
    
    assert(sizeDynArr(stack) >= 2);
	
    tmp = topDynArr(stack);
	popDynArr(stack);
	sum = (topDynArr(stack) + tmp);
	popDynArr(stack);
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
    TYPE tmp, dif;
    
    assert(sizeDynArr(stack) >= 2);
    
    tmp = topDynArr(stack);
	popDynArr(stack);
	dif = (topDynArr(stack) - tmp);
	popDynArr(stack);
	pushDynArr(stack, dif);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
    TYPE tmp, quo;
    
    assert(sizeDynArr(stack) >= 2);
    
    tmp = topDynArr(stack);
	popDynArr(stack);
	quo = (topDynArr(stack) / tmp);
	popDynArr(stack);
	pushDynArr(stack, quo);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their product is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
	TYPE tmp, prod;
    
    assert(sizeDynArr(stack) >= 2);
	
    tmp = topDynArr(stack);
	popDynArr(stack);
	prod = (topDynArr(stack) * tmp);
	popDynArr(stack);
	pushDynArr(stack, prod);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their power is pushed back onto the stack.
*/
void power(struct DynArr *stack)
{
	TYPE tmp, pwr;
    
    assert(sizeDynArr(stack) >= 2);
    
    tmp = topDynArr(stack);
	popDynArr(stack);
	pwr = pow(topDynArr(stack), tmp);
	popDynArr(stack);
	pushDynArr(stack, pwr);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and 
	it's square is pushed back onto the stack.
*/
void square(struct DynArr *stack)
{
    TYPE base;
    
    assert(sizeDynArr(stack) >= 1);
    
    base = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, pow(base, 2));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and 
	it's cube is pushed back onto the stack.
*/
void cube(struct DynArr *stack)
{
    TYPE base;
    
    assert(sizeDynArr(stack) >= 1);
    
    base = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, pow(base, 3));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and 
	it's absolute value is pushed back onto the stack.
*/
void absolute(struct DynArr *stack)
{
    TYPE val;
    
	assert(sizeDynArr(stack) >= 1);
	
    val = topDynArr(stack);
	popDynArr(stack);
    pushDynArr(stack, fabs(val));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and 
	it's square root is pushed back onto the stack.
*/
void root(struct DynArr *stack)
{
    TYPE rad;
    
	assert(sizeDynArr(stack) >= 1);
    
	rad = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, sqrt(rad));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element x is popped and 
	e^x is pushed back onto the stack.
*/
void exponent(struct DynArr *stack)
{
    TYPE pwr;
    
	assert(sizeDynArr(stack) >= 1);
	
    pwr = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, exp(pwr));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and 
	it's ln is pushed back onto the stack.
*/
void ln(struct DynArr *stack)
{
    TYPE of;
    
	assert(sizeDynArr(stack) >= 1);
	
    of = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, log(of));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and 
	it's ln is pushed back onto the stack.
*/
void logten(struct DynArr *stack)
{
    TYPE of;
    
	assert(sizeDynArr(stack) >= 1);
	
    of = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, log10(of));
}
double calculate(int numInputTokens, char **inputString)
{
	int i;
	double num, result = 0.0;

	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
			square(stack);
		else if(strcmp(s, "^3") == 0)
			cube(stack);
		else if(strcmp(s, "abs") == 0)
			absolute(stack);
		else if(strcmp(s, "sqrt") == 0)
			root(stack);
		else if(strcmp(s, "exp") == 0)
			exponent(stack);
		else if(strcmp(s, "ln") == 0)
			ln(stack);
		else if(strcmp(s, "log") == 0)
			logten(stack);
		else 
		{
			
			if (isNumber(s, &num))
            {
				pushDynArr(stack, num);
			}
            else if (strcmp(s, "pi") == 0)
            {
				pushDynArr(stack, M_PI);
			}
            else if (strcmp(s, "e") == 0)
            {
				pushDynArr(stack, M_E);
			}
		}
	}	//end for 

	if (sizeDynArr(stack)!=1)
    {
		printf("Invalid expression. Ignore result.\n");
	}
    else
    {
		result = topDynArr(stack);
	}
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	printf("The result is: %f\n", calculate(argc,argv));
	return 0;
}
