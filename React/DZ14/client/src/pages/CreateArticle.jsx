import { Button, DatePicker, Form, Input, notification } from 'antd';
import React from 'react';
import { useDispatch } from 'react-redux';
import { createArticle } from '../thunks/articleThunks';

const CreateArticle = () => {
    const [form] = Form.useForm();
    const dispatch = useDispatch();

    const [api, contextHolder] = notification.useNotification();
    const openNotification = pauseOnHover => () => {    
        api.open({message: 'Success:',
            description:'This Article is created!',
            showProgress: true,      
            pauseOnHover,
            placement: 'topRight',
            });
        };

    const onFinish = values => {
        console.log('Success:', values);
        dispatch(createArticle(values));
        form.resetFields();
        openNotification(false)();
      };

    return (
        <div>
            <h1>Create Article</h1>
            <Form
                name="basic"
                form={form}
                labelCol={{ span: 4 }}
                wrapperCol={{ span: 20 }}
                style={{ maxWidth: 600 }}
                initialValues={{  }}
                onFinish={onFinish}
                autoComplete="off"
            >
            <Form.Item
                label="Title"
                name="title"
                rules={[{ required: true, message: 'Please input your Title!' }]}
            >
            <Input />
            </Form.Item>

            <Form.Item
                label="Content"
                name="content"
                rules={[{ required: true, message: 'Please input Content!' }]}
            >
            <Input.TextArea rows = {8}/>
            </Form.Item>

            <Form.Item label="Date" name="date">
                <DatePicker />
            </Form.Item>

            <Form.Item label={null}>
                <Button type="primary" htmlType="submit">
                    Submit
                </Button>
            </Form.Item>
            </Form>
            {contextHolder}
        </div>
    );
}

export default CreateArticle;
