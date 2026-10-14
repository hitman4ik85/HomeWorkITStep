import { useFormik } from 'formik';
import React from 'react';
import { Button, StyleSheet, TextInput, View } from 'react-native';
import * as yup from 'yup';

const Form2 = () => {

    const schema = yup.object({
        login: yup
            .string()
            .required('Login is Required')
            .max(12, 'Must be 12 characters or less'),
        email: yup
            .string()
            .required('Email is Required')
            .email('Invalid email address'),
        password: yup
            .string()
            .required('Password is Required')
            .min(3, 'Must be 2 characters or more'),
    });

    const validate = (values: any) => {
        const errors: any = {};
        if (!values.login) {
            errors.login = 'Login is Required';
        } else if (values.login.length > 12) {
            errors.login = 'Must be 12 characters or less';
        }
        if (!values.email) {
            errors.email = 'Email is Required';
        } else if (!/^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,4}$/i.test(values.email)) {
            errors.email = 'Invalid email address';
        }
        if (!values.password) {
            errors.password = 'Password is Required';
        } else if (values.password.length < 3) {
            errors.password = 'Must be 2 characters or more';
        }
        return errors;
    }

    const formik = useFormik({
        initialValues: {
            login: '',
            email: '',
            password: ''
        },
        validationSchema: schema,
        //validate,
        onSubmit: (values) => {
            console.log(JSON.stringify(values));
        }
    })

    return (
        <View style={styles.content}>
            <TextInput
                style={styles.input}
                id="login"
                placeholder='Enter login'
                onChangeText={formik.handleChange}
                onBlur={formik.handleBlur}
                value={formik.values.login}
            />
            {formik.errors.login ? <div style={styles.error}>{formik.errors.login}</div> : null}
            <TextInput
                style={styles.input}
                id="email"
                placeholder='Enter email'
                onChangeText={formik.handleChange}
                onBlur={formik.handleBlur}
                value={formik.values.email}
            />
            {formik.errors.email ? <div style={styles.error}>{formik.errors.email}</div> : null}
            <TextInput
                style={styles.input}
                id="password"
                placeholder='Enter password'
                onChangeText={formik.handleChange}
                onBlur={formik.handleBlur}
                value={formik.values.password}
            />
            {formik.errors.password ? <div style={styles.error}>{formik.errors.password}</div> : null}
            <Button onPress={() => formik.handleSubmit()} title="Login" />
            <Button onPress={(e) => formik.handleReset(e)} title="Reset" />

        </View>
    )
}

export default Form2

const styles = StyleSheet.create({
    content: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        padding: 16
    },
    error: {
        color: 'red'
    },
    input: {
        height: 20,
        width: 200,
        borderWidth: 1,
        borderColor: 'black',
        borderRadius: 10,
        margin: 2
    },
});
