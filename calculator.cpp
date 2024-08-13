#include <iostream>
#include <string>

// ASCI COLOR CODES
#define ANSI_RED_CODE "\033[31m"
#define ANSI_GREEN_CODE "\033[32m"
#define ANSI_YELLOW_CODE "\033[33m"
#define ANSI_RESET_COLOR "\033[0m"

#define LOG_ERROR_COLOR ANSI_RED_CODE // like when logging an error to the console
#define LOG_VARIABLE_COLOR ANSI_YELLOW_CODE // like when logging a variable to the console

#define LOG_ERROR_PREFIX "Calculator.cpp: " // like logging an error for example: "calculator: fatal error..."

//////////////// CALCULATOR ////////////////////

namespace Calculator {
    // define variables
    std::string operation;
    int equation_numbers_count;

    namespace Operators_Identifiers {
        std::string addition = "+";
        std::string subtraction = "-";
        std::string multiplication = "*";
        std::string division = "/";
    }
}

void ask_for_operator() {
    std::cout <<
        "Enter operator (" + Calculator::Operators_Identifiers::addition + ")" +
        "(" + Calculator::Operators_Identifiers::subtraction + ")" +
        "(" + Calculator::Operators_Identifiers::multiplication + ")" +
        "(" + Calculator::Operators_Identifiers::division + ")" +
        " " + "(exit to exit calculator)";
    std::cin >> Calculator::operation;
}

int ask_for_equation_numbers_count(std::string operation) {
    if (operation == Calculator::Operators_Identifiers::addition || operation == Calculator::Operators_Identifiers::subtraction || operation == Calculator::Operators_Identifiers::multiplication || operation == Calculator::Operators_Identifiers::division) {
        std::cout <<
        "How many characters long is this equation (num1 " <<
        operation << " num2 " << operation << " num3...): ";
        std::cin >> Calculator::equation_numbers_count;
        std::cout << std::endl;

        return 0;
    } else {
        std::cerr << LOG_ERROR_PREFIX << LOG_ERROR_COLOR << "Fatal error: " << LOG_VARIABLE_COLOR << operation << ANSI_RESET_COLOR << " isnt a valid operator";
        std::cout << std::endl;

        return 1;
    }
}

int main() {
    ask_for_operator();

    if (Calculator::operation == Calculator::Operators_Identifiers::addition) {
        int ask_for_equation_numbers_count_succesful = ask_for_equation_numbers_count(Calculator::Operators_Identifiers::addition);

        if (ask_for_equation_numbers_count_succesful == 0) {
            double sum = 0;

            for (int i = 1; i < Calculator::equation_numbers_count + 1; i++) {
                double num;

                std::cout << "Number " + std::to_string(i) + ": ";
                std::cin >> num;

                    sum += num;
                }

            std::cout << sum;
        } else {
            return 1;
        }
    } else if (Calculator::operation == Calculator::Operators_Identifiers::subtraction) {
        int ask_for_equation_numbers_count_succesful = ask_for_equation_numbers_count(Calculator::Operators_Identifiers::subtraction);

        if (ask_for_equation_numbers_count_succesful == 0) {
            double sum;

            double num1;

            std::cout << "Number 1: ";
            std::cin >> num1;

            sum = num1;

            for (int i = 2; i < Calculator::equation_numbers_count + 1; i++) {
                double num;

                std::cout << "Number " + std::to_string(i) + ": ";
                std::cin >> num;

                sum -= num;
            }

            std::cout << sum;
        } else {
            return 1;
        }
    } else if (Calculator::operation == Calculator::Operators_Identifiers::multiplication) {
        int ask_for_equation_numbers_count_succesful = ask_for_equation_numbers_count(Calculator::Operators_Identifiers::multiplication);

        if (ask_for_equation_numbers_count_succesful == 0) {
            double sum = 1;

            for (int i = 1; i < Calculator::equation_numbers_count + 1; i++) {
                double num;

                std::cout << "Number " + std::to_string(i) + ": ";
                std::cin >> num;

                sum *= num;
            }

            std::cout << sum;
        } else {
            return 1;
        }
    } else if (Calculator::operation == Calculator::Operators_Identifiers::division) {
        int ask_for_equation_numbers_count_succesful = ask_for_equation_numbers_count(Calculator::Operators_Identifiers::division);

        if (ask_for_equation_numbers_count_succesful == 0) {
            double sum = 0;

            double num1;

            std::cout << "Number 1: ";
            std::cin >> num1;

            sum = num1;

            int was_input_zero = 0;

            for (int i = 2; i < Calculator::equation_numbers_count + 1; i++) {
                double num;

                std::cout << "Number " + std::to_string(i) + ": ";
                std::cin >> num;

                if (num == 0) {
                    was_input_zero = 0;
                } else {
                    sum /= num;
                }
            }

            if (was_input_zero == 0) {
                std::cout << "Your mom";
            } else {
                std::cout << sum;
            }
        }
    } else if (Calculator::operation == "exit") {
        std::cout << "Trying to exit program.";
        std::cout << std::endl;
        return 0;
    } else {
        std::cerr << LOG_ERROR_PREFIX << LOG_ERROR_COLOR << "Fatal error: " << LOG_VARIABLE_COLOR << Calculator::operation << ANSI_RESET_COLOR << " isnt a valid option";
        std::cout << std::endl;
        return 1;
    }

    return 0;
}