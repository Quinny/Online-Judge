#include <iostream>

/*

I solved this problem using a logical pen and paper approach rather than an algorithmic one.

The only solution I could think of as far as algorithms go was to generate all of the possible pandigital numbers
and check if they match the given criteria, which isnt very elegant.

I started by analyzing all of the requirements and seeing if I could come up with anything.

I saw that d4d5d6 must be divisible by 5, and any number divisible by 5 must end in either 5 or 0, so d6 must be either 5 or 0.
I then looked into the requirements for d6d7d8 to see if I could narrow d6 any further.  d6d7d8 must be divisible by 11, so if d6 was 0,
then the values for d7d8 must be 11, 22, 33, 44, etc., which violates our pandigital requirement.  So d6 MUST be 5.

Knowing that d6 is 5, I could then narrow the search for d7 and d8 by only considering multiples of 11 that were between
500 and 600, and did not contain repeating digits (to keep the number pandigital)

This narrowed down the possible values for d6d7d8 to [506, 517, 528, 539, 561, 572, 583, 594]

I then looked at d5d6d7, which must be divisible by 7.  I knew that d6 was 5 and that I had possible values for d7 (from the above
observations) so the values for d5d6d7 could be narrowed down to 3 digit multiples of seven with the middle digit being 5, and the 
last digit coming from the set [0, 1, 2, 3, 6, 7, 8, 9] (taken from the possible values above).  I then had a list of possible
values of d5d6d7 [756, 357, 658, 259, 651, 952]

I could then combine these results and obtain a list of possible values for d5d6d7d8
[7561, 3572, 6583, 2594, 6517, 9528]

Now looking at d7d8d9, it must be divisible by 13.
we have possible values for d7 and d8, so we only need to find 3 digit multiples of 13 which have the first 2 digits being
from the set [61, 72, 83, 94, 17, 28]
We can then say that the possible values for d7d8d9 are [728, 832, 286]

We can now intersect these results with the results for d5d6d7d8 to obtain possible values for d5d6d7d8d9 and we get
[35728, 65832, 95286]

Now looking at d8d9d10, we see it must be divisble by 17.  so we must find all the 3 digit multiples of 17 which have the first 2
digits belonging to the set of possisble values for d8d9 [28, 32, 86]
and we get [289, 867]

Now we can intersect these and get the possible values for d5d6d7d8d9d10
[357289, 952867]

d2d3d4 must be divisible by 2, so that means d4 must be disible by 2.  This means d4 must belong to [0, 2, 4, 8]
We can narrow this down, because the number must remain pandigital.  In the first possiblility from above, 2 and 8 are already present,
so d4 can only be [0, 4, 6].  In the second possibility 2, 6, and 8 are present, so d4 can only be [0,4]
so we have d4d5d6d7d8d9 can be:
[[0, 4, 6]357289, [0, 4]952867]

d3d4d5 must be divisble by 3.  we know d5 must be [3, 9] and d4 [0,4,6] OR [0,4], so we will again have 2 different cases
Case 1:
d3d4 [60,06]

Case 2:
d3d4[09]

Then finding d1 is trivial.  None of the other cases have 1's, so we can put it there.  Using all this information, we obtain the 
6 possible combinations:

1460357289
1406357289
4106357289
4160357289
1430952867
4130952867

*/

int main(void){
	unsigned long long a[] = {1460357289, 1406357289, 4106357289, 4160357289, 1430952867, 4130952867};
	unsigned long long ans = 0;
	for(auto x: a)
		ans += x;
	std::cout << ans << std::endl;
	return 0;
}