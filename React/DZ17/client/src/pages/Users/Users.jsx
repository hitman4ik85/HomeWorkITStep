import React, { useEffect, useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import Loader from '../../components/Loader/Loader';
import { deleteUser, getUsers, setUserRole, updateUser } from '../../thunks/userThunks';
import './Users.css';
import { EditOutlined, DeleteOutlined, SaveOutlined, RollbackOutlined } from '@ant-design/icons';

const Users = () => {
    const dispatch = useDispatch();
    const { list, status, error } = useSelector((s) => s.users);
    const role = useSelector((s) => s.auth?.user?.role);

    const [editId, setEditId] = useState(null);
    const [editName, setEditName] = useState('');
    const [editEmail, setEditEmail] = useState('');
    const [editPassword, setEditPassword] = useState('');
    const [editRole, setEditRole] = useState('user');

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
        setEditPassword('');
        setEditRole(u.role || 'user');
    };

    const cancelEdit = () => {
        setEditId(null);
        setEditName('');
        setEditEmail('');
        setEditPassword('');
        setEditRole('user');
    };

    const saveRow = async (u) => {
        const data = { name: editName, email: editEmail };
        if (editPassword.trim()) data.password = editPassword.trim();
        await dispatch(updateUser({ id: u._id, data }));

        const currentRole = u.role || 'user';
        if (currentRole !== editRole) {
            await dispatch(setUserRole({ id: u._id, role: editRole }));
        }
        cancelEdit();
    };

    return (
        <div>
            <h2>Users</h2>
            <table className="users-table">
                <thead>
                    <tr>
                        <th className="col-email">Email</th>
                        <th className="col-name">Name</th>
                        <th className="col-pass">Password</th>
                        <th className="col-role">Role</th>
                        <th className="col-date">Created</th>
                        <th className="col-actions">Actions</th>
                    </tr>
                </thead>
                <tbody>
                    {list.map((u) => {
                        const created = u.createdAt ? new Date(u.createdAt).toLocaleString('uk-UA') : '';
                        const isEditing = editId === u._id;

                        return (
                            <tr key={u._id}>
                                <td className="col-email">
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
                                <td className="col-name">
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
                                <td className="col-pass">
                                    {isEditing ? (
                                        <input
                                            className="edit-input"
                                            type="password"
                                            value={editPassword}
                                            onChange={(e) => setEditPassword(e.target.value)}
                                            placeholder="new password"
                                        />
                                    ) : (
                                        '••••••'
                                    )}
                                </td>
                                <td className="col-role">
                                    {isEditing ? (
                                        <select
                                            value={editRole}
                                            onChange={(e) => setEditRole(e.target.value)}
                                        >
                                            <option value="user">user</option>
                                            <option value="admin">admin</option>
                                        </select>
                                    ) : (
                                        u.role || 'user'
                                    )}
                                </td>
                                <td className="col-date">{created}</td>
                                <td className="col-actions actions-cell">
                                    {isEditing ? (
                                        <>
                                            <SaveOutlined
                                                className="row-icon"
                                                title="Зберегти"
                                                onClick={() => saveRow(u)}
                                            />
                                            <RollbackOutlined
                                                className="row-icon"
                                                title="Скасувати"
                                                onClick={cancelEdit}
                                            />
                                        </>
                                    ) : (
                                        <>
                                            <EditOutlined
                                                className="row-icon"
                                                title="Редагувати"
                                                onClick={() => startEdit(u)}
                                            />
                                            <DeleteOutlined
                                                className="row-icon danger"
                                                title="Видалити"
                                                onClick={async () => {
                                                    if (window.confirm('Видалити користувача?')) {
                                                        await dispatch(deleteUser(u._id));
                                                    }
                                                }}
                                            />
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
