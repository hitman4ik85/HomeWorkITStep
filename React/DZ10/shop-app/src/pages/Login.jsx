import React, { useState } from 'react';
import { Formik, Form, Field, ErrorMessage } from 'formik';
import * as Yup from 'yup';
import { EyeOutlined, EyeInvisibleOutlined } from '@ant-design/icons';
import { useNavigate } from 'react-router';

const initialValues = {
  email: '',
  password: '',
  remember: false
};

const loginSchema = Yup.object().shape({
  email: Yup.string()
    .email('Invalid email format')
    .required('Email is required'),
  password: Yup.string()
    .required('Password is required')
    .matches(/^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,}$/, 'Min 8 chars, 1 number, 1 lower, 1 upper')
});

const Login = () => {
  const [viewPassword, setViewPassword] = useState('password');
  const navigate = useNavigate();

  const toggleViewPassword = () => {
    setViewPassword(prev => (prev === 'password' ? 'text' : 'password'));
  };

  const onSubmit = (values, formBag) => {
    console.log('Login data:', values);
    formBag.resetForm();
    navigate('/');
  };

  return (
    <div style={{ padding: 20 }}>
      <h1>Login</h1>
      <Formik initialValues={initialValues} onSubmit={onSubmit} validationSchema={loginSchema}>
        {() => (
          <Form>
            <div>
              <Field name="email" type="email" placeholder="Email" />
              <ErrorMessage name="email" component="div" className="invalid" />
            </div>

            <div>
              <div className="password">
                <Field name="password" type={viewPassword} placeholder="Password" />
                <div onClick={toggleViewPassword}>
                  {viewPassword === 'password' ? <EyeOutlined /> : <EyeInvisibleOutlined />}
                </div>
              </div>
              <ErrorMessage name="password" component="div" className="invalid" />
            </div>

            <div>
              <label>
                <Field name="remember" type="checkbox" />
                {' '}Remember me
              </label>
            </div>

            <button type="submit">Sign In</button>
          </Form>
        )}
      </Formik>
    </div>
  );
};

export default Login;
