// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract ContractToCall {
    function func1(uint x, uint y) public pure returns (uint) {
       return x + y;
    }

    function func2() public pure returns (string memory){
        return "Hello World!";
    }

    function func3() public pure returns (string memory, uint, uint){
        string memory s3 = "Hi!";
        return(s3, 10, 20);
    }

}

// calldata, memory
// (string s, uint u1, uint u2) = func3();
// (string s, , ) = func3();