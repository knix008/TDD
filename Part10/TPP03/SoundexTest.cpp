#include "Soundex.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(SoundexEncoding) {
   Soundex soundex;
};

TEST(SoundexEncoding, AppendsZerosToWordForOneLetterWord) {
   CHECK_EQUAL("A000", soundex.encode("A"));
   CHECK_EQUAL("B000", soundex.encode("B"));
}