import React from 'react'
import Web3 from 'web3';
import { useState, useEffect } from 'react';
import { CONTRACT_ADDRESS, CONTRACT_ABI, BYTECODE } from '../config';

export default function Seller() {

    const [accounts, setAccounts] = useState([]);
    const [contract, setContract] = useState(null);
    const [product, setProduct] = useState('');
    const [price, setPrice] = useState(0);
    const [products, setProducts] = useState([]); // додано для таблиці продуктів
    const [contractState, setContractState] = useState(0); // додано для стану
    const state = ['Ready', 'OrderCreated', 'OrderPaid', 'Shippment', 'OrderCompleted'];

    const connectWallet = async () => {
        if(window.ethereum.isMetaMask){
            const w3 = new Web3(window.ethereum);
            const acc = await w3.eth.requestAccounts();
            console.log(acc[0]);
            setAccounts(acc);
        }
    }

    const connectContract = () => {
        if(window.ethereum.isMetaMask) {
            const w3 = new Web3(window.ethereum);
            const myContract = new w3.eth.Contract(CONTRACT_ABI);
            console.log(myContract);
    
            const deployer = myContract.deploy({data: BYTECODE});
            deployer.send({from:accounts[0], gas:20000000})
            .on('receipt', (receipt) => {
                const deployedContract = new w3.eth.Contract(CONTRACT_ABI, receipt.contractAddress);
                console.log("Contract deployed!");
                setContract(deployedContract);
            })
            .on('error', (error) => {
                console.error("Error deploying contract:", error);
            });
        }
    }

    const addProduct = async () => {
        if(product && price && contract) {
            console.log(product + ' : ' + price);
            await contract.methods.createProducts(product, price).send({from: accounts[0]});
	    console.log("Product added:", response);
            getProducts(); // оновимо таблицю одразу
        }
    }

    const getProducts = async () => {
        if(contract){
            const response = await contract.methods.getProducts().call({from: accounts[0]})
            console.log("Products:", response);
            console.log("Products:", JSON.parse(response));
            setProducts(JSON.parse(response));
        }
    }

    useEffect(() => {
        const getState = async () => {
            if (contract) {
                try {
                    const response = await contract.methods.state().call({ from: accounts[0] });
                    console.log("getState");
                    console.log(response);
                    setContractState(parseInt(response)); // оновлюємо стан
                } catch (error) {
                    console.error("Error fetching contract state:", error);
                }
            }
        };
        getState();
    }, [contract, accounts, products]); // щоб стан оновлювався після кожної дії

    return (
    <div>
        <div className='row justify-content-center d-flex'>
            { !accounts[0] &&
                <button className='btn btn-outline-warning col-md-3 col-lg-3 col-sm-4 m-1' onClick={connectWallet}>Connect Wallet</button>
            }

            <div className='left-div col-md-9 col-lg-9 col-sm-8'>
                { accounts[0] &&
                    <div className='alert alert-success'>Connected to {accounts[0]}</div>
                }
            </div>
            <div className='right-div col-md-3 col-lg-3 col-sm-4'>
                { contract &&
                    <div className='alert alert-info'>{state[contractState]}</div>
                }
            </div>
        </div>

        <div className='row justify-content-center d-flex'>
            { !contract && accounts[0] &&
                <button className='btn btn-outline-warning col-md-3 col-lg-3 col-sm-4 m-1' onClick={connectContract}>Connect To Contract</button>
            }
        </div>

        <div className='row justify-content-center d-flex mt-4'>
            <div className='col-md-6'>
                <input 
                    type="text"
                    className="form-control m-1"
                    placeholder="Enter Product Name"
                    value={product}
                    onChange={(event) => setProduct(event.target.value)}
                />
                <input 
                    type="number"
                    className="form-control m-1"
                    placeholder="Enter Product Price"
                    value={price}
                    onChange={(event) => setPrice(event.target.value)}
                />
                <button className='btn btn-outline-success m-1 w-auto' onClick={addProduct}>Add Product</button>
                
                <hr/>

                {products.length > 0 && (
                    <table className='table table-striped'>
                        <thead>
                            <tr><th>Product</th><th>Price</th></tr>
                        </thead>
                        <tbody>
                            {products.map((item, index) => (
                                <tr key={index}>
                                    <td>{item.product}</td>
                                    <td>{item.price}</td>
                                </tr>
                            ))}
                        </tbody>
                    </table>
                )}
            </div>
        </div>
    </div>
    )
}
