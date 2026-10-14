import React, { useEffect, useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import Loader from '../../components/Loader/Loader';
import { deleteUser, getUsers, setUserRole, updateUser } from '../../thunks/userThunks';
import './Users.css';

const Users = () => {
    const dispatch = useDispatch();
    const { list, status, error } = useSelector((s) => s.users);
    const role = useSelector((s) => s.auth?.user?.role);

    // локальний стейт для інлайнового редагування name/email
    const [editId, setEditId] = useState(null);
    const [editName, setEditName] = useState('');
    const [editEmail, setEditEmail] = useState('');

    useEffect(() => {
        dispatch(getUsers());
    }, [dispatch]);

    if (role !== 'admin') return <h3>403 Forbidden</h3>;
    if (status === 'loading') return <Loader />;
    if (status === 'failed') return <h1>{error}</h1>;

    const startEdit = (u) => {
        setEditId(u._id);
        setEditName(u.name || '');
        setEditEmail(u.email || '');
    };
    const cancelEdit = () => {
        setEditId(null);
        setEditName('');
        setEditEmail('');
    };

    return (
        <div>
            <h2>Users</h2>
            <table className="users-table">
                <thead>
                    <tr>
                        <th>Email</th>
                        <th>Name</th>
                        <th>Role</th>
                        <th>Created</th>
                        <th>Actions</th>
                    </tr>
                </thead>
                <tbody>
                    {list.map(u => {
                        const created = u.createdAt ? new Date(u.createdAt).toLocaleString('uk-UA') : '';
                        const isEditing = editId === u._id;

                        return (
                            <tr key={u._id}>
                                <td>
                                    {isEditing ? (
                                        <input
                                            className="edit-input"
                                            value={editEmail}
                                            onChange={(e) => setEditEmail(e.target.value)}
                                            placeholder="email"
                                        />
                                    ) : (
                                        u.email
                                    )}
                                </td>
                                <td>
                                    {isEditing ? (
                                        <input
                                            className="edit-input"
                                            value={editName}
                                            onChange={(e) => setEditName(e.target.value)}
                                            placeholder="name"
                                        />
                                    ) : (
                                        u.name || ''
                                    )}
                                </td>
                                <td>
                                    <select
                                        value={u.role || 'user'}
                                        onChange={async (e) => {
                                            await dispatch(setUserRole({ id: u._id, role: e.target.value }));
                                            // після апдейту role список у стейті оновиться через extraReducer
                                        }}
                                    >
                                        <option value="user">user</option>
                                        <option value="admin">admin</option>
                                    </select>
                                </td>
                                <td>{created}</td>
                                <td className="actions-cell">
                                    {isEditing ? (
                                        <>
                                            <span
                                                className="row-action"
                                                onClick={async () => {
                                                    await dispatch(updateUser({ id: u._id, data: { name: editName, email: editEmail } }));
                                                    cancelEdit();
                                                }}
                                            >
                                                Зберегти
                                            </span>
                                            {' | '}
                                            <span className="row-action" onClick={cancelEdit}>
                                                Скасувати
                                            </span>
                                        </>
                                    ) : (
                                        <>
                                            <span className="row-action" onClick={() => startEdit(u)}>
                                                Редагувати
                                            </span>
                                            {' | '}
                                            <span
                                                className="row-action danger"
                                                onClick={async () => {
                                                    if (window.confirm('Видалити користувача?')) {
                                                        await dispatch(deleteUser(u._id));
                                                    }
                                                }}
                                            >
                                                Видалити
                                            </span>
                                        </>
                                    )}
                                </td>
                            </tr>
                        );
                    })}
                </tbody>
            </table>
        </div>
    );
};

export default Users;
