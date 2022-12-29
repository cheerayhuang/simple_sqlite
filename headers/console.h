#pragma once

#include <iostream>
#include <string>

class Console {

public:
    void Run() {
        for(;;) {
            PrintPrompt();
            if (auto &cin_res = std::getline(std::cin, input_buf_); cin_res.eof()) {

                std::cout << "\nBye!" << std::endl;
                return ;
            }



            if (!CheckCMD()) {
                PrintErrMsg();
            }
        }

    }

    void PrintPrompt() {
        std::cout << "db >";
    }

    void PrintErrMsg() {
        std::cerr << "Invalid command: \"" << input_buf_ << "\".\n";
    }

    bool CheckCMD() {
        if (input_buf_.empty()) {
            return true;
        }
        return false;
    }

private:
    std::string input_buf_;

};
