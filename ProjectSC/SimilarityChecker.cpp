#include <string>
using namespace std;
class SimilarityChecker
{
public:
	SimilarityChecker() = default;
	SimilarityChecker(string str1, string str2) : str1_(std::move(str1)), str2_(std::move(str2)) {}
	static constexpr int kMaxLengthScore = 60;

	size_t GetScore()
	{
		return GetLengthScore();
	}

	void SetStrings(string str1, string str2)
	{
		str1_ = std::move(str1);
		str2_ = std::move(str2);
	}

private:
	size_t GetLengthScore()
	{
		const auto long_str_len = max(str1_.size(), str2_.size());
		const auto short_str_len = min(str1_.size(), str2_.size());

		if (!long_str_len)
		{
			return 0;
		}
		auto gap = long_str_len - short_str_len;

		if (gap >= short_str_len)
		{
			return 0;
		}

		if (!gap)
		{
			return kMaxLengthScore;
		}
		return kMaxLengthScore - gap * kMaxLengthScore / short_str_len;
	}

	string str1_;
	string str2_;
};