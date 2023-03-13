#include "gmock/gmock.h"
#include "Portfolio.h"

using namespace ::testing;

class APortfolio : public Test
{
public:
   Portfolio portfolio_;
};

TEST_F(APortfolio, IsEmptyWhenCreated)
{
   ASSERT_TRUE(portfolio_.IsEmpty());
}

TEST_F(APortfolio, IsNotEmptyAfterPurchase)
{
   portfolio_.Purchase("IBM", 1);

   ASSERT_FALSE(portfolio_.IsEmpty());
}
TEST_F(APortfolio, AnswersZeroForShareCountOfUnpurchasedSymbol)
{
   ASSERT_THAT(portfolio_.ShareCount("AAPL"), Eq(0u));
}

TEST_F(APortfolio, AnswersShareCountForPurchasedSymbol)
{
   portfolio_.Purchase("IBM", 2);
   ASSERT_THAT(portfolio_.ShareCount("IBM"), Eq(2u));
}
