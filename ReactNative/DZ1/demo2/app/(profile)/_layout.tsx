import React from "react";
import { Tabs } from "expo-router";

export default function RootLayout() {
  return (
    <Tabs
      screenOptions={{
        headerShown: false,                 // прибрали заголовки
        tabBarActiveTintColor: "#0ea5e9",
        tabBarInactiveTintColor: "#64748b",
        tabBarStyle: { backgroundColor: "rgb(203, 245, 205)" },
        tabBarLabelStyle: { fontSize: 10, fontWeight: "600" }
      }}
    >
      <Tabs.Screen name="page1" options={{ title: "Page1" }} />
      <Tabs.Screen name="page2" options={{ title: "Page2" }} />
      <Tabs.Screen name="page3" options={{ title: "Page3" }} />
    </Tabs>
  );
}
