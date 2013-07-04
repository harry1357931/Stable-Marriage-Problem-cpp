Stable-Marriage-Problem-cpp
===========================

This repository contains program which matches men and women based on their preferences.

Stable Marriage Using Backtracking
==================================
The Problem:
===========
You have n men and n woman, and their preference rankings of each other, and you need to match them up so that 
the total matching is “stable.”

<b>The preference rankings:</b>
You are given 2 n X n arrays, mp (men’s preference) which gives the men’s ranking of the women, 
and wp (women’s preference) which gives the women’s ranking of the men.
So mp[i][j] gives man i's ranking of woman j and likewise for the women’s ranking of the men in wp.
For example in the following tables we have n=3 and the women and men are “named” 0, 1 or 2 and the raking are 
in the range 0 = highest, 1 second highest and 2 lowest.
<b>
int mp[3][3]={0,2,1,
0,2,1,
1,2,0};
int wp[3][3]={2,1,0,
0,1,2,
2,0,1};
</b>
So man 1 assigns woman 2 the rank of 1 (i.e. second highest) and prefers woman 0 the best.
What is a <b>stable matching</b>?
A matching is stable if there are no “instabilities.” Say the match assigns m1 to w1 and m2 to w2. An instability 
is the situation where there is a mutual greater preference for the other person’s partner than for one’s own. 
For example m1 would prefer w2 to w1 and likewise w2 prefers m1 to m2.
<b>How to do it:</b>
Use the same approach that we used for the one dimensional eight queens problem. In the array q, q[i] is the woman 
assigned to man i. The main program stays the same, besides the limits on the loops. All that needs to change is the 
ok function. Is could look something like this:

<b>bool ok(int q[], int col)</b> {
          col indicates the new man and q[col] the new woman proposed to be added to the match.
We need to do 2 tests:
    1. If the new woman has already been assigned to some man then return false
    2. Check the new pair (new man, new woman) against each existing pair consisting of (current man, current woman) to see if the new pair would make the match unstable. So
        a. if the current man prefers the new woman to his partner and
        b. if the new woman prefers the current man to her partner
                  i. this is unstable, so return false
        c. if the new man prefers the current woman to his partner and
        d. if the current woman prefers the new man to her partner
                  i. This is unstable, so return false
        e. if there are no instabilities introduced with any of the existing (i.e. “current”) couples, so we return true.
}
