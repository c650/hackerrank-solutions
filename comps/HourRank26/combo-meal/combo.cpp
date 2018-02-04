/*
	HourRank 26 upsolve
	Combo Meal.
	02/03/2018
*/
#include <bits/stdc++.h>

static void one_case(void) {
    int a,b,c;
    std::cin >>a>>b>>c;
    std::printf("%d\n", a+b-c);
}

int main() {
    int t;
    std::cin >>t;
    while(t--) one_case();
    return 0;
}
