import React, { useContext } from 'react';
import CartContext from '../contexts/CartContext';

const Cart = () => {
  const { cart } = useContext(CartContext);

  return (
    <div style={{ padding: "20px", textAlign: "center" }}>
      <h2 style={{ color: "green" }}>Кошик</h2>
      {cart.length === 0 ? <p>Кошик порожній</p> : cart.map(p => (
        <div key={p.id} style={{ marginBottom: "10px" }}>
          <img src={p.img} alt={p.name} style={{ width: "80px", height: "80px", objectFit: "contain" }} />
          <p>{p.name} - {p.price} ₴</p>
        </div>
      ))}
    </div>
  );
};

export default Cart;
