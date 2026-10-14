import React, { useState } from 'react';
import './Product.css';
import ProductItem from './ProductItem';
import products from './productData';
import Slider from './Slider/Slider';
import AddProductForm from './AddProductForm';

const ProductList = () => {
  const [items, setItems] = useState(products);
  const [sortType, setSortType] = useState('default');
  // Функція для додавання нового товару
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
    setItems([...items, newProduct]); // додаємо новий товар до списку
  };

  const deleteProduct = (id) => {
    setItems(items.filter(p => p.id !== id));
  };

  const handleSort = (e) => {
    const value = e.target.value;
    setSortType(value);

    if (value === 'default') {
      setItems(products); // повертаємо початковий стан товарів
      return;
    }

    const nextItems = [...items]; // створюємо копію масиву товарів

    if (value === 'price') {
      nextItems.sort((a, b) => a.price - b.price);
    } else if (value === 'rating') {
      nextItems.sort((a, b) => b.rating - a.rating);
    } else if (value === 'name') {
      nextItems.sort((a, b) => a.name.localeCompare(b.name));
    }

    setItems(nextItems); // оновлюємо стан з відсортованими товарами
  };

  const handleRatingProduct = (id, rate) => {
    setItems(items.map((prod) => (prod.id === id ? { ...prod, rating: rate } : prod)));
  };

  const handleLikeProduct = (id) => {
    setItems(items.map((prod) => (prod.id === id ? { ...prod, liked: !prod.liked } : prod)));
  };

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

      <h2 style={{ textAlign: 'center', color: 'green' }}>Наші товари</h2>
      <div className="product-grid">
        {items.map(prod => (
          <ProductItem
            key={prod.id}
            prod={prod}
            onDelete={deleteProduct}
            handleRatingProduct={handleRatingProduct} // передаємо функцію handleRatingProduct для обробки рейтингу
            handleLikeProduct={handleLikeProduct} // передаємо функцію handleLikeProduct для обробки лайків
          />
        ))}
      </div>
    </div>
  );
};

export default ProductList;
