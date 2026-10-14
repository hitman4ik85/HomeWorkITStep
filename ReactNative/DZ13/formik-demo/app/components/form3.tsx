import { useFormik } from 'formik'
import React from 'react'
import { Pressable, StyleSheet, Text, TextInput, View } from 'react-native'
import * as yup from 'yup'

const Form3 = () => {

    const schema = yup.object({
        login: yup.string()
            .required('Login is required')
            .min(3, 'Min length is 3')
            .max(32, 'Max length is 32'),
        email: yup.string()
            .required('Email is required')
            .email('Invalid email'),
        password: yup.string()
            .required('Password is required')
            .min(6, 'Min length is 6')
            .max(64, 'Max length is 64')
    })

    const formik = useFormik({
        initialValues: { login: '', email: '', password: '' },
        validationSchema: schema,
        onSubmit: (values) => { console.log(values) }
    })

    return (
        <View style={styles.wrap}>
            <View style={styles.card}>
                <Text style={styles.title}>Formik + Yup</Text>
                <TextInput
                    style={styles.input}
                    placeholder='Enter login'
                    placeholderTextColor='#94a3b8'
                    value={formik.values.login}
                    onChangeText={formik.handleChange('login')}
                    onBlur={formik.handleBlur('login')}
                />
                {formik.touched.login && formik.errors.login && (
                    <Text style={styles.error}>{formik.errors.login}</Text>
                )}
                <TextInput
                    style={styles.input}
                    placeholder='Enter email'
                    placeholderTextColor='#94a3b8'
                    value={formik.values.email}
                    onChangeText={formik.handleChange('email')}
                    onBlur={formik.handleBlur('email')}
                    keyboardType='email-address'
                    autoCapitalize='none'
                />
                {formik.touched.email && formik.errors.email && (
                    <Text style={styles.error}>{formik.errors.email}</Text>
                )}
                <TextInput
                    style={styles.input}
                    placeholder='Enter password'
                    placeholderTextColor='#94a3b8'
                    value={formik.values.password}
                    onChangeText={formik.handleChange('password')}
                    onBlur={formik.handleBlur('password')}
                    secureTextEntry={true}
                />
                {formik.touched.password && formik.errors.password && (
                    <Text style={styles.error}>{formik.errors.password}</Text>
                )}

                <Pressable style={styles.btn} onPress={formik.handleSubmit as any}>
                    <Text style={styles.btnText}>Send data</Text>
                </Pressable>
                <Pressable style={styles.btn} onPress={formik.resetForm as any}>
                    <Text style={styles.btnText}>Reset form</Text>
                </Pressable>
            </View>
        </View>
    )
}

export default Form3

const styles = StyleSheet.create({
    wrap: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: '#ccc',
        padding: 16
    },
    card: {
        width: '90%',
        backgroundColor: '#fff',
        padding: 16,
        borderRadius: 12
    },
    title: {
        fontSize: 18,
        fontWeight: '700',
        marginBottom: 12
    },
    input: {
        borderWidth: 1,
        borderColor: '#e2e8f0',
        borderRadius: 8,
        padding: 10,
        marginBottom: 6
    },
    error: {
        color: 'crimson',
        marginBottom: 8
    },
    btn: {
        marginTop: 6,
        backgroundColor: '#007AFF',
        borderRadius: 8,
        padding: 10,
        alignItems: 'center'
    },
    btnText: {
        color: '#fff',
        fontWeight: '600'
    }
});
