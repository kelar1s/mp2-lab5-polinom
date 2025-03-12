#include "../Polinom/Monom.h"
#include "../Polinom/Polinom.h"
#include "../Polinom/Monom.cpp"
#include "../Polinom/Polinom.cpp"
#include "gtest.h"

TEST(Polinom, Polinom_assign_works_correct) {
	Monom m1[3] = { Monom(5, 1, 2, 3), Monom(10, 4, 5, 6), Monom(15, 7, 8, 9) };
	Monom m2[2] = { Monom(20, 3, 6, 9), Monom(25, 4, 8, 12) };
	Polinom p1(m1, 3), p2(m2, 2);
	ASSERT_NO_THROW(p1 = p2);
	EXPECT_EQ(p1, p2);
	EXPECT_EQ(p1, p1);
}

TEST(Polinom, Add_monome_to_polinom_works_correct) {
	Monom m1[3] = { Monom(5, 1, 2, 3), Monom(10, 4, 5, 6), Monom(15, 7, 8, 9) };
	Monom m2[2] = { Monom(5, 1, 2, 3), Monom(10, 4, 5, 6) };
	Monom NEGATIVE(-15, 7, 8, 9);
	Polinom p1(m1, 3), p2(m2, 2);
	p1.AddMonom(NEGATIVE);
	EXPECT_EQ(p1, p2);
}