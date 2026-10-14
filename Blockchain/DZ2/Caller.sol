// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

import "./ContractToCall.sol";

contract Caller {

    address toCall = 0x4a9C121080f6D9250Fc0143f41B595fD172E31bf;

    function caller1(uint n1, uint n2) public returns (uint) {
        // Виклик func1(uint, uint)
        (bool result, bytes memory data) = toCall.call(abi.encodeWithSignature("func1(uint256,uint256)", n1, n2));
        require(result, "Call to func1 failed");
        return abi.decode(data, (uint));
    }

    function caller2() public returns (string memory) {
        // Виклик func2()
        (bool result, bytes memory data) = toCall.call(abi.encodeWithSignature("func2()"));
        require(result, "Call to func2 failed");
        return abi.decode(data, (string));
    }

    function caller3() public returns (string memory, uint, uint) {
        // Виклик func3()
        (bool result, bytes memory data) = toCall.call(abi.encodeWithSignature("func3()"));
        require(result, "Call to func3 failed");
        return abi.decode(data, (string, uint, uint));
    }
}