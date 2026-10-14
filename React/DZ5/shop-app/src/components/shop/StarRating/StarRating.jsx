import React, { useState } from 'react';

const StarRating = ({ rate, handleRatingTask, id }) => {
  const [rating, setRating] = useState(rate);

  const handleClick = (i) => {
    const newRating = i + 1 === rating ? 0 : i + 1;
    setRating(newRating);
    handleRatingTask(id, newRating);
  };

  return (
    <div>
      {[...Array(5)].map((_, i) => (
        <span
          key={i}
          onClick={() => handleClick(i)}
          style={{ color: i < rating ? 'gold' : 'gray', cursor: 'pointer' }}
        >
          ★
        </span>
      ))}
    </div>
  );
};

export default StarRating;
