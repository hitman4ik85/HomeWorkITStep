import React, { useContext, useState } from 'react';
import StarRating from './StarRating/StarRating';
import FavoritesContext from '../../contexts/FavoritesContext';
import CartContext from '../../contexts/CartContext';
import { ShoppingCartOutlined, CheckCircleFilled, HeartOutlined, HeartFilled } from '@ant-design/icons';

const ProductItem = ({ prod, onDelete, handleRatingProduct }) => {
  const [visible, setVisible] = useState(false);
  const { favorites, toggleFavorite } = useContext(FavoritesContext);
  const { cart, toggleCart } = useContext(CartContext);

  const isFav = favorites.some(p => p.id === prod.id);
  const isInCart = cart.some(p => p.id === prod.id);

  return (
    <div className="product-card">
      <img src={prod.img} alt={prod.name} />
      <span onClick={() => toggleFavorite(prod)} className="heart" title={isFav ? 'В обраному' : 'Додати в обране'}>
        {isFav ? <HeartFilled style={{ color: 'gold', fontSize: '20px' }} /> : <HeartOutlined style={{ fontSize: '20px' }} />}
      </span>

      <h3>{prod.name}</h3>
      <StarRating rate={prod.rating} id={prod.id} handleRatingTask={handleRatingProduct} />
      <p>{prod.price} ₴</p>

      <div className="button-group">
        <span
          className="cart-icon"
          onClick={() => toggleCart(prod)}
          title={isInCart ? 'У кошику' : 'Додати в кошик'}
        >
          {isInCart
            ? <CheckCircleFilled style={{ color: 'green', fontSize: '24px' }} />
            : <ShoppingCartOutlined style={{ fontSize: '24px' }} />}
        </span>

        <button onClick={() => setVisible(!visible)}>Детальніше</button>
        <button className="delete-btn" onClick={() => onDelete(prod.id)}>Видалити</button>
      </div>

      {visible && <p>Країна виробник: {prod.country}</p>}
    </div>
  );
};

export default React.memo(ProductItem);
