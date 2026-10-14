import AsyncStorage from '@react-native-async-storage/async-storage';
import React, { createContext, PropsWithChildren, useEffect, useState } from 'react';
import { Text, useColorScheme, View } from 'react-native';

type Theme = 'light' | 'dark';

interface ThemeContextType {
  theme: Theme;
  toggleTheme: (newTheme: Theme) => void;
}

export const ThemeContext = createContext<ThemeContextType | null>(null);

const ThemeProvider = ({children}: PropsWithChildren<{}>) => {

  const colorScheme = useColorScheme();
  const [theme, setTheme] = useState((colorScheme as Theme) || 'light');

  useEffect(() => {
    const getThemeFromStorage = async () => {
      try {
        const saveTheme = await AsyncStorage.getItem('theme');
        if (saveTheme == 'light' || saveTheme == 'dark') {
          setTheme(saveTheme);
        }
      }
      catch (error) {
        console.error('LocalStorage error: ', error);
      }
    }
    getThemeFromStorage();
  }, []);

  useEffect(() => { 
    if (colorScheme == 'light' || colorScheme == 'dark') {
      setTheme(colorScheme);
    }
  }, [colorScheme]);

  const toggleTheme = async (newTheme: Theme) => {
    setTheme(newTheme);
    AsyncStorage.setItem('theme', newTheme);
  }

  return (
    <ThemeContext.Provider value={{theme, toggleTheme}}>
      {children}
    </ThemeContext.Provider>
  )
}

export default ThemeProvider