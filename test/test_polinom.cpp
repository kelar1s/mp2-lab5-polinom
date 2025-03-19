#include "../Polinom/Monom.h"
#include "../Polinom/Polinom.h"
#include "../Polinom/Monom.cpp"
#include "../Polinom/Polinom.cpp"
#include "gtest.h"

TEST(Polinom, Polinom_assign_works_correct) {
	Monom m1[3] = { Monom(15, 7, 8, 9), Monom(10, 4, 5, 6), Monom(5, 1, 2, 3)};
	Monom m2[2] = { Monom(25, 4, 8, 12), Monom(20, 3, 6, 9) };
	Polinom p1(m1, 3), p2(m2, 2);
	ASSERT_NO_THROW(p1 = p2);
	EXPECT_EQ(p1, p2);
	EXPECT_EQ(p1, p1);
}

// ADD MONOM

TEST(Polinom, Add_monome_to_polinom_works_correct) {
	Monom m1[3] = { Monom(10, 4, 5, 6), Monom(5, 1, 2, 3), Monom(10, 0, 5, 6) };
	Monom m2[2] = { Monom(10, 4, 5, 6), Monom(5, 1, 2, 3) };
	Monom monom(10, 0, 5, 6);
	Polinom p1(m1, 3), p2(m2, 2);
	p2.AddMonom(monom);
	EXPECT_EQ(p1, p2);
}

TEST(Polinom, Add_opposite_monome_to_beginning_of_polinom_works_correct) {
	Monom m1[3] = { Monom(15, 7, 8, 9), Monom(10, 4, 5, 6), Monom(5, 1, 2, 3) };
	Monom m2[2] = { Monom(10, 4, 5, 6), Monom(5, 1, 2, 3) };
	Monom NEGATIVE(-15, 7, 8, 9);
	Polinom p1(m1, 3), p2(m2, 2);
	p1.AddMonom(NEGATIVE);
	EXPECT_EQ(p1, p2);
}

TEST(Polinom, Add_opposite_monome_to_end_of_polinom_works_correct) {
	Monom m1[3] = { Monom(10, 4, 5, 6), Monom(5, 1, 2, 3), Monom(9, 0, 2, 4)};
	Monom m2[2] = { Monom(10, 4, 5, 6), Monom(5, 1, 2, 3) };
	Monom NEGATIVE(-9, 0, 2, 4);
	Polinom p1(m1, 3), p2(m2, 2);
	p1.AddMonom(NEGATIVE);
	EXPECT_EQ(p1, p2);
}

TEST(Polinom, Add_opposite_monome_to_middle_of_polinom_works_correct) {
	Monom m1[3] = { Monom(10, 4, 5, 6), Monom(9, 1, 2, 4), Monom(5, 0, 2, 3) };
	Monom m2[2] = { Monom(10, 4, 5, 6), Monom(5, 0, 2, 3) };
	Monom NEGATIVE(-9, 1, 2, 4);
	Polinom p1(m1, 3), p2(m2, 2);
	p1.AddMonom(NEGATIVE);
	EXPECT_EQ(p1, p2);
}

// ADD POLINOM

TEST(Polinom, Add_polinom_to_middle_of_polinom_works_correct) {
	Monom m1[2] = { Monom(4, 4, 4, 4), Monom(1, 1, 1, 1)};
	Monom m2[2] = { Monom(3, 3, 3, 3), Monom(2, 2, 2, 2) };
	Monom m3[4] = { Monom(4, 4, 4, 4), Monom(3, 3, 3, 3), Monom(2, 2, 2, 2), Monom(1, 1, 1, 1) };
	Polinom p1(m1, 2), p2(m2, 2), p1p2, corr_res(m3, 4);
	p1p2 = p1 + p2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Add_polinom_to_polinom_with_delete_middle_monom) {
	Monom m1[2] = { Monom(4, 4, 4, 4), Monom(-3, 3, 3, 3) };
	Monom m2[2] = { Monom(3, 3, 3, 3), Monom(2, 2, 2, 2) };
	Monom m3[2] = { Monom(4, 4, 4, 4), Monom(2, 2, 2, 2) };
	Polinom p1(m1, 2), p2(m2, 2), p1p2, corr_res(m3, 2);
	p1p2 = p1 + p2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Add_polinom_to_polinom_with_delete_first_monom) {
	Monom m1[2] = { Monom(4, 4, 4, 4), Monom(3, 3, 3, 3) };
	Monom m2[2] = { Monom(-4, 4, 4, 4), Monom(2, 2, 2, 2) };
	Monom m3[2] = { Monom(3, 3, 3, 3), Monom(2, 2, 2, 2) };
	Polinom p1(m1, 2), p2(m2, 2), p1p2, corr_res(m3, 2);
	p1p2 = p1 + p2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Add_polinom_to_polinom_with_delete_last_monom) {
	Monom m1[2] = { Monom(4, 4, 4, 4), Monom(3, 3, 3, 3) };
	Monom m2[2] = { Monom(-3, 3, 3, 3), Monom(2, 2, 2, 2) };
	Monom m3[2] = { Monom(4, 4, 4, 4), Monom(2, 2, 2, 2) };
	Polinom p1(m1, 2), p2(m2, 2), p1p2, corr_res(m3, 2);
	p1p2 = p1 + p2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Add_polinom_to_polinom_with_adding_monoms_in_middle) {
	Monom m1[3] = { Monom(4, 4, 4, 4), Monom(3, 3, 3, 3), Monom(2, 2, 2, 2) };
	Monom m2[3] = { Monom(3, 3, 3, 3), Monom(2, 2, 2, 2), Monom(1, 1, 1, 1) };
	Monom m3[4] = { Monom(4, 4, 4, 4), Monom(6, 3, 3, 3), Monom(4, 2, 2, 2), Monom(1, 1, 1, 1) };
	Polinom p1(m1, 3), p2(m2, 3), p1p2, corr_res(m3, 4);
	p1p2 = p1 + p2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Add_polinom_to_polinom_with_adding_monoms_in_front) {
	Monom m1[3] = { Monom(4, 4, 4, 4), Monom(3, 3, 3, 3), Monom(2, 2, 2, 2) };
	Monom m2[3] = { Monom(4, 4, 4, 4), Monom(3, 3, 3, 3), Monom(1, 1, 1, 1) };
	Monom m3[4] = { Monom(8, 4, 4, 4), Monom(6, 3, 3, 3), Monom(2, 2, 2, 2), Monom(1, 1, 1, 1) };
	Polinom p1(m1, 3), p2(m2, 3), p1p2, corr_res(m3, 4);
	p1p2 = p1 + p2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Add_polinom_to_polinom_with_adding_monoms_in_back) {
	Monom m1[3] = { Monom(4, 4, 4, 4), Monom(3, 3, 3, 3), Monom(2, 2, 2, 2) };
	Monom m2[3] = { Monom(5, 5, 5, 5), Monom(3, 3, 3, 3), Monom(2, 2, 2, 2) };
	Monom m3[4] = { Monom(5, 5, 5, 5), Monom(4, 4, 4, 4), Monom(6, 3, 3, 3), Monom(4, 2, 2, 2) };
	Polinom p1(m1, 3), p2(m2, 3), p1p2, corr_res(m3, 4);
	p1p2 = p1 + p2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Mixed_adding_of_polinoms_with_delete_and_addings_of_monoms) {
	Monom m1[5] = { Monom(8, 8, 1, 8), Monom(6, 6, 2, 6), Monom(5, 5, 5, 5), Monom(4, 4, 8, 4), Monom(1, 2, 66, 99)};
	Monom m2[4] = { Monom(-8, 8, 1, 8), Monom(3, 6, 2, 6),Monom(-4, 4, 8, 4), Monom(3, 3, 2, 1)};
	Monom m3[4] = { Monom(9, 6, 2, 6), Monom(5, 5, 5, 5), Monom(3, 3, 2, 1), Monom(1, 2, 66, 99)};
	Polinom p1(m1, 5), p2(m2, 4), p1p2, corr_res(m3, 4);
	p1p2 = p1 + p2;
	EXPECT_EQ(p1p2, corr_res);
}

//SUB

TEST(Polinom, Polinom_minus_polinom_with_delete_last_monom) {
	Monom m1[2] = { Monom(4, 4, 4, 4), Monom(1, 1, 1, 1) };
	Monom m2[2] = { Monom(3, 3, 3, 3), Monom(1, 1, 1, 1) };
	Monom m3[2] = { Monom(4, 4, 4, 4), Monom(3, 3, 3, 3) };
	Polinom p1(m1, 2), p2(m2, 2), p1p2, corr_res(m3, 2);
	p1p2 = p1 - p2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Polinom_minus_polinom_with_delete_first_monom) {
	Monom m1[2] = { Monom(4, 4, 4, 4), Monom(1, 1, 1, 1) };
	Monom m2[2] = { Monom(4, 4, 4 ,4), Monom(2, 2, 2, 2) };
	Monom m3[2] = { Monom(2, 2, 2, 2), Monom(1, 1, 1, 1) };
	Polinom p1(m1, 2), p2(m2, 2), p1p2, corr_res(m3, 2);
	p1p2 = p1 - p2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Polinom_minus_polinom_with_delete_middle_monom) {
	Monom m1[3] = { Monom(4, 4, 4, 4),Monom(2, 2, 2, 2), Monom(1, 1, 1, 1) };
	Monom m2[2] = { Monom(5, 5, 5, 5), Monom(2, 2, 2, 2) };
	Monom m3[3] = { Monom(5, 5, 5, 5), Monom(4, 4, 4, 4), Monom(1, 1, 1, 1) };
	Polinom p1(m1, 2), p2(m2, 2), p1p2, corr_res(m3, 2);
	p1p2 = p1 - p2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Polinom_minus_polinom_with_adding_and_deleting_monoms) {
	Monom m1[3] = { Monom(5, 5, 5, 5),Monom(2, 2, 2, 2), Monom(1, 1, 1, 1)};
	Monom m2[2] = { Monom(-5, 5, 5, 5), Monom(2, 2, 2, 2) };
	Monom m3[2] = { Monom(5, 5, 5, 5), Monom(1, 1, 1, 1)};
	Polinom p1(m1, 3), p2(m2, 2), p1p2, corr_res(m3, 2);
	p1p2 = p1 - p2;
	EXPECT_EQ(p1p2, corr_res);
}

//MULT

TEST(Polinom, Mult_two_polinoms) {
	Monom m1[2] = { Monom(2, 4, 2, 1), Monom(-3, 3, 3, 3) };
	Monom m2[2] = { Monom(3, 3, 3, 3), Monom(2, 2, 2, 2) };
	Monom m3[4] = {
		Monom(6, 7, 5, 4),
		Monom(-9, 6, 6, 6),
		Monom(4, 6, 4, 3),   
		Monom(-6, 5, 5, 5)   
	};
	Polinom p1(m1, 2), p2(m2, 2), p1p2, corr_res(m3, 4);
	p1p2 = p1 * p2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Mult_integer_const) {
	Monom m1[2] = { Monom(1, 1, 1, 1), Monom(2, 2, 2, 2) };
	Monom m2[2] = {Monom(2, 1, 1, 1), Monom(4, 2, 2, 2) };
	Polinom p1(m1, 2), corr_res(m2, 2), p1p2;
	p1p2 = p1 * 2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Mult_double_const) {
	Monom m1[2] = { Monom(1, 1, 1, 1), Monom(2, 2, 2, 2) };
	Monom m2[2] = { Monom(2.2, 1, 1, 1), Monom(4.4, 2, 2, 2) };
	Polinom p1(m1, 2), corr_res(m2, 2), p1p2;
	p1p2 = p1 * 2.2;
	EXPECT_EQ(p1p2, corr_res);
}

TEST(Polinom, Mult_zero) {
	Monom m1[2] = { Monom(1, 1, 1, 1), Monom(2, 2, 2, 2) };
	Polinom p1(m1, 2),  p1p0, corr_res;
	p1p0 = p1 * 0;
	EXPECT_EQ(p1p0, corr_res);
}

TEST(Polinom, Mult_monom) {
	Monom m1[2] = { Monom(2, 2, 2, 2), Monom(1, 1, 1, 1) };
	Monom m2[2] = { Monom(4, 4, 4, 4), Monom(2 ,3 ,3 ,3) };
	Polinom p1(m1, 2), corr_res(m2, 2), p1p2;
	p1p2 = p1 * Monom(2, 2, 2, 2);
	EXPECT_EQ(p1p2, corr_res);
}
