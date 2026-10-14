import React from 'react';
import { NavLink } from 'react-router';
import './Header.css';

const Header = () => {
  return (
    <header className="header">
      <nav className="nav">
        <NavLink to="/">Головна сторінка</NavLink>
        <NavLink to="/articles/create">Додавання статті</NavLink>
      </nav>
    </header>
  );
};

export default Header;
