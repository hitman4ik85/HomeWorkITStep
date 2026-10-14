import { Ionicons } from '@expo/vector-icons'
import { Drawer } from 'expo-router/drawer'
import { useColorScheme } from 'react-native'
import { GestureHandlerRootView } from 'react-native-gesture-handler'
import { Color } from '../constants/Colors'

export default function RootLayout() {

  const scheme = useColorScheme() ?? 'light'
  const theme = Color[scheme]

  return (
    <GestureHandlerRootView style={{ flex: 1 }}>
      <Drawer
        screenOptions={{
          drawerActiveTintColor: theme.color,
          drawerStyle: { backgroundColor: theme.background }
        }}
      >
        <Drawer.Screen name="index" options={{
          title: 'Home page',
          drawerLabel: 'Home',
          drawerIcon: ({ color, size }) => (<Ionicons name="home" color={color} size={size} />)
        }} />
        <Drawer.Screen name="page1" options={{
          title: 'Page 1',
          drawerLabel: 'Page 1',
          drawerIcon: ({ color, size }) => (<Ionicons name="book" color={color} size={size} />)
        }} />
      </Drawer>
    </GestureHandlerRootView>
  )
}