import React from 'react';
import './Product.css';
import ProductItem from './ProductItem';

const products = [
  {
    id: 1,
    name: 'Вентилятор SATURN',
    price: 799,
    img: 'https://leo-shop.com.ua/content/images/27/1280x1280l80nn0/94361126059989.webp',
    country: 'Україна'
  },
  {
    id: 2,
    name: 'Вентилятор INTERLUX',
    price: 699,
    img: 'https://content.rozetka.com.ua/goods/images/big/553218455.jpg',
    country: 'Польща'
  },
  {
    id: 3,
    name: 'Холодильник Brevia 40L',
    price: 13451,
    img: 'https://content2.rozetka.com.ua/goods/images/big/567916272.jpg',
    country: 'Німеччина'
  },
  {
    id: 4,
    name: 'Садовий комплект',
    price: 6899,
    img: 'https://content.rozetka.com.ua/goods/images/big/544618807.png',
    country: 'Китай'
  }
];

const ProductList = () => {
  return (
    <div className="products-container">
      <h2 style={{ textAlign: 'center', color: 'green' }}>Наші товари</h2>
      <div className="product-grid">
        {products.map(prod => (
          <ProductItem key={prod.id} prod={prod} />
        ))}
      </div>
    </div>
  );
};

export default ProductList;
