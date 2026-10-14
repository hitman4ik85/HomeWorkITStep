import React, { useEffect } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { deleteArticle, getArticles } from '../../thunks/articleThunks';
import Loader from '../../components/Loader/Loader';
import { NavLink, useNavigate } from 'react-router';
import './Articles.css';

const Articles = () => {
  const dispatch = useDispatch();
  const navigate = useNavigate();
  const articles = useSelector((state) => state.articles);
  const role = useSelector((s) => s.auth?.user?.role);

  useEffect(() => {
    dispatch(getArticles());
  }, [dispatch]);

  if (articles.status === 'loading') return <Loader />;
  if (articles.status === 'failed') return <h1>{articles.error}</h1>;

  return (
    <div>
      <h2>Articles</h2>
      <table className="articles-table">
        <thead>
          <tr>
            <th>Title</th>
            <th>Date</th>
            {role === 'admin' && <th>Actions</th>}
          </tr>
        </thead>
        <tbody>
          {articles.data.map((article) => {
            const created = article.createdAt || article.date;
            const createdText = created ? new Date(created).toLocaleDateString('uk-UA') : '';
            return (
              <tr key={article._id}>
                <td>
                  <NavLink to={`/articles/${article._id}`}>{article.title}</NavLink>
                </td>
                <td>{createdText}</td>
                {role === 'admin' && (
                  <td>
                    <span
                      className="row-action"
                      onClick={() => navigate(`/articles/${article._id}/edit`)}
                    >
                      Редагувати
                    </span>
                    {' | '}
                    <span
                      className="row-action danger"
                      onClick={async () => {
                        if (window.confirm('Видалити статтю?')) {
                          await dispatch(deleteArticle(article._id));
                          dispatch(getArticles());
                        }
                      }}
                    >
                      Видалити
                    </span>
                  </td>
                )}
              </tr>
            );
          })}
        </tbody>
      </table>
    </div>
  );
};

export default Articles;
