import { Tabs } from "expo-router";
import { Ionicons } from "@expo/vector-icons";
import { ImageBackground, Text, Image, StyleSheet } from "react-native";

export default function Layout() {
  return <Tabs screenOptions={{
    tabBarItemStyle: {
      width: '100%',
      height: '100%',
      justifyContent: 'center',
    },
    tabBarStyle: {
      backgroundColor: 'purple',
      borderRadius: 50,
      marginHorizontal: 20
    }
  }}>
    <Tabs.Screen name="index" options={{
      title: "",
      headerShown: false,
      tabBarIcon: (({ color }) => <>
        <Ionicons name={'home'} color={color} size={22} />
      </>),
    }} />
    <Tabs.Screen name="search" options={{
      title: "",
      headerShown: false,
      tabBarIcon: (({ color }) => <>
        <Ionicons name={'search'} color={color} size={22} />
      </>),
    }} />
    <Tabs.Screen name="saved" options={{
      title: "",
      headerShown: false,
      tabBarIcon: (({ color }) => <>
        <Ionicons name={'save'} color={color} size={22} />
      </>),
    }} />
  </Tabs>;
}

const styles = StyleSheet.create({
  iconStyle: {
    width: 30,
    height: 30,
    resizeMode: 'contain',
  }
})