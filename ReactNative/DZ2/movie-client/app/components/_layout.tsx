import { Stack } from "expo-router";

export default function Layout() {
  return <Stack>
    <Stack.Screen name="seachBar" options={{ headerShown: false }} />
  </Stack>;
}
