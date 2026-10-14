import React, { useState } from 'react';

const ProductItem = ({ prod }) => {
  const [visible, setVisible] = useState(false);
  const toggleInfo = () => setVisible(!visible);

  return (
    <div className="product-card">
      <img src={prod.img} alt={prod.name} />
      <h3>{prod.name}</h3>
      <p>{prod.price} ₴</p>
      <div className="button-group">
        <button>Купити</button>
        <button onClick={toggleInfo}>Детальніше</button>
      </div>
      {visible && <p>Країна виробник: {prod.country}</p>}
    </div>
  );
};

export default ProductItem;
