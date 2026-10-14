// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

import "@openzeppelin/contracts/utils/Strings.sol";

contract TradeContract {
    enum State {
        Ready,
        OrderCreated,
        OrderPaid,
        Shippment,
        OrderCompleted
    }
    State public state;
    
    //list of goods
    mapping (string => uint256) public products;
    string[] public keys;

    string public order;

    address payable public seller;
    address payable public buyer;
    uint256 insurance;

    constructor() payable {
        seller = payable (msg.sender);
        insurance = msg.value;
    }

    function createProducts(string memory _product, uint256 _price) public onlySeller {
        require(totalCost() + _price < insurance /2, "Insurance is not sufficient!");
        products[_product] = _price;
        keys.push(_product);
        state = State.Ready;
    }

    function totalCost() public view returns(uint256) {
        uint256 total = 0;
        for (uint8 i=0; i<keys.length; i++){
            total += products[keys[i]];
        }
        return total;
    }

    function getProducts() public view inState(State.Ready) returns (string memory) {
        string memory productList = "[";
        uint256 price = 0;
        for(uint8 i = 0; i < keys.length; i++){
            price = products[keys[i]];
            productList = string.concat(productList, "{\"product\":\"", keys[i] ,"\", \"price\":",  Strings.toString(price), "},");
        }
        productList = string.concat(productList,"]");
        return productList;
    }

    function createOrder(string memory _productName) public inState(State.Ready) {
        require (msg.sender != seller, "You are seller!");
        order = _productName;
        buyer = payable (msg.sender);
        state = State.OrderCreated;
    }

    function payForOrder() public onlyBuyer payable  {
        require(msg.value == products[order] * 2, "Order cost is not match!");
        state = State.OrderPaid;
    }

    function confirmPayment() public onlySeller inState(State.OrderPaid){
        state = State.Shippment;
    }

    function getBallance() public view returns (uint256){
        return address(this).balance;
    }

    function orderCompleated() public onlyBuyer {
        uint256 price = products[order];

        // transfer 3*price to seller
        (bool sentSeller, ) = seller.call{value: 3 * price}("");
        require(sentSeller, "Failed to send to seller");

        // transfer 1*price back to buyer
        (bool sentBuyer, ) = buyer.call{value: price}("");
        require(sentBuyer, "Failed to send to buyer");

        // decrease insurance by 2*price
        insurance -= 2 * price;

        // clear order and buyer
        delete order;
        delete buyer;

        // remove sold product from products
        delete products[order];

        for (uint8 i = 0; i < keys.length; i++) {
            if (keccak256(bytes(keys[i])) == keccak256(bytes(order))) {
                keys[i] = keys[keys.length - 1];
                keys.pop();
                break;
            }
        }
        state = State.Ready;
    }



    ///////////////////////////////////////////////////////////////
    modifier onlySeller() {
        require (msg.sender == seller, "You are not the seller!");
        _;
    }

    modifier onlyBuyer() {
        require (msg.sender == buyer, "You are not the buyer!");
        _;
    }

    modifier inState(State requiredState){
        require (state == requiredState, "Wrong state!");
        _;
    }


}