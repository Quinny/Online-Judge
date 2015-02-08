#include <iostream>
#include <algorithm>

struct Card {
    int val_;
    char suit_;
    Card(): val_(0), suit_(0) {};
    Card(char v, char s) : suit_(s){
        if(v >= 2 && v <= 9)
            val_ = v;
        if(v == 'T')
            val_ = 10;
        if(v == 'J')
            val_ = 11;
        if(v == 'Q')
            val_ = 12;
        if(v == 'K')
            val_ = 13;
        if(v == 'A')
            val_ = 14;
    }
    bool operator < (Card c) const { return val_ < c.val_; } // for stable sort
};

struct Hand {
    Card h_[5];
    int n_ = 0;

    Hand(){};
    void add_card(char v, char s){ // adds card to hand
        h_[n_] = Card(v, s);
        n_++;
        if(n_ == 5) std::stable_sort(h_, h_ + n_);
    }

    bool all_same_suit(){ // returns true if all cards are of same suit
        char f = h_[0].suit_;
        for(int i = 1; i < 5; i++){
            if(h_[i].suit_ != f) return false;
        }
        return true;
    }

    int s_flush(){ // returns -1 if no flush, and the starting card if flush
        if(!all_same_suit()) return -1;
        int f = h_[0].val_;
        for(int i = 1; i < 5; i++){
            if(f + i != h_[i].val_) return -1;
        }
        return f;
    }

    int four_kind(){
        if (h_[0].val_ == h_[1].val_ == h_[2].val_ == h_[3].val_)
            return h_[0].val_;
        if(h_[1].val_ == h_[2].val_ == h_[3].val_ == h_[4].val_)
            return h_[1].val_;
        return -1;
    }

    int three_kind(){
        if (h_[0].val_ == h_[1].val_ == h_[2].val_)
            return h_[0].val_;
        if (h_[1].val_ == h_[2].val_ == h_[3].val_)
            return h_[1].val_;
        if(h_[2].val_ == h_[3].val_ == h_[4].val_)
            return h_[2].val_;
        return -1;
    }

    int one_pair(){
        for(int i = 0; i < 4; i++){
            if(h_[i].val_ == h_[i + 1].val_) return h_[i].val_;
        }
        return -1;
    }

    int full_house(){
        if ((h_[0].val_ == h_[1].val_ == h_[2].val_) && (h_[3].val_ == h_[4].val_))
            return h_[0].val_;
        if ((h_[0].val_ == h_[1].val_) && (h_[2].val_ == h_[3].val_ == h_[4].val_))
            return h_[2].val_;
        return -1;
    }

    bool flush(){
        return all_same_suit();
    }

    int high_card(){
        return h_[4].val_;
    }

    int two_pair(int c){
        int f = one_pair();
        if(f == -1) return false;
        for(int i = 0; i < 4; i++){
            if(h_[i].val_ == h_[i + 1].val_ && h_[i].val_ != f){
                if(c == 1)
                    return  h_[i].val_ > f ? h_[i].val_ : f;
                else
                    return h_[i].val_ > f ? f : h_[i].val_;
            }
        }
        return -1;
    }

    int straight(){
        int f = h_[0].val_;
        for(int i = 1; i < 5; i++){
            if(h_[i].val_ != f + i) return -1;
        }
        return f;
    }

    bool operator > (Hand h){
        if(s_flush() > h.s_flush())
            return true;
        if(four_kind() > h.four_kind())
            return true;
        if(full_house() > h.full_house())
            return true;
        if(flush() && !h.flush())
            return true;
        if(straight() > h.straight())
            return true;
        if(three_kind() > h.three_kind())
            return true;
        if(two_pair(1) > h.two_pair(1))
            return true;
        if(two_pair(2) > h.two_pair(2))
            return true;
        if(one_pair() > h.one_pair())
            return true;
        return high_card() > h.high_card();
    }

};

int main(){
    char val, suit;
    int ans = 0;
    for(int i = 0; i < 1000; i++){
        Hand p1;
        Hand p2;
        for(int j = 0; j < 5; j++){
            std::cin >> val;
            std::cin >> suit;
            p1.add_card(val, suit);
        }
        for(int j = 0; j < 5; j++){
            std::cin >> val;
            std::cin >> suit;
            p2.add_card(val, suit);
        }
        if(p1 > p2) ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}
