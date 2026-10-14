import React from "react";
import { View, Text, StyleSheet } from "react-native";

const Page3 = () => {
  return (
    <View style={s.wrap}>
      <View style={s.item}>
        <Text style={s.label}>Theme</Text>
        <Text style={s.value}>Light</Text>
      </View>
      <View style={s.item}>
        <Text style={s.label}>Notifications</Text>
        <Text style={s.value}>Enabled</Text>
      </View>
      <View style={s.item}>
        <Text style={s.label}>Version</Text>
        <Text style={s.value}>1.0.0</Text>
      </View>
    </View>
  );
};

const s = StyleSheet.create({
  wrap: { flex: 1, backgroundColor: "#f1f5f9", padding: 16 },
  item: {
    backgroundColor: "#ffffff",
    borderRadius: 12,
    padding: 16,
    marginBottom: 10,
    borderWidth: 1,
    borderColor: "#e2e8f0"
  },
  label: { fontSize: 12, color: "#64748b", marginBottom: 4 },
  value: { fontSize: 16, color: "#0f172a", fontWeight: "700" }
});

export default Page3;
