import axios from 'axios';
import { Platform } from 'react-native';
import * as SecureStore from 'expo-secure-store';
import { createContext, PropsWithChildren, useContext, useEffect, useState } from "react";

interface AuthProps {
    authState?: { token: string | null; authenticated: boolean | null };
    onRegister?: (email: string, password: string) => Promise<any>;
    onLogin?: (email: string, password: string) => Promise<any>;
    onLogout?: () => Promise<any>;
}

const TOKEN_KEY = 'my-key';
export const API_URL = 'https://api.developbetterapps.com';

const API_KEY = '';

const AuthContext = createContext<AuthProps>({});

export const useAuth = () => {
    return useContext(AuthContext);
};

// fallback для WEB замість SecureStore
const storage = {
    getItem: async (key: string) => {
        if (Platform.OS === 'web') {
            try { return Promise.resolve(localStorage.getItem(key)); }
            catch { return Promise.resolve(null); }
        }
        return SecureStore.getItemAsync(key);
    },
    setItem: async (key: string, value: string) => {
        if (Platform.OS === 'web') {
            try { localStorage.setItem(key, value); return Promise.resolve(); }
            catch { return Promise.resolve(); }
        }
        return SecureStore.setItemAsync(key, value);
    },
    deleteItem: async (key: string) => {
        if (Platform.OS === 'web') {
            try { localStorage.removeItem(key); return Promise.resolve(); }
            catch { return Promise.resolve(); }
        }
        return SecureStore.deleteItemAsync(key);
    }
};

export const AuthProvider = ({ children }: PropsWithChildren<{}>) => {
    const [authState, setAuthState] = useState<{ token: string | null; authenticated: boolean | null }>({
        token: null,
        authenticated: null
    });

    useEffect(() => {
        const loadToken = async () => {
            try {
                const token = await storage.getItem(TOKEN_KEY);
                if (token) {
                    console.log('Token: ' + token);
                    axios.defaults.headers.common['Authorization'] = `Bearer ${token}`;
                    setAuthState({ token, authenticated: true });
                }
            }
            catch (err) {
                console.log('Error: ' + err);
            }
        }
        loadToken();
    }, []);

    const authHeaders = () => (
        API_KEY
            ? { headers: { 'Content-Type': 'application/json', 'x-api-key': API_KEY } }
            : { headers: { 'Content-Type': 'application/json' } }
    );

    const register = async (email: string, password: string) => {
        try {
            delete axios.defaults.headers.common['Authorization'];
            const url = `${API_URL}/users`;
            const body = { email: (email ?? '').trim(), password: (password ?? '').trim() };

            console.log('POST:', url, body);
            const result = await axios.post(url, body, authHeaders());
            return result;
        }
        catch (err: any) {
            const data = err?.response?.data;
            const msg = data?.msg || data?.message || data?.error || 'Register failed';
            return { error: true, msg };
        }
    }

    const login = async (email: string, password: string) => {
        try {
            delete axios.defaults.headers.common['Authorization'];
            const url = `${API_URL}/auth`;
            const body = { email: (email ?? '').trim(), password: (password ?? '').trim() };

            console.log('POST:', url, body);
            const result = await axios.post(url, body, authHeaders());

            setAuthState({ token: result.data.token, authenticated: true });
            axios.defaults.headers.common['Authorization'] = `Bearer ${result.data.token}`;
            await storage.setItem(TOKEN_KEY, result.data.token);

            return result;
        }
        catch (err: any) {
            const data = err?.response?.data;
            const msg = data?.msg || data?.message || data?.error || 'Login failed';
            return { error: true, msg };
        }
    }

    const logout = async () => {
        await storage.deleteItem(TOKEN_KEY);
        delete axios.defaults.headers.common['Authorization'];
        setAuthState({ token: null, authenticated: false });
    };

    const value = { onRegister: register, onLogin: login, onLogout: logout, authState };

    return (
        <AuthContext.Provider value={value} >
            {children}
        </AuthContext.Provider>
    );
};
