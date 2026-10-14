import React from 'react';
import { NavLink } from 'react-router';
import './Header.css';

const Header = () => {
  return (
    <header className="header">
      <nav className="nav nav-left">
        <NavLink to="/">Головна сторінка</NavLink>
        <NavLink to="/articles/create">Додавання статті</NavLink>
      </nav>

      <nav className="nav nav-right">
        <NavLink to="/login">Login</NavLink>
        <NavLink to="/register">Register</NavLink>
      </nav>
    </header>
  );
};

export default Header;
