import { Stack } from "expo-router";

export default function Layout() {
  return <Stack>
    <Stack.Screen name="movie" options={{ headerShown: false }} />
  </Stack>;
}
