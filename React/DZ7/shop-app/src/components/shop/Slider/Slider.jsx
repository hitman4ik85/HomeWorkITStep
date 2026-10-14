import React, { useState } from 'react';
import '../Product.css';
import sliderData from './sliderData';

const Slider = () => {
  const [index, setIndex] = useState(0);

  const next = () => {
    setIndex((index + 1) % sliderData.length);
  };

  const prev = () => {
    setIndex((index - 1 + sliderData.length) % sliderData.length);
  };

  return (
    <div style={{ textAlign: 'center', marginBottom: '20px' }}>
      <img src={sliderData[index]} alt="slide" style={{ borderRadius: '10px' }} />
      <div className="slider-buttons">
        <button onClick={prev}>Назад</button>
        <button onClick={next}>Вперед</button>
      </div>
    </div>
  );
};

export default React.memo(Slider);
