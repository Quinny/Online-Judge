/*

Quinn Perfetto

Just a quick and dirty class to handle positive integers of arbitrary length.
The need for this class came to me when doing problems on project euler.  There are numerous quesitons
which require integers larger than the built-in types can handle.

Initially I just wrote functions to add strings together, but thats not as clean as making a class.
I realize that there are third party libraries available for this, but I wanted to make my own.

*/
#ifndef QP_BIG_INT_H__
#define QP_BIG_INT_H__

#include <string>

class BigInteger{
	private:
		std::string value_; //the string to store the digits

	public:

		/*-------------------------------
		 * Constructors
		 *-------------------------------*/
		BigInteger(std::string s) : value_(s) {};
		BigInteger(long long n) : value_(std::to_string(n)) {}; 			// Keep the value as long long to prevent narrowing
		BigInteger() : value_("0") {};										// Default 0 value

		/*-------------------------------
		 * Utility
		 *-------------------------------*/
		int length(){ return value_.length(); }

		/*-------------------------------
		 * Conversions
		 *-------------------------------*/
		std::string toString(){ return value_; }

		/*-------------------------------
		 * Iterators
		 *-------------------------------*/
		 std::string::iterator begin(){ return value_.begin(); }
		 std::string::iterator end(){ return value_.end(); }

	private:
		//addition functions
		BigInteger add(BigInteger);
		BigInteger add(std::string);
		BigInteger add(long long);					// Again, prevent narrowing

		//multiplication functions
		BigInteger multiply(BigInteger);
		BigInteger multiply(std::string);
		BigInteger multiply(long long);

		BigInteger oneDigMult(std::string, char);


	public:
		/*-------------------------------
		 * Operators
		 *-------------------------------*/
		template <typename add_type>						// Cover all add functions in 1 go
		BigInteger operator + (add_type x){ return add(x); }
		template <typename add_type>
		void operator += (add_type x){ value_ = add(x).value_; }

		template <typename mult_type>
		BigInteger operator * (mult_type x){ return multiply(x); }
		template <typename mult_type>
		void operator *= (mult_type x){ value_ = multiply(x).value_; }

		char operator [] (int i){ return value_[i]; }

};

/*-------------------------------
 * Addition
 *-------------------------------*/

BigInteger BigInteger::add(std::string s){
	if(length() > s.length()){ 				// Make sure that the numbers are the same length
		int dif = length() - s.length();	// if they are not, pad either one with zeros
		for(int i = 0; i < dif; i++)
			s = "0" + s;
	}
	if(s.length() > length()){
		int dif = s.length() - length();
		for(int i = 0; i < dif; i++)
			value_ = "0" + value_;
	}

	int carry = 0;
	std::string sum = "";
	for(int i = length()-1; i >= 0; i--){
		int val = (value_[i] - '0') + (s[i] - '0') + carry;		// Add the numbers digit by digit
		sum = std::to_string(val%10) + sum;						// Just like grade school
		carry = val/10;
	}
	if(carry) sum = "1" + sum;									// If there is a left over carry then add it
	return BigInteger(sum);
}

BigInteger BigInteger::add(BigInteger b){
	return add(b.toString());
}

BigInteger BigInteger::add(long long n){
	return add(std::to_string(n));
}



/*-------------------------------
 * Multiplication
 *-------------------------------*/

BigInteger BigInteger::oneDigMult(std::string top, char bottom){
	int dig = bottom - '0';
	int carry = 0;
	std::string prod = "";
	for(int i = top.length() - 1; i >= 0; i--){
		int val = dig * (top[i] - '0') + carry;
		prod = std::to_string(val%10) + prod;
		carry = val/10;
	}
	if(carry) prod = std::to_string(carry) + prod;
	return BigInteger(prod);
}

BigInteger BigInteger::multiply(std::string s){
	BigInteger sum;
	for(int i = s.length() - 1; i >= 0; i--){
		BigInteger prod = oneDigMult(value_,s[i]);
		for(int j = 0; j < s.length() - i - 1; j++)
			prod.value_ = prod.value_ + "0";
		sum += prod;
	}
	return sum;
}

BigInteger BigInteger::multiply(BigInteger b){
	return multiply(b.value_);
}

BigInteger BigInteger::multiply(long long x){
	return multiply(std::to_string(x));
}


//ifndef QP_BIG_INT_H__
#endif