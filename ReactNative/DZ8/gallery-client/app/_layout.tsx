import { Ionicons } from '@expo/vector-icons'
import { Tabs } from 'expo-router'
import React from 'react'
import { StyleSheet } from 'react-native'

export default function RootLayout() {
  return (
    <Tabs
      screenOptions={{
        headerShown: false,
        tabBarItemStyle: styles.tabItem,
        tabBarStyle: styles.tabBar
      }}
    >
      <Tabs.Screen
        name="index"
        options={{
          title: '',
          tabBarIcon: ({ color }) => (<Ionicons name="home" color={color} size={34} />)
        }}
      />
      <Tabs.Screen
        name="addPicture"
        options={{
          title: '',
          tabBarIcon: ({ color }) => (<Ionicons name="add-circle" color={color} size={34} />)
        }}
      />
      <Tabs.Screen
        name="infoPicture"
        options={{
          title: '',
          href: null,
          tabBarIcon: ({ color }) => (<Ionicons name="images" color={color} size={34} />)
        }}
      />
    </Tabs>
  )
}

const styles = StyleSheet.create({
  tabItem: {
    width: '100%',
    height: '100%',
    justifyContent: 'center'
  },
  tabBar: {
    backgroundColor: '#102942ff',
    borderRadius: 50,
    marginHorizontal: 10,
    position: 'absolute'
  }
});
