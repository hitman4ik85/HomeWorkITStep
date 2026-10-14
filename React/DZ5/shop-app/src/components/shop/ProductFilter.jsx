import React from 'react';
import './Product.css';

const ProductFilter = ({ filter, setFilter, countries }) => {
  return (
    <div className="product-filter">
      <label className="filter-label">Фільтрація за країною:</label>
      {['All', ...countries].map((country) => (
        <button
          key={country}
          className={`filter-button ${filter === country ? 'active' : ''}`}
          onClick={() => setFilter(country)}
        >
          {country}
        </button>
      ))}
    </div>
  );
};

export default ProductFilter;
