import React, { useState } from 'react';
import '../Product.css';
import sliderData from './sliderData';
import { LeftCircleOutlined, RightCircleOutlined } from '@ant-design/icons';

const Slider = () => {
  const [index, setIndex] = useState(0);

  const next = () => {
    setIndex((index + 1) % sliderData.length);
  };

  const prev = () => {
    setIndex((index - 1 + sliderData.length) % sliderData.length);
  };

  return (
    <div className="slider-container">
      <LeftCircleOutlined className="slider-btn left" onClick={prev} />
      <img src={sliderData[index]} alt="slide" className="slider-img" />
      <RightCircleOutlined className="slider-btn right" onClick={next} />
    </div>
  );
};

export default React.memo(Slider);
