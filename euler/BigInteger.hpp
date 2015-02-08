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
		BigInteger(std::string const& s) : value_(s) {};
		BigInteger(const unsigned long long n) : value_(std::to_string(n)) {}; 	// Keep the value as long long to prevent narrowing
		BigInteger() : value_("0") {};											// Default 0 value

		/*-------------------------------
		 * Utility
		 *-------------------------------*/
		int length() const { return value_.length(); }
		int size() const { return length(); }
		bool palindrome() const;					// This is not really nessesary, but its nice for euler questions
		BigInteger reverse() const;

		/*-------------------------------
		 * Conversions
		 *-------------------------------*/
		std::string to_string() const { return value_; }

		/*-------------------------------
		 * Iterators
		 *-------------------------------*/
		 std::string::iterator begin() { return value_.begin(); }
		 std::string::iterator end() { return value_.end(); }

	private:
		//addition functions
		BigInteger add(BigInteger);
		BigInteger add(std::string);
		BigInteger add(const unsigned long long);			// Again, prevent narrowing

		//multiplication functions
		BigInteger multiply(BigInteger);
		BigInteger multiply(std::string);
		BigInteger multiply(const unsigned long long);

		BigInteger small_mult(std::string, char) const;

		bool equals(std::string const&) const;
		bool equals(BigInteger const&) const;


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

		int operator [] (int i) const { return value_[i] - '0'; }

		template<typename compare_type>
		bool operator == (compare_type const& x) const { return equals(x); }
		template<typename compare_type>
		bool operator != (compare_type const& x) const { return !equals(x); }

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
	sum.reserve(length());
	for(int i = length()-1; i >= 0; i--){
		int val = (value_[i] - '0') + (s[i] - '0') + carry;		// Add the numbers digit by digit
		sum = std::to_string(val % 10) + sum;					// Just like grade school
		carry = val/10;
	}
	if(carry) sum = "1" + sum;									// If there is a left over carry then add it
	return BigInteger(sum);
}

BigInteger BigInteger::add(BigInteger b){
	return add(b.to_string());
}

BigInteger BigInteger::add(unsigned long long const n){
	return add(std::to_string(n));
}



/*-------------------------------
 * Multiplication
 *-------------------------------*/

BigInteger BigInteger::small_mult(std::string top, char bottom) const {
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
		BigInteger prod = small_mult(value_,s[i]);
		for(int j = 0; j < s.length() - i - 1; j++)
			prod.value_ = prod.value_ + "0";
		sum += prod;
	}
	return sum;
}

BigInteger BigInteger::multiply(BigInteger b){
	return multiply(b.value_);
}

BigInteger BigInteger::multiply(const unsigned long long x){
	return multiply(std::to_string(x));
}

/*-------------------------------
 * Operators
 *-------------------------------*/

bool BigInteger::equals(std::string const& s) const {
	return value_ == s;
}

bool BigInteger::equals(BigInteger const& b) const {
	return equals(b.value_);
}

/*-------------------------------
 * Utility
 *-------------------------------*/

bool BigInteger::palindrome() const {
	int len = length();
	for(int i = 0; i < len/2; i++){
		if(value_[i] != value_[len - i - 1]) return false;
	}
	return true;
}

BigInteger BigInteger::reverse() const {
	std::string tmp = value_;
	std::reverse(tmp.begin(),tmp.end());
	return BigInteger(tmp);
}

std::ostream& operator<< (std::ostream &out, BigInteger &x){
	out << x.to_string();
    return out;
}

std::istream& operator>> std::(istream &in, BigInteger &x){
    std::string s;
    in >> s;
    BigInteger y(s);
    if(in)
        x = std::move(y);
    return in;
}

//ifndef QP_BIG_INT_H__
#endif
