import { useContext } from "react";
import { StyleSheet, Text, View } from "react-native";
import CheckBox from "expo-checkbox";
import { ThemeContext } from "../context/ThemeProvider";

type Theme = 'light' | 'dark';

interface ThemeContextType {
    theme: Theme;
    toggleTheme: (newTheme: Theme) => void;
}

export default function Page1() {

    const context = useContext(ThemeContext);
    if (!context) {
        return <Text>No context available!</Text>;
    }

    const { theme, toggleTheme } = context;

    const handleToggleTheme = (value: boolean) => {
        const newTheme: Theme = value ? 'dark' : 'light';
        toggleTheme(newTheme);
    }

    const styles = StyleSheet.create({
        container: {
            flex: 1,
            justifyContent: "center",
            alignItems: "center",
            backgroundColor: theme == "light" ? "#FFFFFF" : "#000000",
        },
        row: {
            flexDirection: "row",
            alignItems: "center",
            margin: 10
        },
        text: {
            fontSize: 16,
            color: theme == "light" ? "blue" : "lightblue",
            marginLeft: 10
        }
    });

    return (
        <View style={styles.container}>
            <View style={styles.row}>
                <CheckBox
                    value={theme == "dark"}
                    onValueChange={handleToggleTheme}
                    color={theme == "light" ? "#555555" : "#007AFF"}
                />
                <Text style={styles.text}>
                    Toggle Theme to {theme == "light" ? "dark" : "light"}
                </Text>
            </View>
        </View>
    );
}
