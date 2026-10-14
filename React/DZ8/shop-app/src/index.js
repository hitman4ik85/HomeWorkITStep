import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import { RouterProvider } from 'react-router-dom';
import router from './router';
import FavoritesProvider from './providers/FavoritesProvider';
import CartProvider from './providers/CartProvider';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <FavoritesProvider>
    <CartProvider>
      <RouterProvider router={router} />
    </CartProvider>
  </FavoritesProvider>
);
