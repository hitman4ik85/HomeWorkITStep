import React, { useContext } from 'react';
import FavoritesContext from '../contexts/FavoritesContext';
import './Pages.css';

const Favorites = () => {
  const { favorites } = useContext(FavoritesContext);

  return (
    <div className="favorites-page">
      <h2 className="favorites-title">Обрані товари</h2>
      {favorites.length === 0 ? (
        <p className="favorites-empty">Список обраного порожній</p>
      ) : (
        <div className="product-grid">
          {favorites.map(p => (
            <div key={p.id} className="product-card">
              <img src={p.img} alt={p.name} />
              <h3>{p.name}</h3>
              <p>{p.price} ₴</p>
            </div>
          ))}
        </div>
      )}
    </div>
  );
};

export default Favorites;
