import React from 'react'
import Web3 from 'web3';
import { useState, useEffect } from 'react';
import { CONTRACT_ADDRESS, CONTRACT_ABI, BYTECODE } from '../config';

export default function Customer() {

  const [address, setAddress] = useState('');
  const [account, setAccount] = useState('');
  const [contract, setContract] = useState(null);
  const [products, setProducts] = useState([]);
  const [appState, setAppState] = useState(0);

  const state = ['Ready', 'OrderCreated', 'OrderPaid', 'Shippment', 'OrderCompleted'];

  useEffect( () => {
    const ad = JSON.parse(localStorage.getItem('address'));
    if(ad) {
      setAddress(ad);
    } else {
      console.log("No address found in localStorage");
    }
  }, []);

  useEffect( () => {
    console.log('buyer contract address');
    console.log(address);
    deployContract();
  }, [address]);

  const deployContract = () => {
    if(window.ethereum.isMetaMask) {
      const w3 = new Web3(window.ethereum);
      const myContract = new w3.eth.Contract(CONTRACT_ABI, address);
      setContract(myContract);
      console.log(myContract);
      const ac = JSON.parse(localStorage.getItem('account'));
      if (ac) {
        setAccount(ac);
      }
    }
  }

  const getProducts = async () => {
    if( contract ){
      const response = await contract.methods.getProducts().call({from:account});
      console.log(response);
      const parsed = JSON.parse(response);
      setProducts(parsed);
      await getState(); // оновимо стан
    }
  }

  const getState = async () => {
    if(contract){
      const response = await contract.methods.state().call({from:account});
      console.log("getState", response);
      setAppState(response);
    }
  }

  const createOrder = async (productName) => {
    if( contract ){
      const response = await contract.methods.createOrder(productName).send({from:account});
      console.log(response);
      await getState(); // оновимо стан
    }
  }

  return (
    <div>
      <div className='row justify-content-center d-flex'>
        <div className='left-div col-md-9 col-lg-9 col-sm-8'>
          { contract &&
            <div className='alert alert-info'>Contract State: {state[appState]}</div>
          }
        </div>
      </div>

      <div className='row justify-content-center d-flex'>
        { contract && 
          <button className='btn btn-warning m-1 w-auto' onClick={getProducts}>Load Products</button>
        }
      </div>

      {products.length > 0 && (
        <div className='row justify-content-center mt-4'>
          <table className='table table-striped w-auto'>
            <thead>
              <tr>
                <th>Product</th>
                <th>Price</th>
                <th>Buy</th>
              </tr>
            </thead>
            <tbody>
              {products.map((item, index) => (
                  <tr key={index}>
                      <td>{item.product}</td>
                      <td>{item.price}</td>
                      <td>
                        <button className='btn btn-outline-primary btn-sm' onClick={() => createOrder(item.product)}>Buy</button>
                      </td>
                  </tr>
              ))}
            </tbody>
          </table>
        </div>
      )}
    </div>
  )
}
