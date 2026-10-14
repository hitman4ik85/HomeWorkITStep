import React, { useState } from 'react';
import axios from 'axios';
import { SearchOutlined } from '@ant-design/icons';
import './Pages.css';

const Weather = () => {
  const [city, setCity] = useState('');
  const [weather, setWeather] = useState(null);
  const [error, setError] = useState('');

  const API_KEY = 'b3ea3946cd08306b75c8e73b04e6a794';

  const handleSearch = () => {
    if (city.trim() === '') {
      setError('Введіть назву міста');
      setWeather(null);
      return;
    }
    axios
      .get(`https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${API_KEY}&units=metric&lang=ua`)
      .then(res => {
        setWeather(res.data);
        setError('');
      })
      .catch(() => {
        setError('Місто не знайдено');
        setWeather(null);
      });
  };

  return (
    <div className="weather-container">
      <h2>Погода</h2>

      <div className="search-box">
        <input
          value={city}
          onChange={e => setCity(e.target.value)}
          placeholder="Введіть назву міста"
          onKeyDown={e => e.key === 'Enter' && handleSearch()}
        />
        <SearchOutlined className="search-icon" onClick={handleSearch} />
      </div>

      {error && <div className="error">{error}</div>}

      {weather && (
        <div className="weather-result">
          <h3>
            {weather.name}{weather.sys?.country ? `, ${weather.sys.country}` : ''}
          </h3>

          <div className="weather-main">
            {weather.weather?.[0]?.icon && (
              <img
                alt="іконка погоди"
                className="weather-icon"
                src={`https://openweathermap.org/img/wn/${weather.weather[0].icon}@2x.png`}
              />
            )}
            <div className="weather-now">
              <div className="temp">{Math.round(weather.main.temp)}°C</div>
              <div className="desc">{weather.weather?.[0]?.description}</div>
            </div>
          </div>

          <div className="weather-extra">
            <div>Відчувається як: {Math.round(weather.main.feels_like)}°C</div>
            <div>Вологість: {weather.main.humidity}%</div>
            <div>Вітер: {Math.round(weather.wind.speed)} м/с</div>
          </div>
        </div>
      )}
    </div>
  );
};

export default Weather;
