// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract Startup {
    address public owner;
    mapping (address => uint) public funders;
    address[] public keys;
    uint256 public targetAmount = 100000000000;
    uint256 public stepAmount = 1000000000;

    constructor() {
        owner = msg.sender;
    }

    function fund() public payable {
        require(address(this).balance - msg.value < targetAmount, "Target amount reached");
        require(msg.value >= stepAmount, "You must send not less than 10 Gwei");

        funders[msg.sender] += msg.value;
        keys.push(msg.sender);
    }

    function getBalance() public view returns (uint256)  {
        return address(this).balance;
    }

}

//msg.sender
//msg.value
//msg.data
//abi


//0x5B38Da6a701c568545dCfcB03FcB875f56beddC4 - owner
//0xAb8483F64d9C6d1EcF9b849Ae677dD3315835cb2 - funder1
//0x4B20993Bc481177ec7E8f571ceCaE8A9e22C02db - funder2