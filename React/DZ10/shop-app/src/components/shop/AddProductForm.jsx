import React, { useState } from 'react';
import { Formik, Form, Field, ErrorMessage } from 'formik';
import * as Yup from 'yup';

const initialValues = {
  name: '',
  price: '',
  img: '',
  country: '',
  rating: ''
};

const productSchema = Yup.object().shape({
  name: Yup.string().required('Назва обовʼязкова').min(2, 'Мінімум 2 символи'),
  price: Yup.number().typeError('Ціна має бути числом').positive('Більше 0').required('Ціна обовʼязкова'),
  img: Yup.string().url('Некоректний URL').required('URL картинки обовʼязковий'),
  country: Yup.string().required('Країна обовʼязкова'),
  rating: Yup.number().typeError('Рейтинг має бути числом').min(1, 'Від 1 до 5').max(5, 'Від 1 до 5').required('Рейтинг обовʼязковий')
});

const AddProductForm = ({ onAdd }) => {
  const [visible, setVisible] = useState(false);

  const onSubmit = (values, formBag) => {
    const { name, price, img, country, rating } = values;
    onAdd(name, price, img, country, rating);
    formBag.resetForm();
    setVisible(false);
  };

  return (
    <div style={{ textAlign: 'center', marginBottom: '30px' }}>
      <div className="form-buttons">
        <button onClick={() => setVisible(true)}>Додати товар</button>
      </div>

      {visible && (
        <div className="modal-overlay">
          <div className="modal">
            <h3>Новий товар</h3>

            <Formik initialValues={initialValues} onSubmit={onSubmit} validationSchema={productSchema}>
              {() => (
                <Form>
                  <div>
                    <Field name="name" placeholder="Назва" />
                    <ErrorMessage name="name" component="div" className="invalid" />
                  </div>

                  <div>
                    <Field name="price" placeholder="Ціна" />
                    <ErrorMessage name="price" component="div" className="invalid" />
                  </div>

                  <div>
                    <Field name="img" placeholder="URL картинки" />
                    <ErrorMessage name="img" component="div" className="invalid" />
                  </div>

                  <div>
                    <Field name="country" placeholder="Країна" />
                    <ErrorMessage name="country" component="div" className="invalid" />
                  </div>

                  <div>
                    <Field name="rating" placeholder="Рейтинг 1-5" />
                    <ErrorMessage name="rating" component="div" className="invalid" />
                  </div>

                  <br />
                  <div className="form-buttons">
                    <button type="submit">Додати</button>
                    <button type="button" onClick={() => setVisible(false)}>Закрити</button>
                  </div>
                </Form>
              )}
            </Formik>
          </div>
        </div>
      )}
    </div>
  );
};

export default React.memo(AddProductForm);
