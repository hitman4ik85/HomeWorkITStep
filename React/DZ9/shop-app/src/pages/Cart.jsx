import React, { useContext } from 'react';
import CartContext from '../contexts/CartContext';
import './Pages.css';

const Cart = () => {
  const { cart } = useContext(CartContext);

  return (
    <div className="cart-page">
      <h2 className="cart-title">Кошик</h2>
      {cart.length === 0 ? (
        <p className="cart-empty">Кошик порожній</p>
      ) : (
        <>
          <div className="cart-list">
            {cart.map(p => (
              <div key={p.id} className="cart-item">
                <img src={p.img} alt={p.name} />
                <span className="name">{p.name}</span>
                <span className="price">{p.price} ₴</span>
              </div>
            ))}
          </div>
          <div className="cart-total">
            Всього: {cart.reduce((sum, p) => sum + p.price, 0)} ₴
          </div>
        </>
      )}
    </div>
  );
};

export default Cart;
