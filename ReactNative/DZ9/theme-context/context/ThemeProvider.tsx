import React, { createContext } from 'react';
import { Text, View } from 'react-native';

type Theme = 'light' | 'dark';

interface ThemeContextType {
  theme: Theme;
  toggleTheme: (newTheme: Theme) => void;
}

export const ThemeContext = createContext<ThemeContextType | null>(null);

const ThemeProvider = () => {
  return (
    <View>
      <Text>ThemeProvider</Text>
    </View>
  )
}

export default ThemeProvider