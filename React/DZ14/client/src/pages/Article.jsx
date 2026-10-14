import React, { useEffect } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { useParams } from 'react-router';
import Loader from '../components/Loader';
import { getArticle } from '../thunks/articleThunks';

const Article = () => {
  const { id } = useParams();
  const dispatch = useDispatch();
  const { current, currentStatus, currentError } = useSelector((state) => state.articles);

  useEffect(() => {
    dispatch(getArticle(id));
  }, [dispatch, id]);

  if (currentStatus === 'loading') return <Loader />;
  if (currentStatus === 'failed') return <h1>{currentError}</h1>;
  if (!current) return null;

  const created = current.createdAt || current.date;
  const createdText = created ? new Date(created).toLocaleString('uk-UA') : '';

  return (
    <div>
      <h1>{current.title}</h1>
      <div style={{ whiteSpace: 'pre-line', margin: '12px 0' }}>{current.content}</div>
      {createdText && <div>Створено: {createdText}</div>}
    </div>
  );
};

export default Article;