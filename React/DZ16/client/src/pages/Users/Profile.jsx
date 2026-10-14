import { Button, Form, Input } from 'antd';
import React, { useEffect } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { updateProfile } from '../../thunks/authThunk';

const Profile = () => {
    const [form] = Form.useForm();
    const dispatch = useDispatch();
    const auth = useSelector((state) => state.auth);

    // коли підтягнеться користувач — підставляємо значення у форму
    useEffect(() => {
        if (auth.user) {
            form.setFieldsValue({
                name: auth.user.name || '',
                email: auth.user.email || '',
                password: ''
            });
        }
    }, [auth.user, form]);

    const onFinish = (values) => {
        dispatch(updateProfile(values));
    };

    return (
        <div>
            <h1>Profile</h1>
            <Form
                name="profile"
                form={form}
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
                    <Button type="primary" htmlType="submit">
                        Save
                    </Button>
                </Form.Item>
            </Form>
        </div>
    );
};

export default Profile;
