import React, { useState, useEffect } from 'react';
import './Product.css';
import ProductItem from './ProductItem';
import products from './productData';
import Slider from './Slider/Slider';
import AddProductForm from './AddProductForm';
import ProductFilter from './ProductFilter';

const ProductList = () => {
  const [items, setItems] = useState(() => {
    const saved = localStorage.getItem('items');
    return saved ? JSON.parse(saved) : products;
  });

  const [sortType, setSortType] = useState('default');
  const [filter, setFilter] = useState(() => localStorage.getItem('filter') || 'All');

    // ⬇️ Зберігаємо список товарів у localStorage при будь-якій зміні
    useEffect(() => {
      localStorage.setItem('items', JSON.stringify(items));
    }, [items]);
  
    // ⬇️ Зберігаємо фільтр у localStorage
    useEffect(() => {
      localStorage.setItem('filter', filter);
    }, [filter]);

  const addProduct = (name, price, img, country, rating) => {
    const newProduct = {
      id: Date.now(),
      name,
      price: parseFloat(price),
      img,
      country,
      rating: parseInt(rating),
      liked: false
    };
    setItems([...items, newProduct]);
  };

  const deleteProduct = (id) => {
    setItems(items.filter(p => p.id !== id));
  };

  const handleSort = (e) => {
    const value = e.target.value;
    setSortType(value);

    if (value === 'default') {
      setItems(products); // або завантажити з localStorage при бажанні
      return;
    }

    const nextItems = [...items];

    if (value === 'price') {
      nextItems.sort((a, b) => a.price - b.price);
    } else if (value === 'rating') {
      nextItems.sort((a, b) => b.rating - a.rating);
    } else if (value === 'name') {
      nextItems.sort((a, b) => a.name.localeCompare(b.name));
    }

    setItems(nextItems);
  };

  const handleRatingProduct = (id, rate) => {
    setItems(items.map(prod => (prod.id === id ? { ...prod, rating: rate } : prod)));
  };

  const handleLikeProduct = (id) => {
    setItems(items.map(prod => (prod.id === id ? { ...prod, liked: !prod.liked } : prod)));
  };

  const countries = [...new Set(items.map(p => p.country))];

  const filteredItems = filter === 'All' ? items : items.filter(p => p.country === filter);

  return (
    <div className="products-container">
      <Slider />

      <h2 style={{ textAlign: 'center', color: 'green' }}>Додати товар</h2>
      <AddProductForm onAdd={addProduct} />

      <div style={{ textAlign: 'center', margin: '20px' }}>
        <label style={{ marginRight: '10px', fontWeight: 'bold' }}>Сортування товарів:</label>
        <select value={sortType} onChange={handleSort}>
          <option value="default">Початковий стан</option>
          <option value="price">За ціною</option>
          <option value="rating">За рейтингом</option>
          <option value="name">За назвою</option>
        </select>
      </div>

      <ProductFilter filter={filter} setFilter={setFilter} countries={countries} />

      <h2 style={{ textAlign: 'center', color: 'green' }}>Наші товари</h2>
      <div className="product-grid">
        {filteredItems.map(prod => (
          <ProductItem
            key={prod.id}
            prod={prod}
            onDelete={deleteProduct}
            handleRatingProduct={handleRatingProduct}
            handleLikeProduct={handleLikeProduct}
          />
        ))}
      </div>
    </div>
  );
};

export default ProductList;
