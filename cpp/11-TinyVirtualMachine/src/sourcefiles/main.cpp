// #include "../hederfiles/VirtualMachine.hpp"
#include "VirtualMachine.hpp"
    //phase one
    // static_cast<int32_t>(OpCode::PUSH),
    // 12,
    // static_cast<int32_t>(OpCode::PUSH),
    // 8,
    // static_cast<int32_t>(OpCode::DUP),
    // static_cast<int32_t>(OpCode::INC),
    // static_cast<int32_t>(OpCode::INC),
    // static_cast<int32_t>(OpCode::MUL),
    // static_cast<int32_t>(OpCode::SUB),
    // static_cast<int32_t>(OpCode::DUP),
    // static_cast<int32_t>(OpCode::PRINT),
    // static_cast<int32_t>(OpCode::PRINT_C),
    // static_cast<int32_t>(OpCode::HALT),
    //phase two
    // static_cast<int32_t>(OpCode::PUSH),
    // 64,
    // static_cast<int32_t>(OpCode::INC),
    // static_cast<int32_t>(OpCode::DUP),
    // static_cast<int32_t>(OpCode::PRINT_C),
    // static_cast<int32_t>(OpCode::DUP),
    // static_cast<int32_t>(OpCode::PUSH),
    // 70,
    // static_cast<int32_t>(OpCode::SUB),
    // static_cast<int32_t>(OpCode::JNZ),
    // 2,
    // static_cast<int32_t>(OpCode::HALT),
int main()
{
    std::vector<int32_t> oPcodes = {
        static_cast<int32_t>(OpCode::PUSH),
        64,
        static_cast<int32_t>(OpCode::CALL),
        10,
        static_cast<int32_t>(OpCode::NOP),
        static_cast<int32_t>(OpCode::CALL),
        10,
        static_cast<int32_t>(OpCode::NOP),
        static_cast<int32_t>(OpCode::HALT),
        static_cast<int32_t>(OpCode::NOP),
        static_cast<int32_t>(OpCode::INC),
        static_cast<int32_t>(OpCode::DUP),
        static_cast<int32_t>(OpCode::PRINT_C),
        static_cast<int32_t>(OpCode::RET),
    };

    VirtualMachine vm(oPcodes);
    vm.Execute();

    std::cout << "Result: " << vm.value() << "\n";

    return 0;
}