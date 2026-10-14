// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.29;

contract Lottery {
    address public owner;
    address[] public players;
    uint256 public entryPrice;

    constructor() {
        owner = msg.sender;
        entryPrice = 0.1 ether;
    }

    event LotteryPurchase(address player, uint timestamp);
    event SetWinner(address winner, uint256 prize, uint timestamp);

    function enter() public payable {
        require(msg.value == entryPrice, "You mast pay 0.1 ether!");
        for (uint i = 0; i < players.length; i++) {
            require(players[i] != msg.sender, "You have already bought a lottery!");
        }
        players.push(msg.sender);
    }

    function getBalance() public view onlyOwner returns (uint256) {
        return address(this).balance;
    }

    function randomIndex() public view returns (uint) {
        return uint(keccak256(abi.encodePacked(block.timestamp, players))) % players.length;
    }

    function pickWinner() public onlyOwner returns (address) {
        require(players.length > 3, "No players in the lottery");
        address winner = players[randomIndex()];
        uint256 prize = address(this).balance/2;
        (bool success1, ) = payable(winner).call{value: prize}("");
        require(success1, "Transfer to winner failed");
        (bool success2, ) = payable(owner).call{value: prize}("");
        require(success2, "Transfer to owner failed");
        players = new address[](0);
        emit SetWinner(winner, prize, block.timestamp);
        return winner;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can call this function");
        _;
    }

}