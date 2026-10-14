import React from "react";
import { Redirect, router } from "expo-router";
import { Pressable, StyleSheet, Text, View } from "react-native";
import { useAuth } from "../context/AuthContext";

export default function Index() {

  const { authState, onLogout } = useAuth();

  if (!authState?.authenticated) {
    return <Redirect href="/Login" />;
  }

  const handleLogout = async () => {
    await onLogout!();
    router.replace("/Login");
  };

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Home (index)</Text>

      <Pressable style={styles.btn} onPress={handleLogout}>
        <Text style={styles.btnText}>Logout</Text>
      </Pressable>
    </View>
  );
}

const styles = StyleSheet.create({
  container: { flex: 1, justifyContent: "center", alignItems: "center", backgroundColor: "#ffffff" },
  title: { fontSize: 18, fontWeight: "700", color: "#0f172a", marginBottom: 12 },
  btn: {
    paddingVertical: 12,
    paddingHorizontal: 16,
    borderRadius: 8,
    backgroundColor: "#ef4444",
    alignItems: "center"
  },
  btnText: { color: "#ffffff", fontWeight: "600" }
});