import React, { useState, useEffect, useCallback, useMemo } from 'react';
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

  useEffect(() => {
    localStorage.setItem('items', JSON.stringify(items));
  }, [items]);

  useEffect(() => {
    localStorage.setItem('filter', filter);
  }, [filter]);

  const addProduct = useCallback((name, price, img, country, rating) => {
    const newProduct = {
      id: Date.now(),
      name,
      price: parseFloat(price),
      img,
      country,
      rating: parseInt(rating)
    };
    setItems((prev) => [...prev, newProduct]);
  }, []);

  const deleteProduct = useCallback((id) => {
    setItems((prev) => prev.filter(p => p.id !== id));
  }, []);

  const handleSort = useCallback((e) => {
    setSortType(e.target.value);
  }, []);

  const handleRatingProduct = useCallback((id, rate) => {
    setItems((prev) => prev.map(prod => (prod.id === id ? { ...prod, rating: rate } : prod)));
  }, []);

  const countries = useMemo(() => [...new Set(items.map(p => p.country))], [items]);

  const filteredItems = useMemo(() => {
    return filter === 'All' ? items : items.filter(p => p.country === filter);
  }, [items, filter]);

  const sortedItems = useMemo(() => {
    const arr = [...filteredItems];
    if (sortType === 'price') {
      arr.sort((a, b) => a.price - b.price);
    } else if (sortType === 'rating') {
      arr.sort((a, b) => b.rating - a.rating);
    } else if (sortType === 'name') {
      arr.sort((a, b) => a.name.localeCompare(b.name));
    }
    return arr;
  }, [filteredItems, sortType]);

  return (
    <div className="products-container">
      <Slider />

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
        {sortedItems.map(prod => (
          <ProductItem
            key={prod.id}
            prod={prod}
            onDelete={deleteProduct}
            handleRatingProduct={handleRatingProduct}
          />
        ))}
      </div>
    </div>
  );
};

export default ProductList;
