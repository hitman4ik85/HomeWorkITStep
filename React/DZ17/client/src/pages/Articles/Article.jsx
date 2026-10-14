import React, { useEffect, useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { useParams } from 'react-router-dom';
import Loader from '../../components/Loader/Loader';
import { getArticle } from '../../thunks/articleThunks';
import { createComment, deleteComment, fetchComments, updateComment } from '../../thunks/commentsThunks';
import useAuth from '../../hooks/useAuth';
import './Article.css';
import { EditOutlined, DeleteOutlined, SaveOutlined, RollbackOutlined, SendOutlined } from '@ant-design/icons';

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
            <th className="col-author">Author</th>
            <th className="col-content">Content</th>
            <th className="col-date">Date</th>
            {role === 'admin' && <th className="col-actions">Actions</th>}
          </tr>
        </thead>
        <tbody>
          {comments.list.map((c) => {
            const dateText = c.createdAt ? new Date(c.createdAt).toLocaleString('uk-UA') : '';
            const isEditing = editId === c._id;

            return (
              <tr key={c._id}>
                <td className="col-author">{c.userName || 'User'}</td>
                <td className="col-content">
                  {isEditing ? (
                    <div className="edit-row">
                      <input
                        className="edit-input"
                        value={editText}
                        onChange={(e) => setEditText(e.target.value)}
                        placeholder="Edit comment..."
                      />
                      <SaveOutlined
                        className="row-icon"
                        title="Зберегти"
                        onClick={async () => {
                          if (!editText.trim()) return;
                          await dispatch(updateComment({ id: c._id, content: editText.trim() }));
                          setEditId(null);
                          setEditText('');
                        }}
                      />
                      <RollbackOutlined
                        className="row-icon"
                        title="Скасувати"
                        onClick={() => {
                          setEditId(null);
                          setEditText('');
                        }}
                      />
                    </div>
                  ) : (
                    c.content
                  )}
                </td>
                <td className="col-date">{dateText}</td>
                {role === 'admin' && (
                  <td className="col-actions actions-cell">
                    {isEditing ? (
                      <span className="muted">Редагування…</span>
                    ) : (
                      <>
                        <EditOutlined
                          className="row-icon"
                          title="Редагувати"
                          onClick={() => {
                            setEditId(c._id);
                            setEditText(c.content);
                          }}
                        />
                        <DeleteOutlined
                          className="row-icon danger"
                          title="Видалити"
                          onClick={() => dispatch(deleteComment(c._id))}
                        />
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
          <SendOutlined
            className="row-icon send"
            title="Надіслати"
            onClick={async () => {
              if (!text.trim()) return;
              await dispatch(createComment({ articleId: id, content: text.trim() }));
              setText('');
            }}
          />
        </div>
      )}
    </div>
  );
};

export default Article;
