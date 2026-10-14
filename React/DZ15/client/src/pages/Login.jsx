import { Button, Form, Input } from 'antd';
import React from 'react';
import { useDispatch } from 'react-redux';
import { login } from '../thunks/authThunk';
import { useNavigate, NavLink } from 'react-router';

const Login = () => {
    const dispatch = useDispatch();
    const navigate = useNavigate();

    const onFinish = values => {
        dispatch(login(values)).then(() => {
            navigate('/'); // Після логіну — перенаправляємо на головну
        });
    };

    return (
        <div>
            <h1>Login</h1>
            <Form
                name="login"
                labelCol={{ span: 8 }}
                wrapperCol={{ span: 16 }}
                style={{ maxWidth: 600 }}
                onFinish={onFinish}
                autoComplete="off"
            >
                <Form.Item
                    label="Email"
                    name="email"
                    rules={[{ required: true, message: 'Please input your Email!' }]}
                >
                    <Input />
                </Form.Item>

                <Form.Item
                    label="Password"
                    name="password"
                    rules={[{ required: true, message: 'Please input your Password!' }]}
                >
                    <Input.Password />
                </Form.Item>

                <Form.Item label={null}>
                    <div style={{ display: 'flex', alignItems: 'center', gap: '12px' }}>
                        <Button type="primary" htmlType="submit">
                            Submit
                        </Button>
                        <NavLink to="/register">Register</NavLink>
                    </div>
                </Form.Item>
            </Form>
        </div>
    );
};

export default Login;
