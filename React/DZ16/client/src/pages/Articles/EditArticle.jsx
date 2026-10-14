import { Button, DatePicker, Form, Input } from 'antd';
import React, { useEffect } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { getArticle, updateArticle } from '../../thunks/articleThunks';
import { useParams, useNavigate } from 'react-router';
import Loader from '../../components/Loader/Loader';

const EditArticle = () => {
    const [form] = Form.useForm();
    const { id } = useParams();
    const dispatch = useDispatch();
    const navigate = useNavigate();
    const articles = useSelector((s) => s.articles);

    useEffect(() => {
        dispatch(getArticle(id));
    }, [dispatch, id]);

    useEffect(() => {
        if (articles.current) {
            form.setFieldsValue({
                title: articles.current.title || '',
                content: articles.current.content || '',
                date: articles.current.createdAt ? null : null // поле дати не використовуємо
            });
        }
    }, [articles, form]);

    const onFinish = async (values) => {
        await dispatch(updateArticle({ id, data: values }));
        navigate(`/articles/${id}`);
    };

    if (articles.status === 'loading') return <Loader />;
    if (articles.status === 'failed') return <h1>{articles.error}</h1>;
    if (!articles.current) return null;

    return (
        <div>
            <h1>Edit Article</h1>
            <Form
                name="edit"
                form={form}
                labelCol={{ span: 4 }}
                wrapperCol={{ span: 20 }}
                style={{ maxWidth: 600 }}
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
                    <Input.TextArea rows={8} />
                </Form.Item>

                <Form.Item label="Date" name="date">
                    <DatePicker />
                </Form.Item>

                <Form.Item label={null}>
                    <Button type="primary" htmlType="submit">Save</Button>
                </Form.Item>
            </Form>
        </div>
    );
};

export default EditArticle;
