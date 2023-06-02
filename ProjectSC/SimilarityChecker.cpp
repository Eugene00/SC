#include <string>
using namespace std;
class SimilarityChecker
{
public:
	SimilarityChecker() = default;
	SimilarityChecker(string str1, string str2) : str1_(std::move(str1)), str2_(std::move(str2)) {}

	static constexpr int kMaxLengthScore = 60;
	static constexpr int kMaxAlphahScore = 40;
	static constexpr int kMaxNumUpperChars = 26;
	static constexpr int kFound = 1;
	static constexpr int kNotFound = 0;

	size_t GetTotalScore()
	{
		return GetLengthScore() + GetAlphaScore();
	}

	void SetStrings(string str1, string str2)
	{
		InitCharArrays();
		str1_ = std::move(str1);
		str2_ = std::move(str2);
	}

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

	size_t GetAlphaScore()
	{
		InitCharArrays();
		MakeCharArrays();

		size_t num_same_alpha = 0;
		size_t num_total_alpha = 0;

		for (int i = 0; i < kMaxNumUpperChars; ++i) {
			if (str1_char_array_[i] || str2_char_array_[i])
			{
				++num_total_alpha;
			}
			if (str1_char_array_[i] && str1_char_array_[i] == str2_char_array_[i])
			{
				++num_same_alpha;
			}
		}
		if (!num_same_alpha)
		{
			return 0;
		}
		if (num_total_alpha == num_same_alpha)
		{
			return kMaxAlphahScore;
		}
		return num_same_alpha * 40 / num_total_alpha;
	}

private:
	void InitCharArrays()
	{
		for (int i = 0; i < kMaxNumUpperChars; ++i)
		{
			str1_char_array_[i] = str2_char_array_[i] = kNotFound;
		}
	}

	void MakeCharArrays()
	{
		for (const char c : str1_)
		{
			if (c >= 'A' && c <= 'Z')
			{
				if (str1_char_array_[c - 'A'] == kNotFound)
				{
					str1_char_array_[c - 'A'] = kFound;
				}
			}
		}
		for (const char c : str2_)
		{
			if (c >= 'A' && c <= 'Z')
			{
				if (str2_char_array_[c - 'A'] == kNotFound)
				{
					str2_char_array_[c - 'A'] = kFound;
				}
			}
		}
	}

	string str1_;
	string str2_;
	size_t str1_char_array_[kMaxNumUpperChars];
	size_t str2_char_array_[kMaxNumUpperChars];
};
