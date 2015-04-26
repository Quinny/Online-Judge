#include <iostream>
#include <set>
#include <stack>
#include <vector>

// Ok so...
// Instead of having to deal with brackets and order of operation issues
// explicitly, I decided to try my hand at using reverse polish notation (RPN)
// to handle all of that for me.  It may have ended up making it more
// complicated, but I learned a fair deal about RPN and how it works
// so I'm happy with it

// Constant to recognize bad divisions
const int BAD_DIVIDE = -999;

enum class rpn_type { op, val };

// Struct for RPN items
// An RPN item can either be an operation, denoted by a binary function pointer
// or a value denoted by an integer
struct rpn_item {
    rpn_type type;
    int v;
    int (*op)(const int, const int) = nullptr;
    rpn_item(int x) : type(rpn_type::val), v(x) {};
    rpn_item(int(*o)(const int, const int)) : type(rpn_type::op), op(o) {};

    // Operators to make my life easier
    int operator() (int const x, int const y) const {
        return op(x, y);
    }

    int operator * () const {
        return v;
    }
};

// Function that takes a stack of rpn_items and evaluates the expression
int eval_rpn_stack(std::stack<rpn_item> s) {
    std::stack<int> ret;
    while (!s.empty()) {
        auto t = s.top();
        s.pop();
        if (t.type == rpn_type::val)
            ret.push(*t);
        else {
            auto arg1 = ret.top();
            ret.pop();
            auto arg2 = ret.top();
            ret.pop();
            auto check = t(arg1, arg2);
            // check for bad division
            if (check == BAD_DIVIDE)
                return BAD_DIVIDE;
            ret.push(check);
        }
    }
    return ret.top();
}

// Little helper function for the mess ahead...
std::stack<rpn_item> push_helper(std::stack<rpn_item> e, std::vector<rpn_item> v) {
    for (auto i : v)
        e.push(i);
    return e;
}

// I'm certain this function could be cleaned up, but it will require some
// serious brain storming, so it is a work in progress....
//
// The idea is I want to generate all possible permutations of RPN stacks given
// a set of 4 input integers.
void perms(std::set<int> possible, std::set<int>& all, std::stack<rpn_item> e, std::vector<rpn_item> const& ops) {
    // Once the stack is finished evaluate and add to the set
    if (e.size() == 7) {
        auto test = eval_rpn_stack(e);
        if (test > 0 && test != BAD_DIVIDE)
            all.insert(test);
        return;
    }

    // The very bottom of the stack MUST be an operator
    if (e.size() == 0) {
        for (auto i : ops) {
            auto tmp = e;
            tmp.push(i);
            perms(possible, all, tmp, ops);
        }
    }

    // the TOP 2 items in the stack MUST be integers
    if (e.size() >= 5) {
        for (auto i : possible) {
            auto tmp = possible;
            auto tmp_e = e;
            tmp.erase(i);
            tmp_e.push(i);
            perms(tmp, all, tmp_e, ops);
        }
    }

    // This is where things get messy...
    // I enumerate all possible stack configurations
    // There is no visible pattern that I can see and easily program so for now
    // this will remain a mess
    for (auto n1 = possible.begin(); n1 != possible.end(); ++n1) {
        for (auto n2 = std::next(n1); n2 != possible.end(); ++n2) {
            auto tmp_p = possible;
            tmp_p.erase(*n1); tmp_p.erase(*n2);
            for (auto op1 = ops.begin(); op1 != ops.end(); ++op1) {
                for (auto op2 = ops.begin(); op2 != ops.end(); ++op2) {
                    // op op n n
                    auto n = push_helper(e, {*op1, *op2, *n1, *n2});
                    perms(tmp_p, all, n, ops);
                    // op n op n
                    n = push_helper(e, {*op1, *n1, *op2, *n2});
                    perms(tmp_p, all, n, ops);
                    // n op n op
                    n = push_helper(e, {*n1, *op1, *n2, *op2});
                    perms(tmp_p, all, n, ops);
                    // op n n op
                    n = push_helper(e, {*op1, *n1, *n2, *op2});
                    perms(tmp_p, all, n, ops);
                    // n op op n
                    n = push_helper(e, {*n1, *op1, *op2, *n2});
                    perms(tmp_p, all, n, ops);
                }
            }
        }
    }
}

// Finds the longest consecutive run in a set
// starting at 1
int run_length(std::set<int> const& s) {
    auto first = s.begin();
    auto second = std::next(first);
    int len = 1;
    if (*first != 1)
        return len;
    while (second != s.end() && *(second++) == *(first++) + 1)
        ++len;
    return len;
}

int main() {
    rpn_item add([](const int x, const int y) { return x + y; });
    rpn_item sub([](const int x, const int y) { return x - y; });
    rpn_item mult([](const int x, const int y) { return x * y; });
    rpn_item div([](const int x, const int y) {
            if (y == 0 || x % y != 0)
                return BAD_DIVIDE;
            return x / y;
        }
    );
    std::vector<rpn_item> ops {add, sub, mult, div};
    int max = 0;
    std::set<int> best;

    for (int i = 1; i <= 9; ++i) {
        for (int j = i + 1; j <= 9; ++j) {
            for (int k = j + 1; k <= 9; ++k) {
                for (int l = k + 1; l <= 9; ++l) {
                    std::set<int> all;
                    std::set<int> poss{i, j, k, l};
                    std::stack<rpn_item> equ;
                    perms(poss, all, equ, ops);
                    auto test = run_length(all);
                    if (test >= max) {
                        max = test;
                        best = std::move(poss);
                    }
                }
            }
        }
    }

    std::cout << max << std::endl;
    for (auto i : best)
        std::cout << i;
    std::cout << std::endl;
    return 0;
}
