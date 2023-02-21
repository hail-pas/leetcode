class Solution:
    def romanToInt(self, s: str) -> int:
        roman_identifier = {
            "M": 1000,
            "D": 500,
            "C": 100,
            "L": 50,
            "X": 10,
            "V": 5,
            "I": 1,
        }
        result = 0

        for index, ch in enumerate(s):
            if index + 1 < len(s) and roman_identifier[ch] < roman_identifier[s[index + 1]]:
                result -= roman_identifier[ch]
            else:
                result += roman_identifier[ch]
        return result

    def _romanToInt(self, s: str) -> int:
        roman_identifier = {
            "M": 1000,
            "CM": 900,
            "D": 500,
            "CD": 400,
            "C": 100,
            "XC": 90,
            "L": 50,
            "XL": 40,
            "X": 10,
            "IX": 9,
            "V": 5,
            "IV": 4,
            "I": 1,
        }
        result = 0
        for k, v in roman_identifier.items():
            while s.startswith(k):
                result += v
                s = s[len(k):]
        return result
