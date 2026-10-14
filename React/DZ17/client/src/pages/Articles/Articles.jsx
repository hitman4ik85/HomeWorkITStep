import React, { useEffect } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { deleteArticle, getArticles } from '../../thunks/articleThunks';
import Loader from '../../components/Loader/Loader';
import { NavLink, useNavigate } from 'react-router-dom';
import './Articles.css';
import { EditOutlined, DeleteOutlined } from '@ant-design/icons';

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
            <th className="col-title">Title</th>
            <th className="col-date">Date</th>
            {role === 'admin' && <th className="col-actions">Actions</th>}
          </tr>
        </thead>
        <tbody>
          {articles.data.map((article) => {
            const created = article.createdAt || article.date;
            const createdText = created ? new Date(created).toLocaleDateString('uk-UA') : '';
            return (
              <tr key={article._id}>
                <td className="col-title">
                  <NavLink to={`/articles/${article._id}`} className="articles-link">
                    {article.title}
                  </NavLink>
                </td>
                <td className="col-date">{createdText}</td>
                {role === 'admin' && (
                  <td className="col-actions">
                    <EditOutlined
                      className="row-icon"
                      title="Редагувати"
                      onClick={() => navigate(`/articles/${article._id}/edit`)}
                    />
                    <DeleteOutlined
                      className="row-icon danger"
                      title="Видалити"
                      onClick={async () => {
                        if (window.confirm('Видалити статтю?')) {
                          await dispatch(deleteArticle(article._id));
                          dispatch(getArticles());
                        }
                      }}
                    />
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
