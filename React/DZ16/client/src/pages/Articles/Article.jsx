import React, { useEffect, useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { useParams } from 'react-router';
import Loader from '../../components/Loader/Loader';
import { getArticle } from '../../thunks/articleThunks';
import { createComment, deleteComment, fetchComments, updateComment } from '../../thunks/commentsThunks';
import useAuth from '../../hooks/useAuth';
import './Article.css';

const Article = () => {
  const { id } = useParams();
  const dispatch = useDispatch();
  const { current, currentStatus, currentError } = useSelector((state) => state.articles);
  const comments = useSelector((s) => s.comments);
  const isAuth = useAuth();
  const role = useSelector((s) => s.auth?.user?.role);

  const [text, setText] = useState('');
  const [editId, setEditId] = useState(null);
  const [editText, setEditText] = useState('');

  useEffect(() => {
    dispatch(getArticle(id));
    dispatch(fetchComments(id));
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

      <hr style={{ margin: '20px 0' }} />
      <h3>Коментарі</h3>

      {/* Таблиця коментарів */}
      <table className="comments-table">
        <thead>
          <tr>
            <th>Author</th>
            <th>Content</th>
            <th>Date</th>
            {role === 'admin' && <th>Actions</th>}
          </tr>
        </thead>
        <tbody>
          {comments.list.map((c) => {
            const dateText = c.createdAt ? new Date(c.createdAt).toLocaleString('uk-UA') : '';
            const isEditing = editId === c._id;

            return (
              <tr key={c._id}>
                <td>{c.userName || 'Anonymous'}</td>
                <td>
                  {isEditing ? (
                    <div className="edit-row">
                      <input
                        className="edit-input"
                        value={editText}
                        onChange={(e) => setEditText(e.target.value)}
                        placeholder="Edit comment..."
                      />
                      <button
                        className="btn"
                        onClick={async () => {
                          if (!editText.trim()) return;
                          await dispatch(updateComment({ id: c._id, content: editText.trim() }));
                          setEditId(null);
                          setEditText('');
                        }}
                      >
                        Зберегти
                      </button>
                      <button
                        className="btn btn-secondary"
                        onClick={() => {
                          setEditId(null);
                          setEditText('');
                        }}
                      >
                        Скасувати
                      </button>
                    </div>
                  ) : (
                    c.content
                  )}
                </td>
                <td>{dateText}</td>
                {role === 'admin' && (
                  <td className="actions-cell">
                    {isEditing ? (
                      <span className="muted">Редагування…</span>
                    ) : (
                      <>
                        <span
                          className="row-action"
                          onClick={() => {
                            setEditId(c._id);
                            setEditText(c.content);
                          }}
                        >
                          Редагувати
                        </span>
                        {' | '}
                        <span
                          className="row-action danger"
                          onClick={() => dispatch(deleteComment(c._id))}
                        >
                          Видалити
                        </span>
                      </>
                    )}
                  </td>
                )}
              </tr>
            );
          })}
        </tbody>
      </table>

      {/* Додавання коментаря — тільки авторизовані */}
      {isAuth && (
        <div className="add-comment">
          <input
            className="add-input"
            value={text}
            onChange={(e) => setText(e.target.value)}
            placeholder="Ваш коментар..."
            onKeyDown={async (e) => {
              if (e.key === 'Enter' && !e.shiftKey && text.trim()) {
                e.preventDefault();
                await dispatch(createComment({ articleId: id, content: text.trim() }));
                setText('');
              }
            }}
          />
          <button
            className="btn"
            onClick={async () => {
              if (!text.trim()) return;
              await dispatch(createComment({ articleId: id, content: text.trim() }));
              setText('');
            }}
          >
            Надіслати
          </button>
        </div>
      )}
    </div>
  );
};

export default Article;
