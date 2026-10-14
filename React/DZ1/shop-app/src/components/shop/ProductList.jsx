import React from 'react';
import './Product.css';
import Product1 from './Product1';
import Product2 from './Product2';
import Product3 from './Product3';
import Product4 from './Product4';

const ProductList = () => {
  return (
    <div className="products-container">
      <h2 style={{ textAlign: 'center', color: 'green' }}>Наші товари</h2>
      <div className="product-grid">
        <Product1 />
        <Product2 />
        <Product3 />
        <Product4 />
      </div>
    </div>
  );
};

export default ProductList;
