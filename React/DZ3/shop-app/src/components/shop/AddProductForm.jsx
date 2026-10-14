import React, { useState } from 'react';

const AddProductForm = ({ onAdd }) => {
  const [name, setName] = useState('');
  const [price, setPrice] = useState('');
  const [img, setImg] = useState('');
  const [country, setCountry] = useState('');
  const [rating, setRating] = useState('');
  const [error, setError] = useState(false);

  const handleAdd = () => {
    if (name === '' || price === '' || img === '' || country === '' || rating === '') {
      setError(true);
      return;
    }

    const newProduct = {
      id: Date.now(),
      name: name,
      price: parseFloat(price),
      img: img,
      country: country,
      rating: parseInt(rating)
    };

    onAdd(newProduct);

    setName('');
    setPrice('');
    setImg('');
    setCountry('');
    setRating('');
    setError(false);
  };

  return (
    <div style={{ textAlign: 'center', marginBottom: '30px' }}>
      <input value={name} onChange={e => setName(e.target.value)} placeholder="Назва" />{' '}
      <input value={price} onChange={e => setPrice(e.target.value)} placeholder="Ціна" />{' '}
      <input value={img} onChange={e => setImg(e.target.value)} placeholder="URL картинки" />{' '}
      <input value={country} onChange={e => setCountry(e.target.value)} placeholder="Країна" />{' '}
      <input value={rating} onChange={e => setRating(e.target.value)} placeholder="Рейтинг 1-5" />{' '}
      <br /><br />
      <div className="form-buttons"><button onClick={handleAdd}>Додати товар</button></div>
      {error && <div className="error">Заповніть всі поля!</div>}
    </div>
  );
};

export default AddProductForm;
