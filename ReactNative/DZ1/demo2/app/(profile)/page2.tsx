import React from "react";
import { View, Text, StyleSheet } from "react-native";

const Page2 = () => {
  return (
    <View style={s.wrap}>
      <View style={s.card}>
        <Text style={s.cardTitle}>Блок А</Text>
        <Text style={s.cardText}>Текст.</Text>
      </View>
      <View style={s.card}>
        <Text style={s.cardTitle}>Блок Б</Text>
        <Text style={s.cardText}>Текст.</Text>
      </View>
      <View style={s.card}>
        <Text style={s.cardTitle}>Нотатки</Text>
        <Text style={s.cardText}>Підказки або список.</Text>
      </View>
    </View>
  );
};

const s = StyleSheet.create({
  wrap: { flex: 1, backgroundColor: "#f1f5f9", padding: 16 },
  card: { backgroundColor: "#ffffff", borderRadius: 12, padding: 16, marginBottom: 12 },
  cardTitle: { fontSize: 16, fontWeight: "700", marginBottom: 6, color: "#0f172a" },
  cardText: { fontSize: 14, color: "#334155" }
});

export default Page2;
