#include "All.h"

TEST(Sanity) {
	CHECK_EQUAL(1, 1);
	CHECK_EQUAL(1, 2);
}

SUITE(Sanity_suite) {
	TEST(test1) {
		CHECK_EQUAL(1, 1);
	}
	TEST(TEST2) {
		CHECK_EQUAL(1, 2);
	}
}

SUITE(Another_sanity_suite) {
	TEST(test3) {
		CHECK_EQUAL("hi", "hi");
	}
	TEST(TEST4) {
		CHECK_EQUAL(15, -42);
	}
}