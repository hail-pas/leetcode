class Solution:
    def intToRoman(self, num: int) -> str:
        """
        字符          数值
         I             1
         V             5
         X             10
         L             50
         C             100
         D             500
         M             1000
        """
        roman_identifier = {
            1000: "M",
            900: "CM",
            500: "D",
            400: "CD",
            100: "C",
            90: "XC",
            50: "L",
            40: "XL",
            10: "X",
            9: "IX",
            5: "V",
            4: "IV",
            1: "I",
        }

        result = []
        for k, v in roman_identifier.items():
            if num < k: continue
            k_nums = num // k
            result += [v*k_nums]
            num = num % k

        return "".join(result)
