import React from 'react'
import Web3 from 'web3';
import { useState } from 'react';
import { CONTRACT_ADDRESS, CONTRACT_ABI, BYTECODE } from '../config';

export default function Seller() {

    const [accounts, setAccounts] = useState([]);
    const [contract, setContract] = useState(null);
    const [product, setProduct] = useState('');
    const [price, setPrice] = useState(0);

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
            deployer.send({from:accounts[0], gas:2000000})
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

    return (
    <div>
        <div className='row justify-content-center d-flex'>
            { !accounts[0] &&
                <button className='btn btn-outline-warning col-md-3 col-lg-3 col-sm-4 m-1' onClick={connectWallet}>Connect Wallet</button>
            }
            { accounts[0] &&
                <div className='alert alert-success'>Connected to {accounts[0]}</div>
            }
        </div>
        <div className='row justify-content-center d-flex'>
            { !contract && accounts[0] &&
                <button className='btn btn-outline-warning col-md-3 col-lg-3 col-sm-4 m-1' onClick={connectContract}>Connect To Contract</button>
            }
        </div>

        <div className='row justify-content-center d-flex mt-4'>
            <div className='col-md-4'>
                <input 
                    type="text"
                    className="form-control m-1"
                    placeholder="Product Name"
                    value={product}
                    onChange={(e) => setProduct(e.target.value)}
                />
                <input 
                    type="number"
                    className="form-control m-1"
                    placeholder="Product Price"
                    value={price}
                    onChange={(e) => setPrice(e.target.value)}
                />
                <button className='btn btn-outline-success col-12 m-1'>
                    Add Product
                </button>
            </div>
        </div>
    </div>
    )
}
