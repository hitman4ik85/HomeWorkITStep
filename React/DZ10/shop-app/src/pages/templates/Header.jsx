import React, { useContext } from 'react';
import { NavLink } from 'react-router';
import './Header.css';
import { HeartOutlined, ShoppingCartOutlined } from '@ant-design/icons';
import FavoritesContext from '../../contexts/FavoritesContext';
import CartContext from '../../contexts/CartContext';

const Header = () => {
  const { favorites } = useContext(FavoritesContext);
  const { cart } = useContext(CartContext);

  return (
    <header>
      <nav className="left-nav">
        <NavLink to="/">Home</NavLink>
        <NavLink to="/weather">Weather</NavLink>
        <NavLink to="/login">Login</NavLink>
      </nav>

      <div className="right-nav">
        <NavLink to="/favorites" className="icon-link">
          <HeartOutlined />
          {favorites.length > 0 && <span className="count">{favorites.length}</span>}
        </NavLink>

        <NavLink to="/cart" className="icon-link">
          <ShoppingCartOutlined />
          {cart.length > 0 && <span className="count">{cart.length}</span>}
        </NavLink>
      </div>
    </header>
  );
};

export default Header;
