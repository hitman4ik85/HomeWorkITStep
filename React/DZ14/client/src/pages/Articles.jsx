import React, { useEffect } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { getArticles } from '../thunks/articleThunks';
import Loader from '../components/Loader';
import { NavLink } from 'react-router';

const Articles = () => {
  const dispatch = useDispatch();
  const articles = useSelector((state) => state.articles);

  useEffect(() => {
    dispatch(getArticles());
  }, [dispatch]);

  if (articles.status === 'loading') return <Loader />;
  if (articles.status === 'failed') return <h1>{articles.error}</h1>;

  return (
    <div>
      {articles.data.map((article) => (
        <h3 key={article._id} style={{ marginBottom: 8 }}>
          <NavLink to={`/articles/${article._id}`}>{article.title}</NavLink>
        </h3>
      ))}
    </div>
  );
}

export default Articles;
