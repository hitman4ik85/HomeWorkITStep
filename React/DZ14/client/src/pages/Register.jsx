import { Button, Form, Input } from 'antd';
import React from 'react';
import { useDispatch } from 'react-redux';
import { register } from '../thunks/authThunk';
import { useNavigate, NavLink } from 'react-router';

const Register = () => {
  const dispatch = useDispatch();
  const navigate = useNavigate();

  const onFinish = values => {
    // Надсилаємо дані на сервер через наш thunk
    dispatch(register(values));
    // Після реєстрації — перенаправляємо на Login
    navigate('/login');
  };

  return (
    <div>
      <h1>Register</h1>
      <Form
        name="register"
        labelCol={{ span: 8 }}
        wrapperCol={{ span: 16 }}
        style={{ maxWidth: 600 }}
        onFinish={onFinish}
        autoComplete="off"
      >
        <Form.Item
          label="Name"
          name="name"
          rules={[{ required: true, message: 'Please input your Name!' }]}
        >
          <Input />
        </Form.Item>

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
            <NavLink to="/login">Login</NavLink>
          </div>
        </Form.Item>
      </Form>
    </div>
  );
};

export default Register;
