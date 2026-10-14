import { Button, Form, Input } from 'antd';
import React from 'react';
import { useDispatch } from 'react-redux';
import { login } from '../thunks/authThunk';
import { NavLink } from 'react-router';

const Login = () => {
    const dispatch = useDispatch();
    const onFinish = values => {
        //console.log('Success:', values);
        dispatch(login(values));
      };

    return (
        <div>
            <h1>Login</h1>
            <Form
                name="basic"
                labelCol={{ span: 8 }}
                wrapperCol={{ span: 16 }}
                style={{ maxWidth: 600 }}
                initialValues={{ remember: true }}
                onFinish={onFinish}
                autoComplete="off"
            >
                <Form.Item
                label="Email"
                name="email"
                rules={[{ required: true, message: 'Please input your username!' }]}
                >
                <Input />
                </Form.Item>

                <Form.Item
                label="Password"
                name="password"
                rules={[{ required: true, message: 'Please input your email!' }]}
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
}

export default Login;
