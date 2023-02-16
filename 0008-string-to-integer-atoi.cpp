#include <climits>
#include <exception>
#include <functional>
#include <iostream>
#include <string>
#include <map>
#include <vector>

class AutomationEndException: public std::exception {
    public:
        const char * what() const noexcept override {
            return "End of Automation";
        };
};

class Automation {
    private:
        bool positive_sign;
        long value;
        std::string state;
        std::map<std::string, std::vector<std::string>> trsfer_table;

    public:
        Automation():positive_sign(true), value(0), state("start"){
            // 点 --线--> 点
            // 状态：start、signed、in_number、end
            // 输入情况：' '、 +/-、number、other
            // 触发迁移表： 状态 * 情况
            //           ' '、     +/-、     number、    other
            this->trsfer_table["start"] = {"start", "signed", "in_number", "end"};
            this->trsfer_table["signed"] = {"end", "end", "in_number", "end"};
            this->trsfer_table["in_number"] = {"end", "end", "in_number", "end"};
            this->trsfer_table["end"] = {"end", "end", "end", "end"};
        }

        int get_state_column(char c) {
            int column_index = 3;
            if (std::isdigit(c)) {
                column_index = 2;
            }
            else if (std::isblank(c)) {
                column_index = 0;
            }else if ('+' == c or '-' == c) {
                column_index = 1;
            }
            return column_index;
        }

        void transfer(char c) {
            this->state = this->trsfer_table[this->state][this->get_state_column(c)];
            if (this->state == "in_number") {
                    this->value = this->value * 10 + (c - '0');
                    if ((-1 + 2 * this->positive_sign) * this->value >= INT_MAX) {
                        this->positive_sign = true;
                        this->value = INT_MAX;
                        throw AutomationEndException();
                    }else if ( (-1 + 2 * this->positive_sign) * this->value <= INT_MIN) {
                        this->positive_sign = true;
                        this->value = INT_MIN;
                        throw AutomationEndException();
                    }
            }
            else if (this->state == "signed") {
                this->positive_sign = c == '+' ? true: false;
            }else if (this->state == "end") {
                throw AutomationEndException();
            }
        }

        int get_result(){
            return this->positive_sign ? this->value : -1 * this->value;
        }

};

class Solution {
public:
    int myAtoi(std::string s) {
        // 状态机实现反而没有直接处理好
        Automation automation = Automation();
        for (auto c: s){
            try {
                automation.transfer(c);
            } catch (AutomationEndException ae) {
                std::cout<<ae.what()<<std::endl;
                break;
            }
        };
        return automation.get_result();
    }
};


int main(int argc, char const *argv[]) {
    std::cout<<Solution().myAtoi("-91283472332")<<std::endl;
    std::cout<<Solution().myAtoi("2147483648")<<std::endl;
    return 0;
}