import React, { useContext } from 'react';
import FavoritesContext from '../contexts/FavoritesContext';

const Favorites = () => {
  const { favorites } = useContext(FavoritesContext);

  return (
    <div style={{ padding: "20px", textAlign: "center" }}>
      <h2 style={{ color: "green" }}>Обрані товари</h2>
      {favorites.length === 0 ? <p>Список обраного порожній</p> : favorites.map(p => (
        <div key={p.id} style={{ marginBottom: "10px" }}>
          <img src={p.img} alt={p.name} style={{ width: "80px", height: "80px", objectFit: "contain" }} />
          <p>{p.name} - {p.price} ₴</p>
        </div>
      ))}
    </div>
  );
};

export default Favorites;
