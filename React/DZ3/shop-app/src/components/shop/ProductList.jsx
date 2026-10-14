import React, { useState } from 'react';
import './Product.css';
import ProductItem from './ProductItem';
import products from './productData';
import Slider from './Slider/Slider';
import AddProductForm from './AddProductForm';

const ProductList = () => {
  const [items, setItems] = useState(products);

  const addProduct = (newProduct) => {
    setItems([...items, newProduct]);
  };

  const deleteProduct = (id) => {
    setItems(items.filter(p => p.id !== id));
  };

  return (
    <div className="products-container">
      <Slider />
      
      <h2 style={{ textAlign: 'center', color: 'green' }}>Додати товар</h2>
      <AddProductForm onAdd={addProduct} />
      
      <h2 style={{ textAlign: 'center', color: 'green' }}>Наші товари</h2>
      <div className="product-grid">
        {items.map(prod => (
          <ProductItem key={prod.id} prod={prod} onDelete={deleteProduct} />
        ))}
      </div>
    </div>
  );
};

export default ProductList;
