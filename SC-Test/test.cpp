#include "pch.h"
#include "../ProjectSC/SimilarityChecker.cpp"

class SimilarityCheckerTest : public ::testing::Test
{
public:
	void SetUp() override
	{
		similarity_checker_ = std::make_unique<SimilarityChecker>();
	}

	void SetStrings(string str1, string str2) const
	{
		similarity_checker_->SetStrings(std::move(str1), std::move(str2));
	}

	size_t GetLengthScore() const
	{
		return similarity_checker_->GetLengthScore();
	}

	size_t GetAlphaScore() const
	{
		return similarity_checker_->GetAlphaScore();
	}


private:
	std::unique_ptr<SimilarityChecker> similarity_checker_;
};

TEST_F(SimilarityCheckerTest, LengthTest1) {
	const int expected = 60;
	SetStrings("ASD", "DSA");
	EXPECT_EQ(GetLengthScore(), expected);
}

TEST_F(SimilarityCheckerTest, LengthTest2) {
	const int expected = 0;
	SetStrings("A", "BB");
	EXPECT_EQ(GetLengthScore(), expected);
}

TEST_F(SimilarityCheckerTest, LengthTest3) {
	const int expected = 20;
	SetStrings("AAABB", "BAA");
	EXPECT_EQ(GetLengthScore(), expected);
}

TEST_F(SimilarityCheckerTest, LengthTest4) {
	const int expected = 30;
	SetStrings("AA", "AAA");
	EXPECT_EQ(GetLengthScore(), expected);
}

TEST_F(SimilarityCheckerTest, AlphaTest1) {
	const int expected = 40;
	SetStrings("ASD", "DSA");
	EXPECT_EQ(GetAlphaScore(), expected);
}

TEST_F(SimilarityCheckerTest, AlphaTest2) {
	const int expected = 0;
	SetStrings("A", "BB");
	EXPECT_EQ(GetAlphaScore(), expected);
}

TEST_F(SimilarityCheckerTest, AlphaTest3) {
	const int expected = 40;
	SetStrings("AAABB", "BAA");
	EXPECT_EQ(GetAlphaScore(), expected);
}

TEST_F(SimilarityCheckerTest, AlphaTest4) {
	const int expected = 20;
	SetStrings("AA", "AAE");
	EXPECT_EQ(GetAlphaScore(), expected);
}