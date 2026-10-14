import { useContext } from "react";
import { Pressable, StyleSheet, Text, View } from "react-native";
import { ThemeContext } from "../context/ThemeProvider";

type Theme = 'light' | 'dark';

interface ThemeContextType {
  theme: Theme;
  toggleTheme: (newTheme: Theme) => void;
}

export default function Index() {

  const context = useContext(ThemeContext);
  if (!context) {
    return <Text>No context available!</Text>;
  }

  const { theme, toggleTheme } = context;  //деструктуризація контекста
  const handleToggleTheme = () => {
    const newTheme: Theme = theme == 'light' ? 'dark' : 'light';
    toggleTheme(newTheme);
  }

  const styles = StyleSheet.create({
    container: {
      flex: 1,
      justifyContent: "center",
      alignItems: "center",
      backgroundColor: theme == "light" ? "#FFFFFF" : "#000000",
    },
    button: {
      margin: 10,
      padding: 10,
      backgroundColor: theme == "light" ? "#555555" : "#007AFF",
      borderRadius: 5,
    },
    text: {
      fontSize: 16,
      color: theme == "light" ? "yellow" : "lightblue",
    }
  });

  return (
    <View style={styles.container}>
      <Pressable onPress={handleToggleTheme} style={styles.button}>
        <Text style={styles.text}>Toggle Theme to {theme == "light" ? "dark" : "light"}</Text>
      </Pressable>
    </View>
  );
}
