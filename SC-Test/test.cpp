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

	size_t GetScore()
	{
		return similarity_checker_->GetScore();
	}

private:
	std::unique_ptr<SimilarityChecker> similarity_checker_;
};

TEST_F(SimilarityCheckerTest, LengthTest1) {
	int expected = 60;
	SetStrings("ASD", "DSA");
	EXPECT_EQ(GetScore(), expected);
}

TEST_F(SimilarityCheckerTest, LengthTest2) {
	int expected = 0;
	SetStrings("A", "BB");
	EXPECT_EQ(GetScore(), expected);
}

TEST_F(SimilarityCheckerTest, LengthTest3) {
	int expected = 20;
	SetStrings("AAABB", "BAA");
	EXPECT_EQ(GetScore(), expected);
}

TEST_F(SimilarityCheckerTest, LengthTest4) {
	int expected = 30;
	SetStrings("AA", "AAA");
	EXPECT_EQ(GetScore(), expected);
}