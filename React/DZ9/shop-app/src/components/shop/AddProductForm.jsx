import React, { useState } from 'react';

const AddProductForm = ({ onAdd }) => {
  const [visible, setVisible] = useState(false);
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

    onAdd(name, price, img, country, rating);
    setName('');
    setPrice('');
    setImg('');
    setCountry('');
    setRating('');
    setError(false);
    setVisible(false);
  };

  return (
    <div style={{ textAlign: 'center', marginBottom: '30px' }}>
      <div className="form-buttons">
        <button onClick={() => setVisible(true)}>Додати товар</button>
      </div>

      {visible && (
        <div className="modal-overlay">
          <div className="modal">
            <h3>Новий товар</h3>
            <input value={name} onChange={e => setName(e.target.value)} placeholder="Назва" />{' '}
            <input value={price} onChange={e => setPrice(e.target.value)} placeholder="Ціна" />{' '}
            <input value={img} onChange={e => setImg(e.target.value)} placeholder="URL картинки" />{' '}
            <input value={country} onChange={e => setCountry(e.target.value)} placeholder="Країна" />{' '}
            <input value={rating} onChange={e => setRating(e.target.value)} placeholder="Рейтинг 1-5" />{' '}
            <br /><br />
            <div className="form-buttons">
              <button onClick={handleAdd}>Додати</button>
              <button onClick={() => setVisible(false)}>Закрити</button>
            </div>
            {error && <div className="error">Заповніть всі поля!</div>}
          </div>
        </div>
      )}
    </div>
  );
};

export default React.memo(AddProductForm);
