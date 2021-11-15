/*
 * A reverse-polish notation calculator.
 */

#include <RPN_calculator.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>


static auto pop_top(std::stack<double>& stack) -> double
{
    if (stack.empty()) {
        throw std::logic_error{"empty stack"};
    }
    auto element = std::move(stack.top());
    stack.pop();
    return element;
}


namespace student { namespace rpn_calculator {
Element::~Element()
{}

Literal::Literal(double const v) : value{v}
{}
auto Literal::evaluate(stack_type& stack) const -> void
{
    stack.push(value);
}

auto Print::evaluate(stack_type& stack) const -> void
{
    std::cout << stack.top() << "\n";
}

auto Addition::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for +"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a + b);
}

auto Subtraction::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a - b);
}

auto Multiplying::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for *"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a * b);
}

auto Dividing::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for /"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a / b);
}

auto Divide_Whole_Numbers::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for //"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    auto const sum = floor(a / b);
    stack.push(sum);
}

auto Modulo::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for %"};
    }
    int b = pop_top(stack);
    int a = pop_top(stack);
    stack.push(a % b);
}

auto Power::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for %"};
    }
    const auto b = pop_top(stack);
    const auto a = pop_top(stack);
    auto sum = a;
    for (auto i=1; i<b; i++){
        sum = sum * a;

    }
    stack.push(sum);
}

auto Root::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for sqrt"};
    }
    const auto a = pop_top(stack);
    stack.push(sqrt(a));
}

auto Triangle_Area::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 3) {
        throw std::logic_error{"not enough operands for triangle area"};
    }
    const auto h = pop_top(stack); //height (third field)
    const auto a = pop_top(stack); //second side  (second field)
    const auto b = pop_top(stack); //first side (first field)

    stack.push((a+b)/h);
}

Calculator::Calculator(stack_type s) : stack{std::move(s)}
{}

auto Calculator::push(std::unique_ptr<Element> op) -> void
{
    ops.push(std::move(op));
}

// FIXME implement Calculator::push(std::string)

auto Calculator::evaluate() -> void
{
    while (not ops.empty()) {
        auto op = std::move(ops.front());
        ops.pop();

        op->evaluate(stack);
    }
}
}}  // namespace student::rpn_calculator


auto make_args(int argc, char* argv[], bool const with_exec = false)
    -> std::vector<std::string>
{
    auto args         = std::vector<std::string>{};
    auto const offset = static_cast<size_t>(not with_exec);
    std::copy_n(argv + offset, argc - offset, std::back_inserter(args));
    return args;
}

auto main(int argc, char* argv[]) -> int
{
    using student::rpn_calculator::Calculator;
    auto calculator = Calculator{};

    for (auto const& each : make_args(argc, argv)) {
        try {
            using student::rpn_calculator::Addition;
            using student::rpn_calculator::Subtraction;
            using student::rpn_calculator::Multiplying;
            using student::rpn_calculator::Dividing;
            using student::rpn_calculator::Divide_Whole_Numbers;
            using student::rpn_calculator::Modulo;
            using student::rpn_calculator::Power;
            using student::rpn_calculator::Root;
            using student::rpn_calculator::Triangle_Area;
            using student::rpn_calculator::Literal;
            using student::rpn_calculator::Print;

            if (each == "p") {
                calculator.push(std::make_unique<Print>());
            } else if (each == "+") {
                calculator.push(std::make_unique<Addition>());
            } else if (each == "-") {
                calculator.push(std::make_unique<Subtraction>());
            } else if (each == "*") {
                calculator.push(std::make_unique<Multiplying>());
            } else if (each == "/") {
                calculator.push(std::make_unique<Dividing>());
            } else if (each == "//") {
                calculator.push(std::make_unique<Divide_Whole_Numbers>());
            } else if (each == "%") {
                calculator.push(std::make_unique<Modulo>());
            } else if (each == "**") {
                calculator.push(std::make_unique<Power>());
            } else if (each == "sqrt") {
                calculator.push(std::make_unique<Root>());
            } else if (each == "<|") {
                calculator.push(std::make_unique<Triangle_Area>());
            }
        } catch (std::logic_error const& e) {
            std::cerr << "error: " << each << ": " << e.what() << "\n";
        }
    }

    try {
        calculator.evaluate();
    } catch (std::logic_error const& e) {
        std::cerr << "error: during evaluation: " << e.what() << "\n";
    }

    return 0;
}
