import React, { useState } from 'react';
import { Pressable, StyleSheet, Text, TextInput, View } from 'react-native';
import { useAuth } from '../context/AuthContext';
import { router } from 'expo-router';

const Login = () => {

  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const { onLogin, onRegister } = useAuth();

  const login = async () => {
    const result = await onLogin!(email.trim(), password);
    if (result && result.error) {
      alert(result.msg);
    } else {
      router.replace('/');
    }
  };

  const register = async () => {
    const result = await onRegister!(email.trim(), password);
    if (result && result.error) {
      alert(result.msg);
    } else {
      alert('Registered! Now press Login.');
    }
  };

  return (
    <View style={styles.container}>
      <View style={styles.card}>
        <Text style={styles.title}>Login</Text>

        <TextInput
          style={styles.input}
          placeholder='Enter email'
          placeholderTextColor='#94a3b8'
          value={email}
          onChangeText={setEmail}
          keyboardType='email-address'
          autoCapitalize='none'
        />
        <TextInput
          style={styles.input}
          placeholder='Enter password'
          placeholderTextColor='#94a3b8'
          value={password}
          onChangeText={setPassword}
          secureTextEntry
        />

        <View style={styles.row}>
          <Pressable style={styles.btnPrimary} onPress={login}>
            <Text style={styles.btnTextPrimary}>Login</Text>
          </Pressable>
          <Pressable style={styles.btnOutline} onPress={register}>
            <Text style={styles.btnTextOutline}>Register</Text>
          </Pressable>
        </View>
      </View>
    </View>
  );
}

export default Login;

const styles = StyleSheet.create({
  container: { flex: 1, justifyContent: 'center', alignItems: 'center', backgroundColor: '#ffffff' },
  card: { width: '90%', backgroundColor: '#f8fafc', borderWidth: 1, borderColor: '#e2e8f0', borderRadius: 12, padding: 16 },
  title: { fontSize: 18, fontWeight: '700', marginBottom: 12, color: '#0f172a' },
  input: {
    borderWidth: 1, borderColor: '#cbd5e1', borderRadius: 8,
    paddingHorizontal: 10, height: 44, marginBottom: 10,
    backgroundColor: '#ffffff', color: '#0f172a'
  },
  row: { flexDirection: 'row', justifyContent: 'space-between', marginTop: 6 },
  btnPrimary: { flex: 1, paddingVertical: 12, borderRadius: 8, backgroundColor: '#007AFF', alignItems: 'center', marginRight: 6 },
  btnOutline: { flex: 1, paddingVertical: 12, borderRadius: 8, backgroundColor: 'transparent', borderWidth: 1, borderColor: '#cbd5e1', alignItems: 'center', marginLeft: 6 },
  btnTextPrimary: { color: '#ffffff', fontWeight: '600' },
  btnTextOutline: { color: '#0f172a', fontWeight: '600' }
});
