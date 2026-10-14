import React, { useState } from 'react';

const StarRating = ({rate}) => {
  const [rating, setRating] = useState(rate);
  const handleClick = (i) => {
    setRating(i + 1 === rating ? 0 : i + 1);
  };

  return (
    <div>
      {[...Array(5)].map((_, i) => (
        <span key={i} onClick={() => handleClick(i)} style={{ color: i < rating ? 'gold' : 'gray', cursor: 'pointer' }}>
          ★
        </span>
      ))}
    </div>
  );
};

export default StarRating;
