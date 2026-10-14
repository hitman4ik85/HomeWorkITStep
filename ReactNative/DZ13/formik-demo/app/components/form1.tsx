import React, { useEffect, useState } from 'react';
import { StyleSheet, Text, TextInput, View } from 'react-native';

const form1 = () => {

    const [user, setUser] = useState({ login: '', password: '' });

    useEffect(() => {
        console.log(user);
    }, [user]);

    const inputFormValue = (event: any, name: string) => {
        setUser({ ...user, [name]: event.target.value });
    }

    return (
        <View>
            <Text>Login Form</Text>
            {/* <TextInput onChangeText={(text) => {setUser({...user, login: text})}} value={user.login} style={styles.input} />
      <TextInput onChangeText={(text) => {setUser({...user, password: text})}} value={user.password} style={styles.input}/> */}
            <TextInput onChange={(event) => { inputFormValue(event, 'login') }} value={user.login} style={styles.input} />
            <TextInput onChange={(event) => { inputFormValue(event, 'password') }} value={user.password} style={styles.input} />
        </View>
    )
}

export default form1

const styles = StyleSheet.create({
    input: {
        borderWidth: 1,
        borderColor: 'black',
        borderRadius: 10,
        margin: 2
    },
})