import React, { useState } from 'react';
import StarRating from './StarRating/StarRating';

const ProductItem = ({ prod, onDelete, handleRatingProduct, handleLikeProduct }) => {
  const [visible, setVisible] = useState(false);

  const toggleInfo = () => setVisible(!visible);

  return (
    <div className="product-card">
      <span
        onClick={() => handleLikeProduct(prod.id)}
        className={prod.liked ? 'heart filled' : 'heart'}
      >
        {prod.liked ? '♥' : '♡'}
      </span>

      <img src={prod.img} alt={prod.name} />
      <h3>{prod.name}</h3>
      <StarRating rate={prod.rating} id={prod.id} handleRatingTask={handleRatingProduct} />
      <p>{prod.price} ₴</p>

      <div className="button-group">
        <button>Купити</button>
        <button onClick={toggleInfo}>Детальніше</button>
        <button className="delete-btn" onClick={() => onDelete(prod.id)}>Видалити</button>
      </div>

      {visible && <p>Країна виробник: {prod.country}</p>}
    </div>
  );
};

export default ProductItem;
