import React from 'react';
import './Pages.css';

const NotFound = () => {
  return (
    <div className="notfound">
      404 — Сторінку не знайдено
    </div>
  );
};

export default React.memo(NotFound);
